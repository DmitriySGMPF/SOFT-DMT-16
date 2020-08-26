#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QGridLayout>

#include "backend.h"

#include "scrollinfodev.h"
#include "infodev.h"
#include "inforight.h"
#include <QTextCodec>

//#include "backenddmt16.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    int row, col;
    int k;
    MainWindow(QWidget *parent = nullptr);
    //MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ScrollInfoDev *scroll;
private slots:
    void on_pushButton_clicked();
    void ext();
signals:
    void deleteThread();

private:

    BackEnd *back;
    //BackEndDMT16 *backDMT16;

    QThread backEndThread, backEndThreadDMT16;

    void SetGraphWindow(int k);
    void DelGraphWindow(int k);
};
#endif // MAINWINDOW_H
