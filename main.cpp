//#include "vector/vector.h"
#include "vector/vector_test.h"
#include "queue/queue_test.h"
#include "list/list_test.h"
#include "map/map_test.h"
#include "sort/merge_sort_test.h"
#include "priority_queue/priority_queue_impl_test.h"
#include "priority_queue/priority_queue_heap_test.h"
#include "graph/graph_test.h"

#include <string>
#include <iostream>



int main() {
    ipm::VectorTest::RunAll();
    ipm::QueueTest::RunAll();
    ipm::ListTest::RunAll();
    ipm::MapTest::RunAll();
    ipm::MergeSortTest::RunAll();
    ipm::PriorityQueueImplTest::RunAll();
    ipm::PriorityQueueHeapTest::RunAll();
    ipm::GraphTest::RunAll();
    return 0;
}