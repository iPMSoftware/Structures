#ifndef IPM_LIST_TEST
#define IPM_LIST_TEST

namespace ipm {
    class ListTest {
        public:
        static void RunAll();
        static bool IsEmptyAfterCreate();
        static bool IsSizeEqualToOneAfterPushFront();
        static bool IsValueCorrectAfterPushFront();
        static bool IsSizeEqualToOneAfterPushBack();
        static bool IsValueCorrectAfterPushBack();
        static bool IsSizeEqualToTwoAfterPushBackAndPushFront();
        static bool AreValuesCorrectAfterPushBackAndPushFront();
        static bool AreValuesCorrectAfterPushFrontAndPushBack();
    };
};

#endif