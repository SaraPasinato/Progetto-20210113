#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "inc/defines.h"
#include "inc/err_exit.h"

//intestazione file F8 e F9
char * strHead="Id;PID";
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

//creat file 

int creatFile(char *pathname){
  //TODO Controllo spazi
 /* char *dir ="../OutputFiles/";
  dir=strcat(dir,pathname);
  dir=strcat(dir,".csv");
  */
  printf("\n Creating file....  \n");
  int fd; //file descriptor
  if( access( pathname, F_OK ) == 0 ) {
      // file exists
  fd=open(pathname,O_RDWR|O_APPEND,S_IRUSR | S_IRWXU);
  } else {
      // file doesn't exist
    fd=open(pathname,O_RDWR| O_CREAT |O_EXCL,S_IRUSR | S_IRWXU);
  }
  
  if(fd ==-1){
   perror("error open file");
   printf("\n");
   return 2;
  }
   printf("\n Created file.\n");
   return fd;
}

//write FileF8
int writeFileF8(char *pathname){
  //controllo e creo all'occorrenza file
 int  fd= creatFile(pathname);
  ssize_t numWrite;//controllo scrittura
 
  
  //scrivo header
  numWrite=write(fd,strHead,sizeof(strHead));
  if (numWrite != sizeof(strHead)){
       perror("error write fileF8");
       printf("\n");
       return 2;
  }

   return 0;
}