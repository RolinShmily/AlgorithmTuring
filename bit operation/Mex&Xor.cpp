/*给定两个正整数a,b,你可以写出一些非负整数数组，使得该数组的MEX和XOR值分别为a和b。
你需要求出满足条件的非负整数数组的最小长度。
提示:
MEX值是指:最小的不存在于该数组之中的非负整数。例如，数组(0.3.2)的MEX值为1。
XOR值是指:数组中的所有元素做异或运算的结果。例如，数组(3,5,5)的XOR值为3
输入t表示t个样例
输入a，b表示每个样例的测试数据
输出答案*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int prexor[N];
void solve()
{
    int a, b;
    cin >> a >> b;
    int y;
    y = b ^ prexor[a - 1];
    if (y == a)
        cout << a + 2 << '\n';
    else if (y == 0)
        cout << a << '\n';
    else
        cout << a + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < 2e5 + 9; ++i)
        prexor[i] = prexor[i - 1] ^ i;
    while (t--)
        solve();
    return 0;
}
// 思维题：mex值使得数组中至少有从0到mex-1（a-1）这些数字，剩下的就是确定xor（b）值，因此可以得到0^1^...(a-1)^y（y视为数组中的一个未知数）=b，因此y=b^0^1^...^(a-1)，对a进行前缀异或运算（减少运算时间优化代码），对y进行判断即可。如果y==a，而a又不可能出现在数组中，只能把a拆为两个比a大的数进行异或为a，因此就会有a+2个数字。如果y==0，说明0^1^...^(a-1)的结果为b，共a个数字。其余情况时，只要不是a，那么这个数字就可以存在在数组中，也就是a+1个数字