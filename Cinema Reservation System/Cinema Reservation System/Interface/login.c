/** Import system headers **/
#include "login.h"


/** Types definition **/
struct User
{
    char username[MAX_USERNAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
};



/**************************************************************************/
/** FUNCTION NAME: login_admin                                            */
/** DESCRIPTION:Logging in the admin on account                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type      I/O                     Description                    */
/** _______________________ ________ ____                    ________________________________*/
/** VOID                    Void     input:console          Logging in the admin on account   */
/**                                  output:file
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void login_admin()
{
    int timer=0;
    char adminname[15],character=' ';
    char *password=(char*)malloc(25*sizeof(char));
    do
    {
        printf("\n ************** ADMIN PANEL ********** \n");
        printf("\t\t\n Enter Username: ");
        scanf("%s",adminname);
        printf("\t\t\n Enter Password: ");
        int i=0;
        while(1)
        {
            character=getch();
            if(character==ENTER || character==TAB)
            {
                password[i]='\0';
                break;
            }
            else if(character==BCKSPC)
            {
                if(i>0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                password[i]=character;
                i++;
                printf("* \b");
            }
        }
        password[i]='\0';
        i=0;
        if(strcmp(adminname,"alexga")==0 && strcmp(password,"alex123")==0)
        {
            printf("\n\n\n\t\t\t Welcome to the admin board!! Connection has been successful");
            printf("\n\n\n\t\t\t Press any key to continue...");
            getch();
            break;
        }
        else if(strcmp(adminname,"antosec")==0 && strcmp(password,"anto123")==0)
        {
            printf("\n\n\n\t\t\t Welcome to the admin board!! Connection has been successful");
            printf("\n\n\n\t\t\t Press any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n\t\t\t Unfortunately...The login has failed!");
            timer++;
            getch();
        }
    }
    while(timer<=2);
    if(timer>2)
    {
        printf("\n\t\t\t Please try to connect again!!!");
        getch();
    }
    free(password);
    system("cls");
}



/**************************************************************************/
/** FUNCTION NAME: signup                                                 */
/** DESCRIPTION:Making a account of user                                                            */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O                  Description                    */
/** _______________________ ________ ____             ________________________________   */
/** VOID                    int      input:console     Making a account of user          */
/**                                  output:file                                         */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: int                                                     */
/** CHANGES:                                                              */
/**************************************************************************/

int signup(void)
{
    struct user User;

    // Get username and password from user
    printf("\t\t\n Enter a username: ");
    scanf("%s", User.username);
    printf("\t\t\n Enter a password: ");
    scanf("%s", User.password);

    // Open file for writing
    FILE *fp = fopen("userscinema.txt", "a+");
    if (fp == NULL)
    {
        printf("\t\t\n Error opening file!\n");
        return 1;
    }

    // Write user data to file
    fprintf(fp, "%s %s\n", User.username, User.password);

    // Close file
    fclose(fp);

    printf("\t\t\nSignup successful!\n");
    return 0;
}



/**************************************************************************/
/** FUNCTION NAME: login                                                  */
/** DESCRIPTION:Logging into your account                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O                Description                    */
/** _______________________ ________ ____              ________________________________*/
/** VOID                    int      Input:console      Logging into                               */
/**                                  Output:file      your account                                 */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: int                                                     */
/** CHANGES:                                                              */
/**************************************************************************/

int login(void)
{
    struct User user;
    char username[MAX_USERNAME_LEN+1];
    char password[MAX_PASSWORD_LEN+1];
    // Get username and password from user
    printf("\t\t\n Enter your username: ");
    scanf("%s", username);
    printf("\t\t\n Enter your password: ");
    scanf("%s", password);

    // Open file for reading
    FILE *fp = fopen("userscinema.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Read users from file and check for a match
    struct user User;
    int found = 0;
    while (fscanf(fp, "%s %s\n", user.username, user.password) == 2)
    {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
        {
            found = 1;
            break;
        }
    }

    // Close file
    fclose(fp);

    if (found)
    {
        welcome_message(user.username);
        return 0;
    }
    else
    {
        printf("\t\t\nInvalid username or password!\n");
        return 1;
    }
}




/**************************************************************************/
/** FUNCTION NAME: choose                                                 */
/** DESCRIPTION:Choosement between logging or signing up                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O              Description                    */
/** _______________________ ________ ____            ________________________________*/
/**                         Void     Console         Choosement between              */
/**                                                 logging or signing up            */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void choose()
{
    int choice;
    printf("\t\t\n Welcome");
    printf("\t\t\n 1.Signup");
    printf("\t\t\n 2.Login\n");
    printf(" Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
    {
        signup();
        break;
    }
    case 2:
    {
        login();
        break;
    }
    default:
    {
        printf("\t\t\n Invalid choice!\n");
        exit(1);
        break;
    }
    }

}



/**************************************************************************/
/** FUNCTION NAME: timec                                                  */
/** DESCRIPTION:Shows the current time                                                          */
/** ARGUMENT LIST:                                                        */
/** Argument                Type     I/O        Description                    */
/** _______________________ ________ ____      ________________________________*/
/**                         Void     Console    Shows the current time         */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void timec()
{
    time_t timenow;
    struct tm *timeinfo;
    time(&timenow);
    timeinfo=localtime(&timenow);
    printf("Current time and date is: %s",asctime(timeinfo));
}



/**************************************************************************/
/** FUNCTION NAME: welcome_message                                        */
/** DESCRIPTION  Print a message of welcoming user:                                                          */
/** ARGUMENT LIST:Struct User                                                         */
/** Argument                Type      I/O                 Description                       */
/** _______________________ ________  ____               ________________________________   */
/** Struct User             VOID     Input:file         Print a message of welcoming user  */
/**                                  Output:console                                        */
/**                                                                       */
/**                                                                       */
/**                                                                       */
/** RETURN VALUE: void                                                    */
/** CHANGES:                                                              */
/**************************************************************************/

void welcome_message(struct User user)
{
    FILE *fp;
    fp=fopen("userscinema.txt","r");
    printf("\t\t\nWELCOME TO OUR CINEMA RESERVATION SYSTEM,%s\n",user.username);
    fclose(fp);
}
