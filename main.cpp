#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;


void Free_All()
{
    delete[] MovieList;
    delete[] stMovieType;
}

int main()
{
    MovieTypeFileLoad(MovieTypeListFile);
    LoadMovieList(MovieListFile);
    
    Customer customer{ "°í°´ 1" };
    customer.FindRentList();
    cout << "Q1: Print Details?(0:Not Use, 1: Use):" << endl;
    cin >> customer.bUseDetails;
    if (customer.bUseDetails == true)
    {
        cout << "Q2: Print Each Amounts?(0:Not Use, 1: Use):" << endl;
        cin >> customer.bShowAmount;
        cout << "Q3: Print Each Pooint?(0:Not Use, 1: Use):" << endl;
        cin >> customer.bShowPoint;
    }
    cout << "Print Receipt...." << endl;
    cout << customer.statement() << endl;

    cout << "\n\nWait Next Customer....\n\n" << endl;;
    customer=Customer{ "°í°´ 2" };
    customer.FindRentList();
    cout << "Q1: Print Details?(0:Not Use, 1: Use):" << endl;
    cin >> customer.bUseDetails;
    if (customer.bUseDetails == true)
    {
        cout << "Q2: Print Each Amounts?(0:Not Use, 1: Use):" << endl;
        cin >> customer.bShowAmount;
        cout << "Q3: Print Each Pooint?(0:Not Use, 1: Use):" << endl;
        cin >> customer.bShowPoint;
    }
    cout << "Print Receipt...." << endl;
    cout << customer.statement() << endl;


    Free_All();
   
    return 0;
}


