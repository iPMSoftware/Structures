#include "list_test.h"
#include "list.h"


#include "../test/test_macros.h"

namespace ipm {
    void ListTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsSizeEqualToOneAfterPushFront())
        COLLECT_RESULTS(IsValueCorrectAfterPushFront())
        COLLECT_RESULTS(IsSizeEqualToOneAfterPushBack())
        COLLECT_RESULTS(IsValueCorrectAfterPushBack())
        COLLECT_RESULTS(IsSizeEqualToTwoAfterPushBackAndPushFront())
        COLLECT_RESULTS(AreValuesCorrectAfterPushBackAndPushFront())
        COLLECT_RESULTS(AreValuesCorrectAfterPushFrontAndPushBack())
        PRINT_RESULTS
    }
 
    bool ListTest::IsEmptyAfterCreate() {
        ipm::List<int> l;
        ASSERT(0,l.size());
    }

    bool ListTest::IsSizeEqualToOneAfterPushFront() {
        ipm::List<int> l;
        l.push_front(1);
        ASSERT(1,l.size());
    }

    bool ListTest::IsValueCorrectAfterPushFront() {
        ipm::List<int> l;
        l.push_front(1);
        int x = l.pop_front();
        ASSERT(x,1);
    }

    bool ListTest::IsSizeEqualToOneAfterPushBack() {
        ipm::List<int> l;
        l.push_back(1);
        ASSERT(1,l.size());
    }

    bool ListTest::IsValueCorrectAfterPushBack() {
        ipm::List<int> l;
        l.push_back(1);
        int x = l.pop_back();
        ASSERT(x,1);
    }

    bool ListTest::IsSizeEqualToTwoAfterPushBackAndPushFront() {
        ipm::List<int> l;
        l.push_back(1);
        l.push_front(1);
        ASSERT(2,l.size());
    }

    bool ListTest::AreValuesCorrectAfterPushBackAndPushFront() {
        ipm::List<int> l;
        l.push_back(1);
        l.push_front(2);
        int one = l.pop_back();
        int two = l.pop_front();
        ASSERT_NO_PASS_RETURN(1,one)
        ASSERT(2,two)
    }

    bool ListTest::AreValuesCorrectAfterPushFrontAndPushBack() {
        ipm::List<int> l;
        l.push_front(1);
        l.push_back(2);
        int one = l.pop_front();
        int two = l.pop_back();
        ASSERT_NO_PASS_RETURN(1,one)
        ASSERT(2,two)
    }

}