#pragma once

class Wallet {
private:
	double money;
	char username[32];
	char password[16];
public:
	void witdraw(double amount);
	void initMoney() {
		money = 500;
	}
};