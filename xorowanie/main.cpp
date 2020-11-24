#include <bits/stdc++.h>
#define lld int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009

using namespace std;

lld n,m,a,b,c;
pair<lld,lld> zap[MAX];
vector<pair<lld,lld> >kon[MAX];
vector<pair<lld,lld> >pocz[MAX];
lld wyniki[MAX],przyps;
map<pair<int,int>,int> kony;
map<pair<int,int>,int> poczy;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        zap[i]=mp(a,b);
        if(!kony[mp(a,b)])kon[a].pb(mp(b,c));

        kony[mp(a,b)]=1;
        if(!poczy[mp(b,a)])pocz[b].pb(mp(-a,c));

        poczy[mp(b,a)]=1;
    }
    for(int i=1;i<=n;++i){

        sort(kon[i].begin(),kon[i].end());
        for(int j=1;j<(int)kon[i].size();++j){
                //cout<<"Y"<<i<<" "<<kon[i][j].f<<endl;
            if(!kony[mp(kon[i][j-1].f+1,kon[i][j].f)]){
                kon[kon[i][j-1].f+1].pb(mp(kon[i][j].f,((kon[i][j].s)^(kon[i][j-1].s))));
                kony[mp(kon[i][j-1].f+1,kon[i][j].f)]=1;
            }
            if(!poczy[mp(kon[i][j].f,kon[i][j-1].f-1)]){
                pocz[kon[i][j].f].pb(mp(-kon[i][j-1].f-1,((kon[i][j].s)^(kon[i][j-1].s))));
                poczy[mp(kon[i][j].f,kon[i][j-1].f-1)]=1;
            }

        }
    }
    for(int i=n;i>=1;--i){
        sort(pocz[i].begin(),pocz[i].end());

        for(int j=0;j<(int)pocz[i].size()-1;++j){//cout<<pocz[i].size()-1;
            //cout<<"X"<<i<<" "<<pocz[i][j].f<<endl;
            if(!poczy[mp(-pocz[i][j].f-1,-pocz[i][j+1].f)]){
                pocz[-pocz[i][j].f-1].pb(mp(pocz[i][j+1].f,((pocz[i][j].s)^(pocz[i][j+1].s))));
                poczy[mp(-pocz[i][j].f-1,-pocz[i][j+1].f)]=1;
            }

        }
    }

    for(int i=n;i>=1;--i){
        sort(pocz[i].begin(),pocz[i].end());
        sort(kon[i].begin(),kon[i].end());
        //cout<<i<<" "<<pocz[i][0].f<<endl;
        if(pocz[i].size()==0||(pocz[i][0].f!=-i&&kon[i][0].f!=i)){
            przyps=1;
            break;
        }else{
            if(pocz[i][0].f==-i){
                wyniki[i]=pocz[i][0].s;
            }else{
                wyniki[i]=kon[i][0].s;
            }
        }
    }
    //cout<<"F";
    if(przyps){
        printf("NIE\n");
    }else{
        for(int i=1;i<=n;++i){
            printf("%d ",wyniki[i]);
        }
    }

    return 0;
}
