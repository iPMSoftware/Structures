#ifndef IPM_MAP_HASH
#define IPM_MASP_HASH

#include <string>

namespace ipm {
    template<typename T, int SIZE>
    struct hash {
        static unsigned long calculate(const T item) {
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
        static unsigned long calculate(const std::string item)  {
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
}

#endif