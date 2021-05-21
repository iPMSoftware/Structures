#include "merge_sort_test.h"
#include "merge_sort.h"


#include "../test/test_macros.h"

namespace ipm {
    void MergeSortTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsOddArraySorted())
        COLLECT_RESULTS(IsEvenArraySorted())
        PRINT_RESULTS
    }

    bool MergeSortTest::IsOddArraySorted() {
        ipm::MergeSort ms;
        int array[] = {9,1,8,2,7,3,6,4,5};
        ms.Do(array,9);
        ASSERT_NO_PASS_RETURN(array[0],1);
        ASSERT_NO_PASS_RETURN(array[1],2);
        ASSERT_NO_PASS_RETURN(array[2],3);
        ASSERT_NO_PASS_RETURN(array[3],4);
        ASSERT_NO_PASS_RETURN(array[4],5);
        ASSERT_NO_PASS_RETURN(array[5],6);
        ASSERT_NO_PASS_RETURN(array[6],7);
        ASSERT_NO_PASS_RETURN(array[7],8);
        ASSERT(array[8],9);
    }

    bool MergeSortTest::IsEvenArraySorted() {
        ipm::MergeSort ms;
        int array[] = {10,1,9,2,8,3,7,4,6,5};
        ms.Do(array,10);
        ASSERT_NO_PASS_RETURN(array[0],1);
        ASSERT_NO_PASS_RETURN(array[1],2);
        ASSERT_NO_PASS_RETURN(array[2],3);
        ASSERT_NO_PASS_RETURN(array[3],4);
        ASSERT_NO_PASS_RETURN(array[4],5);
        ASSERT_NO_PASS_RETURN(array[5],6);
        ASSERT_NO_PASS_RETURN(array[6],7);
        ASSERT_NO_PASS_RETURN(array[7],8);
        ASSERT_NO_PASS_RETURN(array[8],9);
        ASSERT(array[9],10);
    }
}