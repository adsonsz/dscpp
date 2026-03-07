#pragma once
#include <cstddef>

namespace ds {

template <typename T>
class singly_linked_list {
protected:
    struct Node;
    struct Node {
        Node* next;
        T data;

        Node(Node* n, const T& d) : next(n), data(d) {}
        explicit Node(const T& d) : next(nullptr), data(d) {}
    };

private:
    Node* _first;
    size_t _size;

public:
    singly_linked_list() : _first(nullptr), _size(0) {}
    singly_linked_list(const T& data) : _first(new Node(data)), _size(1) {}
    ~singly_linked_list();

    // Element access
    inline const T& first() const { return _first->data; }

    // Capacity
    inline bool empty() const { return _first == nullptr; }
    inline size_t size() const { return _size; }

    // Modifiers
    void push_front(const T& data);
    void pop_front();
    void clear();

    // Iterator class
    class iterator {
        Node* _pointer;

    public:
        explicit iterator(T* pointer) : _pointer(pointer) {}
        iterator& operator=(const iterator&) = default;
        inline T& operator*() const { return _pointer->data; }

        inline iterator& operator++() { _pointer = _pointer->next; return *this; }
        inline iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
        inline bool operator==(const iterator& other) const { return _pointer == other._pointer; }
        inline bool operator!=(const iterator& other) const { return _pointer != other._pointer; }
    };

    // Iterators
    iterator begin() { return iterator(_first); }
    iterator end() { return iterator(nullptr); }
};

template <typename T>
singly_linked_list<T>::~singly_linked_list() {
    this->clear();
}

template <typename T>
void singly_linked_list<T>::push_front(const T& data) {
    Node* new_first = new Node(_first, data);
    _first = new_first;
    _size++;
}

template <typename T>
void singly_linked_list<T>::pop_front() {
    Node* new_first = _first->next;
    delete _first;
    _first = new_first;
    _size--;
}

template <typename T>
void singly_linked_list<T>::clear() {
    // Delete
    Node* current = _first;
    while (current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
    }

    // Reinitialize
    _size = 0;
    _first = nullptr;
}


} // namespace ds

