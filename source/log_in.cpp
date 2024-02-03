#include "log_in.h"
#include "ui_log_in.h"
#include "mainpage.h"
log_in::log_in(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::log_in)
{
    ui->setupUi(this);
    connect_database();
    connect(ui->button_2,SIGNAL(clicked()),this,SLOT(check_database()));
    connect(ui->button_1,SIGNAL(clicked()),this,SLOT(back_to_signup()));
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
}

log_in::~log_in()
{
    delete ui;
}
void log_in::paintEvent(QPaintEvent *  ){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/CoverMain.png");
    painter.drawPixmap(0,0,pix);
}
void log_in::connect_database(){
    DB1=QSqlDatabase::addDatabase("QSQLITE");
    DB1.setDatabaseName("C:/Users/Admin/Documents/CarRental/car.db");
    if(DB1.open()){
        qDebug()<<"db is connected";
    }
    else{
        qDebug()<<"db is not connect";
    }
}
void log_in::check_database(){
    DB1.open();
    QSqlDatabase::database().transaction();
    QSqlQuery sql_1(DB1);
    get_input();
    sql_1.prepare("SELECT *FROM user");
    if(sql_1.exec()){
        int i=-1;
        while(sql_1.next()){
            i++;
        }
        sql_1.first();
        sql_1.previous();
        while(sql_1.next()){
            if(s1==sql_1.value("user_name").toString() && s2==sql_1.value("password").toString()){
                QMessageBox::information(this,"informaton","log in sucessful");
                clear_input();
                s3=sql_1.value("email").toString();
                s4=sql_1.value("phone_number").toString();
                user_name=s1;
                password=s2;
                email=s3;
                phone=s4;
                mainPage *m=new mainPage;
                m->show();
                this->close();
                break;
            }
            else if(sql_1.at()==i &&(s1!=sql_1.value("user_name").toString() || s2!=sql_1.value("password").toString())){
                QMessageBox::critical(this,"critical","log in no successful");
                clear_input();
                break;
            }
        }
    }
    QSqlDatabase::database().commit();
    DB1.close();
}
void log_in::get_input(){
    s1=ui->lineEdit->text();
    s2=ui->lineEdit_5->text();
}
void log_in::clear_input(){
    ui->lineEdit->clear();
    ui->lineEdit_5->clear();
}
void log_in::back_to_signup(){
    s->show();
}

