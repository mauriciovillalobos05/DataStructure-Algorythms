#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    string res;
    int c=1;
    for(int i=0;i<s.length();i++) {
        if(s[i]==s[i+1]) {
            c++;
        }
        else {
            res+=to_string(c);
            res+=s[i];
            c=1;
        }
    }
    cout<<res;
    return 0;
}