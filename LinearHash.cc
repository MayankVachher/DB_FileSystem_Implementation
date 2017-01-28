#include "LinearHashDirectory.cc"

using namespace std;

class LinearHash
{
	std::vector<directory> table;
	long nextSplit;
	long num_records;
	long bkt_size;

	long splitBucket() {
		long currBase = table[nextSplit].get_base();
		long toSetBase = currBase*2;

		long cost = table[nextSplit].get_num_buckets();

		std::vector<long> toRefactor = table[nextSplit].initate_refactor();
		table[nextSplit].set_base(toSetBase);

		table.push_back(directory(bkt_size, toSetBase));

		for(long i = 0; i < toRefactor.size(); i++) {
			long loc = toRefactor[i] % toSetBase;
			table[loc].addData(toRefactor[i]);
		}

		return cost + toRefactor.size();
	}

public:

	LinearHash() {
		nextSplit = 0;
		num_records = 0;
		bkt_size = 1;
		
		table.push_back(directory(bkt_size, 2));
		table.push_back(directory(bkt_size, 2));
	}

	LinearHash(long bucket_size) {
		nextSplit = 0;
		num_records = 0;
		bkt_size = bucket_size;
		
		table.push_back(directory(bkt_size, 2));
		table.push_back(directory(bkt_size, 2));
	}

	long add_element(long data) {
		long location = data % table[nextSplit].get_base();

		if(location < nextSplit) {
			location = data % table[nextSplit-1].get_base();
		}
		table[location].addData(data);
		num_records++;

		if(table[location].hasOverflow()) {
			long accesses = splitBucket();

			if(
				(nextSplit == table.size()-1) || 
				(table[nextSplit].get_base() == table[nextSplit+1].get_base())) {
				nextSplit = 0;
			}
			else {
				nextSplit += 1;
			}
			return accesses;
		}

		return 0;
	}

	bool find(long element) {
		long location = element % table[nextSplit].get_base();
		if(location<nextSplit) {
			location = element % table[nextSplit-1].get_base();
		}
		return table[location].find(element);
	}

	void printTable() {
		for(long i=0; i<table.size(); i++) {
			cout<<i<<" --- Mod "<< table[i].get_base()<<" --- ";
			if(table[i].hasData()) {
				table[i].printData();
			}
			else {
				cout<<"EMPTY BUCKET";
			}
			cout<<"\n";
		}
		cout<<"\n\n";
	}

	long get_num_records() {
		return num_records;
	}

	long get_num_buckets() {
		long num_buckets = 0;
		for(long i=0; i<table.size(); i++) {
			num_buckets += table[i].get_num_buckets();
		}
		return num_buckets;
	}

	long get_bucket_capacity() {
		return bkt_size;
	}
};