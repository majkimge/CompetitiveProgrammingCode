#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000


using namespace std;

lld n,x,y,x2,y2,k=1,ile=1,lastx,tempocz,dod;
lld wynik,wyn;
vector<pair<pair<lld,lld>,pair<lld,lld> > >v;
vector<pair<pair<lld,lld>,pair<lld,lld> > >pozy;
vector<pair<pair<lld,lld>,pair<lld,lld> > >piony;
map<lld,lld> ost;
map<lld,lld> ilepion;
map<lld,lld> ilepoz;

vector<pair<lld,pair<lld,lld> > >tree;

void add(lld gdzie,lld pocz,lld kon,lld w,lld co){
    //cout<<pocz<<" "<<kon<<endl;
    if(pocz==gdzie&&kon==gdzie){
        tree[w].f+=co;
    }else if(kon<gdzie||pocz>gdzie||pocz>kon){
        //return;
    }else{
        if(tree[w].s.f==0){//cout<<"GG";
            tree[w].s.f=ile;
            ile++;
            tree.pb(mp(0,mp(0,0)));
        }
        add(gdzie,pocz,pocz+(kon-pocz)/2,tree[w].s.f,co);
        if(tree[w].s.s==0){

            tree[w].s.s=ile;
            ile++;
            tree.pb(mp(0,mp(0,0)));
        }
        add(gdzie,pocz+(kon-pocz)/2+1,kon,tree[w].s.s,co);
        tree[w].f+=co;
    }
}

void check(lld a,lld b,lld pocz,lld kon,lld w){
    //cout<<pocz<<" "<<kon<<endl;
    if(pocz>=a&&kon<=b){
        wyn+=tree[w].f;
    }else if(pocz>b||kon<a){
        return;
    }else{
        if(tree[w].s.f==0){
            tree[w].s.f=ile;
            ile++;
            tree.pb(mp(0,mp(0,0)));
        }
        check(a,b,pocz,pocz+(kon-pocz)/2,tree[w].s.f);
        if(tree[w].s.s==0){
            tree[w].s.s=ile;
            ile++;
            tree.pb(mp(0,mp(0,0)));
        }
        check(a,b,pocz+(kon-pocz)/2+1,kon,tree[w].s.s);
    }
}

int main()
{
    scanf("%lld",&n);
    while(k<INF){
        k<<=1;
    }
    k=(k-1)*2;
    k++;
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        scanf("%lld",&x2);
        scanf("%lld",&y2);
        if(x==x2){
            //v.pb(mp(mp(x,1),mp(min(y,y2),max(y,y2))));
            piony.pb(mp(mp(x,x),mp(min(y,y2),1)));
            piony.pb(mp(mp(x,x),mp(max(y,y2),2)));
        }else{
            pozy.pb(mp(mp(y,y),mp(min(x,x2),1)));
            pozy.pb(mp(mp(y,y),mp(max(x,x2),2)));
            //v.pb(mp(mp(min(x,x2),0),mp(y,y)));
            //v.pb(mp(mp(max(x,x2),2),mp(y,y)));
        }
    }
    sort(piony.begin(),piony.end());
    sort(pozy.begin(),pozy.end());
    if(piony.size()!=0){
        lastx=piony[0].f.s;
        tempocz=piony[0].s.f;
        ilepion[piony[0].f.s]++;
    }
    for(int i=1;i<piony.size();++i){
        if(piony[i].f.s==lastx){
            if(piony[i].s.s==1){
                if(ilepion[piony[i].f.s]==0){
                    tempocz=piony[i].s.f;

                }ilepion[piony[i].f.s]++;
            }else{
                ilepion[piony[i].f.s]--;
                if(ilepion[piony[i].f.s]==0){
                    v.pb(mp(mp(piony[i].f.s,1),mp(tempocz,piony[i].s.f)));
                }
            }
        }else{
            if(ilepion[piony[i].f.s]==0){
                    tempocz=piony[i].s.f;
                    ilepion[piony[i].f.s]++;
                    lastx=piony[i].f.s;
                }
        }
    }
    if(pozy.size()!=0){
        lastx=pozy[0].f.s;
        tempocz=pozy[0].s.f;

        ilepoz[pozy[0].f.s]++;
    }//cout<<tempocz;
    for(int i=1;i<pozy.size();++i){
            //cout<<"B"<<pozy[i].f.f<<" "<<pozy[i].s.s;

        if(pozy[i].f.s==lastx){
            //cout<<tempocz;
            if(pozy[i].s.s==1){
                if(ilepoz[pozy[i].f.s]==0){
                    //cout<<"BPI";
                    tempocz=pozy[i].s.f;

                }ilepoz[pozy[i].f.s]++;
            }else{
                ilepoz[pozy[i].f.s]--;
                //cout<<ilepoz[pozy[i].f.s];
                if(ilepoz[pozy[i].f.s]==0){//
                    //v.pb(mp(mp(piony[i].f.s,1),mp(tempocz,piony[i].s.f)));
                   // cout<<tempocz<<" "<<pozy[i].s.f;
                    v.pb(mp(mp(tempocz,0),mp(pozy[i].f.f,pozy[i].f.f)));
                    v.pb(mp(mp(pozy[i].s.f,2),mp(pozy[i].f.f,pozy[i].f.f)));
                    wynik+=pozy[i].s.f-tempocz+1;
                    //v.pb(mp(mp(max(x,x2),2),mp(y,y)));
                }
            }
        }else{
            //cout<<"New";
            if(ilepoz[pozy[i].f.s]==0){
                    tempocz=pozy[i].s.f;
                    ilepoz[pozy[i].f.s]++;
                    lastx=pozy[i].f.s;
                }
        }
    }
    //cout<<wynik;
    sort(v.begin(),v.end());
    tree.pb(mp(0,mp(0,0)));
    for(int i=0;i<v.size();++i){
        if(v[i].f.s==0){
            //cout<<v[i].s.s;
            add(v[i].s.s+INF,0,k,0,1);
            //cout<<tree[0].f;
        }else if(v[i].f.s==2){
            add(v[i].s.s+INF,0,k,0,-1);
            //cout<<v[i].s.s;
        }else{
            wynik+=v[i].s.s-v[i].s.f+1;
            wyn=0;

            check(v[i].s.f+INF,v[i].s.s+INF,0,k,0);//cout<<"VV"<<wyn;
            wynik-=wyn;
        }
    }
    printf("%lld",wynik);
    return 0;
}
