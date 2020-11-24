#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define pii pair<int,int>

using namespace std;

int n,m,a,b,czy;
vector<int> kraw[MAX];
vector<int> gr[3];
int odw[MAX];
int wgr[MAX];
int wyny[MAX];
int roby[MAX];
int roby1[MAX][2];
int roby2[MAX];
int grsiz[2];

int dfs(int from, int kt){
    odw[from]=1;
    wgr[from]=kt;
    gr[kt].pb(from);
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            if(kt==1){
                dfs(kraw[from][i],2);
            }else{
                dfs(kraw[from][i],1);
            }
        }

    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        if(!odw[i])dfs(i,1);
    }
    if(gr[1].size()%3==0){
        czy=1;
        for(int i=0;i<gr[1].size();i+=3){
            for(int j=i;j<i+3;++j){
                wyny[gr[1][j]]=i/3+1;
            }
        }
        for(int i=0;i<gr[2].size();i+=3){
            for(int j=i;j<i+3;++j){
                wyny[gr[2][j]]=i/3+1+gr[1].size()/3;
            }
        }
    }else if(gr[1].size()%3==1){
        for(int i=0;i<gr[1].size();++i){
            if(kraw[gr[1][i]].size()<=gr[2].size()-2){
                wyny[gr[1][i]]=1;
                for(int j=0;j<kraw[gr[1][i]].size();++j){
                    roby[kraw[gr[1][i]][j]]=1;
                }
                swap(gr[1][i],gr[1][gr[1].size()-1]);
                gr[1].pop_back();
                czy=1;
                int ile=0;
                for(int j=0;j<gr[2].size();++j){
                    if(!roby[gr[2][j]]&&ile==0){
                        wyny[gr[2][j]]=1;

                        swap(gr[2][j],gr[2][gr[2].size()-1]);
                        ile++;
                        gr[2].pop_back();
                        j=-1;
                    }else if(!roby[gr[2][j]]&&ile==1){
                        wyny[gr[2][j]]=1;//cout<<gr[2][j]<<" ";
                        swap(gr[2][j],gr[2][gr[2].size()-1]);
                        ile++;
                        break;
                    }
                }

                gr[2].pop_back();
                break;
            }
        }
        if(czy){
            for(int i=0;i<gr[1].size();i+=3){
                for(int j=i;j<i+3;++j){
                    wyny[gr[1][j]]=i/3+2;
                }
            }
            for(int i=0;i<gr[2].size();i+=3){
                for(int j=i;j<i+3;++j){
                    wyny[gr[2][j]]=i/3+2+gr[1].size()/3;
                }
            }
        }else if(gr[1].size()>=4){
            //cout<<"A";
            for(int xd=0;xd<2;++xd){

                for(int i=0;i<gr[2].size();++i){//cout<<i;
            if(kraw[gr[2][i]].size()<=gr[1].size()-2+czy*2){
                wyny[gr[2][i]]=xd+1;
                for(int j=0;j<kraw[gr[2][i]].size();++j){
                    roby1[kraw[gr[2][i]][j]][xd]=1;
                }
                swap(gr[2][i],gr[2][gr[2].size()-1]);
                gr[2].pop_back();
                czy++;
                int ile=0;
                for(int j=0;j<gr[1].size();++j){
                    if(!roby1[gr[1][j]][xd]&&ile==0){
                        wyny[gr[1][j]]=xd+1;
                        swap(gr[1][j],gr[1][gr[1].size()-1]);
                        gr[1].pop_back();
                        j=-1;
                        ile++;
                    }else if(!roby1[gr[1][j]][xd]&&ile==1){
                        wyny[gr[1][j]]=xd+1;
                        swap(gr[1][j],gr[1][gr[1].size()-1]);
                        ile++;
                        break;
                    }
                }

                gr[1].pop_back();
                break;
            }
        }
            }
        if(czy==2){
            for(int i=0;i<gr[2].size();i+=3){
                for(int j=i;j<i+3;++j){
                    wyny[gr[2][j]]=i/3+3;
                }
            }
            for(int i=0;i<gr[1].size();i+=3){
                for(int j=i;j<i+3;++j){
                    wyny[gr[1][j]]=i/3+3+gr[2].size()/3;
                }
            }
        }else{
            czy=0;
        }


        }
    }else{
        for(int i=0;i<gr[2].size();++i){
            if(kraw[gr[2][i]].size()<=gr[1].size()-2){
                wyny[gr[2][i]]=1;
                for(int j=0;j<kraw[gr[2][i]].size();++j){
                    roby[kraw[gr[2][i]][j]]=1;
                }
                swap(gr[2][i],gr[2][gr[2].size()-1]);
                gr[2].pop_back();
                czy=1;
                int ile=0;
                for(int j=0;j<gr[1].size();++j){
                    if(!roby[gr[1][j]]&&ile==0){
                        wyny[gr[1][j]]=1;
                        swap(gr[1][j],gr[1][gr[1].size()-1]);
                        gr[1].pop_back();
                        j=-1;
                        ile++;
                    }else if(!roby[gr[1][j]]&&ile==1){
                        wyny[gr[1][j]]=1;
                        swap(gr[1][j],gr[1][gr[1].size()-1]);
                        ile++;
                        break;
                    }
                }

                gr[1].pop_back();
                break;
            }
        }
        if(czy){
            for(int i=0;i<gr[2].size();i+=3){
                for(int j=i;j<i+3;++j){
                    wyny[gr[2][j]]=i/3+2;
                }
            }
            for(int i=0;i<gr[1].size();i+=3){
                for(int j=i;j<i+3;++j){
                    wyny[gr[1][j]]=i/3+2+gr[2].size()/3;
                }
            }
        }else if(gr[2].size()>=4){
            for(int xd=0;xd<2;++xd){

                for(int i=0;i<gr[1].size();++i){
            if(kraw[gr[1][i]].size()<=gr[2].size()-2+czy*2){
                wyny[gr[1][i]]=xd+1;
                for(int j=0;j<kraw[gr[1][i]].size();++j){
                    roby1[kraw[gr[1][i]][j]][xd]=1;
                }
                swap(gr[1][i],gr[1][gr[1].size()-1]);
                gr[1].pop_back();
                czy++;
                int ile=0;
                for(int j=0;j<gr[2].size();++j){
                    if(!roby1[gr[2][j]][xd]&&ile==0){
                        wyny[gr[2][j]]=xd+1;
                        swap(gr[2][j],gr[2][gr[2].size()-1]);
                        gr[2].pop_back();
                        j=-1;
                        ile++;
                    }else if(!roby1[gr[2][j]][xd]&&ile==1){
                        wyny[gr[2][j]]=xd+1;
                        swap(gr[2][j],gr[2][gr[2].size()-1]);
                        ile++;
                        break;
                    }
                }

                gr[2].pop_back();
                break;
            }
        }
            }
        if(czy==2){
            for(int i=0;i<gr[2].size();i+=3){
                for(int j=i;j<i+3&&j<gr[2].size();++j){//cout<<gr[2][j];
                    wyny[gr[2][j]]=i/3+3;
                }
            }
            for(int i=0;i<gr[1].size();i+=3){
                for(int j=i;j<i+3&&j<gr[2].size();++j){
                    wyny[gr[1][j]]=i/3+3+gr[2].size()/3;
                }
            }
        }else{
            czy=0;
        }
    }
    }
    if(czy){
        printf("TAK\n");
        for(int i=1;i<=n;++i){
            printf("%d ",wyny[i]);
        }
    }else{
        printf("NIE\n");
    }
    return 0;
}
/*
6
4
1 5
2 5
3 6
4 6
*/
