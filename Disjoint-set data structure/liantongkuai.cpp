/*无向图，n个点，m条边，求联通块大小，2e5*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5;
// 单向边pre，桶cnt
int pre[N], cnt[N];

// 递归返回值，如果找到根则返回1，否则pre向上追溯，知道找到根
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

// 合并，一个块的根，指向另一个根，即联通
void merge(int x, int y)
{
    pre[root(x)] = root(y);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    // 单向边初始化
    for (int i = 1; i <= n; ++i)
        pre[i] = i;
    // 已知边的合并，构成联通块
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    // 桶，所有联通块的根为同一值
    for (int i = 1; i <= n; ++i)
    {
        cnt[root(i)]++;
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        // 如果不为0，则推入
        if (cnt[i])
            v.push_back(cnt[i]);
    }
    // 排序输出
    sort(begin(v), end(v));
    for (auto &i : v)
        cout << i << ' ';
    return 0;
}