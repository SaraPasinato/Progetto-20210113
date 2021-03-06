#ifndef _ERREXIT_HH
#define _ERREXIT_HH
/// @file err_exit.h
/// @brief Contiene la definizione della funzione di stampa degli errori,con terminazione del processo con status 1.

#pragma once

/// @brief Prints the error message of the last failed
///         system call and terminates the calling process.
void ErrExit(const char *msg);
