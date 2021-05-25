#ifndef IPM_PRIORITY_QUEUE_TEST
#define IPM_PRIORITY_QUEUE_TEST

namespace ipm {
    class PriorityQueueTest {
        public:
        static void RunAll();
        static bool IsEmptyAfterCreate();
        static bool IsGreaterComparisionGood123();
        static bool IsGreaterComparisionGood132();
        static bool IsGreaterComparisionGood213();
        static bool IsGreaterComparisionGood231();
        static bool IsGreaterComparisionGood312();
        static bool IsGreaterComparisionGood321();
        static bool IsLesserComparisionGood123();
        static bool IsLesserComparisionGood132();
        static bool IsLesserComparisionGood213();
        static bool IsLesserComparisionGood231();
        static bool IsLesserComparisionGood312();
        static bool IsLesserComparisionGood321();
    };
};

#endif