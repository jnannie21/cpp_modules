//
// Created by jnannie on 12/28/20.
//

#include "Span.hpp"

Span::Span() {

}

Span::Span(Span const &other) {
	*this = other;
}

Span &Span::operator=(Span const &other) {
	if (this == &other)
		return *this;

	_set = other._set;
	_limit = other._limit;

	return *this;
}

Span::~Span() {

}

Span::Span(unsigned int limit) throw(TooFewElementsException) {
	if (limit < 2)
		throw TooFewElementsException();
	_limit = limit;
}

void Span::addNumber(int number) throw(SetIsFullException) {
	if (_set.size() == _limit)
		throw SetIsFullException();

	_set.insert(number);
}

unsigned int Span::shortestSpan() const throw(TooFewElementsException) {
	if (_set.size() < 2)
		throw TooFewElementsException();

	std::multiset<int>::iterator prev = _set.begin();
	std::multiset<int>::iterator next = ++_set.begin();
	unsigned int shortest = *prev - *next;
	for (unsigned int diff = 0; next != _set.end() && shortest; ++prev, ++next)
	{
		diff = std::abs(*prev - *next);
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

unsigned int Span::longestSpan() const throw(TooFewElementsException) {
	if (_set.size() < 2)
		throw TooFewElementsException();

	std::multiset<int>::iterator last = --_set.end();
	return (std::abs(*last - *_set.begin()));
}

const char *Span::SetIsFullException::what() const throw() {
	return ("set is full");
}

const char *Span::TooFewElementsException::what() const throw() {
	return ("too few elements in set");
}
