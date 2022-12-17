#include <string.h>
#include "../../Server/Server.c"


int main (){
    ST_accountsDB_t IndexAcc;
	ST_cardData_t cardData = {"Ahmed Ahmed Elshetyy" , "1234567890123456" , "11/23"};

	EN_serverError_t  Check = isValidAccount(&cardData,&IndexAcc);

	if(Check == SERVER_OK)
		puts("valid card");
	else
		puts("Account isn't in the database ");
}



