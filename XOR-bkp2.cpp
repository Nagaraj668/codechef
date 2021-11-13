#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
int done_count = 0;
int T;
int MAX_X = 10;
std::vector<long long int> answer;

int log(string log_msg)
{
    std::ofstream outfile;
    outfile.open("logs.txt", std::ios_base::app);
    outfile << log_msg + "\n";
    return 0;
}

int reset_log()
{
    std::ofstream ofs;
    ofs.open("logs.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    return 0;
}

int main()
{
    reset_log();
    std::cin >> T;
    std::vector<std::vector<long long int>> input_wrapper;

    for (int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        std::vector<long long int> input;
        answer.push_back(-1);

        long long int inp;
        for (int j = 0; j < N; j++)
        {
            std::cin >> inp;
            input.push_back(inp);
        }

        input_wrapper.push_back(input);
        
        log("input values: ");
        for (int j = 0; j < N; j++)
        {
            log(to_string(input[j]));
        }

        auto process = [](std::vector<long long int> input_array, int i, int data_len)
        {
            log("Processing index: " + to_string(i));

            log("Lambda Params: ");
            log("input array: ");

            for (long long int h : input_array)
            {
                log(to_string(h));
            }

            log("data_len: " + to_string(data_len));

            int x = 0;
            while (true)
            {
                if (data_len == 1)
                {
                    long long int bigInteger = input_array[0];
                    if (bigInteger == 0)
                    {
                        answer[i] = 0;
                        break;
                    }
                    /* {
                        answer[i] = -1;
                        break;
                    } */
                }
                else
                {
                    long long int xor_value = (input_array[0] + x) ^ (input_array[1] + (x));
                    log("data_len value: " + to_string(data_len));

                    log(to_string((input_array[0] + x)));
                    log(to_string((input_array[1] + x)));
                    log(to_string((input_array[2] + x)));

                    log("(input_array[0] + x) ^ (input_array[1] + x) ^ (input_array[2] + x)): ");
                    log(to_string((input_array[0] + x) ^ (input_array[1] + x) ^ (input_array[2] + x)));

                    log(to_string(xor_value));

                    for (int m = 2; m < data_len; m++)
                    {
                        xor_value = xor_value ^ (input_array[m] + (x));
                    }

                    log("xor value: " + to_string(xor_value));
                    if (xor_value == 0)
                    {
                        log("xor value is 0, x value: " + to_string(x));
                        answer[i] = (x);
                        break;
                    }
                }
                x = x + 1;
                if (x == (MAX_X))
                {
                /*     answer[i] = -1; */
                    break;
                }
            }

            done_count++;
            log("done_count: " + to_string(done_count));

            if (done_count == T)
            {
                log("done count is equal to T: ");
                log("answer: ");
                for (int k = 0; k < T; k++)
                {
                    std::cout << answer[k] << endl;
                    log(to_string(answer[k]));
                }
            }
        };

        std::vector<long long int> duplicate;

        for (int k = 0; k < N; k++)
        {
            duplicate.push_back(input[k]);
        }

        thread th(process, std::ref(input_wrapper[i]), i, N);
        th.join();
    }

    return 0;
}
