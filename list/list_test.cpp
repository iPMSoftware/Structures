#include "list_test.h"
#include "list.h"


#include "../test/test_macros.h"

namespace ipm {
    void ListTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsSizeEqualToOneAfterPush())
        PRINT_RESULTS
    }

    bool ListTest::IsEmptyAfterCreate() {
        ipm::List<int> l;
        ASSERT(0,l.size());
    }

    bool ListTest::IsSizeEqualToOneAfterPush() {
        ipm::List<int> l;
        l.push_front(1);
        ASSERT(1,l.size());
    }

}