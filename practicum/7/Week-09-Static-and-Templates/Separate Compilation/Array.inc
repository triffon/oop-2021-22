const size_t MAX_SIZE = 10;

template <typename T>
inline Array<T>::Array() {
	arr = new T[MAX_SIZE];
	size = 0;
}

template <typename T>
inline Array<T>::~Array() {
	delete[] arr;
}

template <typename T>
inline void Array<T>::add(const T& element) {
	if (size >= MAX_SIZE)
		return;

	arr[size] = element;
	size++;
}

template <typename T>
inline void Array<T>::print() {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';

	std::cout << std::endl;
}