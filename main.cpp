#include "login_window/login_window.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    LoginWindow* loginWindow = new LoginWindow();
    loginWindow -> show();
    return application.exec();
}