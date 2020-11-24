#include <bits/stdc++.h>
#define lld int
#define MAX 1000009
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n,m,a,v,sum,last;

lld tab[MAX];
lld drogi[MAX];
vector<pair<lld,lld> >cow;

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&v);
        scanf("%d",&a);
        tab[i]=(v-1)/a;
        //cout<<tab[i];
    }
    sort(tab,tab+n);
    last=tab[0];
    sum=1;
    if(n==1){
        cow.pb(mp(last,sum));
    }
    for(int i=1;i<n;++i){
        if(tab[i]==last&&i<n-1){
            sum++;

        }else if(tab[i]!=last||i==n-1){//cout<<tab[i]<<endl;
            if(i!=n-1){
            cow.pb(mp(last,sum));
            }else{
                if(tab[i]!=last){
                    cow.pb(mp(last,sum));
                    cow.pb(mp(tab[i],1));

                }else{
                    cow.pb(mp(last,sum+1));
                }

            }
            sum=1;
            last=tab[i];
        }
    }
    for(int i=0;i<cow.size();++i){
        //cout<<cow[i].f<<cow[i].s<<endl;
        sum=cow[i].s;
        int z=0;
        while(sum>0&&z<m){
            if(cow[i].f+1-drogi[z]<=sum){
                sum=sum-cow[i].f-1+drogi[z];
                drogi[z]=cow[i].f+1;

            }else{
                drogi[z]+=sum;
                sum=0;
            }
            z++;
        }
    }
    sum=0;
    for(int i=0;i<m;++i){
        sum+=drogi[i];
        printf("%d\n",sum);
    }

    return 0;
}

/*14 4
9 10
10 5
9 6
12 10
19 15
16 7
18 5
21 6
21 5
40 10
45 11
9 2
11 2
59 10
*/
