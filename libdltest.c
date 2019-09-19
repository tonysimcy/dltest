#include <stdio.h>
#include "libdltest.h"

int testdataA = 0;
int testdataB = 255;

void testSWC(void)
{
    printf("testSWC: testdataA = %d, testdataB = %d\r\n", testdataA, testdataB);
    return;
}
