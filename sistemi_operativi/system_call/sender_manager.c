/// @file sender_manager.c
/// @brief Contiene l'implementazione del sender_manager.
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "err_exit.h"
#include "defines.h"
#include "shared_memory.h"
#include "semaphore.h"
#include "fifo.h"
#include "pipe.h"


char *fileF0 =NULL;
//path del file input
char *pathfile=NULL;

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
    pathfile=argv[1];
    //basename funzione ritorna l'ultimo componente dal pathname puntato eliminado / dal percorso
    fileF0=basename(argv[1]);
     printf("%s \n",fileF0);
    //controllo che non sia una directory
    if (isDirectory(fileF0)>0){
        printf("Error:inserimento directory %s/\n",fileF0);
        printf("Usage:\n");
        printf("%s <directory>/<filename> \n",argv[0]);
        return 1;
    }
  }
  //pid del padre
   pid_t ppid= getpid();
   printf("TEST: %d sono il padre\n",ppid);
  //Genera 3 figli Sender (S1,S2,S3)
 
  // Fork S1,S2,S3
  pid_t s1,s2,s3;
  char *args[]={"./s1",pathfile,NULL};
  s1 = fork();
  if (s1== -1)
    ErrExit("fork S1");
  if (s1== 0) {
    // S1 process
    printf("TEST: io sono S1 pid: %d \n",getpid());
     execv(args[0],args); 
     perror("execv");
    return 2;

  }else {

    s2=fork();
    if(s2== -1)
      ErrExit("fork S2");
    if (s2==0){
     printf("TEST: io sono S2 pid: %d \n",getpid());
      execv(args[0],args); 
     perror("execv");
    return 2;
    
    }else{

    s3=fork();
    if(s3== -1)
    ErrExit("fork S3");
    if (s3==0){
     printf("TEST: io sono S3 pid: %d \n",getpid());
     execv(args[0],args); 
     perror("execv"); /
    return 2;
     
    }
    }
  }
  
  
  
  //genera il file F8.csv da parte di sender Menager

 // aspetto che i figli terminino
 int status;
  pid_t wait_result;

    while ((wait_result = wait(&status)) != -1)
    {
        printf("Process %lu returned result: %d\n", (unsigned long) wait_result, status);
    }

    printf("All children have finished.\n");

    return 0;
}

