#include <stdio.h>
#include"../../Terminal/Terminal.c"

int main(){

    ST_terminalData_t  terminalData ;
    EN_terminalError_t  Check = getTransactionAmount(&terminalData);

    if(Check != TERMINAL_OK){
        printf("The amount is not correct");
        return ;
    }
    else
    printf("The amount is correct");
}
