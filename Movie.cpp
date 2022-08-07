// Movie.cpp
#include "Movie.h"



int Movie::getPriceCode() const { return moviePriceCode; }

void Movie::setPriceCode(int arg) { moviePriceCode = arg; }

std::string Movie::getTitle() const { return movieTitle; }
char* Movie::getTypeName() const { return (char*)stMovieInfo.m_szTypeName; }

double Movie::getBaseAmount() const { return stMovieInfo.m_dBaseAmount; }
double Movie::getExtraAmount_BaseDays() const { return stMovieInfo.m_dExtraAmount_BaseDays; }
double Movie::getExtraAmount_PerDays() const { return stMovieInfo.m_dExtraAmount_PerDays; }
double Movie::getBasePoint() const { return stMovieInfo.m_dBasePoint; }
double Movie::getExtraPoint_BaseDays() const { return stMovieInfo.m_dExtraPoint_BaseDays; }
double Movie::getExtraPoint_PerDays() const { return stMovieInfo.m_dExtraPoint_PerDays; }