#include <doubly_linked_list.hpp>
#include <cassert>
#include <iostream>

void push_from_one() {
    ds::doubly_linked_list<int> list(5);
    assert(list.size() == 1);
    assert(list.front() == 5);
    assert(list.back() == 5);

    list.push_front(4);
    assert(list.size() == 2);
    assert(list.front() == 4);
    assert(list.back() == 5);

    list.push_back(6);
    assert(list.size() == 3);
    assert(list.front() == 4);
    assert(list.back() == 6);
}

void push_from_nothing() {
    ds::doubly_linked_list<int> list;
    assert(list.size() == 0);

    list.push_back(5);
    assert(list.size() == 1);
    assert(list.front() == 5);
    assert(list.back() == 5);

    list.push_front(4);
    assert(list.size() == 2);
    assert(list.front() == 4);
    assert(list.back() == 5);

    list.push_back(6);
    assert(list.size() == 3);
    assert(list.front() == 4);
    assert(list.back() == 6);
}

int main() {
    push_from_one();
    push_from_nothing();
    return 0;
}
