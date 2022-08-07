#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "�Ϲ� 1", eREGULAR };
    Movie regular2{ "�Ϲ� 2", eREGULAR };
    Movie newRelease1{ "���� 1", eNEW_RELEASE };
    Movie newRelease2{ "���� 2",eNEW_RELEASE };
    Movie children1{ "��� 1", eCHILDRENS };
    Movie children2{ "��� 2", eCHILDRENS };
    Movie newGen1{ "�űԼ��� 1", eEXAMPLE_GENRE };
    Movie newGen2{ "�űԼ��� 2", eEXAMPLE_GENRE };
    Movie newGen3{ "�űԼ��� 3", eEXAMPLE_GENRE };
    Movie regular3{ "�Ϲ� 3", eREGULAR };
    Customer customer{ "�� 1" };

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
