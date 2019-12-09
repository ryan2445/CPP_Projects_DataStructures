#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void make_xref(vector<string> s1, map<string, vector<int> > m1);
void print_xref(map<string, vector<int> > m1);

int main(){
    vector<string> v1;
    map<string, vector<int> > m1;
    string s1;
    ifstream read;
    read.open("words.txt");
    while(!read.eof()){
        read >> s1;
        v1.push_back(s1);
        for(int i=0;i<v1.size()-1;i++){
            if(v1[i]==s1){
                v1.erase(v1.end());
            }
        }
    }
    read.close();
    make_xref(v1, m1);
    return 0;
}

void make_xref(vector<string> v1, map<string, vector<int> > m1){
    string s3;
    vector<int> i1;
    ifstream read2;
    string s2;
    int count=0;
    for(int i=0;i<v1.size();i++){
        read2.open("words.txt");
        while(!read2.eof()){
            count++;
            getline(read2, s2);
            for(int j=0;j<s2.length()+1;j++){
                if(s2[j]==' ' || s2[j]=='\0'){
                    if(s3==v1[i]){
                        i1.push_back(count);
                        break;
                    }
                    s3="";
                }
                else{
                    s3+=s2[j];
                }
            }    
        }
        m1.insert({v1[i], i1});
        i1.clear();
        count=0;
        read2.close();
    }
    print_xref(m1);
}

void print_xref(map<string, vector<int> > m1){
    for(auto itr=m1.begin();itr!=m1.end();++itr){
        cout << itr->first << " ";
        for(auto it2 = itr->second.begin(); it2 != itr->second.end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    } 
}