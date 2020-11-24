#include <bits/stdc++.h>

using namespace std;

int n;
int k=0;
int ile;
 int l;
        int p;
        int s;
        int odp;
int notsor[1000000];
int tab[1000000];
int sor[1000000];
long long int pref[1000000];
int pytania[1000000];
int main()
{
    scanf("%int",&n);


    for(int i=0;i<n;i++){
        scanf("%int",&tab[i]);
        notsor[tab[i]]++;
    }
    scanf("%int",&ile);

    for(int i=0;i<ile;i++){
        scanf("%int",&pytania[i]);
    }
    int k=0;
    for(int i=0;i<1000000;i++){



        for(int j=0;j<notsor[i];j++){
            sor[k]=i;
            k++;
    }

    }

    for(int i=0;i<n;i++){
        if(i==0){
            pref[i]=sor[i];
        }else{
            pref[i]=pref[i-1]+sor[i];
        }
    }
    if(n==0){
        printf("0\n");
    }
    for(int i=0;i<ile;i++){
         if(n==1){
            if(pref[0]<=pytania[i]){
                printf("1\n");
            }else{
                printf("0\n");
            }
         }else if(n>1){
         l=0;
         p=n-1;
         s=(p-l)/2;
         odp=0;

        while(l<p){
            if(pref[s]<pytania[i]){
                odp=pref[s];
                l=s+1;
                s=l+(p-l)/2;
            }else if(pref[s]>pytania[i]){

                p=s-1;
                s=p-(p-l)/2;
            }else{
                l=p;
                odp=pref[s];
            }
            if(l>=p&&pref[s]<=pytania[i]){
                odp=pref[s];
            }

        }
        printf("%i\n",odp);
         }

    }
    return 0;
}
