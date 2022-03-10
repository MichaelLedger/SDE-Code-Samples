//
//  main.c
//  DNA-Edit-Distance-Calculator
//
//  Created by MTX on 2022/3/10.
//

#include <stdio.h>
#define M 4
#define N 6

//char A[M] = "CTGA";
//char B[N] = "ACGCTA";
char A[M];
char B[N];
int d[M+1][N+1]; // d[row][column]

int min(int a, int b) {
    return a < b ? a : b;
}

void print2DArr(int d[M+1][N+1]) {
    for (int i = 0; i < M+1; i++) {
        for (int j = 0; j < N+1; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int editdistance(char *str1, int len1, char *str2, int len2) {
    int i,j;
    // int diff;
    int temp;
    for(i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    print2DArr(d);
    for(j = 0; j <= len2; j++) {
        d[0][j] = j;
    }
    print2DArr(d);
    for(i = 1; i <= len1; i++) {
        for(j = 1; j<= len2; j++) {
            if(str1[i-1] == str2[j-1]) {
                d[i][j] = d[i-1][j-1];
                // print2DArr(d);
            }else{
                temp = min(d[i-1][j] + 1, d[i][j-1] + 1);
                d[i][j] = min(temp, d[i-1][j-1] + 1);
                // print2DArr(d);
            }
        }
    }
    print2DArr(d);
    return d[len1][len2];
}

int main(int argc, const char * argv[]) {
    printf("input char[%d]:", M);
    scanf("%s", A);//CTGA
    printf("input char[%d]:", N);
    scanf("%s", B);//ACGCTA
    int distance = editdistance(A, M, B, N);
    printf("distance:%d\n", distance);
    return 0;
}


/*
 input char[4]:CTGA
 input char[6]:ACGCTA
 0 0 0 0 0 0 0
 1 0 0 0 0 0 0
 2 0 0 0 0 0 0
 3 0 0 0 0 0 0
 4 0 0 0 0 0 0

 0 1 2 3 4 5 6
 1 0 0 0 0 0 0
 2 0 0 0 0 0 0
 3 0 0 0 0 0 0
 4 0 0 0 0 0 0

 0 1 2 3 4 5 6
 1 1 1 2 3 4 5
 2 2 2 2 3 3 4
 3 3 3 2 3 4 4
 4 3 4 3 3 4 4

 distance:4
 Program ended with exit code: 0
 */
