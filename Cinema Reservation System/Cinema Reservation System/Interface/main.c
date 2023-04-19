/** Include required headers **/
#include <stdio.h>
#include <stdlib.h>


/** Include system module headers **/
#include "admin.h"
#include "reservation.h"
#include "cinemaseats.h"
#include "login.h"


int main()

{
    int option,option1,option2;
    char answer;
    printf("\t\t\t\nIn which way do you entry in the system?");
    printf("\t\t\n 1.Administrator");
    printf("\t\t\n 2.User\n");
    scanf("%d",&option);
    do
    {
        switch(option)
        {
        case 1:
        {
            login_admin();
            printf("\t\t\n What do you wanna do?\n");
            do
            {
                printf("\t\t\n 1.Introduce a movie\n");
                printf("\t\t\n 2.Build the format of theatre\n");
                printf("\t\t\n 3.View the history of transactions\n");
                scanf("%d",&option1);
                switch(option1)
                {
                case 1:
                {
                    currenttime();
                    insert_id();
                    insert_name();
                    insert_cost();
                    insert_date();
                    insert_timescheadule();
                    getch();
                    system("cls");
                    break;
                }
                case 2:
                {
                    seat();
                    getch();
                    system("cls");
                    break;
                }
                case 3:
                {
                    recordachizitions();
                    getch();
                    system("cls");
                    break;
                }
                default:
                {
                    printf("\t\t\n You have introduced a wrong option! Bye Bye !!:))");
                    exit(1);
                    break;
                }
                }

            }
            while(option1!=0);
            break;
        }
        case 2:
        {
            choose();

            printf("\t\t\n Start reserving the movie:...\n");
            getch();
            system("cls");
            add_name();
            add_number();
            add_date();
            add_priceage();
            reserve_movie();
            reserved_seat();
            break;
        }
        default:
        {
            printf("\t\t\n You have introduced a wrong option! Bye Bye !!:))");
            exit(1);
            break;
        }
        }
    }
    while(option!=0);

}
