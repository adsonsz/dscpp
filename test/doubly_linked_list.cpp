#include <doubly_linked_list.hpp>
#include <cassert>
#include <iostream>

void iterator_test() {
    // Create and populate array. 
    ds::doubly_linked_list<int> arr;
    for (int i = 0; i < 10; ++i) arr.push_back(i);

    // Test population with iterator
    {
        ds::doubly_linked_list<int>::iterator it = arr.begin();
        for (int i = 0; i < 10; ++i) {
            std::cout << "array[" << i << "] == " << *it << std::endl;
            assert(i == *it);
            ++it;
        }
    }

    // Test population with iterator
    {
        ds::doubly_linked_list<int>::iterator it = arr.begin();
        int counter = 0;
        for (; it != arr.end(); ++it) {
            assert(counter == *it);
            ++counter;
        }
    }

    // Increment all items of the array by 10 using iterator
    for (auto it = arr.begin(); it != arr.end(); ++it) *it += 10;

    // Check if the items have been incremented using iterators
    int counter = 10;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        assert(counter == *it);
        ++counter;
    }
}

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
    iterator_test();
    push_from_one();
    push_from_nothing();
    return 0;
}
