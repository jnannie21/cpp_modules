//
// Created by jnannie on 12/16/20.
//

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>
#include <fstream>

class Replacer {
public:
	Replacer(const char *filename, const char *s1, const char *s2);
	void replace(void);
	bool getError(void) const;

private:
	void _uppercaseFilename(std::string &upper_name) const;

	std::ifstream _file;
	std::string _input_filename;
	std::string _output_filename;
	std::string _s1;
	std::string _s2;
	bool _error;
};


#endif //REPLACER_HPP
