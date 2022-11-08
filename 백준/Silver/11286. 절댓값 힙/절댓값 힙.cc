#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> heap;
    cin >> N;
    while (N--)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (heap.size() == 0)
                cout << 0 << "\n";
            else
            {
                cout << heap[0] << "\n";
                ::swap(heap[0], heap[heap.size() - 1]);
                heap.pop_back();

                int now = 0;
                while (true)
                {
                    const int leftChild = now * 2 + 1;
                    const int rightChild = now * 2 + 2;

                    if (leftChild >= heap.size())
                        break;
                    
                    int next = now;
                    if (abs(heap[next]) >= abs(heap[leftChild]))
                    {
                        if (abs(heap[next]) == abs(heap[leftChild]))
                            next = heap[next] > heap[leftChild] ? leftChild : next;   
                        else
                            next = leftChild;
                    }

                    if (rightChild < heap.size() && abs(heap[next]) >= abs(heap[rightChild]))
                    {
                        if (abs(heap[next]) == abs(heap[rightChild]))
                            next = heap[next] > heap[rightChild] ? rightChild : next;
                        else
                            next = rightChild;
                    }

                    if (next == now)
                        break;

                    ::swap(heap[next], heap[now]);
                    now = next;
                }
            }
        }
        else
        {
            heap.push_back(input);
            int now = heap.size() - 1;
            while (now > 0)
            {
                const int parent = (now - 1) / 2;

                if (abs(heap[parent]) >= abs(heap[now]))
                {
                    if (abs(heap[parent]) == abs(heap[now]))
                    {
                        if (heap[parent] < heap[now])
                            break;
                    }

                    ::swap(heap[parent], heap[now]);
                    now = parent;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}