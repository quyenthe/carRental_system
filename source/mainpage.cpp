#include "mainpage.h"
#include "ui_mainpage.h"
#include "log_in.h"
mainPage::mainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("main page");
    ui->label_2->setText(user_name);
    ui->label_6->setText(email);
    ui->label_7->setText(phone);
    ui->pushButton_5->hide();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(find_ride()));
}

mainPage::~mainPage()
{
    delete ui;
}
void mainPage::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/rose2.png");
    painter.drawPixmap(0,0,pix);
}
void mainPage::find_ride(){
    findride *f=new findride;
    f->show();
}


void mainPage::on_pushButton_3_clicked()
{
    if(!str.empty()){
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
        ui->label_13->show();
        ui->label_9->setText("car name: "+str.at(0));
        ui->label_10->setText("capacity: "+str.at(1));
        ui->label_11->setText("car color: "+str.at(2));
        ui->label_12->setText("car engine: "+str.at(3));
        ui->label_13->setText("car owner: "+str.at(4));
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_5->hide();
        ui->label_8->hide();
        ui->pushButton_5->show();
        ui->pushButton_4->hide();
        ui->pushButton_3->hide();
    }
    else{
        QMessageBox::information(this,"information","no older");
    }
}
void mainPage::on_pushButton_5_clicked()
{
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_5->show();
    ui->label_8->show();
    ui->pushButton_5->hide();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
}
void mainPage::on_pushButton_2_clicked()
{
    create_ride *create=new create_ride;
    create->show();
}


void mainPage::on_pushButton_6_clicked()
{
    this->close();
    log_in *l = new log_in;
    l->show();


}


void mainPage::on_pushButton_4_clicked()
{
    edit_account * edit=new edit_account;
    edit->show();
}

