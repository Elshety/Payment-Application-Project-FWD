#include <stdio.h>
#include <string.h>
#include "Server.h"

ST_transaction_t TransactionsDataBase[DB_TRANSACTIONS_MAX] = {
		{{"AhmedAhmedAhmedElshetyyy" , "1234567890123456" , "11/22"},{3000 , 11000,"26/11/2022"},APPROVED, 0 }

};


ST_accountsDB_t AccountsDataBase[DB_ACCOUNTS_MAX] =
{
		{8000,RUNNING,"1234567890123456"},
		{41021.3,BLOCKED,"4567654643154321"},
		{5216.2,RUNNING, "4567654613454321"},
		{54625.1,RUNNING, "4567654642154321"},
		{35559.4,BLOCKED,"1234567840123456"},
		{41021.3,BLOCKED,"4567654643154321"},
		{5216.2,RUNNING, "4567654613664321"},
		{54625.1,RUNNING, "4567654642154321"},
		{35559.4,BLOCKED,"1234567890129456"},
		{41021.3,BLOCKED,"4567654643154321"},
		{5216.2,RUNNING, "4567654613454321"},
		{54625.1,RUNNING, "4567654642154321"},
		{54625.1,RUNNING, "4567654642154321"}

};

uint32_t transactionSequenceNo = 0;
uint32_t CurrentAccountDBIndex = 0 ;


EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence){

	uint16_t Counter;
	EN_serverError_t retval = SERVER_OK;

	for(Counter=0;Counter<=255;Counter++) {
		if ( (strcmp(AccountsDataBase[Counter].primaryAccountNumber, cardData->primaryAccountNumber)) == 0)
		{
			accountRefrence= AccountsDataBase;
			retval = SERVER_OK;
		}
		else {
			accountRefrence = NULL;
			retval = ACCOUNT_NOT_FOUND;
		}
		return retval;
	}
}


EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence){
	if(accountRefrence->state == RUNNING)
		return SERVER_OK;

	return BLOCKED_ACCOUNT;
}


EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence){

	if (termData->transAmount > accountRefrence->balance){
		return LOW_BALANCE;
	}
	else {
		return SERVER_OK;
	}
}


EN_serverError_t saveTransaction(ST_transaction_t *transData){


	if (transactionSequenceNo > DB_ACCOUNTS_MAX){
		return SAVING_FAILED;
		//		printf("Saving failed");
	}
	else {
		TransactionsDataBase[transactionSequenceNo].cardHolderData = transData->cardHolderData;
		TransactionsDataBase[transactionSequenceNo].terminalData = transData->terminalData;
		TransactionsDataBase[transactionSequenceNo].transState = transData->transState;
		TransactionsDataBase[transactionSequenceNo].transState = transData->transactionSequenceNumber;

		//		printf("Saving Ok");
		return SERVER_OK;
	}

}


EN_transState_t recieveTransactionData(ST_transaction_t *transData){
	EN_transState_t retval = APPROVED;


	if( isValidAccount( &(transData->cardHolderData), (ST_accountsDB_t *) &AccountsDataBase[CurrentAccountDBIndex] ) == ACCOUNT_NOT_FOUND )
	{
		retval = DECLINED_STOLEN_CARD;
		transData->transState = DECLINED_STOLEN_CARD;
	}
	else if( isAmountAvailable(&(transData->terminalData), (ST_accountsDB_t *)&AccountsDataBase[CurrentAccountDBIndex]) == LOW_BALANCE  )
	{
		retval = DECLINED_INSUFFECIENT_FUND;
		transData->transState = DECLINED_INSUFFECIENT_FUND;
	}
	else
	{
		if( saveTransaction(transData) == SAVING_FAILED )
		{
			retval = INTERNAL_SERVER_ERROR;
		}
		else
		{   // cut the transaction value from account balance
			printf("The Old balance is : %.2f\n",AccountsDataBase[CurrentAccountDBIndex].balance );
			AccountsDataBase[CurrentAccountDBIndex].balance -= transData->terminalData.transAmount;
			printf("The New balance is : %.2f\n",AccountsDataBase[CurrentAccountDBIndex].balance );

			transactionSequenceNo++;
			CurrentAccountDBIndex++;
			retval = APPROVED;

		}
	}

	return retval;
};


void listSavedTransactions(void)
{
	for(uint8_t i=0;i<=transactionSequenceNo;i++){
		printf("#########################\n\n\n");
		printf(" Transaction Sequence Number: %d\n", TransactionsDataBase[transactionSequenceNo].transactionSequenceNumber);
		printf(" Transaction Date: %s\n", TransactionsDataBase[transactionSequenceNo].terminalData.transactionDate);
		printf(" Transaction Amount: %f\n", TransactionsDataBase[transactionSequenceNo].terminalData.transAmount);
		printf(" Transaction State: %d\n", TransactionsDataBase[transactionSequenceNo].transState);
		printf(" Terminal Max Amount: %f\n", TransactionsDataBase[transactionSequenceNo].terminalData.maxTransAmount);
		printf(" Card holder Name: %s\n", TransactionsDataBase[transactionSequenceNo].cardHolderData.cardHolderName);
		printf(" PAN: %s\n", TransactionsDataBase[transactionSequenceNo].cardHolderData.primaryAccountNumber);
		printf(" Card Expiration Date: %s\n", TransactionsDataBase[transactionSequenceNo].cardHolderData.cardExpirationDate);
		printf("\n\n\n#########################");
	}
}







