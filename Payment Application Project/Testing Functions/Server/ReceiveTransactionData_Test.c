#include <string.h>
#include "../../Server/Server.c"

int main(){


    ST_cardData_t cardData = {"Ahmed Ahmed Elshetyy" , "1234567890123456" , "11/21"};
    ST_terminalData_t  terminalData = { 8000.45 , 10000,"24/07/2022"};

    ST_transaction_t transaction={cardData, terminalData,APPROVED,0};

    EN_transState_t error = recieveTransactionData(&transaction);

    switch (error) {

        case DECLINED_INSUFFECIENT_FUND:
            printf("Low Balance");
            break;

        case DECLINED_STOLEN_CARD:
            printf("Stolen Card");
            break;

        case INTERNAL_SERVER_ERROR :
            printf("Transaction Couldn't be Saved ");
            break;

        case APPROVED:
            printf("Transaction is done successfully");
            break;

    }

    return 0;


}
