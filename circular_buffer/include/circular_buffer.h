//
// Created by alekschamp on 25.04.22.
//

#ifndef CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_CIRCULAR_BUFFER_H

#include <cstddef>
#include "iterator.h"


namespace alexchamp {

    template<typename T, typename Alloc = std::allocator<T>>
    class circular_buffer {
    public:
        using this_type = circular_buffer<T, Alloc>;
        using value_type = T;
        using pointer = value_type *;
        using reference = value_type &;
        using differnce_type = std::ptrdiff_t;
        using size_type = std::size_t;
        using capacity_type = size_type;


        using iterator = details::iterator<circular_buffer<T, Alloc>, details::nonconst_traits<std::allocator_traits<Alloc>>>;

        using allocator_type = Alloc;
        using traits = std::allocator_traits<allocator_type>;


    private:
        pointer _buff;
        pointer _end;
        pointer _first;
        pointer _last;
        size_type _size;
        Alloc alloc;

        template<typename Buff, typename Traits> friend struct details::iterator;

    public:

        void increment(pointer &ptr) const {
            if (++ptr == _end) {
                ptr = _buff;
            }
        }

        void decrement(pointer &ptr) const {
            if (ptr == _buff) {
                ptr = _end;
            }
            --ptr;
        }

        pointer add(pointer &ptr, differnce_type size) const {
            return ptr + ((size < _end - ptr) ? size : size - (_end - _buff));
        }

        pointer sub(pointer &ptr, differnce_type size) const {
            return ptr - (size < (_end - ptr) ? size - (_end - _buff) : size);
        }

        void reserve(capacity_type size) {
            _buff = traits::allocate(alloc, size);
            _end = _buff + size;
        }

        explicit circular_buffer(const allocator_type &alloc = Alloc())
                : alloc(alloc), _buff(0), _size(0), _end(0), _first(0), _last(0) {}

        explicit circular_buffer(capacity_type capacity, const allocator_type &alloc = Alloc()) : alloc(alloc),
                                                                                                  _size(0) {
            reserve(capacity);
            _first = _last = _buff;
        }

        void change_capacity(size_type new_capacity) {
            if (new_capacity <= _size) return;

            pointer _new_buff = traits::allocate(alloc, new_capacity);

            size_type t = 0;
            try {
                for (; t < _size; ++t) {
                    traits::construct(alloc, _new_buff + t, _buff[t]);
                }
            } catch (...) {
                for (size_type j = 0; j < t; ++j) {
                    traits::destroy(alloc, _new_buff + j);
                }
                traits::deallocate(alloc, _new_buff, new_capacity);
                throw;
            }

            for (size_type i = 0; i < _size; ++i) {
                traits::destroy(alloc, _buff + i);
            }
            traits::deallocate(alloc, _buff, _size);
            _first = _buff = _new_buff;
            _last = _new_buff + t;
            _size = _last - _buff;
            _end = _buff + new_capacity;
        }

        iterator begin() {
            return iterator(this, _first);
        }

        iterator end() {
            return iterator(this, 0);
        }

        reference operator[](size_type size) {
            return *(_first + (size < (_end - _first) ? size : size - (_end - _buff)));
        }

        reference front() {
            return *_first;
        }

        reference back() {
            return *(((_last == _buff) ? _end : _last) - 1);
        }

        void pop_back() {
            decrement(_last);
            traits::destroy(alloc, _last);
            --_size;
        }

        void pop_front() {
            traits::destroy(alloc, _first);
            increment(_first);
            --_size;
        }

        void push_back(const value_type &value) {
            if (_size == capacity()) {
                *_last = value;
                increment(_last);
                _first = _last;
            } else {
                traits::construct(alloc, _last, value);
                increment(_last);
                ++_size;
            }
        }

        void push_front(const value_type &value) {
            decrement(_first);
            if (_size == capacity()) {
                *_first = value;
                _last = _first;
            } else {
                traits::construct(alloc, _first, value);
                ++_size;
            }
        }

        size_type size() const {
            return _size;
        }

        capacity_type capacity() const {
            return _end - _buff;
        }

        ~circular_buffer() {
            for (std::size_t sz; sz < _size; ++sz) {
                traits::destroy(alloc, _buff + sz);
            }
            traits::deallocate(alloc, _buff, capacity());
        }
    };


}
#endif //CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
