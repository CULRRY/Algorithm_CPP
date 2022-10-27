#include<iostream>
#include<vector>
using namespace std;
int tmp[1000000];
void merge(vector<int>& a, int low, int mid, int high)
{
    for (int i = low; i <= high; i++)
        tmp[i] = a[i];
    int i, j, k;
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high;)
    {
        if (tmp[i] < tmp[j])
        {
            a[k++] = tmp[i++];
        }
        else
        {
            a[k++] = tmp[j++];
        }
    }
    while (i <= mid)
    {
        a[k++] = tmp[i++];
    }
    while (j <= high)
    {
        a[k++] = tmp[j++];
    }
}

void mergeSort(vector<int> &a, int low, int high)
{
    int mid = (low + high) / 2;
    if (low == high)
        return;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    mergeSort(v, 0, v.size() - 1);
    for (int i = 0; i < N; i++)
    {
        cout <<  v[i] << "\n";
    }

    return 0;
}