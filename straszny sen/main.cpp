#include <bits/stdc++.h>
#define lld long long
#define f first
#define mp make_pair
#define s second
#define pb push_back
#define MAX 200009
#define INF 1000000009

using namespace std;

int n,s,m,t,a,b,wynik=INF,num;
vector<int> kraw[MAX];
int odw[MAX];
int nasc[MAX];
int gleb[MAX];
int gleb1[MAX];
vector<pair<int,int> > dop;

void dfsgl(int from,int gl){
    odw[from]=num;
    gleb[from]=gl;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<num){
            dfsgl(kraw[from][i],gl+1);
        }

    }
}

void dfsgl1(int from,int gl){
    odw[from]=num;
    gleb1[from]=gl;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<num){
            dfsgl1(kraw[from][i],gl+1);
        }

    }
}

int dfssc(int from,int co){
    odw[from]=num;
    if(from==co)return 1;
    int ret=0;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<num){
            ret|=dfssc(kraw[from][i],co);
        }

    }
    if(ret)nasc[from]=1;
    return ret;
}

int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        wynik=INF;
        num=1;
        scanf("%d%d%d",&n,&s,&m);
        for(int i=0;i<n-1;++i){
            scanf("%d%d",&a,&b);
            kraw[a].pb(b);
            kraw[b].pb(a);
        }
        dfsgl(m,0);
        ++num;
        dfsgl1(s,0);
        ++num;
        dfssc(s,m);
        int maxi=0;
        for(int i=0;i<=n;++i){
            maxi=max(maxi,gleb[i]*(!nasc[i]));
        }
        printf("%d\n",gleb[s]+maxi);



        for(int i=0;i<=n;++i){
            kraw[i].clear();
            nasc[i]=0;
            odw[i]=0;
            gleb[i]=0;
        }
        num=1;
    }
    return 0;
}
