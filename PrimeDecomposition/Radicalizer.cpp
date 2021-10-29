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
long lpf(long number)
{
	if (number < 2)
		return -1;
	if (number % 2 == 0)
		return 2;
	for (int i = 3; i * i <= number; i += 2)
	{
		if (number % i == 0)
			return i;
	}
	    return number;
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
	int least = lpf(num);
	rad = least;
	factStr = to_string(rad);
	char f = rad;
	int res = num;

	int count = 0;
	while (res / f %2 == 0)
	{
		count ++;
		res = res / f;
	}
	if (count > 1)
	{
		factStr = factStr + "^" + count;
	}
}
int main()
{
	long number;
	cout << "Enter a positive integer -> ";
	cin >> number;
	if(lpf(number) > 1)
	cout << "lpf(" << number << ") = " << lpf(number);
	if(lpf(number) == -1)
	cout << "lpf(" << number << ") = " << "nan";
}


