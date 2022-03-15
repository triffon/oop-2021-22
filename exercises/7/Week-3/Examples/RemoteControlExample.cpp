/*
    Problem: Write a C++ class that represents an abstract remote control.
             A remote control can report its battery charge (float), its
             model (char*), can move between channels, set a given channel,
             adjust the volume and open a menu.
*/

#include<iostream>
#include<string.h>

using namespace std;

class RemoteControl
{
private:
    float batteryCharge;
    char *model;

public:
    RemoteControl(const char* model, float batteryCharge) {
        this->model = new char[strlen(model)];
        strcpy(this->model, model);

        this->batteryCharge = batteryCharge;
    }

    ~RemoteControl() {
        delete[] this->model;
    }

    char* getModel() const {
        return this->model;
    }

    float getBatteryCharge() const {
        return this->batteryCharge;
    }

    void setChannel(unsigned int channel) {
        cout << "Called 'setChannel' on RC " << model <<  " with channel " << channel << endl;
    }

    void channelUp() {
        cout << "Called 'channelUp' on RC " << model << endl;
    }

    void channelDown() {
        cout << "Called 'channelDown' on RC " << model << endl;
    }

    void volumeUp() {
        cout << "Called 'volumeUp' on RC " << model << endl;
    }

    void volumeDown() {
        cout << "Called 'volumeDown' on RC " << model << endl;
    }

    void openMenu() {
        cout << "Called 'openMenu' on RC " << model << endl;
    }
};

int main() {
    RemoteControl sonyTV("SONY ASDJHAG", 0.5);
    RemoteControl lgTV("LG ASDSKANFKA", 0.5);

    sonyTV.channelDown();
    lgTV.channelUp();

    return 0;
}