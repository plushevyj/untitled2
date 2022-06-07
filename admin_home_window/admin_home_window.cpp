#include "admin_home_window.h"
#include "../sql_service/sql_service.h"

AdminHomeWindow::AdminHomeWindow() : QMainWindow()
{
    auto db = SqlService::connectToDB();
    db.open();
    auto result = db.exec(
        "SELECT a.name, b.name, c.task, c.date_begin, c.date_end FROM admins as a, employees as b, tasks as c WHERE c.id_admin = a.id and c.id_employee = b.id");
    result.next();
    area = new QWidget;
    setCentralWidget(area);

    login = new QLabel("Администратор: Василий");
    exit = new QPushButton("Выход");
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    layout1 = new QBoxLayout(QBoxLayout::RightToLeft);
    layout1->addWidget(exit);
    layout1->addWidget(login);
    layout1->addStretch(1);


    nametable = new QLabel("Задания");
    table = new QTableWidget(this);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels(QStringList() << "Админ" << "Сотрудник" << "Задача" << "Дата начала выполения" << "Дата окончания выполнения");
    table->insertRow(table->rowCount());
    table->insertRow(table->rowCount());

    table->horizontalHeader()->setStretchLastSection(true);
    scroll = new QScrollBar(Qt::Horizontal);

    otchet = new QPushButton("Перейти к отчету");
    layout3 = new QVBoxLayout();
    layout3->addWidget(scroll);
    layout3->addWidget(nametable);
    layout3->addWidget(table);
    layout3->addWidget(otchet);

    employeeLayout = new QVBoxLayout();
    employee = new QListWidget();
    employee->addItems({"Михаил Зубенко", "Егор Петров", "Оксана Дмитреева", "Иван Иванов"});
    employeeLayout->addWidget(employee);
    employeeLayout->addStretch(1);


    layout2 = new QHBoxLayout();
    layout2->addWidget(employee);
    layout2->addLayout(layout3);

    mainlayout = new QVBoxLayout();
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);

    menubar = new QMenuBar();
    CreateMenuBar();

    setWindowTitle("CRM");
    area->setLayout(mainlayout);
    mainlayout->setMenuBar(menubar);

}

void AdminHomeWindow::CreateMenuBar()
{
    QMenu *main = new QMenu("&Меню");
    main->addAction("&Профиль");
    main->addAction("&Создать новую задачу");
    QMenu* subMenu = new QMenu("&Отчетность", main);
    main->addMenu(subMenu);
    subMenu->addAction("&Scrum");
    subMenu->addAction("&Результаты работы сотрудников");
    main->addAction("&Выход", this, SLOT(close()));

    menubar->addMenu(main);
    QMenu * help = new QMenu("&О программе");
    help->addAction("&О Qt");
    help->addAction("&Помощь");
    menubar->addMenu(help);

}

