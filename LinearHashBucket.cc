#include <iostream>
#include <vector>

using namespace std;

class bucket
{
	std::vector<long> data;
	long modBase;
	bool data_present;
public:
	bucket();

	bucket(long base) {
		modBase = base;
		data_present = false;
	}

	long get_base() {
		return modBase;
	}

	void set_base(long base) {
		modBase = base;
	}

	bool hasOverflow() {
		return data.size() > 1;
	}

	bool hasData() {
		return data_present;
	}

	std::vector<long> initate_refactor() {
		std::vector<long> store = data;
		data.clear();

		data_present = false;

		return store;
	}

	void printData() {
		cout<<"("<<data[0];
		for(long i=1; i<data.size(); i++) {
			cout<<", "<<data[i];
		}
		cout<<")";
	}

	void addData(long element) {
		data.push_back(element);
		if(!data_present) {
			data_present = true;
		}
	}

	bool find(long element) {
		if(data_present) {
			for(int i=0; i<data.size(); i++) {
				if(data[i] == element) {
					return true;
				}
			}
		}
		return false;
	}
};