#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<lld,pair<lld,lld> >
#define MAX 300009

using namespace std;

lld n,m,ilech[MAX],a,k,kt,ilem[MAX];
int czyj[MAX],b,c;
pair<lld,pair<int,int> > zapy[MAX];
vector<pair<lld,pair<int,int> > > bin[MAX][2];
lld tree[1100000],kk=1;
int wyny[MAX];
vector<int> ktore[MAX];

void add(lld l,lld p, lld ile){
    l+=kk;
    p+=kk;
    if(l!=p){
        tree[p]+=ile;
    }
    tree[l]+=ile;
    while(l/2!=p/2){
        if(l%2==0){
            tree[l+1]+=ile;
        }
        if(p%2==1){
            tree[p-1]+=ile;
        }
        l>>=1;
        p>>=1;
    }
}

lld check(lld gdz){
    gdz+=kk;
    lld wyn=0;
    while(gdz){
        wyn+=tree[gdz];
        gdz>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    while(kk<m)kk<<=1;
    for(int i=0;i<m;++i){
        scanf("%d",&czyj[i]);
        czyj[i]--;
        ktore[czyj[i]].pb(i);

    }
    for(int i=0;i<n;++i){
        scanf("%lld",&ilech[i]);
        wyny[i]=-1;
    }

    scanf("%lld",&k);
    for(int i=0;i<k;++i){
        scanf("%lld%d%d",&a,&b,&c);
        a--;
        b--;
        zapy[i]=mp(c,mp(a,b));
    }
    for(int i=0;i<n;++i){
        bin[k/2][0].pb(mp(i,mp(0,k)));
    }
    int ilej=0;
    while(ilej<20){
        for(int i=0;i<1100000;++i){
            tree[i]=0;
        }
        for(int i=0;i<m;++i){
            bin[i][kt^1].clear();
        }
        for(int i=0;i<n;++i){
            ilem[i]=0;
        }
        for(int i=0;i<k;++i){
            if(zapy[i].s.f<=zapy[i].s.s){
                add(zapy[i].s.f,zapy[i].s.s,zapy[i].f);
            }else{
                add(zapy[i].s.f,m-1,zapy[i].f);
                add(0,zapy[i].s.s,zapy[i].f);
            }
            /*if(ilej==1){
                for(int i=0;i<m;++i){
                    cout<<check(i)<<" ";
                }
                cout<<endl;
            }*/
            for(int j=0;j<bin[i][kt].size();++j){
                for(int z=0;z<ktore[bin[i][kt][j].f].size();++z){
                    ilem[bin[i][kt][j].f]+=check(ktore[bin[i][kt][j].f][z]);
                }
                //cout<<bin[i][kt][j].f<<" "<<ilem[bin[i][kt][j].f]<<" "<<i<<endl;
                if(ilem[bin[i][kt][j].f]>=ilech[bin[i][kt][j].f]){
                    wyny[bin[i][kt][j].f]=i;
                    bin[i][kt][j].s.s=i-1;
                    int sss=(bin[i][kt][j].s.s+bin[i][kt][j].s.f)/2;
                    bin[sss][kt^1].pb(bin[i][kt][j]);
                }else{
                    bin[i][kt][j].s.f=i+1;
                    int sss=(bin[i][kt][j].s.s+bin[i][kt][j].s.f)/2;
                    bin[sss][kt^1].pb(bin[i][kt][j]);
                }
            }
        }


        kt=kt^1;
        ++ilej;
    }
    for(int i=0;i<n;++i){
        if(wyny[i]!=-1){
            printf("%d\n",wyny[i]+1);
        }else{
            printf("NIE\n");
        }
    }
    return 0;
}
