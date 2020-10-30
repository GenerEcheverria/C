#include <stdio.h>
#define SIZE 4
 
void main (){
    int i, aux,  j, vector_num[SIZE];
 
    for(i=0;i<SIZE;i++){
            printf("\n\nIngresa el numero %d: \n\n", i+1);
            scanf("%d", &vector_num[i]);
    }
 
    for(i=0;i<SIZE;i++){
             for(j=0;j<SIZE-(i+1);j++){
                    if(vector_num[j]<vector_num[j+1]){
                        aux=vector_num[j];
                        vector_num[j]=vector_num[j+1];
                        vector_num[j+1]=aux;
                     }
              }
    }
    for(i=0;i<SIZE;i++){
          printf("%d", vector_num[i]);
    }
}
