#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
// firstly we will declear some global functions. why? because we are going to
// use same varaibles in many functions. If we dont use global variables we have to declare them every time 
//so to avoid a lot of work we will use global variables..
char name[20];
int Deposit_amt;
int amt = 10000; //intially we are having 10000 as account balance.
int account_no;
int withdraw_amt;
int trans_amt;
void menu();
void Deposit_money();
void withdraw_money();
void transfer_money();
void account_Detail();
void transaction_details();
void LastDetail();
int main(){
    int choice;
    printf("Enter your name : ");
    gets(name);

    printf("Enter your account no. : ");
    scanf("%d", &account_no);
    while (1)
    {
     menu();
    
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice){
         case 1:
            Deposit_money();
            break;
        case 2:
            withdraw_money();
            break;
        case 3:
             transfer_money();
            break;

        case 4:
            account_Detail();
            break;

        case 5:
            transaction_details();
            break;

        case 6:
            LastDetail();
            exit(0);
            default:
            printf("Invalid Choice!!!");
            break;
    }
}
    return 0;
}

void menu(){
    printf("Main menu\n");
    printf("1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account Details\n");
    printf("5.Transaction Details\n");
    printf("6.Exit\n");
};
void Deposit_money(){
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt","a");
    printf("Depositing Money \n");
    printf("Enter the amount: \n");

    scanf("%d",&Deposit_amt);
    if (Deposit_amt<=0)
    {
      printf("Deposited money cant be in negative or zero\n");
      Deposit_money();
    }
    
    
     amt += Deposit_amt;
     printf("Money deposited \n ");
    printf("Current balance : %d",amt);
    fprintf(ptr,"Rs %d has been deposited to your account \n",Deposit_amt);
    fprintf(ptr,"Date / time of transaction %s", ctime(&tm));
    getch();
}
 void withdraw_money(){
     time_t tm;
    time(&tm);
       FILE *ptr = fopen("Account.txt","a");
   printf("Withdraw Money \n");
   printf("Enter the amount : ");
   scanf("%d",&withdraw_amt);
   if (withdraw_amt <= 0 )
   {
    printf("Invalid amount\n");
    withdraw_money();
   }
   
   amt -= withdraw_amt;
   printf("Money Withdrawn \n");
   printf("Current balance %d",amt);
    fprintf(ptr,"Rs %d has been withdrawn to your account \n",Deposit_amt);
     fprintf(ptr,"Date / time of transaction %s", ctime(&tm));
   getch();
 }

 void transfer_money()
{
    int ac;
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("TRANSFERRING MONEY\n");
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);
    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
   if (amt < trans_amt)
   {
    printf("You dont have sufficient balance");
   }
   else{
    amt -= trans_amt;
    printf("Money transfered sucessfully.");
    printf("Current balance : %d",amt);
    fprintf(ptr,"Rs %d has been transferred from your account to %d \n",trans_amt,ac);
   }
   fclose(ptr);
    printf("Press any key to continue....\n");
   getch();
}
void account_Detail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", account_no);
    printf("Total balance = %d\n ", amt);
    printf("Press any key.....");
    getch();
}

void transaction_details()
{
    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
      printf("No recent transactions\n");
    }
    else
    {
        printf("Transaction details\n");
        
        while (c != EOF) // EOF=End of file
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }

    getch();
}

void LastDetail()
{
    printf("Name : %s\n", name);
    printf("Account No. : %d\n", account_no);
    printf("Current balance = %d\n ", amt);

    printf("Press any key to exit.....");
    getch();
}