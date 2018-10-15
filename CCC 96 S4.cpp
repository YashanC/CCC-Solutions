#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    map<char,int> val;
    map<int,string> reverse;
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;
    for(auto it=val.begin();it!=val.end();++it) {
        stringstream thing;
        string bleh;
        thing << it->first;
        thing >> bleh;
        reverse[it->second] = bleh;
    }
    reverse[4] = "IV";
    reverse[9] = "IX";
    reverse[40] = "XL";
    reverse[90] = "XC";
    reverse[400] = "CD";
    reverse[900] = "CM";
    string op,copy,num1,num2,roman;
    int t,thing1=0,thing2=0,ans;
    cin >> t;
    for(int i=0;i<t;i++) {
        thing1 = thing2 = 0;
        roman = "";
        cin >> op;
        copy = op;
        vector<int> digit;
        copy = copy.substr(0,copy.length()-1);
        int x = copy.find('+');
        num1 = copy.substr(0,x);
        num2 = copy.substr(x+1,copy.length());
        for(int j=0;j<num1.length();j++) {
            thing1 += val[num1[j]];
            if(j!=num1.length()-1 && val[num1[j]]<val[num1[j+1]]) {
                thing1 += -2*val[num1[j]]+val[num1[j+1]];
                j++;
            }
        }
        for(int j=0;j<num2.length();j++) {
            thing2 += val[num2[j]];
            if(j!=num2.length() && val[num2[j]]<val[num2[j+1]]) {
                thing2 += -2*val[num2[j]]+val[num2[j+1]];
                j++;
            }
        }
        ans = thing1+thing2;
        if(ans>1000) {
            cout << op << "CONCORDIA CUM VERITATE\n";
        } else {
            while(ans>0) {
                digit.push_back(ans%10);
                ans /= 10;
            }
            for(int j=digit.size()-1;j>=0;j--) {
                if(reverse.find(digit[j]*pow(10,j))!=reverse.end()) {
                    roman += reverse[digit[j]*pow(10,j)];
                    digit[j] = 0;
                } else if(digit[j]>5) {
                    roman += reverse[5*pow(10,j)];
                    digit[j] -= 5;
                }
                for(int k=1;k<=digit[j];k++) {
                    roman += reverse[pow(10,j)];
                }
            }
            cout << op << roman << endl;
        }
    }
    return 0;
}
