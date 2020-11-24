#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009

using namespace std;

char s1[MAX];
char s2[MAX];
int c1[MAX];
int c2[MAX];
int prefy[MAX][5][2];
int n,m;
int poczpozy[5][2];
vector<int> v[5][2];
int wyn[MAX];
int wyn2[MAX];

pair<int,int> solve(int l1, int p1, int l2, int p2, int lit){
    pair<int,int> ret=mp(l1,l2);

    int ite1=0;
    int ite2=0;
    int ileb=min(prefy[p1][lit][0]-prefy[l1-1][lit][0],prefy[p2][lit][1]-prefy[l2-1][lit][1]);
    //cout<<ileb;
    if(ileb){
        if(lit==4){
            for(int i=l1;i<=p1;++i){
                if(c1[i]==lit){
                    if(ite1<ileb){
                        wyn[i]=1;
                        ret.f=i;
                        ite1++;
                    }else{
                        break;
                    }
                }
            }
            for(int i=l2;i<=p2;++i){
                if(c2[i]==lit&&ite2<ileb){
                    ret.s=i;
                    wyn2[i]=1;
                    ite2++;
                }else{
                    break;
                }
            }
            return ret;
        }else{
            int do1=v[lit][0][prefy[p1][lit][0]-ileb];
            int od1=l1;
            int do2=v[lit][1][prefy[p2][lit][1]-ileb];
            //cout<<do1;
            int od2=l2;
            pair<int,int> tempor=solve(od1,do1,od2,do2,lit+1);
            for(int i=0;i<ileb-1;++i){
                while(c1[tempor.f]!=lit||wyn[tempor.f]) tempor.f++;
                while(c2[tempor.s]!=lit||wyn2[tempor.s]) tempor.s++;
                wyn[tempor.f]=1;
                wyn2[tempor.s]=1;
                do1=v[lit][0][prefy[p1][lit][0]-ileb+1+i];
                od1=tempor.f;
                do2=v[lit][1][prefy[p2][lit][1]-ileb+1+i];
                od2=tempor.s;
                tempor=solve(od1,do1,od2,do2,lit+1);
            }
            while(c1[tempor.f]!=lit||wyn[tempor.f]) tempor.f++;
            while(c2[tempor.s]!=lit||wyn2[tempor.s]) tempor.s++;
            wyn[tempor.f]=1;
            wyn2[tempor.s]=1;
            tempor=solve(tempor.f,p1,tempor.s,p2,lit+1);
            return tempor;
        }
    }else if(lit!=4){
        pair<int,int> tempor=solve(l1,p1,l2,p2,lit+1);
        return tempor;
    }else{
        return mp(l1,l2);
    }

}

int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    while(s1[n]){
        n++;
    }
    while(s2[m]){
        m++;
    }

    for(int i=0;i<n;++i){
        if(s1[i]=='A'){
            c1[i+1]=1;
        }else if(s1[i]=='C'){
            c1[i+1]=2;
        }else if(s1[i]=='G'){
            c1[i+1]=3;
        }else if(s1[i]=='T'){
            c1[i+1]=4;
        }
    }

    for(int i=0;i<m;++i){
        if(s2[i]=='A'){
            c2[i+1]=1;
        }else if(s2[i]=='C'){
            c2[i+1]=2;
        }else if(s2[i]=='G'){
            c2[i+1]=3;
        }else if(s2[i]=='T'){
            c2[i+1]=4;
        }
    }

    //prefy[0][c1[0]][0]=1;
    //prefy[0][c1[0]][1]=1;
    for(int i=1;i<=n;++i){
        v[c1[i]][0].pb(i);
        prefy[i][c1[i]][0]=prefy[i-1][c1[i]][0]+1;
        for(int j=1;j<=4;++j){
            if(j!=c1[i]){
                prefy[i][j][0]=prefy[i-1][j][0];
            }
        }
    }

    for(int i=1;i<=m;++i){
        v[c2[i]][1].pb(i);
        prefy[i][c2[i]][1]=prefy[i-1][c2[i]][1]+1;
        for(int j=1;j<=4;++j){
            if(j!=c2[i]){
                prefy[i][j][1]=prefy[i-1][j][1];
            }
        }
    }
    //cout<<"A";
    solve(1,n,1,m,1);
    for(int i=1;i<=n;++i){
        if(wyn[i]) printf("%c",s1[i-1]);
    }
    return 0;
}
//GACACGAC
//ACGACGAC
