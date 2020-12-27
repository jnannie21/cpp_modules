//
// Created by jnannie on 12/27/20.
//

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <stdexcept>
#include <string>

class Converter {
public:
	Converter(Converter const &other);
	Converter &operator=(Converter const &other);
	~Converter();

	Converter(std::string const &value);

	void printValues(void);

	class ConvertionNotPossibleException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class OutOfRangeException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class UnknownTypeException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	Converter();
	void _parse() throw(ConvertionNotPossibleException, OutOfRangeException);

	void _countDecimals();

	void _printChar();
	void _printInt();
	void _printFloat();
	void _printDouble();
	void _printPseudo();

	static std::string const _pseudo[6];

	enum Type {
		NOTYPE,
		TYPE_PSEUDO,
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE
	};

	Type _type;
	std::string _stringValue;
	int _intValue;
	float _floatValue;
	double _doubleValue;
	char _charValue;
	size_t _decimals;

};


#endif //CONVERTER_HPP
