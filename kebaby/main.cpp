#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 100009

using namespace std;

int n,k,wynik,a,b,c,sr1,sr2;
vector<int> dia;
int odw[MAX],ondia[MAX];
int gl[MAX];
int maxgl[MAX];
vector<pair<int,int> >kraw[MAX];

void dfs(int from, int gleb){
    gl[from]=gleb;
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]){
            dfs(kraw[from][i].f,gleb+kraw[from][i].s);
        }
    }
}

int dfs1(int from){
    odw[from]=1;
    int ret=0;
    if(from==sr2)ret=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]){
            ret=max(ret,dfs1(kraw[from][i].f));
        }
    }
    if(ret){
        dia.pb(from);
        ondia[from]=dia.size();
    }
    return ret;
}
int dfs2(int from){
    odw[from]=1;
    int ret=0;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]&&!ondia[kraw[from][i].f]){
            ret=max(ret,dfs1(kraw[from][i].f)+kraw[from][i].s);
        }
    }
    maxgl[from]=ret;
    return ret;
}

void clearodw(){
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
}

int check(int dok){

    int maxol=maxgl[dia[0]];
    int czyk=0;
    int ret=0;
    int l1=0;
    int p1=dia.size()-1;
    int dl=0;
    int dp=0;
    for(int i=0;i<dia.size();++i){
        if(maxgl[dia[i]]>dok)return MAX;
    }
    //cout<<"X";
    int nast=0;
    while(l1<dia.size()-1){
        dl=max(maxgl[dia[l1]],dl);
        for(int j=0;j<kraw[dia[l1]].size();++j){
            if(kraw[dia[l1]][j].f==dia[l1+1]){
                nast=kraw[dia[l1]][j].s;
            }
        }
        //if(dok==2)cout<<l1;
        dl+=nast;
        if(dl<=dok){
            ++l1;
        }else{
            break;
        }
    }
    //l1++;

    while(p1>0){
        dp=max(maxgl[dia[p1]],dp);
        for(int j=0;j<kraw[dia[p1]].size();++j){
            if(kraw[dia[p1]][j].f==dia[p1-1]){
                nast=kraw[dia[p1]][j].s;
            }
        }
        dp+=nast;//cout<<"S";
        if(dp<=dok){
            --p1;
        }else{
            break;
        }
    }
    //p1--;
    //if(dok==2)cout<<p1;
    return max(1,p1-l1+1);
}

int bin(){
    int l=0;
    int p=1000000009;
    int s=0;
    int ret=p;
    while(l<=p){
        s=(l+p)/2;
        if(check(s)<=k){
            ret=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;++i){
        scanf("%d%d%d",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
    }
    dfs(1,0);
    int maxi=0;
    sr1=1;
    for(int i=1;i<=n;++i){
        if(gl[i]>maxi){
            maxi=gl[i];
            sr1=i;
        }
    }
    for(int i=1;i<=n;++i){
        gl[i]=0;
    }
    clearodw();
    dfs(sr1,0);
    sr2=sr1;
    maxi=0;
    for(int i=1;i<=n;++i){
        if(gl[i]>maxi){
            maxi=gl[i];
            sr2=i;
        }
    }
    clearodw();
    dfs1(sr1);
    clearodw();
    for(int i=0;i<dia.size();++i){
        dfs2(dia[i]);
    }
    printf("%d",bin());
    return 0;
}


