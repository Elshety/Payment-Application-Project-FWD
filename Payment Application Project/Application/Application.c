#include <stdio.h>
#include <string.h>
#include "Application.h"

void main(void)
{
    puts("\n---------------Welcome---------------\n");
	appStart();
	puts("\n---------------Thanks---------------\n");
}

void appStart(void)
{

    // --------------------------Card----------------------------//
	ST_cardData_t cardData;
	if (getCardHolderName(&cardData) != CARD_OK) {
		puts("Holder name doesn't seem right!");
		return;
	}
	if (getCardExpiryDate(&cardData) != CARD_OK) {
		puts("Expiry date doesn't seem right!");
		return;
	}
	if (getCardPAN(&cardData) != CARD_OK) {
		puts("Primary account number doesn't seem right!");
		return;
	}

	puts("\nData received:");
	printf("Holder Name: %s\nExpiry date: %s\nPrimary Account Number: %s\n",
		cardData.cardHolderName,
		cardData.cardExpirationDate,
		cardData.primaryAccountNumber);


    // -----------------------Terminal----------------------------//

	ST_terminalData_t terminalData;
	if (getTransactionDate(&terminalData) != TERMINAL_OK) {
		puts("Transaction date doesn't seem right!");
		return;
	}

	printf("Transaction Date from system: %s\n\n", terminalData.transactionDate);

	if (isCardExpired(cardData, terminalData) != TERMINAL_OK) {
		puts("Card is Expired");
		return;
	}
	if (setMaxAmount(&terminalData) != TERMINAL_OK) {
		puts("Invalid Max Amount");
		return;
	}
  	if (getTransactionAmount(&terminalData) != TERMINAL_OK) {
 		puts("Invalid Amount");
 		return;
 	}
	if (isBelowMaxAmount(&terminalData) != TERMINAL_OK) {
		puts("Max Amount Exceeded");
		return;
	}



	// --------------------------Server----------------------------//
	ST_transaction_t transaction;
	transaction.cardHolderData = cardData;
	transaction.terminalData = terminalData;

	if(isValidAccount(&cardData,&AccountsDataBase) != SERVER_OK) {
        puts("The Account Not Valid");
		return;
	}


	if(isAmountAvailable(&terminalData,&AccountsDataBase) != SERVER_OK) {
        puts("No Balance Avilable");
		return;
	}

	if(isBlockedAccount(&AccountsDataBase) != SERVER_OK) {
        puts("The Card Is Stolen! Blocked ...");
		return;
	}

	if (recieveTransactionData(&transaction) == APPROVED) {
		printf("TRANSACTION APPROVED\n");
		printf("Updating Data Base Accounts ...\n");
		}
		else{
            printf("TRANSACTION FAILED\n");
	}


}
