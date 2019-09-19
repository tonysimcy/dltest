#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include "libdltest.h"

#define MAXSIGNUM 16
#define MAXSIGNAMELEN 128  /*include seperator */
#define MAXLINELEN (MAXSIGNUM * MAXSIGNAMELEN)

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char signalName[MAXSIGNUM][MAXSIGNAMELEN];
    void *handle = dlopen(NULL, 0);
    int *symbol[MAXSIGNUM];  /* TODO: to support others data type. */

    int i = 0;
    char line[MAXLINELEN];

    fp = fopen("dummy-data.csv", "r");

    /* get signal name */
    if (fgets(line, MAXLINELEN, fp))
    {
        const char* tok;
        for (i = 0, tok = strtok(line, ","); tok && *tok; i++, tok = strtok(NULL, "\r\n"))
        {
            strcpy(signalName[i], tok);
            symbol[i] = dlsym(handle, signalName[i]);
            //printf("%s\t", signalName[i]);
        }
        //printf("\n");
    }

    /* print initial value */
    testSWC();
    
    /* inject test value */
    while (fgets(line, MAXLINELEN, fp))
    {
        const char* tok;
        for (i = 0, tok = strtok(line, ","); tok && *tok; i++, tok = strtok(NULL, "\r\n"))
        {
            *symbol[i] = atoi(tok);
        }
        /* print updated value */
        testSWC();
    }

    fclose(fp);

    return 0;
}
