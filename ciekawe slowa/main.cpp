#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 500009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

int n=1,wynik;
char s[MAX];
char s1[MAX];
lld hasze[MAX];
lld hasze1[MAX];
lld poty[MAX];
int wyny[MAX];

lld pot(lld co,lld dok){
    if(dok==0){
        return 1;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;
    }else{
        return (co*pot(co,dok-1))%MOD;
    }
}

int main()
{
    //scanf("%d",&n);
    scanf("%s",&s[1]);
    while(s[n]){
        n++;
    }
    n--;
    //cout<<n;
    for(int i=1;i<=n;++i){
        s1[n-i+1]=s[i];

    }
    for(int i=1;i<=n;++i){
        hasze[i]=(hasze[i-1]+pot(31,i)*(s[i]-'a'+1))%MOD;
    }

    for(int i=1;i<=n;++i){
        hasze1[i]=(hasze1[i-1]+pot(31,i)*(s1[i]-'a'+1))%MOD;

    }
    for(int i=0;i<=n;++i){
        poty[i]=(pot(31,i))%MOD;
    }
    //cout<<poty[2]<<"F";
    char temp=s[1];
    lld temp1;
    int czy=0;
    for(int i=1;i<=n;++i){
        if(temp!=s[i]){
            czy=1;
        }
    }
    if(!czy){
        printf("%d\n1",n);
    }else{
        czy=0;
        //cout<<(hasze[4]-hasze[2]==hasze[2]*poty[2]);
        for(int i=2;i<=n/2;++i){
            temp1=hasze[i];
            for(int j=i*2;j<=n;j+=i){
                //cout<<temp1;
                if((hasze[j]-hasze[j-i]+MOD)%MOD==(temp1*poty[j-i])%MOD){
                    //cout<<"D";
                    wyny[j-i]=1;
                    czy=1;
                }else{
                    break;
                }
            }
        }
        for(int i=2;i<=n/2;++i){
            temp1=hasze1[i];
            for(int j=i*2;j<=n;j+=i){
                if((hasze1[j]-hasze1[j-i]+MOD)%MOD==(temp1*poty[j-i])%MOD){
                        //cout<<"F";
                    wyny[n-(j-i)]=1;
                    czy=1;
                }else{
                    break;
                }
            }
        }
        if(!czy){
            printf("1\n1");
        }else{
            for(int i=1;i<=n;++i){
                if(!wyny[i]){
                    wynik++;
                }
            }
            printf("2\n%d",wynik);
        }
    }

    return 0;
}
