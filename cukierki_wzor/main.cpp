#include <bits/stdc++.h>
#define pb push_back
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 2000000
#define piii pair<lld,pair<lld,lld> >
#define INF 2000000000

using namespace std;

lld a,d,b,n,h,kk=1,wynik;
int ilep;
lld tab[30];

map<lld,int> mm;

vector<pair<lld,int> >skal;
pair<pair<lld,lld>,pair<lld,int > >points[1200000];

lld tree[4200000];

void zm(lld gdz,lld na){
    gdz+=kk;
    tree[gdz]=max(na,tree[gdz]);
    gdz>>=1;
    while(gdz){
        tree[gdz]=max(tree[gdz*2],tree[gdz*2+1]);
        gdz>>=1;
    }
}

lld podaj(int l, int p){
    l+=kk;
    p+=kk;
    lld wyn=-INF;
    wyn=max(tree[l],tree[p]);

    while(l/2!=p/2){
        if(l%2==0){
            wyn=max(wyn,tree[l+1]);
        }
        if(p%2==1){
            wyn=max(wyn,tree[p-1]);
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

void rob(int kt, int dl, lld aa, lld dd, lld bb){
    if(kt==dl-1){

        if(dl==h){
            points[ilep]=(mp(mp(aa+tab[kt]-dd,1),mp(dd-bb,0)));
            skal.pb(mp(dd-bb,ilep));
            ++ilep;
            points[ilep]=(mp(mp(aa-tab[kt]-dd,1),mp(dd+tab[kt]-bb,0)));
            skal.pb(mp(dd+tab[kt]-bb,ilep));
            ++ilep;
            points[ilep]=(mp(mp(aa-dd,1),mp(dd-tab[kt]-bb,0)));
            skal.pb(mp(dd-tab[kt]-bb,ilep));
            ++ilep;
        }else{

            points[ilep]=(mp(mp(-aa-tab[kt]+dd,0),mp(-dd+bb,0)));
            skal.pb(mp(-dd+bb,ilep));
            ++ilep;
            points[ilep]=(mp(mp(-aa+tab[kt]+dd,0),mp(-dd-tab[kt]+bb,0)));
            skal.pb(mp(-dd-tab[kt]+bb,ilep));
            ++ilep;
            points[ilep]=(mp(mp(-aa+dd,0),mp(-dd+tab[kt]+bb,0)));
            skal.pb(mp(-dd+tab[kt]+bb,ilep));
            ++ilep;
        }
    }else{
        rob(kt+1,dl,aa+tab[kt],dd,bb);
        rob(kt+1,dl,aa,dd+tab[kt],bb);
        rob(kt+1,dl,aa,dd,bb+tab[kt]);
    }
}


int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    h=n/2;
    rob(0,h,0,0,0);
    rob(h,n,0,0,0);
    sort(skal.begin(),skal.end());
    lld kt=0;
    for(int i=0;i<skal.size();++i){
        //mm[skal[i]]=kt;
        points[skal[i].s].s.s=kt;
        while(i+1<skal.size()&&skal[i].f==skal[i+1].f){
            ++i;
            points[skal[i].s].s.s=kt;
        }
        kt++;
    }
    while(kk<kt)kk<<=1;


    sort(points,points+ilep);
    for(int i=0;i<4200000;++i){
        tree[i]=(lld)-24000000000;
    }
    //cout<<mm[-9];
    wynik=(lld)INF*100;
    for(int i=0;i<ilep;++i){
        if(points[i].f.s==0){

            zm(points[i].s.s,points[i].s.f+points[i].f.f);
        }else{
            //cout<<mm[points[i].s]<<" "<<podaj(0,mm[points[i].s])<<endl;
            lld last=wynik;
            wynik=min(wynik,points[i].s.f+points[i].f.f-podaj(0,points[i].s.s));
            if(wynik<0)wynik=last;
        }
    }
    printf("%lld",wynik);
    return 0;
}
