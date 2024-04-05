#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <random>

#include <iostream>
#include "KoDInput.hpp"

using namespace std;

KoDInput::KoDInput(int r){
    range = r;
    this->start();
}

void KoDInput::run(){

    int fd = -1;
    while (fd < 0) {
        fd = open("/dev/input/event2", O_RDONLY);
        std::cerr << "Error." << std::endl;
    }

    input_event ev;
    while (read(fd, &ev, sizeof(ev)) == sizeof(ev)) {
        //std::cout << "Event type: " << ev.type << ", code: " << ev.code << ", Value: " << ev.value << std::endl;
        if(ev.code == 8){
            int scarto = ev.value-position;
            position = ev.value;
            if(scarto==30){scarto=-1;}
            if(scarto==-31){scarto=1;}
            emit positionChanged(scarto);
        }
        //if(ev.code == 330){
        //    buttonStatus=ev.value;
        //    emit buttonStatusChanged(ev.value);
        //}
    }

    close(fd);
};


int KoDInput::getPosition(){
    return position;
};

int KoDInput::getButtonStatus(){
    return buttonStatus;
};
