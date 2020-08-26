#include "devback.h"

DevBack::DevBack(DEV_DEVICE deviceDev, ScrollInfoDev *scroll, int *NumberOfDisplayed, bool newDevAdd, QObject *parent) : QObject(parent)
{
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");

    //Глобальные переменные
    this -> deviceDev = deviceDev;
    this -> scroll = scroll;
    this -> NumberOfDisplayed = NumberOfDisplayed;
    this -> newDevAdd = newDevAdd;
    devConnect = false;
    sortDr = new SortDrives();
    statusDev = 0;
}

DevBack::~DevBack()//Удаление устроства из списка
{

    if (devConnect)
    {
        settings.setValue("uses/" + Id, "noactive");
        connect(this, &DevBack::deleteInfoDevSignal, scroll, &ScrollInfoDev::deleteInfoDevSlot);
        deleteInfoDevSignal(numInfoWin);
        *NumberOfDisplayed = *NumberOfDisplayed - 1;
        QThread::msleep(150);
        workThread.terminate();
    }

}


/*DEV_HANDLE deviceHandle;
char pass[8] = "888888";
char ID[10];
char compInfo[50];
char NONE[10];
unsigned short Bat;
*/




bool DevBack::CheckConnect()
{
    int status = ConnectDevice(deviceDev, &deviceHandle);
    if ((status == 0) || (status == 5))
    {
        return 1;
    }
    return 0;
}


bool DevBack::addNewDevice()//Функция добавления и инициализации нового устройства в систему
{

    ConnectDevice(deviceDev, &deviceHandle);
    QThread::msleep(300);
    VerifiPassword(deviceHandle, pass, 1);
    QThread::msleep(300);
    GetUserDevID(deviceHandle, ID,compInfo,NONE);

    Id = QString(ID);

    USER = settings.value("devices/" + Id + "/user").toString();


    if(settings.value("devices/" + Id+"/user").toString() != "")
    {

           if(settings.value("uses/" + Id) != "active")
           {
                settings.setValue("uses/" + Id, "active");
                devConnect = true;
                *NumberOfDisplayed = *NumberOfDisplayed + 1;
                numInfoWin = *NumberOfDisplayed;
                GetBattery(deviceHandle, &Bat);
                connect(this, &DevBack::CreateWin, scroll, &ScrollInfoDev::CreateInfoWin);
                emit CreateWin(numInfoWin,USER, Bat, Id);
                QThread::msleep(500);
                SetMSCMode(deviceHandle);
                QThread::msleep(1000);
                drive = sortDr->getDrives(ID);

                //Загрузка данных
                QDir sDir = QDir(QString(drive) + ":/" + "DCIM/");
                QString path = settings.value("setting/firstpath", "C:/Bodycam").toString();//

                if (!QDir(path).exists())
                {
                    QDir().mkdir(path);
                }

                path += "/";
                path += settings.value("devices/" + QString(ID) + "/user").toString();


                if (!QDir(path).exists())
                {
                    QDir().mkdir(path);
                }

                path += "///";







                DownloadManager *downloadMediaContent = new DownloadManager(scroll,path,QString(drive), &numInfoWin, deviceHandle);
                connect(&workThread, &QThread::started, downloadMediaContent, &DownloadManager::downdloadInfo);
                downloadMediaContent->moveToThread(&workThread);
                workThread.start();//Запуск скачивания в отдельном потоке
                return true;

           }
           else
           {
               return false;
           }

    }
    else
    {

        if(newDevAdd)
        {



        SetMSCMode(deviceHandle);
        QThread::msleep(1000);

        scroll->diskNewDEv = sortDr->getDrives(ID);

        connect(this, &DevBack::regNewDev, scroll, &ScrollInfoDev::regNewDevice);

        char devName[20];
        GetModelID(deviceHandle, devName);
        char NameDMT16[20] = "BodyCam_DMT16P";
        qDebug() << devName;
        if (*devName == *NameDMT16){
            statusDev = 2;
        }

        emit regNewDev(deviceHandle, statusDev);

        QThread::msleep(50);

        return true;

        }
        else
        {
            connect(this, &DevBack::er, scroll, &ScrollInfoDev::error);
            emit er("ВНИМАНИЕ!","Невозможно добавить несколько устройств одновременно. Отключите все видеорегистраторы и добавляйте в систему по одному устройству");
        }
    }

}
