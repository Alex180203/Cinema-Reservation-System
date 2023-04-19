/** Import system headers **/
#include "reservation.h"



/**************************************************************************/
/** FUNCTION NAME: add_name                                               */
/** DESCRIPTION:   Add the name of person for reservation                                               */
/** ARGUMENT LIST:                                                        */
/** Argument                Type      I/O                 Description                       */
/** _______________________ ________  ____               ________________________________   */
/**                          VOID     Input:File/Console         Add the name of            */
/**                                  Output:Console/File        person for reservation      */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void add_name()
{
    FILE *fp;
    Person p;

    p.first_name=(char*)malloc(24*sizeof(char));
    p.last_name=(char*)malloc(24*sizeof(char));

    printf("\t\t\n Enter first name:");
    scanf("%s",p.first_name);
    printf("\t\t\n Enter last name:");
    scanf("%s",p.last_name);

    fp=fopen("Historyoftransactions.txt","a");

    if(fp==NULL)
    {
        printf("\t\t\nFile not found");
    }
    else
    {
        fprintf(fp,"The first name of person is:%s\n",p.first_name);
        fprintf(fp,"The last name of person is:%s\n",p.last_name);
    }

    free(p.first_name);
    free(p.last_name);

    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: add_number                                             */
/** DESCRIPTION:  Add the number of phone for reservation                                                   */
/** ARGUMENT LIST:                                                        */
/** Argument                Type      I/O                 Description                           */
/** _______________________ ________  ____               ________________________________       */
/**                          VOID     Input:File/Console         Add the number of              */
/**                                  Output:Console/File              phone for reservation     */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void add_number()
{
    FILE *fp;
    Person p;
    p.number=(char*)malloc(10*sizeof(char));

    fp=fopen("Historyoftransactions.txt","a");

    printf("Enter the number of phone:");
    scanf("%s",p.number);
    if(fp==NULL ||strlen(p.number)<10)
    {
        printf("\t\t\n Error! Invalid data introduced!\n");
        exit(1);
    }
    else if(fp!=NULL && strlen(p.number)==10)
    {
        for(int i=0; i<strlen(p.number); i++)
        {
            if(isdigit(p.number[i]))
            {
                fprintf(fp,"The number of phone is:%s\n",p.number);
                break;
            }
        }
    }
    free(p.number);

    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: reserve_movie                                          */
/** DESCRIPTION:  Add the movie of reservation                                                  */
/** ARGUMENT LIST:                                                        */
/** Argument                Type      I/O                 Description                           */
/** _______________________ ________  ____               ________________________________       */
/**                          VOID     Input:File/Console         Add the movie of reservation   */
/**                                  Output:Console/File                                        */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void reserve_movie()
{
    int option,option1;
    char *movie,*moviename,ch;
    FILE *fp;
    FILE *fp1;
    Person p;
    p.movie=(char*)malloc(30*sizeof(char));
    movie=(char*)malloc(30*sizeof(char));

    fp=fopen("Historyoftransactions.txt","a");
    fp1=fopen("moviefile.txt","r");

    if(fp1==NULL)
    {
        printf("\t\t\n File doesn't exist!");
        exit(1);
    }
    else
    {
        while((ch=fgetc(fp1))!=EOF)
        {
            printf("%c",ch);
        }
    }

    printf("\t\t\n Choose your option for movie:");
    scanf("%s",p.movie);

    printf("\t\t\n Add timeline for movie:");
    scanf("%d",&p.hour);
    scanf("%d",&p.minutes);

    fprintf(fp,"The movie choose is:%s\n",p.movie);
    fprintf(fp,"The time is %d:",p.hour);
    fprintf(fp,"%d\n",p.minutes);

    free(p.movie);
    free(movie);

    fclose(fp);
    fclose(fp1);
}



/**************************************************************************/
/** FUNCTION NAME: add_date                                               */
/** DESCRIPTION:Add the date of reservation                                                            */
/** ARGUMENT LIST:                                                        */
/** Argument                Type      I/O                 Description                       */
/** _______________________ ________  ____               ________________________________   */
/**                          VOID     Input:File         Add the date of reservation       */
/**                                  Output:Console                                        */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void add_date()
{
    Person p;
    FILE *fp;
    fp=fopen("Historyoftransactions.txt","a");
    int timer=0;

    do
    {
        printf("\t\t\n Introduce the year of reservation:");
        scanf("%d",&p.year);

        if(p.year>=2023 && p.year<=2024)
        {
            printf("\t\t\n Introduce the month of reservation:");
            scanf("%d",&p.month);
            if(p.month>=1 && p.month<=12)
            {
                if(p.month==1 || p.month==3 || p.month==5 || p.month==7 || p.month==8 || p.month==10 || p.month==12)
                {
                    printf("\t\t\n Introduce the day of reservation:");
                    scanf("%d",&p.day);
                    if(p.day>=1 && p.day<=31)
                    {
                        fprintf(fp,"The day of reservation is: %d\n",p.day);
                        fprintf(fp,"The month of reservation is: %d\n",p.month);
                        fprintf(fp,"The year of reservation is: %d\n",p.year);
                        break;
                    }
                    else
                    {
                        printf("\t\t\n You have introduced a wrong number for day");
                        timer++;
                        getch();
                    }
                }
                else if(p.month==4 || p.month==6 || p.month==9 || p.month==11)
                {
                    printf("\t\t\n Introduce the day of reservation:");
                    scanf("%d",&p.day);
                    if(p.day>=1 && p.day<=30)
                    {
                        fprintf(fp,"The day of reservation is: %d\n",p.day);
                        fprintf(fp,"The month of reservation is: %d\n",p.month);
                        fprintf(fp,"The year of reservation is: %d\n",p.year);
                        break;
                    }
                    else
                    {
                        printf("\t\t\t\n You have introduced a wrong number for day");
                        timer++;
                        getch();
                    }
                }
                else if(p.month==2)
                {
                    if((p.year%4==0 && p.year%100!=0) || (p.year%400==0))
                    {
                        printf("\t\t\n Introduce the day of reservation:");
                        scanf("%d",&p.day);
                        if(p.day>=1 && p.day<=29)
                        {
                            fprintf(fp,"The day of reservation is: %d\n",p.day);
                            fprintf(fp,"The month of reservation is: %d\n",p.month);
                            fprintf(fp,"The year of reservation is: %d\n",p.year);
                            break;
                        }
                        else
                        {
                            printf("\t\t\n You have introduced a wrong number for day");
                            timer++;
                            getch();
                        }
                    }
                    else
                    {
                        printf("\t\t\t\n Introduce the day of reservation:");
                        scanf("%d",&p.day);
                        if(p.day>=1 && p.day<=28)
                        {
                            fprintf(fp,"The day of reservation is: %d\n",p.day);
                            fprintf(fp,"The month of reservation is: %d\n",p.month);
                            fprintf(fp,"The year of reservation is: %d\n",p.year);
                            break;
                        }
                        else
                        {
                            printf("\t\t\n You have introduced a wrong number for day\n");
                            timer++;
                            getch();
                        }
                    }


                }

            }
            else
            {
                printf("\t\t\n You have introduced a wrong number for month\n");
                timer++;
                getch();
            }
        }
        else
        {
            printf("\t\t\n You have introduced a wrong number for year\n");
            timer++;
            getch();
        }
    }
    while(timer<=2);

    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: add_priceage                                           */
/** DESCRIPTION:  Add the price of reservation                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type      I/O                 Description                       */
/** _______________________ ________  ____               ________________________________   */
/**                          VOID     Input:File/Console         Add the price of reservation       */
/**                                  Output:Console/File                                        */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void add_priceage()
{
    int age,option,numberseats=0,nr;
    float fee=1;
    Movie1 movie;
    FILE *fp;
    FILE *fp1;
    fp=fopen("Historyoftransactions.txt","a");
    fp1=fopen("moviefile.txt","r");

    printf("\t\t\n Introduce the number of seats:");
    scanf("%d",&numberseats);

    nr=1;
    do
    {
        printf("\t\t\n Introduce your age:");
        scanf("%d",&age);

        if(age>=0 && age<=12)
        {
            movie.costkids=25.5;
            fee=fee+movie.costkids;
        }
        else if(age>=13 && age<18)
        {
            movie.costpupils=30.0;
            fee=fee+movie.costpupils;
        }
        else if(age>=18 && age<=26)
        {
            printf("\t\t\n Are you student??\n");
            printf("\t\t\n 1:Yes!");
            printf("\t\t\n 2:No!");
            scanf("%d",&option);

            switch(option)
            {
            case 1:
            {
                movie.coststudents=32.5;
                fee=fee+movie.coststudents;
                break;
            }
            case 2:
            {
                movie.costadults=35.0;
                fee=fee+movie.costadults;
                break;
            }
            default:
                printf("\t\t\n You are not student or adult!");
            }
        }
        else if(age>=27 && age<=60)
        {
            movie.costadults=35.0;
            fee=fee+movie.costadults;
        }
        else
        {
            movie.costelders=30.0;
            fee=fee+movie.costelders;

        }
        nr++;
    }
    while(nr<=numberseats);
    fprintf(fp,"%.1f\n",fee);
    printf("\t\t\n%.1f\n",fee);
    fclose(fp);
    fclose(fp1);

}


