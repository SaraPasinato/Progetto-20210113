#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <unistd.h>
/// @file defines.c
/// @brief Contiene l'implementazione delle funzioni
///         specifiche del progetto.

#include "defines.h"


/**
*
* Struttura del messaggio del File F0.csv
*/
typedef struct Message{
  int message_id;
  char message[BUF_MESSAGE_SZ];
  pid_t pid_sender;
  pid_t pid_receiver;
  int DelS1;
  int DelS2;
  int DelS3;
  char message[BUF_TYPE_MESSAGE_SZ];
  list_head_t list; //testa della lista

} message_t;