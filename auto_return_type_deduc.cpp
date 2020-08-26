#include <iostream>
#include <type_traits>
#include "utils.h"

template<typename T1, typename T2>
auto myMax(T1 a, T2 b) {
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto myMax2(T1 a, T2 b) -> decltype(true ? a : b) {
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto myMax3(T1 a, T2 b) -> std::decay_t<decltype(true ? a : b)> {
    return b < a ? a : b;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    int& ra = a;
    int b = 3;
    int& rb = b;

    auto&& maxVal = myMax(a, b);
    // TD<decltype(maxVal)> x; // maxVal is an int&&. The auto return type takes care of passing in lvalue refs

    // auto&& maxVal2 = myMax2(a, b);
    // TD<decltype(maxVal2)> x; // maxVal2 is an int&. We're returning dangling references from functions

    auto&& maxVal3 = myMax3(a, b);
    // TD<decltype(maxVal3)> x; // maxVal3 is an int&&. Now we're talking

    std::cout << maxVal << '\n';
    return 0;
}
