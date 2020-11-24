#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009
#define MOD 1000000009

using namespace std;

int n,dl,wynik=1;
map<int,int> m;
char temp[MAX];
int poty[MAX];
int main()
{
    scanf("%d",&n);
    vector<char> slow[n+1];

    vector<int> hasze[n+1];
    //cout<<"G";
    vector<int> prefy[n+1];
    for(int i=0;i<=n;++i){
        slow[i].clear();
        hasze[i].clear();
        prefy[i].clear();
    }
    for(int i=0;i<MAX;++i){
        temp[i]=0;
        poty[i]=0;
    }
    for(int i=0;i<n;++i){
        scanf("%s",temp);
        dl=0;
        while(temp[dl]){
            dl++;
        }
        slow[i].pb(0);
        for(int j=0;j<dl;++j){
            slow[i].pb(temp[j]);
        }
    }
    poty[0]=1;
//cout<<"G";
    lld tempor=0;
    for(int i=1;i<MAX;++i){
        lld ttt=(lld)poty[i-1];
        tempor=(lld)((ttt*31ll)%MOD);
        //cout<<tempor;
        poty[i]=(int)tempor;
        poty[i]%=MOD;

    }
    //cout<<poty[100];
    for(int i=0;i<n;++i){
        hasze[i].pb(0);
        for(int j=1;j<slow[i].size();++j){
            lld tt1=(lld)hasze[i][j-1];
            lld tt2 = (lld)poty[j];
            lld tt3=(lld)slow[i][j];
            //cout<<"Z"<<tt3;
            lld tempor=(lld)(tt1+tt2*(tt3-64ll))%MOD;
            //cout<<"X"<<tempor;
            tempor%=MOD;
            hasze[i].pb((int)tempor);
        }
    }
    for(int i=0;i<n;++i){
        int prd=0;
        prefy[i].pb(0);
        prefy[i].pb(0);
        //prefy[i].pb(1);
        for(int j=2;j<slow[i].size();++j){
            while(prd!=0&&slow[i][j]!=slow[i][prd+1]) prd=prefy[i][prd];
            if(slow[i][j]==slow[i][prd+1]){
                prefy[i].pb(prd+1);
                prd++;
            }else{
                prefy[i].pb(0);
            }
        }
    }

    int tempix=prefy[n-1][prefy[n-1].size()-1];
    //cout<<hasze[3][5]<<"Y";
    m[hasze[n-1][hasze[n-1].size()-1]]=1;
    while(tempix!=0){
        m[hasze[n-1][tempix]]=1;
        tempix=prefy[n-1][tempix];
    }

    for(int i=n-2;i>=0;--i){
        int tempixik=prefy[i][prefy[i].size()-1];
        //cout<<"X"<<tempixik<<" ";
        int tewar=m[hasze[i][hasze[i].size()-1]];
        m[hasze[i][hasze[i].size()-1]]=max(tewar+1,m[hasze[i][hasze[i].size()-1]]);
        wynik=max(wynik,tewar+1);

        while(tempixik!=0){
            m[hasze[i][tempixik]]=max(tewar+1,m[hasze[i][tempixik]]);
            tempixik=prefy[i][tempixik];
        }
    }
    printf("%d",wynik);
    return 0;
}

/*
5
AB
ABAB
ABCAB
ABCABABCAB
ABCABABCAB
A
A
*/
