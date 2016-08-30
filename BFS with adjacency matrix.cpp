//Problem link:http://acm.timus.ru/problem.aspx?space=1&num=1145
#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define rep(i,n) for(int i=0; i<(int)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define pmp make_pair
#define uu first
#define vv second
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int mr,mc,mx=0;
char w[1000][1000];
int d[1000][1000];
int r,c;
void bfs(int x,int y,int dep)
{
	mem(d,63);
	d[x][y]=0;
	queue<pii>q;
	q.push(pii(x,y));
	while(!q.empty())
	{

		pii top=q.front(); q.pop();

		if(d[top.uu][top.vv]>mx)
		{
			mx=d[top.uu][top.vv];
			mr=top.uu;
			mc=top.vv;
		}
		rep(k,4)
		{
			int tx=top.uu+fx[k];
			int ty=top.vv+fy[k];
			if(tx>=0 and tx<r and ty>=0 and ty<c and w[tx][ty]=='.' and d[top.uu][top.vv]+1<d[tx][ty])
			{
				d[tx][ty]=d[top.uu][top.vv]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}
int main(){
//	READ("in");
	int sx,sy,cc=0;
	cin>>r>>c;
	swap(r,c);
	rep(i,r)
	cin>>w[i];
	rep(i,r)
		rep(j,c)
		if(w[i][j]=='.'){sx=i;sy=j;cc++;}
	bfs(sx,sy,0);

	mx=0;
	bfs(mr,mc,0);
	if(cc==1) mx=0;
	cout<<mx<<endl;
	return 0;
}
