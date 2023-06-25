#include "Person.h"
#include <iostream>

using namespace std;

int main()
{
	// (2)
	Person p("Jack", "Smith", "123456", 2000);
	cout << p.get_birth_year() << endl;
	p.print();

	// (3)
	Person* pp = new Person;
	pp->set_given_name("David");
	pp->set_family_name("Johnson");
	pp->set_ID_number("345678");
	pp->set_birth_year(2002);
	pp->print();

	// (4)
	Person* pp2 = new Person("Jack", "Smith", "123456", 2000);
	if (*pp2 == p)
		cout << "Objects are equal" << endl;

	delete pp;
	delete pp2;

	return 0;
}