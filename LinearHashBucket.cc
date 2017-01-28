#include <iostream>
#include <vector>

using namespace std;

class bucket
{
	std::vector<long> data;
	long bkt_size;
	bool data_saturation;
	bool hasData;
public:
	bucket();

	bucket(long bucket_size) {
		data_saturation = false;
		hasData = false;
		bkt_size = bucket_size;
	}

	bool isSaturated() {
		return data_saturation;
	}

	void addData(long element) {
		if(!hasData) {
			data.push_back(element);
			hasData = true;
		}
		else if (data.size() != bkt_size) {
			data.push_back(element);
		}
		else {
			cout<<"ERROR!";
		}

		if(data.size() == bkt_size) {
			data_saturation = true;
		}
	}

	bool find(long element) {
		for(int i=0; i<data.size(); i++) {
			if(data[i] == element) {
				return true;
			}
		}
		return false;
	}

	std::vector<long> get_data() {
		return data;
	}
};