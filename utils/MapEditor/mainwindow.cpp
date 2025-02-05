#include "mainwindow.h"
#include "QLabel"
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *mainWidget = new QWidget(this);
    mainLayout.addWidget(new QLabel("Map Width"));
    mainLayout.addWidget(&widthNumber);

    mainLayout.addWidget(new QLabel("Map Height"));
    mainLayout.addWidget(&heightNumber);

    mapNameLineEdit = new QLineEdit();
    mapNameLineEdit->setPlaceholderText("Enter map name");
    mainLayout.addWidget(mapNameLineEdit);

    mainLayout.addStretch();

    createMapButton = new QPushButton("Create Map", this);
    mainLayout.addWidget(createMapButton);


    saveMapButton = new QPushButton("Save Map", this);
    mainLayout.addWidget(saveMapButton);

    widthNumber.setValue(40);
    heightNumber.setValue(40);


    mainWidget->setLayout(&mainLayout);
    setCentralWidget(mainWidget);

    connect(createMapButton, &QPushButton::clicked, this, &MainWindow::CreateMap);
    connect(saveMapButton, &QPushButton::clicked, this, &MainWindow::SaveMap);

}

MainWindow::~MainWindow()
{
}

void MainWindow::CreateMap() {
    qDebug() << "Creating map. Width: " << widthNumber.value() << " height: " << heightNumber.value();
    engine = new Engine(mapNameLineEdit->text(), widthNumber.value(), heightNumber.value());

    engine->show();
}

void MainWindow::SaveMap() {
    qDebug() << "Saving map. Width: " << widthNumber.value() << " height: " << heightNumber.value();
}
