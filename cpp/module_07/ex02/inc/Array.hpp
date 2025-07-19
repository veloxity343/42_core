#pragma once

#include <string>
#include <stdexcept>

template<typename T>
class Array {
private:
	T* _data;
	std::size_t _size;

public:
	Array() : _data(NULL), _size(0) {}
	Array(unsigned int n) : _data(new T[n]), _size(n) {}
	Array(const Array& other) : _data(NULL), _size(0) {
		*this = other;
	}
	~Array() {
		delete[] _data;
	}
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _data;
			_size = other._size;
			_data = new T[_size];
			for (std::size_t i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
		return *this;
	}

	T& operator[](std::size_t index) {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	const T& operator[](std::size_t index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	std::size_t size() const {
		return _size;
	}
};
