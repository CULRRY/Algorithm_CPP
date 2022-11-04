#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> heap(100000);
    int size = 0;

    int N;
    cin >> N;

    while (N--)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (size == 0)
                cout << 0 << "\n";
            else
            {
                cout << heap[0] << "\n";
                heap[0] = heap[size-1];
                size--;
                int i = 0;
                while (true)
                {
                    int leftChild = i * 2 + 1;
                    int rightChild = i * 2 + 2;

                    if (leftChild >= size)
                        break;
                    
                    int next = i;
                    if (heap[leftChild] > heap[next])
                    {
                        next = leftChild;
                    }

                    if (rightChild < size && heap[rightChild] > heap[next])
                        next = rightChild;

                    if (next == i)
                        break;
                    
                    ::swap(heap[i], heap[next]);
                    i = next;
                }
            }
        }
        else
        {

            heap[size] = input;
            size++;
            int i = size - 1;
            while (i > 0)
            {

                if (heap[i] < heap[(i - 1) / 2])
                    break;

                int tmp = heap[i];
                heap[i] = heap[(i - 1) / 2];
                heap[(i - 1) / 2] = tmp;
                i = (i - 1) / 2;
            }
            
        }
    }

    return 0;
}