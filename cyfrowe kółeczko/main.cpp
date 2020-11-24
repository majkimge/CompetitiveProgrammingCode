#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define PIER 1400
#define pii pair<int,int>
#define MOD 1000696969

using namespace std;

int n,k,dl,dl1,xd;
lld hasze[MAX];
lld poty[MAX];
char s[MAX];
int tab[MAX];
int doso[MAX];
int cogdz[MAX],wynik;
int dp[MAX];
vector<int> gdzie;
queue<pair<int,pii> >q;

int bin(int a, int b){
    int l=0;
    int p=dl;
    int s=(l+p)/2;
    if(a>b)swap(a,b);
    int wyn=p+1;
    while(l<=p){
        s=(l+p)/2;
        int odj1=0;
        if(a)odj1=hasze[a-1];
        int odj2=0;
        if(b)odj2=hasze[b-1];
        if((((hasze[a+s]-odj1+MOD)%MOD)*poty[b-a])%MOD==(((hasze[b+s]-odj2+MOD)%MOD))){
            l=s+1;

        }else{
            p=s-1;
            wyn=s;
        }

    }
    return wyn;
}

bool cmp(int a, int b){
    int gdz=bin(a,b);
    //cout<<gdz;
    if(gdz==dl+1)return true;
    if(tab[a+gdz]>tab[b+gdz])return false;
    return true;
}


int check(int pocz, int dok){
    int ter=pocz;
    int czyk=1;
    int iledl=0;
    while(ter<n+pocz){
        //cout<<(((cogdz[ter]<=dok)||(ter+n<2*n-dl+1&&(cogdz[ter+n]<=dok)))&&iledl<xd);
        if(((cogdz[ter]<=dok)||(ter+n<2*n-dl+1&&(cogdz[ter+n]<=dok)))&&iledl<xd){
            //cout<<"X";
            ter+=dl;
            iledl++;
        }else{
            if(dl1==dl)return 0;
            ter+=dl1;
        }
    }
    if(iledl==xd)return 1;
    return 0;
}

int binwyn(int pocz){
    int l=0;
    int p=2*n-dl;
    int s=(l+p)/2;
    int wyn=p;
    while(l<=p){
        s=(l+p)/2;
        if(check(pocz,s)){
            wyn=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0;i<2*n;++i){
        tab[i]=s[i%n]-'0';
    }
    poty[0]=1;
    for(int i=1;i<MAX;++i){
        poty[i]=poty[i-1]*23;
        poty[i]%=MOD;
    }
    if(n%k==0){
        dl=n/k;

        //cout<<"X";
    }else{
        dl=n/k +1;
    }

    dl1=n/k;xd=n-k*dl1;
    //cout<<
    hasze[0]=tab[0];
    for(int i=1;i<2*n;++i){
        hasze[i]=hasze[i-1]+tab[i]*poty[i];
        hasze[i]%=MOD;
    }
    for(int i=0;i<2*n;++i){
        doso[i]=i;
    }
    sort(doso,doso+2*n-dl+1,cmp);
    //cout<<cmp(0,1);
    for(int i=0;i<2*n-dl+1;++i){
        //cout<<doso[i]<<" ";
        cogdz[doso[i]]=i;
    }
    int OST=2*n-dl;
    wynik=MOD;
    //cout<<check(0,1);
    //cout<<cogdz[1];
    if(k>PIER){
        for(int i=0;i<dl+1&&i+dl<=n;++i){
            wynik=min(wynik,binwyn(i));
        }

    }else{
        if(n%k!=0){
            for(int i=0;i<dl+2&&i+dl<=n;++i){
                q.push(mp(0,mp(i,0)));
                //gdzie.pb()
               // cout<<endl;
                while(!q.empty()){
                    int war=q.front().f;
                    int ter=q.front().s.f;
                    int wyn=q.front().s.s;
                    /*cout<<ter<<" ";
                    for(int i=0;i<dl;++i){
                        printf("%d",tab[doso[wyn]+i]);
                    }
                    cout<<endl;*/
                    q.pop();
                    if(ter==i+n&&war==k)wynik=min(wynik,wyn);
                    if(ter>=i+n||war>=k)continue;
                    q.push(mp(war+1,mp(ter+dl1,wyn)));
                    q.push(mp(war+1,mp(ter+dl,max(wyn,cogdz[ter]))));
                }

            }
        }else{
            for(int i=0;i<dl+2&&i+dl<=n;++i){
                q.push(mp(0,mp(i,0)));
                //gdzie.pb()
                while(!q.empty()){
                    int war=q.front().f;
                    int ter=q.front().s.f;
                    int wyn=q.front().s.s;
                    q.pop();
                    if(ter==i+n&&war==k)wynik=min(wynik,wyn);
                    if(ter>=i+n||war>=k)continue;
                    //q.push(mp(ter+dl1,wyn));
                    q.push(mp(war+1,mp(ter+dl,max(wyn,cogdz[ter]))));
                }
            }
        }
    }
    for(int i=0;i<dl;++i){
        printf("%d",tab[doso[wynik]+i]);
    }
    return 0;
}
