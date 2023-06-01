#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Directory
{
    map<string, Directory&> subdir;
    set<string> files;
};

map<string, Directory> idx;

void Query(string dir, map<string, int> &result);

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    idx = map<string, Directory>();


    for (int i = 0; i < n + m; i++)
    {
        string root, sub;
        int type;
        cin >> root >> sub >> type;

        auto rdir = idx.find(root);
        if (rdir == idx.end())
        {
            idx.insert({root, Directory{}});
        }

        Directory& now = idx.find(root)->second;

        if (type == 1)
        {
            if (idx.find(sub) == idx.end())
                idx.insert({sub, Directory{}});
            now.subdir.insert({sub, idx[sub]});
        }
        else
        {
            now.files.insert(sub);
        }
    }


    int q;
    cin >> q;
    while (q--)
    {
        string route;
        cin >> route;
        string lastRoute = "";

        for (char c : route)
        {
            if (c == '/')
            {
                lastRoute = "";
                continue;
            }

            lastRoute += c;
        }
        map<string, int> result;
        Query(lastRoute, result);
        int cnt = 0;
        for (auto it : result)
        {
            cnt += it.second;
        }
        cout << result.size() << " " << cnt << endl;

    }
    

    return 0;
}

void Query(string dir, map<string, int>& result)
{
    Directory& now = idx.find(dir)->second;

    for (auto it : now.files)
    {
        result[it]++;
    }

    for (auto it : now.subdir)
    {
        Query(it.first, result);
    }
}