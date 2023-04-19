/*************************************************************/
/** admin.h - Header file for module reservation             */
/** Copyright: 2022                                          */
/** License: Tehnical University of Cluj-Napoca              */
/** Author: Alexandru Gavan and Antonia Szecsi               */
/** Version: 09-01-2023 - V1                                 */
/** Updates: -                                               */
/*************************************************************/


#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED


/** Include required headers **/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>


/** Types definitions **/
typedef struct reserve
{
    char *first_name;
    char *last_name;
    char *number;
    char *movie;
    int day,month,year;
    int age;
    int hour,minutes;

} Person;

typedef struct book1
{
   float costkids,costpupils,coststudents,costadults,costelders;

} Movie1;


/** Function prototypes **/
extern void add_name();
extern void add_number();
extern void reserve_movie();
extern void add_date();


#endif // RESERVATION_H_INCLUDED
