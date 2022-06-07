#ifndef UNTITLED2_LOGIN_WINDOW_H
#define UNTITLED2_LOGIN_WINDOW_H


#include <QtWidgets>

class LoginWindow : public QDialog{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *pattern = nullptr);

    QLabel* loginLabel;
    QLineEdit* login;
    QLabel* passwordLabel;
    QLineEdit* password;
    QCheckBox* saveMe;
    QPushButton* enter;
    QSpacerItem* spacer;
    QPushButton* haveCodeLabel;
    QVBoxLayout* mainLayout;
    QVBoxLayout* layout1;
    QGroupBox* box;

    void pushEnterButtonListener();
    void DataAutofillFromXML();
    void SaveInXML();
};


#endif //UNTITLED2_LOGIN_WINDOW_H
