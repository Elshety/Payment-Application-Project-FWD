#include <stdio.h>
#include"../../Terminal/Terminal.c"

int main(){

    ST_terminalData_t  terminalData ;

    getTransactionDate(&terminalData);

    printf("%s", terminalData.transactionDate);
}
