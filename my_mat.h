#ifndef _MY_MAT_H_
 #define _MY_MAT_H_

#define V 10

void matrixInsert(int mat[V][V]);

void isRoutable(int mat[V][V] , int i , int j);

void shortest(int mat[V][V] , int i , int j);

void floydWarshall(int mat[V][V]);

 #endif