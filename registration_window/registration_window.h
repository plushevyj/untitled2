#ifndef UNTITLED2_REGISTRATION_WINDOW_H
#define UNTITLED2_REGISTRATION_WINDOW_H

#include <QtWidgets>

class RegistrationWindow : public QDialog {
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *pattern = nullptr);

    int idUser{};
    QLabel* nameLabel;
    QLabel* name;
    QLabel* jobTitleLabel;
    QLabel* jobTitle;
    QLabel* newLoginLabel;
    QLineEdit* newLogin;
    QLabel* newPasswordLabel;
    QLineEdit* newPassword;
    QLabel* successPasswordLabel;
    QLineEdit* successPassword;
    QPushButton* enter;
    QPushButton* back;

    QVBoxLayout* mainlayout;
};


#endif //UNTITLED2_REGISTRATION_WINDOW_H
