#include "sign_up.h"
#include "ui_sign_up.h"

sign_up::sign_up(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
    connect(ui->button_1,SIGNAL(clicked()),this,SLOT(back_to_login()));
    connect_database();
    connect(ui->button_2,SIGNAL(clicked()),this,SLOT(insert_database()));
    this->setWindowTitle("sign up");
}

sign_up::~sign_up()
{
    delete ui;
}
void sign_up::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/CoverMain.png");
    painter.drawPixmap(0,0,pix);
}
void sign_up::back_to_login(){
    this->close();
}
void sign_up::connect_database(){
    DB2=QSqlDatabase::addDatabase("QSQLITE");
    DB2.setDatabaseName("C:/Users/Admin/Documents/CarRental/car.db");
}
void sign_up::insert_database(){
    get_input();
    if(s1==""||s2==""||s3==""||s4==""){
        QMessageBox::critical(this,"critical","no successful");
    }
    else{
        QMessageBox::information(this,"information","successful");
        DB2.open();
        QSqlDatabase::database().transaction();
        QSqlQuery sql_2(DB2);
        sql_2.prepare("INSERT INTO user (user_name,password,email,phone_number) VALUES (:user_name,:password,:email,:phone_number)");
        sql_2.bindValue(":user_name",s1);
        sql_2.bindValue(":password",s2);
        sql_2.bindValue(":email",s3);
        sql_2.bindValue(":phone_number",s4);
        sql_2.exec();
        QSqlDatabase::database().commit();
        DB2.close();
    }
    clear_input();
}
void sign_up::get_input(){
    s1=ui->lineEdit->text();
    s2=ui->lineEdit_2->text();
    s3=ui->lineEdit_3->text();
    s4=ui->lineEdit_4->text();
}
void sign_up::clear_input(){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

