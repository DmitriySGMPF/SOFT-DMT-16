#ifndef ADDNEWDEVTOORG_H
#define ADDNEWDEVTOORG_H

#include <QDialog>
#include <QString>
#include "dmt22.h"
#include <QSettings>
#include <QDebug>
#include <fstream>
#include <io.h>
#include <QMessageBox>
using namespace std;

namespace Ui {
class AddNewDevToOrg;
}

class AddNewDevToOrg : public QDialog
{
    Q_OBJECT

public:

    explicit AddNewDevToOrg(DEV_HANDLE Handle, char disk , int statusDev = 0, QWidget *parent = nullptr);
    ~AddNewDevToOrg();
private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::AddNewDevToOrg *ui;
    int ind;
    int statusDev;
    QSettings settings;
    QString name;
    QString login;
    QString pass;
    char drive;
    DEV_HANDLE Handle;
    QStringList subdivision, logins;
    bool setDriveToDevice(char drive, char *ID);
    bool FileExists(const char* fname);
signals:
    void addInfoTextSignal(char *ID);
};

#endif // ADDNEWDEVTOORG_H
