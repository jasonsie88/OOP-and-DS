#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while ( cin>>n && n) {
    int m , flag = 1, tmp;
    for(m=1;flag;m++) {
      tmp = flag = 0;
      for (int i = 1; i < n; i++) {
        tmp = (tmp + m) % i;
      }
      if (tmp != 11) {
          flag = 1;
      }
    }
    cout<<m-1<<endl;
  }
  return 0;
}
