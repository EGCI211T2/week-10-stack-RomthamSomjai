#include<iostream>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;


    int i, j;

    for(i=1;i<argc;i++){

        while(s.pop()){}

        for(j=0;j<strlen(argv[i]);j++){

            if(argv[i][j]=='[' || argv[i][j]=='{' || argv[i][j]=='('){
                s.push(argv[i][j]);
            }

            else if(argv[i][j]==']' || argv[i][j]=='}' || argv[i][j]==')'){

                int t = s.pop();
                if(t == 0) break;

                if( (t=='[' && argv[i][j] != ']') ||
                    (t=='{' && argv[i][j] != '}') ||
                    (t=='(' && argv[i][j] != ')') ){
                    cout << "incorrect" << endl;
                    break;
                }
            }
        }

        if(s.pop()==0){
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}