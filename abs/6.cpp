#include <iostream>
using namespace std;
int sum_digits(int x){
    int sum=0;
    for(;x>0;x=x/10) sum+=(x%10);
    return sum;
}
int main(void){
    int a, b, n, result=0;
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++){
        int sum=sum_digits(i);
        if((a<=sum) && (sum<=b)) result+=i;
    }
    cout << result << endl;
    return 0;
}