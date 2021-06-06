#include "bidirectional_list_test.h"
#include "bidirectional_list.h"


#include "../test/test_macros.h"

namespace ipm {
    void BidirectionalListTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        PRINT_RESULTS
    }
 
    bool BidirectionalListTest::IsEmptyAfterCreate() {
        ipm::bidirectional_list<int> l;
        ASSERT(0,l.size());
    }



}