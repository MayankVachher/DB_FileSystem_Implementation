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
	long successful_searches = 0;
	long search_costs = 0;


	cin>>insert;
	while(insert!='0') {
		if(insert == 'i') {
			cin>>element;
			testObj.add_element(element);
		}
		else if(insert == 's') {
			cin>>element;
			search_costs += testObj.find(element);
			successful_searches += 1;
		}
		else if(insert == 'c') {
			cout<<double(search_costs)/successful_searches<<endl;
			successful_searches = 0;
			search_costs = 0;
		}
		cin>>insert;
	}
	return 0;
}