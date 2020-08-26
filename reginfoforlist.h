#ifndef REGINFOFORLIST_H
#define REGINFOFORLIST_H

#include <QDialog>
#include <QSettings>
#include <QDebug>
#include <QGridLayout>

#include "devinlist.h"

using namespace std;
namespace Ui {
class RegInfoForList;
}

class RegInfoForList : public QDialog
{
    Q_OBJECT

public:
    explicit RegInfoForList(QWidget *parent = nullptr);
    ~RegInfoForList();

private slots:
    void on_aund_clicked();
    void refrash();
    void on_aund_3_clicked();

private:
    Ui::RegInfoForList *ui;
    QSettings settings;
    bool aund;

    QGridLayout *layout;
    QWidget *container;
    QStringList logins;
    bool deleteStatus;
    vector <DevInList *> List;
};

#endif // REGINFOFORLIST_H
