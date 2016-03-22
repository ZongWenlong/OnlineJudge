#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	char result[102];
	int resultSize = 102;
	for (int i = 0; i < resultSize;i++) {
		result[i] = '0';
	}
	while (str != "0") {
		//add two
		int flag = 0;
		int i,j;
		for (i = 0,j = str.size() - 1; j >= 0;j--,i++) {
			result[i] = result[i] + str[j] + flag - '0';
			if (result[i] > '9') {
				flag = 1;
				result[i] = result[i] - 10;
			}
			else {
				flag = 0;
			}
		}
		while (i < resultSize) {
			result[i] = result[i] + flag;
			if (result[i] > '9') {
				flag = 1;
				result[i] = result[i] - 10;
			}
			else {
				flag = 0;
			}
			i++;
		}
		
		cin >> str;
	}

	bool flag = false;
	for (int i = resultSize - 1; i > 0;i--) {
		if (result[i] != '0') {
			flag = true;
			for (; i > 0;i--) {
				cout << result[i];
			}
		}
		

	}
	cout << result[0] << endl;

	system("pause");
}