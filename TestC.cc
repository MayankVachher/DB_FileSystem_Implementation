#include "LinearHash.cc"

using namespace std;

int main() {
	LinearHash testObj = LinearHash(1);
	char insert;
	long element;
	long counter = 0;
	
	cin>>insert;

	while(insert!='0') {
		if(insert=='p') {
			testObj.printTable();
		}
		else{
			cin>>element;
			counter += 1;
			long splitCost = testObj.add_element(element);
			if(splitCost) {
				cout<<counter<<","<<splitCost<<endl;
			}
		}
		cin>>insert;
	}
	return 0;
}