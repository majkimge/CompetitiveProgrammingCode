#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000


using namespace std;

int n,m,a,b,ile,wyni,kt=1,q1,d,e,f1;
vector<pair<int,int> >v[MAX];
int rep[MAX];
int wiel[MAX];
int odp[MAX];
pair<int,int> krawy[MAX];
pair<int,pair<int,int> > zapy[MAX];
int odw[MAX];
priority_queue<pair<int,int> >q;

int Find(int x){
    if(rep[x]!=x) rep[x]=Find(rep[x]);
    return rep[x];
}

void Onion(int x,int y,int c){
    int rx=Find(x);
    int ry=Find(y);
    if(ry!=rx){
        rep[rx]=ry;
        wiel[ry]+=wiel[rx];
    }
}

void dijkstra(int to){
    while(ile<to&&!q.empty()){


    int from=q.top().s;
    //cout<<from;
    if(odw[from]!=kt){
        ile++;
    odw[from]=kt;
    wyni=-q.top().f;

    if(ile>=to){
        while(!q.empty()){
            q.pop();
        }
        return;
    }
    for(int i=0;i<v[from].size();++i){

        if(odw[v[from][i].s]<kt){
                //cout<<"F"<<from<<v[from][i].s;
            q.push(mp(-v[from][i].f,v[from][i].s));
        }
    }
    }

    q.pop();

    //cout<<v[2].size();

    }

}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;++i){
        rep[i]=i;
        wiel[i]=1;
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d",&a,&b);
        //Onion(a,b,i);
        krawy[i]=mp(a,b);
    }

    scanf("%d",&q1);
    for(int i=0;i<q1;++i){
        scanf("%d%d%d",&d,&e,&f1);

        zapy[i]=mp(f1,mp(d,e));

    }
    sort(zapy,zapy+q1);
    for(int i=1;i<=m;++i){
        Onion(krawy[i].f,krawy[i].s,i);
        for(int j=0;j<q1;++j){
            if((zapy[j].f)>=i) break;
            if(odp[j]==0){
                if(Find(zapy[j].s.f)==Find(zapy[j].s.s)){
                    if(wiel[Find(zapy[j].s.f)]>=zapy[j].f){
                        odp[j]=i;
                    }
                }else{
                    if(wiel[Find(zapy[j].s.f)]+wiel[Find(zapy[j].s.s)]>=zapy[j].f){
                        odp[j]=i;
                    }
                }
            }
        }
    }
    for(int j=0;j<q1;++j){
            printf("%d\n",odp[j]);
        }
    return 0;
}
/*
3 3
1 2
1 3
2 3
1
1 2 3


5 6
2 3
4 5
1 2
1 3
1 4
1 5
1
1 3 5
*/
