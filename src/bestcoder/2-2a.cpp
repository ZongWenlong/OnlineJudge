#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef struct{
    int left;
    int right;
}Rule;
bool compare(Rule a,Rule b)
{
  return a.left < b.left ;
}

int main()
{
    int caseNum;
    scanf("%d",&caseNum);
    int N,M;
    for(int i = 1 ; i <= caseNum;i++){
        scanf("%d %d",&N,&M);
        int left,right;
        vector<int> privilege(N+1,0);
        vector<Rule> rules(M);
        for(int j = 0; j < M;j++){
            scanf("%d %d",&rules[j].left,&rules[j].right);
        }
        sort(rules.begin(),rules.end(),compare);

        for(int j = 0; j < M;j++){
            if(rules[j].left < rules[j].right){
                if(privilege[rules[j].right] == 0 || privilege[rules[j].right] > rules[j].left){
                    privilege[rules[j].right] = rules[j].left;
                }
            }
            else{
                if(privilege[rules[j].right] == 0 || (privilege[rules[j].left] != 0 && privilege[privilege[rules[j].right]] > privilege[rules[j].left])){
                    privilege[rules[j].right] = rules[j].left;
                }
            }

        }

        long long total = 0;
        for(int j = 1;j <= N;j++){
            if(privilege[j] != 0){
                if(privilege[privilege[j]] != 0 && j > privilege[privilege[j]]){
                    privilege[j] = privilege[privilege[j]];
                }
                else{
                    privilege[j] = j;
                }

            }
            else{
                privilege[j] = j;
            }
            total = total + privilege[j];
        }
        printf("%d\n",total);
    }
    return 0;
}
