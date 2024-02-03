#include "findride.h"
#include "ui_findride.h"

findride::findride(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::findride)
{
    ui->setupUi(this);
    this->setWindowTitle("find car");
    connect_database();
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),SLOT(find_car()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(reserve()));
}

findride::~findride()
{
    delete ui;

}
void findride::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/rose2.png");
    painter.drawPixmap(0,0,pix);
}
void findride::connect_database(){
    DB3=QSqlDatabase::addDatabase("QSQLITE");
    DB3.setDatabaseName("C:/Users/Admin/Documents/CarRental/car.db");
}
void findride::find_car(){
    QString car_name=ui->lineEdit->text();
    DB3.open();
    QSqlDatabase::database().transaction();
    QSqlQuery sql_3(DB3);
    sql_3.prepare("SELECT * FROM ride WHERE car_name LIKE '%"+car_name+"%'");
    if(sql_3.exec()){
        int i=0,j=0;
        while(sql_3.next()){
            j++;
        }
        ui->tableWidget->setRowCount(j);
        while(sql_3.previous()){

            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sql_3.value("car_name").toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(sql_3.value("capacity").toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(sql_3.value("car_color").toString()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(sql_3.value("car_engine").toString()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(sql_3.value("car_owner").toString()));
            i++;
        }
    }
    QSqlDatabase::database().commit();
    DB3.close();
}



void findride::on_tableWidget_cellClicked(int row, int column)
{
    if(!str.empty()){
        for(int i=0;i<5;i++){
            str.pop_back();
        }
    }
    QTableWidgetItem *item;

    int col=0;
    while(col<5){
        item=((QTableWidgetItem *) ui->tableWidget->item(row,col));
        str.push_back(item->text());
        col++;
    }

}
void findride::reserve(){
    if(str.empty()){
        QMessageBox::critical(this,"critical","you have not selected car yet");
    }
    else{
        QMessageBox::information(this,"information","OK");
    }
}

