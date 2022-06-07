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
        QSpinBox* age;
        QSlider* sliderAge;
        QLabel* newLoginLabel;
        QLineEdit* newLogin;
        QLabel* newPasswordLabel;
        QLineEdit* newPassword;
        QLabel* successPasswordLabel;
        QLineEdit* successPassword;
        QCheckBox* agree;
        QPushButton* enter;
        QPushButton* back;

        QHBoxLayout* ageLayout;
        QGroupBox* ageGroup;
        QVBoxLayout* mainlayout;

        QLabel* lblg;
        QComboBox* langs;
        QGroupBox* box2;
        QRadioButton* genM;
        QRadioButton* genF;
        QHBoxLayout* layout2;
    };


    #endif //UNTITLED2_REGISTRATION_WINDOW_H
