//一维数组的修改与区间求和
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 9;
ll a[N], prefix[N], diff[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, p, q;
    cin >> n >> p >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        diff[i] = a[i] - a[i - 1];
    while (p--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }
    for (int i = 1; i <= n; ++i)
        a[i] = a[i - 1] + diff[i];
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    return 0;
}
// 差分数组diff[N],diff[i]=a[i]-a[i-1]
// 1.回归原数组。通过公式可见,a[i]=diff[i]+a[i-1],而a[i-1]也可以用diff表示,从而diff[1]~[n]的和就是a[n]
// 2.修改后调用。对a[N]的修改可以转化为对diff[N]的修改,再经过diff[N]回归a[N]即可。
//              diff[i]的修改会导致从a[i]开始往后的a[i+1]...均改变,从而实现对区间内a[N]中元素的修改。