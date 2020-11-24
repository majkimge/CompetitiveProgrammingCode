#include <bits/stdc++.h>

#define MAX 100002
using namespace std;

int n;
vector<int> kraw[MAX];
int q;
int w,w1;
int wojt[MAX];
int mat[MAX];
int odw[MAX];
int gleb[MAX];
int Modw[MAX];
int Mgleb[MAX];
int Wodw[MAX];
int Wgleb[MAX];
int Sodw[MAX];
int Sgleb[MAX];
int Mprzed[MAX];
int naj=0;
int boi=0;
void dfs(int x, int glebo){
    //cout<<"B";
    odw[x]=1;
    gleb[x]=glebo;
    for(int i=0;i<kraw[x].size();i++){
        //cout<<"B";
        if(odw[kraw[x][i]]==0){
            dfs(kraw[x][i],glebo+1);
        }
    }

}
void Mdfs(int x, int glebo){
    Modw[x]=1;
    Mgleb[x]=glebo;
    for(int i=0;i<kraw[x].size();i++){
        if(Modw[kraw[x][i]]==0){
            Mprzed[kraw[x][i]]=x;
            Mdfs(kraw[x][i],glebo+1);
        }
    }

}
void Wdfs(int x, int glebo){
    Wodw[x]=1;
    Wgleb[x]=glebo;
    for(int i=0;i<kraw[x].size();i++){
        if(Wodw[kraw[x][i]]==0){
            Wdfs(kraw[x][i],glebo+1);
        }
    }

}
void Sdfs(int x, int glebo){
    Sodw[x]=1;
    Sgleb[x]=glebo;
    for(int i=0;i<kraw[x].size();i++){
        if(Sodw[kraw[x][i]]==0&&kraw[x][i]!=Mprzed[x]){
            //cout<<"B:";
            Sdfs(kraw[x][i],glebo+1);
        }
    }

}
int main()
{

    scanf("%i",&n);
    for(int i=0;i<n-1;i++){
        scanf("%i",&w);
        scanf("%i",&w1);
        if(w1-w!=1||w1-w!=-1){
            boi++;
        }
        kraw[w].push_back(w1);
        kraw[w1].push_back(w);
    }

    scanf("%i",&q);
    for(int i=0;i<q;i++){
        scanf("%i",&mat[i]);
        scanf("%i",&wojt[i]);
    }
    dfs(1,0);
    for(int i=0;i<q;i++){
        naj=0;
        if(i==0){
        Mdfs(mat[i],0);
        Wdfs(wojt[i],0);
        }else {
            if(mat[i]!=mat[i-1]) {
                    for(int z=0;z<=n;z++){
                        Modw[z]=0;
                        Mprzed[z]=0;
                    }
                    Mdfs(mat[i],0);
            }
            if(wojt[i]!=wojt[i-1]){
                    for(int z=0;z<=n;z++){
                        Wodw[z]=0;
                    }
                Wdfs(wojt[i],0);
            }
        }
        for(int i=1;i<=n;i++){
            //cout<<Wgleb[i]<<Mgleb[i];
            if(Wgleb[i]==Mgleb[i]-1||Wgleb[i]==Mgleb[i]-2){
                for(int z=0;z<=n;z++){
                    Sodw[z]=0;
                    Sgleb[z]=0;
                }
                Sdfs(i,Mgleb[i]);
                for(int i=0;i<n;i++){
                        //cout<<Sgleb[i];
                    if(Sgleb[i]>naj){
                        naj=Sgleb[i];
                    }
                }
            }
        }
        if(boi>0){
        printf("%i\n",naj);
        }else{
        printf("%i\n",naj+1);
        }
    }
    return 0;
}
