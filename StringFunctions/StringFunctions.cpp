// StringFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int countLetters(char ph[500]);
int countWords(char ph[500]);
void reverseIt(char ph[500]);
bool isPalindrome(char ph[500]);


int main()
{
	char phrase[500];

	cout << "please enter a phrase or word: ";
	cin.getline(phrase, 500);

	cout << "Your phrase has " << countLetters(phrase) << " letters." << endl;
	cout << "Your phrase has " << countWords(phrase) << " words." << endl;
	reverseIt(phrase);
	cout << "Your phrase reversed is " << phrase << "!" << endl;

	if (isPalindrome(phrase))
	{
		cout << "It's a palindrome!!!! " << endl;
	}
	else
	{
		cout << "It's not a palindrome! :( " << endl;
	}


    return 0;
}

// Functions pass letters, expected to pass character array; character arrays always end in null
int countLetters(char ph[500])
{
	int i;
	int count = 0;

	for (i = 0; ph[i] != '\0'; i++)
	{
		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z') || (ph[i] == '\''))
			count++;
	}

	return count;
}

// Counts the amount of words in the phrase
int countWords(char ph[500])
{
	int i;
	int count = 0;
	bool inWord = false;

	for (i = 0; i < strlen(ph); i++)
	{


		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z'))
		{
			if (!inWord)
			{
				count++;
				inWord = true;
			}
		}
		else
		{
			inWord = false;
		}
	}
	return count;
}


// Reverses the phrase
void reverseIt(char ph[500])
{
	int begin = 0;
	int end = strlen(ph) - 1;
	char temp;

	for (begin=0; begin < end; begin++, end--)
	{
		temp = ph[end];
		ph[end] = ph[begin];
		ph[begin] = temp;
	}
}


// Checks if phrase is a palindrome , returns boolean
bool isPalindrome(char ph[500])
{
	int begin = 0;
	int end = strlen(ph) - 1;
	char temp;

	for (begin = 0; begin < end; begin++, end--)
	{
		if (ph[begin] != ph[end])
		{
			return false;
		}
	}
	return true;
}

