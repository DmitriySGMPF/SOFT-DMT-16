#ifndef FAVORITES_H
#define FAVORITES_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include "QDebug"
#include <QThread>
namespace Ui {
class Favorites;
}

class Favorites : public QDialog
{
    Q_OBJECT

public:
    explicit Favorites(QFileInfo info, QWidget *parent = nullptr);
    ~Favorites();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::Favorites *ui;
    QSettings settings;
    QString path;
    QFileInfo info;
    bool radioBut;
};

#endif // FAVORITES_H
