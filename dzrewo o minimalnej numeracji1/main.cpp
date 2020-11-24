#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 1000009
#define f first
#define s second

using namespace std;

int n,d,przyps;
int tab[MAX];
vector<pair<int,int> >v;
int wynik[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    if(n>1){
        wynik[tab[0]]=0;
        //v.pb(mp(tab[0],1));
        for(int i=1;i<=100;++i){
                przyps=0;
                v.clear();
                v.pb(mp(tab[0],1));
                v.pb(mp(tab[1],2));
            for(int j=2;j<n;++j){
                if(v[v.size()-1].s<i){
                    wynik[tab[j]]=v[v.size()-1].f;
                    v.pb(mp(tab[j],v[v.size()-1].s+1));
                }else{
                    while(v.size()>=2&&v[v.size()-1].f>tab[j]){
                        v.pop_back();
                    }
                    if(v[v.size()-1].f>tab[j]||v.size()<=1){
                        przyps=1;
                        break;
                    }
                    v.pop_back();
                    wynik[tab[j]]=v[v.size()-1].f;
                    v.pb(mp(tab[j],v[v.size()-1].s+1));
                }
            }
            if(!przyps){
                d=i;
                break;
            }
        }
        printf("%d\n",d);
        for(int i=1;i<=n;++i){
            printf("%d ",wynik[i]);
        }
    }else{
        printf("1\n0 ");
    }

    return 0;
}
