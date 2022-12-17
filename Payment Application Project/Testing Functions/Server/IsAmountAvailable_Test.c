#include <string.h>
#include "../../Server/Server.c"

int main(){

     ST_accountsDB_t accountRefrence= {35559.4,BLOCKED,"4567654614254321"};

     ST_terminalData_t  terminalData = { 500 , 5000,"24/07/2022"};

     EN_terminalError_t Check = isAmountAvailable(&terminalData,&accountRefrence);

}
