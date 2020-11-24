#include <bits/stdc++.h>
#define MAX 100009
#define pb push_back

using namespace std;

int kraw[MAX];
int odl[MAX];
int ost[MAX];
int odw[MAX];
int odw1[MAX];

int temp,n,m,co,a,b,gd;

int dfs(int od){

    odw[od]=1;
    for(int i=0;i<kraw[od].size();++i){
        if(!odw[kraw[od][i]]){
            odl[od]=dfs(kraw[od][i])+1;
        }else{
            odl[od]=odl[kraw[od][i]]+1;
        }

    }
    return odl[od];
}

int dfs1(int od){

    odw1[od]=1;
    for(int i=0;i<kraw[od].size();++i){
        if(kraw[od][i]!=n+1){
            if(!odw1[kraw[od][i]]){
            ost[od]=dfs1(kraw[od][i]);
        }else{
            ost[od]=ost[kraw[od][i]];
        }
        }else{
            ost[od]=od;
            return od;
        }


    }
    return odl[od];
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&temp);
        if(i+temp<=n){
            kraw[i].pb(i+temp);
            odwrkraw[i+temp].pb(i);
        }else{
            kraw[i].pb(n+1);
            odwrkraw[n+1].pb(i);
        }

    }
    for(int i=1;i<=n;++i){

                    dfs(i);
                dfs1(i);


            }
            for(int i=1;i<=n;++i){
                odw[i]=0;
                odw1[i]=0;}


    for(int i=1;i<=m;++i){
        scanf("%lld",&co);
        if(co==0){
            scanf("%lld",&a);
            scanf("%lld",&b);
            kraw[a].clear();
            if(i+temp<=n){
            kraw[a].pb(a+b);
            odwrkraw[i+temp].pb(i);
        }else{
            kraw[a].pb(n+1);
            odwrkraw[n+1].pb(i);
        }
            for(int j=1;j<=n;++j){

                    dfs(j);
                dfs1(j);


            }
            for(int j=1;j<=n;++j){
                odw[j]=0;
                odw1[j]=0;}
        }else{
            scanf("%d",&a);
            printf("%d %d\n",ost[a],odl[a]);
        }
    }
    return 0;
}
