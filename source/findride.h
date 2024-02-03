#ifndef FINDRIDE_H
#define FINDRIDE_H

#include <QMainWindow>
#include <QPainter>
#include <QtSql>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QList>
#include <QVector>
#include <QMessageBox>
inline QVector<QString> str;
namespace Ui {
class findride;
}

class findride : public QMainWindow
{
    Q_OBJECT

public:
    explicit findride(QWidget *parent = nullptr);
    ~findride();
    void paintEvent(QPaintEvent *);
    void connect_database();
public slots:
    void find_car();
    void reserve();
    void on_tableWidget_cellClicked(int row, int column);
private:
    Ui::findride *ui;
    QSqlDatabase DB3;
};

#endif // FINDRIDE_H
