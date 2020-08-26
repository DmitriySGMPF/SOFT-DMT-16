#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QDir>
#include <QFileInfoList>
#include <QDateTime>
#include <QFileInfo>
#include <QDebug>
//#include "dmt10.h"
#include "scrollinfodev.h"
class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(ScrollInfoDev *scroll,QString path,QString drive,int *numInfoWin,DEV_HANDLE deviceDev, QObject *parent = nullptr);
    //Наполняет список всех вложенных дирректорий и файлов
    void recursiveContentList(QDir &dir, QFileInfoList &contentList);
    //Ищет отсутствующие иили неактуальные элементы в резервной директории
    void contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffList);
    //Запускает процесс загрузки в отдельном потоке
    void downdloadInfo();
signals:
    void refreshInfoDevSignal(int k, unsigned short uBattery, int downloadStatus);
    void finished();
private:
    QDir sDir;
    QDir dDir;
    QFileInfoList diffList;
    ScrollInfoDev *scroll;
    int *numInfoWin;
    unsigned short Bat;
    DEV_HANDLE deviceHandle;
    bool deleteFlag;
    QSettings settings;
};

#endif // DOWNLOADMANAGER_H
