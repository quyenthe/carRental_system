#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QMainWindow>
#include <QPainter>

#include <QtSql>
#include <QString>
#include <QMessageBox>

namespace Ui {
class sign_up;
}

class sign_up : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_up(QWidget *parent = nullptr);
    ~sign_up();
    void paintEvent(QPaintEvent *);
    void connect_database();
    void get_input();
    void clear_input();
public slots:
    void back_to_login();
    void insert_database();

private:
    Ui::sign_up *ui;
    QSqlDatabase DB2;
    QString s1,s2,s3,s4;
};

#endif // SIGN_UP_H
