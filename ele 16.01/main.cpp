#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define pb push_back
#define INF 1000000009

using namespace std;

pair<int,int> lim[MAX];
priority_queue<pair<int,int> >q;
int n,gdz,a,b,wynik,tmin,tpos;
pair<int,int> ter;
int odw[MAX];
vector<pair<int,int> >v;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&b,&a);
        lim[i]=mp(a,b);
        v.pb(mp(max(a,b),i));
    }
    while(!v.empty()){
        tmin=INF;
        for(int i=0;i<v.size();++i){
            v[i].f=max(lim[v[i].s].f+gdz,lim[v[i].s].s);
            if(v[i].f-lim[v[i].s].f>lim[v[i].s].s){
                swap(v[i],v[v.size()-1]);
                v.pop_back();
                --i;
            }else{
                if(v[i].f<tmin){
                    tmin=v[i].f;
                    tpos=i;
                }
            }
        }
        if(tmin<INF){
            wynik++;
            gdz=tmin;
            swap(v[tpos],v[v.size()-1]);
            v.pop_back();
        }

    }
    printf("%d",wynik);
    return 0;
}

/*
10
4 7
2 5 bbb
1 9 bbb
5 6
1 3 bbb
2 10 bbb
1 4 bbb
3 8 bbb
4 1
5 2
*/
