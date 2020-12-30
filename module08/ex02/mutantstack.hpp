//
// Created by jnannie on 12/29/20.
//

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin();
	iterator end();

};

template<typename T>
MutantStack<T>::MutantStack() {

}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &other) {
	 *this = other;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other) {
	std::stack<T>::operator=(other);
}

template<typename T>
MutantStack<T>::~MutantStack() {

}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}


#endif //MUTANTSTACK_HPP
