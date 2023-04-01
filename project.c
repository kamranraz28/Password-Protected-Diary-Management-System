#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
FILE *pass,*record;
int j;
char data[100000];
struct rec
{
    char name[30];
    char date[50];
    char note[100000];
};
struct ps
{
    char pass[100];
};
struct ps p;
struct rec x[100];
int ace;
int login();
void logout();
int addallrecord();
int onlynumber();
int newtime();
void makesinglestr();
void makegeneralstr();
int viewname();
void readall();
void passviewprocess();
int createpassword();
int checkpassword();
int main()
{
    char ch,name[100],note[10000];
    int a,i,k,check,flag,c;
    system("color 4F");
logout:
    check=login();
    if(check==0)
    {
main:
        system("cls");
        flag=0;
        readall();
        printf("\n\t**********************************************\n");
        printf("\t\tPASSWORD PROCTED PERSONAL DIARY\n");
        printf("\t**********************************************\n\n");
        printf("\n\n\tMAIN MENU:\n");
        printf("\n\tADD RECORD\t[1]");
        printf("\n\tVIEW RECORD\t[2]");
        printf("\n\tEDIT RECORD\t[3]");
        printf("\n\tDELETE RECORD\t[4]");
        printf("\n\tEDIT PASSWORD\t[5]");
        printf("\n\tLOGOUT\t\t[6]");
        printf("\n\tEXIT\t\t[7]");
        remove("delete.txt");
        printf("\n\n\tENTER YOUR CHOICE : ");
        makegeneralstr();
        c = onlynumber();
        switch(c)
        {
        case 1:
aaab:
            system("cls");
            printf("\n\n\t****************************************\n");
            printf("\t\tWELLCOME TO THE ADD MENU\n");
            printf("\t****************************************\n");
            printf("\n\n\tADD RECORD:\n\n");
            printf("\tEnter the headline of your note name\t: ");
aaaat:
            fflush(stdin);
            gets(x[j].name);
            if(x[j].name[0]=='\0')
                goto aaaat;
            for(i=0; i<j; i++)
            {
                if(strcmp(x[j].name,x[i].name)==0)
                {
                    printf("\n\tAlreday added by this headline\tGIVE ANOTHER HEAD LINE\tPress any key: ");
                    getch();
                    goto aaab;
                }
            }
            printf("\tWrite your note\t\t\t\t: ");
aaac:
            fflush(stdin);
            gets(x[j].note);
            if(x[j].note[0]=='\0')
                goto aaac;
            newtime();
            makesinglestr();
            a=addallrecord();
            if(a==1)
                printf("\n\tThe NOTE IS SAVED SUCCESFULLY\n");
            else
                printf("\n\tNOT SAVED..\n");
            printf("\n\tPress Enter button to go to main menu: ");
            getch();
            goto main;
        case 2:
            system("cls");
            printf("\n\t****************************************\n");
            printf("\t\tWELLCOME TO THE VIEW MENU\n");
            printf("\t****************************************\n\n");
            printf("\n\tMENU:");
            viewname();
            if(ace==2)
            {
                printf("\n\tEnter Your choice: ");
                i = onlynumber();
                i=i-1;
                if(i<j)
                {
                    printf("\n\t\tNOTE NAME\t\t: %s\n\t\tTIME & DATE\t\t: %s\n\t\tYOUR NOTE\t\t: %s\n\n",x[i].name,x[i].date,x[i].note);
                    flag=1;
                }
                if(flag==0)
                    printf("\n\tWrong choice\n");
            }
            if(ace==1)
            {
                printf("\n\tNO RECORD FOUND\n");
            }
            printf("\n\tPress Enter button to go to main menu: ");
            getch();
            goto main;
        case 3:
            system("cls");
            printf("\n\t****************************************\n");
            printf("\t\tWELLCOME TO EDIT MENU\n");
            printf("\t****************************************\n");
            viewname();
            if(ace==2)
            {
                printf("\n\tEnter Your choice: ");
                fflush(stdin);
                i = onlynumber();
                i=i-1;
                if(i<j)
                {
                    printf("\n\t\t1.\tNOTE NAME\t\t: %s\n\t\t2.\tTIME & DATE\t\t: %s\n\t\t3.\tYOUR NOTE\t\t: %s\n\n",x[i].name,x[i].date,x[i].note);
aaaa:
                    printf("\n\n\t\tEnter your choice, which you want to edit: ");
                    scanf("%d",&c);
                    switch(c)
                    {
                    case 1:
                        printf("\n\t\tEnter new note name: ");
aaaac:
                        fflush(stdin);
                        gets(x[i].name);
                        if(x[i].name[0]=='\0')
                            goto aaaac;
                        break;
                    case 2:
                        printf("\n\t\tYou can not change your old date\n");
                        break;
                    case 3:
                        printf("\n\t\tEnter new note [you can paste your old note and edit]: \n\t\t\t\t\t\t\t\t");
aaad:
                        fflush(stdin);
                        gets(x[i].note);
                        if(x[i].note[0]=='\0')
                            goto aaad;
                        break;
                    default:
                        printf("\n\t\tWrong choice...Enter any key to try again.\n");
                        getch();
                        goto aaaa;
                    }
                    printf("\n\t\tEdit another part? [Y/N]: ");
                    fflush(stdin);
                    scanf("%c",&ch);
                    if(ch=='Y' || ch=='y')
                        goto aaaa;
                    makesinglestr();
                    j--;
                    a=addallrecord();
                    if(a==1)
                        printf("\n\tThe NOTE IS EDITED SUCCESFULLY\n");
                    else
                        printf("\n\tERROR..\n");
                }
                else
                    printf("\n\tWrong Choice\n");
            }
            if(ace==1)
            {
                printf("\n\tNO RECORD FOUND\n");
            }
            printf("\n\tPress Enter button to go to main menu: ");
            getch();
            goto main;
        case 4:
            system("cls");
            printf("\n\t****************************************\n");
            printf("\t\tWELLCOME TO THE DELETE MENU\n");
            printf("\t****************************************\n\n");
            viewname();
            if(ace==2)
            {
                printf("\n\tEnter Your choice: ");
                i = onlynumber();
                k=i-1;
                for(i=k; i<j; i++)
                {
                    strcpy(x[i].name,x[i+1].name);
                    strcpy(x[i].date,x[i+1].date);
                    strcpy(x[i].note,x[i+1].note);
                }
                j--;
                makesinglestr();
                j--;
                a=addallrecord();
                if(a==1 && k<=j)
                    printf("\n\tThe NOTE IS DELETED SUCCESFULLY\n");
                else
                    printf("\n\tWrong choice\n");
            }
            if(ace==1)
            {
                printf("\n\tNO RECORD FOUND\n");
            }
            printf("\n\tPress Enter button to go to main menu: ");
            getch();
            goto main;
        case 5:
            checkpassword();
            createpassword();
            printf("\n\tPress Enter button to go to main menu: ");
            getch();
            goto main;
        case 6:
            logout();
            goto logout;
        case 7:
            printf("\n\n\t\tThank you for using this software BY:\n\n\t\tMd. Rafiul Islam\n\t\tMd Kamran hossan\n");
            exit(0);
        default:
            printf("\n\n\t\tYou entered wrong choich..\n\t\tPress any key to try again");
            getch();
            goto main;
        }
    }
}
int onlynumber()
{
    char ch;
    int c=0,d=0,b=0;
aaae:
    ch = getch();
    if(isdigit(ch)==1)
    {
        c = ch - 48;
        printf("%d",c);
        if(c==0)
        {
            printf("\b");
            printf(" ");
            printf("\b");
            goto aaae;
        }
        for(;;)
        {
            ch = getch();
            if(isdigit(ch)==1)
            {
                d = ch - 48;
                printf("%d",d);
                c=c*10+d;
            }
            if(ch=='\r')
                break;
            if(c==0 && b==0)
            {
                printf("\b");
                printf(" ");
                printf("\b");
                b--;
            }
            if(ch=='\b' && c!=0)
            {
                printf("\b");
                printf(" ");
                printf("\b");
                c/=10;
                if(c==0)
                    b--;
            }
        }
    }
    else
        goto aaae;
    return c;
}
int addallrecord()
{
    record = fopen("record.txt","w");
    if(record!=NULL)
    {
        for(int i=0; i<=j; i++)
        {
            fprintf(record,"%s %s %s\n",x[i].name,x[i].date,x[i].note);
        }
        fclose(record);
        return 1;
    }
    else
        return 0;
}
void makesinglestr()
{
    int i;
    for(int b=0; b<=j; b++)
    {
        for(i=0; i<strlen(x[b].name); i++)
        {
            if(x[b].name[i]==' ')
                x[b].name[i]='#';
        }
        for(i=0; i<strlen(x[b].date); i++)
        {
            if(x[b].date[i]==' ')
                x[b].date[i]='#';
        }
        for(i=0; i<strlen(x[b].note); i++)
        {
            if(x[b].note[i]==' ')
                x[b].note[i]='#';
        }
    }
}
void makegeneralstr()
{
    int i,k;
    for(k=0; k<j; k++)
    {
        for(i=0; i<strlen(x[k].name); i++)
        {
            if(x[k].name[i]=='#')
                x[k].name[i]=' ';
        }
        for(i=0; i<strlen(x[k].date); i++)
        {
            if(x[k].date[i]=='#')
                x[k].date[i]=' ';
        }
        for(i=0; i<strlen(x[k].note); i++)
        {
            if(x[k].note[i]=='#')
                x[k].note[i]=' ';
        }
    }
}
void readall()
{
    record = fopen("record.txt","r");
    int i=0;
    j=0;
    if(record!=NULL)
    {
        while(fscanf(record,"%s",data)!=EOF)
        {
            if(i%3==0)
                strcpy(x[j].name,data);
            else if(i%3==1)
                strcpy(x[j].date,data);
            else if(i%3==2)
                strcpy(x[j].note,data);
            i++;
            if(i>2 && i%3==0)
                j++;
        }
    }
    if(i<2)
        ace=1;
    else
        ace=2;
}
int viewname()
{
    printf("\n\tAll Note Name: \n");
    int i;
    for(i=0; i<j; i++)
    {
        printf("\n\t%d.\t%s",i+1,x[i].name);
    }
    printf("\n\n");
}
int newtime()
{
    time_t mytime = time(NULL);
    char *t = ctime(&mytime);
    t[strlen(t)-1] = '\0';
    strcpy(x[j].date,t);
}
int login()
{
    int a;
    pass = fopen("pass.txt","r");
    if(pass==NULL)
        a=createpassword();
    else
        a=checkpassword();
    if(a==0)
        return 0;
}
int createpassword()
{
abc:
    printf("\n\tEnter Your NEW password\t\t: ");
    passviewprocess();
    strcpy(data,p.pass);
    printf("\n\tEnter Your NEW password AGAIN\t: ");
    passviewprocess();
    if(strcmp(data,p.pass)==0)
    {
        pass = fopen("pass.txt","w");
        strcpy(x[0].name,data);
        makesinglestr();
        if(pass!=NULL)
        {
            fprintf(pass,"%s",x[0].name);
            printf("\n\tYOUR NEW PASSWORD IS SAVED SUCCESSFULLY");
            fclose(pass);
            return 0;
        }
    }
    else
    {
        printf("\n\tYOUR NEW PASSWORD IS NOT MATCHED.\n\tPRESS ENTER BUTTON TO TRY AGAIN.");
        getch();
        goto abc;
    }
}
int checkpassword()
{
    pass = fopen("pass.txt","r");
    int i;
    if(pass!=NULL)
        fscanf(pass,"%s",x[0].name);
    j=1;
    makegeneralstr();
    for(i=0; i<3; i++)
    {
        system("cls");
        printf("\t**************************************\n");
        printf("\t\tWELLCOME TO LOG IN PAGE\n");
        printf("\t**************************************\n");
        printf("\n\tEnter YOUR PASSWORD\t\t: ");
        passviewprocess();
        if(strcmp(p.pass,x[0].name)==0)
        {
            return 0;
            break;
        }
        else if(i<2)
        {
            printf("\n\n\tWRONG PASSWORD\n\tONLY THREE TRIALS ARE ALOWED.\n\n\tPress ENTER BUTTON TO TRY AGAIN\t: ");
            getch();
        }
    }
    if(i==3)
    {
        printf("\n\n\tWRONG PASSWORD\n\tYOUR THREE TIMES IS GONE\t: ");
        exit(0);
    }
}
void passviewprocess()
{
    int i=0;
    fflush(stdin);
    p.pass[0]=getch();
    while(p.pass[i]!='\r')
    {
        if(p.pass[i]=='\b' && i>0)
        {
            i--;
            printf("\b");
            printf(" ");
            printf("\b");
            p.pass[i]=getch();
        }
        else if(p.pass[0]!='\b')
        {
            printf("*");
            i++;
            p.pass[i]=getch();
        }
        else
            p.pass[0]=getch();
    }
    p.pass[i]='\0';
}
void logout()
{
    system("cls");
    printf("\n\tYour log out is succesful..\n\tNow press Enter button to go to log in page");
    getch();
}
