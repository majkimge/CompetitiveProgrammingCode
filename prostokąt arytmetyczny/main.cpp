#include <bits/stdc++.h>
#define mp make_pair
#define lld long long
#define f first
#define s second
#define pb push_back
#define MAX 3008

using namespace std;

int t,n,m,wynik;
int tab[MAX][MAX];
int dop[MAX][MAX], dod[MAX][MAX];
bool blokp[MAX][MAX],blokd[MAX][MAX];
vector<pair<int,int> >v;

int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&tab[i][j]);
            }
        }

        for(int i=1;i<=n;++i){
            for(int j=3;j<=m;++j){
                if(tab[i][j]-tab[i][j-1]!=-tab[i][j-2]+tab[i][j-1]){
                    blokp[i][j-1]=1;
                }
            }
        }


        for(int i=1;i<=m;++i){
            for(int j=3;j<=n;++j){
                if(tab[j][i]-tab[j-1][i]!=-tab[j-2][i]+tab[j-1][i]){
                    blokd[j-1][i]=1;
                }
            }
        }

        for(int i=1;i<=n;++i){
            int kt=1;
            for(int j=m;j>0;--j){

                dop[i][j]=kt;
                if(blokp[i][j])kt=1;
                ++kt;
            }
        }

        for(int i=1;i<=n;++i){
            int kt=1;
            for(int j=m;j>0;--j){

                if(blokd[i-1][j])kt=0;
                dod[i][j]=kt;

                ++kt;
            }
        }
        /*for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<blokd[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n+1;++j){
                int last=j;
                if(dod[j][i]>=dop[j][i]){
                    while(!v.empty()&&v[v.size()-1].f>=dop[j][i]){
                        wynik=max(wynik,v[v.size()-1].f*(j-v[v.size()-1].s));
                        last=v[v.size()-1].s;
                        v.pop_back();

                    }
                    v.pb(mp(dop[j][i],last));

                }else{
                    while(!v.empty()&&v[v.size()-1].f>=dod[j][i]){
                        wynik=max(wynik,v[v.size()-1].f*(j-v[v.size()-1].s));
                        last=v[v.size()-1].s;
                        v.pop_back();

                    }
                    v.pb(mp(dod[j][i],last));

                    v.pb(mp(min(dop[j][i],dop[j-1][i]),max(last,j-1)));
                    v.pb(mp(dop[j][i],j));
                }




            }
            v.clear();
        }
        for(int i=2;i<=m;++i){
            for(int j=1;j<=n;++j){
                wynik=max(wynik,min(dop[i][j],dop[i-1][j])*2);
                wynik=max(wynik,dop[i][j]);
            }
        }
        wynik=max(wynik,min(2,n*m));
        printf("%d\n",wynik);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                tab[i][j]=dop[i][j]=dod[i][j]=blokp[i][j]=blokd[i][j]=0;
            }
        }
        wynik=0;

    }
    return 0;
}
/*
3
5 4
1 1 1 1
2 2 2 2
3 4 5 6
4 5 6 7
5 6 7 8
*/
