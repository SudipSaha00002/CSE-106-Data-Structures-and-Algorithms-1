#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
#define MAX 100


int Size;
vector<vector<int>> graph1(MAX);     
vector<vector<int>> graph2(MAX);
vector<int> stack;
vector<bool> vis(MAX,false);



void DFS(int item){
    vis[item] = true;
    for (int i:graph1[item]){
        if ( !vis[i]){
            DFS(i);
        }
    }
    stack.push_back(item);
}

vector<int> indexNo(MAX,-1);
vector<int> value;
void result() {
    stack.clear();
    fill(vis.begin(), vis.end(), false);
    for (int i = 0; i < Size; ++i) {
        if (!vis[i]) {
            DFS(i);
        }
    }
    fill(indexNo.begin(), indexNo.end(), -1);
    int count = 0;
    while (!stack.empty()) {
        int item = stack.back();
        stack.pop_back();
        if (indexNo[item] == -1) {
            indexNo[item] = count++;
        }
    }
}



void node(int a) {
    if (find(value.begin(), value.end(), a) == value.end()) {
        value.push_back(a);
        Size++;
    }
}


void creatIncident(int n,int m,bool notN,bool notM ){
    n=2*n^notN;
    m=2*m^notM;
    graph1[n^1].push_back(m);
    graph1[m^1].push_back(n);
    node(n);
    node(n^1);
    graph2[n].push_back(m^1);
    graph2[m].push_back(n^1);
    node(m);
    node(m^1);
}


int assignmentPossibility() {
    fill(vis.begin(), vis.end(), false);
    for (int i = 0; i < Size; i += 2) {
        int n = value[i];
        int m = value[i + 1];
        if (indexNo[n] == indexNo[m]) {
            return false;
        }
        int p=value[i]/2;
        vis[p] = indexNo[n] > indexNo[m];
    }
    
    return true;
}


int main(){
    ifstream input("in.txt");
    ofstream output("out.txt");

    int n;
    Size = 0;
    input>>n;
    int k = 0;
    input.ignore();
    while (k < n)
    {
        string str;
        getline(input, str);
        int x=-1, y=-1;
        bool notX = false, notY = false;
        int count = 0;
        char c = '\0';

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            if (x == -1) {
                x = ch - 'a';
                notX = (c == '~');
            } else {
                y = ch - 'a';
                notY = (c == '~');
            }
        }
        c = ch;
    }
        int singleChar = 1;
        if (str.length() <= 2 && str.length() != 0) {
        output << (notX ? !x : x); 
        singleChar = singleChar && x; 
        k++;
        continue;
        }
        creatIncident(x,y,notX,notY);
        k++;
    }
    result();
    sort(value.begin(),value.end());
    if (assignmentPossibility()) {   
        for (int i = 0; i < Size; i+=2){
            char ch=(value[i]/2)+'a';
            int j=value[i]/2;
            output<<ch<<" ";
            if (vis[j]){
                output  << "true" << endl;
            }
            else {
                output<< "false" << endl;
            }
        }
    }
    else{
        output << "No assignment possible" << endl;
    }
    return 0;
}