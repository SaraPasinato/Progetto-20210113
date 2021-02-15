/// @file sender_manager.c
/// @brief Contiene l'implementazione del sender_manager.
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "err_exit.h"
#include "defines.h"
#include "shared_memory.h"
#include "semaphore.h"
#include "fifo.h"
#include "pipe.h"

// #########         Variabili      ################
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

  // ########### Creo il padre ###############
  
   pid_t ppid= getpid(); //pid del padre
   printf("TEST: %d sono il padre\n",ppid);

  // ######### Genera 3 figli Sender (S1,S2,S3) #########

  pid_t s1,s2,s3;
  //argomenti args per execv s1
  char *args[]={"./s1",pathfile,NULL};
  //TODO argomenti per s2 e S3

   creatFile("OutputFiles/F8.csv");  
  s1 = fork(); //creo s1

  if (s1== -1)
    ErrExit("fork S1");
  if (s1== 0) {
    // Codice s1 
    printf("TEST: io sono S1 pid: %d \n",getpid());
     execv(args[0],args); 
     perror("execv");
    return 2;

  }else {
    // codice s2
    s2=fork();
    if(s2== -1)
      ErrExit("fork S2");
    if (s2==0){
        printf("TEST: io sono S2 pid: %d \n",getpid());
          execv(args[0],args); 
        perror("execv");
        return 2;
      
      }else{
          // codice s3
        s3=fork();
        if(s3== -1)
        ErrExit("fork S3");

        if (s3==0){
          printf("TEST: io sono S3 pid: %d \n",getpid());
          execv(args[0],args); 
          perror("execv"); 
          return 2;
        
        }
      }
  }
  
  
  
  // ######## SM genera il file F8.csv  ############
  
 //########## aspetto che i figli terminino ###############
  int status;//stato wait
  pid_t wait_result; //pid tel figlio terminato

  while ((wait_result = wait(&status)) != -1)
  {
     if (status==0){
       printf("\nProcess %lu terminated normally.\n\n", (unsigned long) wait_result);
     }else{
       printf("Process %lu terminated  with  error:\n\n", (unsigned long) wait_result);
       perror("Error wait");
       return 2;
     }
  }
 
  printf("All children have finished.Terminated normally.\n");
 
  return 0;
}

