//https://atcoder.jp/contests/abs/tasks/abc081_b
#include <stdio.h>
int main(void){
    int r, n, ai, min=1000;
    r=scanf("%d", &n);
    for(int i=0;i<n;i++){
        r=scanf("%d", &ai);
        int j=0;
        for(;(ai&1)==0;j++){
            if(j>=min) break;
            ai=(ai>>1);
        }
        min=(j<min)?j:min;
    }
    printf("%d\n",min);
    return 0;
}