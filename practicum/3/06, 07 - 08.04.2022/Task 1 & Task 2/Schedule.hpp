#ifndef __SCHEDULE_HPP__
#define __SCHEDULE_HPP__

#include "Event.hpp"

#include <stddef.h>

class Schedule {
    char *name;
    Event *events;
    size_t eventsCapacity;
    size_t eventsSize;

    void copyEvents(const Event *events, size_t eventSize);

  public:
    Schedule();
    Schedule(const char *name, const Event *events, size_t eventSize);
    Schedule(const Schedule &o);
    ~Schedule();

    const char *getName() const;
    void setName(const char *name);

    size_t getEventsSize() const;

    Event *getEvents();
    void addEvent(const Event &e);
    void removeLastEvent();

    Schedule &operator=(const Schedule &o);

    friend std::ostream &operator<<(std::ostream &out, const Schedule &d);
};

#endif // __SCHEDULE_HPP__