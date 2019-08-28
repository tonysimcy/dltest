#include <stdio.h>
#include "libdltest.h"
void *testVar;
int testIntVar = 18;
int testFunc(int x) { return x + 42; }
void testFunc2(void)
{
    printf("from testFunc2: testIntVar = %d\r\n", testIntVar);
    return;
}
