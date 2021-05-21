#ifndef IPM_SORT
#define IPM_SORT


namespace ipm {

    struct Sort {
        virtual void Do(int*, int) = 0;
    };
}

#endif