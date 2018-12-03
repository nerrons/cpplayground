#include <iostream>

int main() {
    double dval = 3.14;
    const int ic = 42;
    const int &ri = dval;
    const int *p;
    const int ic, &r = ic;
    int *p1, *const p2;
    p1 = &ic;
    p2 = p1;
    

    std::cout << dval << " " << ri << std::endl;
    return 0;
}
