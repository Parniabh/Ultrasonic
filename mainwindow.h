#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void measureDistance();

private:
    QLabel *distanceLabel;
    QPushButton *measureButton;
    QVBoxLayout *layout;

    int triggerPin = 0; // GPIO pin connected to the trigger pin of the ultrasonic sensor
    int echoPin = 1;    // GPIO pin connected to the echo pin of the ultrasonic sensor
};

#endif // MAINWINDOW_H
