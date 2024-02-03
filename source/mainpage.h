#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QPainter>
#include <QtSql>

#include <QDebug>
#include "log_in.h"
#include "findride.h"
#include "create_ride.h"
#include "edit_account.h"

namespace Ui {
class mainPage;
}

class mainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainPage(QWidget *parent = nullptr);
    ~mainPage();
    void paintEvent(QPaintEvent *);
    void connect_database();
public slots:
    void find_ride();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::mainPage *ui;
    QSqlDatabase DB3;
};

#endif // MAINPAGE_H
