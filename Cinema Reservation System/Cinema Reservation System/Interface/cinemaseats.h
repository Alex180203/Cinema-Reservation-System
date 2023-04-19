/*************************************************************/
/** cinemaseats.h - Header file for module cinema seats      */
/** Copyright: 2022                                          */
/** License: Tehnical University of Cluj-Napoca              */
/** Author: Alexandru Gavan and Antonia Szecsi               */
/** Version: 09-01-2023 - V1                                 */
/** Updates: -                                               */
/*************************************************************/


#ifndef CINEMASEATS_H_INCLUDED
#define CINEMASEATS_H_INCLUDED


/** Include required headers **/
#include <stdio.h>
#include <stdlib.h>


/** Constant definition **/
#define Rowlimit 10
#define Columnlimit 11


/** Function prototypes **/
extern void seat();
extern int change(FILE*,FILE*);
extern int verify(int,int);
extern void reserved_seat();


#endif // CINEMASEATS_H_INCLUDE
