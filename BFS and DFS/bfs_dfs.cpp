#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int fa[N];
vector<int> g[N];
void dfs(int x)
{
    cout << x << ' ';    // 树根
    for (auto &i : g[x]) // 遍历该father的对应son
        dfs(i);          // 递归通过dfs搜索
}
void bfs(int x)
{
    queue<int> q;
    q.push(x); // 将树根推入
    while (q.size())
    {
        int y = q.front();   // 临时存储队头
        q.pop();             // 将队头打掉
        cout << y << ' ';    // 输出队头
        for (auto &i : g[y]) // 遍历该队头（father）的对应son
            q.push(i);       // 将son推入
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    // n-1个father，存储对应的son
    for (int i = 2; i <= n; ++i)
        cin >> fa[i];
    // vector实现邻接图，存储father与son
    for (int i = 2; i <= n; ++i)
        g[fa[i]].push_back(i);
    // 对son排序，遍历即实现对father排序
    for (int i = 1; i <= n; ++i)
        sort(g[i].begin(), g[i].end());
    // dfs深度搜索：由一节点出发，搜索最近的节点，循环如此，直到这一条打通，回到上一级节点，再次循环
    dfs(1);
    cout << '\n';
    // bfs广度搜索：由某一节点出发，搜索最近的节点，并将所有一级最近节点访问完，再访问二级最近节点
    bfs(1);
    return 0;
}