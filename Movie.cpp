// Movie.cpp

#include "Movie.h"

using namespace std;




//{typename, baseAmount, base2extraDay(a), extratAmount(Per Day), basePoint, base2extraDay(p),extraPoint(Per Day)}
int iTypeMax = 0;
STTYPEINFO* stMovieType;
int iMovieListMax = 0;
Movie* MovieList;


Movie::Movie(const std::string& title, int priceCode) :
    movieTitle(title),
    moviePriceCode(priceCode)
{
    memcpy_s(&stMovieInfo, sizeof(struct STTYPEINFO), &stMovieType[priceCode], sizeof(struct STTYPEINFO));
}


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


const int FileDataCount(const char* FileName)
{
    string line;
    ifstream file;
    char szline[256] = "";
    int iCount = 0;
    char* ptr = NULL;
    char* context = NULL;

    //count movies list
    file.open(FileName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            strcpy_s(szline, sizeof(szline), line.c_str());
            if ((szline[0] == '#') || (szline[0] == NULL)) continue;
            iCount++;
        }
    }
    else cout << "Usable to open file" << endl;
    file.close();
    return iCount;
}

void MovieTypeFileLoad(const char* FileName)
{
    string line;
    ifstream file;
    char szline[256] = "";
    int idx = 0;

    iTypeMax=FileDataCount(FileName);

    stMovieType = new STTYPEINFO[iTypeMax];

    file.open(FileName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            strcpy_s(szline, sizeof(szline), line.c_str());
            if ((szline[0] == '#') || (szline[0] == NULL)) continue;
            LoadTypeInfo(stMovieType, idx, szline);
            idx++;
        }
    }
    else cout << "Usable to open file" << endl;
    file.close();
}

void LoadTypeInfo(STTYPEINFO* TypeInfo, int TypeIdx, char* source)
{

    STTYPEINFO m_stTypeInfo;
    char szBuf[iType_Info_Num][100] = { 0, };
    char* context = NULL;
    char* ptr = strtok_s(source, ",", &context);
    int idx = 0;
    while (ptr != NULL)
    {
        strcpy_s(szBuf[idx], sizeof(szBuf[idx]), ptr);
        idx++;
        ptr = strtok_s(NULL, ",", &context);
    }

    strcpy_s(m_stTypeInfo.m_szTypeName, sizeof(m_stTypeInfo.m_szTypeName), szBuf[0]);
    if ((szBuf[1][0] >= '0') && (szBuf[1][0] <= '9')) m_stTypeInfo.m_dBaseAmount = atof(szBuf[1]);
    if ((szBuf[2][0] >= '0') && (szBuf[2][0] <= '9')) m_stTypeInfo.m_dExtraAmount_BaseDays = atof(szBuf[2]);
    if ((szBuf[3][0] >= '0') && (szBuf[3][0] <= '9')) m_stTypeInfo.m_dExtraAmount_PerDays = atof(szBuf[3]);
    if ((szBuf[4][0] >= '0') && (szBuf[4][0] <= '9')) m_stTypeInfo.m_dBasePoint = atof(szBuf[4]);
    if ((szBuf[5][0] >= '0') && (szBuf[5][0] <= '9')) m_stTypeInfo.m_dExtraPoint_BaseDays = atof(szBuf[5]);
    if ((szBuf[6][0] >= '0') && (szBuf[6][0] <= '9')) m_stTypeInfo.m_dExtraPoint_PerDays = atof(szBuf[6]);
    TypeInfo[TypeIdx] = m_stTypeInfo;
}
void LoadMovieList(const char* FileName)
{
    string line;
    ifstream file;
    char szline[256] = "";
    char* ptr = NULL;
    char* context = NULL;

    //count movies list
    iMovieListMax = FileDataCount(FileName);
    MovieList= new Movie[iMovieListMax];

    
    char szBuf[2][100] = { 0, };
    int iDataIdx = 0,iMovieIdx=0;
    file.open(FileName);
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
            MovieList[iMovieIdx] = Movie(szBuf[0], atoi(szBuf[1]));
            iMovieIdx++;
        }
    }
    else cout << "Usable to open file" << endl;
    file.close();
}


int MovieSearch(char* MovieName)
{
    int iRtn = -1;
    for (int idx = 0; idx < iMovieListMax; idx++)
    {
        if (strcmp(MovieName, MovieList[idx].getTitle().c_str()) == 0)
        {
            iRtn = idx;
            return iRtn;
        }
    }
    return iRtn;
}

