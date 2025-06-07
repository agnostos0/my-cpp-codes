#include <iostream>
#include <string>
using namespace std;

        
    
    int main() {
        string s = "h()";
        int n = s.length();
        cout << n << endl;
        size_t pos = s.find("(");
        cout << pos << endl;
        while (1){
            pos = s.find(")", pos+1);
           
            if (pos == string::npos) {
                cout << "valid" << endl;
                break;
    
        }

    }
    
        return 0;
    }