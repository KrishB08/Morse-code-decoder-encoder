#include<iostream>
#include<queue>
#include <unordered_map>
using namespace std;

class node {
    public:
        char data;
        node* dot;
        node* dash;

    node(char d) {
        this -> data = d;
        this -> dot = NULL;
        this -> dash = NULL;
    }
};

node* buildree() {

    node* root = new node(' ');

    root->dot = new node('E');
    root->dash = new node('T');

    root->dot->dot = new node('I');
    root->dot->dash = new node('A');
    root->dash->dot = new node('N');
    root->dash->dash = new node('M');

    root->dot->dot->dot = new node('S');
    root->dot->dot->dash = new node('U');
    root->dot->dash->dot = new node('R');
    root->dot->dash->dash = new node('W');
    root->dash->dot->dot = new node('D');
    root->dash->dot->dash = new node('K');
    root->dash->dash->dot = new node('G');
    root->dash->dash->dash = new node('O');

    root->dot->dot->dot->dot = new node('H');
    root->dot->dot->dot->dash = new node('V');
    root->dot->dot->dash->dot = new node('F');
    root->dot->dot->dash->dash = new node(' ');
    root->dot->dash->dot->dot = new node('L');
    root->dot->dash->dash->dot = new node('P');
    root->dot->dash->dash->dash = new node('J');
    root->dash->dot->dot->dot = new node('B');
    root->dash->dot->dot->dash = new node('X');
    root->dash->dot->dash->dot = new node('C');
    root->dash->dot->dash->dash = new node('Y');
    root->dash->dash->dot->dot = new node('Z');
    root->dash->dash->dot->dash = new node('Q');
    root->dash->dash->dash->dot = new node(' ');
    root->dash->dash->dash->dash = new node(' ');

    root->dot->dot->dot->dot->dot = new node('5');
    root->dot->dot->dot->dot->dash = new node('4');
    root->dot->dot->dash->dash->dash = new node('2');
    root->dot->dash->dash->dash->dash = new node('1');
    root->dash->dot->dot->dot->dot = new node('6');
    root->dash->dash->dot->dot->dot = new node('7');
    root->dash->dash->dash->dot->dot = new node('8');
    root->dash->dash->dash->dash->dot = new node('9');
    root->dash->dash->dash->dash->dash = new node('0');

    return root;

}

unordered_map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"},
    {' ', "/"}
};

string traverse(string s, node* root){
    node* temp = root;
    string answ = "";
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c=='.') temp = temp->dot;
        else if(c=='-' || c=='_') temp = temp->dash;
        else if(c == ' '){
            answ+= temp->data;
            temp = root;
        }
        else if(c == '/') {
            answ+= temp->data;
            answ+=" ";
            temp = root;
        } 
        else {  
            return "Invalid Morse Code";
        }
    }
    answ+= temp->data;
    for (auto& x : answ) { 
        x = tolower(x); 
    } 
    return answ;
}

void Decode() {
    string a;
    cout<< "Enter Encoded string : ";
    cin.ignore();
    getline(cin, a);
    cout << "Decoded string : " << traverse(a, buildree())<<endl;
}
void Encode() {
    string a;
    cout<< "Enter Decoded string : ";
    cin.ignore();
    getline(cin, a);
    string answ = "";

    for (char c : a) {
        c = toupper(c);
        if (morseCode.find(c) != morseCode.end()) {
            answ += morseCode[c] + " ";
        } else {
            cout << "Invalid character in input string." << endl;
            return;
        }
    }
    cout << "Encoded string : " << answ << endl;
}
int main() {
    
    while(true){
        int k;
        cout<<"\n-----------------------------------"<<endl;
        cout<<"Main menu : \n1.Encode\n2.Decode\n3.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>k;

        if(k==1) Encode();
        else if(k==2) Decode();
        else if(k==3) break;
        else cout<<"Invalid input !";              
    }


}