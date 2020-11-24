#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

map<pair<int,int>,int> m;
int n,x,y,a,b,c,d,wyn;
vector<int> v[MAX];
vector<int> kolor[MAX];
int last[MAX];
vector<int> kraw;
vector<int> przyp;
lld ilekol[MAX];
int ileraz[MAX];
lld ileter[MAX];
int czyprzyp[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        scanf("%d",&y);
    }
    for(int i=0;i<n-2;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        kolor[a].pb(d);
        kolor[b].pb(d);
        kolor[c].pb(d);
        ileraz[a]++;
        ileraz[b]++;
        ileraz[c]++;
        ilekol[d]+=3;
        m[mp(a,b)]++;
        m[mp(a,c)]++;
        m[mp(b,c)]++;
        m[mp(b,a)]++;
        m[mp(c,a)]++;
        m[mp(c,b)]++;
        v[a].pb(b);
        v[a].pb(c);
        v[b].pb(a);
        v[b].pb(c);
        v[c].pb(b);
        v[c].pb(a);

    }

        for(int j=0;j<v[1].size();++j){
            if(m[mp(v[1][j],1)]<2){
                last[1]=v[1][j];
                przyp.pb(1);
                przyp.pb(v[1][j]);
                czyprzyp[1]=1;
                break;
            }
        }
        while(przyp.size()<n){
            int pp=przyp[przyp.size()-1];
            for(int j=0;j<v[pp].size();++j){
            if(m[mp(v[pp][j],pp)]<2&&last[v[pp][j]]!=pp){
                last[pp]=v[pp][j];
                przyp.pb(v[pp][j]);
                czyprzyp[pp]=1;
                break;
            }
        }
        }
        for(int i=1;i<=n;++i){
            if(!czyprzyp[i]){
                last[i]=przyp[0];
            }
            cout<<last[i];
        }
        int cot=1;
        for(int j=1;j<=n;++j){
            for(int i=0;i<=n;++i){
                ileter[i]=0;
            }
            cot=j;
            for(int xx=0;xx<kolor[cot].size();++xx){
                ileter[kolor[cot][xx]]++;
            }
            cot=last[cot];
            for(int xx=0;xx<kolor[cot].size();++xx){
                ileter[kolor[cot][xx]]++;
            }
            for(int i=0;i<n-j-1;++i){
                cot=last[cot];

                for(int xx=0;xx<kolor[cot].size();++xx){
                ileter[kolor[cot][xx]]++;
                }
                int czyx=1;
                for(int xx=0;xx<kolor[cot].size();++xx){
                if(ileter[kolor[cot][xx]]!=ilekol[kolor[cot][xx]]&&ileter[kolor[cot][xx]]!=0){
                    czyx=0;
                    //cout<<"F";
                    break;
                }
                }
                if(czyx){
                        cout<<"A"<<cot<<"A"<<j;
                    wyn++;
                }

            }
        }
        printf("%d",wyn);

    return 0;
}
