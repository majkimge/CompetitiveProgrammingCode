#include <bits/stdc++.h>
#define lld long long
#define llu unsigned long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define pii pair<lld,lld>

using namespace std;

lld n,kt=1,p,wynik;
lld tab[MAX];
pii tab1[MAX];
lld cok[MAX];
vector<pair<pii,lld> >v;
vector<pii> wys[MAX];
pii lin[MAX];
pii zw[MAX];
pii ost[MAX];
lld pod[MAX];
lld startod,podd;

lld wynod(lld dl, lld maxh){
    if(maxh==0||dl==0)return 0;
    lld od=(p+maxh-1)/maxh;
    if(od>dl)return 0;
    lld xh=ost[dl].f-ost[od-1].f-(dl-od+1)*lin[od-1].f;
    lld xd=ost[dl].s-ost[od-1].s-(dl-od+1)*lin[od-1].s;
    return xh*maxh-xd;
}

int main()
{
    scanf("%lld%lld",&n,&p);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        tab1[i]=mp(tab[i],i);
    }
    sort(tab1,tab1+n);
    for(int i=0;i<n;++i){
        lld tt=tab1[i].f;
        cok[kt]=tt;
        tab[tab1[i].s]=kt;
        while(i<n-1&&tab1[i+1].f==tt){
            ++i;
            tab[tab1[i].s]=kt;
        }
        ++kt;
    }
    /*for(int i=0;i<n;++i){
        cout<<tab[i]<<" ";
    }*/
    for(int i=0;i<=n;++i){
        /*if(!v.empty()&&v[v.size()-1].f.f<tab[i]){
            podd=v[v.size()-1].f.f;
        }else if(!v.empty()&&v[v.size()-1].f>tab[i]){
            pod[v[v.size()-1].f]=max(pod[v[v.size()-1].f],tab[i]);
        }*/
        lld pocz=i;
        if(!v.empty()&&tab[i]<v[v.size()-1].f.f){
            v[v.size()-1].s=max(v[v.size()-1].s,tab[i]);
        }
        while(!v.empty()&&tab[i]<v[v.size()-1].f.f){
            v[v.size()-1].s=max(v[v.size()-1].s,tab[i]);
            wys[v[v.size()-1].f.f].pb(mp(i-v[v.size()-1].f.s,v[v.size()-1].s));
            pocz=min(pocz,v[v.size()-1].f.s);
            v.pop_back();
        }
        podd=0;
        if(!v.empty()&&tab[i]>v[v.size()-1].f.f){
            podd=v[v.size()-1].f.f;
        }
        if(v.empty()||(!v.empty()&&tab[i]>v[v.size()-1].f.f)){
            v.pb(mp(mp(tab[i],pocz),podd));
        }
    }

    startod=(p+1000000000-1)/1000000000;
    for(int i=startod;i<=n;++i){
        zw[i].f=1;
        zw[i].s=((p+i-1)/i-1);
    }
    for(int i=startod;i<=n;++i){
        lin[i].f=lin[i-1].f+zw[i].f;
        lin[i].s=lin[i-1].s+zw[i].s;
    }
    for(int i=startod;i<=n;++i){
        ost[i].f=ost[i-1].f+lin[i].f;
        ost[i].s=ost[i-1].s+lin[i].s;
    }
    /*for(int i=1;i<=n;++i){
        cout<<ost[i].s<<" ";
    }
    cout<<endl;
    cout<<wynod(4,5)<<" ";*/
    for(int i=kt;i>0;--i){
        for(int j=0;j<wys[i].size();++j){
            //cout<<i<<" "<<wys[i][j].f<<" "<<wys[i][j].s<<"  X  ";
            wynik+=wynod(wys[i][j].f,cok[i])-wynod(wys[i][j].f,cok[wys[i][j].s]);//cout<<"C";
        }
        //cout<<endl;
    }
    printf("%lld",wynik);
    return 0;
}
