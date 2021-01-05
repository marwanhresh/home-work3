#include <stdio.h>
#include "isort.h"

int main(){
  
 int array[LEN];
    for(int i=0; i<LEN; i++){
       scanf( "%d", (array+i));
    }
    
  
    insertion_sort(array,LEN);
    
    for(int i=0; i<LEN;i++){
       printf("%d,", *(array+i));
    }
    printf("\n");
    return 0;
}