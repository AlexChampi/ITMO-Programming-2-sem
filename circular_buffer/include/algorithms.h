#ifndef RINGBUFFER_ALGHORITHMS_H
#define RINGBUFFER_ALGHORITHMS_H

namespace alexchamp {

    ///\brief Check that predicate is true for each element
    template<typename InputIterator, typename UnaryPredicate>
    bool all_of(InputIterator first, InputIterator last, UnaryPredicate predicate) {
        for (; first != last && predicate(*first); ++first);
        return (first == last);
    }

/// \brief Check that predicate is true at least for one element
    template<typename InputIterator, typename UnaryPredicate>
    bool any_of(InputIterator first, InputIterator last, UnaryPredicate predicate) {
        for (; first != last && !predicate(*first); ++first);
        return (first != last);
    }

    //!\brief Check that predicate is false for each element
    template<typename InputIterator, typename UnaryPredicate>
    bool none_of(InputIterator first, InputIterator last, UnaryPredicate predicate) {
        for (; first != last && !predicate(*first); ++first);
        return (first == last);
    }

    ///\brief Check that predicate true is for exactly one element
    template<typename InputIterator, typename UnaryPredicate>
    bool one_of(InputIterator first, InputIterator last, UnaryPredicate predicate) {
        int counter = 0;
        for (; first != last; ++first) {
            if (predicate(*first)) {
                counter++;
            }
        }
        return counter == 1;
    }

    ///Determines whether the elements of a sequence are sorted.
    template<typename ForwardIterator, typename Compare>
    bool is_sorted(ForwardIterator first, ForwardIterator last, Compare compare) {
        if (first != last) {
            ForwardIterator next = first;
            while (++next != last) {
                if (compare(*next, *first)) {
                    return next == last;
                }
                first = next;
            }
        }
        return true;
    }

    /// Check whether the sequences are partitioned
    template<typename InputIt, typename UnaryPredicate>
    bool is_partitioned(InputIt first, InputIt last, UnaryPredicate predicate) {
        for (; first != last; ++first)
            if (!predicate(*first))
                break;
        for (; first != last; ++first)
            if (predicate(*first))
                return false;
        return true;
    }

    ///Find the first element in sequences for which a predicate is false
    template<typename InputIt, typename T>
    InputIt find_not(InputIt first, InputIt last, T key) {
        for (; first != last && *first == key; ++first);
        return first;
    }

    ///Find the last element in sequences for which a predicate is true
    template<typename BidirectionalIterator, typename T>
    BidirectionalIterator find_backward(BidirectionalIterator first, BidirectionalIterator last, T key) {
        BidirectionalIterator end = last;
        --last;
        --first;
        for (; last != first && *first != key; --last);
        if (first == last)
            return end;
        return last;
    }

        ///Check whether the sequences are palindrome
    template<typename BidirectionalIterator, typename Compare>
    bool is_palindrome(BidirectionalIterator first, BidirectionalIterator last, Compare comp) {
        BidirectionalIterator end = last;
        --last;
        for (; first != end; ++first, --last) {
            if (!comp(*first, *last))
                return false;
        }
        return true;
    }
}
#endif //RINGBUFFER_ALGHORITHMS_H
