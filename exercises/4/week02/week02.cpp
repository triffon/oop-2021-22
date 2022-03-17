#include <iostream>
#include <assert.h>
using namespace  std;

/*struct dummy {
   int a;
   long long b;
   bool c;

};

struct dummy1 {
    int a;
    bool c;
    long long b;
};
*/

struct Fraction {
    void setNumerator(int numerator) {
        this -> numerator = numerator;
        // int a = 5
        // a = a
        // (*this).
        // this->
    }
    // Default constructor
    Fraction () {
        cout<<"Fraction"<<endl;
        numerator = 0;
        denumerator = 1;
    }

    // Destructor
    ~Fraction () {
        cout<<"~Fraction"<<endl;
     }
    void setDenumerator(int denumerator) {
        assert(denumerator != 0);
        this -> denumerator = denumerator;
    }
    int getDenumerator() {
       return denumerator;
    }
    int getNumerator() {
        return numerator;
    }

    void print() {
        cout<<numerator<<"/"<<denumerator<<endl;
    }

    void add(Fraction other) {
         numerator =
                numerator * other.denumerator + other.numerator * denumerator;
         denumerator = denumerator * other.denumerator;
        normalize();
    }
    void multiply(Fraction other) {
        numerator =
                numerator * other.numerator;
        denumerator = denumerator * other.denumerator;
        normalize();
    }

    void div(Fraction other) {
        assert(other.numerator != 0);
        numerator =
                numerator * other.denumerator;
        denumerator = denumerator * other.numerator;
        normalize();
    }
    // TO DO add remove
private: // public ....
    int numerator, denumerator;
    int gcd(int a, int b) {
        if (b == 0) return a;
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    void normalize() {
        int number = gcd(numerator, denumerator);
        numerator /= number;
        denumerator /= number;
    }
};

int main() {
   /*
    cout<<sizeof(int)<<" "<<sizeof(long long)<<" "<<sizeof(bool)<<endl;
    cout<<sizeof(dummy)<<endl;
    cout<<sizeof(dummy1)<<endl;
   */

   Fraction first;
   cout<<"----"<<endl;
   // first.denumerator = 1;
   // first.numerator = 1;

    first.setNumerator(2);
    first.setDenumerator(1);
    // first.setDenumerator(0); will thrown an error because of 0
    Fraction second;
    second.setNumerator(4);
    second.setDenumerator(2);
    first.add(second);

    // ??? a + b
    // a --> a.add(b)

    first.print();
    first.multiply(second);
    first.print();
    first.div(first);
    first.print();



	// Fraction* test = new Fraction [10];

	//delete [] test;
    return 0;
}
