#include <iostream>

class rational
{
 public:
    explicit rational(int nom = 0, int denom = 1);

    int nom() const;
    int denom() const;

    operator bool() const;
    operator double() const;

    rational& operator++();
    rational& operator+=(const rational&);
    rational& operator+=(int);
    rational operator++(int);

    friend std::istream& operator>>(std::istream&, rational&);
 private:
    int m_nom{0};
    int m_denom{1};

    void normalize();
};

int gcd(int, int);

rational operator+(const rational&, const rational&);
rational operator+(const rational&, int);
rational operator+(int, const rational&);

rational operator*(const rational&, const rational&);
rational operator*(const rational&, int);
rational operator*(int, const rational&);

// TODO: - /

bool operator==(const rational&, const rational&);
bool operator<(const rational&, const rational&);
bool operator!=(const rational&, const rational&);
bool operator<=(const rational&, const rational&);
bool operator>(const rational&, const rational&);
bool operator>=(const rational&, const rational&);

rational operator-(const rational&);

std::ostream& operator<<(std::ostream&, const rational&);
