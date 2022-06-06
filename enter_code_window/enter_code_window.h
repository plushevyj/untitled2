//
// Created by kirill on 6/6/22.
//

#ifndef UNTITLED2_ENTER_CODE_WINDOW_H
#define UNTITLED2_ENTER_CODE_WINDOW_H

#include <QtWidgets>

class EnterCodeWindow : public QDialog {
    Q_OBJECT

public:
    explicit EnterCodeWindow(QWidget *pattern = nullptr);

    QLabel* description;
    QLineEdit* code;
    QPushButton* enter;
    QPushButton* back;
    QVBoxLayout* mainLayout;


};


#endif //UNTITLED2_ENTER_CODE_WINDOW_H
