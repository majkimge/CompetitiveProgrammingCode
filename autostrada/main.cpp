#include <bits/stdc++.h>

#define lld long long
#define N 100002
#define MLD 100000000000
using namespace std;

int n;
int m;
vector<int> kraw[N];
queue <int> kol;
int odw[N];
int gleb[N];
int odl[N];
int stop[N];
int krawz1[N];
int jednostop=0;
int wynik=0;
int odwiedzone=0;
int w,w1;
int temp,temp1,tem,tem1,temp2,temp3;
//make_pair(<int>,<int>);
void bfs(){
    while(!kol.empty()){
        int x=kol.front();
        kol.pop();
odwiedzone++;
        //stop[x]=kraw[x].size();
        if(stop[x]==1){
            krawz1[kraw[x][0]]=1;
        }
        for(int i=0;i<kraw[x].size();i++){
            if(odl[x]+1<odl[kraw[x][i]]){
                odl[kraw[x][i]]=odl[x]+1;
                kol.push(kraw[x][i]);
            }
        }
    }
}
int main()
{
    scanf("%i",&n);
    scanf("%i",&m);
    for(int i=0;i<=n;i++){
        odl[i]=MLD;
    }
    for(int i=0;i<m;i++){
        scanf("%i",&w);
        scanf("%i",&w1);
        kraw[w].push_back(w1);
        kraw[w1].push_back(w);
    }
    odl[1]=0;
    kol.push(1);
    bfs();
    //cout<<odwiedzone;
    for(int i=0;i<=n;i++){
        stop[i]=kraw[i].size();
    }
    for(int i=0;i<=n;i++){
        if(stop[i]==1){
            jednostop++;
        }
    }
    wynik+=jednostop*m-(jednostop*(jednostop+1)/2);
    for(int i=0;i<=n;i++){
        //cout<<stop[i];
        if(stop[i]==2&&krawz1[i]==0){
                //cout<<"B";
            wynik++;
        }
    }
    for(int i=0;i<=n;i++){
        //odwiedzone=0;
        if(stop[i]>2&&krawz1[i]==0){

            for(int k=0;k<kraw[i].size();++k){
                temp=kraw[i][k];
                kraw[i][k]=i;
                for(int q=0;q<kraw[kraw[i][k]].size();++q){

                    if(kraw[kraw[i][k]][q]==i){//cout<<"BOI";
                        tem=q;
                        kraw[kraw[i][k]][q]=kraw[i][k];
                        break;
                    }
                }
                //cout<<"M";
                if(k<kraw[i].size()-1){
                for(int p=i;p<=n;p++){
                    if(stop[p]>2&&krawz1[p]==0){
                        if(p>i){
                            for(int z=0;z<kraw[p].size();++z){
                                temp1=kraw[p][z];
                                kraw[p][z]=p;
                                for(int l=0;l<kraw[kraw[p][z]].size();++l){
                                    if(kraw[kraw[p][z]][l]==p){
                                        tem1=l;
                                        kraw[kraw[p][z]][l]=kraw[p][z];
                                        break;
                                    }
                                }

                                kol.push(1);
                                odwiedzone=0;
                                for(int i=0;i<n;i++){
                                    odl[i]=MLD;
                                }
                                odl[1]=0;
                                bfs();
                                //cout<<odwiedzone;
                                if(odwiedzone<=n-1){
                                    wynik++;
                                }
                                kraw[p][z]=temp1;
                                kraw[kraw[p][z]][tem1]=p;
                            }
                        }else{
                            for(int z=k+1;z<kraw[p].size();++z){
                                temp1=kraw[p][z];
                                kraw[p][z]=p;
                                for(int l=0;l<kraw[kraw[p][z]].size();++l){
                                    if(kraw[kraw[p][z]][l]==p){
                                        tem1=l;
                                        kraw[kraw[p][z]][l]=kraw[p][z];
                                        break;
                                    }
                                }
                                kol.push(1);
                                odwiedzone=0;
                                for(int i=0;i<n;i++){
                                    odl[i]=MLD;
                                }
                                odl[1]=0;
                                bfs();
                                //cout<<odwiedzone;
                                if(odwiedzone<=n-1){
                                    wynik++;
                                }
                                kraw[p][z]=temp1;
                                kraw[kraw[p][z]][tem1]=p;
                            }
                        }

                    }
                }
                }else{
                for(int p=i+1;p<=n;p++){
                    if(stop[p]>2&&krawz1[p]==0){
                        if(p>i){
                            for(int z=0;z<kraw[p].size();++z){
                                temp1=kraw[p][z];
                                kraw[p][z]=p;
                                for(int l=0;l<kraw[kraw[p][z]].size();++l){
                                    if(kraw[kraw[p][z]][l]==p){
                                        tem1=l;
                                        kraw[kraw[p][z]][l]=kraw[p][z];
                                        break;
                                    }
                                }
                                kol.push(1);
                                odwiedzone=0;
                                for(int i=0;i<n;i++){
                                    odl[i]=MLD;
                                }
                                odl[1]=0;
                                bfs();
                                //cout<<odwiedzone;
                                if(odwiedzone<=n-1){
                                    wynik++;
                                }
                                kraw[p][z]=temp1;
                                kraw[kraw[p][z]][tem1]=p;
                            }
                        }else{
                            for(int z=k+1;z<kraw[p].size();++z){
                                temp1=kraw[p][z];
                                kraw[p][z]=p;
                                for(int l=0;l<kraw[kraw[p][z]].size();++l){
                                    if(kraw[kraw[p][z]][l]==p){
                                        tem1=l;
                                        kraw[kraw[p][z]][l]=kraw[p][z];
                                        break;
                                    }
                                }
                                kol.push(1);
                                odwiedzone=0;
                                for(int i=0;i<n;i++){
                                    odl[i]=MLD;
                                }
                                odl[1]=0;
                                bfs();
                                //cout<<odwiedzone;
                                if(odwiedzone<=n-1){
                                    wynik++;
                                }
                                kraw[p][z]=temp1;
                                kraw[kraw[p][z]][tem1]=p;
                            }
                        }

                    }
                }
                }
                kraw[i][k]=temp;
                kraw[kraw[i][k]][tem]=i;
            }
        }
    }
    printf("%i",wynik);
    return 0;
}
