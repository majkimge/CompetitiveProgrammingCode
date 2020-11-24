#include <bits/stdc++.h>
#define lld long long
#define MAX 290
#define MOD 1000000009
#define mp make_pair
#define f first
#define s second
#define pb push_back
using namespace std;

lld t,n,l,a,suma,nn,baza,www;
lld pocz[MAX];
float wyny[MAX];
pair<lld,float> wynik[MAX][MAX];
vector<pair<lld,float> > temp;

lld sgn( float tt){
    if(tt>0){
        return 1;
    }else if(tt<0){
        return 0;
    }else{
        return 0;
    }
}

int main()
{
    scanf("%lld",&t);
    for(int z=0;z<t;++z){

        suma=0;
    www=0;
        scanf("%lld",&n);
        scanf("%lld",&l);
        //scanf("%lld",&n);
        for(int j=1;j<=n;++j){
        for(int i=0;i<=n;++i){
            wynik[i][j]=mp(0,0);
        }
    }
        for(int i=1;i<=l;++i){
        scanf("%lld",&a);
        suma+=a;
        //baza+=round((float)a/
        pocz[i]=a;
    }
    for(int i=1;i<=n;++i){
        wyny[i]=round((float)((float)i/(float)n*(float)100))-(float)i/(float)n*(float)100;
        //
    }
    nn=n-suma;
    for(int i=0;i<=nn;++i){
        wynik[1][i]=mp(sgn(wyny[i+pocz[i]]),wyny[i+pocz[i]]);
    }
    for(int j=2;j<=l;++j){
        for(int i=0;i<=nn;++i){
            for(int kk=0;kk<=i;++kk){
                temp.pb(mp(sgn(wyny[kk+pocz[j]])+wynik[j-1][i-kk].f,wyny[kk+pocz[j]]+wynik[j-1][i-kk].s));
                //cout<<sgn(wyny[kk+pocz[j]])+wynik[j-1][i-kk].f;
            }

            sort(temp.begin(),temp.end());
            wynik[j][i]=temp[temp.size()-1];
            //cout<<wynik[j-1][i].f;
            temp.clear();
        }
    }
    for(int i=0;i<=nn;++i){
           www=max(www,wynik[l][i].f);

        }
        //cout<<n;
        if(n%10==0){
            printf("Case #%d: 100\n",z+1);
        }else{
            printf("Case #%d: %lld\n",z+1,www+99);
        }

    }

    return 0;
}
