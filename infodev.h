#ifndef INFODEV_H
#define INFODEV_H

#include <QWidget>
//#include "dmt10.h"
#include <QString>
#include <QDebug>
#include <QPixmap>
#include <QSettings>
namespace Ui {
class InfoDev;
}

class InfoDev : public QWidget
{
    Q_OBJECT

public:
    void SetUser(QString USER_NAME);
    void SetBatVal(int bat);
    void SetDownloadProgress(int progress);
    void SetStatusDev(QString ID);
    explicit InfoDev(QWidget *parent = nullptr);
    ~InfoDev();
private:
    Ui::InfoDev *ui;
    int exStatus;
};

#endif // INFODEV_H
