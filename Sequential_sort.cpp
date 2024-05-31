#include <iostream>
#include <string>
#include <vector>
#include <omp.h>

using namespace std;
using std::string;


void sequential_sort( vector<unsigned int >& X){
    unsigned int i, j ,count, N = X.size();
    vector<unsigned int > tmp(N);
    #pragma omp parallel for private(j)
    for (i = 0; i < N; i++)    {
        count = 0;
        for ( j = 0; j < N; j++){
            if (X[j] < X[i] || X[j] == X[i] && j < i)
            {
                count ++;
            }
        }
        tmp[count] = X[i];
    }
    std::copy(tmp.begin(), tmp.end(), X.begin());
}

int main(int argc, char const *argv[])
{
    vector<unsigned int> Test(rand());

    sequential_sort(Test);
    for(int i=0;i< Test.size() ; i++){
		cout<<(" [%d]",Test[i]);
	}
    return 0;
}
