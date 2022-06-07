#include "enter_code_window.h"
#include "../login_window/login_window.h"
#include "../registration_window/registration_window.h"
#include "../sql_service/sql_service.h"

EnterCodeWindow::EnterCodeWindow(QWidget* pattern) : QDialog(pattern) {
    description = new QLabel("Введите код,\nкоторыйВам предоставил администратор");
    code = new QLineEdit();
    enter = new QPushButton("Продолжить");
    back = new QPushButton("Назад");

    mainLayout = new QVBoxLayout();
    mainLayout ->addWidget(description);
    mainLayout ->addWidget(code);
    mainLayout ->addWidget(enter);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(back);

    setWindowTitle("Регистрация");
    setLayout(mainLayout);

    connect(enter, &QPushButton::clicked, [=] {
        auto db = SqlService::connectToDB();
        if (db.open()) {
            auto result = db.exec("SELECT id FROM employees WHERE invite_code = \'" + code->text() + "\'");
            if (result.next()) {
                auto* registrationWindow = new RegistrationWindow();
                registrationWindow->show();
                this->close();
            }
            else {
//                QMessageBox* messageBox;
                QMessageBox::critical(0,"Ошибка","Неверный код!");
//                messageBox->setFixedSize(500,200);
//                messageBox->open();
            }
        }
    });

    connect(back, &QPushButton::clicked, [=] {
        auto* loginWindow = new LoginWindow();
        loginWindow->show();
        this->close();
    });
}