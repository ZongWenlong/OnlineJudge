#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string line;
	cin >> line;
	int varIndex[5];

	while (line != "0") {
		int index = 0;
		memset(varIndex, -1, sizeof(varIndex));
		for (int i = 0; i < line.size(); i++) {
			if (line[i] >= 'a' && line[i] <= 'z' && varIndex[line[i] - 'p'] == -1) {
				varIndex[line[i] - 'p'] = index;
				index++;
			}
		}
		vector<vector<bool> > flag(1 << index);
		for (int i = 0; i < flag.size(); i++) {
			vector<bool> row(index);
			int temp = i;
			for (int j = 0; j < index; j++) {
				row[j] = temp % 2 == 1 ? true : false;
				temp = temp >> 1;
			}
			flag[i] = row;
		}

		bool currentResult;
		bool tautologyFlag = true;
		for (int i = 0; i < flag.size(); i++) {
			stack<bool> operand;
			for (int j = line.size() - 1; j >= 0; j--) {
				if (line[j] >= 'A' && line[j] <= 'Z') {
					if (line[j] == 'N') {
						bool first = operand.top();
						operand.pop();
						operand.push(!first);
					}
					else {
						bool first = operand.top();
						operand.pop();
						bool second = operand.top();
						operand.pop();
						if (line[j] == 'K') {
							operand.push(first && second);
						}
						else if (line[j] == 'A') {
							operand.push(first || second);
						}
						else if (line[j] == 'C') {
							operand.push(!(first && (!second)));

						}
						else if (line[j] == 'E') {
							operand.push(first == second);
						}
					}
				}
				else {
					operand.push(flag[i][varIndex[line[j] - 'p']]);
				}
			}

			if (operand.top() == false) {
				tautologyFlag = false;
				break;
			}

		}

		if (tautologyFlag == false) {
			cout << "not" << endl;
		}
		else {
			cout << "tautology" << endl;
		}
		cin >> line;
	}

	return 0;
}
