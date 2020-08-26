#ifndef STTNGS_H
#define STTNGS_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Sttngs;
}

class Sttngs : public QDialog
{
    Q_OBJECT

public:
    explicit Sttngs(QString login, QWidget *parent = nullptr);
    ~Sttngs();

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();




    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::Sttngs *ui;

    QString login;
    bool aund;
    QSettings settings;

    int ind;
    QStringList subdivision, logins;

    bool deleteFlag;
};

#endif // STTNGS_H
