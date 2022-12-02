#include <stdio.h>
#include "my_mat.h"


void floydWarshall(int mat[V][V]){ // algorithm for shortest way
    int a, b, minsum , sum;

    for(int k = 0 ; k < V ; k++){
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                a = mat[i][k];
                b = mat[k][j];
                sum = a+b;
                if(a == 0 || b == 0){
                    sum = 0;
                }
                if( mat[i][j] == 0){
                    minsum = sum;
                }
                else if( sum == 0){
                        minsum = mat[i][j];
                }
                else if( mat[i][j] < sum){
                        minsum = mat[i][j];
                }
                else{
                    minsum = sum;
                }
                if(i == j){ 
                    minsum = mat[j];
                }
                mat[i][j] = minsum;
            }
        }
    }
    
}


void matrixInsert(int mat[V][V]){ //insert the numbers to the matrix
    int num = 0;
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d" , &num);
            mat[i][j] = num;
        }
    }
    floydWarshall(mat); 
}


void isRoutable(int mat[V][V] , int i , int j){ // checks if there is a way from A to B
    if(mat[i][j] == 0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}

void shortest(int mat[V][V] , int i , int j){ // checks the shortest way from A to B depends on the algorithm
     if(mat[i][j] == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n" , mat[i][j]);
    }
}