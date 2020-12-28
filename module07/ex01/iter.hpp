//
// Created by jnannie on 12/27/20.
//

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>


template<typename T>
void iter(T *arr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		(*f)(arr[i]);
}

#endif //ITER_HPP
