//跑火车（栈：先进后出）问题（stack）
/*现在有n部火车，每一部火车都有一个1~n的编号各不相同(火车编号构成一个排列)
现在他们按照给定的顺序排列在一条轨道上，且可以向两个方向移动，问他们能否通过一个车站，且每部火车至多进站一次，使得出站口的编号顺序变为升序?
如果可以输出"Yes”，如果不行输出"No"。*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], pos;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    pos = 1;
    stack<int> stk;
    for (int i = 1; i <= n; ++i)
    {
        while (pos <= n && (stk.empty()||stk.top()!=i))
        {
            stk.push(a[pos++]);
        }
        if (stk.top() == i)
            stk.pop();
        else
        {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
//跑火车核心：中间站（栈）的判定。出站口的升序排列，只有两种操作，进站口先进入中间站再出站，中间站的顶部出站（且符合排序）。暴力枚举出站口的顺序从1开始到n，只需判断中间站顶部是否为当前需要的编号。中间站的输入由入站口决定，如果中间站为空，则必须有入站口进站，如果中间站顶部不为当前所需编号，则必须入站，直到入站口无车，内循环结束。此时所有车全部在中间站，如果顶部不为所需编号，则一定不能构成升序排列。而整个循环跑完都为出现异常，则说明已经构成升序排列。