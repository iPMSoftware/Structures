#ifndef IPM_MAP
#define IPM_MAP

#include "../vector/vector.h"
#include "hash.h"

namespace ipm {   
    template<typename Key, typename Value, int Size = 1000>
    class Map {
        public:
        Map() {
            buffer_ = new ipm::vector<bucket>[Size];
        }
        ~Map() {
            delete[] buffer_;
        }
        int size() const {
            return size_;
        }
        void put(const Key& key, const Value& value) {
            auto index = ipm::hash<Key,Size>::calculate(key);
            int bucket_index = -1;
            for(int i=0;i<buffer_[index].size();i++) {
                if (buffer_[index][i].key_ == key) {
                    bucket_index = i;
                    break;
                }
            }
            if(bucket_index != -1) {
                buffer_[index][bucket_index].value_ = value;
            }
            size_++;
            buffer_[index].push_back(bucket{key,value});
        }

        Value get(const Key& key) const {
            auto index = ipm::hash<Key,Size>::calculate(key);
            for(int i=0;i<buffer_[index].size();i++) {
                if (buffer_[index][i].key_ == key) {
                    return buffer_[index][i].value_;
                }
            }
            return Value{};
        }
        void clear() {
            size_ = 0;
            for(auto i = 0;i<Size;i++) {
                buffer_[i].clear();
            }
        }
        bool remove(const Key& key) {
            auto index = ipm::hash<Key,Size>::calculate(key);
            for(int i=0;i<buffer_[index].size();i++) {
                if (buffer_[index][i].key_ == key) {
                    buffer_[index].erase(buffer_[index].begin()+i);
                    size_--;
                    return true;
                }
            }
            return false;
        }
        
    private:
    struct bucket {
            Key key_;
            Value value_;
        };
        ipm::vector<bucket>* buffer_;

        int size_ {0};
    };

}

#endif