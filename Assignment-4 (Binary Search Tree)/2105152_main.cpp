#include"2105152.h"
#include"2105152.cpp"


int main() {
    BSTnode<int> BST;
    BSTnode<int>* root = NULL;

    ifstream input("in.txt");
    ofstream output("out.txt");

    if (!input) {
        return 0;
    }

    string Keyword;
    while (getline(input, Keyword)) {
    
        char KeyW=Keyword[0];
        Keyword=Keyword.substr(2);

        if (KeyW == 'F') { 
            int key=stoi(Keyword);
            if (BST.search(root, key)) {
                output << "found" << endl;
            } else {
                output << "not found" << endl;
            }
        } else if (KeyW == 'I') { 
            int key=stoi(Keyword);
            root = BST.insert(root, key);
            output << "(";
            BST.display(root, output);
            output << ")" << endl;
        } else if (KeyW == 'D') { 
            int key=stoi(Keyword);
            root = BST.deleteN(root, key);
            output << "(";
            BST.display(root, output);
            output << ")" << endl;
        } else if (KeyW == 'T') { 
            string traversal=Keyword;
            if (traversal == "In") {
                    BST.inorder(root, output);
            } else if (traversal == "Pre") {
                    BST.preorder(root, output);
            } else if (traversal == "Post") {
                    BST.postorder(root, output);
            } else {
                output << "Invalid" << endl;
            }
            output << endl;
        } 
    }

  return 0;
}