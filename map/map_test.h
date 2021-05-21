#ifndef IPM_MAP_TEST
#define IPM_MAP_TEST

namespace ipm {
    class MapTest {
        public:
        static void RunAll();
        static bool IsEmptyAfterCreate();
        static bool IsSizeEqualToOneAfterPut();
        static bool IsGetElementSamAsPut();
        static bool IsEmptyAfterClear();
        static bool IsReturningDefaultValue();
        static bool IsOverwritingValuesForSameKey();
    };
}

#endif