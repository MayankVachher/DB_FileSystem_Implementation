#include "LinearHash.cc"

using namespace std;

int main() {
	LinearHash testObj;
	testObj.printTable();
	testObj.add_element(1);
	testObj.printTable();
	testObj.add_element(2);
	testObj.printTable();
	testObj.add_element(3);
	testObj.printTable();
	testObj.add_element(5);
	testObj.printTable();
	testObj.add_element(8);
	testObj.printTable();
	testObj.add_element(13);
	testObj.printTable();
	testObj.add_element(21);
	testObj.printTable();
	testObj.add_element(34);
	testObj.printTable();
	testObj.add_element(55);
	testObj.printTable();
	return 0;
}