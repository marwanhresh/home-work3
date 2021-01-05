#include <stdio.h>
#include "isort.h"


 void shift_element(int* arr, int i){
  int k=i;
  while(i>0){
    *(arr+k)=*(arr+k-1);
      k--;
      i--;
  }
 
 }
  
 void insertion_sort(int *arr, int len){
 	
 	for(int i=0; i<len; i++){
 	    int n=0;
 	    for(int j=i; j<len; j++){
 	    n++;
 	   
 	    if(*(arr+i)>*(arr+j)){
 		int temp=*(arr+j);
 		 shift_element((arr+i),n-1);
 		*(arr+i)=temp;
 	 }
   }
  }
 }


 