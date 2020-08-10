#include <iostream>
#include <memory>
#include <unordered_map>

using ID = unsigned;
std::unordered_map<ID, std::weak_ptr<int>> um;

std::shared_ptr<int> cachedFactory(ID id) {
    auto ptr = um[id].lock();
    if (ptr) {
        std::cout << "in cached, value: " << *ptr << std::endl;
    } else {
        ptr = std::make_shared<int>(42);
        um[id] = ptr;
        std::cout << "made it" << std::endl;
    }
    return ptr;
}

int main() {
    auto int1 = cachedFactory(7);
    auto int2 = cachedFactory(7);
    return 0;
}

