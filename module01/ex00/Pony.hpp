//
// Created by jnannie on 12/13/20.
//

#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
public:
	Pony(void);
	~Pony(void);

	enum PonyColor {
		COLOR_WHITE,
		COLOR_BLUE,
		COLOR_RED,
		NUMBER_OF_COLORS
	};

	void sayName(void) const;
	void sayColor(void) const;
	void walk(void);
	void stop(void);
	void changeName(std::string &new_name);
	void changeColor(PonyColor new_color);

private:
	static const std::string _string_colors[];

	std::string _name;
	PonyColor _color;
	bool _is_walking;
};

#endif //PONY_HPP
