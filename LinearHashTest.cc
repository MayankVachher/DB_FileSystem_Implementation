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
	int insert;
	long element;
	cin>>insert;
	while(insert) {
		cin>>element;
		testObj.add_element(element);
		cout<<storage_utilization(testObj)<<endl;
		cin>>insert;
	}
	return 0;
}