#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include "engine.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QVBoxLayout mainLayout;
    QPushButton *createMapButton;
    QPushButton *saveMapButton;
    QLineEdit *mapNameLineEdit;

    QSpinBox widthNumber, heightNumber;

    Engine *engine;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



public slots:
    void CreateMap();
    void SaveMap();



};
#endif // MAINWINDOW_H
