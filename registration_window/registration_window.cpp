#include "registration_window.h"
#include "../login_window/login_window.h"

RegistrationWindow::RegistrationWindow(QWidget* pattern) : QDialog(pattern) {
    nameLabel = new QLabel("Ваши ФИО");
    name = new QLabel("Иванов Иван Иванович");
    jobTitleLabel = new QLabel("Должность");
    jobTitle = new QLabel("Разработчик десктопных приложений");

    age = new QSpinBox();
    sliderAge = new QSlider(Qt::Horizontal);
    age->setRange(18, 100);
    sliderAge->setRange(18,100);
    ageGroup = new QGroupBox("Ваш возраст");

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

    ageLayout = new QHBoxLayout();
    ageLayout->addWidget(age);
    ageLayout->addWidget(sliderAge);
    ageGroup->setLayout(ageLayout);

    mainlayout = new QVBoxLayout();
    mainlayout->addWidget(nameLabel);
    mainlayout->addWidget(name);
    mainlayout->addSpacing(20);
    mainlayout->addWidget(jobTitleLabel);
    mainlayout->addWidget(jobTitle);
    mainlayout->addSpacing(20);
    mainlayout->addWidget(ageGroup);
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

    connect(age, SIGNAL(valueChanged(int)), sliderAge, SLOT(setValue(int)));
    connect(sliderAge, SIGNAL(valueChanged(int)), age, SLOT(setValue(int)));

    connect(enter, &QPushButton::clicked, [=] {
        auto* loginWindow = new LoginWindow();
        loginWindow->show();
        this->close();
    });

    connect(back, &QPushButton::clicked, [=] {
        auto* loginWindow = new LoginWindow();
        loginWindow->show();
        this->close();
    });

    setLayout(mainlayout);
    setWindowTitle("Регистрация");
};