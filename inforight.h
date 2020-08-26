#ifndef INFORIGHT_H
#define INFORIGHT_H

#include <QWidget>
#include "fileman.h"
#include <QSettings>
#include "sttngs.h"
#include "reginfoforlist.h"
namespace Ui {
class InfoRight;
}

class InfoRight : public QWidget
{
    Q_OBJECT

public:
    explicit InfoRight(QString login, QString nameOrg, QWidget *parent = nullptr);
    ~InfoRight();
signals:
    void ex();

private slots:


    void on_Exit_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::InfoRight *ui;
    QString nameOrg;
    QString login;
};

#endif // INFORIGHT_H
