/// @file sender_manager.c
/// @brief Contiene l'implementazione del sender_manager.
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>
#include "err_exit.h"
#include "defines.h"
#include "shared_memory.h"
#include "semaphore.h"
#include "fifo.h"
#include "pipe.h"

char *fileF0 =NULL;


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
    //basename funzione ritorna l'ultimo componente dal pathname puntato eliminado / dal percorso
    fileF0=basename(argv[1]);
    printf("%s file F0\n",fileF0);
   
  }
  
  //Genera 3 figli Sender (S1,S2,S3)
  //genera il file F8.csv da parte di sender Menager
  
    return 0;
}

