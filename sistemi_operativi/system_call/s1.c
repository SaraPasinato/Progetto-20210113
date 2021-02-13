#include <stdio.h>
#include <stdlib.h>

int process_s1(int argc , char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s pathfile \n", argv[0]);
        return 1;
    }
   printf("ciao");

return 0;

}