#include <iostream>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

int checkList[26];

int main(){
	int T;
	cin >> T;
	int a = 0;
	while (T--){
		memset(checkList,0,sizeof(checkList));
		a++;
		int n,k;
		scanf("%d %d",&n,&k);
		//cout << n << k;
		string str;
		cin >> str;
		int len = str.length();
	
		int CNT = 0;

		queue<char> temp;

		for (int j=0;j<len;j++){
			int x = str[j]-'A';
			//cout << x;
			//cout << checkList[x]<< endl;
            if (checkList[x]!=0){
            	CNT++;
            }


			checkList[x]++;
			if (j>=k){
				checkList[str[j-k]-'A']--;
			}

		}
		printf("Case %d: %d\n",a,CNT);

	}
	return 0;
}
