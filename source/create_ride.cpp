#include "create_ride.h"
#include "ui_create_ride.h"

create_ride::create_ride(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::create_ride)
{
    ui->setupUi(this);
    connect_database();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(create()));
    this->setWindowTitle("create ride");
}

create_ride::~create_ride()
{
    delete ui;
}
void create_ride::connect_database(){
    DB4=QSqlDatabase::addDatabase("QSQLITE");
    DB4.setDatabaseName("C:/Users/Admin/Documents/CarRental/car.db");
}
void create_ride::get_input(){
    car_name=ui->lineEdit->text();
    capacity=ui->lineEdit_2->text();
    car_color=ui->lineEdit_3->text();
    car_engine=ui->lineEdit_4->text();
    car_owner=ui->lineEdit_5->text();
}
void create_ride::create(){
    get_input();
    DB4.open();
    QSqlDatabase::database().transaction();
    QSqlQuery sql_4(DB4);
    sql_4.prepare("INSERT INTO ride (car_name,capacity,car_color,car_engine,car_owner) VALUES (:car_name,:capacity,:car_color,:car_engine,:car_owner)");
    sql_4.bindValue(":car_name",car_name);
    sql_4.bindValue(":capacity",capacity);
    sql_4.bindValue(":car_color",car_color);
    sql_4.bindValue(":car_engine",car_engine);
    sql_4.bindValue(":car_owner",car_owner);
    if(sql_4.exec()){
        QMessageBox::information(this,"information","submit successful");
        this->close();
    }
    QSqlDatabase::database().commit();
    DB4.close();
}
