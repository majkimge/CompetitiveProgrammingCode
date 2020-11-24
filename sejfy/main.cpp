#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 3009
#define INF 1000000009

using namespace std;

int n,czy=1,pier,pier1,ost,ost1,oster,zost,it,wynik,czy1,czy2;
int lud[MAX];
int sejf[MAX];
int ilema[MAX];
pair<int,int> dp[MAX][MAX][2];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&lud[i]);
        lud[i+n]=lud[i+2*n]=lud[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&sejf[i]);
        sejf[i+n]=sejf[i+2*n]=sejf[i];
    }
    //oster=lud[1];
    //oster-=max(0,sejf[1]-lud[2]);
    //zost=max(0,lud[2]-sejf[1]);
    wynik=n;
    for(int i=1;i<n;++i){
        ilema[i+1]+=min(sejf[i],lud[i+1]);
        ilema[i]+=sejf[i]-ilema[i+1];
    }

    int dod=min(sejf[n],lud[1]-ilema[1]);
    ilema[1]+=dod;
    ilema[n]+=sejf[n]-dod;
    int nad=max(0,ilema[1]-lud[1]);
    ilema[1]-=nad;
    ilema[n]+=nad;//cout<<ilema[3];
    for(int i=n;i>1;--i){
        nad=ilema[i]-lud[i];
        ilema[i-1]+=min(nad,sejf[i-1]);
    }
    for(int i=1;i<=n;++i){
            //cout<<ilema[i]<<" ";
        if(ilema[i]<lud[i]){
            czy=0;
            printf("-1");
            break;
        }
    }
    if(czy){
        for(int i=1;i<=n;++i){

        }
    }
    return 0;
}
