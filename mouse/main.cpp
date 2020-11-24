#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define INF 1000000009

using namespace std;

int n,co,wyn,wynix,kt=1,xd;
int tab[MAX];
int wyny[MAX];
int odw[MAX];
vector<int>kraw[MAX];

int dfs(int from){
    if(odw[from]==0){
        odw[from]=kt;
    //wynix=min(wynix,tab[from]);

    if(odw[kraw[from][0]]){
        wyny[from]=min(tab[kraw[from][0]],tab[from]);
        return wyny[from];
    }else{
        wyny[from]=min(dfs(kraw[from][0]),tab[from]);
        return wyny[from];
    }
    }


}
int dfs2(int from){
    if(odw[from]==0){
            //cout<<"C";
        odw[from]=kt;
    //wynix=min(wynix,tab[from]);

    if(odw[kraw[from][0]]){
        wyny[from]=min(wyny[kraw[from][0]],tab[from]);
        //if(from==4) cout<<wyny[3];
        return min(wyny[kraw[from][0]],tab[from]);
    }else{
        wyny[from]=min(dfs2(kraw[from][0]),tab[from]);
        wyny[from]=min(wyny[from],wyny[kraw[from][0]]);

        return wyny[from];
    }
    }


}
void dfs1(int from){
    if(odw[from]==0){


    odw[from]=kt;
    //wynix=min(wynix,tab[from]);

    if(odw[kraw[from][0]]>0&&odw[kraw[from][0]]<kt){

    }else if(odw[kraw[from][0]]==kt){

        //cout<<from;
        wyn+=wyny[from];

    }else{
        dfs1(kraw[from][0]);

    }
}
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&co);
        kraw[i].pb(co);
    }
    for(int i=1;i<=n;++i){
        wynix=INF;
        dfs(i);
        kt++;
        //cout<<wyny[i]<<" ";

    }
    //cout<<endl;
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    for(int i=1;i<=n;++i){
        wynix=INF;
        dfs2(i);
        kt++;
        //cout<<wyny[i]<<" ";
    }

    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    for(int i=1;i<=n;++i){
        wynix=INF;
        dfs1(i);
        kt++;

    }
    printf("%d",wyn);
    return 0;
}
