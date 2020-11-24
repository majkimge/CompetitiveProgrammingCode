#include <bits/stdc++.h>
#define MAX 100009

using namespace std;

int tree[MAX*4];
int prefzam[MAX];
char temp[MAX];
int tab[MAX];
int n,m,k=1,x,y;

void ustaw(){
    int kk=k;
    int gdzie=kk/2;
    while(kk>0){
        gdzie=kk/2;
        while(gdzie<kk){
            tree[gdzie]=min(tree[gdzie*2],tree[gdzie*2+1]);
            gdzie++;
        }
    kk=kk/2;
    }
}

int mini(int a,int b){
    a+=k;
    b+=k;
    int wyn=min(tree[a],tree[b]);
    while(a/2!=b/2){
        if(a%2==0){
            wyn=min(wyn,tree[a+1]);
        }
        if(b%2==1){
            wyn=min(wyn,tree[b-1]);
        }
        a>>=1;
        b>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%s",temp);
    for(int i=0;i<n;++i){

        if(temp[i]=='('){
            tab[i]=1;
           }else{
            tab[i]=-1;
           }
    }
    while(k<n){
        k*=2;
    }
    tree[k]=tab[0];
    for(int i=1;i<n;++i){
        tree[k+i]=tree[k+i-1]+tab[i];
        //cout<<tree[k+i];
    }
    for(int i=n;i<k;++i){
        tree[k+i]=10000000;
    }
    if(tab[0]==-1){
        prefzam[0]=1;
    }
    for(int i=1;i<n;++i){
        prefzam[i]=prefzam[i-1];
        if(tab[i]==-1){
            prefzam[i]++;
        }
    }
    ustaw();
    for(int i=0;i<m;++i){
        scanf("%d",&x);
        scanf("%d",&y);
        if(x!=1){
            //cout<<tree[k+x-1];
            printf("%d\n",(prefzam[y-1]-prefzam[x-2]+min(0,(mini(x-1,y-1)-(tree[k+x-1]-tab[x-1]))))*2);
        }else{
            //cout<<mini(x-1,y-1);
            printf("%d\n",(prefzam[y-1]+(mini(x-1,y-1)))*2);
        }

    }
    return 0;
}
