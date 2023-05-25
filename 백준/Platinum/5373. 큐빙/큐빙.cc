#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum
{
    U, D, F, B, L, R
};

vector<vector<vector<char>>> cube(6);

void U_(char c)
{
    int n;
    if (c == '+')
        n = 0;
    else
        n = 2;

    vector<char> tmp(3);
    for (int i = 0; i < 3; i++)
        tmp[i] = cube[L][n][i];
    for (int i = 0; i < 3; i++)
        cube[L][n][i] = cube[F][n][i];
    for (int i = 0; i < 3; i++)
        cube[F][n][i] = cube[R][n][i];
    for (int i = 0; i < 3; i++)
        cube[R][n][i] = cube[B][n][i];
    for (int i = 0; i < 3; i++)
        cube[B][n][i] = tmp[i];
}

void D_(char c)
{
    int n;
    if (c == '+')
        n = 2;
    else
        n = 0;

    vector<char> tmp(3);
    for (int i = 0; i < 3; i++)
        tmp[i] = cube[L][n][i];
    for (int i = 0; i < 3; i++)
        cube[L][n][i] = cube[B][n][i];
    for (int i = 0; i < 3; i++)
        cube[B][n][i] = cube[R][n][i];
    for (int i = 0; i < 3; i++)
        cube[R][n][i] = cube[F][n][i];
    for (int i = 0; i < 3; i++)
        cube[F][n][i] = tmp[i];
}

void F_(char c)
{
    int n, r;
    if (c == '+')
        n = 2, r = 0;
    else
        n = 0, r = 2;

    vector<char> tmp(3);
    for (int i = 0; i < 3; i++)
        tmp[i] = cube[U][n][i];
    for (int i = 0; i < 3; i++)
        cube[U][n][i] = cube[L][2-i][n];
    for (int i = 0; i < 3; i++)
        cube[L][i][n] = cube[D][r][i];
    for (int i = 0; i < 3; i++)
        cube[D][r][i] = cube[R][2-i][r];
    for (int i = 0; i < 3; i++)
        cube[R][i][r] = tmp[i];
}

void B_(char c)
{
    int n, r;
    if (c == '+')
        n = 0, r = 2;
    else
        n = 2, r = 0;

    vector<char> tmp(3);
    for (int i = 0; i < 3; i++)
        tmp[i] = cube[U][n][i];
    for (int i = 0; i < 3; i++)
        cube[U][n][i] = cube[R][i][r];
    for (int i = 0; i < 3; i++)
        cube[R][i][r] = cube[D][r][2-i];
    for (int i = 0; i < 3; i++)
        cube[D][r][i] = cube[L][i][n];
    for (int i = 0; i < 3; i++)
        cube[L][i][n] = tmp[2 - i];
}

void L_(char c)
{
    int n, r;
    if (c == '+')
        n = 0, r = 2;
    else
        n = 2, r = 0;
    
    vector<char> tmp(3);
    for (int i = 0; i < 3; i++)
        tmp[i] = cube[U][i][n];
    for (int i = 0; i < 3; i++)
        cube[U][i][n] = cube[B][2-i][r];
    for (int i = 0; i < 3; i++)
        cube[B][i][r] = cube[D][2-i][n];
    for (int i = 0; i < 3; i++)
        cube[D][i][n] = cube[F][i][n];
    for (int i = 0; i < 3; i++)
        cube[F][i][n] = tmp[i];
}

void R_(char c)
{
    int n, r;
    if (c == '+')
        n = 2, r = 0;
    else
        n = 0, r = 2;
    
    vector<char> tmp(3);
    for (int i = 0; i < 3; i++)
        tmp[i] = cube[U][i][n];
    for (int i = 0; i < 3; i++)
        cube[U][i][n] = cube[F][i][n];
    for (int i = 0; i < 3; i++)
        cube[F][i][n] = cube[D][i][n];
    for (int i = 0; i < 3; i++)
        cube[D][i][n] = cube[B][2-i][r];
    for (int i = 0; i < 3; i++)
        cube[B][i][r] = tmp[2 - i];
}
void RotateRightArray(vector<vector<char>>& arr)
{
    vector<vector<char>> tmp(3, vector<char>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tmp[j][2 - i] = arr[i][j];
        }
    }

    arr = tmp;
}

void RotateLeftArray(vector<vector<char>>& arr)
{
    vector<vector<char>> tmp(3, vector<char>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tmp[2 - j][i] = arr[i][j];
        }
    }

    arr = tmp;
}

void Spin(int face, char c)
{
    if (c == '+')
        RotateRightArray(cube[face]);
    else
        RotateLeftArray(cube[face]);

    switch (face)
    {
    case U:
        if (c == '+')
            U_('+');
        else
            D_('-');
        break;
    
    case D:
        if (c == '+')
            D_('+');
        else
            U_('-');
        break;

    case F:
        if (c == '+')
            F_('+');
        else
            B_('-');
        break;

    case B:
        if (c == '+')
            B_('+');
        else
            F_('-');
        break;

    case L:
        if (c == '+')
            L_('+');
        else
            R_('-');
        break;

    case R:
        if (c == '+')
            R_('+');
        else
            L_('-');
        break;

    default:
        break;
    }
}

int CharToFace(char c)
{
    switch (c)
    {
    case 'U':
        return U;
    case 'D':
        return D;
    case 'F':
        return F;
    case 'B':
        return B;
    case 'L':
        return L;
    case 'R':
        return R;
    }

    return 0;
}


void print_cube()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 3; j++)
        {
            cout << cube[U][i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << cube[L][i][j];
        }

        for (int j = 0; j < 3; j++)
        {
            cout << cube[F][i][j];
        }
        for (int j = 0; j < 3; j++)
        {
            cout << cube[R][i][j];
        }
        for (int j = 0; j < 3; j++)
        {
            cout << cube[B][i][j];
        }


        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 3; j++)
        {
            cout << cube[D][i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        cube[U] = vector<vector<char>>(3, vector<char>(3, 'w'));
        cube[D] = vector<vector<char>>(3, vector<char>(3, 'y'));
        cube[F] = vector<vector<char>>(3, vector<char>(3, 'r'));
        cube[B] = vector<vector<char>>(3, vector<char>(3, 'o'));
        cube[L] = vector<vector<char>>(3, vector<char>(3, 'g'));
        cube[R] = vector<vector<char>>(3, vector<char>(3, 'b'));

        int n;
        cin >> n;
        while (n--)
        {
            string cmd;
            cin >> cmd;

            Spin(CharToFace(cmd[0]), cmd[1]);
            //print_cube();
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << cube[U][i][j];
            }
            cout << endl;
        }
        
    }
    

    return 0;
}