#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    int **matrix;
    int usercounter=0, filecounter=0, userindex, fileindex;
    string line, uname;
    ifstream file1, file2, file3; 
    ofstream ofile, ofile2;
    vector<string> users, files;
    file1.open("Question3/allfiles.txt");
    file2.open("Question3/allusers.txt");
    file3.open("Question3/fileset.txt");
    ofile.open("Question3/output.txt");
    ofile2.open("Question4/output.adj");
    while(getline(file1, line))
        files.push_back(line);
    while(getline(file2, line))
        users.push_back(line);

    matrix = new int*[files.size()];
    for (int i = 0; i < files.size(); ++i)
        matrix[i] = new int[users.size()];

    while(getline(file3, line)){
        uname=line;
        for (int i = 0; i < users.size(); ++i){
            if(uname == users[i]){
                userindex = i;
                break;
            }
        }
        while(line!=""){ 
            getline(file3, line);
            if(line!=""){
                for (int i = 0; i < files.size(); ++i){
                    if(line == files[i]){
                        fileindex = i;
                        break;
                    }
                }
                matrix[fileindex][userindex] = 1;    
            }
               
        }
    }

    for (int i = 0; i < files.size(); ++i){
        for (int j = 0; j < users.size(); ++j){
            ofile << matrix[i][j] << " ";
        }
        ofile << endl;
    }

    int ** adj;

    adj = new int*[users.size()];
    for (int i = 0; i < users.size(); ++i)
        adj[i] = new int[users.size()];


    for (int i = 0; i < users.size(); ++i){
        for (int j = 0; j < users.size(); ++j){
            for (int k = 0; k < files.size(); ++k){
                if(matrix[k][i] == 1 && matrix[k][j] == 1){
                    adj[i][j]++;
                }
            }
            ofile2 << adj[i][j] << " ";   
        }
        ofile2 << endl;
    }

    for (int i = 0; i < files.size(); ++i)
        delete [] matrix[i];
    delete [] matrix;

    for (int i = 0; i < users.size(); ++i)
        delete [] adj[i];
    delete [] adj;

    return 0;
}

