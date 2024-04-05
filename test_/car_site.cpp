#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
char f_1(char cs)
{
    if (cs == 'N')
        return 'W';
    else if (cs == 'W')
        return 'S';
    else if (cs == 'S')
        return 'E';
    else if (cs == 'E')
        return 'N';
}
char f_2(char cs)
{
    if (cs == 'N')
        return 'E';
    else if (cs == 'E')
        return 'S';
    else if (cs == 'S')
        return 'W';
    else if (cs == 'W')
        return 'N';
}
char command_(int command, char cs)
{
    switch (command)
    {
    case 0:
        return 'N';
    case 1:
        return f_1(cs);
    case 2:
        return f_2(cs);
    }
}
int main()
{
    int time0 = 0, time = 0, command0 = 0, command = 0, x = 0, y = 0;
    char cs = 'N';
    while (command0 != 3)
    {
        cin >> time >> command;
        int diff = time - time0;
        time0 = time;
        cs = command_(command0, cs);
        switch (cs)
        {
        case 'N':
            y += diff * 10;
            break;
        case 'W':
            x -= diff * 10;
            break;
        case 'S':
            y -= diff * 10;
            break;
        case 'E':
            x += diff * 10;
            break;
        }
        command0 = command;
    }
    cout << x << ' ' << y;
    return 0;
}