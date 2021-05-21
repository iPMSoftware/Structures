#include "map_test.h"
#include "map.h"


#include "../test/test_macros.h"

namespace ipm {
    void MapTest::RunAll() {
        PREPARE_COLLECT
        COLLECT_RESULTS(IsEmptyAfterCreate())
        COLLECT_RESULTS(IsSizeEqualToOneAfterPut())
        COLLECT_RESULTS(IsGetElementSamAsPut())
        COLLECT_RESULTS(IsEmptyAfterClear())
        COLLECT_RESULTS(IsReturningDefaultValue())
        COLLECT_RESULTS(IsOverwritingValuesForSameKey())
        PRINT_RESULTS
    }

    bool MapTest::IsEmptyAfterCreate() {
        using Key = std::string;
        using Value = std::string;
        constexpr auto Size = 100;
        ipm::Map<Key,Value,Size> m;
        ASSERT(0,m.size());
    }

    bool MapTest::IsSizeEqualToOneAfterPut() {
        using Key = std::string;
        using Value = std::string;
        constexpr auto Size = 100;
        ipm::Map<Key,Value,Size> m;
        m.put("John","Smith");
        ASSERT(1,m.size());
    }

    bool MapTest::IsGetElementSamAsPut() {
        using Key = std::string;
        using Value = std::string;
        constexpr auto Size = 100;
        ipm::Map<Key,Value,Size> m;
        m.put("John","Smith");
        Value res = m.get("John");
        ASSERT(res,"Smith");
    }

    bool MapTest::IsEmptyAfterClear() {
        using Key = std::string;
        using Value = std::string;
        constexpr auto Size = 100;
        ipm::Map<Key,Value,Size> m;
        m.put("John","Smith");
        m.clear();
        ASSERT(0,m.size());
    }

    bool MapTest::IsReturningDefaultValue() {
        using Key = std::string;
        using Value = std::string;
        constexpr auto Size = 100;
        ipm::Map<Key,Value,Size> m;
        Value res = m.get("John");
        ASSERT(res,"");
    }

    bool MapTest::IsOverwritingValuesForSameKey() {
        using Key = std::string;
        using Value = std::string;
        constexpr auto Size = 100;
        ipm::Map<Key,Value,Size> m;
        m.put("John","Smith");
        m.put("John","Max");
        Value res = m.get("John");
        ASSERT(res,"Max");
    }
}