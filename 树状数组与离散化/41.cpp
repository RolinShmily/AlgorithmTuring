#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], td[N], tid[N];
int n, q;
// 定义lowbit
int lowbit(int x)
{
    return x & -x;
}
// 区间修改，分段
void update(ll x, ll y)
{
    for (int i = x; i <= n; i += lowbit(i))
        td[i] += y, tid[i] += x * y;
}
// 根据差分数组还原求和
ll getsum(ll x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += (1 + x) * td[i] - tid[i];
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    // 初始化td,tid数组
    for (int i = 1; i <= n; ++i)
    {
        // 对象是差分数组，两步单点修改
        update((ll)i, a[i]), update((ll)(i + 1), -a[i]);
    }
    while (q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll k, x, v;
            cin >> k >> x >> v;
            update(k, v), update(x + 1, -v);
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