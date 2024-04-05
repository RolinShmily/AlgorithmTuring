/*
假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的
贪心算法进行安排。（这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个
顶点，不相容活动间用边相连。使相邻顶点着有不同颜色的最小着色数，相应于要找的最小
会场数。）

输入格式:
第一行有 1 个正整数k，表示有 k个待安排的活动。
接下来的 k行中，每行有 2个正整数，分别表示 k个待安排的活动开始时间和结束时间。时间
以 0 点开始的分钟计。

输出格式:
输出最少会场数。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
struct Time
{
    int a;
    int b;
    bool operator<(const Time &u) const
    {
        if (a == u.a)
            return b < u.b;
        else
            return a < u.a;
    }
} s[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, count = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> s[i].a >> s[i].b;
    }
    sort(s+1, s+1+t);
    s[t + 2].a = s[1].a;
    s[t + 2].b = s[1].b;
    for (int i = 1; i <= t; ++i)
    {
        if (s[i + 2].a >= s[t + 2].b)
        {
            count++;
            s[t + 2].a = s[i + 2].a;
            s[t + 2].b = s[i + 2].b;
        }
        else
            continue;
    }
    cout << count;
    return 0;
}