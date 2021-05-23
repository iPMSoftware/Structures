#include "queue_test.h"
#include "queue.h"


#include "../test/test_macros.h"

namespace ipm {
    void QueueTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsSizeEqualToOneAfterPush())
        COLLECT_RESULTS(IsEmptyAfterPushAndPop())
        COLLECT_RESULTS(IsValuePopFrontEqualToOnePushed())
        COLLECT_RESULTS(IsMoreElementsAddedCorrectly())
        PRINT_RESULTS
    }

    bool QueueTest::IsEmptyAfterCreate() {
        ipm::Queue<int> q;
        ASSERT(0,q.size());
    }

    bool QueueTest::IsSizeEqualToOneAfterPush() {
        ipm::Queue<int> q;
        q.push(1);
        ASSERT(1,q.size());
    }

    bool QueueTest::IsEmptyAfterPushAndPop() {
        ipm::Queue<int> q;
        q.push(1);
        q.pop();
        ASSERT(0,q.size());
    }

    bool QueueTest::IsValuePopFrontEqualToOnePushed() {
        ipm::Queue<int> q;
        q.push(1);
        int x = q.front();
        ASSERT(x,1);
    }

    bool QueueTest::IsMoreElementsAddedCorrectly() {
        ipm::Queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        ASSERT(5,q.size());
    }
}