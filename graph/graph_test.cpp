#include "graph_test.h"
#include "graph.h"


#include "../test/test_macros.h"

namespace ipm {
    void GraphTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        PRINT_RESULTS
    }
 
    bool GraphTest::IsEmptyAfterCreate() {
        ipm::graph<int> g;
        ASSERT(0,g.size());
    }  
}