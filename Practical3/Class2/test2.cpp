#include <iostream>
#include "xClass.h"

using namespace std;

int main()
{
	xClass* px = new xClass(10, 100);
	px->print_data();

	cout << px->ave_data() << endl;
	cout << px->data_at(5) << endl;
	cout << px->range_data(40, 50) << endl;

	xClass* py = new xClass(*px);
	py->print_data();

	*px += *py;
	px->print_data();

	*py += *px;
	py->print_data();

	delete px;
	delete py;

	return 0;
}

int main1()
{
	xClass x(10, 100);
	x.print_data();

	cout << x.ave_data() << endl;
	cout << x.data_at(5) << endl;
	cout << x.range_data(40, 50) << endl;

	xClass y = x;
	y.print_data();

	x += y;
	x.print_data();

	y += x;
	y.print_data();

	return 0;
}
