#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 1000009
#define f first
#define s second
#define INF 1000000000
#define MOD 1000000009
#define MOD1 1000000009

using namespace std;

int n,m,wyn,nast;
int tab[MAX];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=0;i<n;++i){
        if(tab[i]==2){
            ++i;
            m>>=1;
            nast=1;
        }else if(tab[i]==1){
            m>>=1;
            nast=0;
        }else{
            nast=0;
        }
        if(m==0&&nast){
            wyn=i;
        }else if(m==0){
            wyn=i+1;
        }
    }
    if(wyn){
        printf("%d",wyn);
    }else{
        printf("NIE");
    }

    return 0;
}
