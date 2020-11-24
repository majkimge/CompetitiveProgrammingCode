#include <bits/stdc++.h>
#define lld long long
#define MAX 2009
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

vector<pair<pair<lld,lld>,pair<lld,lld> > > troj;
pair<pair<lld,lld>,pair<lld,lld> > troj1[MAX];

lld n,x,y,m,tem,suma;

void check(pair<pair<lld,lld>,pair<lld,lld> > przed, pair<pair<lld,lld>,pair<lld,lld> > po){

    if(po.f.f<=przed.f.f+przed.s.f&&po.f.s<=przed.f.s+przed.s.f-(po.f.f-przed.f.f)&&po.f.s+po.s.f>=przed.f.s){
        //cout<<przed.f.f<<" "<<po.f.f<<" "<<przed.s.s<<endl;
        lld yy=max(po.f.s,przed.f.s);
        lld mm=min(po.f.s+po.s.f-yy,przed.f.s+przed.s.f-(po.f.f-przed.f.f)-yy);
        if(przed.s.s==1){
            suma-=mm*mm;
            troj.pb(mp(mp(po.f.f,yy),mp(mm,-1)));
        }else{
            suma+=mm*mm;
            troj.pb(mp(mp(po.f.f,yy),mp(mm,1)));
            //cout<<"G";
        }
    }
}


int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        scanf("%lld",&m);
        //tem=troj.size();
        troj1[i]=mp(mp(x,y),mp(m,1));

    }
    sort(troj1,troj1+n);
    for(int i=0;i<n;++i){
        tem=troj.size();
        troj.pb(troj1[i]);
        suma+=troj1[i].s.f*troj1[i].s.f;
        //troj1[i]=mp(mp(x,y),mp(m,1));
        for(int j=0;j<tem;++j){

            check(troj[j],troj[tem]);
        }
    }
    if(suma%2){
        printf("%lld.5",suma/2);
    }else{
        printf("%lld.0",suma/2);
    }
    //cout<<troj.size();

    //cout<<troj.size();
    return 0;
}
/*
5
0 0 1
0 0 1
0 0 1
0 0 1
0 0 1
*/
