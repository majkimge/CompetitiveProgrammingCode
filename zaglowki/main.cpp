#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 409
#define f first
#define s second
#define INF 1000000000


using namespace std;

int n,m,n1,m1;
char co1[MAX][MAX];
char co;
int tab[MAX*MAX];
pair<int,int> roz[MAX*MAX];
queue<int> q;
vector<int> v[MAX*MAX];


int wyn[MAX*MAX];
int odw[MAX*MAX];

void bfs(){
    while(!q.empty()){
        int from=q.front();
        q.pop();
        odw[from]=1;
        for(int i=0;i<v[from].size();++i){
            if(!odw[v[from][i]]){
                if(v[from][i]==from+1&&v[from][i]%m1!=0){
                    roz[v[from][i]].f++;
                }else if(v[from][i]==from-1&&from%m1!=0){
                    roz[v[from][i]].s++;
                }else if(v[from][i]==from+m1){
                    if(tab[v[from][i]]==1){
                        roz[v[from][i]].f++;
                    }else{
                        roz[v[from][i]].s++;
                    }
                }else if(v[from][i]==from-m1){
                    if(tab[v[from][i]]==1){
                        roz[v[from][i]].s++;
                    }else{if(v[from][i]==11){
                        cout<<from;
                    }
                        roz[v[from][i]].f++;
                    }
                }
                if(roz[v[from][i]].f>=2||roz[v[from][i]].s>=2){

                    wyn[v[from][i]]=wyn[from]+2;
                    q.push(v[from][i]);
                }
            }
        }

    }
}

int main()
{
    scanf("%d%d",&n,&m);
    n1=n+2;
    m1=m+2;
    for(int i=1;i<=n;++i){
        scanf("%s",&co1[i][1]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            co=co1[i][j];
            if(co=='Z'){
                tab[i*m1+j]=1;

            }else{
                tab[i*m1+j]=2;
            }
            cout<<tab[11];
            v[i*m1+j].pb(i*m1-m1+j);
            v[i*m1+j].pb(i*m1+m1+j);
            v[i*m1+j].pb(i*m1+1+j);
            v[i*m1+j].pb(i*m1-1+j);
            v[i*m1-m1+j].pb(i*m1+j);
            v[i*m1+m1+j].pb(i*m1+j);
            v[i*m1+1+j].pb(i*m1+j);
            v[i*m1-1+j].pb(i*m1+j);

        }
    }
    for(int i=0;i<m1;++i){
        q.push(i);
        q.push(i+m1*(n1-1));
        q.push(m1*i);
        q.push(m1*i+m1-1);
        odw[i]=1;
        odw[i+m1*(n1-1)]=1;
        odw[m1*i]=1;
        odw[m1*i+m1-1]=1;
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            wyn[i*m1+j]=-1;
        }
    }
    bfs();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%d ",wyn[i*m1+j]);
        }
        printf("\n");
    }
    return 0;
}
