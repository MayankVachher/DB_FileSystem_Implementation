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
	long successful_searches = 0;
	long search_costs = 0;


	cin>>insert;
	while(insert) {
		cin>>element;
		if(insert == 1) {
			testObj.add_element(element);
		}
		else if(insert == 2) {
			search_costs += testObj.find(element);
		}
		else if(insert == 3) {
			cout<<double(search_costs)/successful_searches<<endl;
			successful_searches = 0;
			search_costs = 0;
		}
		cin>>insert;
	}
	return 0;
}