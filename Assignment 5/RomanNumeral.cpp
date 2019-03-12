#include <iostream>
#include <fstream>
#include <string>
#include "RomanNumeral.h"

using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0) {}
RomanNumeral::RomanNumeral(string romanNumeral) : roman(romanNumeral), decimal(to_decimal(romanNumeral)) {}
RomanNumeral::RomanNumeral(int number) : roman(to_roman(number)), decimal(number) {}

/***** Complete this class implementation. *****/
string RomanNumeral::to_roman(int num) {
	string roman = "";
	while (num != 0) {
		if (num >= 1000) {
			for (int i = 0; i < num / 1000; i++) {
				roman.append("M");
			}
			num = num % 1000;
		}
		if (num >= 900) {
			roman.append("CM");
			num = num % 900;
		}
		else if (num >= 500) {
			for (int i = 0; i < num / 500; i++) {
				roman.append("D");
			}
			num = num % 500;
		}
		if (num >= 400) {
			roman.append("CD");
			num = num % 400;
		}
		else if (num >= 100) {
			for (int i = 0; i < num / 100; i++) {
				roman.append("C");
			}
			num = num % 100;
		}
		if (num >= 90) {
			roman.append("XC");
			num = num % 90;
		}
		else if (num >= 50) {
			for (int i = 0; i < num / 50; i++) {
				roman.append("L");
			}
			num = num % 50;
		}
		if (num >= 40) {
			roman.append("XL");
			num = num % 40;
		}
		else if (num >= 10) {
			for (int i = 0; i < num / 10; i++) {
				roman.append("X");
			}
			num = num % 10;
		}
		if (num == 9) {
			roman.append("IX");
			num = num % 9;
		}
		else if (num >= 5) {
			for (int i = 0; i < num / 5; i++) {
				roman.append("V");
			}
			num = num % 5;
		}
		if (num == 4) {
			roman.append("IV");
			num = num % 4;
		}
		else if (num >= 1) {
			for (int i = 0; i < num; i++) {
				roman.append("I");
			}
			num = 0;
		}
	}
	return roman;
}

int RomanNumeral::to_decimal(string roman) {
	int decimal = 0;
	for (int i = 0; i < roman.length(); i++) {
		string letter = roman.substr(i, 1);
		if (letter == "I") {
			if (i != roman.length() - 1) {
				i++;
				if (roman.substr(i, 1) == "V") {
					decimal += 4;
				}
				else if (roman.substr(i, 1) == "X") {
					decimal += 9;
				}
				else {
					decimal++;
					i--;
				}
			}
			else {
				decimal++;
			}
		}
		if (letter == "X") {
			if (i != roman.length() - 1) {
				i++;
				if (roman.substr(i, 1) == "L") {
					decimal += 40;
				}
				else if (roman.substr(i, 1) == "C") {
					decimal += 90;
				}
				else {
					decimal += 10;
					i--;
				}
			}
			else {
				decimal += 10;
			}
		}
		if (letter == "C") {
			if (i != roman.length() - 1) {
				i++;
				if (roman.substr(i, 1) == "D") {
					decimal += 400;
				}
				else if (roman.substr(i, 1) == "M") {
					decimal += 900;
				}
				else {
					decimal += 100;
					i--;
				}
			}
			else {
				decimal += 100;
			}
		}
		if (letter == "M") {
			decimal += 1000;
		}
		if (letter == "V") {
			decimal += 5;
		}
		if (letter == "L") {
			decimal += 50;
		}
		if (letter == "D") {
			decimal += 500;
		}
	}
	return decimal;
}

string RomanNumeral::getRoman() {
	return roman;
}

int RomanNumeral::getDecimal() {
	return decimal;
}

RomanNumeral operator +(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	RomanNumeral newRoman(rn1.decimal + rn2.decimal);
	return newRoman;
}

RomanNumeral operator -(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	RomanNumeral newRoman(abs(rn1.decimal - rn2.decimal));
	return newRoman;
}

RomanNumeral operator *(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	RomanNumeral newRoman(rn1.decimal * rn2.decimal);
	return newRoman;
}

RomanNumeral operator /(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	RomanNumeral newRoman(rn1.decimal / rn2.decimal);
	return newRoman;
}

bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	if (rn1.decimal == rn2.decimal && rn1.roman == rn2.roman) {
		return true;
	}
	return false;
}

bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	if (rn1.decimal != rn2.decimal || rn1.roman != rn2.roman) {
		return true;
	}
	return false;
}

ostream& operator <<(ostream& os, const RomanNumeral& rn) {
	os << "[" << rn.decimal << ":" << rn.roman << "]";
	return os;
}

istream& operator >>(istream& is, RomanNumeral& rn) {
	string roman;
	is >> roman;
	rn.roman = roman;
	rn.decimal = rn.to_decimal(roman);

	return is;
}
