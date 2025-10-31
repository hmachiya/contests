//https://atcoder.jp/contests/abs/tasks/abc081_a
#include <iostream>
using namespace std;
int main(void){
    char s[4];
    cin >> s;
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=s[i]-'0';
    }
    cout << sum << endl;
    return 0;
}