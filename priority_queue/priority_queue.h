#ifndef IPM_PRIORITY_QUEUE
#define IPM_PRIORITU_QUEUE

#include "../queue/queue.h"

#include <string>

#include "lesser.h"
#include "greater.h"
#include "priority_queue_impl.h"

namespace ipm {
    
    template<typename T, typename COMP = ipm::greater<T>, typename IMPL = ipm::PriorityQueueImpl<T,COMP>>
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
        std::string to_string()  {
            return impl_.to_string();
        }

        private:
        IMPL impl_; 

    };

}

#endif