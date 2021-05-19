//#include "vector/vector.h"
#include "vector/vector_test.h"
#include "queue/queue_test.h"
#include "list/list_test.h"

#include <string>
#include <iostream>



int main() {
    ipm::VectorTest::RunAll();
    ipm::QueueTest::RunAll();
    ipm::ListTest::RunAll();
    return 0;
}