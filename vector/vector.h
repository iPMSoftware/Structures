#ifndef IPM_VECTOR
#define IPM_VECTOR

namespace ipm {

    template<typename T>
    class vector {
        public:
        vector() {
            size_ = 4;
            buff_ = new T[size_];
        }
        void  push_back(T item) {
            if (pos_ == size_) {
                T* temp = new T[2*size_];
                for(int i = 0;i<size_;i++)
                    temp[i] = buff_[i];
                delete[] buff_;
                buff_ = temp;
                }
            buff_[pos_++] = item;
        }
        int size() const {
            return pos_;
        }
        T& operator[](int pos) {
            return buff_[pos];
        }

        private:
        int size_;
        int pos_;
        T* buff_;

    };
}

#endif