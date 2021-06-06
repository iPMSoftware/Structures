#include "graph_test.h"
#include "graph.h"


#include "../test/test_macros.h"

namespace ipm {
    void GraphTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsVertexPresentAfterInsertion())
        COLLECT_RESULTS(CheckEdgeIsPresentAfterVertexInsertion())
        COLLECT_RESULTS(CheckEdgeIsPresentWithoutVertexInsertion())
        COLLECT_RESULTS(CheckEdgeIsPresentAfterOneVertexInsertion())
        COLLECT_RESULTS(CheckDeleteOfExistingEdge())
        COLLECT_RESULTS(CheckDeleteOfNonExistingEdge())
        PRINT_RESULTS
    }
 
    bool GraphTest::IsEmptyAfterCreate() {
        ipm::graph<int> g;
        ASSERT_NO_PASS_RETURN(0,g.vertexes())
        ASSERT(0,g.edges())
    }

    bool GraphTest::IsVertexPresentAfterInsertion() {
        ipm::graph<int> g;
        bool add_vertex = g.add_vertex(1);
        ASSERT(add_vertex,true)
    }

    bool GraphTest::IsVertexNotPresentAfterDelete() {
        //@TODO fix map class
        // ipm::graph<int> g;
        // g.add_vertex(1);
        // bool delete_edge = g.delete_vertex(1);
        // ASSERT(delete_edge,true)
        return false;
    }

    bool GraphTest::CheckEdgeIsPresentAfterVertexInsertion() {
        ipm::graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        bool add_edge = g.add_edge(1,2);
        ASSERT(add_edge,true)
    }

    bool GraphTest::CheckEdgeIsPresentWithoutVertexInsertion() {
        ipm::graph<int> g;
        bool add_edge = g.add_edge(1,2);
        ASSERT(add_edge,false)
    }

    bool GraphTest::CheckEdgeIsPresentAfterOneVertexInsertion() {
        ipm::graph<int> g;
        g.add_vertex(1);
        bool add_edge = g.add_edge(1,2);
        ASSERT(add_edge,false)        
    }

    bool GraphTest::CheckDeleteOfExistingEdge() {
        ipm::graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        g.add_edge(1,2);
        bool delete_edge = g.delete_edge(1,2);
        ASSERT(delete_edge,true)
    }

    bool GraphTest::CheckDeleteOfNonExistingEdge() {
        ipm::graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        bool delete_edge = g.delete_edge(1,2);
        ASSERT(delete_edge,false)
    }
}