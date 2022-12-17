#include <string.h>
#include "../../Server/Server.c"

int main (){

	ST_accountsDB_t accountRefrence = {35559.4,BLOCKED,"4567654614254321"}; // RUNNING - BLOCKED

	EN_accountState_t  Check = isBlockedAccount(&accountRefrence);

	if(Check == RUNNING)
		puts("The account is Running");
	else
		puts("The account is Blocked");

		return 0;
}
