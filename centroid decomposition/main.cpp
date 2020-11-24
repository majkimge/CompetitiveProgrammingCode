#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000000
#define pii pair<int,int>

using namespace std;

int n,a,b;
int odw[MAX];
int gl[MAX];
int uzy[MAX];
int wiel[MAX];
vector<int> kraw[MAX];

int dfswi(int gdz, int gleb){
    odw[gdz]=1;
    gl[gdz]=gleb;
    int wyn=1;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            wyn+=dfswi(kraw[gdz][i],gleb+1);
        }
    }
    wiel[gdz]=wyn;
    return wyn;
}

int dfscen(int gdz, int ww){
    odw[gdz]=1;
    int ret=gdz;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]&&wiel[kraw[gdz][i]]>ww/2){
            ret=dfscen(kraw[gdz][i],ww);
        }
    }
    return ret;
}

void clean(){
    for(int i=1;i<=n;++i){
        if(!uzy[i])odw[i]=0;
    }
}

void cd(int st, int wlk){
    dfswi(st,0);
    clean();
    int centr=dfscen(st,wlk);
    cout<<centr<<endl;
    uzy[centr]=1;
    clean();
    dfswi(centr,0);
    clean();
    for(int i=0;i<kraw[centr].size();++i){
        if(!odw[kraw[centr][i]]){
            cd(kraw[centr][i],wiel[kraw[centr][i]]);
        }
    }

}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    cd(n,n);
    return 0;
}
