#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

lld n,ilenp,ktnp;
lld tab[MAX],suma;

lld pot(lld co){
    lld wyn=0;
    while(co%2==0){
        wyn++;
        co>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        suma+=tab[i];
    }
    if(n==1){
        if(suma%2==0){
            printf("ADAM");
        }else{
            printf("JAN");
        }
    }else{
    if(n%2&&(suma)%2==0){
        printf("ADAM");
    }else if(n%2&&(suma)%2){
        int czy=1;
        int ile=0;
        while (czy){
                //cout<<"A";
            ilenp=0;
            ktnp=0;
            for(int i=0;i<n;++i){
                if(tab[i]==1){
                    czy=0;
                    ilenp=0;
                    break;
                }
                if(tab[i]%2==1){
                    ilenp++;
                    ktnp=i;
                }

            }
            if(ilenp==1){
                tab[ktnp]--;
                suma--;
                lld maxi=pot(suma);
                //cout<<maxi;
                for(int i=0;i<n;++i){
                    if(pot(tab[i])<maxi){
                        czy=0;
                    }
                }
            }else{
                czy=0;
            }
            if(czy){
                lld GCD=tab[0];
                for(int i=1;i<n;++i){
                    GCD=__gcd(GCD,tab[i]);
                }
                for(int i=1;i<n;++i){
                    tab[i]=tab[i]/GCD;
                    //cout<<tab[i]<<" ";
                }
                //cout<<endl;
                suma=suma/GCD;
                ++ile;
            }
        }
        if(ile%2==1){
            printf("ADAM");
        }else{
            printf("JAN");
        }
    }else if(n%2==0&&suma%2==1){
        printf("ADAM");
    }else{
        printf("JAN");
    }
    }

    return 0;
}
