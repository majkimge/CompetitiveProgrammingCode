#include <bits/stdc++.h>
#define MAX 1000009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

using namespace std;

int n,k,t;
int tab[MAX];
deque<pair<int,pii> >q;

void dod(pair<int,pii> co){
    while(!q.empty()&&(co.s.f<q.back().s.f||(co.s.f==q.back().s.f&&co.s.s>=q.back().s.s))){
        q.pop_back();
    }
    q.push_back(co);
}

void usy(int dok){
    while(!q.empty()&&q.front().f<dok)q.pop_front();
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
    }
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        scanf("%d",&k);
        q.clear();
        dod(mp(1,mp(0,tab[1])));
        for(int i=2;i<=n;++i){
            pii twyn=q.front().s;
            if(i==n){
                if(twyn.s<=tab[i]){
                    printf("%d\n",twyn.f+1);
                }else{
                    printf("%d\n",twyn.f);
                }
                break;
            }
            cout<<q.front().f<<" "<<q.front().s.f<<" "<<q.front().s.s<<endl;
            if(twyn.s<=tab[i]){
                dod(mp(i,mp(twyn.f+1,tab[i])));
            }else{
                dod(mp(i,mp(twyn.f,tab[i])));
            }
            if(i==n){
                printf("%d\n",q.front().s.f);
                break;
            }else{
                usy(i-k+1);
            }
        }
    }
    return 0;
}
