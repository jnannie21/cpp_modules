//
// Created by jnannie on 12/16/20.
//

#include "StreamEditor.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

StreamEditor::StreamEditor(const char *filename, const char *s1, const char *s2) :
						   _input_filename(filename), _s1(s1), _s2(s2), _error(false) {
	this->_file.open(this->_input_filename);
	if (!this->_file)
	{
		std::cout << "error opening file" << std::endl;
		this->_error = true;
		return ;
	}

	if (this->_s1.empty() || this->_s2.empty())
	{
		std::cout << "strings must not be empty" << std::endl;
		this->_error = true;
		return ;
	}

	this->_output_filename = this->_input_filename;
	this->_uppercaseFilename(this->_output_filename);
	this->_output_filename += ".replace";
}

bool StreamEditor::getError(void) const {
	return (this->_error);
}

void StreamEditor::replace(void) {
	if (this->_error)
		return ;
	std::ofstream output_file(this->_output_filename);
	if (!output_file)
	{
		std::cout << "error opening output file" << std::endl;
		this->_error = true;
		return ;
	}

	std::string line;
	while (std::getline(this->_file, line))
	{
		if (line == this->_s1)
			line = this->_s2;
		if (!(output_file << line))
		{
			perror(("error while writing to file " + this->_output_filename).c_str());
			this->_error = true;
			return ;
		}
		output_file << std::endl;
	}
	if (this->_file.bad())
	{
		perror(("error while reading file " + this->_input_filename).c_str());
		this->_error = true;
	}
}

void StreamEditor::_uppercaseFilename(std::string &upper_name) const {
	for (int i = 0; upper_name[i]; i++)
		upper_name[i] = toupper(upper_name[i]);
}
