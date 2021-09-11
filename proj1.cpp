
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <math.h>

using namespace std;

class Ccenter
{
public:

	Ccenter();
	Ccenter(const string& n_X, const string& n_Y, const string& n_OBJECTID, const string& n_ID,
		const string& n_NAME, const string& n_ADDRESS, const string& n_CITY, const string& n_STATE,
		const string& n_ZIP, const string& n_ZIP4, const string& n_TELEPHONE, const string& n_TYPE,
		const string& n_STATUS, const string& n_POPULATION, const string& n_COUNTY, const string& n_COUNTYFIPS,
		const string& n_COUNTRY, const string& n_LATITUDE, const string& n_LONGITUDE, const string& n_NAICS_CODE,
		const string& n_NAICS_DESC, const string& n_SOURCE, const string& n_SOURCEDATE, const string& n_VAL_METHOD,
		const string& n_VAL_DATE, const string& n_WEBSITE, const string& n_ST_SUBTYPE)

		:X{ n_X }, Y{ n_Y }, OBJECTID{ n_OBJECTID }, ID{ n_ID }, NAME{ n_NAME }, ADDRESS{ n_ADDRESS }, CITY{ n_CITY },
		STATE{ n_STATE }, ZIP{ n_ZIP }, ZIP4{ n_ZIP4 }, TELEPHONE{ n_TELEPHONE }, TYPE{ n_TYPE }, STATUS{ n_STATUS },
		POPULATION{ n_POPULATION }, COUNTY{ n_COUNTY }, COUNTYFIPS{ n_COUNTYFIPS }, COUNTRY{ n_COUNTRY }, LATITUDE{ n_LATITUDE },
		LONGITUDE{ n_LONGITUDE }, NAICS_CODE{ n_NAICS_CODE }, NAICS_DESC{ n_NAICS_DESC }, SOURCE{ n_SOURCE }, SOURCEDATE{ n_SOURCEDATE },
		VAL_METHOD{ n_VAL_METHOD }, VAL_DATE{ n_VAL_DATE }, WEBSITE{ n_WEBSITE }, ST_SUBTYPE{ n_ST_SUBTYPE }
	{
	}


	friend bool operator == (const Ccenter& c1, const Ccenter& c2);
	friend bool operator <= (const Ccenter& c1, const Ccenter& c2);
	friend bool operator >= (const Ccenter& c1, const Ccenter& c2);
	friend bool operator < (const Ccenter& c1, const Ccenter& c2);
	friend bool operator> (const Ccenter& c1, const Ccenter& c2);
	friend ostream& operator << (ostream& os, const Ccenter& c1);

private:
	string X;
	string Y;
	string OBJECTID;
	string ID;
	string NAME;
	string ADDRESS;
	string CITY;
	string STATE;
	string ZIP;
	string ZIP4;
	string TELEPHONE;
	string TYPE;
	string STATUS;
	string POPULATION;
	string COUNTY;
	string COUNTYFIPS;
	string COUNTRY;
	string LATITUDE;
	string LONGITUDE;
	string NAICS_CODE;
	string NAICS_DESC;
	string SOURCE;
	string SOURCEDATE;
	string VAL_METHOD;
	string VAL_DATE;
	string WEBSITE;
	string ST_SUBTYPE;

};
Ccenter::Ccenter()
{
}
bool operator == (const Ccenter& t, const Ccenter& v) {

	return (t.NAME == v.NAME);

}
bool operator<  (const Ccenter& t, const Ccenter& v) {

	return (t.NAME < v.NAME);

}
bool operator> (const Ccenter& t, const Ccenter& v) {
	return (t.NAME > v.NAME);

}
bool operator<= (const Ccenter& t, const Ccenter& v) {
	return (t.NAME <= v.NAME);

}
bool operator>= (const Ccenter& t, const Ccenter& v) {
	return (t.NAME >= v.NAME);

}
ostream& operator << (ostream& os, const Ccenter& t) {
	os << t.X << "," << t.Y << "," << t.OBJECTID << "," << t.ID << "," << t.NAME << "," << t.ADDRESS
		<< "," << t.CITY << "," << t.STATE << "," << t.ZIP << "," << t.ZIP4 << "," << t.TELEPHONE
		<< "," << t.TYPE << "," << t.STATUS << "," << t.POPULATION << "," << t.COUNTY << "," << t.COUNTYFIPS
		<< "," << t.COUNTRY << "," << t.LATITUDE << "," << t.LONGITUDE << "," << t.NAICS_CODE
		<< "," << t.NAICS_DESC << "," << t.SOURCE << "," << t.SOURCEDATE << "," << t.VAL_METHOD
		<< "," << t.VAL_DATE << "," << t.WEBSITE << "," << t.ST_SUBTYPE << endl;
	return os;
}


void insertionSort(vector<Ccenter>& arr, int low, int n)
{

	for (int i = low + 1; i <= n; i++)
	{
		Ccenter key = arr[i];
		int j = i;
		while (j > low && arr[j - 1] > key)
		{
			arr[j] = arr[j - 1];
			j--;
		}

		arr[j] = key;
	}
}

void merge(vector<Ccenter>& a, int p, int q, int r)
{
	int size1 = q - p + 1;
	int size2 = r - q;
	vector<Ccenter> L(size1);
	vector<Ccenter> R(size2);

	for (int i = 0; i < size1; i++)
	{
		L[i] = a[p + i];
	}
	for (int j = 0; j < size2; j++)
	{
		R[j] = a[q + j + 1];
	}

	int i = 0, j = 0;
	int k;
	for (k = p; k <= r && i < size1 && j < size2; k++)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
	for (i = i; i < size1; ++i)
	{
		a[k] = L[i];
		k++;
	}

	for (j = j; j < size2; j++)
	{
		a[k] = R[j];
		k++;
	}
}

void mergeSort(vector<Ccenter>& arr, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}

}
void swap(Ccenter* a, Ccenter* b)
{
	Ccenter t = *a;
	*a = *b;
	*b = t;
}

Ccenter medOf3(vector<Ccenter>& a, int p, int r)
{
	int i = (p + r) / 2;
	if (a[i] < a[p]) {
		swap(a[p], a[i]);
	}
	if (a[r] < a[p]) {
		swap(a[p], a[r]);

	}
	if (a[r] < a[i]) {
		swap(a[i], a[r]);
	}
	swap(a[i], a[r - 1]);
	return a[i - 1];
}
void quickSort(vector<Ccenter>& arr, int left, int right)
{
	if (left < right) {
		Ccenter pivot = medOf3(arr, left, right);
		int i = left, j = right - 1;

		for (;;) {
			while (arr[++i] < pivot) {}
			while (pivot < arr[--j]) {}
			if (i < j) {
				swap(arr[i], arr[j]);
			}
			else {
				break;
			}
		}
		swap(arr[i], arr[right - 1]);
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}
}

void hqSort(vector<Ccenter>& a, int left, int right)
{
	if (left + 20<= right) {
		Ccenter pivot = medOf3(a, left, right);
		int i = left, j = right - 1;
		for (;;) {
			while (a[++i] < pivot) {}
			while (pivot < a[--j]) {}
			if (i < j) {
				swap(a[i], a[j]);
			}
			else {
				break;
			}
		}
		swap(a[i], a[right - 1]);
		hqSort(a, left, i - 1);
		hqSort(a, i + 1, right);
	}
	else {
		insertionSort(a,left,right);
	}
}

void readitems(vector<Ccenter>& data) {
	data.clear();
	cout << "Reading file...." << endl;
	ifstream inputFile;
	inputFile.open("Child_Care_Centers.csv");
	while (inputFile)
	{
		string s;
		if (!getline(inputFile, s)) break;

		istringstream ss(s);
		vector <string> r;

		while (ss)
		{
			string s;
			if (!getline(ss, s, ',')) break;
			r.push_back(s);
		}

		data.push_back(Ccenter(r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9],
			r[10], r[11], r[12], r[13], r[14], r[15], r[16], r[17], r[18], r[19], r[20],
			r[21], r[22], r[23], r[24], r[25], r[26]));

	}
	data.erase(data.begin());
	if (!inputFile.eof())
	{
		cerr << "end!\n";
	}

}
void INSwriteitems(vector<Ccenter>& INSlist) {
	cout << "Writing file...." << endl;
	ofstream outFile("INSSortedFile.csv");
	outFile << "X,Y,OBJECTID,ID,NAME,ADDRESS,CITY,STATE,ZIP,ZIP4,TELEPHONE,TYPE,STATUS,POPULATION,COUNTY,COUNTYFIPS,COUNTRY,LATITUDE,LONGITUDE,NAICS_CODE,NAICS_DESC,SOURCE,SOURCEDATE,VAL_METHOD,VAL_DATE,WEBSITEST_SUBTYPE"<<endl;
	for (int j = 0; j < INSlist.size(); j++) {
		outFile << INSlist[j];
	}
	outFile.close();


}
void MRGwriteitems(vector<Ccenter>& INSlist) {
	cout << "Writing file...." << endl;
	ofstream outFile("MRGSortedFile.csv");
	outFile << "X,Y,OBJECTID,ID,NAME,ADDRESS,CITY,STATE,ZIP,ZIP4,TELEPHONE,TYPE,STATUS,POPULATION,COUNTY,COUNTYFIPS,COUNTRY,LATITUDE,LONGITUDE,NAICS_CODE,NAICS_DESC,SOURCE,SOURCEDATE,VAL_METHOD,VAL_DATE,WEBSITEST_SUBTYPE" << endl;
	for (int j = 0; j < INSlist.size(); j++) {
		outFile << INSlist[j];
	}
	outFile.close();


}
void QSwriteitems(vector<Ccenter>& INSlist) {
	cout << "Writing file...." << endl;
	ofstream outFile("QSSortedFile.csv");
	outFile << "X,Y,OBJECTID,ID,NAME,ADDRESS,CITY,STATE,ZIP,ZIP4,TELEPHONE,TYPE,STATUS,POPULATION,COUNTY,COUNTYFIPS,COUNTRY,LATITUDE,LONGITUDE,NAICS_CODE,NAICS_DESC,SOURCE,SOURCEDATE,VAL_METHOD,VAL_DATE,WEBSITEST_SUBTYPE" << endl;
	for (int j = 0; j < INSlist.size(); j++) {
		outFile << INSlist[j];
	}
	outFile.close();


}
void HQSwriteitems(vector<Ccenter>& INSlist) {
	cout << "Writing file...." << endl;
	ofstream outFile("HQSSortedFile.csv");
	outFile << "X,Y,OBJECTID,ID,NAME,ADDRESS,CITY,STATE,ZIP,ZIP4,TELEPHONE,TYPE,STATUS,POPULATION,COUNTY,COUNTYFIPS,COUNTRY,LATITUDE,LONGITUDE,NAICS_CODE,NAICS_DESC,SOURCE,SOURCEDATE,VAL_METHOD,VAL_DATE,WEBSITEST_SUBTYPE" << endl;
	for (int j = 0; j < INSlist.size(); j++) {
		outFile << INSlist[j];
	}
	outFile.close();


}
void HPSwriteitems(vector<Ccenter>& INSlist) {
	cout << "Writing file...." << endl;
	ofstream outFile("HPSSortedFile.csv");
	outFile << "X,Y,OBJECTID,ID,NAME,ADDRESS,CITY,STATE,ZIP,ZIP4,TELEPHONE,TYPE,STATUS,POPULATION,COUNTY,COUNTYFIPS,COUNTRY,LATITUDE,LONGITUDE,NAICS_CODE,NAICS_DESC,SOURCE,SOURCEDATE,VAL_METHOD,VAL_DATE,WEBSITEST_SUBTYPE" << endl;
	for (int j = 0; j < INSlist.size(); j++) {
		outFile << INSlist[j];
	}
	outFile.close();


}

int leftChild(int i)
{
	return 2 * i + 1;
}
void percDown(vector<Ccenter>& a, int i, int n)
{
	int child;
	Ccenter tmp;
	for (tmp = move(a[i]); leftChild(i) < n; i = child)
		{
		child = leftChild(i);
		if (child != n - 1 && a[child] < a[child + 1])
			++child;
		if (tmp < a[child])
			 a[i] = std::move(a[child]);
		 else
			 break;
		}
	a[i] = move(tmp);
}
void heapSort(vector<Ccenter>& a)
{
	for (int i = a.size() / 2 - 1; i >= 0; --i) 
		percDown(a, i, a.size());
	for (int j = a.size() - 1; j > 0; --j)
	{
		swap(a[0], a[j]); 
		percDown(a, 0, j);
	}
}

void runINS(vector<Ccenter>& INSlist) {

	readitems(INSlist);
	cout << "sorting...." << endl;
	auto start = chrono::steady_clock::now();
	insertionSort(INSlist,0,INSlist.size()-1);
	auto end = chrono::steady_clock::now();
	cout << "Sorted! Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	INSwriteitems(INSlist);
	
	cout << "File Ready!"<<endl;
}
void runMRG(vector<Ccenter>& INSlist) {

	readitems(INSlist);
	cout << "sorting...." << endl;
	auto start = chrono::steady_clock::now();
	mergeSort(INSlist, 0, INSlist.size() - 1);
	auto end = chrono::steady_clock::now();
	cout << "Sorted! Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	MRGwriteitems(INSlist);
	cout << "File Ready!" << endl;
}
void runQS(vector<Ccenter>& INSlist) {

	readitems(INSlist);
	cout << "sorting...." << endl;
	auto start = chrono::steady_clock::now();
	quickSort(INSlist, 0, INSlist.size());
	auto end = chrono::steady_clock::now();
	cout << "Sorted! Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	QSwriteitems(INSlist);
	cout << "File Ready!" << endl;
}
void runHQS(vector<Ccenter>& INSlist) {

	readitems(INSlist);
	cout << "sorting...." << endl;
	auto start = chrono::steady_clock::now();
	hqSort(INSlist, 0, INSlist.size() - 1);
	auto end = chrono::steady_clock::now();
	cout << "Sorted! Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	HQSwriteitems(INSlist);
	cout << "File Ready!" << endl;
}
void runHS(vector<Ccenter>& INSlist) {

	readitems(INSlist);
	cout << "sorting...." << endl;
	auto start = chrono::steady_clock::now();
	heapSort(INSlist);
	auto end = chrono::steady_clock::now();
	cout << "Sorted! Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	HPSwriteitems(INSlist);
	cout << "File Ready!" << endl;
}
int main()
{
	vector<Ccenter> INSlist;
	cout << "Select an option number from the following menu:\r\n" <<
		"Option  Action\r\n" <<
		"------  -----------------------------------------\r\n" <<
		"   1    Sort Child_Care_Centers.csv with Insertion Sort.\r\n" <<
		"   2    Sort Child_Care_Centers.csv with Merge Sort.\r\n" <<
		"   3    Sort Child_Care_Centers.csv with Quick Sort.\r\n" <<
		"   4    Sort Child_Care_Centers.csv with Hybrid Quick Sort.\r\n" <<
		"   5    Sort Child_Care_Centers.csv with Heap Sort.\r\n" <<
		"   6    Quit.\r\n" <<
		"Enter your choice number 1-6:" <<
		"" << endl;
	bool loop = true;
	int x;
	while (loop) {
		while (true) {
			cin >> x;
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "invalid imput!" << endl;

			}

			else {
				break;
			}
		}

		switch (x)
		{

		case 1:
			runINS(INSlist);
			break;
		case 2:
			runMRG(INSlist);
			break;
		case 3:
			runQS(INSlist);
			break;
		case 4:
			runHQS(INSlist);
			break;
		case 5:
			runHS(INSlist);
			break;
		case 6:
			cout << "goodbye..." << endl;
			loop = false;
			break;
		default:
			break;

		}
	}
}
