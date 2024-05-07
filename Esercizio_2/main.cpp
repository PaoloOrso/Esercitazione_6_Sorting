//GENERO VETTORE DI LUNGHEZZA SCELTA, IN UN CICLO ESEGUO GLI ALGORITMI DI MERGESORT E BUBBLESORT, MODIFICANDO VIA VIA IL VETTORE, PRENDENDO I TEMPI

#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <SortingAlgorithm.hpp>

using namespace std;
using namespace SortLibrary;

int main()
//int main(int argc, char **argv)
{
  //  cout << argc << endl;
  //  cout << argv[0] << endl;
  //  cout << argv[1] << endl;

    vector<vector<int>> vettori1 = {};
    vector<vector<int>> vettori2 = {};

    int j = 0;
    int k = 0;
    int l = 10;
    int n = 0;
    vector<int> variable1(l);
    vector<int> variable2(l);
    vector<int> fixed(l);
    vector<int> fixed2(l);
    int n_test = 10;

    cout << "Number of tests: " << n_test << endl;
    vector<double> times(n_test);
    vector<double> times2(n_test);
    double sum = 0.0;
    double median = 0.0;
    double sum2 = 0.0;
    double median2 = 0.0;

    generate(fixed.begin(),fixed.end(),[&n] () {return n++;});


    for(int i = 0; i < l; i++)
    {
        fixed[i] = rand() % 10;

    }

    cout << "Initial vector: ";

    for(int i = 0; i < l; i++)
    {
        cout << fixed[i] << " ";

    }

    cout << endl << endl;;

    variable1 = fixed;
    variable2 = fixed;
    fixed2 = fixed;

    //------------------------------------------------------------------------------------------------------------

    vettori1 = PartialSort(fixed);



    for(j = 0; j < n; j++)   //partial sort limit
    {

        for(int i = 0; i < l; i++)
            cout << vettori1[j][i] << " ";

        cout << " , bubblesort: ";


        for(int i = 0; i != n_test; i++)

        {

        chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();

        BubbleSort(vettori1[j]);

        chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

        double duration = chrono::duration_cast<chrono::nanoseconds>(t_end - t_begin).count();

        times[i] = duration;

        variable1 = fixed;

        }

        for(int i = 0; i != n_test; i++)
        {

            sum += times[i];

        }

        median = sum / n_test;

        sum  = 0.0;

        cout << median << endl;

    }

    cout << endl;

    //------------------------------------------------------------------------------------------------------------

    vettori2 = PartialSort(fixed2);

    for(k = 0; k < n; k++)   //partial sort limit
    {

        for(int i = 0; i < l; i++)
            cout << vettori2[k][i] << " ";

        cout << " , mergesort: ";


        for(int i = 0; i != n_test; i++)

        {

            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();

            MergeSort(vettori2[k],0,n-1);

            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

            double duration2 = chrono::duration_cast<chrono::nanoseconds>(t_end - t_begin).count();

            times2[i] = duration2;

            variable2 = fixed2;

        }

        for(int i = 0; i != n_test; i++)
        {

            sum2 += times2[i];

        }

        median2 = sum2 / n_test;

        sum2 = 0.0;

        cout << median2 << endl;

    }

}

