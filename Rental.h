// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;

private:
  Movie rentedMovie;
  int nDaysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented ):
  rentedMovie( movie ),
  nDaysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return nDaysRented; }

inline const Movie& Rental::getMovie() const { return rentedMovie; }

#endif // RENTAL_H
