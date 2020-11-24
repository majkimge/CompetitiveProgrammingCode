#include <bits/stdc++.h>
#define lld unsigned int
#define MAX 100009
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second

using namespace std;

int t,n,w1,w2,czy;
int tab[MAX];
int p[MAX];
int np[MAX];

int v, g;

int get_int()
{
    v=0;
    g=getchar();
    while(g>47&&g<58)
    {
        v=(v<<3)+(v<<1)+g-48;
        g=getchar();
    }
    return v;
}

int main()
{
    //scanf("%d",&t);
    t=get_int();
    for(int i=0;i<t;++i){
        w1=1000000;
        w2=1000000;
        czy=0;
        //scanf("%d",&n);
        n=get_int();
        for(int j=0;j<n;++j){
            //scanf("%d",&tab[j]);
            tab[j]=get_int();
        }
        for(int j=0;j<n;++j){
            if(j%2==0){
                p[j/2]=tab[j];
            }else{
                np[j/2]=tab[j];
            }

        }
        sort(p,p+(n+1)/2);
        sort(np,np+n/2);

        for(int j=0;j<n;++j){
            //cout<<p[j/2];
            if(j%2==0){
                if(n%2==0){
                    if(p[j/2]>np[j/2]){
                        czy=1;
                        w1=j;
                        break;
                    }
                }else{
                    if(j==n-1){
                        break;
                    }
                    if(p[j/2]>np[j/2]){
                        czy=1;
                        w1=j;
                        break;
                    }
                }

            }else{
                if(n%2==1){
                    if(np[j/2]>p[j/2+1]){
                        czy=1;
                        w1=j;
                        break;
                    }
                }else{
                    if(j==n-1){
                        break;
                    }
                    if(np[j/2]>p[j/2+1]){
                        czy=1;
                        w1=j;
                        break;
                    }
                }
            }
        }
        if(czy){
            printf("Case #%d: %d\n",i+1,min(w1,w2));
        }else{
            printf("Case #%d: OK\n",i+1);
        }

    }
    return 0;
}
