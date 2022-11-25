#include <stdio.h>
#include "my_mat.h"


void floydWarshall(int mat[V][V]){
    int a, b, minsum , sum;
    
    // for(i = 0 ; i < V ; i++){
    //     for(j = 0 ; j < V ; j++){
    //         dist[i][j] = mat[i][j];
    //     }
    // }

    for(int k = 0 ; k <= V ; k++){
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
                    minsum = 0;
                }
                mat[i][j] = minsum;
            }
        }
    }
    
}


void matrixInsert(int mat[V][V]){
    int num = 0;
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d" , &num);
            mat[i][j] = num;
        }
    }
    // printf("\n");
    // printf("\n");
    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         if (mat[i][j] == 0){
    //             printf(" %d", 0);
    //         }
    //         else{
    //             printf(" %d", mat[i][j]);
    //         }
    //     }
    //     printf("\n");
    // } 
    // printf("\n");
    // printf("\n");

    floydWarshall(mat);

    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         if (mat[i][j] == 0)
    //             printf(" %d", 0);
    //         else
    //             printf(" %7d", mat[i][j]);
    //     }
    //     printf("\n");
    // }
}


void isRoutable(int mat[V][V] , int i , int j){

    if(mat[i][j] == 0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}

void shortest(int mat[V][V] , int i , int j){
     if(mat[i][j] == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n" , mat[i][j]);
    }
}


