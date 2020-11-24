#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define pii pair<double,double>

using namespace std;

lld n,L,ile;
pii tab[MAX];
double wynik,odl,tl,tp,nal,nap,a,b;

int check(double zas){
    nal=0.0;
    nap=0.0;
    double zas1=zas*zas;
    for(int i=0;i<n;++i){
        if(zas1-tab[i].s>0.00001){
        odl=sqrt(zas1-tab[i].s);

        tl=tab[i].f-odl;
        tp=tab[i].f+odl;
        nap=max(tp,nap);
        //cout<<odl;
        if(tl-0.0000001<nal){
            nal=max(nap,nal);
        }
        }
    }
    if(nal+0.0000001>=L)return 1;
    return 0;
}

void bin(){
    double l=0.0;
    double p=10000000000.0;
    double ss=(l+p)/2;
    //int ile=0;
    while(l<p){
            //++ile;
        //cout<<s;
        ss=(l+p)/2;
        if(check(ss)){
            wynik=ss;
            p=ss-0.00001;
        }else{
            l=ss+0.00001;
        }
    }
}

int main()
{
    scanf("%lld%lld",&n,&L);
    for(int i=0;i<n;++i){
        scanf("%lf%lf",&a,&b);
        b=abs(b);
        b*=b;
        tab[i]=mp(a,b);

    }
    bin();
    printf("%.8lf",wynik);
    //cout<<endl<<ile;
    //cout<<check((double)6);
    return 0;
}
