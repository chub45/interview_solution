#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

//function that creates and returns a map fulfilling the required criteria
map<string, string> assignmentGenerator(vector<string> names, map<string, string> &previous){
    map<string, string> currAssignment;
    //set<string> hTable;
	for(int i = 0;i < names.size(); i++){
        for(int j = 0; j < names.size(); j++){
			if(currAssignment.find(names[i]) == currAssignment.end()){
				if((names[i] != names[j]) &&                                    //check if pair involves same word twice
				   (previous[names[i]] != names[j])){                           //check if previous assignment has pair
					if(currAssignment.find(names[j]) == currAssignment.end()){  //if names[j] doesn't exist yet
						/*if(hTable.find(names[j]) == hTable.end()){
							currAssignment.insert(pair<string, string>(names[i], names[j]));
					        hTable.insert(names[j]);	
						}*/
                        currAssignment.insert(pair<string, string>(names[i], names[j]));
					}
				   	else if(currAssignment[names[j]] != names[i] /*&& 
                            hTable.find(names[j]) == hTable.end()*/){
							currAssignment.insert(pair<string, string>(names[i], names[j]));
						    //hTable.insert(names[j]);
				    }
				}
            }
        }
    }
    for(map<string, string>::iterator it = currAssignment.begin(); it != currAssignment.end(); it++){
        cout << it->first << ", " << it->second << endl;
    }
    return currAssignment;
}
int main(){
    vector<string> nameList = {"Rajesh", "Ron", "Ryan", "Steve", "Scott", "Ted", "Dan", "Sergiy"};
    map<string, string> prevAssignment;
    prevAssignment["Rajesh"] = "Steve";
    prevAssignment["Steve"] = "Ted";
    prevAssignment["Ted"] = "Sergiy";
    prevAssignment["Sergiy"] = "Ryan";
	prevAssignment["Ryan"] = "Ron";
    prevAssignment["Ron"] = "Scott";
    prevAssignment["Scott"] = "Dan";
    prevAssignment["Dan"] = "Rajesh";
    map<string, string> currAssignment;
	assignmentGenerator(nameList, prevAssignment);

}
