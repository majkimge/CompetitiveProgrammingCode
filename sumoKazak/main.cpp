#include <bits/stdc++.h>
#define lld int
#define MAX 300009
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n,k;
vector<lld> kraw[MAX];
lld wal[MAX][2];
lld kol[MAX];
lld wynin=1;

lld dwo(lld a,lld na){


        kol[a]=na;
        for(int i=0;i<kraw[a].size();++i){
            if(kol[kraw[a][i]]!=2&&kol[kraw[a][i]]!=na^1){
                wynin=0;
                break;
            }
        }
        for(int i=0;i<kraw[a].size();++i){
            if(kol[kraw[a][i]]==2){
                //ko.push(mp(kraw[a][i],na^1));
                dwo(kraw[a][i],na^1);

            }
        }


}

lld bin(void){
    for(int i=0;i<=n;++i){
        kol[i]=2;
        kraw[i].clear();
    }
    lld l=0;
    lld p=k-1;
    lld s=(l+p)/2;
    lld wyn;
    while(l<=p){
            for(int i=0;i<=n;++i){
        kol[i]=2;
        kraw[i].clear();
    }
        s=(l+p)/2;
        for(int i=0;i<=s;++i){
            kraw[wal[i][0]].pb(wal[i][1]);
            kraw[wal[i][1]].pb(wal[i][0]);
        }
        //kol[1]=1;

        wynin=1;
        //cout<<s<<endl;
        for(int i=1;i<=n;++i){
            if(kol[i]==2){
                //ko.push(mp(i,1));
                dwo(i,1);
            }
            //dwo();
        }


        if(wynin==0){
            p=s-1;
        }else{


            wyn=s;
            l=s+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);

    for(int i=0;i<k;++i){
        scanf("%d",&wal[i][0]);
        scanf("%d",&wal[i][1]);
    }
    printf("%d",min(bin()+2,k));
    return 0;
}
