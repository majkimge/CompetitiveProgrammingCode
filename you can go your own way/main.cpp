#include <bits/stdc++.h>
#define lld long long
#define MAX 100009

using namespace std;

int t,n,last;
char s[MAX];
char wyn[MAX];
int prefy[MAX];

int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        scanf("%d",&n);
        scanf("%s",s);
        printf("Case #%d: ",xd+1);
        if(s[0]=='E'){
            if(s[2*n-3]=='S'){
                for(int i=0;i<n-1;++i){
                    printf("S");
                }
                for(int i=0;i<n-1;++i){
                    printf("E");
                }
            }else{
                int wys=0;
                int ostw=0;
                int czy=0;
                for(int i=0;i<2*n-2;++i){
                    if(s[i]=='E')czy=1;
                    if(s[i]=='S'){
                        if(!czy){
                            ostw=wys;
                            break;
                        }else{
                            czy=0;
                            wys++;
                        }
                    }
                }
                for(int i=0;i<ostw;++i){
                    printf("S");
                }
                for(int i=0;i<n-1;++i){
                    printf("E");
                }
                for(int i=ostw;i<n-1;++i){
                    printf("S");
                }
            }
        }else{
            if(s[2*n-3]=='E'){
                for(int i=0;i<n-1;++i){
                    printf("E");
                }
                for(int i=0;i<n-1;++i){
                    printf("S");
                }
            }else{
                int wys=0;
                int ostw=0;
                int czy=0;
                for(int i=0;i<2*n-2;++i){
                    if(s[i]=='S')czy=1;
                    if(s[i]=='E'){
                        if(!czy){
                            ostw=wys;
                            break;
                        }else{
                            czy=0;
                            wys++;
                        }
                    }
                }
                for(int i=0;i<ostw;++i){
                    printf("E");
                }
                for(int i=0;i<n-1;++i){
                    printf("S");
                }
                for(int i=ostw;i<n-1;++i){
                    printf("E");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
