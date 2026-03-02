#include <dynamic_array.hpp>
#include <cassert>
#include <iostream>

void iterator_test() {
    // Create and populate array. 
    ds::dynamic_array<int> arr;
    for (int i = 0; i < 10; ++i) arr.push_back(i);

    // Test if has populated correctly.
    for (int i = 0; i < 10; ++i) assert(arr[i] == i);
    
    // Test population with iterator
    {
        ds::dynamic_array<int>::iterator it = arr.begin();
        for (int i = 0; i < 10; ++i) {
            assert(i == *it);
            ++it;
        }
    }

    // Test population with iterator
    {
        ds::dynamic_array<int>::iterator it = arr.begin();
        int counter = 0;
        for (; it != arr.end(); ++it) {
            assert(counter == *it);
            ++counter;
        }
    }

    // Increment all items of the array by 10 using iterator
    for (auto it = arr.begin(); it != arr.end(); ++it) *it += 10;

    // Checking if the items have been incremented correctly
    for (int i = 0; i < 10; ++i) assert(arr[i] == i+10);

    // Check if the items have been incremented using iterators
    int counter = 10;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        assert(counter == *it);
        ++counter;
    }
}

void push_back_test() {
    ds::dynamic_array<int> arr;
    assert(arr.size() == 0);

    arr.push_back(1);
    assert(arr.size() == 1);
    assert(arr[0] == 1);
    assert(arr.front() == 1);
    assert(arr.back() == 1);

    arr.push_back(2);
    assert(arr.size() == 2);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr.front() == 1);
    assert(arr.back() == 2);

    arr.push_back(3);
    assert(arr.size() == 3);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr.front() == 1);
    assert(arr.back() == 3);
}

int main() {
    iterator_test();
    push_back_test();
    return 0;
}
