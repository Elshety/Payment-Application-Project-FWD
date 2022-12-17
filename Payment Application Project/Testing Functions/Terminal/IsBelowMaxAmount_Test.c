#include <stdio.h>
#include"../../Terminal/Terminal.c"


int main(){

    ST_terminalData_t  terminalData ;
    terminalData.transAmount = 12000; // let's check with 8000 and 12000

    setMaxAmount(&terminalData); //10000

    EN_terminalError_t Check = isBelowMaxAmount(&terminalData);

    if(Check == TERMINAL_OK){

        printf("The amount is valid ");
    }
    else
    printf("The amount is not valid");
    return 0;
}
