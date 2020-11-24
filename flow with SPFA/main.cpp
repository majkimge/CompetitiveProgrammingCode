#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 6000009
#define INF 1000000000
#define pb push_back
#define piii pair<int,pair<int,int> >

using namespace std;

int n,k,ss,tt,wynik,sss,ttt,sumka;
int tab[3009][3009];
vector<piii> kraw[6000009];
int d[MAX];
int vis[MAX];
int from[MAX];
queue<int> q;

void SPFA(){

    while(!q.empty()){
        int ter=q.front();
        q.pop();
        vis[ter]=0;
        for(int i=0;i<kraw[ter].size();++i){

            if(kraw[ter][i].s.s){
                if(d[kraw[ter][i].f]>d[ter]+kraw[ter][i].s.f){
                    d[kraw[ter][i].f]=d[ter]+kraw[ter][i].s.f;
                    from[kraw[ter][i].f]=ter;           //Ustal sk¹d przychodzi
                    if(!vis[kraw[ter][i].f]){
                        q.push(kraw[ter][i].f);
                        vis[kraw[ter][i].f]=1;
                    }
                }
            }
        }
    }
}

void flow(){
    int czyk=1;
    while(czyk){
        for(int i=0;i<=(n+2)*(n+2);++i){
            d[i]=INF;
        }
        d[sss]=0;
        d[ss]=INF;
        d[tt]=INF;
        d[ttt]=INF;             //Przygotuj do puszczenia SPFA
        q.push(sss);
        SPFA();
        if(d[ttt]<INF){         //Jak dochodzisz do ujœcia aktualizuj
            wynik-=d[ttt];
            czyk=1;
        }else{
            break;
        }
        int gdz=ttt;
        int odd=ttt;
        while(true){                                //Zmieñ sieæ rezydualn¹
            for(int i=0;i<kraw[gdz].size();++i){
                if(kraw[gdz][i].f==from[gdz]&&gdz!=ttt&&gdz!=ss){
                    kraw[gdz][i].s.s++;
                }else if(kraw[gdz][i].f==odd){
                    kraw[gdz][i].s.s--;
                }
            }
            odd=gdz;
            if(gdz==sss)break;
            gdz=from[gdz];

        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
