#include "Schedule.hpp"

#include "Event.hpp"
#include <cstring>

#pragma warning(disable : 4996)

void Schedule::copyEvents(const Event *events, size_t eventsSize) {
    if (this->events != nullptr)
        delete[] this->events;

    this->events = new Event[eventsSize];
    for (size_t i = 0; i < eventsSize; i++) {
        this->events[i] = events[i];
    }
    this->eventsCapacity = eventsSize;
    this->eventsSize = eventsSize;
}

Schedule::Schedule() {
    this->name = nullptr;
    this->eventsCapacity = 4;
    this->events = new Event[this->eventsCapacity];
    this->eventsSize = 0;
}

Schedule::Schedule(const char *name, const Event *events, size_t eventsSize) : Schedule() {
    this->setName(name);
    this->copyEvents(events, eventsSize);
}

Schedule::Schedule(const Schedule &o) : Schedule() {
    this->setName(o.name);
    this->copyEvents(o.events, o.eventsSize);
}

Schedule::~Schedule() {
    if (this->name != nullptr)
        delete[] this->name;

    if (this->events != nullptr)
        delete[] this->events;
}

Schedule &Schedule::operator=(const Schedule &o) {
    if (this == &o)
        return *this;

    this->setName(o.name);
    this->copyEvents(o.events, o.eventsSize);

    return *this;
}

const char *Schedule::getName() const {
    return this->name;
}

void Schedule::setName(const char *name) {
    if (this->name != nullptr)
        delete[] this->name;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

size_t Schedule::getEventsSize() const {
    return this->eventsSize;
}

Event *Schedule::getEvents() {
    return this->events;
}

void Schedule::addEvent(const Event &e) {
    if (this->eventsSize == this->eventsCapacity) {
        this->eventsCapacity *= 2;
        Event *newEvents = new Event[this->eventsCapacity];

        for (size_t i = 0; i < this->eventsSize; i++) {
            newEvents[i] = this->events[i];
        }

        delete[] this->events;

        this->events = newEvents;
    }

    this->events[this->eventsSize++] = e;
}

void Schedule::removeLastEvent() {
    this->eventsSize--;
}

std::ostream &operator<<(std::ostream &out, const Schedule &d) {
    out << "SCHEDULE: " << d.name << std::endl;
    for (size_t i = 0; i < d.eventsSize; i++) {
        out << "\t" << d.events[i] << std::endl;
    }

    return out;
}