/*
 * GetCardExpireDate_Test.c
 *
 *  Created on: 09/11/2022
 *  Author: Ahmed El-Shety
 */

void getCardExpiryDateTest ();
#include <stdio.h>
#include "../../Card/Card.c"

int main(){

    getCardExpiryDateTest();

}

void getCardExpiryDateTest ()
     {
         ST_cardData_t Customer1,Customer2 ;

         // Test case 1
         EN_cardError_t Check = getCardExpiryDate(&Customer1);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 1: \n");
     	 printf("Input Data: 11/22 \n");
         printf("Expected Result: 0 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         // Test case 2
     	 Check = getCardExpiryDate(&Customer2);
         printf("\n\n");
         printf("====================================");
         printf("\nTester Name: Ahmed Elshety \n");
     	 printf("Function Name: getCardExpiryDate\n");
     	 printf("Test Case 2: \n");
     	 printf("Input Data: 55555 \n");
         printf("Expected Result: 2 \n");
     	 printf("Actual Result: %d\n",Check);
     	 printf("====================================");
     	 printf("\n\n");

         }

