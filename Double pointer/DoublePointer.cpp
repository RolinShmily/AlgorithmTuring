//双指针: 元素不重复情况下的数组最大长度
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], c[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        c[a[i]] = 0;
    // memset(c, 0, sizeof(int) * (n + 1));
    ll ans = 0;
    for (int i = 1, j = 0; i <= n; ++i)
    {
        while (j < n && !c[a[j + 1]])
            c[a[++j]]++;
        ans = max(ans, ll(j - i + 1));
        c[a[i]]--;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
// memset(void *ptr,int value,size_t num);a数组每次调用都会重新赋值，c数组通过memset进行重置，重置的大小是（n+1）个int，因为c数组长度为N，实际使用长度为n+1。(ps:此时c的范围不是n+1，因为调用的下标由a[i]的数值控制) 老老实实for循环
// 双指针思想，i慢，j快，当a(j+1)为重复时，i跑，直到j+1不重复，否则j跑
// 套用桶思想：0/1变换，！（非）运算符，桶数组c只有0/1，0代表a中元素未被查询，1表示已查询（即重复），！c（即！0为真）运行，++j不改变此时j值，而使j跑1，在大循环背后将i跑过去的元素桶给重置为0.
// 注意max函数中两个变量的同一类型