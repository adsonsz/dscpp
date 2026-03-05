#include <doubly_linked_list.hpp>
#include <cassert>

int main() {
    ds::doubly_linked_list<int> list(5);
    assert(list.size() == 1);

    list.push_front(4);
    assert(list.size() == 2);

    list.push_back(6);
    assert(list.size() == 3);

    return 0;
}
