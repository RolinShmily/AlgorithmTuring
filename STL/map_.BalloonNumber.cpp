// map（映射），（key，value），（红黑树，非线性）
// 气球问题：t个事例；对于每个示例，第一行输入n个气球，接下来n行输入一个气球的颜色（表示）；输出要求，按照气球出现的顺序，输出气球的颜色和数量；
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    map<string, int> mp;
    vector<string> v;
    int n;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        if (mp.count(s))
            mp[s]++;
        else
            v.push_back(s), mp[s] = 1;
        n--;
    }
    for (auto &i : v)
        cout << i << ' ' << mp[i] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
//vector用来将记录气球出现的顺序