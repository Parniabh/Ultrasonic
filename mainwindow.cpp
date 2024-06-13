#include "mainwindow.h"
#include <wiringPi.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Setup UI
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    distanceLabel = new QLabel("Distance: -- cm", this);
    measureButton = new QPushButton("Measure Distance", this);

    layout = new QVBoxLayout();
    layout->addWidget(distanceLabel);
    layout->addWidget(measureButton);

    centralWidget->setLayout(layout);

    connect(measureButton, &QPushButton::clicked, this, &MainWindow::measureDistance);

    // Setup GPIO
  wiringPiSetup();
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

MainWindow::~MainWindow() {
}

void MainWindow::measureDistance() {
    // Send a 10us pulse to trigger pin
    digitalWrite(triggerPin, LOW);
    delay(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Wait for echo start
    while (digitalRead(echoPin) == LOW);
    long startTime = micros();

    // Wait for echo end
    while (digitalRead(echoPin) == HIGH);
    long travelTime = micros() - startTime;

    // Calculate distance in cm
    int distance = travelTime / 58;

    // Update label
    distanceLabel->setText(QString("Distance: %1 cm").arg(distance));
}

