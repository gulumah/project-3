/*******************************************************
git ls-files >allfiles.txt    
git log --pretty="%cn" |sort |uniq >allusers.txt
git log --stat --pretty="%cn" --name-only >allchanges.txt
*******************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int isitUser(string tmp,string all[],int number ){
	for(int i=0;i<number;i++){
		if(all[i]==tmp){
			return i;
		}
	}
	return -1;
}
int isitFile(string tmp,string all[],int number ){
	for(int i=0;i<number;i++){
		if(all[i]==tmp){
			return i;
		}
	}
	return -1;
}


int main(){
	string users[1000];
	string files[1000];
	string temp;
	int user_counter=0,file_counter=0;
	ofstream output;
	ifstream input1,input2,input3;
	input1.open("allusers.txt");
	input2.open("allfiles.txt");
	input3.open("allchanges.txt");
	output.open("output.txt");
	int n,m,counter=0;
	
	while(getline(input1,users[user_counter])){
		user_counter++;
	}
	
	while(getline(input2,files[file_counter])){
		file_counter++;
	}
	
	int matrix[user_counter][file_counter];
	
	for(int i=0;i<user_counter;i++){
		for(int j=0;j<file_counter;j++){
			matrix[i][j]=0;
		}
	}


	while(getline(input3,temp)){
		if(temp!=""){
			if(isitUser(temp,users,user_counter)>-1){
				n=isitUser(temp,users,user_counter);
				
			}
			else if(isitFile(temp,files,file_counter)>-1){
				m=isitFile(temp,files,file_counter);
				matrix[n][m]=1;
			}
		}
		
	}
	
	for(int i=0;i<user_counter;i++){
		for(int j=0;j<file_counter;j++){
			output<<matrix[i][j];
		}
		output<<endl;
	}
	
	input1.close();
	input2.close();
	input3.close();
	output.close();

	
	return 0;
	
	
}

