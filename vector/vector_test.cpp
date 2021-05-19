#include "vector_test.h"
#include "vector.h"

#include "../test/test_macros.h"

namespace ipm {
    void VectorTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsSizeEqualToOne())
        COLLECT_RESULTS(GetElementAtFirstPosition())
        PRINT_RESULTS
    }

    bool VectorTest::IsEmptyAfterCreate() {
        ipm::vector<int> V;
        ASSERT(0,V.size());
    }

    bool VectorTest::IsSizeEqualToOne() {
        ipm::vector<int> V;
        V.push_back(1);
        ASSERT(1,V.size());
    }

    bool VectorTest::GetElementAtFirstPosition() {
        ipm::vector<int> V;
        int elem = 2;
        V.push_back(elem);
        ASSERT(elem,V[0]);
    }
}