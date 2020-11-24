#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

int wyny[2][MAX],n,wynik;
char s[MAX];
lld hasze[MAX];
vector<int> pocz[MAX];
vector<int> pref[MAX];

int lcs()
{
    int wyn=0;
    for (int i=1; i<=n+1; ++i){
        for (int j=i+1; j<=n+1; ++j){
            if (s[i-1] == s[j-1] &&wyny[0][j-1] < (j - i)){
                wyny[1][j] = wyny[0][j-1] + 1;
                wyn=max(wyn,wyny[1][j]);
            }
            else{
                wyny[1][j] = 0;
            }

        }
        for (int j=i+1; j<=n+1; ++j){
            wyny[0][j]=wyny[1][j];

        }
    }
    return wyn;
}

lld pot(int co,int dok){
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        temp%=MOD;
        return (temp*temp)%MOD;
    }else if(dok==1){
        return co;
    }else{
        lld temp=pot(co,dok-1);
        temp%=MOD;
        return (temp*co)%MOD;
    }

}

int main()
{
    scanf("%s",&s[1]);
    n=1;
    while(s[n]!=0){
        n++;
    }
    n--;
    wynik=lcs();
    hasze[1]=(s[1]-'a'+1)*31;
    for(int i=2;i<=n;++i){
        hasze[i]=(hasze[i-1]+(pot(31,i)*(s[i]-'a'+1)))%MOD;
        //cout<<hasze[i]<<" ";
    }
    //cout<<(((hasze[10]-hasze[7]+MOD)%MOD))%MOD;
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            if((((hasze[i]-hasze[j]+MOD)%MOD)*pot(31,(i-j)))%MOD==(((hasze[i+i-j]-hasze[i]+MOD)%MOD))%MOD){
                pref[i].pb(i-j);
                //cout<<i;
                pocz[j+1].pb(i-j);
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<pref[i].size();++j){
            for(int z=0;z<pocz[i+pref[i][j]+1].size();++z){
                wynik=max(wynik,pref[i][j]+pocz[i+pref[i][j]+1][z]);
            }
        }
    }
    printf("%d",wynik);
    return 0;
}
