#ifndef LOG_IN_H
#define LOG_IN_H

#include <QMainWindow>
#include <QPainter>
#include <QtSql>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "sign_up.h"
inline QString user_name,password,email,phone;

QT_BEGIN_NAMESPACE
namespace Ui { class log_in; }
QT_END_NAMESPACE
class log_in : public QMainWindow
{
    Q_OBJECT

public:
    log_in(QWidget *parent = nullptr);
    ~log_in();
    void paintEvent(QPaintEvent *);
    void connect_database();

    void get_input();
    void clear_input();


public slots:
    void check_database();
    void back_to_signup();
private:
    Ui::log_in *ui;
    QSqlDatabase DB1;
    QString s1,s2,s3,s4;
    sign_up *s=new sign_up;


};
#endif // LOG_IN_H
