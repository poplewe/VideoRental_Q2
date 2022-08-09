// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <fstream>
#include <string>



const char MovieTypeListFile[100] = "MovieType.txt";
const char MovieListFile[100] = "MovieTitle.txt";

const int iMax_Type = 4;
/*
	eREGULAR		= 0
    eNEW_RELEASE	= 1
    eCHILDRENS		= 2
    eEAXMPLE_GENRE	= 3

*/
enum eTypeNum
{
    eREGULAR = 0,
    eNEW_RELEASE,
    eCHILDRENS,
    eEXAMPLE_GENRE
};


const int iType_Info_Num = 7;
/*
	m_szTypeName[100]			= typename
	m_iBaseAmount				= baseAmount
	m_iExtraAmount_BaseDays		= base2extraDay(Amount)
	m_iExtraAmount_PerDays		= extratAmount(Per Day)
	m_iBasePoint				= basePoint
	m_iExtraPoint_BaseDays		= base2extraDay(Point)
	m_iExtraPoint_PerDays		= extraPoint(Per Day)
*/
struct STTYPEINFO
{
	    char		m_szTypeName[100];
	    double		m_dBaseAmount;
	    double		m_dExtraAmount_BaseDays;
	    double		m_dExtraAmount_PerDays;
	    double		m_dBasePoint;
	    double		m_dExtraPoint_BaseDays;
	    double		m_dExtraPoint_PerDays;
};

class Movie {
public:

  Movie( const std::string& title="", int priceCode = eREGULAR);

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;
  char*	 getTypeName() const;
  double getBaseAmount() const;
  double getExtraAmount_BaseDays() const;
  double getExtraAmount_PerDays() const;
  double getBasePoint() const;
  double getExtraPoint_BaseDays() const;
  double getExtraPoint_PerDays() const;


private:
  std::string movieTitle;
  int moviePriceCode;
  STTYPEINFO stMovieInfo;
};

extern int iTypeMax;
extern STTYPEINFO* stMovieType;
extern int iMovieListMax;
extern Movie* MovieList;


//common function
const int FileDataCount(const char* FileName);
//Load Movie Type
void MovieTypeFileLoad(const char* FileName);
void LoadTypeInfo(STTYPEINFO* TypeInfo, int TypeIdx, char* source);
//Load Moive List
void LoadMovieList(const char* FileName);
//Movie Search
int MovieSearch(char* MovieName);

#endif // MOVIE_H
