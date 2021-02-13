/// @file sender_manager.c
/// @brief Contiene l'implementazione del sender_manager.
#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>
#include "err_exit.h"
#include "defines.h"
#include "shared_memory.h"
#include "semaphore.h"
#include "fifo.h"
#include "pipe.h"

// Fork S1,S2,S3
pid_t s1,s2,s3;
char *fileF0 =NULL;
//path del file input
char *pathfile=NULL;
char *pathF8="OutputFiles/F8_p.csv";
//definzione buffer Scrittura
char *titolo="Id;PID";

int main(int argc, char *argv[]) {
  //menu 
  //assegnamento valori argv 
  if (argc != 2){
    printf("Usage:\n");
    printf("%s <directory>/<filename> \n",argv[0]);
    return 1;
  }
  //controllo che argv non sia nullo  e ottengo il nome del fileF0 
  if (argc==2 && argv[1] != NULL){
    //TODO: se serve per s1
    
    //basename funzione ritorna l'ultimo componente dal pathname puntato eliminado / dal percorso
    fileF0=basename(argv[1]);
     printf("TEST: %s \n",fileF0);
    //controllo che non sia una directory
    if (isDirectory(fileF0)>0){
        printf("Error:inserimento directory %s/\n",fileF0);
        printf("Usage:\n");
        printf("%s <directory>/<filename> \n",argv[0]);
        return 1;
    }else{
      //posso usare pathfile per leggere F0 in S1 
      pathfile=argv[1];
    }
  }
  //pid del padre
   pid_t SM= getpid();
   printf("TEST: %d sono il padre\n",SM);
  //Genera 3 figli Sender (S1,S2,S3)
 char *args[] = { "s1",pathfile, NULL };
  //########## genero S1 S2 S3 figli di Sender Menager
  s1 = fork();
  if (s1== -1)
    ErrExit("fork S1");
  if (s1== 0) {
    // S1 :esecuzione processo s1
     execvp("./s1",args);
      // s1_process(pathfile);
  }/**else {
    s2=fork();
    if(s2== -1)
      ErrExit("fork S2");
    if (s2==0){
      printf("TEST: io sono s2 ");
       // S1 :esecuzione processo s1
      process_s2();
    }else{
    s3=fork();
    if(s3== -1)
      ErrExit("fork S3");
    if (s3==0){
      printf("TEST: io sono s3 ");
      process_s3();
    }
    }
  }**/
  
  //######### genera il file F8.csv da parte di sender Menager ##########
  /**
  int fd=open(pathF8,O_RDWR|O_CREAT|O_TRUNC|O_EXCL,S_IRUSR|S_IWUSR);
  if (fd==-1)
    ErrExit("Failed Open F8_p");

  ssize_t numWrite= write(fd,header,sizeof(header));
  if(numWrite != sizeof(header))
      ErrExit("errore Write");

    close(fd);
  **/
    return 0;
}

