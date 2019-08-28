#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "libdltest.h"

int main(int argc, char *argv[]) {
    void *handle = dlopen(NULL, 0);
    void *symbol = dlsym(handle, "testVar");
    printf("testVar: %p\n", symbol);
    symbol = dlsym(handle, "testFunc");
    printf("testFunc: %p\n", symbol);

    int *symbol2 = dlsym(handle, "testIntVar");
    testFunc2();
    //printf("testIntVar: %d\n", *symbol2);
    *symbol2 = atoi(argv[1]);
    //printf("testIntVar: %d\n", *symbol2);
    testFunc2();

    return 0;
}
