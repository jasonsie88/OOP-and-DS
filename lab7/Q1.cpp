#include <vector>
#include <iostream>
using namespace std;

class Room{
public:
    int up_room, down_room, left_room, right_room, index;
};

int main()
{
    int m, n; 
	cin>> m>> n;
    Room R[m];
    for(int i= 0; i< m; i++)
    {
        int u, d, l, r; 
		cin>> u>> d>> l>> r;
        R[i].up_room= u;
        R[i].down_room= d;
        R[i].left_room= l;
        R[i].right_room= r;
        R[i].index= i;
    }
    for(int i= 0; i< n; i++)
    {
        int times; 
		cin>> times;
        int nowIndex= 0;
        while(times--)
        {
            char ch;
			 cin>> ch;
            if(nowIndex== -1){
            	continue;
			} 
            if(ch== 'u'){
    			nowIndex= R[nowIndex].up_room;        	
			} else if(ch== 'd') {
				nowIndex= R[nowIndex].down_room;
			}else if(ch== 'l') {
				nowIndex= R[nowIndex].left_room;
			}
            else if(ch== 'r') {
            	nowIndex= R[nowIndex].right_room;
			}
        }
        cout<< nowIndex<< "\n";
    }
    return 0;
}
