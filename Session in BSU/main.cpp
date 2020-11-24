#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009
#define INF 1000000009

using namespace std;

int n,a,b,wyn=0;
int kt=1;
int odw[MAX];
int odw1[MAX];
int wyny[MAX];
int war[MAX];
vector<int> dodni[MAX];
pair<int,int> tab[MAX];
//pair<int,int> tab1[MAX];
int m[MAX];
map<int,int> m1;
//vector<int> zapy;

int skoj(int from){
      // cout<<from;

        //cout<<from;
        odw[from]=kt;
        for(int i=0;i<dodni[from].size();++i){
            if(m[dodni[from][i]]==-1){
                m[dodni[from][i]]=from;
                wyn++;
                return 1;
            }
        }

        for(int i=0;i<dodni[from].size();++i){
            if(!odw1[from]&&odw[m[dodni[from][i]]]<kt&&skoj(m[dodni[from][i]])){
                m[dodni[from][i]]=from;
                return 1;
            }
        }




    odw1[from]=1;
    return 0;

}



int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        tab[i]=mp(b,a);
//        tab1[i]=mp(a,b);
        war[i*2]=a;
        war[i*2+1]=b;

    }
    //sort(tab,tab+n);
//    sort(tab1,tab1+n);
    sort(war,war+2*n);
    for(int i=0;i<2*n;++i){
        m1[war[i]]=i;
        m[i]=-1;
        //cout<<war[i];
    }
    for(int i=0;i<n;++i){
        tab[i].f=m1[tab[i].f];
        tab[i].s=m1[tab[i].s];
        dodni[tab[i].f].pb(i);
        dodni[tab[i].s].pb(i);
    }

    for(int i=0;i<2*n;++i){
        skoj(i);
        kt++;
        if(wyn==n){
            printf("%d",war[i]);
            break;
        }
    }
    if(wyn<n){
        printf("-1");
    }
    return 0;
}
