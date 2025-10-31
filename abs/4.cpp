//https://atcoder.jp/contests/abs/tasks/abc081_b
#include <iostream>
using namespace std;
int main(void){
    int n, ai, min=1000;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ai;
        int j=0;
        for(;(ai&1)==0;j++){
            if(j>=min) break;
            ai=ai>>1;
        }
        min=(min>j)?j:min;
    }
    cout << min << endl;
    return 0;
}