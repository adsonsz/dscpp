#pragma once
#include <cstddef>

namespace ds {

template <typename T>
class doubly_linked_list {
protected:
    struct Node;
    struct Node {
        Node* previous;
        Node* next;
        T data;

        Node(Node* p, Node* n, const T& d) : previous(p), next(n), data(d) {}
    };

private:
    Node* _first;
    Node* _last;
    size_t _size;

protected:
    void push_first_data(const T& data);

public:
    doubly_linked_list() : _first(nullptr), _last(nullptr), _size(0) {}
    doubly_linked_list(const T& data) 
    : _first(new Node(nullptr, nullptr, data)), _last(_first), _size(1) {}
    ~doubly_linked_list();

    // Element access
    inline const T& front() const { return _first->data; }
    inline const T& back() const { return _last->data; }

    // Capacity
    inline bool empty() const { return _size == 0; }
    inline size_t size() const { return _size; }

    // Modifiers
    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();
    void clear();

    // Iterator class
    class iterator {
    public:
        Node* _pointer;

    public:
        explicit iterator(Node* pointer) : _pointer(pointer) {}
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
doubly_linked_list<T>::~doubly_linked_list() {
    this->clear();
}

template <typename T>
void doubly_linked_list<T>::push_first_data(const T& data) {
    Node* node = new Node(nullptr, nullptr, data);
    _first = node;
    _last = node;
}


template <typename T>
void doubly_linked_list<T>::push_front(const T& data) {
    if (_size) {
        Node* node = new Node(nullptr, _first, data);
        _first->previous = node;
        _first = node;
    }

    else {
        this->push_first_data(data);
    }

    _size++;
}

template <typename T>
void doubly_linked_list<T>::push_back(const T& data) {
    if (_size) {
        Node* node = new Node(_last, nullptr, data);
        _last->next = node;
        _last = node;
    }

    else {
        this->push_first_data(data);
    }

    _size++;
}

template <typename T>
void doubly_linked_list<T>::pop_front() {
    Node* new_first = _first->next;
    delete _first;
    _first = new_first;
    _size--;
}

template <typename T>
void doubly_linked_list<T>::pop_back() {
    Node* new_last = _last->previous;
    delete _last;
    _last = new_last;
    _size--;
}

template <typename T>
void doubly_linked_list<T>::clear() {
    // Delete
    Node* current = _first;
    while (current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
    }

    // Reinitialize
    _first = nullptr;
    _last = nullptr;
    _size = 0;
}

} // namespace ds

