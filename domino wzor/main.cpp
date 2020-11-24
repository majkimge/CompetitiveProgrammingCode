#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 16009
#define INF 1000000000
#define pb push_back
#define pii pair<int,int>

using namespace std;

int n,k,ss=0,tt=MAX-1,iled,ilep=1,wynik;
unsigned int sumix;
int tab[2009][2009];
vector<pii> kraw[MAX];
pair<int,pair<pii,pii> > domin[8000009];
int xory[2009][2009];
int odw[2009][2009];
int nump[2009][2009];
pii from[MAX];
int odl[MAX];
int vis[MAX];
deque<int> q;

void zerod(){
    for(int i=0;i<MAX;++i){
        odl[i]=INF;
    }
}

void SPFA(){
    while(!q.empty()){
        int ter=q.front();
        int wart=odl[ter];
        vis[ter]=0;
        q.pop_front();
        //cout<<ter<<" "<<wart<<endl;
        for(int i=0;i<kraw[ter].size();++i){
            if(odl[kraw[ter][i].s]>wart+kraw[ter][i].f){

                odl[kraw[ter][i].s]=wart+kraw[ter][i].f;
                /*if(ter==4){
                    cout<<kraw[ter][i].s<<" "<<odl[kraw[ter][i].s]<<endl;

                }*/
                from[kraw[ter][i].s]=mp(ter,i);
                if(!vis[kraw[ter][i].s]){
                    if(q.empty()||kraw[ter][i].s<q.front()){
                        q.push_front(kraw[ter][i].s);
                    }else{
                        q.push_back(kraw[ter][i].s);
                    }

                    vis[kraw[ter][i].s]=1;
                }
            }
        }
    }
    wynik+=odl[tt];
    //cout<<odl[tt];
    int temp=tt;
    while(temp!=ss){
            //cout<<temp<<" ";
        int ff=from[temp].f;
        kraw[temp].pb(mp(-kraw[ff][from[temp].s].f,ff));
        swap(kraw[ff][from[temp].s],kraw[ff][kraw[ff].size()-1]);
        kraw[ff].pop_back();
        temp=ff;
    }
    //cout<<endl;
}


int main()
{
    scanf("%d%d",&n,&k);
    srand(time(0));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&tab[i][j]);
            //tab[i][j]=rand()%1000;
            sumix+=(unsigned int)tab[i][j];
            tab[i][j]=-tab[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=1;j<n;++j){
            domin[iled]=mp(tab[i][j]+tab[i][j-1],mp(mp(i,j-1),mp(i,j)));
            iled++;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=1;j<n;++j){
            domin[iled]=mp(tab[j][i]+tab[j-1][i],mp(mp(j-1,i),mp(j,i)));
            iled++;
        }
    }
    sort(domin,domin+iled);
    for(int i=1;i<n;++i){
        xory[0][i]=1^xory[0][i-1];
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<n;++j){
            xory[i][j]=xory[i-1][j]^1;
        }
    }
    for(int i=0;i<min(iled,k*7+1);++i){
            //cout<<domin[i].f<<endl;
            if(xory[domin[i].s.f.f][domin[i].s.f.s])swap(domin[i].s.f,domin[i].s.s);
        if(!xory[domin[i].s.f.f][domin[i].s.f.s]){
            if(!odw[domin[i].s.f.f][domin[i].s.f.s]){
                odw[domin[i].s.f.f][domin[i].s.f.s]=1;
                //if(!tab[domin[i].s.f.f][domin[i].s.f.s])cout<<domin[i].s.f.f<<domin[i].s.f.s<<endl;
                kraw[ss].pb(mp(tab[domin[i].s.f.f][domin[i].s.f.s],ilep));
                nump[domin[i].s.f.f][domin[i].s.f.s]=ilep;
                ++ilep;
            }
            if(!odw[domin[i].s.s.f][domin[i].s.s.s]){
                odw[domin[i].s.s.f][domin[i].s.s.s]=1;
                kraw[ilep].pb(mp(0,tt));
                nump[domin[i].s.s.f][domin[i].s.s.s]=ilep;
                ++ilep;

            }
            kraw[nump[domin[i].s.f.f][domin[i].s.f.s]].pb(mp(tab[domin[i].s.s.f][domin[i].s.s.s],nump[domin[i].s.s.f][domin[i].s.s.s]));
        }
    }
    //cout<<tt;

    for(int i=0;i<k;++i){
        zerod();
        odl[ss]=0;
        q.push_front(ss);
        SPFA();
    }
    //cout<<wynik<<endl;
    printf("%u",(unsigned int)sumix+wynik);
    return 0;
}
/*
3 3
10 9 0
9 -10 0
-10 5 5
*/
