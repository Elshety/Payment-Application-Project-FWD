/*
 * GetCardHolderName_Test.c
 *
 *  Created on: 09/11/2022
 *  Author: Ahmed El-Shety
 */

#include <stdio.h>
#include <string.h>
#include "../../Card/Card.c"
void getCardHolderNameTest ();

int main(){

    getCardHolderNameTest();

}

void getCardHolderNameTest ()
     {
         ST_cardData_t Customer1,Customer2,Customer3 ;

         // Test case 1
         EN_cardError_t Check = getCardHolderName(&Customer1);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardHolderName\n");
     	 printf("Test Case 1: \n");
     	 printf("Input Data: AhmedAhmedAhmedElshetyy \n");
         printf("Expected Result: 0 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         // Test case 2
     	 Check = getCardHolderName(&Customer2);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardHolderName\n");
     	 printf("Test Case 2: \n");
     	 printf("Input Data: 1234567890 \n");
         printf("Expected Result: 1 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         // Test case 3
         Check = getCardHolderName(&Customer3);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardHolderName\n");
     	 printf("Test Case 3: \n");
     	 printf("Input Data: 1234567890123456789012345678901234567890 \n");
         printf("Expected Result: 1 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");
     }
