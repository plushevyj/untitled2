#include "registration_window.h"

RegistrationWindow::RegistrationWindow(QWidget* pattern) : QDialog(pattern) {
    nameLabel = new QLabel("Ваши ФИО");
    name = new QLabel("Иванов Иван Иванович");
    jobTitleLabel = new QLabel("Должность");
    jobTitle = new QLabel("Разработчик десктопных приложений");

    newLoginLabel = new QLabel("Придумайте логин");
    newLogin = new QLineEdit();
    newLogin->setPlaceholderText("Логин");

    newPasswordLabel = new QLabel("Придумайте пароль");
    newPassword = new QLineEdit();
    newPassword->setPlaceholderText("********");
    newPassword->setEchoMode(QLineEdit::Password);

    successPasswordLabel = new QLabel("Подтвердите пароль");
    successPassword = new QLineEdit();
    successPassword->setPlaceholderText("********");
    successPassword->setEchoMode(QLineEdit::Password);

    enter = new QPushButton("Зарегистрироваться");
    back = new QPushButton("Назад");

    mainlayout = new QVBoxLayout();
    mainlayout->addWidget(nameLabel);
    mainlayout->addWidget(name);
    mainlayout->addWidget(jobTitleLabel);
    mainlayout->addWidget(jobTitle);
    mainlayout->addSpacing(20);
    mainlayout->addWidget(newLoginLabel);
    mainlayout->addWidget(newLogin);
    mainlayout->addWidget(newPasswordLabel);
    mainlayout->addWidget(newPassword);
    mainlayout->addWidget(successPasswordLabel);
    mainlayout->addWidget(successPassword);
    mainlayout->addSpacing(20);
    mainlayout->addWidget(enter);
    mainlayout->addWidget(back);

};