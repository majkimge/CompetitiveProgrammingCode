#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define pb push_back
#define s second
#define MOD 2005
#pragma GCC optimize ("Ofast")

using namespace std;

int prefy[1009][2009];
int n,t,a,b,p;
pair<int,int> kon;
pair<int,int> pocz;
int tab[1009];
int sumy[1109];
pair<int,pair<pair<int,int>,pair<int,int> > >zapy[100009];
int wyniki[100009];

int bin(int ilez, int po, int ko){
    int l=0;
    int pp=MOD-1;
    int s=0;
    int wyn=-1;
    while(l<=pp){
        s=(l+pp)/2;
        if(prefy[ko][(s+pocz.f)%MOD]-prefy[po-1][(s+pocz.f)%MOD]>=ilez){
            wyn=s;
            l=s+1;
        }else{
            pp=s-1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=1;i<=n;++i){
        sumy[i]=tab[i]+sumy[i-1];
    }
    for(int i=0;i<t;++i){
        scanf("%d%d%d",&a,&b,&p);
        zapy[i]=mp((sumy[b]-sumy[a-1])/p,mp(mp(a,b),mp(p,i)));
    }
    sort(zapy,zapy+t);
    pocz=mp(0,1);
    kon=mp(MOD-1,MOD);
    for(int i=0;i<MOD;++i){
        for(int j=1;j<=n;++j){
            prefy[j][i]=tab[j]/(i+1)+prefy[j-1][i];
        }
    }
    //cout<<prefy[6][0];
    for(int i=0;i<t;++i){

        int wyn=0;
        if(prefy[zapy[i].s.f.s][(MOD-1+pocz.f)%MOD]-prefy[zapy[i].s.f.f-1][(MOD-1+pocz.f)%MOD]>=zapy[i].s.s.f){
            wyn=MOD-1;
        }else{
            wyn=bin(zapy[i].s.s.f,zapy[i].s.f.f,zapy[i].s.f.s);
        }
        //cout<<wyn;
        while(wyn==MOD-1){
            //cout<<"X";
            kon.f=pocz.f;
            pocz.f=(pocz.f+1)%MOD;

            pocz.s++;
            kon.s++;
            for(int j=1;j<=n;++j){
                prefy[j][kon.f]=tab[j]/(kon.s)+prefy[j-1][kon.f];
            }
            if(prefy[zapy[i].s.f.s][(MOD-1+pocz.f)%MOD]-prefy[zapy[i].s.f.f-1][(MOD-1+pocz.f)%MOD]>=zapy[i].s.s.f){
                wyn=MOD-1;
            }else{
                wyn=MOD-2;
            }
        }
        if(wyn==-1){
            wyniki[zapy[i].s.s.s]=0;
        }else{
            wyniki[zapy[i].s.s.s]=wyn+pocz.s;
        }

    }
    for(int i=0;i<t;++i){
        printf("%d\n",wyniki[i]);

    }
    return 0;
}

/*
9 3
10000 10000 10000 10000 10000 10000 10000 1 10000
1 3 1
1 9 9
1 2 20001
*/
