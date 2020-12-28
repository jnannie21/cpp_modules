//
// Created by jnannie on 12/28/20.
//

#include "Array.hpp"
#include <string>
#include <iostream>

struct Data {
	std::string s;
};

int main(void) {
	Array<int> intArray1;
	Array<int> intArray2(5);

	Array<double> doubleArray(5);

	Array<Data> dataArray(5);

	try {
			std::cout << "array size: " << intArray1.size() << std::endl << intArray1[-1] << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "int test" << std::endl;
	std::cout << "array size: " << intArray2.size() << " int array value: " << intArray2[1] << std::endl;
	intArray2[1] = 6;
	std::cout << "array size: " << intArray2.size() << " int array value: " << intArray2[1] << std::endl;


	std::cout << "double test" << std::endl;
	std::cout << "array size: " << doubleArray.size() << " double array value: " << doubleArray[2] << std::endl;
	doubleArray[2] = 3.14;
	std::cout << "array size: " << doubleArray.size() << " double array value: " << doubleArray[2] << std::endl;


	std::cout << "string test" << std::endl;
	std::cout << "array size: " << dataArray.size() << " string array value: " << dataArray[4].s << std::endl;
	dataArray[4].s = "hello";
	std::cout << "array size: " << dataArray.size() << " string array value: " << dataArray[4].s << std::endl;


	Array<Data> *dataArray2;
	dataArray2 = new Array<Data>;
	*dataArray2 = dataArray;
	std::cout << "copy assignment operator test" << std::endl;
	std::cout << "array size: " << dataArray2->size() << " string array value: " << (*dataArray2)[4].s << std::endl;


	Array<Data> *dataArray3;
	dataArray3 = new Array<Data>;
	*dataArray3 = *dataArray2;
	std::cout << "copy constructor test" << std::endl;
	std::cout << "array size: " << dataArray3->size() << " string array value: " << (*dataArray3)[4].s << std::endl;


	delete dataArray2;
	delete dataArray3;

	return 0;
}
