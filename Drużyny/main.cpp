#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define pii pair<int,int>

using namespace std;

int n,a;
pii tab[MAX];
priority_queue<pii>dr;
int wdr[MAX];
int kt;
vector<int> vdr[MAX];
int iledr[MAX];

void donajm(int zaw){
    pii ter=dr.top();
    ter.f=-ter.f;
    dr.pop();
    wdr[zaw]=ter.s;
    vdr[ter.s].pb(zaw);
    ter.f++;
    ter.f=-ter.f;
    dr.push(ter);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        tab[i]=mp(a,i);
    }
    sort(tab+1,tab+1+n);
    int ilemam=0;
    int iledrmam=0;
    for(int i=1;i<=n;++i){
        ilemam++;
        if(ilemam>=tab[i].f){
            ilemam=0;
            iledrmam++;
            iledr[i]=iledrmam;
        }
    }
    for(int i=1;i<=n;++i){
        iledr[i]=max(iledr[i],iledr[i-1]);
        //cout<<iledr[i]<<" ";
    }
    //cout<<"A";
    for(int i=n;i>=1;--i){
        //cout<<tab[i].f<<tab[i].s<<endl;
        if(tab[i].f>i||iledr[i-1]>1+iledr[max(0,i-tab[i].f)]&&i!=n){
            donajm(tab[i].s);
        }else{
            for(int j=i;j>i-tab[i].f;--j){
                wdr[tab[j].s]=kt;
                vdr[kt].pb(tab[j].s);
            }
            dr.push(mp(-tab[i].f,kt));
            ++kt;
            i=i-tab[i].f+1;
        }
    }
    printf("%d\n",dr.size());
    while(!dr.empty()){
        pii ter=dr.top();
        dr.pop();
        printf("%d ",-ter.f);
        //sort(vdr[ter.s].begin(),vdr[ter.s].end());
        for(int i=0;i<vdr[ter.s].size();++i){
            printf("%d ",vdr[ter.s][i]);
        }
        printf("\n");
    }
    return 0;
}
