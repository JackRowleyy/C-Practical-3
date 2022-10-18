#include "xClass.h"
#include <iostream>
using namespace std;

xClass::xClass(int length, int max_val)
	: size(length)
{
	data = NULL;
	if (size <= 0) {
		cout << "array not valid" << size << endl;
		return;
	}
	if (max_val <= 0) {
		cout << "array not valid" << max_val << endl;
		return;
	}
	if ((data = new int[size]) != NULL) {
		for (int i = 0; i < size; i++) {
			data[i] = rand() % max_val;
		}
	}
}
xClass::~xClass() {
	delete[] data;
}
void xClass::print_data() const {
	int *pi = data;
	for (int i = 0; i < size; i++) {
		cout << *pi++ << " ";
		
	}
	cout << endl;
}
int xClass::ave_data() const {
	int avg = 0;
	for (int i = 0; i < size; i++) {
		avg += data[i];
	}
	avg /= size;
	return avg;
}
int xClass::data_at(int i) const {
	int n = 0;
	if (i > 0 && i < size) {
		n = data[i];
		return n;
	}
	else {
		cout << "out of bounds error" << i << endl;
		exit(0);
	}

}
int xClass::range_data(int min, int max) const {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (data[i] >= min && data[i] <= max) {
			count++;
		}
		return count;
	}
}
xClass::xClass(const xClass& b){
	size = b.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = b.data[i];
	}
}
void xClass::operator += (const xClass& b) {
	int nsize = size + b.size;
	int* newdata = new int[nsize];
	for (int i = 0; i < size; i++) {
		newdata[i] = data[i];
	}
	for (int i = 0; i < b.size; i++) {
		newdata[i + size] = b.data[i];
	}
	delete[] data;
	data = newdata;
	size = nsize;
}