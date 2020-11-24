#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<lld,pair<lld,lld> >
#define pii pair<lld,lld>
#define MAX 50009
#pragma GCC optimalize ("ofast")

using namespace std;

lld z,n;
lld wynik;
char s[MAX];
pair<pii,lld> KMR[30][MAX];
lld posort[MAX];
lld LCP[MAX],kk;

lld poty[30];
lld powty;
vector<pair<lld,lld> >v;


int main()
{
    scanf("%lld",&z);
    for(lld xdd=0;xdd<z;++xdd){
        scanf("%lld",&n);
        scanf("%s",s);
        for(lld i=0;i<n;++i){
            KMR[0][i]=mp(mp(s[i]-'a',s[i]-'a'),i);
        }
        poty[0]=1;
        for(lld i=1;i<20;++i){
            poty[i]=poty[i-1]*2;
        }
        posort[n]=-1;
        for(lld i=1;i<=15;++i){
            sort(KMR[i-1],KMR[i-1]+n);
            //cout<<endl;
            lld kt=0;
            for(lld j=0;j<n;++j){
                posort[KMR[i-1][j].s]=kt;
                while(j<n&&KMR[i-1][j].f.f==KMR[i-1][j+1].f.f&&KMR[i-1][j].f.s==KMR[i-1][j+1].f.s){
                    ++j;
                    posort[KMR[i-1][j].s]=kt;
                }
                ++kt;
            }
            for(lld j=0;j<n;++j){
                //cout<<posort[j]<<" ";
                KMR[i][j]=mp(mp(posort[j],posort[min((lld)n,j+poty[i-1])]),j);
            }
        }
        lld ter=0;
        for(lld i=0;i<n;++i){
            //cout<<i<<" "<<KMR[14][i].s<<endl;

            ter=max(ter,(lld)1);
            if(posort[i]==n-1){
                ter=0;
                continue;
            }
            lld poczna=KMR[14][posort[i]+1].s;
            //cout<<posort[i]<<endl;
            lld wsk1=i+ter-1;
            lld wsk2=poczna+ter-1;
            while(wsk1<n&&wsk2<n&&s[wsk1]==s[wsk2]){
                ++ter;
                ++wsk1;
                ++wsk2;
            }
            ter--;
            LCP[posort[i]]=ter;
        }
        v.pb(mp(0,-1));
        for(lld i=0;i<n;++i){
            //cout<<LCP[i]<<endl;
            if(v.empty()||v[v.size()-1].f<LCP[i]){
                v.pb(mp(LCP[i],i));
            }else if(!v.empty()&&v[v.size()-1].f>LCP[i]){
                //lld last=v[v.size()-1].f;
                lld last=v[v.size()-1].s;
                while(!v.empty()&&v[v.size()-1].f>LCP[i]&&v[v.size()-1].f){
                    powty+=(lld)(v[v.size()-1].f-max((lld)v[v.size()-2].f,(lld)LCP[i]))*(i-v[v.size()-1].s)*(i-v[v.size()-1].s+1)/2;
                    last=v[v.size()-1].s;
                    v.pop_back();
                }
                if(v.empty()||v[v.size()-1].f<LCP[i]){
                    v.pb(mp(LCP[i],last));
                }

            }
        }
        lld sumik=n*(n+1)/2;
        sumik=sumik*(sumik-1)/2;
        //cout<<powty;
        printf("%lld / %lld\n",powty/__gcd(powty,sumik),sumik/__gcd(powty,sumik));
        v.clear();
        powty=0;
        for(lld i=0;i<=n;++i){
            LCP[i]=0;
            posort[i]=0;
            for(lld j=0;j<=15;++j){
                KMR[j][i]=mp(mp(0,0),0);
            }
        }
    }
    return 0;
}
/*
10
5
aaaab
*/
