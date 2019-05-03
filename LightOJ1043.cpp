#include <bits/stdc++.h>

using namespace std;

int main()
{
    double ab, bc, ac, r, ans;
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> ab >> ac >> bc >> r;
        r = 1 + (1 / r);
        r = (1 / r);
        r = r * (ab * ab);
        ans = sqrt(r);
        printf("Case %d: %.6lf\n", t, ans);
    }
    return 0;
}

