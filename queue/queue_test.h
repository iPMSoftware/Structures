#ifndef IPM_QUEUE_TEST
#define IPM_QUEUE_TEST

namespace ipm {
    class QueueTest {
        public:
        static void RunAll();
        static bool IsEmptyAfterCreate();
        static bool IsSizeEqualToOneAfterPush();
        static bool IsEmptyAfterPushAndPopFront();
        static bool IsValuePopFrontEqualToOnePushed();
        static bool IsMoreElementsAddedCorrectly();
    };
};

#endif