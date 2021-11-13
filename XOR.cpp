#include <iostream>
#include <thread>
#include <vector>

using namespace std;
int done_count = 0;
int T;
int MAX_X = 2500;
std::vector<long long int> answer;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin >> T;
    std::vector<std::vector<long long int>> input_wrapper;

    for (register int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        std::vector<long long int> input;
        answer.push_back(-1);

        long long int inp;
        for (register int j = 0; j < N; j++)
        {
            std::cin >> inp;
            input.push_back(inp);
        }

        input_wrapper.push_back(input);

        auto process = [](std::vector<long long int> input_array, int i, int data_len)
        {
            for (register int x = 0; x <= MAX_X; x++)
            {
                if (data_len == 1)
                {
                    long long int bigInteger = input_array[0];
                    if (bigInteger == 0)
                    {
                        answer[i] = 0;
                    }
                    break;
                }
                else
                {
                    long long int xor_value = (input_array[0] + x) ^ (input_array[1] + (x));
                    for (register int m = 2; m < data_len; m++)
                    {
                        xor_value = xor_value ^ (input_array[m] + (x));
                    }
                    if (xor_value == 0)
                    {
                        answer[i] = (x);
                        break;
                    }
                }
            }

            done_count++;

            if (done_count == T)
            {
                for (register int k = 0; k < T; k++)
                {
                    std::cout << answer[k] << "\n";
                }
            }
            return 0;
        };

        thread th(process, std::ref(input_wrapper[i]), i, N);
        th.join();
    }

    return 0;
}
