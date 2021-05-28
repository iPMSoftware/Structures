#include "priority_queue_heap_test.h"
#include "priority_queue.h"
#include "heap.h"
#include "lesser.h"

#include "../test/test_macros.h"

namespace ipm {
    void PriorityQueueHeapTest::RunAll() {
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

    bool PriorityQueueHeapTest::IsEmptyAfterCreate() {
        ipm::PriorityQueueHeap<int> pqh;
        ASSERT(0,pqh.size());
    }

    bool PriorityQueueHeapTest::IsGreaterComparisionGood123() {
        ipm::PriorityQueueHeap<int> pqh;
        pqh.push(1);
        pqh.push(2);
        pqh.push(3);
        ASSERT(3,pqh.front());
    }

    bool PriorityQueueHeapTest::IsGreaterComparisionGood132() {
        ipm::PriorityQueueHeap<int> pqh;
        pqh.push(1);
        pqh.push(3);
        pqh.push(2);
        ASSERT(3,pqh.front());
    }

    bool PriorityQueueHeapTest::IsGreaterComparisionGood213() {
        ipm::PriorityQueueHeap<int> pqh;
        pqh.push(2);
        pqh.push(1);
        pqh.push(3);
        ASSERT(3,pqh.front());
    }

    bool PriorityQueueHeapTest::IsGreaterComparisionGood231() {
        ipm::PriorityQueueHeap<int> pqh;
        pqh.push(2);
        pqh.push(3);
        pqh.push(1);
        ASSERT(3,pqh.front());
    }

    bool PriorityQueueHeapTest::IsGreaterComparisionGood312() {
        ipm::PriorityQueueHeap<int> pqh;
        pqh.push(3);
        pqh.push(1);
        pqh.push(2);
        ASSERT(3,pqh.front());
    }

    bool PriorityQueueHeapTest::IsGreaterComparisionGood321() {
        ipm::PriorityQueueHeap<int> pqh;
        pqh.push(3);
        pqh.push(2);
        pqh.push(1);
        ASSERT(3,pqh.front());
    }

    bool PriorityQueueHeapTest::IsLesserComparisionGood123() {
        ipm::PriorityQueueHeap<int,ipm::lesser<int>> pqh;
        pqh.push(1);
        pqh.push(2);
        pqh.push(3);
        ASSERT(1,pqh.front());
    }

    bool PriorityQueueHeapTest::IsLesserComparisionGood132() {
        ipm::PriorityQueueHeap<int,ipm::lesser<int>> pqh;
        pqh.push(1);
        pqh.push(3);
        pqh.push(2);
        ASSERT(1,pqh.front());
    }

    bool PriorityQueueHeapTest::IsLesserComparisionGood213() {
        ipm::PriorityQueueHeap<int,ipm::lesser<int>> pqh;
        pqh.push(2);
        pqh.push(1);
        pqh.push(3);
        ASSERT(1,pqh.front());
    }

    bool PriorityQueueHeapTest::IsLesserComparisionGood231() {
        ipm::PriorityQueueHeap<int,ipm::lesser<int>> pqh;
        pqh.push(2);
        pqh.push(3);
        pqh.push(1);
        ASSERT(1,pqh.front());
    }

    bool PriorityQueueHeapTest::IsLesserComparisionGood312() {
        ipm::PriorityQueueHeap<int,ipm::lesser<int>> pqh;
        pqh.push(3);
        pqh.push(1);
        pqh.push(2);
        ASSERT(1,pqh.front());
    }

    bool PriorityQueueHeapTest::IsLesserComparisionGood321() {
        ipm::PriorityQueueHeap<int,ipm::lesser<int>> pqh;
        pqh.push(3);
        pqh.push(2);
        pqh.push(1);
        ASSERT(1,pqh.front());
    }

}