#pragma once
#include <cstddef>
#include <cstring>

namespace ds {

template <typename T> 
class dynamic_array {
    T* _data;
    size_t _size;
    size_t _capacity;

public:
    // Constructor
    dynamic_array() : _data(nullptr), _size(), _capacity() {}
    dynamic_array(size_t size) : _data(new T[size]), _size(size), _capacity(size) {}

    // Destructor
    ~dynamic_array();

    // Element access
    inline const T& operator[](size_t index) const { return _data[index]; }
    inline T& operator[](size_t index) { return _data[index]; }
    inline const T& front() const { return _data[0]; }
    inline const T& back() const { return _data[_size-1]; }
    inline const T* data() const { return _data; }

    // Capacity
    inline bool empty() const {  return _size == 0; }
    inline size_t size() const { return _size; }
    size_t max_size() const { return _capacity; }
    void reserve(size_t capacity);
    void shrink_to_fit();

    // Modifiers
    void clear();
    void push_back(const T& item);
    void pop_back();

    // Iterator class
    class iterator {
        T* _pointer;

    public:
        explicit iterator(T* pointer) : _pointer(pointer) {}
        iterator& operator=(const iterator&) = default;
        inline T& operator*() const { return *_pointer; }

        inline iterator& operator++() { _pointer++; return *this; }
        inline iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
        inline bool operator==(const iterator& other) const { return _pointer == other._pointer; }
        inline bool operator!=(const iterator& other) const { return _pointer != other._pointer; }
    };

    // Iterators
    iterator begin() { return iterator(_data); }
    iterator end() { return iterator(_data + _size); }


protected:
    void change_capacity(size_t capacity);
    
};

template <typename T>
dynamic_array<T>::~dynamic_array() {
    delete[] _data;
}

template <typename T>
void dynamic_array<T>::reserve(size_t capacity) {
    if (capacity > _capacity) this->change_capacity(capacity);
}

template <typename T>
void dynamic_array<T>::shrink_to_fit() {
    this->change_capacity(_size);
}

template <typename T>
void dynamic_array<T>::clear() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
void dynamic_array<T>::push_back(const T& item) {
    if (_size < _capacity) {
        _data[_size++] = item;
    }

    else if (_capacity == 0) {
        this->change_capacity(2);
        _data[_size++] = item;
    }

    else {
        this->change_capacity(_capacity * 2);
        _data[_size++] = item;
    }
}

template <typename T>
void dynamic_array<T>::pop_back() {
    _size--;

    if (_size < _capacity / 4) {
        size_t new_capacity = _capacity / 2;
        if (new_capacity % 2) new_capacity++;
        this->change_capacity(new_capacity);
    }
}

template <typename T>
void dynamic_array<T>::change_capacity(size_t capacity) {
    // Allocate new space in memory
    T* new_data = new T[capacity];

    // Copy data.
    size_t min  = _size < _capacity ? _size : _capacity;
    if (min > 0) std::memcpy(new_data, _data, min * sizeof(T));

    // Delete old pointer, and point to new pointer
    delete[] _data;
    _data = new_data;

    // Change capacity
    _capacity = capacity;
}

}   // namespace ds
