#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 3000009

using namespace std;

int n;
int tab[20];
int wyn;
char s[11];
int rob(int nn, int pocz, int kon){
    if(nn==1){
        return 1;
    }
    int czy=1;
    for(int i=pocz+1;i<=kon;++i){
        if(tab[i]<tab[i-1])czy=0;
    }
    if(czy)return n;
    return max(rob(nn/2,pocz,(pocz+kon)/2),rob(nn/2,(pocz+kon)/2+1,kon));
}


int main()
{
    scanf("%s",s);
    int sum=0;
    int czy;
    for(int i=0;i<11;++i){
        if(!s[i])break;
        sum+=s[i]-'A'+1;
    }

    cout<<sum;
    return 0;
}
