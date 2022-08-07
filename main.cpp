#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "�Ϲ� 1", Movie::REGULAR };
    Movie regular2{ "�Ϲ� 2", Movie::REGULAR };
    Movie newRelease1{ "���� 1", Movie::NEW_RELEASE };
    Movie newRelease2{ "���� 2",Movie::NEW_RELEASE };
    Movie children1{ "��� 1", Movie::CHILDRENS };
    Movie children2{ "��� 2", Movie::CHILDRENS };
    Movie newGen1{ "�űԼ��� 1", Movie::EXAMPLE_GENRE };
    Movie newGen2{ "�űԼ��� 2", Movie::EXAMPLE_GENRE };

    Customer customer{ "����" };

    customer.addRental({ regular1, 2 });
    customer.addRental({ regular2, 3 });
    customer.addRental({ newRelease1, 1 });
    customer.addRental({ newRelease2, 2 });
    customer.addRental({ children1, 3 });
    customer.addRental({ children2, 4 });
    customer.addRental({ newGen1, 4 });
    customer.addRental({ newGen2, 2 });

    cout << customer.statement() << endl;

    return 0;
}