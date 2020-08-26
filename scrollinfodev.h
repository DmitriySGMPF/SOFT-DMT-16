#ifndef SCROLLINFODEV_H
#define SCROLLINFODEV_H

#include <QScrollArea>
#include <QGridLayout>
#include "infodev.h"
#include <QDebug>
#include <QString>
#include <addnewdevtoorg.h>
//#include "dmt10.h"
#include <QThread>
#include <QMessageBox>
using namespace std;
namespace Ui {
class ScrollInfoDev;
}

class ScrollInfoDev : public QScrollArea
{
    Q_OBJECT

public:
    explicit ScrollInfoDev(QWidget *parent = nullptr);
    ~ScrollInfoDev();
    ////////////////
    QGridLayout *layout;
    QWidget* container;
    void SetGraphWindow(int k);
    vector<InfoDev *> InfoList;
    AddNewDevToOrg *newDev;
    char diskNewDEv;
public slots:
    void CreateInfoWin(int k, QString USER, unsigned short uBattery, QString ID);
    void deleteInfoDevSlot(int k);
    void regNewDevice(DEV_HANDLE Handle, int statusDev);
    void refreshInfoDevSlot(int k, unsigned short uBattery, int downloadStatus);
    void error(QString mes1, QString mes2);


private:
    Ui::ScrollInfoDev *ui;
    bool errorInfoMes;
};


#endif // SCROLLINFODEV_H
