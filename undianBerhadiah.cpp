#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  int kupon[N], arrMin[N], minNum;
  for (int i = 0; i < N; i++) {
    cin >> kupon[i];
    arrMin[i] = X-kupon[i];
    if (arrMin[i] < 0) {
      arrMin[i] *= -1;
    }
  }

  minNum = arrMin[0];
  for (int i = 0; i < N; i++) {
      if (arrMin[i] < minNum) {
        minNum = arrMin[i];
      }
  }

  vector<int> indexMin;
  for (int i = 0; i < N; i++) {
    if ((kupon[i] == X+minNum) || (kupon[i] == X-minNum)) {
      indexMin.push_back(kupon[i]);
    }
  }

  int temp;
  int ttl = indexMin.size();
  for (int i = 1; i < ttl; i++) {
    for (int j = 0; j < ttl-i; j++) {
      if (indexMin[j] > indexMin[j+1]) {
        temp = indexMin[j];
        indexMin[j] = indexMin[j+1];
        indexMin[j+1] = temp;
      }
    }
  }

  for (int i = 0; i < ttl; i++) {
      if ((i < ttl-1) && (indexMin[i] == indexMin[i+1])) {
        continue;
      }
      cout << indexMin[i] <<endl;
  }
}
