/*************************************************************/
/** admin.h - Header file for module admin                   */
/** Copyright: 2022                                          */
/** License: Tehnical University of Cluj-Napoca              */
/** Author: Alexandru Gavan and Antonia Szecsi               */
/** Version: 09-01-2023 - V1                                 */
/** Updates: -                                               */
/*************************************************************/


#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED


/** Include required headers **/
#include <time.h>
#include <stdio.h>
#include <strings.h>
#include <conio.h>
#include <stdlib.h>


/** Types definition **/
typedef struct book
{
    char id[20];
    char name[25];
    char dater[25];
    float costkids,costpupils,coststudents,costadults,costelders;
    int hour,minutes;
    int year,month,day;

} Movie;


/** Function prototypes **/
extern void currenttime();
extern void recordachizitions();
extern void insert_id();
extern void insert_name();
extern void insert_date();
extern void insert_cost();
extern void insert_timescheadule();
extern void add_priceage();


#endif // ADMIN_H_INCLUDED
