#include <stdio.h>
#include <strings.h>
typedef struct {
    char name[50];
    double balance;
    char number[15];
    char pin[10];
}Accounts;
int main(){
    Accounts account[10];
    int choice,n=0,accnum,m,PIN=1;
    char pin[10];
    double deposit,withdraw;
    while(1){
        printf("\n\nPress:\n1 ==> AddAccount.\n2 ==> AccountDetails\n3 ==> Deposit\n4 ==> Withdraw\n");
        scanf("%d",&choice);
        getchar();
        if(choice==1){
            account[n]=(Accounts){"",0,""};
            printf("Enter the account name: \n");
            fgets(account[n].name,50,stdin);
            account[n].name[strlen(account[n].name)-1]='\0';
            printf("Enter in your balance;:\n");
            scanf("%lf",&account[n].balance);
            getchar();
            printf("Enter in your contact details:\n");
            fgets(account[n].number,15,stdin);
            account[n].number[strlen(account[n].number)-1]='\0';
            printf("Set a pin:\n");
            fgets(account[n].pin,10,stdin);
            account[n].pin[strlen(account[n].pin)-1]='\0';
            printf("Your account number is %d\n",n+29180);
            n++;
        }
        else if(choice==2){
            while(PIN){ 
                printf("Please enter account number:\n");
                scanf("%d",&accnum);
                m=accnum-29180;
                getchar();
                printf("Enter in your pin:\n");
                fgets(pin,10,stdin);
                pin[strlen(pin)-1]='\0';
                if(pin[0]=='\0'){
                    PIN=0;
                }
                if(strcmp(pin,account[m].pin)==0){
                    printf("Account name: %s\n",account[m].name);
                    printf("Account balance: %.2lf\n",account[m].balance);
                    printf("Account contact: %s\n",account[m].number);
                    PIN=0;
                }
                else{
                    printf("INVALID PIN OR ACCOUNT NUMBER!!TRY AGAIN\n\n");
                }
            }
            PIN=1;
        }
        else if (choice==3){
            printf("Please enter in the account number:\n");
            scanf("%d",&accnum);
            m=accnum-29180;
            printf("Enter the amount to deposit:\n");
            scanf("%lf",&deposit);
            account[m].balance+=deposit;
        }
        else if(choice==4){
            while(PIN){
                printf("Please enter account number:\n");
                scanf("%d",&accnum);
                m=accnum-29180;
                getchar();
                printf("Enter in your pin:\n");
                fgets(pin,10,stdin);
                pin[strlen(pin)-1]='\0';
                if(pin[0]=='\0'){
                    PIN=0;
                }
                if(strcmp(pin,account[m].pin)==0){
                    printf("Enter the amount to withdraw:\n");
                    scanf("%lf",&withdraw);
                    if(withdraw<=account[m].balance)
                    account[m].balance-=withdraw;  
                    else
                    printf("Insufficient Balance!!");
                    PIN=0;
                }
                else{
                    printf("INVALID PIN OR ACCOUNT NUMBER!!TRY AGAIN\n\n");
                }
            }
            PIN=1;
        }
        else{
            break;
        }

    }
    return 0;
}