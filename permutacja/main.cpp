#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 500009
#define INF 1000000000
#define pb push_back
#define pii pair<int,int>

using namespace std;

int tab[MAX];
int n,k;
int jakdal[MAX];
int cogdz[MAX];
int odw[MAX];
queue<int> q;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
        cogdz[tab[i]]=i;
    }
    for(int i=1;i<=n;++i){
        q.push(i);
        odw[i]=1;
    }
    while(!q.empty()){
        int ter=q.front();
        int gdz=cogdz[ter];
        //cout<<ter<<" "<<gdz<<endl;
        odw[ter]=0;
        q.pop();
        if(ter!=n){
            if(gdz-cogdz[ter+1]>=k){
                swap(tab[gdz],tab[cogdz[ter+1]]);
                swap(cogdz[ter],cogdz[ter+1]);
                if(!odw[ter])q.push(ter);
                if(!odw[ter+1])q.push(ter+1);
                odw[ter]=1;
                odw[ter+1]=1;
                //cout<<"X";
                continue;
            }
        }
        if(ter!=1){
            if(-gdz+cogdz[ter-1]>=k){
                swap(tab[gdz],tab[cogdz[ter-1]]);
                swap(cogdz[ter],cogdz[ter-1]);
                if(!odw[ter])q.push(ter);
                if(!odw[ter-1])q.push(ter-1);
                odw[ter]=1;
                odw[ter-1]=1;
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<tab[i]<<" ";
    }
    return 0;
}
