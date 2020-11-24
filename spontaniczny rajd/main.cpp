#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009


using namespace std;

lld n,m,a,b,d,inf=(lld)1000000000000000;
vector<pair<pair<lld,lld>,lld> >kraw[MAX];
priority_queue<pair<lld,lld> > q;
vector<pair<lld,lld> >krawy[MAX];
lld odl[MAX];
lld odl1[MAX];
lld kf[MAX];
lld kf1[MAX];
lld ocz[MAX];
lld ocz1[MAX];
vector<lld> sciez;
vector<lld> wynik;
vector<pair<pair<lld,lld>,pair<lld,lld> > >v;
vector<lld> wyno;
vector<lld> kt;
vector<pair<lld,lld> >odki[MAX];
vector<pair<lld,lld> >odki1[MAX];
int odw[MAX];
int odw1[MAX];
int odw2[MAX];

void dijkstra(){
    while(!q.empty()){
        pair<lld,lld> temp=q.top();
        lld from=temp.s;
        lld od=-temp.f;
        q.pop();
        if(od==odl[from]){
            for(int i=0;i<kraw[from].size();++i){
                if(odl[kraw[from][i].f.s]>od+kraw[from][i].f.f){
                    odl[kraw[from][i].f.s]=od+kraw[from][i].f.f;
                    kf[kraw[from][i].f.s]=kraw[from][i].s;
                    ocz[kraw[from][i].f.s]=from;
                    q.push(mp(-odl[kraw[from][i].f.s],kraw[from][i].f.s));
                    odki[kraw[from][i].f.s].clear();
                    odki[kraw[from][i].f.s].pb(mp(from,kraw[from][i].s));
                }else if(odl[kraw[from][i].f.s]==od+kraw[from][i].f.f){
                    odki[kraw[from][i].f.s].pb(mp(from,kraw[from][i].s));
                }
            }
        }
    }
}

void dijkstra1(){
    while(!q.empty()){
        pair<lld,lld> temp=q.top();
        lld from=temp.s;
        //cout<<from;
        lld od=-temp.f;
        q.pop();
        if(od==odl1[from]){
            for(int i=0;i<kraw[from].size();++i){
                if(odl1[kraw[from][i].f.s]>od+kraw[from][i].f.f){
                    odl1[kraw[from][i].f.s]=od+kraw[from][i].f.f;
                    kf1[kraw[from][i].f.s]=kraw[from][i].s;
                    ocz1[kraw[from][i].f.s]=from;
                    q.push(mp(-odl1[kraw[from][i].f.s],kraw[from][i].f.s));
                    odki1[kraw[from][i].f.s].clear();
                    odki1[kraw[from][i].f.s].pb(mp(from,kraw[from][i].s));
                }else if(odl1[kraw[from][i].f.s]==od+kraw[from][i].f.f){
                    odki1[kraw[from][i].f.s].pb(mp(from,kraw[from][i].s));
                }
            }
        }
    }
}

void sdfs(int from){
    odw[from]=1;
    sciez.pb(from);
    for(int i=0;i<odki[from].size();++i){
        if(!odw[odki[from][i].f]){
            sdfs(odki[from][i].f);
        }
    }
}

void wdfs(int from){
    odw1[from]=1;
    //wynik.pb(from);
    for(int i=0;i<odki[from].size();++i){
        wynik.pb(odki[from][i].s);
        if(!odw1[odki[from][i].f]){
            wdfs(odki[from][i].f);
        }
    }
}

void wdfs1(int from){
    odw2[from]=1;
    //wynik.pb(from);
    for(int i=0;i<odki1[from].size();++i){
        wynik.pb(odki1[from][i].s);
        if(!odw2[odki1[from][i].f]){
            wdfs1(odki1[from][i].f);
        }
    }
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i =1;i<=m;++i){
        scanf("%lld%lld%lld",&a,&b,&d);
        kraw[a].pb(mp(mp(d,b),i));
        kraw[b].pb(mp(mp(d,a),i));
        krawy[i].pb(mp(a,b));
    }
    for(int i=1;i<=n;++i){
        odl[i]=inf;
    }
    odl[1]=0;
    q.push(mp((lld)0,(lld)1));
    dijkstra();

    for(int i=1;i<=n;++i){
        odl1[i]=inf;
    }
    odl1[n]=0;
    q.push(mp((lld)0,n));
    dijkstra1();
    for(int i=1;i<=n;++i){
        //cout<<odl1[i]<<" ";
    }
    lld gdz=n;
    sdfs(n);
    for(int i=0;i<sciez.size();++i){
        //cout<<sciez[i]<<" ";
    }
    for(int i=0;i<sciez.size();++i){
        for(int j=0;j<kraw[sciez[i]].size();++j){
            v.pb(mp(mp(odl[sciez[i]]+odl1[kraw[sciez[i]][j].f.s]+kraw[sciez[i]][j].f.f,kraw[sciez[i]][j].f.s),mp(kraw[sciez[i]][j].s,sciez[i])));
        }
    }

    sort(v.begin(),v.end());
    //int kt=0;
    int odleg=0;
    int czy=0;
    for(int i=0;i<v.size();++i){
        //cout<<"X"<<v[i].f.f<<"X";
        if(v[i].f.f>odl[n]){
            if(!czy){
                odleg=v[i].f.f;
                kt.pb(i);
                czy=1;
            }else{
                if(v[i].f.f==odleg){
                    kt.pb(i);
                }else{
                    break;
                }
            }
        }
    }

    for(int zz=0;zz<kt.size();++zz){
        pair<pair<lld,lld>,pair<lld,lld> >tt=v[kt[zz]];
        wynik.pb(tt.s.f);
        gdz=tt.s.s;
        /*while(gdz!=1){
            wynik.pb(kf[gdz]);
            gdz=ocz[gdz];
        }*/
        wdfs(gdz);
        gdz=tt.f.s;
        /*while(gdz!=n){//cout<<gdz;
            //system("pause");
            wynik.pb(kf1[gdz]);
            gdz=ocz1[gdz];
        }*/
        wdfs1(gdz);
    }

    sort(wynik.begin(),wynik.end());
    if(!wynik.empty())wyno.pb(wynik[0]);
    for(int i=1;i<wynik.size();++i){
        if(wynik[i]!=wynik[i-1]) wyno.pb(wynik[i]);
    }
    printf("%d\n",wyno.size());
    for(int i=0;i<wyno.size();++i){
        printf("%lld ",wyno[i]);
    }
    return 0;
}
