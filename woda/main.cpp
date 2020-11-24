#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000696969


using namespace std;

lld n;

double a,b,c,wagi;
pair<double,pair<double,double> > bec[17];

double odl[17][17];
int rep[20];
int poty[20];
double drzewa[200000];
double dp[200000];
vector<int> vert;
int MAXI;
double teuj;
vector<pair<double,pair<int,int> > > kraw;

vector<int> osty;
vector<int> terra;

int Find(int x){
    if(rep[x]!=x)rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x, int y){
    int rx=Find(x);
    int ry=Find(y);

    if(rx!=ry){
        teuj+=odl[x][y];
        rep[rx]=ry;
    }
}




void robdrz(int kt, int ile){
    if(kt==n){
        kraw.clear();
        for(int i=0;i<vert.size();++i){
            for(int j=0;j<vert.size();++j){
                kraw.pb(mp(odl[vert[i]][vert[j]],mp(vert[i],vert[j])));
            }
        }
        teuj=0.0000000;
        double dodik=0;

        sort(kraw.begin(),kraw.end());
        for(int i=0;i<n;++i){
            rep[i]=i;
        }


        int maska=0;
        for(int i=0;i<vert.size();++i){
            maska+=poty[vert[i]];
            dodik+=bec[vert[i]].f;
        }
        for(int i=0;i<kraw.size();++i){
            //if(maska==7)cout<<kraw[i].s.f<<" "<<kraw[i].s.s<<endl;
            Union(kraw[i].s.f,kraw[i].s.s);
        }

        drzewa[maska]=(double)(dodik-teuj)/ile;
        //cout<<maska<<" "<<drzewa[maska]<<endl;
    }else{

        robdrz(kt+1, ile);
        vert.pb(kt);
        robdrz(kt+1, ile+1);
        vert.pop_back();
    }
}

void rob(int kt, int maska){
    if(kt==osty.size()){
        int maskik=0;
        for(int i=0;i<terra.size();++i){
            maskik+=poty[terra[i]];
        }
        //if(maska==15)cout<<maskik;
        dp[maska]=max(dp[maska],min(drzewa[maskik],dp[maska-maskik]));
    }else{
        rob(kt+1,maska);
        terra.pb(osty[kt]);
        rob(kt+1,maska);
        terra.pop_back();
    }
}

void rozw(){
    for(int i=1;i<=MAXI;++i){
            //cout<<"X";
        osty.clear();
        int ti=i;
        int kt=0;
        while(ti){
            if(ti%2){
                osty.pb(kt);
            }
            ++kt;
            ti>>=1;
        }
        //cout<<"X";
        rob(0,i);
    }
}



int main()
{
    scanf("%lld",&n);
    poty[0]=1;
    for(int i=1;i<20;++i){
        poty[i]=poty[i-1]*2;
    }
    for(int i=0;i<n;++i){
        scanf("%lf%lf%lf",&a,&b,&c);
        bec[i]=mp(c,mp(a,b));
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            odl[i][j]=sqrt((bec[i].s.f-bec[j].s.f)*(bec[i].s.f-bec[j].s.f)+(bec[i].s.s-bec[j].s.s)*(bec[i].s.s-bec[j].s.s));
        }
    }
    robdrz(0,0);
    int xdd=0;
    for(int i=0;i<n;++i){
        xdd+=poty[i];
    }
    MAXI=xdd;
    dp[0]=(double)INF;
    rozw();//cout<<"D";

    printf("%lf",dp[xdd]);

    return 0;
}
