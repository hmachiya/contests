//https://atcoder.jp/contests/abs/tasks/abc085_c
#include <iostream>
using namespace std;
#define NUM_KINDS 3
int g_price[NUM_KINDS] = {10000, 5000, 1000};
int g_total_price      = 0;
int g_total_number     = 0;

inline int min(int a, int b){
    return (a<b)?a:b;
}

int sum(int * a, int len){
    int s=0;
    for(int i=0;i<len;i++){
        s+=a[i];
    }
    return s;
}

int get_remaining_number(int *n){
    return g_total_number - sum(n, NUM_KINDS);
}

int get_remaining_price(int *n){
    int total_price=0;
    for(int i=0; i<NUM_KINDS;i++){
        total_price+=g_price[i]*n[i];
    }
    return g_total_price - total_price;
}
//recursive search, prioritize larger bills
int find(int * n, int offset){
    int r_num   = get_remaining_number(n);
    int r_price = get_remaining_price(n);
    //cerr << "DBG: " << n[0] << " " << n[1] << " " << n[2] << " " << r_num << " " << r_price << endl;
    if(offset==NUM_KINDS-1){
        if(r_num*g_price[offset]==r_price){
            n[offset]=r_num;
            return 0;
        }else{
            return -1;
        }
    }
    int imax    = min(r_num, r_price/g_price[offset]);
    for(int i=imax;i>=0;i--){
        n[offset]=i;
        int r_num_next   = r_num - i;
        int r_price_next = r_price - i * g_price[offset];
        if(r_num_next == 0 && r_price_next == 0) return  0;
        if(r_num_next == 0 && r_price_next >  0) return -1;
        if(r_num_next >  0){
            int rval = find(n, offset+1);
            if(rval==0) return 0;
        }
    }
    return -1;
}

int main(void){
    int n[NUM_KINDS] = {0,0,0};
    cin >> g_total_number >> g_total_price;
    int rval = find(n, 0);
    if(rval<0){
        cout << "-1 -1 -1" << endl;
    }else{
        for(int i=0;i<NUM_KINDS;i++){
            if(i>0) cout <<" ";
            cout << n[i];
        }
        cout << endl;
    }
    return 0;
}