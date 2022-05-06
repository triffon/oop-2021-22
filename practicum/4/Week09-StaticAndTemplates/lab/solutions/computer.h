#pragma once

#include <cstddef>
#include <string>
#include <fstream>

class Computer
{
private:
    static std::size_t counter;
    std::size_t serialNumber;
    std::string brand;
    std::string processor;
    std::size_t video;
    std::size_t hardDrive;
    double weight;
    double batteryLife;
    double price;
    std::size_t quantity;  

public:
    Computer() = default;
    Computer(const std::string& brand, const std::string& processor, 
    std::size_t video, std::size_t hardDrive, double weight, 
    double batteryLife, double price, std::size_t quantity);

    std::string getBrand() const;
    std::string getProcessor() const;
    std::size_t getVideo() const;
    std::size_t getHardDrive() const;
    double getWeight() const;
    double getBatteryLife() const;
    double getPrice() const;
    std::size_t getQuantity() const;

    void setBrand(const std::string& brand);
    void setProcessor(const std::string& processor);
    void setVideo(std::size_t video);
    void setHardDrive(std::size_t hardDrive);
    void setWeight(double weight);
    void setBatteryLife(double batteryLife);
    void setPrice(double price);
    void setQuantity(std::size_t quantity);

    void increaseQuantityBy(std::size_t quantityToAdd);
    void decreaseQuantity();

    bool operator == (const Computer& other) const;

    friend std::istream& operator >> (std::istream& in, Computer& computer);
    friend std::ostream& operator << (std::ostream& out, const Computer& computer);
};