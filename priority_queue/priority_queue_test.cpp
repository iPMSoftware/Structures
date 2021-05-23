#include "priority_queue_test.h"
#include "priority_queue.h"


#include "../test/test_macros.h"

namespace ipm {
    void PriorityQueueTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        PRINT_RESULTS
    }

    bool PriorityQueueTest::IsEmptyAfterCreate() {
        ipm::PriorityQueue<int> pq;
        ASSERT(0,pq.size());
    }

}