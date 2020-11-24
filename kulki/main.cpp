#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,q,root,temp,co,k,x,k1=1,kolejnosc,tw;

vector<pair<lld,lld> >kraw[MAX];
vector<pair<lld,lld> > leaf;
bool odw[MAX];
bool odw1[MAX];
lld gleb[MAX];
lld ilesyn[MAX];
lld LCA[LOG][MAX];
lld tree[MAX*6];
lld najm[MAX];
lld kolej[MAX];
lld kolej1[MAX];
bool kulka[MAX];
pair<lld,lld> zakresy[MAX];

pair<lld,lld> dfs(lld a,lld g){
    pair<lld,lld> para;
    odw[a]=1;
    gleb[a]=g;
    najm[a]=INF;
    for(int i=0;i<kraw[a].size();++i){
        if(!odw[kraw[a][i].s]){
            para=dfs(kraw[a][i].s,g+1);
            ilesyn[a]+=para.f+1;
            najm[a]=min(najm[a],para.s);
            kraw[a][i]=mp(para.s,kraw[a][i].s);
        }
    }
    /*if(ilesyn[a]==0){
        leaf.pb(mp(najm[a],a));
    }*/

    return mp(ilesyn[a],min(najm[a],a));
}

void tdfs(lld a){
    odw1[a]=1;
    sort(kraw[a].begin(),kraw[a].end());
     for(int i=0;i<kraw[a].size();++i){
        if(!odw1[kraw[a][i].s]){
            tdfs(kraw[a][i].s);
        }

    }
    kolej[kolejnosc]=a;
    kolej1[a]=kolejnosc;
        kolejnosc++;
}

void dodaj(lld gdz,lld czego){
    lld gdz1=gdz+k1;
    tree[gdz1]+=czego;
    gdz1>>=1;
    while(gdz1>0){
        tree[gdz1]=min(tree[gdz1*2],tree[gdz1*2+1]);
        gdz1>>=1;
    }
}

lld spad(lld x1){
    lld x2=x1;
    lld wyn=0;
    for(int i=17;i>=0;i--){
        if(kulka[LCA[i][x2]]){
            x2=LCA[i][x2];
            wyn+=pow(2,i);
        }
    }
    kulka[x2]=0;
    dodaj(kolej1[x2],-1);

    return wyn;
//    leaf.pb(x1);
}


/*lld check(lld a,lld b){
    lld a1=a+k1;
    lld b1=b+k1;
    lld wyn=0;

    if(a1!=b1){
        wyn+=tree[a1];
        wyn+=tree[b1];
    }else{
        wyn+=tree[a1];
    }
    while(a1/2!=b1/2){
        if(a1%2==0){
            wyn+=tree[a1+1];
        }
        if(b1%2==1){
            wyn+=tree[b1-1];
        }
        a1>>=1;
        b1>>=1;
    }
    return wyn;
}*/

lld check(){
    //lld wyn=0;
    lld tr=1;
    while(tr<k1){
        if(tree[tr*2]==0){
            tr=tr*2;
        }else{
            tr=tr*2+1;
        }
    }
    tr=tr-k1;
    dodaj(tr,1);
    kulka[kolej[tr]]=1;

    return kolej[tr];

}

/*lld bin(){
    lld l=0;
    lld p=n-1;
    lld wyn=1000000;
    lld s=(l+p)/2;
    while(p>=l){
        s=(l+p)/2;
        if(check(0,s)==s&&check(s,s)==0){
            //cout<<tree[<<s<<" "<<check(0,s)<<" "<<l<<" "<<p<<endl;
            wyn=s;
            break;

        }else if(check(0,s)<=s){
            //cout<<"B"<<s<<" "<<check(0,s)<<" "<<l<<" "<<p<<endl;
            p=s-1;
        }else{
            l=s+1;
        }
    }

    dodaj(wyn,1);
    kulka[kolej[wyn]]=1;

    return kolej[wyn];
}*/

void dodajkule(lld k2){
    lld c1=0;
    for(int i=0;i<k2;++i){
        c1=check();
    }
    printf("%lld\n",c1);
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&q);
    while(k1<n){
        k1<<=1;
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&temp);
        if(temp!=0){
            //kraw[i].pb(mp(0,temp));
            kraw[temp].pb(mp(0,i));
            LCA[0][i]=temp;
        }else{
            root=i;
            LCA[0][i]=0;
        }
    }
    /*for(int i=0;i<q;++i){
        scanf("%lld",&co)
    }*/
    dfs(root,1);
    tdfs(root);
    //for(int i=1;i<=n;++i){
        //cout<<i<<ilesyn[i]<<endl;
   // }
    for(int i=1;i<LOG;++i){
        for(int x1=1;x1<=n;++x1){
            LCA[i][x1]=LCA[i-1][LCA[i-1][x1]];
        }
    }

    /*for(int i=0;i<n;++i){
        cout<<kolej[i];
    }*/

    for(int i=0;i<q;++i){
        scanf("%lld",&co);
        scanf("%lld",&x);
        if(co==1){
            dodajkule(x);
        }else{
            tw=spad(x);
            printf("%lld\n",tw);
        }
    }


    return 0;
}
