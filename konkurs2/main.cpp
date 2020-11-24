#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1100

using namespace std;

int z,w,k,r,kk=1;
int tree1[MAX][MAX];
int wyniki[MAX][MAX];
int tab[MAX][MAX];
priority_queue<pair<int,int> >q;

int main()
{

    scanf("%d",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%d",&w);
        scanf("%d",&k);
        scanf("%d",&r);
        for(int i=0;i<2092;++i){
            for(int j=0;j<2092;++j){
            tab[i][j]=0;
        }
        }
        while(kk<max(w,k)){
            kk<<=1;
        }
        for(int i=0;i<w;++i){
            for(int j=0;j<k;++j){
                int temp=0;
                scanf("%d",&tab[i][j]);
                //ustaw(j,i,temp);
            }
        }

        for(int i=0;i<k;++i){
            int xj=0;
            for(int j=0;j<w;++j){
                while(xj<=r+j&&xj<w){
                    q.push(mp(tab[xj][i],xj));
                    ++xj;
                }
                while(q.top().s<j-r){
                    q.pop();
                }
                tree1[j][i]=q.top().f;
            }
            while(!q.empty()){
                q.pop();
            }
            //printf("\n");
        }
        for(int i=0;i<w;++i){
            int xj=0;
            for(int j=0;j<k;++j){
                while(xj<=r+j&&xj<k){
                    q.push(mp(tree1[i][xj],xj));
                    ++xj;
                }
                while(q.top().s<j-r){
                    q.pop();
                }
                wyniki[i][j]=q.top().f;
                printf("%d ",wyniki[i][j]);
            }
            while(!q.empty()){
                q.pop();
            }
            printf("\n");
        }

    }
    return 0;
}
