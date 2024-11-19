#pragma once

#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <QObject>
#include <QThread>

using namespace std;

class KoDInput: public QThread {
    Q_OBJECT
    Q_PROPERTY(int position READ getPosition NOTIFY positionChanged)
    Q_PROPERTY(int buttonStatus READ getButtonStatus NOTIFY buttonStatusChanged)

public:
    KoDInput(int r);

    int getPosition();
    int getButtonStatus();

signals:
    void positionChanged(int value);
    void buttonStatusChanged(int value);

private:
    void run() override;
    int position = 0;
    int buttonStatus = 0;
    int range = 0;
};
