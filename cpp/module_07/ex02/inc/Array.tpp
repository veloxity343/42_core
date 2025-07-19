#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) {
	*this = other;
}

template<typename T>
Array<T>::~Array() {
	delete[] _data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (std::size_t i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](std::size_t index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template<typename T>
const T& Array<T>::operator[](std::size_t index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template<typename T>
std::size_t Array<T>::size() const {
	return _size;
}
