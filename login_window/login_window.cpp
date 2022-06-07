#include "login_window.h"
#include "../enter_code_window/enter_code_window.h"
#include "../sql_service/sql_service.h"
#include "../admin_home_window/admin_home_window.h"
#include "../employee_home_window/employee_home_window.h"
#include <QtXml>

LoginWindow::LoginWindow(QWidget* pattern) : QDialog(pattern) {
    loginLabel = new QLabel("Введите логин");
    login = new QLineEdit();
    login->setPlaceholderText("Логин");

    passwordLabel = new QLabel("Введите пароль");
    password = new QLineEdit();
    password->setPlaceholderText("********");
    password->setEchoMode(QLineEdit::Password);

    box = new QGroupBox();
    layout1 = new QVBoxLayout();
    layout1->addWidget(loginLabel);
    layout1->addWidget(login);
    layout1 ->addWidget(passwordLabel);
    layout1->addWidget(password);
    box->setLayout(layout1);

    saveMe = new QCheckBox("Запомнить меня");
    enter = new QPushButton("Войти");

    spacer = new QSpacerItem(0, 20);

    haveCodeLabel = new QPushButton("Я новый сотрудник");

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(box);
    mainLayout->addWidget(saveMe);
    mainLayout->addWidget(enter);
    mainLayout->addItem(spacer);
    mainLayout->addWidget(haveCodeLabel);

    connect(enter, &QPushButton::clicked, [=] {
        QString userRole = "";
        auto db = SqlService::connectToDB();
        if (db.open()) {
            userRole = "admin";
            auto result = db.exec("SELECT id FROM admins WHERE login = \'" + login->text() + "\' AND password = \'" + password->text() + "\'");
            if (result.next()) {
                QString idUser = result.value(0).toString();
                SaveInXML();
                qDebug() << idUser;
                auto* adminHomeWindow = new AdminHomeWindow();
                adminHomeWindow->show();
                this->close();
            }
            else {
                auto result1 = db.exec("SELECT id FROM employees WHERE login = \'" + login->text() + "\' AND password = \'" + password->text() + "\'");
                if (result1.next())
                {
                    userRole = "employee";
//                    auto* employeeHomeWindow = new EmployeeHomeWindow();
//                    employeeHomeWindow->show();
//                    this->close();
                }
                else {
                    qDebug() << "User is not found!";
                }
            }
        }
        else {
            qDebug() << "Not Database connection!";
        }
    });

    connect(haveCodeLabel, &QPushButton::clicked, [=] {
        auto* registrationWindow = new EnterCodeWindow();
        registrationWindow->show();
        this->close();
    });



    DataAutofillFromXML();
    setWindowTitle("Вход");
    setLayout(mainLayout);
}

void LoginWindow::DataAutofillFromXML()
{
    QFile xmlFile("../config/userdata.xml");
    xmlFile.open(QIODevice::ReadWrite | QIODevice::Text);
    QXmlStreamReader xmlReader(&xmlFile);
    while (!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if (xmlReader.name() == "login")
            login->setText(xmlReader.readElementText());
        if (xmlReader.name() == "password")
            password->setText(xmlReader.readElementText());
        if (xmlReader.name() == "checkbox")
            if (xmlReader.readElementText() == "true")
                saveMe->setChecked(true);
    }
    xmlFile.close();
}

void LoginWindow::SaveInXML()
{
    QFile xmlFile("../config/userdata.xml");
    xmlFile.open(QIODevice::ReadWrite | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&xmlFile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("config");
    xmlWriter.writeStartElement("login");
    xmlWriter.writeCharacters(saveMe->isChecked() ? login->text() : "");
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("password");
    xmlWriter.writeCharacters(saveMe->isChecked() ? password->text() : "");
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("checkbox");
    xmlWriter.writeCharacters(saveMe->isChecked() ? "true" : "false");
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    xmlFile.close();
}
