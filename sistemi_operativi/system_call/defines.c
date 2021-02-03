#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <unistd.h>
#include "defines.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int i=1;
/// @file defines.c
/// @brief Contiene l'implementazione delle funzioni
///         specifiche del progetto.



// controlla se il file è una directory 
int isDirectory(char *path){
    struct stat statbuf;
    if(stat(path, &statbuf) == -1)
        return 0;
    else
        return S_ISDIR(statbuf.st_mode);
}
// funzionalità dell processo S1
void s1_process(char *file){
  pid_t pid = getpid();
  printf("io sono s1: %d  %s\n", pid, file);
}
//funzioni del processo S2 e S3
void s2s3_process(){
  i++;
  pid_t child=getpid();
  printf(": %d  \n",child);
}