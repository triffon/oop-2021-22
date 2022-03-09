struct Rational {
    // ниво 0: представяне
    // numer е цяло число
    // denom е положително число
    // gcd(numer,denom) = 1
    long numer, denom;

    // ниво 1: конструктори

    // конструктор по подразбиране
    Rational();

    // конструктор с параметри
    Rational(long _numer, long _denom);

    // ниво 1: селектори за достъп
    long getNumerator()   const { return numer; }
    long getDenominator() const { return denom; }

    // ниво 1: селектори за извеждане
    void print()   const;
    void printnl() const;

    // ниво 1: селектор за конвертиране
    double toDouble() const; 

    // ниво 1: мутатор за въвеждане
    void read();

    // ниво 1: вътрешна функция за нормализация
    void normalize();
};

// ниво 2: аритметични операции за умножение и събиране
Rational multiply(Rational const& p, Rational const& q);
Rational add(Rational const& p, Rational const& q);