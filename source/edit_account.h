#ifndef EDIT_ACCOUNT_H
#define EDIT_ACCOUNT_H

#include <QMainWindow>
#include <QPainter>
#include <QtSql>
#include <QTableWidget>
#include <QString>
namespace Ui {
class edit_account;
}

class edit_account : public QMainWindow
{
    Q_OBJECT

public:
    explicit edit_account(QWidget *parent = nullptr);
    ~edit_account();
    void paintEvent(QPaintEvent *);

    void add_database();
    void connect_database();
    void edit();
private slots:



    void on_tableWidget_cellClicked(int row, int column);



    void on_pushButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::edit_account *ui;
    QSqlDatabase DB4;
    QString user,pass;
    QTableWidgetItem *item1,*item2;
};

#endif // EDIT_ACCOUNT_H
