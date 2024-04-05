// 二分查找
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (q--)
    {
        ll x;
        cin >> x;
        ll l = 1, r = n;
        while (l + 1 != r)
        {
            ll mid = (l + r) >> 1;
            if (a[mid] < x)
                l = mid;
            else
                r = mid;
        }
        if (a[r] == x)
            cout << r << ' ';
        else
            cout << -1 << ' ';
    }
    return 0;
}
// 有序数组区间[l,r] 每一次取其中间值作为左/右端点 保证的是输出以右端点为主
//>>右移 位运算符 对二进制数的操作