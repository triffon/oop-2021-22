#include "Event.hpp"

#include "DateTime.hpp"
#include <cstring>

#pragma warning(disable : 4996)

Event::Event() : start(), end() {
    this->name = nullptr;
}

Event::Event(const char *name, const DateTime &start, const DateTime &end) : Event() {
    this->setName(name);
    this->start = start;
    this->end = end;
}

Event::Event(const Event &o) : Event() {
    this->setName(o.name);
    this->start = o.start;
    this->end = o.end;
}

Event::~Event() {
    if (this->name != nullptr)
        delete[] this->name;
}

const char *Event::getName() const {
    return this->name;
}

void Event::setName(const char *name) {
    if (this->name != nullptr)
        delete[] this->name;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Event::serialize(std::ostream &out) const {
    this->start.serialize(out);
    this->end.serialize(out);
    int len = strlen(this->name);
    out.write((char *)&len, sizeof(len));
    out.write(this->name, len);
}

void Event::deserialize(std::istream &in) {
    this->start.deserialize(in);
    this->end.deserialize(in);
    int len;
    in.read((char *)&len, sizeof(len));
    char *name = new char[len + 1];

    in.read(name, len);
    name[len] = '\0';

    this->setName(name);
    delete[] name;
}

Event &Event::operator=(const Event &o) {
    if (this == &o)
        return *this;

    this->setName(o.name);
    this->start = o.start;
    this->end = o.end;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Event &d) {
    out << d.name << " from: " << d.start << " to: " << d.end;

    return out;
}