/** Include system headers **/
#include "admin.h"



/**************************************************************************/
/** FUNCTION NAME: current_time                                           */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O             Description                    */
/** _______________________ ________ ____           ________________________________*/
/** VOID                    void    Console     Shows the current time */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void currenttime()
{
    time_t timenow;
    struct tm *timeinfo;
    time(&timenow);
    timeinfo=localtime(&timenow);
    printf("Current time and date is: %s",asctime(timeinfo));
}



/**************************************************************************/
/** FUNCTION NAME: insert_id                                              */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O             Description                    */
/** _______________________ ________ ____           ________________________________*/
/** VOID                    void    Input:Console     Insert the  id of movie */
/**                                 Output:FIle                                      */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void insert_id()
{
    FILE *fp;
    struct book movie;
    printf("\n Enter the Id of movie:");
    scanf("%s",movie.id);
    fp=fopen("moviefile.txt","a");
    if(fp==NULL)
    {
        printf("File not found!");
    }
    else
    {
        fprintf(fp,"The id of movie is:%s\n",movie.id);
        printf("\nThe id of movie has been added!");
        getch();

    }
    printf("\n");
    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: insert_name                                            */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O             Description                    */
/** _______________________ ________ ____           ________________________________*/
/** VOID                    void    Input:Console     Insert the name of movie       */
/**                                 Output:File                                      */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void insert_name()
{
    FILE *fp;
    Movie movie;
    printf("Enter the name of movie(For space introduce '_'):");
    scanf("%s",movie.name);
    fp=fopen("moviefile.txt","a");
    if(fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        fprintf(fp,"The name of movie is:%s\n",movie.name);
        printf("\nThe name of movie has been added!");
        getch();
    }
    printf("\n");
    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: insert_date                                            */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type         I/O               Description                    */
/** _______________________ ________     ____             ________________________________*/
/** VOID                    void         Input:Console     Insert the date of release      */
/**                                      Output:File                  of the movie         */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void insert_date()
{
    FILE *fp;
    Movie movie;
    int timer=0;


    fp=fopen("moviefile.txt","a");
    if(fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        do
        {
            printf("Introduce the year of release:");
            scanf("%d",&movie.year);

            if(movie.year>=1950 && movie.year<=2023)
            {
                printf("Introduce the month of release:");
                scanf("%d",&movie.month);
                if(movie.month>=1 && movie.month<=12)
                {
                    if(movie.month==1 || movie.month==3 || movie.month==5 ||movie.month==7 || movie.month==8 ||movie.month==10 || movie.month==12)
                    {
                        printf("Introduce the day of release:");
                        scanf("%d",&movie.day);
                        if(movie.day>=1 && movie.day<=31)
                        {
                            fprintf(fp,"The day of release is: %d\n",movie.day);
                            fprintf(fp,"The month of release is: %d\n",movie.month);
                            fprintf(fp,"The year of release is: %d\n",movie.year);
                            break;
                        }
                        else
                        {
                            printf("You have introduced a wrong number for day");
                            timer++;
                            getch();
                        }
                    }
                    else if(movie.month==4 || movie.month==6 ||movie.month==9 ||movie.month==11)
                    {
                        printf("Introduce the day of reservation:");
                        scanf("%d",&movie.day);
                        if(movie.day>=1 && movie.day<=30)
                        {
                            fprintf(fp,"The day of release is: %d\n",movie.day);
                            fprintf(fp,"The month of release is: %d\n",movie.month);
                            fprintf(fp,"The year of release is: %d\n",movie.year);
                            break;
                        }
                        else
                        {
                            printf("You have introduced a wrong number for day");
                            timer++;
                            getch();
                        }
                    }
                    else if(movie.month==2)
                    {
                        if((movie.year%4==0 && movie.year%100!=0) || (movie.year%400==0))
                        {
                            printf("Introduce the day of reservation:");
                            scanf("%d",&movie.day);
                            if(movie.day>=1 && movie.day<=29)
                            {
                                fprintf(fp,"The day of release is: %d\n",movie.day);
                                fprintf(fp,"The month of release is: %d\n",movie.month);
                                fprintf(fp,"The year of release is: %d\n",movie.year);
                                break;
                            }
                            else
                            {
                                printf("You have introduced a wrong number for day");
                                timer++;
                                getch();
                            }
                        }
                        else
                        {
                            printf("Introduce the day of reservation:");
                            scanf("%d",&movie.day);
                            if(movie.day>=1 && movie.day<=28)
                            {
                                fprintf(fp,"The day of release is: %d\n",movie.day);
                                fprintf(fp,"The month of release is: %d\n",movie.month);
                                fprintf(fp,"The year of release is: %d\n",movie.year);
                                break;
                            }
                            else
                            {
                                printf("You have introduced a wrong number for day\n");
                                timer++;
                                getch();
                            }
                        }


                    }

                }
                else
                {
                    printf("You have introduced a wrong number for month\n");
                    timer++;
                    getch();
                }
            }
            else
            {
                printf("You have introduced a wrong number for year\n");
                timer++;
                getch();
            }
        }
        while(timer<=2);
        fclose(fp);
    }
}


/**************************************************************************/
/** FUNCTION NAME: insert_cost                                            */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O             Description                    */
/** _______________________ ________ ____           ________________________________*/
/** VOID                    void    Input:Console     Insert the cost of movie */
/**                                 Output:File                                      */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void insert_cost()
{
    FILE *fp;
    struct book movie;
    printf("Enter the fee for kids:");
    scanf("%f",&movie.costkids);
    printf("Enter the fee for pupils:");
    scanf("%f",&movie.costpupils);
    printf("Enter the fee for students:");
    scanf("%f",&movie.coststudents);
    printf("Enter the fee for adults:");
    scanf("%f",&movie.costadults);
    printf("Enter the fee for elders:");
    scanf("%f",&movie.costelders);

    fp=fopen("moviefile.txt","a");
    if(fp==NULL)
    {
        printf("File not found");
    }
    else
    {
        fprintf(fp,"Fee for kids is: %.2f\n",movie.costkids);
        fprintf(fp,"Fee for pupils is: %.2f\n",movie.costpupils);
        fprintf(fp,"Fee for students is: %.2f\n",movie.coststudents);
        fprintf(fp,"Fee for adults is: %.2f\n",movie.costadults);
        fprintf(fp,"Fee for elders is: %.2f\n",movie.costelders);
        printf("\nThe cost of movie has been added!");
        getch();
    }
    printf("\n");
    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: insert_timeschadule                                    */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type        I/O             Description                   */
/** _______________________ ________   ____           ________________________________*/
/** VOID                    void      Input:Console     Insert the timescreen of movie*/
/**                                   Output:File                                 */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void insert_timescheadule()
{
    FILE *fp;
    Movie movie;

    printf("Introduce the hour: ");
    scanf("%d",&movie.hour);

    printf("Introduce the minutes: ");
    scanf("%d",&movie.minutes);

    fp=fopen("moviefile.txt","a");
    if(fp==NULL)
    {
        printf("File not found");
    }
    else
    {
        fprintf(fp,"The transmission time of movie is: %d:%d\n\n",movie.hour,movie.minutes);
        printf("\nThe timeline of movie has been added!\n");
    }

    printf("Movie has been added successfully\n");

    fclose(fp);

}



/**************************************************************************/
/** FUNCTION NAME: record_achizitions                                     */
/** DESCRIPTION:                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O             Description                    */
/** _______________________ ________ ____           ________________________________*/
/** VOID                    void    Input:File        Insert the date of id of movie */
/**                                 Output:Console                                     */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void recordachizitions()
{
    char ch;
    FILE *fp;
    fp=fopen("Historyoftransactions.txt","r");
    if(fp==NULL)
    {
        printf("The file doesn't exist!");
        exit(1);
    }
    else
    {
        while((ch=fgetc(fp))!=EOF)
            printf("%c",ch);
    }
    printf('\n');
    fclose(fp);
}
