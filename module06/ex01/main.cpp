//
// Created by jnannie on 12/27/20.
//

#include <cctype>
#include <string>
#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void fillString(std::string &s) {
	unsigned char ch;

	for (int i = 0; i < 8; i++)
	{
		while (1)
		{
			ch = rand() % 128;
			if (isalnum(ch))
			{
				s += ch;
				break ;
			}
		}
	}
}

void printData(Data *data) {
	std::cout << data->s1 << " " << data->n << " " << data->s2 << std::endl;
}

void *serialize(void) {
	Data *data = new Data();

	fillString(data->s1);
	data->n = rand();
	fillString(data->s2);

	return (reinterpret_cast<void *>(data));
}

Data *deserialize(void *raw) {
	return (reinterpret_cast<Data *>(raw));
}

int main(void) {
	void *raw = 0;
	Data *data = 0;

	srand(time(NULL));

	raw = serialize();
	printData(reinterpret_cast<Data *>(raw));
	data = deserialize(raw);
	printData(data);

	delete reinterpret_cast<Data *>(raw);
	return 0;
}