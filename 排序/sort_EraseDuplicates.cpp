// 排序并去重（vector）
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 9;
vector<ll> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto &i : a)
        cout << i << ' ';
    return 0;
}
// vector 替代数组, sort 函数排序, erase 去重, unique 对于sort过的vector，将其中重复的元素放在集合最后，并返回第一个重复值（第二次出现的位置）。 &表示引用, for枚举将一个范围中的所有元素赋值给一个临时变量i，对i的访问即是查看a中的元素， auto 为自动判断数据类型
// vector 成员元素的录入 a.push_back(x) , 读取 a.begin(), a.end()