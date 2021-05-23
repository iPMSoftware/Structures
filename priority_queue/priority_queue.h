#ifndef IPM_PRIORITY_QUEUE
#define IPM_PRIORITU_QUEUE

#include "../queue/queue.h"

#include "greater.h"
#include "priority_queue_impl.h"

namespace ipm {
    
    template<typename T, typename IMPL = ipm::PriorityQueueImpl<T,ipm::greater<T>>>
    class PriorityQueue {
        public:
        PriorityQueue() {}

        void push(T elem) {
            impl_.push(elem);
        }
        T front() {
            impl_.front();
        }
        void pop() {
            impl_.pop();
        }
        int size() const {
            return impl_.size();
        }

        private:
        IMPL impl_; 

    };

}

#endif