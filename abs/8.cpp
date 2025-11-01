//https://atcoder.jp/contests/abs/tasks/abc085_b
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i=0;i<n;i++) cin >> d[i];
    sort(d.begin(), d.end());
    int counts=1;
    for(int i=1;i<n;i++){
        if(d[i-1]!=d[i]) counts++;
    }
    cout << counts << endl;
    return 0;
}