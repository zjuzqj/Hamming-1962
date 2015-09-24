//
//  main.c
//  NALab1
//
//  Created by mszqj on 15/9/15.
//  Copyright (c) 2015年 mszqj. All rights reserved.
//

#include <stdio.h>

void Series_Sum( double sum[] );

int main(int argc, const char * argv[]) {
    int i;
    double x, sum[3001];
    
    Series_Sum( sum );
    
    x = 0.0;
    for (i=0; i<3001; i++)
        printf("%6.2lf %16.12lf\n", x + (double)i * 0.10, sum[i]);

    return 0;
}

void Series_Sum( double sum[] ){
    double dX = 0.000;
    double dSum = 0.000;
    double tailSum = 0.000;
    double diff;
    double m;
    int i,j, k;
    int iter;
    
    for( j = 2000000; j > 100000; j--){
        tailSum += 1.0 /((double)(j)*(double)(j+1)*(double)(j));
    }
    
    for( i = 0; i < 10; i++){
        dX = 0.1 *(double)(i);
        dSum = tailSum;
        for(j = 100000; j > 0 ; j--){
            dSum += 1.0 /((double)(j)*(double)(j+1)*(double)(j+dX));
        }
        dSum *= (1-dX);
        sum[i] = dSum + 1;
    }
    
    for( i = 10; i < 3001; i++){
        diff = 0.0;
        dX = 0.1 * (double)(i);
        j = i % 10;
        k = i / 10;
        m = 0.1 * (double)(j);
        
        if(j != 0){
            for(iter = 1; iter <= k; iter ++){
                diff += 1.0 /((double)(iter) + m);
            }
        
            sum[i] = (sum[j]*m + diff)/dX;
            /*if(sum[i] < 0){
                printf("i = %d, j = %d, k = %d, m =%f, diff = %f\n",i,j,k,m,diff);
            }*/
        }
        else{
            for(iter = 1; iter <= k ; iter++){
                diff += 1/(double)(iter);
            }
            sum[i] = diff/k;
        }
    }
    
    return;
}