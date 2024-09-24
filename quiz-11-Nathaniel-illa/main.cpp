// #include "main.hpp"
#include "main.hpp"

int main()
{
	string filename = "allstates.txt";
	string state, name;
	vector<Result> MFNames(2);
	char gen;
	int year, cnt;
	ifstream ifs;
	int count = 0;
	char delimiter = ',';

	vector<Name> namerecords = rewritesplitwords(filename, delimiter);

	// 1) Your splited text file test
	ifs.open("split.txt");
	while (ifs >> state >> gen >> year >> name >> cnt)
	{
		cout << state << "\t" << gen << "\t" << year << "\t" << name << "\t" << cnt << endl;
		count += 1;
	}
	cout << "the total number of lines is " << count << endl;

	// 2) Test for MFN
	MFNames = MFN(namerecords, "IN", 2018);
	cout << "The Most frequently used male name and count in IN, 2018 " << MFNames[0].name << " " << MFNames[0].count << endl;
	cout << "The Most frequently used female name and count in IN, 2018 " << MFNames[1].name << " " << MFNames[1].count << endl;
	MFNames = MFN(namerecords, "DE", 2018);
	cout << "The Most frequently used male name and count in DE, 2018 " << MFNames[0].name << " " << MFNames[0].count << endl;
	cout << "The Most frequently used female name and count in DE, 2018 " << MFNames[1].name << " " << MFNames[1].count << endl;
}
