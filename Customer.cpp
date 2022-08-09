// Customer.cc
#include "Customer.h"


using namespace std;
using std::ostringstream;
using std::vector;

Customer::Customer() {}

Customer::Customer(const std::string& name) :
	customerName(name) 
{
	char szFilename[100] = "";
	string line;
	char szline[256] = "";
	ifstream file;
	char szBuf[2][100] = { 0, };
	char* ptr = NULL;
	char* context = NULL;
	int iDataIdx = 0;

	//Find Customer Rent List & Calc Amount & Point
	sprintf_s(szFilename, "Customer\\%s.txt", name.c_str());

	file.open(szFilename);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			iDataIdx = 0;
			strcpy_s(szline, sizeof(szline), line.c_str());
			if ((szline[0] == '#') || (szline[0] == NULL)) continue;
			ptr = strtok_s(szline, ",", &context);
			while (ptr != NULL)
			{
				strcpy_s(szBuf[iDataIdx], sizeof(szBuf[iDataIdx]), ptr);
				iDataIdx++;
				ptr = strtok_s(NULL, ",", &context);
			}
			int Movieindex=MovieSearch(szBuf[0]);
			int RentDays = atoi(szBuf[1]);
			addRental({ MovieList[Movieindex],RentDays });
		}
	}
	else cout << "Usable to open file" << endl;
	file.close();

}

void Customer::addRental(const Rental& arg) { customerRentals.push_back(arg); }

std::string Customer::getName() const { return customerName; }

std::string  Customer::PrintReceiptDetails()
{
	std::ostringstream result;
	std::vector< Rental >::iterator iter = customerRentals.begin();
	std::vector< Rental >::iterator iter_end = customerRentals.end();
	stPrintEach PrintInfo;

	result << "장르\t제목\t대여기간\t가격\t" << std::endl;
	for (; iter != iter_end; ++iter)
	{
		Rental each = *iter;
		strcpy_s(PrintInfo.szType, sizeof(PrintInfo.szType), each.getMovie().getTypeName());
		strcpy_s(PrintInfo.szName, sizeof(PrintInfo.szName), each.getMovie().getTitle().c_str());
		PrintInfo.iDayRent = each.getDaysRented();
		PrintInfo.dAmount = each.getCalcAmount();

		result << "(" << PrintInfo.szName << "\t" << PrintInfo.szName << "\t" 
			<< PrintInfo.iDayRent << "\t" << PrintInfo.dAmount << ")" << std::endl;

	}

	return result.str();
}


std::string Customer::statement()
{
  dTotalAmount=0.;
  dfrequentRenterPoints = 0;

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();

  int PrintSize = customerRentals.size();

  // result will be returned by statement()
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";

  // Loop over customer's rentals
  int iPrintIdx = 0;
  for ( ; iter != iter_end; ++iter ) {

    Rental each = *iter;   
    // Determine amounts for each rental
    double thisAmount = each.getCalcAmount();

    // Add frequent renter points
	dfrequentRenterPoints +=each.getCalcPoint();

    // Show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << std::endl;
	dTotalAmount += thisAmount;

  }

  // Add footer lines
  result << "Amount owed is " << dTotalAmount << "\n";
  result << "You earned " << dfrequentRenterPoints
         << " frequent renter points"<<std::endl;
  //add details
  result << PrintReceiptDetails();
  return result.str();
}
