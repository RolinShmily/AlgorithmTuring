// 桶排序，应用于数组长度很长，而元素大小较小。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 9;
ll a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j < a[i]; ++j)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
// 将元素记为数组下标，数组大小表示该下标（元素）的出现次数，第一个for循环用于枚举在题目范围内的元素，第二个for循环用于输出固定个数的已知元素，通过枚举的升序法对下标（元素）进行排序。