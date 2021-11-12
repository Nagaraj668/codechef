// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
using namespace std;

int array_len;
int done_count;
int main()
{
    int arr[3];
    array_len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < array_len; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < array_len; i++)
    {
        auto f = [](int arr[], int i)
        {
            arr[i] = arr[i] + 1;

            done_count++;
            if (done_count == array_len)
            {
            }
        };
        thread th(f, arr, i);
        th.join();
    }

    cout << "Main thread - End";
    return 0;
}
