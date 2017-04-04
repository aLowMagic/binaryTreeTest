#include<iostream>
#include<vector>
using namespace std;
class BTTest {
public:
	vector<int> numb;
	vector<int> heap;
	int length = 0;
	BTTest& Sift_up(int);
	BTTest& Sift_down(int, const int);
	BTTest& Insert(int);
	BTTest& Delete(int);
	BTTest& change(int, int);
	BTTest& Makehap();
	BTTest& Heapsort(BTTest&);
	ostream& print(ostream&,vector<int>&);
};
inline BTTest &BTTest::change(int i, int j) {//½«numb[i]Óënumb[j]»¥»»
	int mid;
	mid = numb[i];
	numb[i] = numb[j];
	numb[j] = mid;
	return *this;
}
istream &read(istream &is, BTTest& bt) {
	int mid;
	bt.numb.push_back(NULL);
	while (is>>mid) {
		bt.numb.push_back(mid);
		bt.length++;
	}
	return is;
}
ostream &BTTest::print(ostream& os, vector<int>& pr) {
	for (auto i = 1; i <= (pr.size()-1);i++) {
		os << pr[i] << " " ;
	}
	return os;
}
BTTest& BTTest::Sift_up(int i) {
	while (i != 1) {
		if (numb[i] > numb[i / 2]) {
			change(i, i / 2);
			i = i / 2;
		}
	}
	return *this;
}
BTTest &BTTest::Sift_down(int i, const int length) {
	while (i <= length/2) {
		if ((length >= (2 * i + 1) && numb[i] < numb[2 * i] && numb[2 * i + 1] < numb[2 * i]) || (numb[2 * i] > numb[i] && (length == 2*i))) {
			change(i, i * 2);
			i = i * 2;
		}
		else if (length >= (2*i+1) &&  numb[i] <numb[2*i+1] && numb[2*i+1] >= numb[2*i]){
			change(i, i * 2 + 1);
			i = i * 2 + 1;
		}
		else {
			return *this;
		}
	}
	return *this;
}
BTTest &BTTest::Insert(int i) {
	numb.push_back(i);
	length++;
	Sift_up(length);
	return *this;
}
BTTest &BTTest::Delete(int i) {
	if (i != length) {
		change(i, length);
		numb[length] = NULL;
		length--;
		Sift_down(i, length);
	}
	else if (i == length) {
		numb[length] = NULL;
		length--;
	}
	else {
		return *this;
	}
	return *this;
}
BTTest &BTTest::Makehap() {
	for (int i = length / 2; i >= 1; i--) {
		Sift_down(i, length);
	};
	return *this;
}
BTTest &BTTest::Heapsort(BTTest &bt) {
	int i = 1;
	bt.heap.push_back(NULL);
	while(length >= 1) {
		change(1, length);
		bt.heap.push_back(numb[length]);
		i++;
		Delete(length);
		Sift_down(1, length);
	}
	return *this;
}
int main() {
	BTTest test;
	read(cin, test);
	cout << "read: " << endl;
	test.print(cout, test.numb) << endl << "makehap: " << endl;
	test.Makehap();
	test.print(cout, test.numb)<<endl<<"heapsort:"<<endl; 
	test.Heapsort(test);
	test.print(cout, test.heap);
	system("pause");
}