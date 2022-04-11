#include "SumAvgCalculator.h"

SumAvgCalculator::SumAvgCalculator(int initialValue)
{
	totalSum = initialValue;
	size = 1;
}

int SumAvgCalculator::sum() const
{
	return totalSum;
}

void SumAvgCalculator::add(unsigned number)
{
	totalSum += number;
	size++;
}

void SumAvgCalculator::sub(int number)
{
	totalSum += (-1 *number);
	size++;
}

double SumAvgCalculator::avarage() const
{
	return ((double)totalSum/(double)size);
}

SumAvgCalculator SumAvgCalculator::operator+(const SumAvgCalculator& other)
{
	SumAvgCalculator result(this->totalSum + other.totalSum);
	result.size = this->size + other.size;
	return result;
}

SumAvgCalculator& SumAvgCalculator::operator+=(const SumAvgCalculator& other)
{
	*this = *this + other;
	return *this;
}
