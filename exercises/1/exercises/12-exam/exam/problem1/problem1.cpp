#include <iostream>
#include <cstring>

class String
{
 public:
    String() = default;
    String(const char *);
    ~String();
    String(const String&);
    String& operator=(const String&);

    friend std::ostream& operator<<(std::ostream&, const String&);
 private:
    char * m_data{nullptr};
    size_t m_size{0};
};

String::String(const char * str)
{
    if (str)
    {
        size_t len{strlen(str)};
        m_data = new char[len + 1];
        m_size = len;
        strcpy(m_data, str);
    }
    else
    {
        m_data = nullptr;
        m_size = 0;
    }
}

String::~String()
{
    delete [] m_data;
}

String::String(const String& other):
    m_data{other.m_size ? new char[other.m_size + 1] : nullptr},
    m_size{other.m_size}
{
    strcpy(m_data, other.m_data);
}

String& String::operator=(const String& other)
{
    String copy{other};
    std::swap(m_data, copy.m_data);
    std::swap(m_size, copy.m_size);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.m_data;
}

struct AirTravel
{
    String flight_number;
    unsigned duration{0};

    void print() const;
};

void AirTravel::print() const
{
    std::cout << flight_number << ' ' << duration << '\n';
}

struct CarTravel
{
    unsigned reg_number[4]{};
    unsigned distance{0};
    unsigned duration{0};

    void print() const;
};

void CarTravel::print() const
{
    std::cout << reg_number[0] << reg_number[1] << reg_number[2] << reg_number[3] << ' ' << distance << ' ' << duration << '\n';
}

// TODO: vector
#include <vector>

struct CombinedTrip: public AirTravel, public CarTravel
{
    std::vector<String> destinations;
    unsigned free_time{0};

    unsigned get_duration() const;
    void print() const;
};

unsigned CombinedTrip::get_duration() const
{
    return free_time + CarTravel::duration + AirTravel::duration;
}

void CombinedTrip::print() const
{
    AirTravel::print();
    CarTravel::print();
    for (const String& destination : destinations)
    {
        std::cout << destination << '\n';
    }

    std::cout << free_time << '\n';
}

int main()
{

    CombinedTrip combo{
        AirTravel{
            "FNO123876",
            60 // duration
        },
        CarTravel{
            {1, 2, 3, 4},
            100, // distance
            120, // duration
        },
        std::vector<String>{"Plovdiv", "Sofia"},
        20 // free time
    };

    combo.print();

    std::cout << combo.get_duration();
    return 0;
}
