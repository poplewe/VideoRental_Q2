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
    cout << customer.statement() << endl;

    customer=Customer{ "°í°´ 2" };
    cout << customer.statement() << endl;


    Free_All();
   
    return 0;
}


