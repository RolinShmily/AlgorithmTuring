#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N], t[N];
vector<int> X;
int lowbit(int x)
{
    return x & -x;
}
void update(int x, int y)
{
    for (int i = x; i <= X.size(); i += lowbit(i))
        t[i] += y;
}
int getsum(int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += t[i];
    return res;
}

int binary(int x)
{
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        X.push_back(a[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans +=(ll) getsum(X.size()) - getsum(binary(a[i]));
        update(binary(a[i]), 1);
    }
    cout << ans << '\n';
    return 0;
}