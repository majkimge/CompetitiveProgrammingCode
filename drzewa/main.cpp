#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 500009
#define INF 1000000009

using namespace std;

int n,a,b;
map<pair<int,int>,int>mapa;
map<pair<int,int>,int>odw;
priority_queue<pair<int,pair<int,int> > >kra;
vector<int> kraw[MAX];
int rep[MAX];
int wynik;
int bez[MAX];
int wiel[MAX];

int Find(int x){
    if(rep[x]==x) return x;
    rep[x]=Find(rep[x]);
    return rep[x];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        mapa[mp(a,b)]=1;
        mapa[mp(b,a)]=1;
        kraw[a].pb(b);
        kraw[b].pb(a);
        kra.push(mp(1,mp(a,b)));
        kra.push(mp(1,mp(b,a)));
    }
    for(int i=0;i<n-1;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        mapa[mp(a,b)]++;
        mapa[mp(b,a)]++;
        if(mapa[mp(b,a)]>=2){
            kra.push(mp(2,mp(b,a)));
            kra.push(mp(2,mp(a,b)));
        }
            kraw[a].pb(b);
            kraw[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        wiel[i]=kraw[i].size();
        rep[i]=i;
    }
    while(wynik<n-1){//cout<<"G";
        while(!kra.empty()&&(odw[kra.top().s]||bez[kra.top().s.f]||bez[kra.top().s.s])){
                odw[kra.top().s]=1;
        //cout<<"X";
            /*if(bez[kra.top().s.f]&&!bez[kra.top().s.s]){
                mapa[mp(Find(kra.top().s.f),kra.top().s.s)]++;
                mapa[mp(kra.top().s.s,Find(kra.top().s.f))]++;
                kra.push(mp(mapa[mp(Find(kra.top().s.f),kra.top().s.s)],mp(Find(kra.top().s.f),kra.top().s.s)));
                kra.push(mp(mapa[mp(kra.top().s.s,Find(kra.top().s.f))],mp(kra.top().s.s,Find(kra.top().s.f))));
            }else if(bez[kra.top().s.s]&&!bez[kra.top().s.f]){
                mapa[mp(Find(kra.top().s.s),kra.top().s.f)]++;
                mapa[mp(kra.top().s.f,Find(kra.top().s.s))]++;
                kra.push(mp(mapa[mp(Find(kra.top().s.s),kra.top().s.f)],mp(Find(kra.top().s.s),kra.top().s.f)));
                kra.push(mp(mapa[mp(kra.top().s.f,Find(kra.top().s.s))],mp(kra.top().s.f,Find(kra.top().s.s))));
            }*/

            kra.pop();

        }//cout<<kra.top().f<<" "<<kra.top().s.f<<" "<<kra.top().s.s<<endl;
        if(kra.empty()||kra.top().f<2) break;
        pair<int,int> temp=kra.top().s;
        kra.pop();
        temp.f=Find(temp.f);
        temp.s=Find(temp.s);
        odw[temp]=1;
        odw[mp(temp.s,temp.f)]=1;

        if(temp.f<=temp.s){
                //cout<<"WF";
            for(int i=0;i<kraw[temp.f].size();++i){
                if(kraw[temp.f][i]!=temp.s&&kraw[temp.f][i]!=temp.f&&!odw[mp(kraw[temp.f][i],temp.f)]){
                mapa[mp(temp.s,kraw[temp.f][i])]++;
               // cout<<"X"<<temp.s<<" "<<kraw[temp.f][i]<<endl;
        //system("pause");

                mapa[mp(kraw[temp.f][i],temp.s)]++;
                //odw[mp(kraw[temp.f][i],temp.f)];
                //odw[mp(temp.f,kraw[temp.f][i])];
                rep[temp.f]=temp.s;

                wiel[temp.s]+=wiel[temp.f];
                bez[temp.f]=1;
                if(mapa[mp(temp.s,kraw[temp.f][i])]<=2){
                        kraw[temp.s].pb(kraw[temp.f][i]);
                kraw[kraw[temp.f][i]].pb(temp.s);
                    kra.push(mp(mapa[mp(temp.s,kraw[temp.f][i])],mp(temp.s,kraw[temp.f][i])));
                    kra.push(mp(mapa[mp(kraw[temp.f][i],temp.s)],mp(kraw[temp.f][i],temp.s)));
                }

                }

            }
        }else{
            for(int i=0;i<kraw[temp.s].size();++i){
                if(kraw[temp.s][i]!=temp.f&&kraw[temp.s][i]!=temp.s&&!odw[mp(temp.s,kraw[temp.s][i])]){
                mapa[mp(temp.f,kraw[temp.s][i])]++;
                mapa[mp(kraw[temp.s][i],temp.f)]++;
                //cout<<"X"<<temp.f<<" "<<kraw[temp.s][i]<<endl;
                //odw[mp(temp.s,kraw[temp.s][i])]=1;
                //odw[mp(kraw[temp.s][i],temp.s)]=1;
                rep[temp.s]=temp.f;

                wiel[temp.f]+=wiel[temp.s];
                bez[temp.s]=1;
                if(mapa[mp(temp.f,kraw[temp.s][i])]<=2){
                kraw[temp.f].pb(kraw[temp.s][i]);
                kraw[kraw[temp.s][i]].pb(temp.f);
                    kra.push(mp(mapa[mp(temp.f,kraw[temp.s][i])],mp(temp.f,kraw[temp.s][i])));
                kra.push(mp(mapa[mp(kraw[temp.s][i],temp.f)],mp(kraw[temp.s][i],temp.f)));
                }

            }
            }
        }
        wynik++;
    }
    if(wynik==n-1){
        printf("TAK");
    }else{
        printf("NIE");
    }
    return 0;
}
