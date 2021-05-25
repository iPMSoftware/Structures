#ifndef IPM_PRIORITY_QUEUE_IPML
#define IPM_PRIORITY_QUEUE_IPML

#include "greater.h"

#include <string>
namespace ipm {
    
    template<typename T, typename COMP = ipm::greater<T>>
    class PriorityQueueImpl {
        public:
 
        void push(T elem) {
            size_++;
            Node* val = new Node(elem);
             if(front_ == nullptr) {
                 front_ = val;
                 return;
             }
             Node* temp = front_;
             Node* previous;
             while(temp != nullptr) {
                 if(comp_(val->value_,temp->value_)) {
                     if(temp->previous_ != nullptr)
                        temp->previous_->next_ = val;
                     val->previous_ = temp->previous_;

                     temp->previous_ = val;
                     val->next_ = temp;
                     if(temp == front_)
                        front_ = val;
                     return;
                 }
                 previous = temp;
                 temp = temp->next_;
             }
             previous->next_ = val;
             val->previous_ = previous;
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
            size_--;
        }
        int size() const {
            
            return size_;
        }

        std::string to_string() {
            std::string ret;
            if(front_ == nullptr)
                return ret;
            Node* temp = front_;
            while(temp != nullptr) {
                ret += std::to_string(temp->value_);
                ret += " ";
                temp = temp->next_;
            }
            return ret;
        }

        private:
        struct Node {
            Node(T value = T()) : value_(value), next_(nullptr), previous_(nullptr) {}
            T value_;
            Node* next_;
            Node* previous_;
        };
        COMP comp_;
        Node* front_{nullptr};
        int size_{0};
    };

}

#endif