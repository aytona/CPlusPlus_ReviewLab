#include <iostream>
#include <string>
using namespace std;

bool PalindromeRecursion(int start, int end, const string &word)
{
	if (start >= end)
		return true;
	if (word[start] != word[end])
		return false;
	return PalindromeRecursion(++start, --end, word);
}

bool PalindromeIterative(const string &word)
{
	int start = 0;
	int end = word.length() - 1;
	while (start < end)
	{
		if (word[start++] != word[end--])
			return false;
	}
	return true;
}

int main()
{
	string word;
	cout << "Palinedrome checker" << endl << "Word: ";
	getline(cin, word);
	if (PalindromeRecursion(0, word.length() - 1, word))
		cout << "Recursive check..\tIs a palindrome" << endl;
	if (PalindromeIterative(word))
		cout << "Iterative check..\tIs a palindrome" << endl;
	else
		cout << "Not a palindrome" << endl;
	return 0;
}