#include "LinearHash.cc"

using namespace std;

double storage_utilization(LinearHash obj) {
	long N = obj.get_num_records();
	long B = obj.get_num_buckets();
	long b = obj.get_bucket_capacity();

	double metricA = double(N)/(B*b);
	return metricA;
}

int main() {
	LinearHash testObj = LinearHash(10);
	char insert;
	long element;
	long counter=0;

	cin>>insert;
	while(insert!='0') {
		if(insert=='p') {
			testObj.printTable();
		}
		else {
			cin>>element;
			counter = 0;
			testObj.add_element(element);
			cout<<storage_utilization(testObj)<<endl;
		}
		cin>>insert;
	}
	return 0;
}