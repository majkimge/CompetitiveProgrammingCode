#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000
using namespace std;

int n;
int tab[MAX];
int kt[MAX*20];
pair<int,int> portal;

pair<int,int> bin(int l,int p,int pier){
    int s=(l+p)/2;
    int tog=0;
    int mini=INF;
    while(l<=p&&(l+p)/2>pier){
        s=(l+p)/2;
        int tempo=0;
        if(tab[kt[(s-pier)/2+pier]]>pier&&tab[kt[(s-pier)/2+pier]]<s){
            if(tab[kt[(s-pier)/2+pier]]<=(s-pier)/2+pier){
            if(kt[(s-pier)/2+pier]+1!=n&&tab[kt[(s-pier)/2+pier]+1]<s){
                tempo=max(s-tab[kt[(s-pier)/2+pier]+1],tab[kt[(s-pier)/2+pier]]-pier);
            }else{
                tempo=max(0,tab[kt[(s-pier)/2+pier]]-pier);
            }

        }else{
            if(kt[(s-pier)/2+pier]!=0&&tab[kt[(s-pier)/2+pier]-1]>pier){
                tempo=max(s-tab[kt[(s-pier)/2+pier]],tab[kt[(s-pier)/2+pier]-1]-pier);
            }else{
                tempo=max(s-tab[kt[(s-pier)/2+pier]],0);
            }
        }
        }

        int odma=abs(tab[n-1]-s);
        //cout<<"A"<<pier<<" "<<s<<" "<<tempo<<" "<<odma;
        if(max(tempo,odma)<mini){
            tog=s;
        }
        mini=min(max(tempo,odma),mini);
        if(odma>tempo){
            l=s+1;
        }else{
            p=s-1;
        }
    }
    return mp(mini,tog);
}

int main()
{
   scanf("%d",&n);
   for(int i=0;i<n;++i){
    scanf("%d",&tab[i]);
    tab[i]+=MAX*10;
   }
   sort(tab,tab+n);
   int ter=0;
   for(int i=0;i<=MAX*20;++i){
        if(abs(tab[ter]-i)>abs(tab[min(ter+1,n-1)]-i)){
            kt[i]=min(ter+1,n-1);
            ter=min(ter+1,n-1);
        }else{
            kt[i]=ter;
        }
   }
   for(int i=MAX*10;i<=8+MAX*10;++i){
    //cout<<kt[i]<<" ";
   }
   int wyn=INF;
   for(int i=tab[0];i<=tab[n-1];++i){
        pair<int,int> tempor=bin(i,tab[n-1],i);
        if(wyn>tempor.f+i-tab[0]){
            portal=mp(i,tempor.s);
        }
    wyn=min(wyn,tempor.f+i-tab[0]);
   }
   cout<<portal.f<<" "<<portal.s;
   for(int i=0;i<n;++i){
    wyn=max(min(abs(tab[n-1]-portal.f)+abs(tab[i]-portal.s),min(tab[n-1]-tab[i],abs(tab[n-1]-portal.s)+abs(tab[i]-portal.f))),wyn);
   }
   printf("%d",wyn);
    return 0;
}
