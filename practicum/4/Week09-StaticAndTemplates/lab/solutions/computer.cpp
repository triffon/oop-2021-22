#include "computer.h"
#include <iostream>

std::size_t Computer::counter = 0;

Computer::Computer(const std::string& brand, const std::string& processor, 
    std::size_t video, std::size_t hardDrive, double weight, 
    double batteryLife, double price, std::size_t quantity)
    : brand(brand), processor(processor), video(video), hardDrive(hardDrive),
    weight(weight), batteryLife(batteryLife), price(price), quantity(quantity)
{
    this->serialNumber = Computer::counter++;
}

std::string Computer::getBrand() const
{
    return this->brand;
}

std::string Computer::getProcessor() const
{
    return this->processor;
}

std::size_t Computer::getVideo() const
{
    return this->video;
}

std::size_t Computer::getHardDrive() const
{
    return this->hardDrive;
}

double Computer::getWeight() const
{
    return this->weight;
}

double Computer::getBatteryLife() const
{
    return this->batteryLife;
}

double Computer::getPrice() const
{
    return this->price;
}

std::size_t Computer::getQuantity() const
{
    return this->quantity;
}

void Computer::setBrand(const std::string& brand)
{
    this->brand = brand;
}

void Computer::setProcessor(const std::string& processor)
{
    this->processor = processor;
}

void Computer::setVideo(std::size_t video)
{
    this->video = video;
}

void Computer::setHardDrive(std::size_t hardDrive)
{
    this->hardDrive = hardDrive;
}

void Computer::setWeight(double weight)
{
    this->weight = weight;
}

void Computer::setBatteryLife(double batteryLife)
{
    this->batteryLife = batteryLife;
}

void Computer::setPrice(double price)
{
    this->price = price;
}

void Computer::setQuantity(std::size_t quantity)
{
    this->quantity = quantity;
}

void Computer::increaseQuantityBy(std::size_t quantityToAdd)
{
    this->quantity += quantityToAdd;
}

void Computer::decreaseQuantity()
{
    --this->quantity;
}

bool Computer::operator == (const Computer& other) const
{
    return this->serialNumber == other.serialNumber;
}

std::istream& operator >> (std::istream& in, Computer& computer)
{
    std::cout << "Enter brand: ";
    in >> computer.brand;
    std::cout << "Enter processor: ";
    in >> computer.processor;
    std::cout << "Enter video: ";
    in >> computer.video;
    std::cout << "Enter hard drive: ";
    in >> computer.hardDrive;
    std::cout << "Enter weight: ";
    in >> computer.weight;
    std::cout << "Enter battery life: ";
    in >> computer.batteryLife;
    std::cout << "Enter price: ";
    in >> computer.price;
    std::cout << "Enter quantity: ";
    in >> computer.quantity;

    return in;
}

std::ostream& operator << (std::ostream& out, const Computer& computer)
{
    out << computer.serialNumber << " " << computer.brand << " " <<
    computer.processor << " " << computer.video << " " <<
    computer.hardDrive << " " << computer.weight << " " <<
    computer.batteryLife << " " << computer.price << " " <<
    computer.quantity;

    return out;
}