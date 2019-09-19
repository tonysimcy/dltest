# dltest

Build
```
$ make
cc    -c -o dltest.o dltest.c
gcc -rdynamic -L. -o dltest dltest.o -Wl,--whole-archive -ldltest -Wl,--no-whole-archive -ldl
```

Usage
```
$ ./dltest.exe
testSWC: testdataA = 0, testdataB = 255
testSWC: testdataA = 1, testdataB = 2
testSWC: testdataA = 2, testdataB = 4
testSWC: testdataA = 3, testdataB = 6
testSWC: testdataA = 4, testdataB = 8
testSWC: testdataA = 5, testdataB = 10
testSWC: testdataA = 6, testdataB = 12
testSWC: testdataA = 7, testdataB = 14
testSWC: testdataA = 8, testdataB = 16
testSWC: testdataA = 9, testdataB = 18
testSWC: testdataA = 10, testdataB = 20
```
