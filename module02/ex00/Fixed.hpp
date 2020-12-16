//
// Created by jnannie on 12/16/20.
//

#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed {
public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();
	Fixed &operator= (const Fixed &f);

	int getRawBits(void) const;
	void setRawBits(const int raw);

private:
	int _raw;
	static const int _number_of_fractional_bits = 8;
};


#endif //FIXED_HPP
