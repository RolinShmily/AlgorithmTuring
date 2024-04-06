// 多重关键字（结构体）排序
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 9;
struct Book
{
    int a, b, c;
    bool operator < (const Book &u) const
    {
        if (a == u.a && b == u.b)
        {
            return c < u.c;
        }
        if (a == u.a)
        {
            return b < u.b;
        }
        return a < u.a;
    }
} p[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i].a >> p[i].b >> p[i].c;
    sort(p + 1, p + 1 + n);
    reverse(p + 1, p + 1 + n);
    for (int i = 1; i <= n; ++i)
        cout << p[i].a << " " << p[i].b << " " << p[i].c << '\n';
    return 0;
}
// 1.sort函数的排序范围是左闭右开，上例中数组从1->n，p初值为0，且sort函数只用于可进行整数型操作的数据排序
// 2.reverse函数对排序结果进行倒置
// 3.bool(返回值类型) operator '<(>,+,-,=)' (const 结构体名 &u(引用实例))const{<结构体>}
//   结构体Book内的运算符'<'重载，使其返回一个bool类型值（整数），用于排序的比较。
//   &u是对于结构体Book中某一实例的引用，在结构体中进行比较说明。
//   三种情况：（1）前两个元素相同，返回值为第三个元素比较的结果
//            （2）只有第一个元素相同，返回值为第二个元素比较的结果
//            （3）第一个元素就不相同，返回值为第一个元素比较的结果
// 4.上例中对'<'进行重载，原因是sort函数的运算是升序排列。
// 5.reverse函数的替代：对operator < 结构体中的返回值做其反面（逻辑的倒置）。