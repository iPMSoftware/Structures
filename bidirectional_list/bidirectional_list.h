#ifndef IPM_BIDIRECTIONAL_LIST
#define IPM_BIDIRECTIONAL_LIST



#include <string>
namespace ipm {
    
    template<typename T>
    class bidirectional_list {
        public:
 
        void push(T value) {
            size_++;
            if(head_ == nullptr) {
                Node* node = new Node(value);
                node->next_ = head_;
                head_ = node;
                return;
            }
            Node* temp = head_;
            while(temp->next_ != nullptr) {
                temp = temp->next_;
            }
            temp->next_ = new Node(value);
            temp->next_->previous_ = temp;
        }
        bool erase(T value) {
            if(head_ == nullptr) {
                return false;
            }
            if(head_->value_ == value) {
                pop();
                return true;
            }
            Node* temp = head_;
            Node* previous;
            while(temp != nullptr) {
                if(temp->value_ == value) {
                    temp->previous_->next_ = temp->next_;
                    temp->next_->previous_ = temp->previous_;
                    delete temp;
                    return true;
                }
                previous = temp;
                temp = temp->next_;
            }
            return false;
        }
        bool has_value(T value) {
            if(head_ == nullptr) {
                return false;
            }
            if(head_->value_ == value) {
                return true;
            }
            Node* temp = head_;
            Node* previous;
            while(temp != nullptr) {
                if(temp->value_ == value) {
                    return true;
                }
                previous = temp;
                temp = temp->next_;
            }
            return false;
        }
        T front() {
            if(head_ == nullptr) 
                return T();
            return head_->value_;
        }
        void pop() {
            if(head_ == nullptr)
                return;
            Node* temp = head_;
            head_ = head_->next_;
            delete temp;
            size_--;
        }
        int size() const {
            return size_;
        }

        std::string to_string() {
            std::string ret;
            if(head_ == nullptr)
                return ret;
            Node* temp = head_;
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
        Node* head_{nullptr};
        int size_{0};
    };

}

#endif