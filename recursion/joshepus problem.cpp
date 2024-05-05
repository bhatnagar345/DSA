/*Given the total number of persons n and a number k which indicates that k-1 persons are skipped 
and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform
these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.*/




#include <bits/stdc++.h>

using namespace std;

void Josh(vector<int> person, int k, int index)
{
	if (person.size() == 1) {
		cout << person[0] << endl;
		return;
	}
	index = ((index + k) % person.size());
	person.erase(person.begin() + index);
	Josh(person, k, index);
}

int main()
{
	int n = 14; // specific n and k values for original
				// josephus problem
	int k = 2;
	k--; // (k-1)th person will be killed
	int index
		= 0; // The index where the person which will die

	vector<int> person;
	// fill the person vector
	for (int i = 1; i <= n; i++) {
		person.push_back(i);
	}

	Josh(person, k, index);
}
