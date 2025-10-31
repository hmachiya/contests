//https://atcoder.jp/contests/abs/tasks/abc087_b
#include <iostream>
using namespace std;
inline int min(int a, int b){
    return (a<b)?a:b;
}
int main(void){
    int a,b,c,x,remaining,counts=0;
    cin >> a >> b >> c >> x;
    int imax=min(a, x/500);
    for(int i=0;i<=imax;i++){
        remaining=x-i*500;
        if(remaining==0){counts++; continue;}
        int jmax=min(b, remaining/100);
        for(int j=0;j<=jmax;j++){
            remaining=x-i*500-j*100;
            if( ( (remaining%50) == 0 ) && ( (remaining / 50) <= c ) ) counts++;
        }
    }
    cout << counts <<endl;
    return 0;
}