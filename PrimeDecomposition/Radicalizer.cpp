/**
 * This program will compute the least prime factor and radical of a positive integer, computer the prime factorization,
 * and determines whether or not it is a prime number.
 * @author Mitchell Stephany
 * <pre>
 * Date: October 29, 2021
 * File: Radicalizer.cpp
 * Course: csc1253 Section 3 <br>
 * Programming Project #: 3 <br>
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <iostream>
#include <cmath>
using namespace std;

/**
* Gives the least prime factor
* @param num an integer greater than 1
* @return the least prime factor of the specified number or
* -1 if the specified number is less than 2
*/

long lpf(long num)
{
	if (num < 2)
		return -1;
	if (num % 2 == 0)
		return 2;
	for (int i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
			return i;
	}
	    return num;
}

/**
* Compute the radical of the specified number and generate
* its prime factorization
* @param num an integer
* @param rad the radical of the specified number or -1-num
* if the number is less than 1
* @param factStr a string representing the prime factorization
* of the specified number or the string "nan" if the number
* is less than 2
* <pre>
* Note: the radical of 1 is 1
* </pre>
*/

void factorize(long num, long& rad, string& factStr)
{
	int fact, residual;
	fact = lpf(num);
	factStr = to_string(fact);
	rad = fact;
	residual = num;
	int count = 0;
	bool isPrime = true;
	if(fact == -1)
	{
		cout << "Prime Decomposition: " << num << " = nan" << endl;
		cout << "isPrime (" << num << ") = false" << endl;
		cout << "radical (" << num << ") = nan" << endl;
	}
	while(residual % fact == 0)
	{
		count ++;
		residual = residual / fact;
	}
	if(count > 1)
	{
		factStr = factStr + "^" + to_string(count);
	}
	while(fact <= sqrt(residual))
	{
		fact = fact + 1;
		if(residual % fact == 0)
		{
			rad = rad * fact;
			factStr = factStr + " x " + to_string(fact);
			count = 0;
			while(residual % fact == 0)
			{
				count ++;
				residual = residual / fact;
			}
			if(count > 1)
			{
				factStr = factStr + "^" + to_string(count);
			}
		}
	}
	if(residual > 1)
	{
		rad = rad * residual;
		factStr = factStr + " x " + to_string(residual);
	}
	int i;
	for(i = 2; i < num; i++)
	{
		if(num % i == 0)
		{
			isPrime = false;
		}
	}
	cout << "Prime Decomposition: " << num << " = " << factStr << endl;
	if(isPrime == 0)
	{
		cout << "?isPrime(" << num << ") = false" << endl;
	}
	else
	{
		cout << "?isPrime(" << num << ") = true" << endl;
	}
	cout << "radical (" << num << ") = " << rad << endl;
}
int main()
{
	long rad;
	string factStr;
	long num;
	cout << "Enter a positive integer -> ";
	cin >> num;
	if(lpf(num) > 1)
	{
		cout << "lpf(" << num << ") = " << lpf(num) << endl;
	}
	if(lpf(num) == -1)
		cout << "lpf(" << num << ") = " << "nan" << endl;
	factorize(num, rad, factStr);
	return 0;
}

