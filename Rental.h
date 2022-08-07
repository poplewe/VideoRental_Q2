// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;
  double getCalcAmount() const;
  double getCalcPoint() const;

private:
  Movie rentedMovie;
  int nDaysRented;
  double dCalcAmount;
  double dCalcPoint;
};

inline Rental::Rental( const Movie& movie, int daysRented ):
  rentedMovie( movie ),
  nDaysRented( daysRented ) 
{

	dCalcAmount = 0;
	dCalcAmount += movie.getBaseAmount();
	if ((movie.getExtraAmount_BaseDays() != 0) && (getDaysRented() > movie.getExtraAmount_BaseDays()))
		dCalcAmount += (getDaysRented() - movie.getExtraAmount_BaseDays()) * movie.getExtraAmount_PerDays();

	dCalcPoint = 0;
	dCalcPoint += movie.getBasePoint();
	if ((movie.getExtraPoint_BaseDays() != 0) && (getDaysRented() > movie.getExtraPoint_BaseDays()))
		dCalcPoint += (getDaysRented() - movie.getExtraPoint_BaseDays()) * movie.getExtraPoint_PerDays();

}

inline int Rental::getDaysRented() const { return nDaysRented; }

inline const Movie& Rental::getMovie() const { return rentedMovie; }

inline double Rental::getCalcAmount() const { return dCalcAmount; }
inline double Rental::getCalcPoint() const { return dCalcPoint; }


#endif // RENTAL_H
