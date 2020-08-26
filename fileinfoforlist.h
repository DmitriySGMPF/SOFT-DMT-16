#ifndef FILEINFOFORLIST_H
#define FILEINFOFORLIST_H

#include <QWidget>
#include <QFileInfo>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include "favorites.h"
namespace Ui {
class fileInfoForList;
}

class fileInfoForList : public QWidget
{
    Q_OBJECT

public:
    explicit fileInfoForList(QFileInfo *thisFile, QWidget *parent = nullptr);
    ~fileInfoForList();

private slots:
    void on_open_clicked();

    void on_save_clicked();
signals:
    void rfrsh();
private:
    Ui::fileInfoForList *ui;
    QFileInfo thisFile;
    QSettings settings;

};

#endif // FILEINFOFORLIST_H
