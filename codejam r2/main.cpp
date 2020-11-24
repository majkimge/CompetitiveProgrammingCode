#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009

using namespace std;

lld n,t,l,r,swapped;

lld binl(){
    lld ll=0;
    lld pp=2000000000;
    lld s=(ll+pp)/2;
    lld ret=0;
    while(ll<=pp){
        s=(ll+pp)/2;
        if(s*n+s*(s-1)<=l){
            ll=s+1;
            ret=s;
        }else{
            pp=s-1;
        }
    }
    return ret;
}

lld binr(){
    lld ll=0;
    lld pp=2000000000;
    lld s=(ll+pp)/2;
    lld ret=0;
    while(ll<=pp){
        s=(ll+pp)/2;
        if(s*n+s*(s-1)+s<=r){
            ll=s+1;
            ret=s;
        }else{
            pp=s-1;
        }
    }
    return ret;
}

pair<lld,lld> points[109];
lld a,b;

map<pair<lld,lld>,vector<lld> > m;

map<pair<lld,lld>,lld > odwkier;

vector<pair<lld,lld> >kier;

map<pair<pair<lld,lld>,lld>, lld> odwpar;

map<pair<lld,lld>,vector<lld> > proste;

vector<lld> dx,dy;

vector<lld> ter;

lld odw[109],wynik,twyn;

pair<lld,lld> poi[109][109];

vector<lld> tter;

int odwziom[109];

int main()
{
    scanf("%lld",&t);

    for(int xdd=0;xdd<t;++xdd){
        scanf("%lld",&n);
        for(int i=0;i<n;++i){
            scanf("%lld%lld",&a,&b);
            points[i]=mp(a,b);
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                lld ddx=points[j].f-points[i].f;
                lld ddy=points[j].s-points[i].s;
                if(ddx==0){
                    dx.pb(i);
                    dx.pb(j);
                    poi[i][j]=mp(0,1);
                    continue;
                }
                if(ddy==0){
                    dy.pb(i);
                    dy.pb(j);
                    poi[i][j]=mp(1,0);
                    continue;
                }
                if(ddx*ddy<0){
                    ddx=-abs(ddx);
                    ddy=abs(ddy);
                }else{
                    ddx=abs(ddx);
                    ddy=abs(ddy);
                }
                ddx/=__gcd(ddx,ddy);
                ddy/=__gcd(ddx,ddy);
                poi[i][j]=mp(ddx,ddy);
                kier.pb(mp(ddx,ddy));
                m[mp(ddx,ddy)].pb(i);
                m[mp(ddx,ddy)].pb(j);
            }
        }

        for(int i=0;i<kier.size();++i){
            twyn=0;
            for(int j=0;j<m[kier[i]].size();++j){
                odw[m[kier[i]][j]]++;
                if(odw[m[kier[i]][j]]==1){

                    ter.pb(m[kier[i]][j]);
                }
            }
            if(!odwkier[kier[i]]){
                for(int i=0;i<ter.size();++i){
                    int tempo=1;

                        for(int j=i+1;j<ter.size();++j){
                            if(poi[ter[i]][ter[j]]==kier[i]){
                                tempo++;
                                swap(ter[j],ter[ter.size()-1]);
                                ter.pop_back();
                                --j;
                            }
                        }

                    tter.pb(tempo);
                }
                for(int i=0;i<tter.size();++i){
                    twyn+=tter[i]/2*2;
                }
                wynik=max(wynik,twyn+2);
                odwkier[kier[i]]=1;
            }


            //wynik=max(wynik,twyn);
            ter.clear();
            tter.clear();
            for(int j=0;j<m[kier[i]].size();++j){
                odw[m[kier[i]][j]]=0;

            }
        }

        twyn=0;
            for(int j=0;j<dx.size();++j){
                odw[dx[j]]++;
                if(odw[dx[j]]==1){
                    ter.pb(dx[j]);
                }
            }
            for(int i=0;i<ter.size();++i){
                    int tempo=1;

                        for(int j=i+1;j<ter.size();++j){
                            if(poi[ter[i]][ter[j]].f==0){
                                tempo++;
                                swap(ter[j],ter[ter.size()-1]);
                                ter.pop_back();
                                --j;
                            }
                        }

                    tter.pb(tempo);
                }
                for(int i=0;i<tter.size();++i){
                    twyn+=tter[i]/2*2;
                }
                wynik=max(wynik,twyn+2);
            //wynik=max(wynik,twyn);
            for(int j=0;j<dx.size();++j){
                odw[dx[j]]=0;

            }

            twyn=0;
            for(int j=0;j<dy.size();++j){
                odw[dy[j]]++;
                if(odw[dy[j]]==1){
                    ter.pb(dy[j]);
                }
            }
            for(int i=0;i<ter.size();++i){
                    int tempo=1;

                        for(int j=i+1;j<ter.size();++j){
                            if(poi[ter[i]][ter[j]].s==0){
                                tempo++;
                                swap(ter[j],ter[ter.size()-1]);
                                ter.pop_back();
                                --j;
                            }
                        }

                    tter.pb(tempo);
                }
                for(int i=0;i<tter.size();++i){
                    twyn+=tter[i]/2*2;
                }
                wynik=max(wynik,twyn+2);
            //wynik=max(wynik,twyn);
            for(int j=0;j<dy.size();++j){
                odw[dy[j]]=0;

            }
        printf("Case #%d: %lld \n",xdd+1,min(n,wynik));
        n=0;
        wynik=0;
        for(int i=0;i<kier.size();++i){
            m[kier[i]].clear();
            odwkier[kier[i]]=0;
        }
        dx.clear();
        dy.clear();
        kier.clear();
    }
    return 0;
}
/*
6
1 1
2 2
3 3
2 0
1 0
3 0
*/
