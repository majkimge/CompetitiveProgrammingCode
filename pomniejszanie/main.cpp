#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define int uint_fast32_t

using namespace std;



int t,k,n,ilep[MAX],czyk[MAX],ilem,wyn[MAX];
char s1[MAX],s2[MAX];

int32_t main()
{
    scanf("%d",&t);
    t=100;
    for(int xd=0;xd<t;++xd){
        //for(int i=1;i<=100000;++i)s1[i]=s2[i]='9';
        scanf("%s",&s1[1]);
        scanf("%s",&s2[1]);
        scanf("%d",&k);
        //k=1;
        n=1;
        while(s1[n])++n;
        --n;
        for(int i=1;i<=n;++i){
            s1[i]=s1[i]-'0';
            s2[i]=s2[i]-'0';
            ilep[i]=ilep[i-1]+(s1[i]!=s2[i]);
        }
        int ud=0;
        int im=0;
        int dod=0;
        for(int i=n;i>0;--i){
            im=i-1;
            dod=ilep[im]+n-i;
            if(s2[i] && (ilep[im]<k||(ilep[im]==k&&s1[i]<s2[i])) &&  (dod>=k|| (dod==(k-1)&&(s2[i]>1||(s2[i]==1&&s1[i]!=0))))){
                //cout<<i<<endl;
                int ilej=ilep[i-1];
                ud=1;
                for(int j=1;j<i;++j){
                    wyn[j]=s2[j];
                }
                if(ilej==k){
                    for(int j=i;j<=n;++j)wyn[j]=s1[j];
                    break;
                }
                wyn[i]=s2[i]-1;
                if(wyn[i]!=s1[i])++ilej;
                int skon=0;
                for(int j=i+1;j<=n;++j){
                    if(ilej==k){
                        for(int z=j;z<=n;++z)wyn[z]=s1[z];
                        skon=1;
                        break;
                    }
                    wyn[j]=9;
                    ilej+=(wyn[j]!=s1[j]);

                }
                if(skon)break;
                for(int j=n;j>i;--j){
                    if(ilej==k)break;
                    if(wyn[j]==s1[j]){
                        wyn[j]=8;
                        ++ilej;
                    }
                }
                if(ilej==k-1){
                    wyn[i]--;
                }
                break;
            }
        }
        if(ud){
            for(int i=1;i<=n;++i)printf("%u",wyn[i]);
            printf("\n");
        }else{
            printf("-1\n");
        }

        for(int i=1;i<=n;++i){
            s1[i]=s2[i]=wyn[i]=ilep[i]=0;
        }

    }
    return 0;
}

