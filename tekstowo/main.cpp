#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696969

char s[MAX];
char temp;
int n,m,al,wyn,wynik,pocz,kon,k;
char a[MAX];
lld hasze[MAX];
lld ahasze[MAX];
lld wyny[MAX];
using namespace std;

lld pot(lld co,lld dok){
    if(dok==0){
        return 1;
    }else
    if(dok==1){
        return co;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        temp%=MOD;
        return (temp*temp)%MOD;
    }else{
        return ((pot(co,dok-1)%MOD)*co)%MOD;
    }
}

int main()
{

    scanf("%s",s);
    scanf("%d",&m);
    temp=s[0];
    n=0;
    while(temp!=0){
        n++;
        temp=s[n];
    }
    hasze[0]=s[0]-96;
    for(int i=1;i<n;++i){
        hasze[i]=(hasze[i-1]+((s[i]-96)*pot(31,i))%MOD)%MOD;
    }
    lld ost=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            ahasze[j]=0;
            a[j]=0;
            wyny[j]=0;
        }
        scanf("%d",&k);
        scanf("%s",&a);
        al=0;
        temp=a[0];
        while(temp!=0){
            al++;
            temp=a[al];
        }
        ost=al;
        ahasze[0]=a[0]-96;
        for(int j=1;j<al;++j){
            ahasze[j]=(ahasze[j-1]+((a[j]-96)*pot(31,j))%MOD)%MOD;
        }
        for(int j=al-1;j<n;++j){
            if(j!=al-1){

                if((ahasze[al-1]*pot(31,j-(al-1)))%MOD==hasze[j]-hasze[j-(al-1)-1]){

                wyny[j]=1;
            }
            }else{
                if((ahasze[al-1]*pot(31,j-(al-1)))%MOD==hasze[j]){
                wyny[j]=1;
            }
            }

        }
        pocz=0;
        kon=0;
        wyn=0;
        int czy=0;
        wynik=MOD;
        for(int i=0;i<n;++i){
            //cout<<wyny[i];
        }
        while(kon<=n&&pocz<=n){

            while(kon<=n&&wyn<k){
                wyn+=wyny[kon];
                if(wyny[kon]){
                    wyny[kon-al+1]=-1;
                }
                kon++;
            //cout<<wyn;
            }
            if(wyn>=k){
                wynik=min(wynik,kon-pocz);
                czy=1;
            }if(kon!=0){
                pocz++;
            }
            while(pocz<=n){
                if(wyny[pocz]==-1){
                    wyn--;
                    break;
                }
                pocz++;

            }
            if(wyn>=k-1){
                wynik=min(wynik,kon-pocz);
                czy=1;
            }
        }
        if(czy){
            printf("%d\n",wynik);
        }else{
            printf("-1\n");
        }

        //cout<<wynik;
    }
    //cout<<pot(n,n);

    return 0;
}
