#ifndef IPM_PRIORITY_QUEUE_IPML
#define IPM_PRIORITY_QUEUE_IPML

#include "greater.h"

namespace ipm {
    
    template<typename T, typename COMP = ipm::greater<T>>
    class PriorityQueueImpl {
        public:
 
        void push(T elem) {
            
        }
        T front() {
            if(front_ == nullptr) 
                return T();
            return front_->value_;
        }
        void pop() {
            if(front_ == nullptr)
                return;
            Node* temp = front_;
            front_ = front_->next_;
            delete temp;
        }
        int size() const {
            return 0;
        }

        private:
        struct Node {
            Node(T value = T()) : value_(value), next_(nullptr) {}
            T value_;
            Node* next_;
        };
        Node* front_{nullptr};
        int size_{0};
    };

}

#endif