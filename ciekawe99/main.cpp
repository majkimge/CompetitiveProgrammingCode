#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 500009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

int n;
char s[MAX];
char s1[MAX];
lld poty[MAX];
lld hasze[MAX];
lld hasze1[MAX];
lld wyny[MAX];

lld por(lld gdzie,lld dl){
    if(gdzie+1==dl){
        return ((poty[gdzie+1]*hasze[gdzie])%MOD==(hasze[gdzie+dl]-hasze[gdzie]+MOD)%MOD);
    }else{
        return ((poty[gdzie+1]*(hasze[gdzie]-hasze[gdzie-dl]+MOD))%MOD==(poty[gdzie-dl]*(hasze[gdzie+dl]-hasze[gdzie]+MOD))%MOD);
    }
}

lld por1(lld gdzie,lld dl){
    if(gdzie+1==dl){
        return ((poty[gdzie+1]*hasze1[gdzie])%MOD==(hasze1[gdzie+dl]-hasze1[gdzie]+MOD)%MOD);
    }else{
        return ((poty[gdzie+1]*(hasze1[gdzie]-hasze1[gdzie-dl]+MOD))%MOD==(poty[gdzie-dl]*(hasze1[gdzie+dl]-hasze1[gdzie]+MOD))%MOD);
    }
}

int main()
{
    scanf("%s",s);
    while(s[n]){
        ++n;
    }
    poty[0]=1;
    for(int i=1;i<n;++i){
        poty[i]=(poty[i-1]*31)%MOD;
    }
    for(int i=0;i<n;++i){
        s1[i]=s[n-i-1];
    }
    hasze[0]=s[0]-'a'+1;
    hasze1[0]=s1[0]-'a'+1;
    for(int i=1;i<n;++i){
        hasze[i]=(hasze[i-1]+(s[i]-'a'+1)*poty[i])%MOD;
        hasze1[i]=(hasze1[i-1]+(s1[i]-'a'+1)*poty[i])%MOD;
    }
    char xd=s[0];
    int czy=1;
    for(int i=0;i<n;++i){
        if(s[i]!=xd){
            czy=0;
        }
    }
    if(czy){
        printf("%d\n1",n);
    }else{
        for(int i=2;i<n;i++){
            for(int j=i-1;j<n;j+=i){
                if(por(j,i)){
                    //cout<<j<<" "<<i<<endl;
                    wyny[j]=1;
                    czy=1;
                }
            }
        }
        for(int i=2;i<n;i++){
            for(int j=i-1;j<n;j+=i){
                if(por1(j,i)){

                    wyny[n-j-2]=1;
                    czy=1;
                }
            }
        }
        if(!czy){
            printf("1\n1");
        }else{
            int wynik=0;
            for(int i=0;i<n;++i){
                if(wyny[i]==0){
                    wynik++;
                }
            }
            printf("2\n%d",wynik);
        }
    }
    return 0;
}
