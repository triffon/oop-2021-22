#pragma once


class SumAvgCalculator {
private:
	int totalSum;
	int size;
public:
	SumAvgCalculator(int initialValue);
	int sum() const;
	void add(unsigned number);
	void sub(int number);
	int num() const {
		return size;
	}
	double avarage() const;
	SumAvgCalculator operator +(const SumAvgCalculator& other);
	SumAvgCalculator& operator +=(const SumAvgCalculator& other);
};