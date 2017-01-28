#include "LinearHashBucket.cc"

using namespace std;

class LinearHash
{
	std::vector<bucket> table;
	int nextSplit;

	void splitBucket() {
		long currBase = table[nextSplit].get_base();
		long toSetBase = currBase*2;

		std::vector<long> toRefactor = table[nextSplit].initate_refactor();
		table[nextSplit].set_base(toSetBase);

		table.push_back(bucket(toSetBase));

		for(long i = 0; i < toRefactor.size(); i++) {
			long loc = toRefactor[i] % toSetBase;
			table[loc].addData(toRefactor[i]);
		}
	}

public:

	LinearHash() {
		table.push_back(bucket(2));
		table.push_back(bucket(2));
		nextSplit = 0;
	}

	void add_element(long data) {
		long location = data % table[nextSplit].get_base();
		table[location].addData(data);
		if(table[location].hasOverflow()) {
			splitBucket();

			if(
				(nextSplit == table.size()-1) || 
				(table[nextSplit].get_base() == table[nextSplit+1].get_base())) {
				nextSplit = 0;
			}
			else {
				nextSplit += 1;
			}
		}
	}

	bool find(long element) {
		loc = element % table[nextSplit].get_base();
		if(loc<nextSplit) {
			loc = element % table[nextSplit-1].get_base();
		return table[loc].find(element);
	}

	void printTable() {
		for(long i=0; i<table.size(); i++) {
			cout<<i<<" --- ";
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
};