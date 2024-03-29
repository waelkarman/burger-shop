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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, range);
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int value = distrib(gen);
        emit positionChanged(value);
    }


    // int fd = open("/dev/input/event2", O_RDONLY);
    // if (fd < 0) {
    //     std::cerr << "Error." << std::endl;
    // }

    // input_event ev;
    // while (read(fd, &ev, sizeof(ev)) == sizeof(ev)) {
    //     if(ev.code == 8){
    //         std::cout << "Event type: " << ev.type << ", code: " << ev.code << ", Value: " << ev.value << std::endl;
    //         position=ev.value;
    //         emit positionChanged();
    //     }
    // }

    // close(fd);
};


int KoDInput::getPosition(){
    return position;
};
