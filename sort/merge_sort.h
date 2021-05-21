#ifndef IPM_MERGE_SORT
#define IPM_MERGE_SORT

#include "sort.h"

namespace ipm {

    struct MergeSort : public Sort {
        void Do(int* array, int size) override {
            temp = new int[size];
            merge_sort(array,array+size);
        }
        ~MergeSort() {
            delete[] temp;
        }
        private:
        int* temp;
        void merge_sort(int* begin, int* end) {
            int size = end - begin;
            if(size < 2)
                return;
            int* half = begin+size/2;
            merge_sort(begin,half);
            merge_sort(half,end);

            int* a = begin;
            int* b = half;
            int* c = temp;
            while (a < half && b < end) {
                if (*b < *a) { // *a < *b would be unstable
                    *c++ = *b++;
                } else {
                    *c++ = *a++;
                }
            }
            while (a < half) {
                *c++ = *a++;
            }
            while (b < end) {
                *c++ = *b++;
            }

            c = temp;
            while (begin < end) {
                *begin++ = *c++;
            }
        }
    };
}

#endif