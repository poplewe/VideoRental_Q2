#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "일반 1", eREGULAR };
    Movie regular2{ "일반 2", eREGULAR };
    Movie newRelease1{ "신작 1", eNEW_RELEASE };
    Movie newRelease2{ "신작 2",eNEW_RELEASE };
    Movie children1{ "어린이 1", eCHILDRENS };
    Movie children2{ "어린이 2", eCHILDRENS };
    Movie newGen1{ "신규세대 1", eEXAMPLE_GENRE };
    Movie newGen2{ "신규세대 2", eEXAMPLE_GENRE };
    Movie newGen3{ "신규세대 3", eEXAMPLE_GENRE };
    Movie regular3{ "일반 3", eREGULAR };
    Customer customer{ "고객 1" };

    customer.addRental({ regular1, 2 });
    customer.addRental({ regular2, 3 });
    customer.addRental({ newRelease1, 1 });
    customer.addRental({ newRelease2, 2 });
    customer.addRental({ children1, 3 });
    customer.addRental({ children2, 4 });
    customer.addRental({ newGen1, 4 });
    customer.addRental({ newGen2, 2 });
    customer.addRental({ newGen3, 3 });
    customer.addRental({ regular3, 4 });

    cout << customer.statement() << endl;



    return 0;
}
