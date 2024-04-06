//二维数组的修改与查找
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 9;
ll a[N][N], prefix[N][N], diff[N][N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            diff[i][j] += a[i][j];
            diff[i + 1][j] -= a[i][j];
            diff[i][j + 1] -= a[i][j];
            diff[i + 1][j + 1] += a[i][j];
        }
    }
    while (q--)
    {
        ll x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + diff[i][j];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
//二维差分数组一般情况下为空，所以直接对其赋值求解。
//基本遵循差分定理，即差分数组中每个元素的数值是，原数组中该元素减去上一个（左上）元素得到的差值。
//对差分数组进行前缀和，即可还原成原数组。