#include <bits/stdc++.h>

#define MAX 100000
#define MAX1 190
#define INF 100000
#define lld long long

using namespace std;

queue<int> kol;
vector<int> kraw[MAX];
int odl[MAX];
lld n;
lld m;
bool tab[MAX1][MAX1];
int wierz[MAX1][MAX1];
int ilejed=0;
int tabjed[MAX];
bool jestwier=0;
lld ktor=0;
lld minol;
string slowa[MAX];

void bfs(){
    while(!kol.empty()){
        int x=kol.front();
        //cout<<kol.front()<<" ";
        kol.pop();
        for(int i=0;i<kraw[x].size();i++){
            //cout<<kraw[5][1]<<" ";
            if(odl[x]+1<odl[kraw[x][i]]){

                odl[kraw[x][i]]=odl[x]+1;
                kol.push(kraw[x][i]);
            }
        }
    }
    //cout<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>m;
    for(int i=0;i<n;++i){
        cin>>slowa[i];
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            wierz[i][j]=i*m+j;
            if(slowa[i][j]=='0'){
                odl[i*m+j]=INF;
            }else{
                odl[i*m+j]=0;
                //cout<<"j";
                kol.push(wierz[i][j]);
                tabjed[ilejed]=wierz[i][j];
                ilejed++;

            }

        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(n==1&&m!=1){
                if(j==0){
                    kraw[j].push_back(wierz[0][1]);
                }else if(j==m-1){
                    kraw[j].push_back(wierz[0][j-1]);
                }else{
                    kraw[j].push_back(wierz[0][j+1]);
                    kraw[j].push_back(wierz[0][j-1]);
                }
            }else if(m==1&&n!=1){
                if(i==0){
                    kraw[i].push_back(wierz[1][0]);
                }else if(i==n-1){
                    kraw[i].push_back(wierz[i-1][0]);
                }else{
                    kraw[i].push_back(wierz[i-1][0]);
                    kraw[i].push_back(wierz[i+1][0]);
                }
            }else if(m!=1&&n!=1){
            if(i==0&&j==0){
                kraw[0].push_back(wierz[0][1]);
                kraw[0].push_back(wierz[1][0]);
            }else if(i==0&&j==m-1){
                kraw[m-1].push_back(wierz[0][m-2]);
                kraw[m-1].push_back(wierz[1][m-1]);
            }
            else if(i==n-1&&j==0){
                kraw[i*m].push_back(wierz[i-1][0]);
                kraw[i*m].push_back(wierz[i][1]);
            }else if(i==n-1&&j==m-1){
                kraw[i*m+j].push_back(wierz[i-1][j]);
                kraw[i*m+j].push_back(wierz[i][j-1]);
            }else if(i==0){
                kraw[j].push_back(wierz[0][j+1]);
                kraw[j].push_back(wierz[0][j-1]);
                kraw[j].push_back(wierz[1][j]);
            }else if(i==n-1){
                kraw[i*m+j].push_back(wierz[i][j+1]);
                kraw[i*m+j].push_back(wierz[i][j-1]);
                kraw[i*m+j].push_back(wierz[i-1][j]);
            }
            else if(j==0){
                kraw[i*m].push_back(wierz[i-1][0]);
                kraw[i*m].push_back(wierz[i+1][0]);
                kraw[i*m].push_back(wierz[i][1]);
            }
            else if(j==m-1){
                kraw[i*m+j].push_back(wierz[i-1][j]);
                kraw[i*m+j].push_back(wierz[i+1][j]);
                kraw[i*m+j].push_back(wierz[i][j-1]);
            }else{
                kraw[i*m+j].push_back(wierz[i-1][j]);
                kraw[i*m+j].push_back(wierz[i+1][j]);
                kraw[i*m+j].push_back(wierz[i][j-1]);
                kraw[i*m+j].push_back(wierz[i][j+1]);
            }
            }


        }
    }

        bfs();




    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j!=m-1){
                cout<<odl[i*m+j]<<" ";
            }else{
                cout<<odl[i*m+j]<<endl;
            }
        }
    }

    return 0;
}
