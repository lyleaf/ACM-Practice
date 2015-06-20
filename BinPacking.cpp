//============================================================================
// Name        : BPacking.cpp
// Author      : elin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int bins[100010];

int main() {
	int nCase;
	scanf("%d",&nCase);
	while (nCase--){

		memset(bins,0,sizeof(bins));
		int n;
		cin >> n;
		int l;
		cin >> l;
		//how to create a vector
		for (int i=0;i<n;i++){
			cin >> bins[i];
		}
		sort(bins, bins+n);
		int num = 0;
		int i=0;
		int j=n-1;
		while (true){
			if (bins[i]+bins[j]<=l){
				num ++;
				i ++;
				j --;
			}
			else {
				num ++;
				j--;
			}
			if (i>j){
				break;
			}
		}

		cout << num << endl;
		if (nCase !=0){
			cout << endl;
		}

	}

	return 0;
}
