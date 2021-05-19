#ifndef IPM_QUEUE
#define IPM_QUEUE

namespace ipm {
    template<typename T>
    class Queue {
        public:
        Queue() {
            size_ = 4;
            data_ = new T[size_];
        }

        void push(T elem) {
            if(back_ == size_) {
                T* temp = new T[size_*2];
                for(int i=0;i<size_;i++) {
                    temp[i] = data_[i];
                }
                delete[] data_;
                data_ = temp;
                size_ *=2;
            }

            data_[back_++] = elem;
        }

        T pop_front() {
            if(back_ == front_)
                return T{};
            T val = data_[front_++];

            return val;
        }
        int size() const {
            return back_ - front_;
        }

        private:
        int front_ {0};
        int back_ {0};
        int size_ {0};
        T* data_;

    };

}

#endif