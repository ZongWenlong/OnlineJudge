#include <iostream>
#include <string>
#include <list>

using namespace std;
int main(void)
{
	string input;
	list<int> results;

	getline(cin, input);
	
	while (input != "#") {
		int result = 0;

		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ' ') {
				result = result + (i + 1) * (input[i] - 'A' + 1);
			}
		}
		results.push_back(result);
		getline(cin, input);
	}

	for (list<int>::iterator it = results.begin(); it != results.end(); ++it) {
		cout << *it<<"\n";
	}

}