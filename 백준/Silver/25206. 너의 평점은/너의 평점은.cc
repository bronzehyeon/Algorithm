#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	map<string, double> grade;
	grade.insert({ {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0} });
	double totalDept = 0, totalGrade = 0;
	for (int i = 0; i < 20; i++) {
		string cname, cgrade;
		double dept;
		cin >> cname >> dept >> cgrade;
		if (grade.find(cgrade) != grade.end()) {
			auto it = grade.find(cgrade);
			totalDept += dept;
			totalGrade += it->second * dept;
		}
	}
	cout << totalGrade / totalDept;
}