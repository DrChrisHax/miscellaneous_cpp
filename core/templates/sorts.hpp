#ifndef SORTS_H_
#define SORTS_H_

#include <concepts>
#include <iterator>

template <std::random_access_iterator T> requires std::totally_ordered<std::iter_value_t<T>>
void SelectionSort(T start, T end) {
    while (start != end) {
        T smallest {start};
        for (T curr{start + 1}; curr < end; ++curr) {
            if (*curr < *smallest) {
                smallest = curr;
            }
        }

        std::swap(*start, *smallest);
        ++start;
    }
}

template <std::random_access_iterator T> requires std::totally_ordered<std::iter_value_t<T>>
void BubbleSort(T start, T end) {
    while (start < end - 1) {
        for (T curr{ start }; curr < end - 1; ++curr) {
            if (*curr > *std::next(curr)) {
                std::swap(*curr, *std::next(curr));
            }
        }
        --end;
    }

}


#endif // SORTS_H_