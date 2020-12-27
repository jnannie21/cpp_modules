//
// Created by jnannie on 12/27/20.
//

#include "Converter.hpp"
#include <cerrno>
#include <iostream>

static std::string const pseudo[6] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
};

Converter::Converter() {

}

Converter::Converter(Converter const &other) {
	*this = other;
}

Converter &Converter::operator=(Converter const &other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	_stringValue = other._stringValue;
	_intValue = other._intValue;
	_floatValue = other._floatValue;
	_doubleValue = other._doubleValue;
	_charValue = other._charValue;
	_decimals = other._decimals;
	return (*this);
}

Converter::~Converter() {

}

Converter::Converter(std::string const &stringValue) :
_type(NOTYPE), _stringValue(stringValue), _intValue(0), _floatValue(0.0), _doubleValue(0.0), _charValue('\0'), _decimals(1) {
	_parse();
	_countDecimals();
}

void Converter::printValues(void) {
	if (_type == TYPE_CHAR)
		_printChar();
	else if (_type == TYPE_INT)
		_printInt();
	else if (_type == TYPE_FLOAT)
		_printFloat();
	else if (_type == TYPE_DOUBLE)
		_printDouble();
	else if (_type == TYPE_PSEUDO)
		_printPseudo();
	else
		throw UnknownTypeException();
}

void Converter::_parse() throw(ConvertionNotPossibleException, OutOfRangeException) {

	size_t length = _stringValue.length();

	if (!std::isprint(_stringValue[0]) || std::isspace(_stringValue[0]))
		throw ConvertionNotPossibleException();

	// ******************************************* char
	if (length == 1 && !std::isdigit(_stringValue[0]))
	{
		_charValue = _stringValue[0];
		_type = TYPE_CHAR;
		return ;
	}

	// ******************************************* pseudo
	for (int i = 0; i < 6; i++)
	{
		if (_stringValue == pseudo[i])
		{
			_type = TYPE_PSEUDO;
			return ;
		}
	}
	if (_stringValue == "inf")
		throw ConvertionNotPossibleException();

	char *endptr;
	double tempDouble = (strtod(_stringValue.c_str(), &endptr));

	errno = 0;
	if (errno == ERANGE)
		throw OutOfRangeException();

	// ******************************************* float
	if (_stringValue.find('f') != std::string::npos)
	{
		size_t pos = _stringValue.find('.');
		if (!isdigit(_stringValue[pos + 1]))
			throw ConvertionNotPossibleException();
		if (*(endptr + 1) != '\0')
			throw ConvertionNotPossibleException();
		if (tempDouble > std::numeric_limits<float>::max() || tempDouble < std::numeric_limits<float>::lowest())
			throw OutOfRangeException();
		_floatValue = static_cast<float>(tempDouble);
		_type = TYPE_FLOAT;
		return ;
	}

	// ******************************************* double
	size_t pos = 0;
	if ((pos = _stringValue.find('.')) != std::string::npos)
	{
		if (!isdigit(_stringValue[pos + 1]))
			throw ConvertionNotPossibleException();
		if (*endptr != '\0')
			throw ConvertionNotPossibleException();
		_doubleValue = tempDouble;
		_type = TYPE_DOUBLE;
		return ;
	}

	// ******************************************* int
	size_t i = 0;
	if (_stringValue[i] == '-' || _stringValue[i] == '+')
		i++;
	while (i < _stringValue.length())
	{
		if (!std::isdigit(_stringValue[i]))
			throw ConvertionNotPossibleException();
		i++;
	}
	if (tempDouble > std::numeric_limits<int>::max() || tempDouble < std::numeric_limits<int>::lowest())
		throw OutOfRangeException();
	_intValue = static_cast<int>(tempDouble);
	_type = TYPE_INT;
}

void Converter::_countDecimals() {
	if (_type <= TYPE_INT)
		return ;

	size_t i = 0;
	size_t dot = _stringValue.find('.');
	if (dot == std::string::npos)
		return ;
	dot++;
	while (_stringValue[dot])
	{
		i++;
		dot++;
	}
	if (i == 0)
		return ;
	_decimals = i;
	if (_type == TYPE_FLOAT)
		_decimals = i - 1;
}

void Converter::_printChar() {
	if (std::isprint(_charValue) && !std::isspace(_charValue))
		std::cout << "char: " << _charValue << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(_charValue) << std::endl;

	std::cout.precision(_decimals);
	std::cout << std::fixed;

	std::cout << "float: " << static_cast<float>(_charValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_charValue) << std::endl;
}

void Converter::_printInt() {
	if (std::isprint(static_cast<char>(_intValue)))
		std::cout << "char: " << static_cast<char>(_intValue) << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(_intValue) << std::endl;

	std::cout.precision(_decimals);
	std::cout << std::fixed;

	std::cout << "float: " << static_cast<float>(_intValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_intValue) << std::endl;
}

void Converter::_printFloat() {
	if (std::isprint(static_cast<char>(_floatValue)))
		std::cout << "char: " << static_cast<char>(_floatValue) << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(_floatValue) << std::endl;

	std::cout.precision(_decimals);
	std::cout << std::fixed;

	std::cout << "float: " << static_cast<float>(_floatValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_floatValue) << std::endl;
}

void Converter::_printDouble() {
	if (std::isprint(static_cast<char>(_doubleValue)))
		std::cout << "char: " << static_cast<char>(_doubleValue) << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(_doubleValue) << std::endl;

	std::cout.precision(_decimals);
	std::cout << std::fixed;

	std::cout << "float: " << static_cast<float>(_doubleValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_doubleValue) << std::endl;
}

void Converter::_printPseudo() {
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (_stringValue[0] == '-')
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (_stringValue[0] == '+')
	{
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}


const char *Converter::ConvertionNotPossibleException::what() const throw() {
	return ("convertion is not possible");
}

const char *Converter::OutOfRangeException::what() const throw() {
	return ("out of range");
}

const char *Converter::UnknownTypeException::what() const throw() {
	return ("unknown type");
}
