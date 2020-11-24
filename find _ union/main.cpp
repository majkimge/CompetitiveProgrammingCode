#include <bits/stdc++.h>

#define lld long long
#define L 100000
using namespace std;

int n;
int czy;
int tab[L][2];
int ilepol=0;
int ilezap=0;
int zap[L];
int grupy[L];
int rangi[L];
int parent[L];
int ileel[L];
int ileilo[L];

int Find(int x){

    if(parent[x]!=x){
        parent[x]=Find(parent[x]);
    }
    return parent[x];

}
void Union(int x, int y){
    int a=Find(x);
    int b=Find(y);
    if(a!=b){
        if(rangi[a]<rangi[b]){
            parent[a]=b;
            ileilo[ileel[a]+ileel[b]]++;
            ileilo[ileel[b]]--;
            ileilo[ileel[a]]--;
            ileel[b]+=ileel[a];
            ileel[a]=-1;

        }else if(rangi[b]<rangi[a]){
            parent[b]=a;
            ileilo[ileel[a]+ileel[b]]++;
            ileilo[ileel[a]]--;
            ileilo[ileel[b]]--;
            ileel[a]+=ileel[b];
            ileel[b]=-1;

        }else{
            parent[b]=a;
            ileilo[ileel[a]+ileel[b]]++;
            ileilo[ileel[a]]--;
            ileilo[ileel[b]]--;
            rangi[a]=rangi[a]+1;
            ileel[a]+=ileel[b];
            ileel[b]=-1;
        }
    }
}
int main()
{
    //std::ios_base::sync_with_stdio(0);
    for(int i=0;i<L;i++){
        grupy[i]=i;
        parent[i]=i;
        ileel[i]=1;
    }
    ileilo[1]=L;
    scanf("%i",&n);
    for(int i=0;i<n;++i){
        scanf("%i",&czy);
        if(czy==0){
            scanf("%i",&tab[ilepol][0]);
            scanf("%i",&tab[ilepol][1]);
            Union(tab[ilepol][0]-1,tab[ilepol][1]-1);
            ilepol++;
        }else{
            scanf("%i",&zap[ilezap]);
            printf("%i\n",ileilo[zap[ilezap]]);
            ilezap++;
        }
    }
    //cout<<ileel[1];
    return 0;
}
