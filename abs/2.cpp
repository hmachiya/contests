//https://atcoder.jp/contests/abs/tasks/abc086_a
#include <iostream>
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    if((a%2 + b%2)==2){
        cout << "Odd" << endl;
    }else{
        cout << "Even" << endl;
    }
    return 0;
}