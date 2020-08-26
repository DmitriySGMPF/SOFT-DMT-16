#include "downloadmanager.h"

DownloadManager::DownloadManager(ScrollInfoDev *scroll,QString path,QString drive, int *numInfoWin, DEV_HANDLE deviceDev,QObject *parent) : QObject(parent)
{

sDir = QDir(drive + ":/" + "DCIM/");
dDir = QDir(path);
diffList = QFileInfoList();
contentDifference(sDir,dDir,diffList);
this->scroll = scroll;
this->numInfoWin = numInfoWin;
deviceHandle = deviceDev;
deleteFlag = settings.value("setting/deleteflag", false).toBool();
if(deleteFlag){
}
else
{
}
}

void DownloadManager::recursiveContentList(QDir &dir, QFileInfoList &contentList)
{
    foreach(QFileInfo info, dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
        contentList.append(info);
        qDebug() << info;
        if(info.isDir()){
            dir.cd(info.fileName());
            recursiveContentList(dir, contentList);
            dir.cdUp();
        }
    }
}

void DownloadManager::contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffList)
{
    foreach(QFileInfo sInfo, sDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
        qDebug()<<sInfo.fileName();
        bool fileExists = false;
        foreach(QFileInfo dInfo, dDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
            qDebug()<<dInfo.fileName();
            if (sInfo.fileName() == dInfo.fileName()){
                if (sInfo.isDir() || sInfo.lastModified() <= dInfo.lastModified()){
                    fileExists = true;
                }
                break;

            }
        }
        if(!fileExists){
            qDebug()<<sInfo.fileName();
            diffList.append(sInfo);
        }
        if(sInfo.isFile()){
            continue;
        }
        if(fileExists){
            sDir.cd(sInfo.fileName());
            dDir.cd(sInfo.fileName());
            contentDifference(sDir, dDir, diffList);
            dDir.cdUp();
            sDir.cdUp();
        }
        else {
            sDir.cd(sInfo.fileName());
            recursiveContentList(sDir, diffList);
            sDir.cdUp();
        }

    }
}

void DownloadManager::downdloadInfo()
{
    GetBattery(deviceHandle, &Bat);
    int maxDownloadFiles = diffList.length();
    qDebug() << "КОЛИЧЕСТВО ФАЙЛОВ";
    int numDownloadFiles = 0;
    connect(this, &DownloadManager::refreshInfoDevSignal, scroll, &ScrollInfoDev::refreshInfoDevSlot);

    if (maxDownloadFiles > 0){


    foreach(QFileInfo diffInfo, diffList)
    {

        QString backUpPath = diffInfo.filePath().replace(sDir.absolutePath(),dDir.absolutePath());
        qDebug() << backUpPath;
        if(diffInfo.isFile()){
            QFile::remove(backUpPath);
            QFile::copy(diffInfo.absoluteFilePath(), backUpPath);

            if(deleteFlag){
              QFile::remove(diffInfo.absoluteFilePath());
            }

        }
        if (diffInfo.isDir()){
            dDir.mkdir(backUpPath);
        }
        numDownloadFiles++;

        emit refreshInfoDevSignal(*numInfoWin, Bat,int(numDownloadFiles*100/maxDownloadFiles));
    }
    ///////////Загрузка данных///////////////////////////////////////////////////////////////////////////////
    }
    else {
        emit refreshInfoDevSignal(*numInfoWin, Bat,100);
    }
    qDebug() << "УНИЧТОЖАЕМ ПОТОК";
    emit finished();

}

