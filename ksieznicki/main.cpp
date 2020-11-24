#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 5000009
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696951
#define MOD1 1000000009

using namespace std;

int n,m,jakie,ile,wyn,t;
char tab[409][409];
int odw[90009];
vector<int> v[90009];

void dfs(int from){
    odw[from]=1;
    for(int i=0;i<v[from].size();++i){
        if(!odw[v[from][i]]){
            dfs(v[from][i]);
        }

    }
}

int main()
{
    scanf("%d",&t);
    for(int xdd=0;xdd<t;++xdd){
        for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
                    tab[i][j]=0;
                    odw[i*(m+1)+j]=0;


            }
        }
        wyn=0;
        scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;++i){
        scanf("%s",&tab[i][1]);
    }
    jakie=4;
    ile=0;
    for(int xd=0;xd<100;++xd){
            ile=0;
        for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
                if(tab[i][j]=='.'){
                    int temp=0;
                if(tab[i][j+1]=='.') temp++;
                if(tab[i+1][j]=='.') temp++;
                if(tab[i][j-1]=='.') temp++;
                if(tab[i-1][j]=='.') temp++;
                if(temp==jakie){
                    ile++;
                    tab[i][j]='#';
                }
                }

            }
        }
        if(ile==0) jakie=max(jakie-1,1);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
                if(tab[i][j]=='.'){
                    //int te(m+1)p=0;
                if(tab[i][j+1]=='.'){
                    v[i*(m+1)+j].pb(i*(m+1)+j+1);
                    v[i*(m+1)+j+1].pb(i*(m+1)+j);
                }
                if(tab[i+1][j]=='.'){
                    v[i*(m+1)+j].pb(i*(m+1)+j+(m+1));
                    v[i*(m+1)+j+(m+1)].pb(i*(m+1)+j);
                }
                if(tab[i][j-1]=='.'){
                    v[i*(m+1)+j].pb(i*(m+1)+j-1);
                    v[i*(m+1)+j-1].pb(i*(m+1)+j);

                }
                if(tab[i-1][j]=='.'){
                    v[i*(m+1)+j].pb(i*(m+1)+j-(m+1));
                    v[i*(m+1)+j-(m+1)].pb(i*(m+1)+j);
                }

                }

            }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
                if(tab[i][j]=='.'){
                    if(!odw[i*(m+1)+j]){
                        dfs(i*(m+1)+j);

                        wyn++;
                    }
                }

            }
        }//cout<<"F";
    printf("0\n");
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            printf("#");
        }
        printf("\n");
    }
    }


    return 0;
}
