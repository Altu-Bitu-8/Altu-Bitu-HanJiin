#include <iostream>
#include <string>
#include <stack>

using namespace std;

void check(string str, stack<char> &s){
    for(char ch : str){
            if(ch == '(' || ch == '['){
                s.push(ch);
            }
            if(ch == ')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else{
                    cout << "no\n";
                    break;
                }
            }
            if(ch == ']'){
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }
                else{
                    cout << "no\n";
                    break;
                }
            }
            if(ch == '.' && s.empty()){
                cout << "yes\n";
            }
            if(ch == '.' && !s.empty() && (s.top() == '(' || s.top() == '[')){
                cout << "no\n";
            }
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    
    int x = 0;
    
    while(true){
        getline(cin, str);
        if(str == ".") break;
        
        stack<char> s;
        check(str, s);
    }

    return 0;
}