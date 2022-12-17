#include <stdio.h>
#include <string.h>
#include "Card.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData){

    printf("Please enter the card name: ");
    gets(cardData->cardHolderName);
    uint32_t i = strlen(cardData->cardHolderName);

    if(i > 24 ||  i < 20  ){
        return WRONG_NAME;
    }

    return CARD_OK;

}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){

    printf("Please enter the expire date as MM/YY : ");
    gets(cardData->cardExpirationDate);
    uint32_t i = strlen(cardData->cardExpirationDate);

    if( i != 5 || cardData->cardExpirationDate[2] != '/' ){
        return WRONG_EXP_DATE;
    }

    return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){

    printf("Please enter the card PAN: ");
    gets(cardData ->primaryAccountNumber);
    uint32_t i = strlen(cardData ->primaryAccountNumber);

    if( i > 19 ||  i < 16   ){
        return WRONG_PAN;
    }

    return CARD_OK ;
}
