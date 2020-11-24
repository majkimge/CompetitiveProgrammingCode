#include "cho.h"
#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 109

using namespace std;

int w,w1,ite,n;
char s[101];
void flip(int gdz){
    if(s[gdz]=='0'){
        s[gdz]='1';
    }else{
        s[gdz]='0';
    }
}
/*int recytuj(const std::string& proba){
    return 0;
}*/

int main()
{
    n=100;
    for(int i=0;i<n;++i){
        s[i]='0';
    }
    w=recytuj(s);

    while(w&&ite<n){
        if(w==100){
            //return 0;
        }
        flip(ite);
        w1=recytuj(s);
        while(w1>=w){
            w=w1;
            flip(ite);
            w1=recytuj(s);
        }
        w=recytuj(s);
        ++ite;
    }
    for(int i=0;i<n;++i){
        flip(i);
    }
    recytuj(s);
    //for(int i=0;i<n;++i)cout<<s[i];
    return 0;
}
