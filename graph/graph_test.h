#ifndef IPM_GRAPH_TEST
#define IPM_GRAPH_TEST

namespace ipm {
    class GraphTest {
        public:
        static void RunAll();
        static bool IsEmptyAfterCreate();
        static bool IsVertexPresentAfterInsertion();
        static bool IsVertexNotPresentAfterDelete();
        static bool CheckEdgeIsPresentAfterVertexInsertion();
        static bool CheckEdgeIsPresentWithoutVertexInsertion();
        static bool CheckEdgeIsPresentAfterOneVertexInsertion();
        static bool CheckDeleteOfExistingEdge();
        static bool CheckDeleteOfNonExistingEdge();
    };
};

#endif