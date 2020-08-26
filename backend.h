#ifndef BACKEND_H
#define BACKEND_H


#include <QObject>
#include <QThread>
#include <QDebug>
#include "scrollinfodev.h"
#include "infodev.h"
#include "dmt22.h"
#include "devback.h"

using namespace std;


class BackEnd : public QObject
{
    Q_OBJECT
public:
    void stop();
    bool stopFlag;
    explicit BackEnd(ScrollInfoDev *scroll, QObject *parent = nullptr);
    ScrollInfoDev *scroll;
    DEV_DEVICE deviceDev[30];
    vector <DevBack *> List;



signals:
    void finished();
public slots:
    void run();

private:
    bool newDevAdd;

    void uppendNumInfoWin(int k);
    void delay(int mlsec);
    int amount = 0;
    int NumberOfDisplayed;
    vector<QThread> addDevThread;
    int actual_amount = 0;
    bool checkIdInList(DEV_DEVICE DEV);


    int amountDMT16 = 0;
    int actual_amountDMT16 = 0;

    DEV_DEVICE deviceDevDMT16[30];
};

#endif // BACKEND_H
