#ifndef IPM_HEAP
#define IPM_HEAP

#include "greater.h"
#include "../vector/vector.h"

#include <string>
#include <vector>

namespace ipm {
    
    template<typename T, typename COMP = ipm::greater<T>>
    class heap {
        public:
        heap() {
            data_.push_back(T{});
        }
        void push(T elem) {
            if((size()+1) == data_.size()) {
                data_.push_back(elem);
                size_++;
            }
            else 
                data_[++size_] = elem;
            heap_up(size_);
        }
        T front() {
            if(size() == 0)
                return T{};
            return data_[1];
        }
        void pop() {
            if(size() == 0)
                return;
            if(size() == 1)
                size_--;
            else {
                data_[1] = data_[size_--];
                heap_down(1);
            }
        }
        int size() const {
            return size_;
        }

        std::string to_string() {
            std::string ret;
            if(size() == 0)
                return ret;
            for(int i=1;i<=size_;i++) {
                ret += std::to_string(data_[i]);
                ret += " ";
            }
            return ret;
        }

        private:
        void heap_up(int index) {
            if(index == 1)
                return;
            int parent = index/2;
            if(comp_(data_[index],data_[parent])) {
                swap(index,parent);
                heap_up(parent);
            }
        }  
        void heap_down(int index) {
            int best = 2 * index;
            if(best > size_)
                return;
            int right_child_index = best + 1;
            if(right_child_index < size_ && comp_(data_[right_child_index],data_[best])) {
                best = right_child_index;
            }
            if(comp_(data_[best],data_[index])) {
                swap(best,index);
                heap_down(best);
            }

        }  
        void swap(int a,int b) {
            T temp = data_[a];
            data_[a] = data_[b];
            data_[b] = temp;
        } 
        ipm::vector<T> data_;
        COMP comp_;
        int size_{0};
    }; 

}


#endif