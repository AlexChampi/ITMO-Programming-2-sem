//
// Created by alekschamp on 25.04.22.
//

#ifndef CIRCULAR_BUFFER_ITERATOR_H
#define CIRCULAR_BUFFER_ITERATOR_H

#include <iterator>


namespace alexchamp {
    namespace details {

        template<class Traits>
        struct nonconst_traits;

        template<class Traits>
        struct nonconst_traits {
            using value_type = typename Traits::value_type;
            using pointer = typename Traits::pointer;
            using reference = value_type&;
            using iterator_category = std::random_access_iterator_tag;
            using size_type = typename Traits::size_type;
            using difference_type = typename Traits::difference_type;

            using nonconst_self = nonconst_traits<Traits>;
        };


        template<class Buff, class Traits>
        struct iterator : public std::iterator<std::random_access_iterator_tag,
                typename Traits::value_type,
                typename Traits::difference_type,
                typename Traits::pointer,
                typename Traits::reference> {


            using nonconst_self = iterator<Buff, typename Traits::nonconst_self>;

            using iterator_category = std::random_access_iterator_tag;
            using value_type = typename Traits::value_type;
            using referecne = typename Traits::reference;
            using pointer = typename Traits::pointer;
            using size_type = typename Traits::size_type;
            using difference_type = typename Traits::difference_type;

            const Buff *_buff;
            pointer _it;

            iterator(const Buff *buf, const pointer p) : _buff(buf), _it(p) {}

            iterator(const nonconst_self &it) : _buff(it._buff), _it(it._it) {}


            pointer convert(const iterator<Buff, Traits> &iterator) const {
                return iterator._it == 0 ? _buff->_buff + _buff->size() :
                       (iterator._it < _buff->_first ? iterator._it + (_buff->_end - _buff->_first)
                                                     : _buff->_buff + (iterator._it - _buff->_first));
            }

            iterator &operator=(const iterator &iterator) {
                if (this == &iterator) {
                    return *this;
                }
                _buff = iterator._buff;
                _it = iterator._it;
                return *this;
            }

            referecne operator[](difference_type index) const {
                return *(*this + index);
            }

            referecne operator*() const {
                return *_it;
            }

            pointer operator->() const {
                return &(operator*());
            }

            difference_type operator-(const iterator <Buff, Traits> &iterator) const {
                return convert(*this) - convert(iterator);
            }

            iterator &operator++() {
                _buff->increment(_it);
                if (_it == _buff->_last) {
                    _it = 0;
                }
                return *this;
            }

            iterator operator++(int) {
                iterator<Buff, Traits> tmp = *this;
                ++*this;
                return tmp;
            }

            iterator &operator--() {
                if (_it == 0) {
                    _it = _buff->_last;
                }
                _buff->decrement(_it);
                return *this;
            }

            iterator operator--(int) {
                iterator<Buff, Traits> tmp = *this;
                --*this;
                return tmp;
            }

            iterator &operator+=(difference_type size) {
                if (size > 0) {
                    _it = _buff->add(_it, size);
                    if (_it == _buff->_last) {
                        _it = 0;
                    }
                } else {
                    *this -= -size;
                }
                return *this;
            }

            iterator operator+(difference_type size) const {
                iterator<Buff, Traits> tmp = *this;
                tmp += size;
                return tmp;
            }

            iterator &operator-=(difference_type size) {
                if (size > 0) {
                    if (_it == 0) {
                        _it = _buff->_last;
                    }
                    _it = _buff->sub(_it, size);
                } else {
                    *this += -size;
                }
                return *this;
            }

            iterator operator-(difference_type size) const {
                return iterator<Buff, Traits>(*this) -= size;


            }

            template<class T>
            bool operator==(const iterator <Buff, T> &iterator) const {
                return _it == iterator._it;
            }

            template<class T>
            bool operator!=(const iterator <Buff, T> &iterator) const {
                return _it != iterator._it;
            }

            template<class T>
            bool operator<(const iterator <Buff, T> &iterator) const {
                return convert(*this) < convert(iterator);
            }

            template<class T>
            bool operator>(const iterator <Buff, T> &iterator) const {
                return convert(*this) > convert(iterator);
            }

            template<class T>
            bool operator<=(const iterator <Buff, T> &iterator) const {
                return convert(*this) <= convert(iterator);
            }

            template<class T>
            bool operator>=(const iterator <Buff, T> &iterator) const {
                return convert(*this) >= convert(iterator);
            }
        };
    }
}
#endif //CIRCULAR_BUFFER_ITERATOR_H
