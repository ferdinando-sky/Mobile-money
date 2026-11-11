#include <stdio.h>
#define CHARGE 1000.0f
void checkBalance(float Balance);
float withdraw(float balance);

int main() {

// WITHDRAW OF MOBILE MONEY

int choice = 0;
float balance =70000.0f;

printf("***WELCOME TO AIRTEL MOBILE MONEY*** ");
do{
printf("\nSelect an option: \n");
printf("\n1. Check balance\n");
printf("\n2.Withdraw money\n");
printf("\n3.Exit\n");
printf("\nEnter your choice:");
scanf("%d", &choice);

switch(choice){
      case 1:
            checkBalance(balance);
            break;
      case 2:
            balance = withdraw(balance);
            break;
      case 3:
      printf("Thank you. Goodbye ! \n");
      break;
default:
      printf("Invalid option. Please choose 1,2 or 3. \n");
}
}while(choice!=3);

    return 0;
}

void checkBalance(float Balance){
     printf("Your balance is UGX %.0f\n", Balance);
}
float withdraw(float balance){
   float amount;
   printf("Enter amount to withdraw: ");
   scanf("%f", &amount);

if(amount<=0){
printf("Invalid amount. It must be greater than zero.\n");
} else if(balance<amount+CHARGE){
    printf("Insufficient funds. \n",amount + CHARGE, CHARGE);
}else{
      static int txnId =1000;
balance =balance-amount-CHARGE;
printf("Withdrawn: UGX %.0f\n",amount);
printf("New balance: UGX %.0f\n",balance);      
printf("Transaction Successful !\n");
printf("Transaction ID: TXN%d\n", ++txnId);
}

return balance;

}
