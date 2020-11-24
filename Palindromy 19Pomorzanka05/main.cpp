#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

char s[MAX];
int ss[MAX];
int dody[MAX];
int n,a,b,start,t;
vector<int> pocz[MAX];
pair<int,int> zm[MAX];
lld xd;
lld maxim;
int main()
{
    //scanf("%s",s);
    //cout<<(int)'z'-'a'+1;
    srand(time(0));
    for(int xdd=0;xdd<100;++xdd){
        for(int i=0;i<10000;++i){
        s[i]=rand()%26+'a';
    }
    while(s[n])++n;
    for(int i=0;i<n;++i){
        ss[i]=(int)s[i]-'a';
    }
    start=(n+1)/2;
    //scanf("%d",&t);
    t=100000;
    for(int i=0;i<t;++i){
        //scanf("%d%d",&a,&b);
        a=rand()%n+1;
        b=rand()%n+1;
        a--;
        b--;
        zm[i]=mp(a,b);
    }
    sort(zm,zm+t);
    for(int i=0;i<t;++i){
        if(n%2){
            if(zm[i].f==start-1){
                zm[i].f++;
            }else if(zm[i].s==start-1){
                zm[i].s--;
            }
        }
        if(zm[i].s<start-(n%2)){
            int temp=start+start-(n%2)-zm[i].s-1;
            zm[i].s=n-zm[i].f-1;
            zm[i].f=temp;
        }else if(zm[i].s>=start&&zm[i].f<start-(n%2)){
            int lr=zm[i].s-start+1;
            int ll=start-(n%2)-zm[i].f;
            zm[i].f=min(lr,ll)+start;
            zm[i].s=start+max(ll,lr)-1;
        }
    }

    for(int i=0;i<t;++i){
        if(zm[i].s>=zm[i].f){
            pocz[zm[i].f].pb(zm[i].s);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<pocz[i].size();++j){
            //cout<<i<<" "<<pocz[i][j]<<endl;
        }
    }
    for(int i=start;i<n;++i){
        int ite=0;
        int last=0;
        int firs=0;
        if(pocz[i].empty())continue;
        sort(pocz[i].begin(),pocz[i].end());
        //cout<<pocz[i].size();
        firs=pocz[i][0];
        last=pocz[i][0];
        while(ite<(int)pocz[i].size()-1&&pocz[i][ite]==pocz[i][ite+1]){
            last=pocz[i][ite];
            firs=pocz[i][ite];
            ++xd;
            ++ite;
        }//cout<<"X";
        for(int j=ite+1;j<pocz[i].size();++j){
            pocz[last+1].pb(pocz[i][j]);
            ++xd;
            while(j<(int)pocz[i].size()-1&&pocz[i][j]==pocz[i][j+1]){
                last=pocz[i][j];
                ++xd;
                ++j;
            }
        }
        pocz[i].clear();
        pocz[i].pb(firs);
    }
    int iledod=0;
    for(int i=start;i<n;++i){
        ss[i]+=iledod;
        if(!pocz[i].empty()){
            //cout<<i<<" "<<pocz[i][0]<<endl;
            iledod+=(ss[(start-n%2-1)-(i-start)]-ss[i]+26);
            dody[pocz[i][0]]+=-(ss[(start-n%2-1)-(i-start)]-ss[i]+26);
            ss[i]=ss[(start-n%2-1)-(i-start)];
        }
        iledod+=dody[i];
    }
    int wyn=1;
    for(int i=0;i<n;++i){
        if(ss[i]%26!=ss[n-1-i]%26)wyn=0;
    }
    if(wyn){
        printf("TAK");
    }else{
        printf("NIE");
    }
    for(int i=0;i<n;++i){
        dody[i]=0;
        pocz[i].clear();
    }
    n=0;
    maxim=max(maxim,xd);
    xd=0;
    }
    cout<<endl<<maxim;
    return 0;
}
