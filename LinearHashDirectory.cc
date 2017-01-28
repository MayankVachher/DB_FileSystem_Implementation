#include "LinearHashBucket.cc"

using namespace std;

class directory
{
	std::vector<bucket> buckets;
	long modBase;
	long bkt_size;
	bool data_present;

public:
	directory();

	directory(long bucket_size, long base) {
		modBase = base;
		data_present = false;
		bkt_size = bucket_size;
	}

	long get_base() {
		return modBase;
	}

	void set_base(long base) {
		modBase = base;
	}

	bool hasOverflow() {
		return buckets.size() > 1;
	}

	bool hasData() {
		return data_present;
	}

	std::vector<long> initate_refactor() {
		std::vector<long> store;
		std::vector<long> retrieved;
		for(long i = 0; i<buckets.size(); i++) {
			retrieved = buckets[i].get_data();
			store.insert(store.end(), retrieved.begin(), retrieved.end());
		}
		buckets.clear();

		data_present = false;

		return store;
	}

	void printData() {

		std::vector<long> retrieved = buckets[0].get_data();
		cout<<"("<<retrieved[0];
		for(long i=1; i<retrieved.size(); i++) {
			cout<<", "<<retrieved[i];
		}
		cout<<")";

		for(long i=1; i<buckets.size(); i++) {
			cout<<", ";
			std::vector<long> retrieved = buckets[i].get_data();
			cout<<"["<<retrieved[0];
			for(long i=1; i<retrieved.size(); i++) {
				cout<<", "<<retrieved[i];
			}
			cout<<"]";
		}
	}

	void addData(long element) {

		if(!data_present) {
			buckets.push_back(bucket(bkt_size));
			data_present = true;
		}

		else if(buckets[buckets.size()-1].isSaturated()) {
			buckets.push_back(bucket(bkt_size));
		}

		buckets[buckets.size()-1].addData(element);
	}

	long find(long element) {
		if(data_present) {
			for(long i=0; i<buckets.size(); i++) {
				if(buckets[i].find(element)) {
					return i+1;
				}
			}
		}
		return -1;
	}

	long get_num_buckets() {
		if(!data_present) {
			return 1;
		}
		return buckets.size();
	}
};