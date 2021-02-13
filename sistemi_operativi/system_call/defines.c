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

//funzioni del processo S2
void process_s2(void){
  
  pid_t child=getpid();
  printf(": %d  \n",child);
}

//funzioni del processo  S3
void process_s3(void){
  
  pid_t child=getpid();
  printf(": %d  \n",child);
}