//
// Created by jnannie on 12/28/20.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <exception>

class Span {
public:
	Span(Span const &other);
	Span &operator=(Span const &other);
	virtual ~Span();

	Span(unsigned int limit) throw(TooFewElementsException, LimitIsTooHighException);

	void addNumber(int number) throw(SetIsFullException);
	unsigned int shortestSpan() const throw(TooFewElementsException);
	unsigned int longestSpan() const throw(TooFewElementsException);

	void generate(void);

	class SetIsFullException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class TooFewElementsException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class LimitIsTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	Span();

	unsigned int _limit;
	std::multiset<int> _set;
};


#endif //SPAN_HPP
