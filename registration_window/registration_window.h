#ifndef UNTITLED2_REGISTRATION_WINDOW_H
#define UNTITLED2_REGISTRATION_WINDOW_H

#include <QtWidgets>

class RegistrationWindow : public QDialog {
    Q_OBJECT

    int idUser;
public:
    RegistrationWindow(int idUser) {
        this->idUser = idUser;
    }

    QLabel* nameLabel;
    QLabel* name;
    QLabel* jobTitleLabel;
    QLabel* jobTitle;
    QLabel* newLoginLabel;
    QLineEdit* newLogin;
    QLabel* newPasswordLabel;
    QLineEdit* newPassword;
};


#endif //UNTITLED2_REGISTRATION_WINDOW_H
