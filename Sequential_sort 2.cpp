#include <iostream>
#include <string>
#include <vector>
#include <omp.h>

using namespace std;
using std::string;

void quickSort(int *array, int ini, int fim)
{
    int i = ini;
    int j = fim;
    int pivo = array[(i + j) / 2];
    int temp;

    while (i <= j){
        while (array[i] < pivo)
            i++;
        while (array[j] > pivo)
            j--;
        if (i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > ini)
        quickSort(array, ini, j);
    if (i < fim)
        quickSort(array, i, fim);
}

void ShowArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << endl;
}

int main()
{
    int array[] = {95,55,789,1,9,2,15151,70};
    int n = sizeof(array)/sizeof(array[0]);

    cout << "Antes :" << endl;
    ShowArray(array, n);
    quickSort(array, 0, n);

    cout << "Depois :" << endl;
    ShowArray(array, n);
    return 0;
}