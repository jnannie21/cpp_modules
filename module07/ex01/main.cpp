//
// Created by jnannie on 12/27/20.
//

#include "iter.hpp"
#include <iostream>


struct Data {
	std::string s1;
};

void doubleInt(int &i) {
	i *= 2;
}

void changeData(Data &el) {
	el.s1 += "!!!";
}

int main(void) {
	int intArr[] = {1, 2, 3};
	Data dataArr[] = {{"hello"}, {"hi"}, {"privet"}};

	iter(intArr, 3, doubleInt);
	std::cout << intArr[0] << " " << intArr[1] << " " << intArr[2] << std::endl;

	iter(dataArr, 3, changeData);
	std::cout << dataArr[0].s1 << " " << dataArr[1].s1 << " " << dataArr[2].s1 << std::endl;

	return 0;
}
