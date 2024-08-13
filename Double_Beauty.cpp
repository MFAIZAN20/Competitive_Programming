#include <iostream.h>

using namespace std;

int maxDoubleBeauty(vector <int> numArray,int KSize)
{
    int PermutationSum = 0;
    for (int i = 1; i <= KSize; ++i)
    {
        numArray[i] = numArray[i] * 2;
        PermutationSum += numArray[i];
    }    
    return PermutationSum;
}

int main()
{
    int N,K,Element;
    vector<int> NumArray;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> Element;
        NumArray.push_back(Element);         
    }

    int DoubleBeauty = maxDoubleBeauty(NumArray,K);
    cout << DoubleBeauty;

    return 0;
}
