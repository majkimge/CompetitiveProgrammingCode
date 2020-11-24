#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define PIER 77

using namespace std;

int n,m,a,b,pocz,wynik,sum;
pair<int,int> lud[MAX];
pair<int,int> hot[MAX];
priority_queue<pair<int,int> > q;
int odw[MAX];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&lud[i].f);
        lud[i].s=i;
        lud[i].f=-lud[i].f;
        q.push(lud[i]);
    }
    while(!q.empty()){
        if(q.top().s<=sum){
            q.pop();
        }else{
            wynik+=a*((-q.top().f)*(q.top().s-sum))+b;
            sum=q.top().s;
            odw[q.top().s]=1;
            q.pop();
        }
    }
    printf("%d",wynik);

    return 0;
}
