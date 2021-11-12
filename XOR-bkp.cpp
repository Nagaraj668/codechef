#include <iostream>
using namespace std;

int main()
{
    int T;
    std::cin >> T;
    long long int answer[T];
    int MAX_X = 1000;

    for (int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        long long int input[N];

        for (int j = 0; j < N; j++)
        {
            std::cin >> input[j];
        }

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
        }
    }

    for (int k = 0; k < T; k++)
    {
        std::cout << answer[k] << endl;
    }
}
