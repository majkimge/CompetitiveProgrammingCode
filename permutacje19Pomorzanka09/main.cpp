#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define int uint_fast32_t

using namespace std;


int n,tab[MAX][3],kk=1;
int poz[MAX][3];
pair<pii,int> poso[MAX];
pii dwaos[MAX];
pii templ[MAX],tempp[MAX],tempc[MAX];
lld wynik;
int tree[1100000];
vector<int> dody;

int dod(int gdz, int ile){
    gdz+=kk;
    while(gdz){
        tree[gdz]+=ile;
        gdz>>=1;
    }
}

int sum(int l, int p){
    int ret=0;
    l+=kk;
    p+=kk;
    ret+=tree[l];
    if(l!=p){
        ret+=tree[p];
    }
    while(l/2!=p/2){
        if(!(l&1)){
            ret+=tree[l+1];
        }
        if(p&1){
            ret+=tree[p-1];
        }
        l>>=1;
        p>>=1;
    }
    return ret;
}

void con(int l, int p){
    if(l>=p)return;

    con(l,(l+p)/2);
    con((l+p)/2+1,p);
    int d=p-l+1;
    int dl=(l+p)/2-l+1;
    int dp=d-dl;
    for(int i=l;i<=p;++i){
        tempc[i-l]=dwaos[i];
    }
    for(int i=0;i<dl;++i){
        templ[i]=tempc[i];
    }
    for(int i=dl;i<d;++i){
        tempp[i-dl]=tempc[i];
    }
    sort(templ,templ+dl);
    sort(tempp,tempp+dp);
    int zako=dp;
    //cout<<sum(0,n)<<"X";
    for(int i=dl-1;i>=0&&i<=MAX;--i){
        if(zako>0){
                while(zako>0&&templ[i].f<tempp[zako-1].f){
                dody.pb(tempp[zako-1].s);
                dod(tempp[zako-1].s,1);
                zako--;
                //cout<<zako<<" ";
            }
        }

        wynik+=(lld)sum(templ[i].s,n);//cout<<l<<" "<<p<<" "<<templ[i].f<<" "<<templ[i].s<<" "<<wynik<<endl;
    }
    for(int i=0;i<dody.size();++i){
        dod(dody[i],-1);
    }
    dody.clear();
    return;
}

int32_t main()
{
    scanf("%u",&n);
    while(kk<n)kk<<=1;
    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j){
            scanf("%u",&tab[j][i]);
            tab[j][i]--;
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j){
            poz[tab[j][i]][i]=j;
        }
    }
    for(int i=0;i<n;++i){
        //cout<<poz[i][0]<<" ";
        poso[i]=mp(mp(poz[i][0],poz[i][1]),poz[i][2]);
    }
    sort(poso,poso+n);
    for(int i=0;i<n;++i){
        dwaos[i]=mp(poso[i].f.s,poso[i].s);
        //cout<<dwaos[i].f<<" "<<dwaos[i].s<<endl;
    }
    //cout<<"X";
    con(0,n-1);
    printf("%lld",wynik);
    return 0;
}
