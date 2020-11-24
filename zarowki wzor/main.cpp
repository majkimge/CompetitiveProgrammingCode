#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 200009
#define pii pair<int,int>
#define MOD 1000000007
#define NAD 500000004

using namespace std;

lld n,k,tab[MAX],a,ilel[MAX],ilep[MAX],wyny[MAX],dwumix[MAX];

vector<pair<lld,lld> > coki[MAX];

priority_queue<pair<lld,lld> >q,q1;

lld pot(lld co, lld dok){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;
    }
    lld temp=pot(co,dok-1);
    return (temp*co)%MOD;
}

lld sil[MAX];
lld odwsil[MAX];

lld odwr(lld co){
    return pot(co,MOD-2);
}

lld dwum(lld d, lld g){
    return (((sil[g]*odwsil[d])%MOD)*odwsil[g-d])%MOD;
}

lld odwum(lld d, lld g){
    return (((odwsil[g]*sil[d])%MOD)*sil[g-d])%MOD;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    sil[0]=1;

    for(int i=1;i<=n;++i){
        sil[i]=sil[i-1]*i;
        sil[i]%=MOD;
    }
    odwsil[n]=pot(sil[n],MOD-2);
    for(int i=n-1;i>=0;--i){
        odwsil[i]=odwsil[i+1]*(i+1);
        odwsil[i]%=MOD;
    }//cout<<odwsil[0];
    for(int i=1;i<=n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=n;i>0;--i){
        while(!q.empty()&&q.top().f>tab[i]){
            int ter=q.top().f;
            int il=1;
            q.pop();
            while(!q.empty()&&q.top().f==ter){
                ++il;
                q.pop();
            }
            coki[i].pb(mp(ter,il));
        }
        q.push(mp(tab[i],i));
    }
    int lim=MAX;
    /*for(int i=1;i<=n;++i){
        for(int j=0;j<coki[i].size();++j){
            cout<<coki[i][j].f<<" ";
        }
        cout<<endl;
    }*/
    for(int i=2;i<=n;++i){
        lld lim=min(tab[i],lim);
        if(lim>=tab[i]){
            ilep[tab[i]]++;
        }
    }
    /*for(int i=1;i<=n;++i){
        cout<<ilep[i]<<endl;
    }*/
    for(int i=1;i<=n;++i){
        dwumix[i]=1;
    }
    wyny[1]=1;
    wyny[n]=1;

    for(int i=2;i<n;++i){
        lld wynik=wyny[i-1];
        while(!q1.empty()&&q1.top().f>tab[i-1]){
            int ter=q1.top().f;
            int il=1;
            q1.pop();
            while(!q1.empty()&&q1.top().f==ter){
                ++il;
                q1.pop();
            }
            wynik*=odwum(ilel[ter],ilel[ter]+ilep[ter]);
            wynik%=MOD;
            ilel[ter]=0;
        }

        q1.push(mp(tab[i-1],i-1));
        wynik*=odwum(ilel[tab[i-1]],ilel[tab[i-1]]+ilep[tab[i-1]]);
        wynik%=MOD;
        ilel[tab[i-1]]++;
        wynik*=dwum(ilel[tab[i-1]],ilel[tab[i-1]]+ilep[tab[i-1]]);
        wynik%=MOD;
        for(int j=0;j<coki[i].size();++j){
            wynik*=odwum(ilel[coki[i][j].f],ilel[coki[i][j].f]+ilep[coki[i][j].f]);
            wynik%=MOD;
            ilep[coki[i][j].f]+=coki[i][j].s;
            wynik*=dwum(ilel[coki[i][j].f],ilel[coki[i][j].f]+ilep[coki[i][j].f]);
            wynik%=MOD;
        }
        wynik*=odwum(ilel[tab[i]],ilel[tab[i]]+ilep[tab[i]]);//cout<<dwum(ilel[tab[i]],ilel[tab[i]]+ilep[tab[i]]);
        wynik%=MOD;
        ilep[tab[i]]--;
        wynik*=dwum(ilel[tab[i]],ilel[tab[i]]+ilep[tab[i]]);
        wynik%=MOD;
        wyny[i]=wynik;
    }
    for(int xd=0;xd<k;++xd){
        scanf("%lld",&a);
        printf("%lld\n",wyny[a]);
    }
    return 0;
}
