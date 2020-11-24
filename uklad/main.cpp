#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1009

using namespace std;

int n,m,k,czyn,mini,odw[MAX][MAX],ilej;

pair<pair<int,int>,pair<int,int> >wyny[MAX*MAX];

void dodcho(int wier, int kol, int str){
    if(str==0){
        while(ilej<k&&kol>2){
            wyny[ilej]=mp(mp(wier,kol),mp(wier,kol-1));
			odw[wier][kol-1]=1;
			++ilej;
			--kol;
        }
    }else{
        while(ilej<k&&kol<(m-1)){
            wyny[ilej]=mp(mp(wier,kol),mp(wier,kol+1));
			odw[wier][kol+1]=1;
			++ilej;
			++kol;
        }
    }
    if(ilej<k){
        wyny[ilej]=mp(mp(wier,kol),mp(wier+1,kol));
        odw[wier+1][kol]=1;
        ++ilej;
        ++wier;
    }
    if(ilej<k){
        dodcho(wier,kol,(str^1));
    }
}

void dodcho1(int wier, int kol, int str){
    if(str==0){
        while(ilej<k&&wier>2){
            wyny[ilej]=mp(mp(wier,kol),mp(wier-1,kol));
			odw[wier-1][kol]=1;
			++ilej;
			--wier;
        }
    }else{
        while(ilej<k&&wier<(n-1)){
            wyny[ilej]=mp(mp(wier,kol),mp(wier+1,kol));
			odw[wier+1][kol]=1;
			++ilej;
			++wier;
        }
    }
    if(ilej<k){
        wyny[ilej]=mp(mp(wier,kol),mp(wier,kol+1));
        odw[wier][kol+1]=1;
        ++ilej;
        ++kol;
    }
    if(ilej<k){
        dodcho1(wier,kol,(str^1));
    }
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n%2||m%2)czyn=1;
	mini=n+m-1;
	if(czyn)mini--;
	if(k<mini||k>n*m-1){
		printf("NIE");
		return 0;
	}
	if(czyn&&n%2==0){
        if(k<2*n+m-3){
            ilej=0;

			odw[1][1]=1;
			for(int i=1;i<=m/2;++i){
				wyny[ilej]=mp(mp(1,i),mp(1,i+1));
				odw[1][i+1]=1;
				++ilej;
			}
			for(int i=1;i<n;++i){
				wyny[ilej]=mp(mp(i,m/2+1),mp(i+1,m/2+1));
				odw[i+1][m/2+1]=1;
				++ilej;
			}
			for(int i=m/2+1;i>1;--i){
				wyny[ilej]=mp(mp(n,i),mp(n,i-1));
				odw[n][i-1]=1;
				++ilej;
			}
			int ite=n;
			while(ilej<k&&ite>2){
				wyny[ilej]=mp(mp(ite,1),mp(ite-1,1));
				odw[ite-1][1]=1;
				++ilej;
				--ite;
			}
			for(int i=1;i<=n;++i){
				int itj=m/2+1;
				while(itj<m&&!odw[i][itj+1]){
					wyny[ilej]=mp(mp(i,itj),mp(i,itj+1));
					odw[i][itj+1]=1;
					++ilej;
					++itj;
				}
				itj=m/2+1;
				while(itj>1&&!odw[i][itj-1]){
					wyny[ilej]=mp(mp(i,itj),mp(i,itj-1));
					odw[i][itj-1]=1;
					++ilej;
					--itj;
				}
			}
		}else{
            ilej=0;
            odw[1][1]=1;
            for(int i=1;i<n;++i){
                wyny[ilej]=mp(mp(i,1),mp(i+1,1));
                odw[i+1][1]=1;
                ++ilej;
            }
            //cout<<wyny[0].f.f;
            for(int i=1;i<m;++i){
                wyny[ilej]=mp(mp(n,i),mp(n,i+1));
                odw[n][i+1]=1;
                ++ilej;
            }
            for(int i=n;i>1;--i){
                wyny[ilej]=mp(mp(i,m),mp(i-1,m));
                odw[i-1][m]=1;
                ++ilej;
            }
            //cout<<ilej;
            int itn=1;
            int itm=m;
            if(ilej<k)dodcho(itn,itm,0);
            for(int i=2;i<m;++i){
                int item=n;
                while(item>1&&!odw[item-1][i]){
                    wyny[ilej]=mp(mp(item,i),mp(item-1,i));
                    odw[item-1][i]=1;
                    ++ilej;
                    --item;
                }
            }
		}
	}else{
	    ilej=0;
        if(k<2*m+n-3){
            odw[1][1]=1;
            for(int i=1;i<=n/2;++i){
                wyny[ilej]=mp(mp(i,1),mp(i+1,1));
                odw[i+1][1]=1;
                ++ilej;
			}
			for(int i=1;i<m;++i){
				wyny[ilej]=mp(mp(n/2+1,i),mp(n/2+1,i+1));
				odw[n/2+1][i+1]=1;
				++ilej;
			}
			for(int i=n/2+1;i>1;--i){
				wyny[ilej]=mp(mp(i,m),mp(i-1,m));
				odw[i-1][m]=1;
				++ilej;
			}
			int ite=m;
			while(ilej<k&&ite>2){
				wyny[ilej]=mp(mp(1,ite),mp(1,ite-1));
				odw[1][ite-1]=1;
				++ilej;
				--ite;
			}
			for(int i=1;i<=m;++i){
				int itj=n/2+1;
				while(itj<n&&!odw[itj+1][i]){
					wyny[ilej]=mp(mp(itj,i),mp(itj+1,i));
					odw[itj+1][i]=1;
					++ilej;
					++itj;
				}
				itj=n/2+1;
				while(itj>1&&!odw[itj-1][i]){
					wyny[ilej]=mp(mp(itj,i),mp(itj-1,i));
					odw[itj-1][i]=1;
					++ilej;
					--itj;
				}
			}
        }else{
            ilej=0;
            odw[1][1]=1;
            for(int i=1;i<m;++i){
                wyny[ilej]=mp(mp(1,i),mp(1,i+1));
                odw[1][i+1]=1;
                ++ilej;
            }
            //cout<<wyny[0].f.f;
            for(int i=1;i<n;++i){
                wyny[ilej]=mp(mp(i,m),mp(i+1,m));
                odw[i+1][m]=1;
                ++ilej;
            }
            for(int i=m;i>1;--i){
                wyny[ilej]=mp(mp(n,i),mp(n,i-1));
                odw[n][i-1]=1;
                ++ilej;
            }
            //cout<<ilej;

            int itn=n;
            int itm=1;
            if(ilej<k)dodcho1(itn,itm,0);//cout<<odw[2][2];
            for(int i=2;i<n;++i){
                int item=m;
                while(item>1&&!odw[i][item-1]){
                    wyny[ilej]=mp(mp(i,item),mp(i,item-1));
                    odw[i][item-1]=1;
                    ++ilej;
                    --item;
                }
            }
        }
	}
	/*
	if(k<2*n+m-3){
		ilej=0;
		if(czyn&&n%2==0){
			odw[1][1]=1;
			for(int i=1;i<=m/2;++i){
				wyny[ilej]=mp(mp(1,i),mp(1,i+1));
				odw[1][i+1]=1;
				++ilej;
			}
			for(int i=1;i<n;++i){
				wyny[ilej]=mp(mp(i,m/2+1),mp(i+1,m/2+1));
				odw[i+1][m/2+1]=1;
				++ilej;
			}
			for(int i=m/2+1;i>1;--i){
				wyny[ilej]=mp(mp(n,i),mp(n,i-1));
				odw[n][i-1]=1;
				++ilej;
			}
			int ite=n;
			while(ilej<k&&ite>2){
				wyny[ilej]=mp(mp(ite,1),mp(ite-1,1));
				odw[ite-1][1]=1;
				++ilej;
				--ite;
			}
			for(int i=1;i<=n;++i){
				int itj=m/2+1;
				while(itj<m&&!odw[i][itj+1]){
					wyny[ilej]=mp(mp(i,itj),mp(i,itj+1));
					odw[i][itj+1]=1;
					++ilej;
					++itj;
				}
				itj=m/2+1;
				while(itj>1&&!odw[i][itj-1]){
					wyny[ilej]=mp(mp(i,itj),mp(i,itj-1));
					odw[i][itj-1]=1;
					++ilej;
					--itj;
				}
			}
		}else if(czyn){
			if(k<2*m+n-3){
				odw[1][1]=1;
				for(int i=1;i<=n/2;++i){
					wyny[ilej]=mp(mp(i,1),mp(i+1,1));
					odw[i+1][1]=1;
					++ilej;
				}
				for(int i=1;i<m;++i){
					wyny[ilej]=mp(mp(n/2+1,i),mp(n/2+1,i+1));
					odw[n/2+1][i+1]=1;
					++ilej;
				}
				for(int i=n/2+1;i>1;--i){
					wyny[ilej]=mp(mp(i,m),mp(i-1,m));
					odw[i-1][m]=1;
					++ilej;
				}
				int ite=m;
				while(ilej<k&&ite>2){
					wyny[ilej]=mp(mp(1,ite),mp(1,ite-1));
					odw[1][ite-1]=1;
					++ilej;
					--ite;
				}
				for(int i=1;i<=m;++i){
					int itj=n/2+1;
					while(itj<n&&!odw[itj+1][i]){
						wyny[ilej]=mp(mp(itj,i),mp(itj+1,i));
						odw[itj+1][i]=1;
						++ilej;
						++itj;
					}
					itj=n/2+1;
					while(itj>1&&!odw[itj-1][i]){
						wyny[ilej]=mp(mp(itj,i),mp(itj-1,i));
						odw[itj-1][i]=1;
						++ilej;
						--itj;
					}
				}
			}
		}else if(!czyn){

				odw[1][1]=1;
				for(int i=1;i<=m/2;++i){
					wyny[ilej]=mp(mp(1,i),mp(1,i+1));
					odw[1][i+1]=1;
					++ilej;
				}
				for(int i=1;i<n;++i){
					wyny[ilej]=mp(mp(i,m/2+1),mp(i+1,m/2+1));
					odw[i+1][m/2+1]=1;
					++ilej;
				}
				for(int i=m/2+1;i>1;--i){
					wyny[ilej]=mp(mp(n,i),mp(n,i-1));
					odw[n][i-1]=1;
					++ilej;
				}
				int ite=n;
				while(ilej<k&&ite>2){
					wyny[ilej]=mp(mp(ite,1),mp(ite-1,1));
					odw[ite-1][1]=1;
					++ilej;
					--ite;
				}
				for(int i=1;i<=n;++i){
					int itj=m/2+1;
					while(itj<m&&!odw[i][itj+1]){
						wyny[ilej]=mp(mp(i,itj),mp(i,itj+1));
						odw[i][itj+1]=1;
						++ilej;
						++itj;
					}
					itj=m/2+1;
					while(itj>1&&!odw[i][itj-1]){
						wyny[ilej]=mp(mp(i,itj),mp(i,itj-1));
						odw[i][itj-1]=1;
						++ilej;
						--itj;
					}
				}
			}

	}else{
	    //cout<<"X";
		ilej=0;
		odw[1][1]=1;
		for(int i=1;i<n;++i){
			wyny[ilej]=mp(mp(i,1),mp(i+1,1));
			odw[i+1][1]=1;
			++ilej;
		}
		//cout<<wyny[0].f.f;
		for(int i=1;i<m;++i){
			wyny[ilej]=mp(mp(n,i),mp(n,i+1));
			odw[n][i+1]=1;
			++ilej;
		}
		for(int i=n;i>1;--i){
			wyny[ilej]=mp(mp(i,m),mp(i-1,m));
			odw[i-1][1]=1;
			++ilej;
		}
		//cout<<ilej;
		int itn=1;
		int itm=m;
		if(ilej<k)dodcho(itn,itm,0);
		for(int i=2;i<m;++i){
            int item=n;
            while(item>1&&!odw[item-1][i]){
                wyny[ilej]=mp(mp(item,i),mp(item-1,i));
                odw[item-1][i]=1;
                ++ilej;
            }
		}
	}*/
    printf("TAK\n");
    for(int i=0;i<ilej;++i){
        printf("%d %d %d %d\n",wyny[i].f.f,wyny[i].f.s,wyny[i].s.f,wyny[i].s.s);
    }
	return 0;
}
/*
1 1 2 1
2 1 3 1
3 1 3 2
3 2 3 3
3 3 2 3
2 3 1 3
3 1 4 1
4 1 5 1
3 2 4 2
4 2 5 2
3 2 2 2
2 2 1 2
3 3 4 3
4 3 5 3
*/
