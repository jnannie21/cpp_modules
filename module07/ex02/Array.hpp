//
// Created by jnannie on 12/28/20.
//

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
public:
	Array();
	Array(Array const &other);
	Array &operator=(Array const &other);
	virtual ~Array();

	Array(unsigned int n);

	T &operator[](unsigned int i);

	unsigned int size() const;

	class OutOfTheLimitsException : public std::exception {
		virtual const char *what() const throw();
	};

private:
	unsigned int _size;
	T *_arr;

};


template<typename T>
Array<T>::Array() : _size(0) {
	_arr = new T[0];
}

template<typename T>
Array<T>::Array(Array<T> const &other) : _size(0) {
	_arr = NULL;

	*this = other;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &other) {
	if (this == &other)
		return *this;

	delete[] _arr;
	_arr = NULL;
	_size = other._size;
	if (_size > 0)
	{
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {
	delete [] _arr;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	_arr = new T[n];
}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw OutOfTheLimitsException();

	return (_arr[i]);
}

template<typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template<typename T>
const char *Array<T>::OutOfTheLimitsException::what() const throw() {
	return ("out of the limits");
}


#endif //ARRAY_HPP
