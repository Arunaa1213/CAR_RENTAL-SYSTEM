#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct login{
    char fname[50];
    char username[50];
    char password[50];
};
int logins=0;
struct owner{
    int car_code;
    char car_name[25];
    int rent;
    char place[30];
    struct owner *next;
};

int code1;
int kms,days,week;
struct owner *head,*temp,*tail;
void create()
{
    temp=(struct owner *)malloc(sizeof(struct owner));
    printf("Enter the car code:");
    scanf("%d",&temp->car_code);
    printf("Enter the car name :");
    scanf("%s",temp->car_name);
    printf("Enter the rent per day : ");
    scanf("%d",&temp->rent);
    printf("Enter the place : ");
    scanf("%s",temp->place);
}
void creation()
{
    int choice=1;
    head=0;
    while(choice)
    {
        create();
        temp->next=0;
        if(head==0)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        printf("\n\nDo you want to continue (0 for no / 1 for yes)");
        scanf("%d",&choice);
    }
    printf("\n\n");
}

void display()
{
    
    temp=head;
    if(temp == 0)
    {
        printf("list is empty");
    }
    else{
        printf("Car code\tCarName \t Rentprice \t Place \n");
    while(temp!=0)
    {
        printf("%d\t\t %s \t\t %d \t\t %s\n",temp->car_code,temp->car_name,temp->rent,temp->place);
        temp=temp->next;
    }
    }
    printf("\n\n");
}
void update()
{
    struct owner *temp1=head;
    int code;
    printf("Enter the car code where you want to update : ");
    scanf("%d",&code);
    while(temp1!=0)
    {
        if(temp1->car_code == code)
        {
            printf("Enter the car details : \n");
            printf("Enter the car name : ");
            scanf("%s",temp1->car_name);
            printf("Enter the rent : ");
            scanf("%d",&temp1->rent);
            printf("Enter the place : ");
            scanf("%s",temp1->place);
            printf("\n UPDATED CAR DETAILS IS : \n");
            printf("Car code :%d \nCar name : %s \nCar rent :%d \nCar place : %s \n",temp1->car_code,temp1->car_name,temp1->rent,temp1->place);
        }
        temp1=temp1->next;
    }
    printf("UPDATED SUCCESSFULLY!!!");
}

void select()
{
    
    int kms,days,week;
    struct owner *temp2=head;
    printf("Enter the car code to select : \n");
    display();
    scanf("%d",&code1);
    while(temp2!=0)
    {
        if(temp2->car_code == code1)
        {
            printf("Car name : %s \n Car rent per day  : %d \n Cestination place : %s\n",temp2->car_name,temp2->rent,temp2->place);
        }
    temp2=temp2->next;
    }
    printf("\n\n");
}

void amount()
{
    struct owner *temp3=head;
    int rent2=0;
    printf("\nFOR EVERY ONE EXTRA KILOMETERS RS.30 WILL BE ADDED !!!\n");
    printf("If you want to travel extra km , enter the approxiamate kms (if not press 0): \n");
    scanf("%d",&kms);
    printf("\nTHE ABOVE RENT PRICE IS FOR ONE DAY!!!\n");
    printf("For how many days you want car : \n");
    scanf("%d",&days);
    printf("\nIF YOU RENT CAR FOR WEEKENDS THE PRICE WILL INCREASED BY RS.1000!!!\n");
    printf("Do you want car in weekends(press 1 for yes , (or) 0 for no : \n");
    scanf("%d",&week);
    while(temp3!=0)
    {
        if(temp3->car_code == code1)
        {
            rent2 += temp3->rent * days;
           if(kms!=0)
           {
               rent2 += kms*30;
           }
           if(week==1)
           {
               rent2 += 1000;
           } 
        }
    temp3=temp3->next;
    }
    printf("\nTOTAL AMOUNT FOR THE CAR YOU SELECTED IS  : %d\n\n\n ",rent2);
}
void login(){
     char username[50],password[20];
     FILE *log;
     log=fopen("login12.txt","r");
     struct login l;
     printf("USERID : ");
     scanf("%s",&username);
    printf("PASSWORD : ");
    scanf("%s",&password);
    while(fread(&l,sizeof(l),1,log)){
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            logins++;
            printf("\nSUCCESSFULLY LOGGED IN !!!\n\n");}
        else{
            printf("\nERROR...INCORRECT USERNAME OR PASSWORD! PLEASE ENTER CORRECT VALUE!!!\n");}
    }
    fclose(log);
 }

void register_fun()
 {
     FILE *log;
     log=fopen("login12.txt","w");
     struct login l;
    printf("Enter the first name : \n");
    scanf("%s",l.fname);
    printf("Enter the username : \n");
    scanf("%s",l.username);
    printf("Enter the password : \n");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    printf("\n\nyour USERNAME is your USERID \n");
    printf("Now login with USERID and PASSWORD\n\n");
    
    login();
 }
int main()
{
    int choice1,choice2,choice3,code1;
    char car[50];
    int num,rent1,place1;
    struct owner *temp2=head;
    do{
    printf("SELECT THE OPTION: \n 1) Enter as owner  \n 2) Enter as customer \n 3) Exit\n");

    scanf("%d",&choice1);

    switch(choice1)
    {
        case 1:
            {
                
                do{
                    printf("\nSELECT THE OPTION : \n 1) Enter car data \n 2) Update details \n 3)Exit\n");
                    scanf("%d",&choice2);
                    switch(choice2){
                        case 1:
                            creation();
                        break;
                        case 2:
                            update();
                            break;
                    }
                }while(choice2!=3);
            }
            break;
        case 2:
            {
                do{
                    printf("WELCOME !!!");
                    printf("\nSELECT THE OPTION : \n 1)New Registration  \n 2)Rent Car\n 3)Total amount \n 4)exit\n");
                    scanf("%d",&choice3);
                    switch(choice3){
                        case 1:
                        register_fun();
                        break;
                        case 2:{
                            if(logins!=0)
                            {
                            select();
                            }
                            else  
                                printf("\n\nYOU'RE NOT A REGISTERED USER . PLEASE REGISTER TO CONTINUE.\n\n");
                        }
                        break;
                        case 3:
                            amount();
                            break;
                    }
                }while(choice3!=3);
            }
            break;
    }
    }while(choice1!=3);

}