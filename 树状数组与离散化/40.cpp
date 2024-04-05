#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], t[N];
int n, q;
// 定义lowbit
int lowbit(int x)
{
    return x & -x;
}
// 单点修改，即t数组包含a数组的，都要修改（t默认初始化为0）
void update(ll x, ll y)
{
    for (int i = x; i <= n; i += lowbit(i))
        t[i] += y;
}
// 前缀和思想，无缝衔接求和
ll getsum(ll x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += t[i];
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    // 初始化t数组
    for (int i = 1; i <= n; ++i)
    {
        update((ll)i, a[i]);
    }
    while (q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll k, x;
            cin >> k >> x;
            update(k, x);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << getsum(r) - getsum(l - 1) << '\n';
        }
    }
    return 0;
}