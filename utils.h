#pragma once
#include <vector>
#include <iostream>

template<typename T>
void print_vector(const std::vector<T>& v) {
    std::cout << "{ ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, ", ")); // .c_str() needed for the second param
    std::cout << '}' << std::endl;
}
