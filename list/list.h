#ifndef IPM_LIST
#define IPM_LIST

namespace ipm {
    template<typename T>
    class List {

        struct Node {
            Node(T value) : value_(value) {};
            T value_;
            Node* next_{nullptr};
        };
        public:
        List() {}

        void push_front(T value) {
            Node* node = new Node(value);
            node->next_ = head_;
            head_ = node;
            size_++;
        }

        T pop_front() {
            if(head_ == nullptr)
                return T{};
            T value = head_->value_;
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
            size_--;
            return value;
        }

        int size() const {
            return size_;
        }

        

        private:
        Node* head_{nullptr};
        int size_{0};

    };  

}

#endif