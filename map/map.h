#ifndef IPM_MAP
#define IPM_MAP

#include "../vector/vector.h"

#include <string>

namespace ipm {
    template<typename T, int SIZE>
    struct hash {
        static unsigned long cal(const T item) {
            const int MOD = 1000000007;
            unsigned long h = 0;
            const int size = sizeof(T);
            const unsigned char* ptr = reinterpret_cast<const unsigned char*>(&item);
            for(int i = 0;i<size;i++) {
                h *= 127;
                h += ptr[i];
            }
            return (MOD + h % MOD)%SIZE;
        }
    };

    template<int SIZE>
    struct hash<std::string,SIZE> {
        static unsigned long cal(const std::string item)  {
            const int MOD = 1000000007;
            unsigned long h = 0;
            const int size = item.length();
            const unsigned char* ptr = reinterpret_cast<const unsigned char*>(item.data());
            for(int i = 0;i<size;i++) {
                h *= 127;
                h += ptr[i];
            }
            return (MOD + h % MOD)%SIZE;
        }
    };

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
            auto index = ipm::hash<Key,Size>::cal(key);
            int bucket_index = -1;
            for(int i=0;i<buffer_[index].size();i++) {
                if (buffer_[index][i].key_ == key) {
                    bucket_index = i;
                    break;
                }
            }
            if(bucket_index != -1) {
                buffer_[index][bucket_index] = bucket{key, value};
                return true;
            }
            size_++;
            buffer_[index].push_back(bucket{key,value});
            return true;
        }

        Value get(const Key& key) const {
            auto index = ipm::hash<Key,Size>::cal(key);
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
            auto index = ipm::hash<Key,Size>::cal(key);
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