#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    int left, right;
};
vector<node> v;

void preOrder(int root)
{
    if (root == -1)
        return;
    else
    {
        cout << v[root].data;
        preOrder(v[root].left);
        preOrder(v[root].right);
    }
}

void inOrder(int root)
{
    if (root == -1)
        return;
    else
    {
        inOrder(v[root].left);
        cout << v[root].data;
        inOrder(v[root].right);
    }
}

void postOrder(int root)
{
    if (root == -1)
        return;
    else
    {
        postOrder(v[root].left);
        postOrder(v[root].right);
        cout << v[root].data;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    v.assign(N, node());

    for (int i = 0; i < N; i++)
    {
        char data;
        char left, right;
        cin >> data >> left >> right;
        if (left == '.')
            left = -1;
        else 
            left = left - 'A';

        if (right == '.')
            right = -1;
        else
            right = right - 'A';
            
        v[data - 'A'].data = data;
        v[data - 'A'].left = left;
        v[data - 'A'].right = right;
    }

    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);

    return 0;
}