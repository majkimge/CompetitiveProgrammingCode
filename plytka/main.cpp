#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009

using namespace std;

int t,n,a,b,mrep,czy;

int tab[MAX];
int rep[MAX];
vector<int> v;
int wyny[MAX][2];

int main()
{
    scanf("%d",&t);
    for(int xa=0;xa<t;++xa){
        scanf("%d",&n);
        czy=1;
        v.clear();
        for(int i=0;i<MAX;++i){
            tab[i]=0;
            rep[i]=0;
            wyny[i][0]=wyny[i][1]=0;
        }
        for(int i=1;i<=n/2;++i){
            scanf("%d",&a);
            scanf("%d",&b);
            tab[a]=tab[b]=i;
            rep[i]=i;
        }
        mrep=tab[1];
        int kon=2;
        int ktor=1;
        while(rep[tab[kon]]==mrep){
            v.pb(kon);
            kon++;

        }
        rep[tab[kon]]=mrep;
        wyny[1][0]=1;
        wyny[1][1]=kon;
        ktor++;
        kon++;
        int moc=0;
        while(kon<=n&&ktor<n/2){
            if(v.empty()){
                moc=kon;
                kon++;
            }else{
                moc=v[v.size()-1];
                v.pop_back();
            }
            while(!((rep[tab[kon]]==mrep)^(rep[tab[moc]]==mrep))){
                v.pb(kon);
                kon++;
                if(kon>n){
                    czy=0;
                    break;
                }
            }
            if(!czy) break;
            wyny[ktor][0]=moc;
            wyny[ktor][1]=kon;
            rep[tab[kon]]=rep[tab[moc]]=mrep;

            ktor++;
            //v.pop_back();
            kon++;
        }
        int pp=0;
        for(pp=0;pp<v.size();pp++){
            wyny[ktor][pp]=v[pp];
        }
        //cout<<pp;
        if(pp==0){
            while(pp<2){
            wyny[ktor][pp]=kon+pp;
            pp++;
        }
        }else{
        while(pp<2){
            wyny[ktor][pp]=kon+pp-1;
            pp++;
        }
        }

        if(czy){
            printf("TAK\n");
            for(int i=1;i<=n/2;++i){
                printf("%d %d\n",wyny[i][0],wyny[i][1]);
            }
        }else{
            printf("NIE\n");
        }

    }
    return 0;
}
