#ifndef IPM_PRIORITY_QUEUE_GREATER
#define IPM_PRIORITY_QUEUE_GREATER

#include <string>

namespace ipm {

    template<typename T>
    struct greater {
        constexpr bool operator()(T&& lhs, T&& rhs) {
            return lhs > rhs;
        }
    };

    template<>
    struct greater<std::string> {
        bool operator()(std::string&& lhs, std::string&& rhs) {
            auto min_len = (lhs.length() < rhs.length() ? lhs.length() : rhs.length());
            for(auto i =0;i<min_len;i++) {
                if(rhs[i] < lhs[i])
                    return true;
                else return false;
            }
            return false;
        }
    };

}

#endif    