#include <bits/stdc++.h>

#define MAX 400002
#define MLD 1000000000
using namespace std;
int n,m,temp1,temp2,temp3,temp4,tem,tem1;
vector <int> ktore[MAX];
vector <int> all[MAX];
vector <int> przezktore[MAX];
int gleb[MAX];
queue <int> kol;
int odw[MAX];
int gleb[MAX];
int odl[MAX];
int del[MAX];
int odw=0;
int tempodw=0;
void bfs(){
    while(!kol.empty()){
        int x=kol.front();
        kol.pop();
        odw++;
        tempodw++;
        for(int i=0;i<all[x].size();i++){
            if(odl[x]+1<odl[all[x][i]]){
                odl[all[x][i]]=odl[x]+1;
                kol.push(all[x][i]);
            }
        }
    }
}
int main()
{
    scanf("%i",&n);
    scanf("%i",&m);
    for(int i=0;i<n;++i){
        scanf("%i",&temp1);
        scanf("%i",&temp2);
        if(temp1!=-1){
            ktore[i].push_back(temp1);
            przezktore[temp1].push_back(i);
            all[i].push_back(temp1);
            all[temp1].push_back(i);
        }
        if(temp2!=-1){
            ktore[i].push_back(temp2);
            przezktore[temp2].push_back(i);
            all[i].push_back(temp2);
            all[temp2].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        odl[i]=MLD;
    }
    odl[1]=0;
    kol.push(1);
    bfs();
    for(int i=0;i<m;i++){
        tempodw=0;
        scanf("%i",&temp3);
        scanf("%i",&temp4);
        for(int j=0;j<all[temp3].size();j++){
            if(all[temp3][j]==ktora[temp3][temp4-1]){
                tem=j;
            }
        }
        for(int j=0;j<all[tem].size();j++){
            if(all[tem][j]==temp3){
                tem1=j;
            }
        }
        all[temp3][tem]=temp3;
        all[tem][tem1]=tem;
        odl[1]=0;
        kol.push(1);
        bfs();
        if(tempodw!=odw){

        }

    }
    return 0;
}
