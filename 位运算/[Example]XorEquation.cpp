/*给定一个大小为n的非负整数数组a。
你可以选定一个非负整数x并令bi = ai^x; ,其中1<=i<=n请问是否存在x，使得b1^b2^...^bn=0?
第一行，一个整数t，表示有(1<=t<=200)个案例，
对于每个案例:
第一行:一个整数n(1<=n<=1000，且n为奇数)，表示数组的大小。
第二行: n个整数，表示数组a(0<=ai<=10^9)。
对于每个样例，若存在，输出x，不存在输出-1*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 9;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ll x;
            cin >> x;
            ans ^= x;
        }
        cout << ans << '\n';
    }
    return 0;
}
// 通过异或的计算规则（结合律与交换律）可化简为x=a1^a2^...^an;