#ifndef CREATE_RIDE_H
#define CREATE_RIDE_H

#include <QMainWindow>
#include <QtSql>
#include <QString>
#include <QMessageBox>
namespace Ui {
class create_ride;
}

class create_ride : public QMainWindow
{
    Q_OBJECT

public:
    explicit create_ride(QWidget *parent = nullptr);
    ~create_ride();
    void connect_database();
    void get_input();
    QString car_name,capacity,car_color,car_engine,car_owner;
public slots:
    void create();

private:
    Ui::create_ride *ui;
    QSqlDatabase DB4;

};

#endif // CREATE_RIDE_H
