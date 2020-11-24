#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define lld long long
#define f first
#define s second
#define MAX 37000009
#define INF 2000000009

using namespace std;

int n,a,b,k,na,ileodw,wyn=-2;
int odw[MAX];
vector<int> v[6009];
queue<pair<int,int> >q;

void bfs(){
    int done=0;
    while(!q.empty()){

        if(done) break;
        int co=q.front().f;
        int odl=q.front().s;
        odw[co]=1;
        q.pop();
        int t1=co/(n+1);

        int t2=co%(n+1);
       // cout<<"X"<<t1<<" "<<t2<<endl;
        for(int i=0;i<v[t1].size();++i){
            for(int j=0;j<v[t2].size();++j){
                int aa=v[t1][i];
                int bb=v[t2][j];

                if(aa>bb) swap(aa,bb);
                if(aa==bb){
                    wyn=odl;
                    done=1;
                    break;
                }//cout<<aa<<" "<<bb<<endl;
                //cout<<"CC"<<aa*(n+1)+bb;
                if(!odw[aa*(n+1)+bb]){
                    q.push(mp(aa*(n+1)+bb,odl+1));
                }

            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;++i){
        scanf("%d",&k);
        for(int j=0;j<k;++j){
            scanf("%d",&na);
            v[i].pb(na);
        }
    }
    if(a>b) swap(a,b);
    q.push(mp(a*(n+1)+b,0));
    bfs();
    //cout<<"F";
    printf("%d",wyn+1);
    return 0;
}
