//
// Created by jnannie on 12/16/20.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &f);

	Fixed(int i);
	Fixed(float f);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int _raw;
	static const int _number_of_fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &s, const Fixed &f);

#endif //FIXED_HPP
