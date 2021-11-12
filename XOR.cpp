#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
int done_count;
int T;
int MAX_X = 18;

int log(string log_msg)
{
    std::ofstream outfile;
    outfile.open("logs.txt", std::ios_base::app);
    outfile << log_msg + "\n";
    return 0;
}

int main()
{
    std::cin >> T;
    std::vector<long long int> answer(T);

    for (int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        std::vector<long long int> input;
        long long int inp;
        for (int j = 0; j < N; j++)
        {
            std::cin >> inp;
            input.push_back(inp);
        }

        log("input values: ");
        for (int j = 0; j < N; j++)
        {
            log(to_string(input[j]));
        }

        log("Processing index" + to_string(i));
        int x = 0;
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
                long long int xor_value = (input[0] + x) ^ (input[1] + (x));
                log("data_len value: " + to_string(N));

                log(to_string((input[0] + x)));
                log(to_string((input[1] + x)));
                log(to_string((input[2] + x)));

                log("(input[0] + x) ^ (input[1] + x) ^ (input[2] + x)): ");
                log(to_string((input[0] + x) ^ (input[1] + x) ^ (input[2] + x)));

                log(to_string(xor_value));

                for (int m = 2; m < N; m++)
                {
                    xor_value = xor_value ^ (input[m] + (x));
                }

                log("xor value: " + to_string(xor_value));
                if (xor_value == 0)
                {
                    log("xor value is 0, x value: " + to_string(x));
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
        }

        done_count++;
        if (done_count == T)
        {
            for (int k = 0; k < T; k++)
            {
                std::cout << answer[k] << endl;
            }
        }
    }
    return 0;
}
