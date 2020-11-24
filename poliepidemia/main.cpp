#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,a,b;
vector<int> v[MAX];
queue<pair<int,int> >q;
int odw[MAX];
int ligma;
void bfs(){
    while(!q.empty()){
        int from=q.front().f;
        int lig=q.front().s;
    if(lig==1&&!odw[from]){

            ligma++;
        }
        odw[from]=1;
        q.pop();//cout<<from;

        for(int i=0;i<v[from].size();++i){
            if(!odw[v[from][i]]){

                q.push(mp(v[from][i],lig));
            }
        }
        //return lig;
    }


}




int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    q.push(mp(1,1));
    q.push(mp(n,0));
    bfs();
    //cout<<ligma;
    if(ligma>n-ligma){
        printf("Ligma");
    }else{
        printf("Sugma");
    }
    return 0;
}
