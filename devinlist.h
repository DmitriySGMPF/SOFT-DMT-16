#ifndef DEVINLIST_H
#define DEVINLIST_H

#include <QWidget>
#include <QSettings>
#include <QMessageBox>
namespace Ui {
class DevInList;
}

class DevInList : public QWidget
{
    Q_OBJECT

public:
    explicit DevInList(QString devID, QWidget *parent = nullptr);
    ~DevInList();
    void deleteDev();
    bool deleteStatus;
private slots:
    void on_deleteReg_clicked();

    void on_userName_textEdited(const QString &arg1);

private:
    Ui::DevInList *ui;
    QSettings settings;

    QString devID;
    QString devName;
    bool devStatus;



};

#endif // DEVINLIST_H
