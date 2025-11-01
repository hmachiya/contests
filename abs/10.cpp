//https://atcoder.jp/contests/abs/tasks/arc065_a
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> g_keywords = {"dream", "dreamer", "erase", "eraser"};
vector<string> g_lookahead_string;
vector<int> g_lookahead_offset;

void make_lookahead_cache(void){
    for(int i=0;i<(int)g_keywords.size();i++){
        for(int j=0;j<(int)g_keywords.size();j++){
            string keyword = g_keywords[i]+g_keywords[j];
            int offset     = g_keywords[i].length();
            g_lookahead_string.push_back(keyword);
            g_lookahead_offset.push_back(offset);
        }
    }
    for(int i=0;i<(int)g_keywords.size();i++){
        g_lookahead_string.push_back(g_keywords[i]);
        g_lookahead_offset.push_back(0);
    }
    return;
}

int contains_str_offset(string &s, int offset, string &token){
    for(int i=0;i<(int)token.length();i++){
        if(s[offset+i]!=token[i]) return 0;
    }
    return 1;
}

int find_match_length(string &s, int offset){
    for(int i=0;i<(int)g_lookahead_string.size();i++){
        if( !contains_str_offset(s,offset,g_lookahead_string[i]) ) continue;
        if( (g_lookahead_offset[i] > 0) ) return offset+g_lookahead_offset[i];
        if( ( g_lookahead_offset[i] == 0 ) ){
            if( ( s.length() - offset ) != g_lookahead_string[i].length() ) continue;
            return s.length();
        }
    }
    return -1;
}

int main(void){
    string s;
    cin >> s;
    make_lookahead_cache();
    int offset = 0;
    while(offset < (int)s.length()){
        offset=find_match_length(s,offset);
        if(offset<0) break;
    }
    if(offset<0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}