#include <iostream>
#include <cmath>

struct ComplexNumber {
	double real, img;
};

void print(const ComplexNumber& w) {
	std::cout << w.real << " + " << w.img << "i" << std::endl;
}

ComplexNumber read() {
	ComplexNumber w;
	std::cin >> w.real >> w.img;

	return w;
}

void readInto(ComplexNumber& w) {
	std::cin >> w.real >> w.img;
}

ComplexNumber add(const ComplexNumber &w1, const ComplexNumber &w2) {
	ComplexNumber sum;
	sum.real = w1.real + w2.real;
	sum.img = w1.img + w2.img;

	return sum;
}

ComplexNumber diff(const ComplexNumber& w1, const ComplexNumber& w2) {
	ComplexNumber res;
	res.real = w1.real - w2.real;
	res.img = w1.img - w2.img;

	return res;
}

ComplexNumber prod(const ComplexNumber& w1, const ComplexNumber& w2) {
	ComplexNumber res;
	res.real = w1.real * w2.real - w1.img * w2.img;
	res.img = w1.real * w2.img + w1.img * w2.real;

	return res;
}

ComplexNumber avg(ComplexNumber *arr, size_t n) {
	ComplexNumber res = { 0, 0 };
	for (size_t i = 0; i < n; i++) {
		// res.real += arr[i].real;
		// res.real += arr[i].img;
		res = add(res, arr[i]);
	}

	res.real /= n;
	res.img /= n;

	return res;
}

double mod(ComplexNumber w) {
	return sqrt(w.real * w.real + w.img * w.img);
	//return sqrt(pow(w.real, 2) + pow(w.img, 2));
}

void sort(ComplexNumber* arr, size_t n) {
	double *mods = new double[n];
	
	for (size_t i = 0; i < n; i++) {
		mods[i] = mod(arr[i]);
	}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			/*if (mod(arr[i]) > mod(arr[j])) {
				ComplexNumber tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}*/
			if (mods[i] > mods[j]) {
				ComplexNumber tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				double tmp1 = mods[i];
				mods[i] = mods[j];
				mods[j] = tmp1;
			}
		}
	}

	delete[] mods;
}

int main() {
	ComplexNumber arr[100];
	for (size_t i = 0; i < 5; i++) {
		readInto(arr[i]);
	}

	sort(arr, 5);

	for (size_t i = 0; i < 5; i++) {
		print(arr[i]);
	}
	return 0;
}