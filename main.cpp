#include "login_window/login_window.h"
#include "admin_home_window/admin_home_window.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    AdminHomeWindow* adminHomeWindow = new AdminHomeWindow();
    adminHomeWindow -> show();
    return application.exec();
}