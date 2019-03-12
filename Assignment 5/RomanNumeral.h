#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
using namespace std;

class RomanNumeral
{
public:
	/**
	 * Default constructor.
	 */
	RomanNumeral();
	/***** Complete this class declaration. *****/
	RomanNumeral(int); // constructor with integer parameter
	RomanNumeral(string); // constructor with string parameter

	string getRoman(); // gets the roman numeral string
	int getDecimal(); // gets the decimal number of the roman numeral

	/*
	This is an overload operator to add  two roman numerals
	@param rn1 - the first roman numeral
	@param rn2 - the second roman numeral
	@return a roman numeral object that equals the sum of both roman numerals
	*/
	friend RomanNumeral operator +(const RomanNumeral& rn1, const RomanNumeral& rn2);

	/*
	This is an overload operator to subtract two roman numerals
	@param rn1 - the first roman numeral
	@param rn2 - the second roman numeral
	@return a roman numeral object that equals the difference of both roman numerals
	*/
	friend RomanNumeral operator -(const RomanNumeral& rn1, const RomanNumeral& rn2);

	/*
	This is an overload operator to multiply two roman numerals
	@param rn1 - the first roman numeral
	@param rn2 - the second roman numeral
	@return a roman numeral object that equals the product of both roman numerals
	*/
	friend RomanNumeral operator *(const RomanNumeral& rn1, const RomanNumeral& rn2);

	/*
	This is an overload operator to divide two roman numerals
	@param rn1 - the first roman numeral
	@param rn2 - the second roman numeral
	@return a roman numeral object that equals the quotient of both roman numerals
	*/
	friend RomanNumeral operator /(const RomanNumeral& rn1, const RomanNumeral& rn2);

	/*
	This is an overload operator that checks equality between two roman numerals
	@param rn1 - the first roman numeral
	@param rn2 - the second roman numeral
	@return true if they are equal and false if they are not
	*/
	friend bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2);

	/*
	This is an overload operator that checks inequality between two roman numerals
	@param rn1 - the first roman numeral
	@param rn2 - the second roman numeral
	@return true if they are not equal and false if they are equal
	*/
	friend bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2);

	/*
	This is an output overload operator that outputs the roman numeral in the format of [decimal:string]
	@param os - the output stream
	@param rn - the roman numeral
	@return os - the output stream
	*/
	friend ostream& operator <<(ostream& os, const RomanNumeral& rn);

	/*
	This is an input overload operator that takes the input of a roman numeral string
	@param is - the input stream
	@param rn - the roman numeral
	@return is - the input stream
	*/
	friend istream& operator >>(istream& is, RomanNumeral& rn);

private:
	string roman; // the roman numeral string
	int decimal; // the decimal number of the roman numeral

	/*
	This function takes a decimal number and turns it into a roman numeral string
	@param int - this is the decimal number we will be converting
	@return string - the string of the roman numeral
	*/
	string to_roman(int);

	/*
	This function takes a string roman numeral and turns it into a decimal number
	@param string - this is the string roman numeral we will be converting
	@return int - the decimal value of the roman numeral
	*/
	int to_decimal(string);
};

#endif /* ROMANNUMERAL_H_ */