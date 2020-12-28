//
// Created by jnannie on 12/28/20.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int const toFind) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), toFind);
	return (it);
}


#endif //EASYFIND_HPP
