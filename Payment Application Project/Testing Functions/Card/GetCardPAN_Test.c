/*
 * GetCardPAN_Test.c
 *
 *  Created on: 09/11/2022
 *  Author: Ahmed El-Shety
 */

#include <stdio.h>
#include "../../Card/Card.c"
void getCardPANTest ();

int main(){

    getCardPANTest();
}


void getCardPANTest ()
     {
         ST_cardData_t Customer1,Customer2,Customer3 ;

         // Test case 1
         EN_cardError_t Check = getCardPAN(&Customer1);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 1: \n");
     	 printf("Input Data: 1234567890123456 \n");
         printf("Expected Result: 0 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         // Test case 2
     	 Check = getCardPAN(&Customer2);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 2: \n");
     	 printf("Input Data: 1234567890 \n");
         printf("Expected Result: 3 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         // Test case 3
         Check = getCardPAN(&Customer3);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 3: \n");
     	 printf("Input Data: 123456789012345678901234567890 \n");
         printf("Expected Result: 3 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");
     }
