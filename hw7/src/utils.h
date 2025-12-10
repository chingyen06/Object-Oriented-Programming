#ifndef UTILS_H
#define UTILS_H

#include <vector>

template <typename RandomIt>
void bubble_sort(RandomIt first, RandomIt last) {
    // Implementation
    auto n = std::distance(first, last);
    for (auto i=0;i<n-1;i++) {
        for (auto j=0;j<n-i-1;j++) {
            if (*(first+j+1) < *(first+j)) {
                auto tmp = *(first+j);
                *(first+j) = *(first+j+1);
                *(first+j+1) = tmp;
            }
        }
    }
}

template <typename RandomIt, typename Compare>
void bubble_sort(RandomIt first, RandomIt last, Compare comp) {
    // Implementation
    auto n = std::distance(first, last);
    for (auto i=0;i<n-1;i++) {
        for (auto j=0;j<n-i-1;j++) {
            if (comp(*(first+j+1), *(first+j))) {
                auto tmp = *(first+j);
                *(first+j) = *(first+j+1);
                *(first+j+1) = tmp;
            }
        }
    }
}

#endif // UTILS_H