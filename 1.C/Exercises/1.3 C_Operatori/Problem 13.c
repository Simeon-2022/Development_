#include <stdio.h>
int main() {
 int iCounter = 5;
 while( ++ iCounter < 10 ) {
 printf("Counter %d\n", iCounter);
 printf("++ Counter: %d\n", ++ iCounter);
 printf("-- Counter: %d\n", -- iCounter);
 printf("Counter ++: %d\n", iCounter ++);
 printf("Counter --: %d\n", iCounter --);
 }
 return 0;
}
