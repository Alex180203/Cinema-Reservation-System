/** Import system headers **/
#include "cinemaseats.h"


/** IMPLEMENTATION OF THE PUBLIC FUNCTIONS **/



/**************************************************************************/
/** FUNCTION NAME: seat                                                   */
/** DESCRIPTION:"Construct" the theatre                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O             Description                    */
/** _______________________ ________ ____           ________________________________*/
/** VOID                    void    Input:Console     "Construct" the theatre */
/**                                 Output:File                                      */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void seat()
{
    int i,j,k=0,pick,rows,columns;
    FILE *fp;
    printf("t\t\nIntroduce the number of rows:");
    scanf("%d",&rows);
    printf("t\t\nIntroduce the number of columns:");
    scanf("%d",&columns);

    int **seat=(int**)calloc(rows,sizeof(int*));
    for(i=0; i<rows; i++)
    {
        seat[i]=(int*)calloc(columns,sizeof(int));
    }
    fp=fopen("places.txt","w");
    if(fp==NULL)
    {
        printf("t\t\nFile not found");
        exit(1);
    }
    else if(verify(rows,columns)==0)
    {
        printf("t\t\nYou have introduced a number which succeed the limit of rows/columns");
        exit(1);
    }
    else
    {
        fprintf(fp,"%d ",rows);
        fprintf(fp,"%d\n",columns);

        for(i=0; i<rows; i++)
        {
            for(j=0; j<columns; j++)
            {
                k++;
                seat[i][j]=k;
            }
        }

        for(i=0; i<rows; i++)
        {
            for(j=0; j<columns; j++)
            {
                fprintf(fp,"%d ",seat[i][j]);
            }
            fprintf(fp,"\n");
        }

    }
    for(i=0; i<rows; i++)
        free(seat[i]);
    free(seat);
    fclose(fp);
}



/**************************************************************************/
/** FUNCTION NAME: verify                                                 */
/** DESCRIPTION:Verify the conditions                                                          */
/** ARGUMENT LIST:int rows,int columns                                                        */
/** Argument                Type       I/O             Description                    */
/** _______________________ ________  ____           ________________________________*/
/** Number of rows/columns            void             Verify the conditions*/
/**                                                                      */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

int verify(int rows,int column)
{
    if(rows>Rowlimit ||column>Columnlimit)
        return 0;
    return 1;
}



/**************************************************************************/
/** FUNCTION NAME: reserved_seat                                          */
/** DESCRIPTION:Let us to choose the seats(by dynamical allocated matrix)         */
/** ARGUMENT LIST:                                                        */
/** Argument                Type         I/O                   Description                    */
/** _______________________ ________    ____                ________________________________*/
/** VOID                        void    File/Console           Let us to choose the seats */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void reserved_seat()
{
    int c,ok,pick=0,i,j,k,l,m,numberseat;
    int rows,columns,pozi,pozj,prow,pcolumns;
    int **seats_free,**seats_take;
    FILE *fp,*fp2;
    FILE *fp1;

    fp=fopen("places.txt","r");
    fp2=fopen("places_reserved.txt","w");
    fp1=fopen("Historyoftransactions.txt","a");
    if(fp==NULL)
    {
        printf("t\t\nFile not found");
        exit(1);
    }
    fscanf(fp,"%d%d",&rows,&columns);

    seats_take=(int**)calloc(rows,sizeof(int*));
    for(i=0; i<rows; i++)
    {
        seats_take[i]=(int*)calloc(columns,sizeof(int));
    }

    for(i=0; i<rows; i++)
        for(j=0; j<columns; j++)
        {
            fscanf(fp,"%d",&seats_take[i][j]);
        }
    printf("t\t\nWrite the number of seats:\n");
    scanf("%d",&numberseat);
    m=0;
    do
    {
        ok=0;
        printf("t\t\nWrite the pick:\n");
        scanf("%d",&pick);
        if(seats_take[0][0]>pick || seats_take[rows-1][columns-1]<pick)
        {
            printf("t\t\nYou have picked an invalid seat!");
        }
        else
        {
            for(i=0; i<rows; i++)
                for(j=0; j<columns; j++)
                {
                    if(seats_take[i][j]!=pick)
                    {
                        ok=1;
                        k=pick;
                    }
                    else if(seats_take[i][j]==pick)
                    {
                        seats_take[i][j]=0;
                        ok=0;
                        k=0;
                        break;
                    }
                }

            if(ok==1)
            {
                fprintf(fp1,"The seat you have selected is:%d\n",k);
                printf("t\t\nYour seat has been reserved\n!");
            }
            else
            {
                printf("t\t\nThe seat is already reserved!");
            }
            for(i=0; i<rows; i++)
            {
                for(j=0; j<columns; j++)
                {
                    printf("t\t\n%d ",seats_take[i][j]);
                }
                printf("\n");
            }
        }
        m++;
    }
    while(m<numberseat);
    fprintf(fp1,"\n");
    for(i=0; i<rows; i++)
        free(seats_take[i]);
    free(seats_take);
    fclose(fp);
    fclose(fp1);
}
