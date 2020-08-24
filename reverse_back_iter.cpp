#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "utils.h"

int main(int argc, char const *argv[])
{
    using Iter = std::vector<int>::iterator::value_type;
    using Trait = std::iterator_traits<std::vector<int>::iterator>::iterator_category;

    std::vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7 };

    auto it1 = std::next(v.begin(), 3);
    std::cout << "normal iter pointing at: " << *it1 << '\n';

    std::vector<int>::reverse_iterator it2(it1);
    std::cout << "reverse iter pointing at: " << *it2 << '\n';

    print_vector(v);

    std::back_insert_iterator<std::vector<int>> biit(v);
    *biit = 8;
    *biit = 9;

    print_vector(v);

    std::copy(v.begin(), v.end(), biit);

    print_vector(v);

    auto pos = v.insert(std::next(v.begin(), 2), 99);
    v.insert(pos, 888);

    std::inserter(v, std::next(v.begin())) = 6666;

    print_vector(v);
    return 0;
}
