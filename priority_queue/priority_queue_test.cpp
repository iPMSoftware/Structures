#include "priority_queue_test.h"
#include "priority_queue.h"
#include "lesser.h"

#include "../test/test_macros.h"

namespace ipm {
    void PriorityQueueTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsGreaterComparisionGood123())
        COLLECT_RESULTS(IsGreaterComparisionGood132())
        COLLECT_RESULTS(IsGreaterComparisionGood213())
        COLLECT_RESULTS(IsGreaterComparisionGood231())
        COLLECT_RESULTS(IsGreaterComparisionGood312())
        COLLECT_RESULTS(IsGreaterComparisionGood321())
        COLLECT_RESULTS(IsLesserComparisionGood123())
        COLLECT_RESULTS(IsLesserComparisionGood132())
        COLLECT_RESULTS(IsLesserComparisionGood213())
        COLLECT_RESULTS(IsLesserComparisionGood231())
        COLLECT_RESULTS(IsLesserComparisionGood312())
        COLLECT_RESULTS(IsLesserComparisionGood321())
        PRINT_RESULTS
    }

    bool PriorityQueueTest::IsEmptyAfterCreate() {
        ipm::PriorityQueue<int> pq;
        ASSERT(0,pq.size());
    }

    bool PriorityQueueTest::IsGreaterComparisionGood123() {
        ipm::PriorityQueue<int> pq;
        pq.push(1);
        pq.push(2);
        pq.push(3);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueTest::IsGreaterComparisionGood132() {
        ipm::PriorityQueue<int> pq;
        pq.push(1);
        pq.push(3);
        pq.push(2);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueTest::IsGreaterComparisionGood213() {
        ipm::PriorityQueue<int> pq;
        pq.push(2);
        pq.push(1);
        pq.push(3);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueTest::IsGreaterComparisionGood231() {
        ipm::PriorityQueue<int> pq;
        pq.push(2);
        pq.push(3);
        pq.push(1);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueTest::IsGreaterComparisionGood312() {
        ipm::PriorityQueue<int> pq;
        pq.push(3);
        pq.push(1);
        pq.push(2);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueTest::IsGreaterComparisionGood321() {
        ipm::PriorityQueue<int> pq;
        pq.push(3);
        pq.push(2);
        pq.push(1);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueTest::IsLesserComparisionGood123() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(1);
        pq.push(2);
        pq.push(3);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueTest::IsLesserComparisionGood132() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(1);
        pq.push(3);
        pq.push(2);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueTest::IsLesserComparisionGood213() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(2);
        pq.push(1);
        pq.push(3);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueTest::IsLesserComparisionGood231() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(2);
        pq.push(3);
        pq.push(1);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueTest::IsLesserComparisionGood312() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(3);
        pq.push(1);
        pq.push(2);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueTest::IsLesserComparisionGood321() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(3);
        pq.push(2);
        pq.push(1);
        ASSERT("1 2 3 ",pq.to_string());
    }

}