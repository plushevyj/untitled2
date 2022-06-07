#ifndef ADMIN_HOME_WINDOW_H
#define ADMIN_HOME_WINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql>
#include <QBoxLayout>
#include <QGroupBox>

class AdminHomeWindow : public QMainWindow
{
Q_OBJECT

public:
    AdminHomeWindow();

private:
    QWidget *area;

    QLabel *login;
    QPushButton *exit;
    QBoxLayout *layout1;

    QScrollBar *scroll;

    QLabel *nametable;
    QTableWidget *table;
//    QSqlRelationalTableModel *model;
    QPushButton *otchet;
    QListWidget *employee;
    QVBoxLayout *employeeLayout;
    QVBoxLayout *layout3;
    QHBoxLayout *layout2;

    QVBoxLayout *mainlayout;

    QSqlDatabase db;
    QSqlQuery query1;

    QMenuBar* menubar;
    void CreateMenuBar();

};

#endif // ADMIN_HOME_WINDOW_H
