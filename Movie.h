// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

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

const STTYPEINFO stMovieType[iMax_Type]=
{
	//{typename, baseAmount, base2extraDay(a), extratAmount(Per Day), basePoint, base2extraDay(p),extraPoint(Per Day)}
	{ "REGULAR", 2, 2, 1.5, 1, 0, 0 },
	{ "NEW_RELEASE", 3, 1, 3, 1, 1, 1 },
	{ "CHILDRENS", 1.5, 3, 1.5, 1, 0, 0 },
	{ "EXAMPLE_GENRE", 1, 1, 1.5, 1, 1, 1 }

};


class Movie {
public:


  Movie( const std::string& title, int priceCode = eREGULAR );

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

inline Movie::Movie( const std::string& title, int priceCode ): 
  movieTitle( title ),
  moviePriceCode( priceCode )
{
	memcpy_s(&stMovieInfo, sizeof(struct STTYPEINFO), &stMovieType[priceCode], sizeof(struct STTYPEINFO));
}



#endif // MOVIE_H
