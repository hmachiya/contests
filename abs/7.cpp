//https://atcoder.jp/contests/abs/tasks/abc088_b
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> ai(n);
    for(int i=0;i<n;i++){
        cin >> ai[i];
    }
    sort(ai.rbegin(), ai.rend());
    int alice=0, bob=0;
    for(int i=0;i<n;i++){
        if((i%2)==0) alice+=ai[i];
        else bob+=ai[i];
    }
    cout << (alice - bob) << endl;
    return 0;    
}