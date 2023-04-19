/*************************************************************/
/** admin.h - Header file for module login                   */
/** Copyright: 2022                                          */
/** License: Tehnical University of Cluj-Napoca              */
/** Author: Alexandru Gavan and Antonia Szecsi               */
/** Version: 09-01-2023 - V1                                 */
/** Updates: -                                               */
/*************************************************************/


#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED


/** Include required headers **/
#include <time.h>
#include <stdio.h>
#include <strings.h>
#include <conio.h>
#include <stdlib.h>


/** Constant definition **/
#define ENTER 13
#define TAB 9
#define BCKSPC 8

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50


/** Types definition **/
struct user {
    char username[MAX_USERNAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
};

typedef struct person
{
    char *firstname;
    char *lastname;
    char *username;
    char *email;
    char *password;
}User1;


/** Function prototypes **/
extern int login();
extern int signup();
extern void login_admin();
extern void timec();
extern void choose();
extern void welcome_message();


#endif // LOGIN_H_INCLUDED
