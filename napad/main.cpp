#include <bits/stdc++.h>
#define lld long long
#define ld double
#define MAX 100009
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,a,b,w,wyn;
vector<pair<lld,lld> > kraw[MAX];
vector<lld> wwyny;
vector<lld> wynydla[MAX];
lld odw[MAX];
lld ilesyn[MAX];
lld gleby[MAX];
lld wyny[MAX];
lld turwyny[MAX];
lld usuny[MAX];
//lld centry;

lld binodj(lld co,lld odj){
    lld l=0;
    lld wynik=INF;
    lld p=wynydla[odj].size()-1;
    lld s=(l+p)/2;
    while(l<=p){
        s=(l+p)/2;
        if(wynydla[odj][s]>=co){
            wynik=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    if(wynik>wynydla[odj].size()){
        return 0;
    }else{
        return wynydla[odj].size()-wynik;
    }
}

lld bindod(lld co){
    lld l=0;
    lld wynik=INF;
    lld p=wwyny.size()-1;
    lld s=(l+p)/2;
    while(l<=p){
        s=(l+p)/2;
        if(wwyny[s]>=co){
            wynik=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    if(wynik>wwyny.size()){
        return 0;
    }else{
        return wwyny.size()-wynik;
    }
}


lld dfs(lld a1,lld gleb){
    odw[a1]=1;
    //gleby[a1]=gleb;
    lld sy=0;
    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i].f]&&usuny[kraw[a1][i].f]==0){

            //wyn++;
            sy+=dfs(kraw[a1][i].f,gleb+1);
        }
    }
    ilesyn[a1]=sy;
    return sy+1;
}

lld findcentr(lld a1,lld wlk){
    odw[a1]=1;
    lld tur=0;
    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i].f]&&ilesyn[kraw[a1][i].f]>wlk/2&&usuny[kraw[a1][i].f]==0){

            return findcentr(kraw[a1][i].f, wlk);
            tur++;
        }
    }
    if(!tur){

        lld centry=a1;
    //cout<<centry;

        wyny[a1]=INF;
        //cout<<"CENR"<<centry<<endl;
        return centry;
    }

}

void dfs2(lld a1,lld gleb){
    odw[a1]=1;
    gleby[a1]=gleb;
    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i].f]&&usuny[kraw[a1][i].f]==0){

           dfs2(kraw[a1][i].f,gleb+1);
        }
    }

}

void dfs1(lld a1,lld ociec){

    odw[a1]=1;
    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i].f]&&usuny[kraw[a1][i].f]==0){
            wyny[kraw[a1][i].f]=min(wyny[a1],kraw[a1][i].s-gleby[a1]-1);
            //cout<<kraw[a1][i].f<<" "<<wyny[kraw[a1][i].f]<<endl;
            wwyny.pb(wyny[kraw[a1][i].f]);
            if(ociec==0){
                wynydla[kraw[a1][i].f].pb(wyny[kraw[a1][i].f]);
                dfs1(kraw[a1][i].f,kraw[a1][i].f);
            }else{
                wynydla[ociec].pb(wyny[kraw[a1][i].f]);
                dfs1(kraw[a1][i].f,ociec);
            }


        }
    }
}

void dfs3(lld a1,lld ociec,lld mini,lld centry){
    lld mini1;
    odw[a1]=1;
    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i].f]&&usuny[kraw[a1][i].f]==0){
            if(wyny[kraw[a1][i].f]>=0){
                turwyny[centry]++;
            }
            if(gleby[kraw[a1][i].f]<=mini){
                turwyny[kraw[a1][i].f]++;
            }
            if(ociec==0){
                turwyny[kraw[a1][i].f]+=bindod(gleby[kraw[a1][i].f])-binodj(gleby[kraw[a1][i].f],kraw[a1][i].f);
                //cout<<kraw[a1][i].f<<" "<<turwyny[kraw[a1][i].f]<<" "<<binodj(gleby[kraw[a1][i].f],kraw[a1][i].f)<<endl;
                dfs3(kraw[a1][i].f,kraw[a1][i].f,min(mini,gleby[a1]+kraw[a1][i].s),centry);
            }else{
                turwyny[kraw[a1][i].f]+=bindod(gleby[kraw[a1][i].f])-binodj(gleby[kraw[a1][i].f],ociec);
                //cout<<kraw[a1][i].f<<" "<<turwyny[kraw[a1][i].f]<<" "<<binodj(gleby[kraw[a1][i].f],ociec)<<endl;
                dfs3(kraw[a1][i].f,ociec,min(mini,gleby[a1]+kraw[a1][i].s),centry);
            }


        }
    }
}


void turbix(lld a1,lld wlk,lld c){
    if(wlk==0){
        usuny[a1]=1;
        //cout<<"B";
        return;
    }
    //cout<<"C"<<a1;
    //cout<<usuny[3];
    fill(gleby,gleby+n+1,0);
    fill(ilesyn,ilesyn+n+1,0);
    fill(wyny,wyny+n+1,0);
    fill(odw,odw+n+1,0);
    dfs(a1,0);
    fill(odw,odw+n+1,0);
lld centry=findcentr(a1,wlk);
//cout<<centry;
    fill(odw,odw+n+1,0);
    fill(gleby,gleby+n+1,0);
    dfs(centry,0);
    fill(odw,odw+n+1,0);
    dfs2(centry,0);
    fill(odw,odw+n+1,0);
    dfs1(centry,0);
    fill(odw,odw+n+1,0);
    sort(wwyny.begin(),wwyny.end());
    for(int i=1;i<=n;++i){
        //cout<<ilesyn[i];
    }
    for(int i=0;i<=c;++i){
        sort(wynydla[i].begin(),wynydla[i].end());
    }
    /*for(int i=0;i<=c;++i){
        for(int j=0;j<wynydla[i].size();++j){
            cout<<i<<" "<<wynydla[i][j];
        }
        cout<<endl;
    }*/
    //cout<<centry;
usuny[centry]=1;
    dfs3(centry,0,INF,centry);
    fill(odw,odw+n+1,0);

    wwyny.clear();
    for(int i=0;i<=c;++i){
        wynydla[i].clear();
    }
//cout<<"B"<<kraw[centry].size();
    for(int i=0;i<kraw[centry].size();++i){
        if(usuny[kraw[centry][i].f]==0){
            turbix(kraw[centry][i].f,wlk/2,c);
        }
    }

}



int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n-1;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&w);
        kraw[a].pb(mp(b,w));
        kraw[b].pb(mp(a,w));
    }

    /*dfs(1,0);
    fill(odw,odw+n+1,0);*/
    turbix(1,n,n);
    for(int i=1;i<=n;++i){

        printf("%lld\n",turwyny[i]+1);
    }
    return 0;
}
