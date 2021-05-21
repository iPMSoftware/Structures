#ifndef IPM_TEST_MACROS
#define IPM_TEST_MACROS

#include <iostream>

#define ASSERT(x,y) if(x == y) { \
        std::cout << "PASS " << __func__ << " " << x << " = " << #y << std::endl; \
        return true; \
    } else { \
        std::cout << "FAIL " << __func__ << " " << x << " != " << #y << std::endl; \
        return false; \
    }

#define ASSERT_NO_PASS_RETURN(x,y) if(x == y) { \
        std::cout << "PASS STEP" << __func__ << " " << x << " = " << #y << std::endl; \
    } else { \
        std::cout << "FAIL " << __func__ << " " << x << " != " << #y << std::endl; \
        return false; \
    }    

#define PREPARE_COLLECT bool result = false;int counter_positive = 0;int counter_negative = 0;

#define COLLECT_RESULTS(x) { \
    x ? counter_positive++ : counter_negative++; \
}

#define PRINT_RESULTS  std::cout << "TEST PASSED: " << counter_positive << "\nTEST FAILED: " << counter_negative << std::endl;

#endif