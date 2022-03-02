#pragma once

class Rational {
private:
	int num;
	int dem;
public:
	void print() const;
	void setNum(int _num);
	void setDem(int dem);
	int getNum() const;
	int getDem() const;
	void read();

};