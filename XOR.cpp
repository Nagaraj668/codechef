#include <iostream>
#include <thread>
#include <vector>

using namespace std;
int done_count;
int T;
int MAX_X = 18;

int process(std::vector<long long int> input_array, int i, int data_len, int answers[])
{
    long long int x = 0;
    while (true)
    {

        if (data_len == 1)
        {
            long long int bigInteger = input_array[0];
            if (bigInteger == 0)
            {
                answers[i] = 0;
                break;
            }
            else
            {
                answers[i] = -1;
                break;
            }
        }
        else
        {
            long long int xorValue = (input_array[0] + x) ^ (input_array[1] + (x));
            for (int m = 2; m < data_len; m++)
            {
                xorValue = xorValue ^ (input_array[m] + (x));
            }

            if (xorValue == 0)
            {
                answers[i] = x;
                break;
            }
        }
        x = x + 1;
        if (x == (MAX_X))
        {
            answers[i] = -1;
            break;
        }
    }

    done_count++;

    if (done_count == T)
    {
        for (int i; i < answers.size(); i++)
        {
            cout << answers[i];
        }
    }
    return 0;
}

int main()
{
    std::cin >> T;
    vector<long long int> answer(T);

    for (int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        vector<long long int> input(N);
        long long int inp;
        for (int j = 0; j < N; j++)
        {
            std::cin >> inp;
            input.push_back(inp);
        }

        std::thread thread_object(process, input, i, N, answer);
        thread_object.join();
        /* 
        long long int x = 0;
        while (true)
        {

            if (N == 1)
            {
                long long int bigInteger = input[0];
                if (bigInteger == 0)
                {
                    answer[i] = 0;
                    break;
                }
                else
                {
                    answer[i] = -1;
                    break;
                }
            }
            else
            {
                long long int xorValue = (input[0] + x) ^ (input[1] + (x));
                for (int m = 2; m < N; m++)
                {
                    xorValue = xorValue ^ (input[m] + (x));
                }

                if (xorValue == 0)
                {
                    answer[i] = x;
                    break;
                }
            }
            x = x + 1;
            if (x == (MAX_X))
            {
                answer[i] = -1;
                break;
            }
        } */
    }

    /* for (int k = 0; k < T; k++)
    {
        std::cout << answer[k] << endl;
    } */
}
