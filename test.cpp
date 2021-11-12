// CPP program to create an empty vector
// and push values one by one.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int n = -1;

    // Create a vector of size n with
    // all values as 10.
    vector<long long int> vect;

    while(n != 0) {
        cin >> n;
        vect.push_back(n);
    }
    
    vect.back();
    vect.pop_back();

    for (long long int x : vect)
        cout << x << " ";

    return 0;
}
