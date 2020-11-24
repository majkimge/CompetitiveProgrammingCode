#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1009

using namespace std;

int dp[MAX];
int pref1[MAX];
int pref2[MAX];
int tab1[MAX];
int tab2[MAX];
int t,n,m,wynik,maxin;
int gdzpref2[MAX];

int main()
{
    scanf("%d",&t);
    scanf("%d",&n);
    srand(time(0));
    for(int i=1;i<=n;++i){
        scanf("%d",&tab1[i]);
        //tab1[i]=rand()%12+1;
    }

    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d",&tab2[i]);
        //tab2[i]=rand()%12+1;
    }
    for(int i=1;i<=n;++i){
        pref1[i]=pref1[i-1]+tab1[i];
    }

    for(int i=1;i<=m;++i){
        pref2[i]=pref2[i-1]+tab2[i];
    }
    pref2[m+1]=MAX-1;
    for(int i=1;i<=m;++i){
        for(int j=pref2[i];j<min(t+1,pref2[i+1]);++j){
            gdzpref2[j]=i;
        }
    }
    dp[0]=1;
    for(int i=0;i<=n;++i){
        for(int j=t;j>=tab1[i];--j){
            dp[j]=(dp[j-tab1[i]]|dp[j]);
            if(dp[j])maxin=max(maxin,j);
        }
        if(pref1[i]-maxin<=t){
            wynik=max(wynik,i+gdzpref2[(t-(pref1[i]-maxin))]);
        }
    }
    printf("%d",wynik);
    return 0;
}
