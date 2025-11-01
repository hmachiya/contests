//https://atcoder.jp/contests/abs/tasks/arc089_a
#include <iostream>
#include <vector>
using namespace std;
inline int abs(int x){
    return (x<0)?-x:x;
}
int main(void){
    int n, x0=0, y0=0, t0=0, dx, dy, dt, success=1;
    cin >> n;
    vector<int> ts(n), xs(n), ys(n);
    for(int i=0;i<n;i++) cin >> ts[i] >> xs[i] >> ys[i];
    for(int i=0;i<n;i++){
        dx=abs(xs[i]-x0); dy=abs(ys[i]-y0); dt=ts[i]-t0;
        if( (dt-dx-dy < 0) || ( ( (dt-dx-dy)%2 ) == 1 ) ){
            success=0;
            break;
        }
        x0=xs[i]; y0=ys[i]; t0=ts[i];
    }
    if(success)  cout << "Yes" << endl;
    else         cout << "No"  << endl;
    return 0;
}