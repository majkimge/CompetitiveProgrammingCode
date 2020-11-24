#include <bits/stdc++.h>

#define MAX 1000002
#define MOD 1000000009
#define lld long long
using namespace std;

lld a,m,n,k;
lld wynik;
lld d[MAX][3];

lld fast_pow1(lld n,lld k){
    lld w=1;
    lld last=1;
   lld i=0;
   lld tab[100];

    lld l=k;

  while(l>0)
  {

    tab[i]=l%2;
    l/=2;
    ++i;

  }

  for(lld j=0;j<i;++j){
    if(j==0){
        last=n;

        if(tab[j]==1){
            w=(last*w);
        }
    }else{
        last=((last)*(last))%MOD;

        if(tab[j]==1){
            w=(w*last)%MOD;
        }
    }
  }
  return w;
}

int main()
{
    scanf("%lld",&a);
    for(int i=0;i<a;++i){
        scanf("%lld",&d[i][0]);
        scanf("%lld",&d[i][1]);
        scanf("%lld",&d[i][2]);
        //d[i][0]=MAX;
        //d[i][1]=MAX;
        //d[i][2]=MAX;
    }
    for(int i=0;i<a;++i){
        wynik=fast_pow1(d[i][1],d[i][2]*d[i][0]);
        printf("%lld\n",wynik);
    }
    return 0;
}
