/*题目描述:给定义一个数组a,有q次询问，对于每次询问：给定两个整数l，r，求出a[l]+a[l+1]+...+a[r]的结果
  输入:第一行一个整数1<=T<=10,表示样例个数。
  对于每组样例:
       第一行2个整数 1<=n<=10^5,1<=q<=10^5,分别表示数组长度和询问次数
       第二行n个整数 表示数组a中的元素
       接下俩q行 每行两个整数1<=l<=r<=n表示询问的区间
  输出:对于每组样例 一行一个整数表示答案*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 9;
ll a[N], prefix[N];
void inqure(ll a[], ll prefix[])
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        inqure(a, prefix);
    return 0;
}
// 前缀和数组prefix[N],prefix[i]=prefix[i-1]+a[i]
// 计算数组a[N]的前n项和，将结果单独放入前缀和数组prefix[N]中，实现数组中连续区间的数字和。