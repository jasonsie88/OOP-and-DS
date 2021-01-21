#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
bool v[21][21];
char map[21][21];
int gox[4]={1,0,-1,0};
int goy[4]={0,1,0,-1};
int m,n,ans; //m is row(y) n is column(x)
char land;
bool bound(int y,int x){
    if((y>=0)&&(y<m)&&(x>=0)&&(x<n)){
        return true;
    }
    return false;
}
void DFS(int y,int x){
    int ny,nx;
    v[y][x]=1;
    for(int i=0;i<4;i++){
        nx=x+gox[i];
        if(nx>=n){
            nx=0;
        }else if(nx<0){
            nx=n-1;
        }
        ny=y+goy[i];
        if(bound(ny,nx)&&!v[ny][nx]&&map[ny][nx]==land){
            DFS(ny,nx);
        }
    }
}
void  DFS2(int y,int x){
    int ny,nx;
    v[y][x]=1;
    ans++;
    for(int i=0;i<4;i++){
        nx=x+gox[i];
        if(nx>=n){
            nx=0;
        }else if(nx<0){
            nx=n-1;
        }
        ny=y+goy[i];
        if(bound(ny,nx)&&!v[ny][nx]&&map[ny][nx]==land){
            DFS2(ny,nx);
        }
    }
}
int main() {
    int sy,sx,max;
    string s;
    while(cin>>m>>n){
        max=0;
        memset(v,0,sizeof(v));
        for(int i=0;i<m;i++){
            cin>>s;
            for(int j=0;j<n;j++){
                map[i][j]=s[j];
            }
        }
        cin>>sy>>sx;
        land=map[sy][sx];
        DFS(sy,sx);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=0;
                if(!v[i][j]&&map[i][j]==land){
                    DFS2(i,j);
                    if(ans>max){
                        max=ans;
                    }
                }
            }
        }
        cout<<max<<"\n";
    }
    return 0;
}

