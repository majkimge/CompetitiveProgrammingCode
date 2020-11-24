#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MAX1 131072

using namespace std;

bitset<MAX1> bts[8];
int n,m,wynik;
char s1[MAX];
char s2[MAX];
int temp;
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    int n=0;
    while(s1[n]){
        if(s1[n]=='A'){
            bts[0].set(n);
        }else if(s1[n]=='C'){
            bts[1].set(n);
        }else if(s1[n]=='G'){
            bts[2].set(n);
        }else if(s1[n]=='T'){
            bts[3].set(n);
        }
        n++;
    }
    int m=0;
    while(s2[m]){
        if(s2[m]=='A'){
            bts[4].set(m);
        }else if(s2[m]=='C'){
            bts[5].set(m);
        }else if(s2[m]=='G'){
            bts[6].set(m);
        }else if(s2[m]=='T'){
            bts[7].set(m);
        }
        m++;
    }
    if(n-m<100000-6250){
    for(int i=0;i<=n-m;++i){

        temp=((bts[4]&(bts[0]>>i))|(bts[5]&(bts[1]>>i))|(bts[6]&(bts[2]>>i))|(bts[7]&(bts[3]>>i))).count();
        wynik=max(wynik,temp);

    }
    }else{
        for(int i=0;i<=n-m;++i){
            temp=0;
            for(int j=0;j<m;++j){
                if(s2[j]==s1[i+j]) temp++;
            }
            wynik=max(wynik,temp);
        }
    }
    printf("%d",wynik);
    return 0;
}
