#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000000000000000
using namespace std;

lld n,wyn,dl,itl;
lld czy[1000];
char s[200009];

int main()
{
    //czy['a']=1;
    //czy['e']=1;
    //czy['i']=1;
    //czy['o']=1;
    //czy['u']=1;
    //czy['y']=1;
    scanf("%s",s);
    while(s[n]){
        ++n;
    }
    //cout<<(int)'a';
    itl=-1;
    for(int i=0;i<n-2;++i){
        if(czy[s[i]]==czy[s[i+1]]&&czy[s[i]]==czy[s[i+2]]){
            wyn+=(i-itl)*(n-i-2);
            itl=i;

        }
    }
    cout<<s[0];
    printf("%lld",wyn);
    return 0;
}
