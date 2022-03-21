#include <iostream>
#include <cstring>

const size_t MAX_PRODUCTS = 1000; // Max length of products in Night Club.


struct Balloon {
           
private:    //Private members which are visible only in struct Balloon
    double price;
    char* color ;

   //Allocating dynamic memory and copping value of given char array.
   void copy(const char* color) {
       free();
       size_t len = strlen(color);
       this->color = new (std::nothrow) char[len + 1];
       if (!this->color) {
           std::cout << "Error with allocating dynamic memory!";
           return;
       }
       strcpy(this->color, color);
   }
   
public:  
    //Free dynamic allocated memory.
    void free() {
        delete[] color;
        color = nullptr;
    }

    double getPrice() const{ return price; }
    
    void setPrice(double price) { this->price = price; }

    const char* getColor() const{ return color; }

    void setColor(const char* color) { copy(color); }
 

    //Default constructor.
    Balloon() :price(0), color(nullptr) { }

    //Constructor with parameters.
    Balloon(const char* color, double price) : price(price) { copy(color); }

    Balloon(const Balloon &other)
    {
        price = other.price;
        color = nullptr;
        copy(other.color);
    }

    Balloon& operator=(const Balloon &other)
    {
        if (this != &other)
        {
            price = other.price;
            color = nullptr;
            copy(other.color);
        }

        return *this;
    }

    //Destructor
    ~Balloon() {free(); }
    void print() {
        std::cout << "color: " << color << " price: " << price << "\n";
    }
}; 

struct Shisha
{
private:
   
    double price;
    char* brand;
    char* taste;
     
    //Allocate and copy dynamic char array.
    void allocate(char*& destination, const char* source) {
        if (destination) {
            delete[] destination;
            destination = nullptr;
        }

        size_t len = strlen(source);
        destination = new (std::nothrow) char[len + 1];

        if (!destination) {
            std::cout << "Error with allocating dynamic memory" << std::endl;
            return;
        }

        strcpy(destination, source);
    }
public:
    void  free() {
        delete[] brand;
        delete[] taste;
        brand = nullptr;
        taste = nullptr;
    }

    double getPrice() const { return price; }
    
    const char* getBrand() const { return brand; }
    
    const char* getTaste() const { return taste; }


    void setPrice(double price) { this->price = price; }

    void setBrand(const char* brand) { allocate(this->brand, brand); }

    void setTaste(const char* taste) { allocate(this->taste, taste); }
    

    Shisha() : price(0) ,brand(nullptr), taste(nullptr) {}
    
    Shisha(double price,const char* brand, const char* taste)
        : price(price), brand(nullptr), taste(nullptr)
    {
       allocate(this->brand,brand);
       allocate(this->taste,taste);
    }

    Shisha(const Shisha &other) {
        brand = nullptr;
        taste = nullptr;
        price = other.price;
        allocate(this->brand, other.brand);
        allocate(this->taste, other.taste);
    }

    Shisha& operator=(const Shisha &other)
    {
        if (this != &other)
        {
            brand = nullptr;
            taste = nullptr;
            price = other.price;
            allocate(this->brand, other.brand);
            allocate(this->taste, other.taste);
        }

        return *this;
    }
    
    ~Shisha() {
        free();
    }
    
    void print()
    {
        std::cout << "Brand: " << brand << " taste: " << taste << " price: " << price << "\n";
    }
}; 


struct Alcohol
{ 
private:   
    double price;
    char* name;
   
    void allocate(const char* name) {
        free();
        size_t len = strlen(name);
        this->name = new (std::nothrow) char[len + 1];
        if (!this->name) {
            std::cout << " Error with allocating dynamic memory " << std::endl;
        }
        strcpy(this->name, name);
    }

public:
    void  free() {
        delete[] name;
        name = nullptr;
    }

    double getPrice() const { return price; }

    void setPrice(double price) { this->price = price; }

    const char* getName() const { return name; }

    void setName(const char* color) { allocate(color); }

    void print() {
        std::cout << "name: " << name << " price " << price << "\n";
    }

    Alcohol() :price(0), name(nullptr) { }

    Alcohol(double price,const char* name) : price(price), name(nullptr) {
        allocate(name);
    }

    Alcohol(const Alcohol &other)
    {
        price = other.price;
        name = nullptr;
        allocate(other.name);
    }

    ~Alcohol() {
        free();
    }
};

struct NightClub {

private:
    //Array from type Balloon.
    Balloon balloons[MAX_PRODUCTS]{};
    std::size_t  sizeBalloons;

    Alcohol alcohols[MAX_PRODUCTS]{};
    std::size_t sizeAlcohols;

    Shisha shishas[MAX_PRODUCTS]{};
    std::size_t sizeShishas;  
    
public:
    NightClub() : sizeBalloons(0), sizeShishas(0), sizeAlcohols(0) { }

    void addBallon(const char* color, double price) {

        this->balloons[sizeBalloons].setColor(color);
        this->balloons[sizeBalloons].setPrice(price);
        sizeBalloons++;
    }    

    void addShisha(const char* brand, const char* taste, double price) {
        shishas[sizeShishas].setPrice(price);
        shishas[sizeShishas].setBrand(brand);
        shishas[sizeShishas].setTaste(taste);
        sizeShishas++;    }
    
    void addAlcohol(const char* name, double price){
       
       alcohols[sizeAlcohols].setName(name);
       alcohols[sizeAlcohols].setPrice(price);
       sizeAlcohols++;
    }


    bool findBalloon(const char* color) {
        for (std::size_t i = 0; i < this->sizeBalloons; ++i)
        {
            if (strcmp(balloons[i].getColor(), color) == 0)
            {
                return true;
            }
        }
        return false;
    } 

    bool findShisha(const char* brand, const char* taste) {
        for (std::size_t i = 0; i < sizeShishas; ++i)
        {
            if (strcmp(shishas[i].getBrand(), brand) == 0 && strcmp(shishas[i].getTaste(), taste) == 0)
            {
                return true;
            }
        }
        return false;
    }

    bool findAlcohol(const char* name) {
        for (std::size_t i = 0; i < sizeAlcohols; ++i)
        {
            if (strcmp(alcohols[i].getName(), name) == 0)
            {
                return true;
            }
        }
        return false;
    }


    bool removeBalloon(const char* color)
    {
        for (std::size_t i = 0; i < this->sizeBalloons; ++i)
        {
            if (strcmp(balloons[i].getColor(), color) == 0)
            {
                sizeBalloons--;
                if (sizeBalloons != 0)
                {
                    balloons[i].setColor(balloons[sizeBalloons].getColor());
                    balloons[i].setPrice(balloons[sizeBalloons].getPrice());
                }
                balloons[sizeBalloons].free();
                return true;
            }
        }
        return false;
    }

    bool removeShisha(const char* brand, const char* taste) {
        for (std::size_t i = 0; i < this->sizeShishas; i++)
        {
            if (strcmp(shishas[i].getBrand(), brand) == 0 && strcmp(shishas[i].getTaste(), taste) == 0)
            {
                sizeShishas--;
                if (sizeShishas != 0)
                {
                    shishas[i].setBrand(shishas[sizeShishas].getBrand());
                    shishas[i].setTaste(shishas[sizeShishas].getTaste());
                    shishas[i].setPrice(shishas[sizeShishas].getPrice());
                }
                shishas[sizeShishas].free();
                shishas[sizeShishas].free();
                return true;                
            }
        }
        return false;
    }

    bool removeAlcohol(const char* name) {
        for (std::size_t i = 0; i < sizeAlcohols; ++i)
        {
            if (findAlcohol(name))
            {
                sizeAlcohols--;
                if (sizeAlcohols != 0)
                {
                    alcohols[i].setName(alcohols[sizeAlcohols].getName());
                    alcohols[i].setPrice(alcohols[sizeAlcohols].getPrice());
                }
                alcohols[sizeAlcohols].free();

                return true;
            }
        }
        return false;
    }


    void printBalloon() {

        std::cout << "Balloons in Night Club:\n";
        for (int i = 0; i < sizeBalloons; i++) {
            std::cout << "\t" << i + 1 << ". ";
            balloons[i].print();
        }
    }

    void printShisha(){
        std::cout << "Shishas in Night Club:\n";
        for (int i = 0; i < sizeShishas; i++) {
            std::cout << "\t" << i + 1 << ". ";
            shishas[i].print();
        }
    }

    void printAlcohol() {
        std::cout << "Alcohols in Night Club:\n";
        for (int i = 0; i < sizeAlcohols; i++) {
            std::cout << "\t" << i + 1 << ". ";
            alcohols[i].print();
        }
    }

    void print() {
        printBalloon();
        printShisha();
        printAlcohol();       
    }
};

int main()
{ 
    NightClub nc;
    
    nc.addBallon("red", 3.2);
    nc.addBallon("green", 4.4);
    nc.addBallon("yellow" , 2.5);
    std::cout << "\n";
    nc.printBalloon();
    std::cout << "\n";
    
    if (!nc.removeBalloon("red")) {
        std::cout << "Error!\n";
    }
    nc.printBalloon();
    std::cout << "\n";
    nc.addAlcohol("Alaska", 7.2);
    nc.addAlcohol("Dom Perignon", 12.5);
    nc.addAlcohol("Tomatin", 99.9);
    nc.printAlcohol();
    std::cout << "\n";
    if (!nc.removeAlcohol("Alaska")) {
        std::cout << "Error!\n";
    }
    nc.printAlcohol();
    std::cout << "\n";

    nc.addShisha("Holster", "Strong Lemon", 17.55);
    nc.addShisha("Amazing", "Beach Party", 18.99);
    nc.addShisha("Zomo", "Strong Passion", 13.45);
    nc.addShisha("Amazing", "Ice cream", 13.45);
    nc.printShisha();
    std::cout << "\n";

    if (!nc.removeShisha("Zomo", "Strong Passion")){
        std::cout << "Error!\n";
    }
    nc.printShisha();
    std::cout << "\n";

    nc.print();

    return 0;
}

