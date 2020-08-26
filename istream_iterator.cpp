#include <iostream>
#include <iterator>
#include <string>

int main(int argc, char const *argv[])
{
    std::ostream_iterator<int> oit(std::cout, "\n");
    std::ostream_iterator<const char *> stroit(std::cout, "\n");

    stroit = "before creation\n";
    std::istream_iterator<int> intIt(std::cin);
    stroit = "after creation\n";
    std::istream_iterator<int> intEOF;

    while (intIt != intEOF) {
        std::advance(intIt, 2);
        if (intIt != intEOF) {
            stroit = "--- ";
            oit++ = *intIt++;
            // ++intIt;
            // std::cout << "progressed!\n";
        }
    }

    return 0;
}
