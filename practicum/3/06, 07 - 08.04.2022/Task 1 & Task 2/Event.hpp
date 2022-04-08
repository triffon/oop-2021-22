#pragma once

#include "DateTime.hpp"

class Event {
    char *name;

  public:
    DateTime start;
    DateTime end;

    Event();
    Event(const char *name, const DateTime &start, const DateTime &end);
    Event(const Event &o);
    ~Event();

    const char *getName() const;
    void setName(const char *name);

    void serialize(std::ostream &out) const;
    void deserialize(std::istream &in);
    
	Event &operator=(const Event &o);

    friend std::ostream &operator<<(std::ostream &out, const Event &d);
};