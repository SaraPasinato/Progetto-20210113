/// @file defines.h
/// @brief Contiene la definizioni di variabili
///         e funzioni specifiche del progetto.

#pragma once
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#define S_CHILD 2
#define BUF_READ_SZ 256
#define BUF_MESSAGE_SZ 256
#define BUF_TYPE_MESSAGE_SZ 4
//dimensione massima di allocazione della stringa del path dei file
#define PATH_SZ 1024
#define SLEEP_TIME_S1 1
/**
*
* Struttura del messaggio del File F0.csv

typedef struct message{
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

*/
// controlla se è una isDirectory
int isDirectory(char *path);
// funzionalità dell processo S1
void s1_process(char *file);
