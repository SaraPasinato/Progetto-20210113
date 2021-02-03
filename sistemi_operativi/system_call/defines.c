#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <unistd.h>
#include "defines.h"
#include <sys/stat.h>
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

