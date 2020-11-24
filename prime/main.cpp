#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 5000009
#define f first
#define s second
#define INF 1000000000
#define MOD 1000000009
#define MOD1 1000000009

using namespace std;

int main()
{
    for(int i=1000006966;i>=1000000000;--i){
        int czy=1;
        for(int j=2;j*j<=i;++j){
            if(i%j==0) czy=0;
        }
        if(czy){
            cout<<i;
            break;
        }
    }
    return 0;
}
