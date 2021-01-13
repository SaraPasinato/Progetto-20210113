/// @file defines.h
/// @brief Contiene la definizioni di variabili
///         e funzioni specifiche del progetto.

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#define BUF_READ_SZ 256
#define BUF_MESSAGE_SZ 256
#define BUF_TYPE_MESSAGE_SZ 4
//dimensione massima di allocazione della stringa del path dei file
#define PATH_SZ 1024
#define SLEEP_TIME_S1 1

/**
* Nodo per double linked list di Message head
**/
typedef struct list_head{
  struct list_head *next;
  struct list_head *prev;
} list_head_t;

/**
*
* @brief inizializza una lista list_head
* @param head la testa della lista
**/
static void list_head_init(list_head_t *list);

/**
*
* @brief testa se la lista e vuota
* @param head la testa della lista da controllare
* @return 1 se è vuota altrimenti 0
**/
static int list_head_empty(list_head_t const * head);
/**
*
* @brief Inserisco un noda a  list_head_t tra 2 nodi conosciuti
* @param *next puntatote al prossimo nodo della lista
* @param *prev puntatore al nodo precedente
* @param *new  puntatote del nodo da collegare
**/
static void list_add(list_head_t * new, list_head_t * prev, list_head_t * next);

/**
*
* @brief ottengo la stuttura per il nodo
* @param ptr puntatote al riferimento della testa 
* @param type tipo di struttura 
* @param member il nome della list_head specificata da type
**/
#define void list_entry(ptr, type, member)   
    ((type *)((char*)(ptr)- (unsigned long)(&((type *)0)->memeber)))
/**
*
* @brief itero sulla lista
* @param pos iteratore sulla struttura di riferimento dalla           testa della lista
* @param head testa della lista
**/
#define void list_for_each(pos,head)(    
  for ((pos)=(head)-> next;(pos)!= (head); (pos)=(pos)->next)
)
