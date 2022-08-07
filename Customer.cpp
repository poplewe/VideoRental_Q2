// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

struct stPrintEach
{
    char szName[100] = "";
    char szType[100] = "";
    int iDayRent = 0;
    int iAmount = 0;
};

std::string Customer::statement()
{
  double totalAmount = 0.;
  int frequentRenterPoints = 0;

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();

  int PrintSize = customerRentals.size();
  stPrintEach* PrintEach = new stPrintEach[PrintSize];

  // result will be returned by statement()
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";


  // Loop over customer's rentals
  int iPrintIdx = 0;
  for ( ; iter != iter_end; ++iter ) {

    double thisAmount = 0.;
    Rental each = *iter;
    strcpy_s(PrintEach[iPrintIdx].szName, sizeof(PrintEach[iPrintIdx].szName), each.getMovie().getTitle().c_str());
    PrintEach[iPrintIdx].iDayRent = each.getDaysRented();

    // Determine amounts for each rental
    switch ( each.getMovie().getPriceCode() ) {

      case Movie::REGULAR:
        thisAmount += 2.;
        if ( each.getDaysRented() > 2 )
          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
        strcpy_s(PrintEach[iPrintIdx].szType, sizeof(PrintEach[iPrintIdx].szType), "REGULAR");
        break;

      case Movie::NEW_RELEASE:
        thisAmount += each.getDaysRented() * 3;
        strcpy_s(PrintEach[iPrintIdx].szType, sizeof(PrintEach[iPrintIdx].szType), "NEW_RELEASE");
        break;

      case Movie::CHILDRENS:
        thisAmount += 1.5;
        if ( each.getDaysRented() > 3 )
          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
        strcpy_s(PrintEach[iPrintIdx].szType, sizeof(PrintEach[iPrintIdx].szType), "CHILDRENS");
        break;
      case Movie::EXAMPLE_GENRE:
          thisAmount += 1;
          if (each.getDaysRented() > 1)
          {
              thisAmount += (each.getDaysRented() - 1) * 1.5;
          }
          strcpy_s(PrintEach[iPrintIdx].szType, sizeof(PrintEach[iPrintIdx].szType), "EXAMPLE_GENRE");
          break;
    }

    // Add frequent renter points
    frequentRenterPoints++;

    // Add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;
    if ((each.getMovie().getPriceCode() == Movie::EXAMPLE_GENRE) &&
        (each.getDaysRented() > 1)) frequentRenterPoints += (each.getDaysRented() - 1) * 1;
    // Show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << std::endl;
    totalAmount += thisAmount;

    PrintEach[iPrintIdx].iAmount = thisAmount;
    iPrintIdx++;
  }

  // Add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points"<<std::endl;
  //add details
  result << "장르\t제목\t대여기간\t가격\t" << std::endl;
  for (int idx = 0; idx < PrintSize; idx++)
  {
      result << "(" << PrintEach[idx].szType << "\t" << PrintEach[idx].szName << "\t" << PrintEach[idx].iDayRent << "\t" << PrintEach[idx].iAmount << ")" << std::endl;
  }
  delete[] PrintEach;
  return result.str();
}
