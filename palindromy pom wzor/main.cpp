#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

char s[MAX];
int ss[MAX];
int dody[MAX];
int n,a,b,start,t;

vector<int> kraw[MAX];
int odw[MAX];
int wag[MAX];
int sumik,kt=1,wyn=1;

int dfs(int from){
    odw[from]=kt;
    sumik+=wag[from];
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<kt){
            dfs(kraw[from][i]);
        }
    }
}

int main()
{
    scanf("%s",s);
    while(s[n])++n;
    for(int i=1;i<=n;++i){
        ss[i]=(int)s[i-1]-'a';
    }

    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        kraw[a].pb(b+1);
        kraw[b+1].pb(a);
    }
    //wag[0]=ss[0];
    for(int i=0;i<=n;++i){
        //kraw[i].pb(n-i);
        kraw[i].pb(n-i);
        wag[i]=ss[i+1]-ss[i];
    }
    for(int i=0;i<=n;++i){
        if(!odw[i])dfs(i);
        if((sumik%26)!=0)wyn=0;
    }
    if(wyn){
        printf("TAK");
    }else{
        printf("NIE");
    }
    return 0;
}
