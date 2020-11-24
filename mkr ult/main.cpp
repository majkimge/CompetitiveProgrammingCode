#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define pb push_back
#define pii pair<lld,lld>
#define MAX 100009
#define INF 2000000000

using namespace std;

lld n,wyn,czyk,mini=INF,nadto,t;
lld tab[MAX];
lld temp[MAX];
vector<pii> v;
priority_queue<pii> q;

lld check(lld gr){
    lld ilet=0;
    temp[0]=tab[0];
    v.clear();
    for(int i=1;i<n;++i){
        temp[i]=tab[i];
        if(tab[i]>temp[i-1]+gr){
            //ilet+=tab[i]-temp[i-1]-gr;
            temp[i]=temp[i-1]+gr;
        }
    }
    for(int i=n-2;i>=0;--i){
        if(temp[i]>temp[i+1]+gr){
            //ilet+=tab[i]-temp[i-1]-gr;
            temp[i]=temp[i+1]+gr;

        }
        ilet+=tab[i]-temp[i];
    }
    ilet+=tab[n-1]-temp[n-1];
    //cout<<ilet<<endl;
    if(ilet<=t)return 1;
    return 0;
}

void bin(){
    lld l=0;
    lld p=1000000001;
    lld s=(l+p)/2;
    while(l<=p){
        s=(l+p)/2;
        if(check(s)){
            wyn=s;
            p=s-1;
        }else{
            l=s+1;
        }

    }
}

int main()
{
    scanf("%lld%lld",&n,&t);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        mini=min(mini,tab[i]);
    }
        bin();
        //cout<<wyn;
        check(wyn);
        nadto=0;
        for(int i=n-1;i>=0;--i){
            q.push(mp(temp[i],i));
            nadto+=tab[i]-temp[i];
        }
        //cout<<nadto;
        /*for(int i=0;i<n;++i){
            printf("%lld ",temp[i]);
        }
        cout<<endl;*/
        lld doile=(t-nadto)/n;
        for(int i=n-1;i>=0;--i){
            //q.push(mp(temp[i],i));
            temp[i]-=doile;
        }
        nadto+=doile*n;
        //cout<<nadto;
        for(int i=nadto+1;i<=t;++i){
            pii terr=q.top();
            q.pop();
            temp[terr.s]--;
            terr.f--;
            q.push(terr);
        }
        //printf("%lld\n",wyn);
        for(int i=0;i<n;++i){
            printf("%lld ",temp[i]);
        }
    return 0;
}
/*
2 1000000000
999999999 900000000
*/
