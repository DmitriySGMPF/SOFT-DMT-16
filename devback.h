#ifndef DEVBACK_H
#define DEVBACK_H
#include <QObject>
#include "dmt22.h"
#include <QDebug>
#include <QThread>
#include <QSettings>
#include <QCoreApplication>

#include "scrollinfodev.h"
#include <io.h>
#include <windows.h>
#include <QMessageBox>
//#include "newdev.h"

#include <QDir>
#include <fstream>
#include <downloadmanager.h>
#include "sortdrives.h"
using namespace std;

class DevBack : public QObject
{
    Q_OBJECT
public:
    DevBack(DEV_DEVICE deviceDev, ScrollInfoDev *scroll, int *NumberOfDisplayed, bool newDevAdd, QObject *parent = nullptr);
    ~DevBack();
    DEV_DEVICE deviceDev;
    ScrollInfoDev *scroll;
    int numInfoWin;
    bool CheckConnect();
signals:
    void er(QString mes1, QString mes2);
    void regNewDev(DEV_HANDLE Handle, int statusDev);
    void CreateWin(int k, QString USER, unsigned short uBattery, QString ID);
    void deleteInfoDevSignal(int k);
    void refreshInfoDevSignal(int k, unsigned short uBattery, int downloadStatus);
public slots:

    bool addNewDevice();
private:


    QString USER;
    int *NumberOfDisplayed;
    bool devConnect;
    QSettings settings;
    QString Id;
    bool newDevAdd;

    char getDrives();
    char drive;

    string SharedDrives;
    string devDISK;
    bool FileExists(const char* fname);
    bool successReg;
    QThread workThread;
    SortDrives *sortDr;
    int statusDev;

    DEV_HANDLE deviceHandle;
    char pass[8] = "888888";
    char ID[10];
    char compInfo[50];
    char NONE[10];
    unsigned short Bat;
};

#endif // DEVBACK_H
