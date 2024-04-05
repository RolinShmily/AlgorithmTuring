#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
vector<int> X;
int prefix[N];
// 定义 修改add 访问que
struct add
{
    int a, b;
} add[N], que[N];
// 二分查找
ll binary(ll x)
{
    // lower_bound下边界（排序后为左界）
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
    // X由1开始排下标
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        add[i].a = a, add[i].b = b;
        X.push_back(a);
    }
    for (int i = 1; i <= q; ++i)
    {
        ll l, r;
        cin >> l >> r;
        que[i].a = l, que[i].b = r;
        X.push_back(l), X.push_back(r);
    }
    // 排序并去重
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    // 翻译 修改
    for (int i = 1; i <= n; ++i)
    {
        ll x = binary(add[i].a);
        int w = add[i].b;
        prefix[x] += w;
    }
    // 前缀和
    for (int i = 1; i <= (int)X.size(); ++i)
    {
        prefix[i] += prefix[i - 1];
    }
    // 翻译 访问 并输出结果
    for (int i = 1; i <= q; ++i)
    {
        ll l = binary(que[i].a);
        ll r = binary(que[i].b);
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    return 0;
}
// 离散化：将已知数组中的访问下标保存至另一个可变数组中，将原数组中的操作，翻译为新数组X中的操作。