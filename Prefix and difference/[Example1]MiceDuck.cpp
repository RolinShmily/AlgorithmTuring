/*在一个叫做酱西功爷枝叶鸡树学院的地方有n只小动物，要么是鼠鼠，要么是鸭鸭，从1到n编号，每只小动物有个体重ai。在这个学校里，存在一种神奇的魔法，可以将编号位于某个区间,内的所有鼠鼠都变为鸭鸭，鸭鸭都变为鼠鼠(魔法并不会改变体重。现在你可以施放这个魔法至多1次。(也可以不施放)
问最终鸭鸭的总重量最多是多少?
第一行一个整数T表示样例个数。(1<=T<=10)
对于每个样例:
第一行一个整数n表示小动物的个数。(1<=n<=10^5)
第二行n个整数，表示第i个小动物的类型。0表示鼠鼠，1表示鸭鸭。
第三行n个整数，表示第i个小动物的体重ai。(1<=ai<=10^9)
对于每个样例一行一个整数表示答案*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 9;
ll a[N], b[N], prefix[N];
void mouth_duck(ll a[], ll b[], ll prefix[])
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    ll ess = 0;
    for (int i = 1; i <= n; ++i)
        ess += b[i] * a[i];
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + b[i] * (a[i] ? -1 : 1);
    ll mi = 0, fix = 0;
    for (int i = 1; i <= n; ++i)
    {
        fix = max(fix, prefix[i] - mi);
        mi = min(mi, prefix[i]);
    }
    cout << ess + fix << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        mouth_duck(a, b, prefix);
    return 0;
}
// 首先，不考虑存在魔法，那么总重量即两个数组对应元素相乘得加和。
// 存在的魔法是让0变1，1变0，从而体重数组得元素对于答案的影响是*（-1）或1，形成偏移量，从而答案就变为，ess（不进行魔法）+fix（偏移量）。
// 对于偏移量，可以对偏移值数组进行前缀和，而取值只需对fix求最大值，即求取最大子段，对于两端点l，r，r可以用for遍历，l即是求prefix[j]（j<i）的最小值，最后再求取遍历过程中的最大差值，即为偏移量。
// ps：三元运算符  bool_a ? if_true(返回值1):if_false(返回值2)