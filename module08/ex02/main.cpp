//
// Created by jnannie on 12/28/20.
//

#include "mutantstack.hpp"
#include <iostream>

struct Data {
	Data(std::string s) : _s(s) {}
	std::string _s;
};

int main()
{
	std::cout << "*********************************** subject" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0); //5 3 5 737 0
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "*********************************** not subject" << std::endl;
	{
		MutantStack<Data> mstack;

		mstack.push(Data("hello"));
		mstack.push(Data("!!!"));
		std::cout << "top: " << mstack.top()._s << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(Data("hi"));
		mstack.push(Data("privet"));
		mstack.push(Data("aloha"));
		mstack.push(Data("!!!")); //"hello" "hi" "privet" "aloha"
		MutantStack<Data>::iterator it = mstack.begin();
		MutantStack<Data>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << it->_s << std::endl;
			++it;
		}
		std::stack<Data> s(mstack);
	}

	return 0;
}
