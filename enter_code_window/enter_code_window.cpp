//
// Created by kirill on 6/6/22.
//

#include "enter_code_window.h"
#include "../login_window/login_window.h"

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

    connect(back, &QPushButton::clicked, [=] {
        auto* loginWindow = new LoginWindow();
        loginWindow->show();
        this->close();
    });
}