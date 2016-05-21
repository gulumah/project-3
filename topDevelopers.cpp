#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	double showlimit,commitNumber, totalCommit=0;
	string name,line;
	ifstream file;  
	ofstream ofile;
    file.open("Question2-b/allCommits.txt");
	while(getline(file, line)){  
	    stringstream in_line(line); 
	    in_line >> commitNumber >> name;
	    totalCommit+=commitNumber;
	}
	file.close();
	showlimit = (totalCommit * 80)/100;
	totalCommit=0;
	file.open("Question2-b/allCommits.txt");
	ofile.open("Question2-b/80percentage.txt");
	while(getline(file, line)){  
	    stringstream in_line(line); 
	    in_line >> commitNumber >> name;
	    totalCommit+=commitNumber;
	    if(totalCommit <= showlimit)
	    	ofile << name << " " << commitNumber << " ("<<setprecision(3)<<(commitNumber * 100)/showlimit<<"%)" <<endl;
	    else
			break;
	}
	file.close();
	ofile.close();
	return 0;
}
