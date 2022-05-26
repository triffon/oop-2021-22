#include <iostream>
#include <cassert>

class Time
{
 public:
    Time() = default;
    Time(unsigned, unsigned);

    unsigned minutes() const;
 private:
    unsigned m_minutes{0};
};

Time::Time(unsigned hours, unsigned minutes):
    m_minutes{hours * 60 + minutes}
{
    assert(m_minutes < 24 * 60);
}

unsigned Time::minutes() const
{
    return m_minutes;
}

int duration(const Time& start, const Time& end)
{
    return end.minutes() - start.minutes();
}

bool between(const Time& time, const Time& start, const Time& end)
{
    return time.minutes() >= start.minutes() && time.minutes() <= end.minutes();
}

class Event
{
 public:
    Event() = default;
    virtual ~Event() = default;
    
    virtual Event * clone() const = 0;
    virtual bool is_ongoing(const Time&) const = 0;
 protected:
    Event(const Event&) = default;
    Event& operator=(const Event&) = default;
};

class SimpleEvent: public Event
{
 public:
    SimpleEvent(const Time&, const Time&);

    SimpleEvent * clone() const final;
    bool is_ongoing(const Time&) const final;  
 private:
    Time m_start{};
    Time m_end{};
};

SimpleEvent::SimpleEvent(const Time& start, const Time& end):
    m_start{start},
    m_end{end}
{
    int event_duration{
        duration(m_start, m_end)
    };

    if (event_duration > 2 * 60 || event_duration < 0)
    {
        std::cout << "Error\n";
        m_start = {};
        m_end = {};
    }
}

SimpleEvent * SimpleEvent::clone() const
{
    return new SimpleEvent{*this};
}

bool SimpleEvent::is_ongoing(const Time& time) const
{
    return between(time, m_start, m_end);
}

class EventWithFixedIntermission: public Event
{
 public:
    EventWithFixedIntermission(const Time&, const Time&, const Time&);

    EventWithFixedIntermission * clone() const final;
    bool is_ongoing(const Time&) const final;  
 private:
    Time m_start{};
    Time m_break_start{};
    Time m_end{};
};

EventWithFixedIntermission::EventWithFixedIntermission(const Time& start, const Time& break_start, const Time& end):
    m_start{start},
    m_break_start{break_start},
    m_end{end}
{
    int event_duration{
        duration(m_start, m_end)
    };

    if (event_duration > 4 * 60 + 20
        || event_duration < 0
        || duration(m_break_start, m_end) < 20
        || duration(m_start, m_break_start) < 0
    )
    {
        std::cout << "Error\n";
        m_start = {0, 0};
        m_break_start = {0, 0};
        m_end = {0, 20};
    }
}

EventWithFixedIntermission * EventWithFixedIntermission::clone() const
{
    return new EventWithFixedIntermission{*this};
}

bool EventWithFixedIntermission::is_ongoing(const Time& time) const
{
    int time_from_break{
        duration(m_break_start, time)
    };

    return between(time, m_start, m_end) && (time_from_break < 0 || time_from_break > 20);
}

// TODO: smart pointers
class EventManager
{
 public:
    EventManager() = default;
    ~EventManager();
    EventManager(const EventManager&);
    EventManager& operator=(const EventManager&);

    bool add_event(const Event * event);
    size_t ongoing_events(const Time&) const;
 private:
    Event * m_events[100]{nullptr};
    size_t m_size{0};
};

EventManager::~EventManager()
{
    for (size_t i{0}; i < m_size; ++i)
    {
        delete m_events[i];
    }
}

EventManager::EventManager(const EventManager& other)
{
    for (size_t i{0}; i < m_size; ++i)
    {
        m_events[i] = other.m_events[i]->clone();
    }
}

EventManager& EventManager::operator=(const EventManager& other)
{
    EventManager copy{other};
    std::swap(m_size, copy.m_size);
    for (size_t i{0}; i < m_size; ++i)
    {
        std::swap(m_events[i], copy.m_events[i]);
    }
    return *this;
}

bool EventManager::add_event(const Event * event)
{
    if (m_size == 100)
    {
        return false;
    }

    m_events[m_size++] = event->clone();
    return true;
}

size_t EventManager::ongoing_events(const Time& time) const
{
    size_t count{0};

    for (size_t i{0}; i < m_size; ++i)
    {
        count += m_events[i]->is_ongoing(time);
    }

    return count;
}

int main()
{
    SimpleEvent e1{
        {0, 0},
        {2, 0}
    };

    SimpleEvent e2{
        {1, 0},
        {2, 0}
    };

    EventManager manager;

    manager.add_event(&e1);
    manager.add_event(&e1);
    manager.add_event(&e2);

    std::cout << manager.ongoing_events({0, 0}) << '\n';
    std::cout << manager.ongoing_events({1, 0}) << '\n';
    return 0;
}