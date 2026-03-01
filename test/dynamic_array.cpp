#include <dynamic_array.hpp>
#include <cassert>

int main() {
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
