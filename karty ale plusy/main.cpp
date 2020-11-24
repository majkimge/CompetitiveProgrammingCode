#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MOD 1000000007
#define MAX 300009

using namespace std;

int n,kk=1,wynik=0;
char tab1[2009][2009];
int inty[2009][2009];

int vtree[2009][5000];
int htree[2009][5000];

void add(int h,int v,int co){
    int hh=h+kk;
    while(hh>0){
        htree[v][hh]+=co;
        hh>>=1;
    }
    int vv=v+kk;
    while(vv>0){
        vtree[h][vv]+=co;
        vv>>=1;
    }
}

int hcheck(int l,int p,int v){
    int suma=0;
    l+=kk;
    p+=kk;
    if(l==p){
        suma+=htree[v][l];
    }else{
        suma+=htree[v][l]+htree[v][p];
    }
    while(l/2!=p/2){
        if(l%2==0){
            suma+=htree[v][l+1];
        }
        if(p%2==1){
            suma+=htree[v][p-1];
        }
        l>>=1;
        p>>=1;
    }
    return suma;
}

int vcheck(int l,int p,int h){
    int suma=0;
    l+=kk;
    p+=kk;
    if(l==p){
        suma+=vtree[h][l];
    }else{
        suma+=vtree[h][l]+vtree[h][p];
    }
    while(l/2!=p/2){
        if(l%2==0){
            suma+=vtree[h][l+1];
        }
        if(p%2==1){
            suma+=vtree[h][p-1];
        }
        l>>=1;
        p>>=1;
    }
    return suma;
}

int hbin(int h,int v){
    int l=0;
    int p=min(h,n-h);
    //int pp=min(2000-h,2000-v);
    //p=min(p,pp);
    int s=(l+p)/2;
    int wyn=0;
    while(l<=p){
        s=(l+p)/2;
        if(hcheck(h-s,h+s,v)==1){
            l=s+1;
            wyn=s;
        }else{
            p=s-1;
        }
    }
    return wyn;
}

int vbin(int h,int v){
    int l=0;
    int p=min(n-v,v);
    //int pp=min(2000-h,2000-v);
    //p=min(p,pp);
    int s=(l+p)/2;
    int wyn=0;
    while(l<=p){
        s=(l+p)/2;
        if(vcheck(v-s,v+s,h)==1){
            l=s+1;
            wyn=s;
        }else{
            p=s-1;
        }
    }
    return wyn;
}

int main()
{
    while(kk<2000){
        kk<<=1;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;++i){

            scanf("%s",&tab1[i]);

    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            inty[i][j]=(int)(tab1[i][j-1]-'0');

            add(j,i,(inty[i][j]));
        }
        //cout<<hcheck(1,5,i);
        //cout<<endl;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(inty[i][j]){

                int dl=1;
                int maxdl=2000;
                int w=0;
                while(hcheck(j-dl,j+dl,i)==2*dl+1&&vcheck(i-dl,i+dl,j)==2*dl+1&&i-dl>0&&i+dl<=n&&j+dl<=n&&j-dl>0&&dl<=maxdl){//cout<<"F";
                    maxdl=min(hbin(j,i+dl),hbin(j,i-dl));

                    int tt=min(vbin(j+dl,i),vbin(j-dl,i));//cout<<tt;
                    maxdl=min(maxdl,tt);

                    if(dl>maxdl){
                        w=1;
                        //cout<<"X";
                    }
                    dl++;
                }
                if(w)dl--;
                dl=dl-1;
                wynik+=dl;
            }
        }
    }
    printf("%d",wynik);
    return 0;
}
