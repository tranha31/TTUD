#include<bits/stdc++.h>
using namespace std;
#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define dembit1(x) __builtin_popcountll(x)
#define fi first
#define se second
typedef long long ll;
const int mod=1e9+7;
const int oo = INT_MAX;
const int N = 40;
int m,n,k,c[N][N],ans;
vector<int> a[N],t[N];
 
bool check(int su, int tc)
{
    bool rt=false;
    For(i,0,a[tc].size())
    {
        if(su==a[tc][i])
        {
            rt=true;
            break;
        }
    }
    if(rt==false) return rt;
    For(i,0,t[tc].size())
    {
        int j = t[tc][i];
        if(c[su][j]==1)
        {
            rt=false;
            break;
        }
    }
    return rt;
}
 
void dfs(int u)
{
    if(u==n+1)
    {
        int res=0;
        Fr(i,1,n) res=max(res,(int)t[i].size());
        ans=min(ans,res);
        return;
    }
    Fr(i,1,m)
    {
        if(check(u,i))
        {
            t[i].push_back(u);
            if(t[i].size()<ans)
            {
                dfs(u+1);
            }
            t[i].pop_back();
        }
    }
}
 
int main()
{
    scanf("%d %d",&m,&n);
    Fr(i,1,m)
    {
        scanf("%d",&k);
        Fr(j,1,k)
        {
            int u;
            scanf("%d",&u);
            a[i].push_back(u);
        }
    }
    scanf("%d",&k);
    Fr(i,1,k)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        c[u][v]=c[v][u]=1;
    }
    ans=oo;
    dfs(1);
    if(ans == oo) printf("-1");
    else printf("%d",ans);
    return 0;
}
