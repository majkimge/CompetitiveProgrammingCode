#include <bits/stdc++.h>

#define lld long long
#define N 100002
#define MLD 100000000000
using namespace std;

int n;
int m;
vector<int> kraw[N];
queue <int> kol;
int odw[N];
int gleb[N];
int odl[N];
int stop[N];
int krawz1[N];
int jednostop=0;
int wynik=0;
int odwiedzone=0;
int w,w1;
int temp,temp1,tem,tem1,temp2,temp3;
//make_pair(<int>,<int>);
void bfs(){
    while(!kol.empty()){
        int x=kol.front();
        kol.pop();
odwiedzone++;
        //stop[x]=kraw[x].size();
        if(stop[x]==1){
            krawz1[kraw[x][0]]=1;
        }
        for(int i=0;i<kraw[x].size();i++){
            if(odl[x]+1<odl[kraw[x][i]]){
                odl[kraw[x][i]]=odl[x]+1;
                kol.push(kraw[x][i]);
            }
        }
    }
}
int main()
{
    scanf("%i",&n);
    scanf("%i",&m);
    for(int i=0;i<=n;i++){
        odl[i]=MLD;
    }
    for(int i=0;i<m;i++){
        scanf("%i",&w);
        scanf("%i",&w1);
        kraw[w].push_back(w1);
        kraw[w1].push_back(w);
    }
    odl[1]=0;
    kol.push(1);
}
