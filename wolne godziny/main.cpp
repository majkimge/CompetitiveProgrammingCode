#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 309

using namespace std;

pair<int,int> dp[MAX*MAX];
int n,m,k;
int sam[MAX],prac[MAX];
int sumsam,mnok,sumpra,wynik;



int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&sam[i]);
        sumsam+=sam[i];

    }



    for(int i=0;i<m;++i){
        scanf("%d",&prac[i]);
        //sumpra+=prac[i];
    }

    for(int i=0;i<n;++i){
        if(sam[i]<k){
            printf("Impossible");
            return 0;
        }
    }
    sort(prac,prac+m);
    mnok=n*k;
    dp[0].s=1;
    for(int i=0;i<m;++i){
        sumpra+=prac[i];
        for(int j=sumpra;j>=prac[i];--j){
            if(dp[j-prac[i]].s){
                dp[j].f=max(dp[j].f,dp[j-prac[i]].f+min(prac[i],n));
                dp[j].s=1;
            }
        }
    }
    for(int i=sumsam;i<=sumpra;++i){
        if(dp[i].f>=mnok){
            wynik=i;
            break;
        }
    }
    if(wynik){
        printf("%d",wynik-sumsam);
    }else{
        printf("Impossible");
    }
    return 0;
}
