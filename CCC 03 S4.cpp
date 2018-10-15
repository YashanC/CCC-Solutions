#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int j=0;j<N;j++) {
      string str;
      cin >> str;
      int tot = 1;
      vector<string> suffix;
      for(int i=1;i<=str.length();i++) {
          suffix.push_back(str.substr(str.length()-i));
      }
      sort(suffix.begin(),suffix.end());
      tot += suffix[0].length();
      for(int i=1;i<suffix.size();i++) {
          tot += suffix[i].length();
          int counter = 0;
          while(counter<min(suffix[i].length(),suffix[i-1].length()) && suffix[i-1][counter]==suffix[i][counter]) {
              counter++;
              tot--;
          }
      }
      cout << tot << '\n';
    }
    return 0;
}
