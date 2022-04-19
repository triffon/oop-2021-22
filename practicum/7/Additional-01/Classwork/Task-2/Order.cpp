#include"Order.h"

const size_t MAX_LEN = 60;

Order::Order() {
	copy("\0", "\0", nullptr);
}

Order::Order(const char* srcAddr, const char* destAddr, TaxiDriver* driver) {
	if (strlen(srcAddr) >= 60 || strlen(destAddr) >= 60)
		throw std::invalid_argument("ADDRESS IS TOO LONG\n");
	
	copy(srcAddr, destAddr, driver);
}

Order::Order(const Order& other) {
	copy(other.srcAddr, other.destAddr, other.driver);
}

Order& Order::operator=(const Order& other) {
	if (this != &other) {
		clear();
		copy(other.srcAddr, other.destAddr, other.driver);
	}

	return *this;
}

Order::~Order(){
	clear();
}

void Order::copy(const char* srcAddr, const char* destAddr, TaxiDriver* driver) {
	this->srcAddr = new char[strlen(srcAddr) + 1];
	this->destAddr = new char[strlen(destAddr) + 1];

	strcpy_s(this->srcAddr, strlen(srcAddr) + 1, srcAddr);
	strcpy_s(this->destAddr, strlen(destAddr) + 1, destAddr);

	this->driver = driver;
}

void Order::clear() {
	delete[] srcAddr;
	delete[] destAddr;
}

std::istream& operator>>(std::istream& in, Order& order) {

	if (order.srcAddr || order.destAddr) {
		delete[] order.srcAddr;
		delete[] order.destAddr;
	}

	char buff[MAX_LEN];
	in.getline(buff, MAX_LEN);

	order.srcAddr = new char[strlen(buff) + 1];
	strcpy_s(order.srcAddr, strlen(buff) + 1, buff);

	in.getline(buff, MAX_LEN);
	order.destAddr = new char[strlen(buff) + 1];
	strcpy_s(order.destAddr, strlen(buff) + 1, buff);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Order& order) {
	out << order.srcAddr << "\n";
	out << order.destAddr << "\n";

	return out;
}