#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 3009

#define lld long long

using namespace std;

lld n,lud[MAX],sejf[MAX],ilema[MAX],iletrzeba[MAX],ilechce[MAX],wynik,INF=10000000000000009;
pair<lld,lld> dp[MAX][2];

int main()
{
    scanf("%lld",&n);
    for(lld i=1;i<=n;++i){
        scanf("%lld",&lud[i]);
        lud[i+n]=lud[i+2*n]=lud[i];
    }
    for(lld i=1;i<=n;++i){
        scanf("%lld",&sejf[i]);
        sejf[i+n]=sejf[i+2*n]=sejf[i];
    }
    //printf("-1");
    //return 0;
    //oster=lud[1];
    //oster-=max(0,sejf[1]-lud[2]);
    //zost=max(0,lud[2]-sejf[1]);
    wynik=n;
    for(lld i=1;i<n;++i){
        ilema[i+1]+=min(sejf[i],lud[i+1]);
        ilema[i]+=sejf[i]-ilema[i+1];
    }

    lld dod=min(sejf[n],lud[1]-ilema[1]);
    ilema[1]+=dod;
    ilema[n]+=sejf[n]-dod;
    lld nad=max((lld)0,ilema[1]-lud[1]);
    ilema[1]-=nad;
    ilema[n]+=nad;//cout<<ilema[3];
    for(lld i=n;i>1;--i){
        nad=ilema[i]-lud[i];
        ilema[i-1]+=min(nad,sejf[i-1]);
    }
    for(lld i=1;i<=n;++i){
            //cout<<ilema[i]<<" ";
        if(ilema[i]<lud[i]){
            //czy=0;
            printf("-1");
            return 0;
        }
    }
    lld wynik=n;
    for(lld i=1;i<=n;++i){
        ilechce[n+i]=lud[n+i];
        lld przyps=0;
        for(lld j=n+i-1;j>i;--j){
            iletrzeba[j]=ilechce[j+1];
            if(sejf[j]<iletrzeba[j])przyps=1;
            //cout<<j<<" "<<iletrzeba[j]<<" < ";
            ilechce[j]=max((lld)0,lud[j]-max((lld)0,(sejf[j]-iletrzeba[j])));
        }
        if(przyps)continue;
        //cout<<endl;

        dp[i+1][1].f=1;
        dp[i+1][1].s=sejf[i+1]-lud[i+1];
        if(lud[i+1]){
            dp[i+1][0]=mp(MAX,-INF);
        }else{
            dp[i+1][0]=mp(0,0);
        }


        if(dp[i+1][1].s<iletrzeba[i+1])continue;
       // cout<<dp[i+1][1].s;
        for(lld j=i+2;j<n+i;++j){
            dp[j][1]=mp(MAX,-INF);
            dp[j][0]=mp(MAX,-INF);
            if(dp[j-1][0].s>=0&&sejf[j]-lud[j]>=iletrzeba[j]){
                pair<lld,lld> temp=mp(dp[j-1][0].f+1,sejf[j]-lud[j]);
                if(temp.f<dp[j][1].f||(temp.f==dp[j][1].f&&temp.s>dp[j][1].f))dp[j][1]=temp;
            }
            if(dp[j-1][0].s>=0&&lud[j]==0&&iletrzeba[j]==0){
                pair<lld,lld> temp=mp(dp[j-1][0].f,0);
                if(temp.f<dp[j][0].f||(temp.f==dp[j][0].f&&temp.s>dp[j][0].f))dp[j][0]=temp;
            }
            if(dp[j-1][1].s>=0&&sejf[j]+min((lld)0,(-lud[j]+dp[j-1][1].s))>=iletrzeba[j]){
                pair<lld,lld> temp=mp(dp[j-1][1].f+1,sejf[j]+min((lld)0,(-lud[j]+dp[j-1][1].s)));
                //cout<<lud[j];
                if(temp.f<dp[j][1].f||(temp.f==dp[j][1].f&&temp.s>dp[j][1].f))dp[j][1]=temp;

            }
            if(dp[j-1][1].s>=0&&(-lud[j]+dp[j-1][1].s)>=iletrzeba[j]&&iletrzeba[j]==0){
                pair<lld,lld> temp=mp(dp[j-1][1].f,0);
                if(temp.f<dp[j][0].f||(temp.f==dp[j][0].f&&temp.s>dp[j][0].f))dp[j][0]=temp;

            }
           // cout<<j<<" "<<dp[j][0].s<<" "<<dp[j][1].s<<" X ";
            lld il=0;
            if(dp[j][1].f>=MAX){
                dp[j][1].s=-INF;
            }
            if(dp[j][0].f>=MAX){
                dp[j][0].s=-INF;
            }
            if(dp[j][1].f>=MAX&&dp[j][0].f>=MAX){
                 przyps=1;
                break;
            }
        }
        if(przyps)continue;
        wynik=min(wynik,min(dp[n+i-1][0].f,dp[n+i-1][1].f));
        //cout<<endl<<i<<" "<<wynik<<endl;
    }
    printf("%lld",wynik);
    return 0;
}
