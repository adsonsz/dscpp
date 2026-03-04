#include <singly_linked_list.hpp>
#include <cassert>

int main() {
    ds::singly_linked_list<int> list(5);
    assert(list.size() == 1);

    list.push_front(4);
    assert(list.size() == 2);

    return 0;
}
