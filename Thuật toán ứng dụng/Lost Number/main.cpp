#include<iostream>

using namespace std;

int res[7];
int mark[7];
int map[7] = {4,8,15,16,23,42};
int ar[7];

int flag = 0;
void dfs(int k,int last_val)
{
    if(flag == 1)
        return;
    if(k == 5)
    {
        for(int i = 0; i < 6; i ++)
        {
            if(! mark[i])
            {
                res[k] = map[i];
                flag = 1;
                return;
            }
        }
    }

    for(int i = 0; i < 6; i ++)
    {
        if(k == 0 && !mark[i])
        {
            if(flag == 1)
                return;
            mark[i] = 1;
            res[k] = map[i];
            dfs(k + 1 , map[i]);
            mark[i] = 0;
        }
        else if(k > 0 && !mark[i] && ar[k] == last_val * map[i])
        {
            if(flag == 1)
                return;
            mark[i] = 1;
            res[k] = map[i];
            dfs(k + 1 , map[i]);
            mark[i] = 0;
        }
    }
}


int main()
{
    //freopen("test.txt","r",stdin);
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&ar[1]);

    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d",&ar[2]);

    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d",&ar[3]);

    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&ar[4]);
    dfs(0 , 1);
    printf("! %d %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4], res[5]);

    return 0;
}
