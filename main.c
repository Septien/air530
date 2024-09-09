#include <stdio.h>
#include <string.h>

#include "air350.h"

#ifdef TESTS
#include "tests.h"
#endif

int main(void)
{

#ifdef TESTS
    tests();
#endif
    return 0;
}
