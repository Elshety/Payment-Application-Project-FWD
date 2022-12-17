#include <string.h>
#include "../../Server/Server.c"

int main(){

    ST_cardData_t cardData = {"Ahmed Ahmed Elshety" , "4117394584032555" , "11/23"};
    ST_terminalData_t  terminalData = { 900 , 5800,"12/09/2022"};
    ST_transaction_t transaction={cardData, terminalData,APPROVED,0};

    saveTransaction(&transaction);


    printf("\n\n");
    printf("--------- The transactions ------------\n");
    printf("%s\n" , transaction.cardHolderData.cardHolderName);
    printf("%s\n" , transaction.cardHolderData.primaryAccountNumber);
    printf("%s\n" , transaction.cardHolderData.cardExpirationDate);
    printf("%d\n" , transaction.transactionSequenceNumber);
}
