#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> v;
    while (x != 0)
    {
        v.push_back(x);
        cin >> x;
    }
    int k = 0, mx = 0;
    vector<int> ans, a;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            a.push_back(v[i]);
        }
        else
        {
            a.clear();
        }
        if (ans.size() < a.size())
        {
            ans = a;
        }
    }

    for (auto el : ans)
    {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}
