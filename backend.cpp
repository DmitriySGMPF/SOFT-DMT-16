#include "backend.h"
using namespace std;
BackEnd::BackEnd(ScrollInfoDev *scroll, QObject *parent) : QObject(parent)
{

    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");

    //Глобальные переменные
    this -> scroll = scroll;
    //
    amount = 0;
    actual_amount = 0;
    stopFlag = true;
    NumberOfDisplayed = 0;
    newDevAdd = true;

}



void BackEnd::run()
{

    while(stopFlag)
    {
        //DMT10
        amount = EnumStorageList(deviceDev,0);
        qDebug() << "________________________________________";
        qDebug() << "Количество устройств";
        qDebug() << amount;
        qDebug() << "Количество actual устройств";
        qDebug() << actual_amount;
        qDebug() << " ";
        qDebug() << "Количество видимых на экране устройств";
        qDebug() << NumberOfDisplayed;
        qDebug() << "________________________________________";
        if (amount>actual_amount){
            for(int i=0; i < amount; i++){

                amount = EnumStorageList(deviceDev,0);

                if (amount > 1)
                {
                    newDevAdd = false;
                }
                else
                {
                    newDevAdd = true;
                }

                DevBack *dev = new DevBack(deviceDev[i], scroll, &NumberOfDisplayed, newDevAdd);
                if(dev->addNewDevice()){
                    List.push_back(dev);
                    actual_amount++;
                    qDebug() << "Увеличение количества актуальных устройств";
                    qDebug() << actual_amount;
                    qDebug() << "__________________________________________";
                }

            }

        }



        for (int i = 0; i < actual_amount; i++) {
            qDebug() << i;
            if (!(List[i]->CheckConnect())) {
                List[i]->~DevBack();
                List.erase(List.begin() + i);
                uppendNumInfoWin(i);
                actual_amount--;
                i--;
            }
        }

        delay(3000);
    }

    emit finished(); // Уничтожение программе при выходе из цикла с помощью слота stop
}




void BackEnd::uppendNumInfoWin(int k)//Функция, которая обновляет список элементов во время удаление устройства, => уменьшает количество отображаемых девайсов
{
    for (int i = k; i < List.size(); i++){
        List[i]->numInfoWin = List[i]->numInfoWin - 1;
    }
}






void BackEnd::delay(int mlsec) //Функция отзывчивой задержки
{
        for (int i = 0; i < 100; i++){
        if (!stopFlag){
            emit finished();
            break;
        }
        QThread::msleep(mlsec/100);
    }

}

void BackEnd::stop() // Слот, останавливающий выполнение программы
{

    stopFlag = false;
}
