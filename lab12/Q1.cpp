#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class meeting
{
    public:
    meeting(int s, int e){
        start = s;
        end = e;
    }
    int start;
    int end;
};

int main() {
    int N, s, e, i ,k = 0 , min1, min2,flag = 0;
    vector<meeting*> a;
    vector<int> ans;
    cin >> N;
    ans.resize(N);
    while(N > 0){
        a.erase(a.begin(), a.end());
        while(cin >> s >> e){
            if(s == 0 && e == 0){
                break;
            }
            else{
                a.push_back(new meeting(s, e));
            }
        }
        min1 = a[0]->end;
        for (i = 0; i < a.size();i++){
            if(a[i]->end < min1){
                min1 = a[i]->end;
            }
        }
        ans[k] = 1; //min1是下界 min2是上界 
        while(1){
            min2 = 10000;
            flag = 0;
            for (i = 0; i < a.size();i++){
                if(a[i]->start >= min1){
                    if(a[i]->end < min2){
                        min2 = a[i]->end; //產生新上界 
                   		flag = 1;                        
                    }
                }
            }
            if(flag == 0){
                break;
            }
            min1 = min2; //改變下界 用這次的上界代 
            ans[k]++;
        }
        k++;
        N--;
    }
    for (i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }

        return 0;
}


