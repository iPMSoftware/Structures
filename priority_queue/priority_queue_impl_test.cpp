#include "priority_queue_impl_test.h"
#include "priority_queue.h"
#include "heap.h"
#include "lesser.h"

#include "../test/test_macros.h"

namespace ipm {
    void PriorityQueueImplTest::RunAll() {
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

    bool PriorityQueueImplTest::IsEmptyAfterCreate() {
        ipm::PriorityQueue<int> pq;
        ASSERT(0,pq.size());
    }

    bool PriorityQueueImplTest::IsGreaterComparisionGood123() {
        ipm::PriorityQueue<int> pq;
        pq.push(1);
        pq.push(2);
        pq.push(3);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsGreaterComparisionGood132() {
        ipm::PriorityQueue<int> pq;
        pq.push(1);
        pq.push(3);
        pq.push(2);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsGreaterComparisionGood213() {
        ipm::PriorityQueue<int> pq;
        pq.push(2);
        pq.push(1);
        pq.push(3);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsGreaterComparisionGood231() {
        ipm::PriorityQueue<int> pq;
        pq.push(2);
        pq.push(3);
        pq.push(1);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsGreaterComparisionGood312() {
        ipm::PriorityQueue<int> pq;
        pq.push(3);
        pq.push(1);
        pq.push(2);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsGreaterComparisionGood321() {
        ipm::PriorityQueue<int> pq;
        pq.push(3);
        pq.push(2);
        pq.push(1);
        ASSERT("3 2 1 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsLesserComparisionGood123() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(1);
        pq.push(2);
        pq.push(3);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsLesserComparisionGood132() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(1);
        pq.push(3);
        pq.push(2);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsLesserComparisionGood213() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(2);
        pq.push(1);
        pq.push(3);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsLesserComparisionGood231() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(2);
        pq.push(3);
        pq.push(1);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsLesserComparisionGood312() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(3);
        pq.push(1);
        pq.push(2);
        ASSERT("1 2 3 ",pq.to_string());
    }

    bool PriorityQueueImplTest::IsLesserComparisionGood321() {
        ipm::PriorityQueue<int,ipm::lesser<int>> pq;
        pq.push(3);
        pq.push(2);
        pq.push(1);
        ASSERT("1 2 3 ",pq.to_string());
    }

}