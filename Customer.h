// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <sstream>
#include "Rental.h"

struct stPrintEach
{
	char szName[100] = "";
	char szType[100] = "";
	int iDayRent = 0;
	double dAmount = 0;
};

// The customer class represents the customer of the store

class Customer {
public:
  Customer();
  explicit Customer( const std::string& name );

  void addRental( const Rental& arg );
  std::string getName() const;
  //(�帣 ���� �뿩�Ⱓ ����) print
  std::string PrintReceiptDetails();

  // Generate a statement for the customer
  std::string statement();

private:
  std::string customerName;
  std::vector< Rental > customerRentals;
  double dTotalAmount;
  double dfrequentRenterPoints;

};


#endif // CUSTOMER_HH
