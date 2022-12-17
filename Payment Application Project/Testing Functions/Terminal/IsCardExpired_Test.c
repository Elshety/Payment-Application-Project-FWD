#include <stdio.h>
#include <time.h>
#include"../../Terminal/Terminal.c"
void IsCardExpiredTest ();
int main(){

    IsCardExpiredTest();
}

void IsCardExpiredTest ()
     {
         ST_cardData_t cardData1 = {"Any Holder Name","Any Primary Acc. ","08/22"}; // Expired date " 2 "
         ST_cardData_t cardData2 = {"Any Holder Name","Any Primary Acc. ","11/22"}; // Valid date " 0 "


         ST_terminalData_t  terminalData ;
         // Get the time from the system
         time_t now =time(NULL) ;
         struct  tm* Current_Time = localtime(&now);
         strftime(terminalData.transactionDate  , 11 , "%d/%m/%Y",Current_Time);
         /*-------------------------------------------------------------------*/

         // Test case 1
     	 EN_terminalError_t Check = isCardExpired(cardData2,terminalData);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 2: \n");
     	 printf("Input Data: 11/22 \n");
         printf("Expected Result: 0 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         // Test case 2
         Check = isCardExpired(cardData1,terminalData);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 1: \n");
     	 printf("Input Data: 08/22 \n");
         printf("Expected Result: 2 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");


     }
