//
// Created by jnannie on 12/16/20.
//

#ifndef STREAMEDITOR_HPP
#define STREAMEDITOR_HPP

#include <string>
#include <fstream>

class StreamEditor {
public:
	StreamEditor(const char *filename, const char *s1, const char *s2);
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


#endif //STREAMEDITOR_HPP
