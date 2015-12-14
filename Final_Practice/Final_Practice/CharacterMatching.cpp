#include "Main.h"

void PrintError(char ch, int index)
{
	std::cout << "\tError " << ch << " at " << index << std::endl;
}

void ParseString(char *str, int size)
{
	if (str == "" || size <= 0)
	{
		std::cout << "\tError with parameter" << std::endl;
		return;
	}
	ArraybasedStack<char> sList(size);
	char ch = 0;
	int errors = 0;
	for (int i = 0; i < size; i++)
	{
		switch (str[i])
		{
		case '{':
		case '(':
		case '[':
			sList.push(str[i]);
			break;

		case '}':
		case ')':
		case ']':
			if (!sList.isEmpty())
			{
				ch = sList.pop();

				if ((ch != '{' && str[i] == '}') ||
					(ch != '(' && str[i] == ')') ||
					(ch != '[' && str[i] == ']'))
				{
					PrintError(ch, i + 1);
					errors++;
				}
			}
			break;
		}
	}
	if (sList.isEmpty() && errors == 0)
		std::cout << "\tNo Parsing Errors" << std::endl;
	else if (!sList.isEmpty())
		std::cout << "\tUnclosed Characters: " << sList.GetSize() << std::endl;
}

void CharacterMatching()
{
	char str[] = { '{', '(', 'a', '[', '5', ']', ')', '}' };
	int size = std::strlen(str);			// Returns the length of the given byte string
	std::cout << "Parsing str." << std::endl;
	ParseString(str, size);
	char str2[] = { '{', ')', 'b', '[', '10', ']', ')', '}' };
	size = std::strlen(str2);
	std::cout << "Parsing str2." << std::endl;
	ParseString(str2, size);
}