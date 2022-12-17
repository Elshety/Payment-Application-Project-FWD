#include <stdio.h>
#include <time.h>
#include "Terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){

    // Getting the time from system
    time_t now =time(NULL) ;

    struct  tm* Current_Time = localtime(&now);

    strftime(termData->transactionDate  , 11 , "%d/%m/%Y",Current_Time);


return CARD_OK;


}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData){

    // Convert the date into a numeric values MM/YY

    uint8_t Card_Month = (cardData.cardExpirationDate[0] - '0') * 10 + (cardData.cardExpirationDate[1] - '0');
    uint8_t Current_Month = (termData.transactionDate[3] - '0') * 10 + (termData.transactionDate[4] - '0');

    uint8_t Card_Year = (cardData.cardExpirationDate[3] - '0') * 10 + (cardData.cardExpirationDate[4] - '0');
    uint8_t Current_Year = (termData.transactionDate[8] - '0') * 10 + (termData.transactionDate[9] - '0');

    if (Current_Year > Card_Year)
    {
        return EXPIRED_CARD;
    }
    else if (Current_Year == Card_Year && Current_Month > Card_Month)
    {
        return EXPIRED_CARD;
    }

    return TERMINAL_OK;

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){

    printf("Kindly Enter The Amount you want: ");

    scanf("%f",&termData->transAmount);

    if (termData->transAmount <= 0)
    {
        return INVALID_AMOUNT;
    }
    return TERMINAL_OK;

}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){

    termData->maxTransAmount = 10000;

    return TERMINAL_OK;

}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){

    if (termData->transAmount > termData->maxTransAmount)
    {
        return EXCEED_MAX_AMOUNT;
    }
    return TERMINAL_OK;

}
