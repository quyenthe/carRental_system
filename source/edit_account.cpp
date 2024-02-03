#include "edit_account.h"
#include "ui_edit_account.h"
#include <QDebug>
edit_account::edit_account(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edit_account)
{
    ui->setupUi(this);
    connect_database();
    add_database();
    this->setWindowTitle("edit account");

}

edit_account::~edit_account()
{
    delete ui;
}
void edit_account::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/rose2.png");
    painter.drawPixmap(0,0,pix);
}
void edit_account::connect_database(){
    DB4=QSqlDatabase::addDatabase("QSQLITE");
    DB4.setDatabaseName("C:/Users/Admin/Documents/CarRental/car.db");
}
void edit_account::add_database(){
    DB4.open();
    QSqlDatabase::database().transaction();
    QSqlQuery sql_4(DB4);
    sql_4.prepare("SELECT *FROM user");
    if(sql_4.exec()){
        int i=0,j=0;
        while(sql_4.next())
            i++;
        ui->tableWidget->setRowCount(i);

        while(sql_4.previous()){
            ui->tableWidget->setItem(j,0,new QTableWidgetItem(sql_4.value("user_name").toString()));
            ui->tableWidget->setItem(j,1,new QTableWidgetItem(sql_4.value("password").toString()));
            ui->tableWidget->setItem(j,2,new QTableWidgetItem(sql_4.value("email").toString()));
            ui->tableWidget->setItem(j,3,new QTableWidgetItem(sql_4.value("phone_number").toString()));
            j++;
        }
    }
    QSqlDatabase::database().commit();
    DB4.close();
}
void edit_account::on_tableWidget_cellClicked(int row, int column)
{
    item2=(QTableWidgetItem *) ui->tableWidget->item(row,0);
    user=item2->text();


}
void edit_account::on_pushButton_clicked()
{
    this->close();
}


void edit_account::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    DB4.open();
    QSqlDatabase::database().transaction();
    QSqlQuery sql_4(DB4);
    sql_4.prepare("UPDATE user SET password=:value1 WHERE user_name=:value2");
    sql_4.bindValue(":value1",item->text());
    sql_4.bindValue(":value2",user);
    sql_4.exec();
    QSqlDatabase::database().commit();
    DB4.close();

}

