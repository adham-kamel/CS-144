/*
 * BigPi.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: adhamkamel
 */

#include <iostream>
#include <iomanip>
#include <string.h>
#include <chrono>
#include <mpir.h>
#include <mpirxx.h>
#include <math.h>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 5;
const int PLACES = 1000;        // desired decimal places
const int PRECISION = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE = 10;  // base 10 numbers
const int BIT_COUNT = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE = 100;               // digits to print per line
const int LINE_COUNT = PLACES / LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;


/**
 * Compute multiple-precision pi using functions
 * and return the elapsed time.
 * @param pi to be computed.
 * @return the compute time.
 */
duration<double> compute_pi(mpf_t& pi);

/**
 * Compute multiple-precision pi using overloaded operators
 * and return the elapsed time.
 * @param pi to be computed.
 * @return the compute time.
 */
duration<double> compute_pi(mpf_class& pi);

int main() {
	mpf_set_default_prec(BIT_COUNT * PRECISION / 2);  // precision in bits
	mpf_t p;
	mpf_init(p);

	cout << "pi to 1000 places calculated with functions:" << endl << endl;
	duration<double> elapsedT = compute_pi(p);
	cout << "Time: " << elapsedT.count() << " seconds" << endl << endl;

	mpf_class pi;
	cout << "pi to 1000 places calculated with operators:" << endl << endl;
	duration<double> elapsedC = compute_pi(pi);
	cout << "Time: " << elapsedC.count() << " seconds" <<endl;
	return 0;
}

/***** Complete this program. *****/
duration<double> compute_pi(mpf_t& pi) {
	steady_clock::time_point start = steady_clock::now();
	mpf_t six;		mpf_init(six);		mpf_set_str(six, "6", BASE);
	mpf_t four;		mpf_init(four);		mpf_set_str(four, "4", BASE);
	mpf_t two;		mpf_init(two);		mpf_set_str(two, "2", BASE);
	mpf_t one;		mpf_init(one);		mpf_set_str(one, "1", BASE);
	mpf_t sqrt2;	mpf_init(sqrt2);	mpf_sqrt(sqrt2, two);
	mpf_t sqrt4;	mpf_init(sqrt4);	mpf_sqrt(sqrt4, four);

	mpf_t fourSqrt2;	mpf_init(fourSqrt2);	mpf_mul(fourSqrt2, four, sqrt2);

	mpf_t an;			mpf_init(an);			mpf_sub(an, six, fourSqrt2);
	mpf_t yn;			mpf_init(yn);			mpf_sub(yn, sqrt2, one);




	for (int i = 1; i <= MAX_ITERATIONS; i++){
		// yi
		mpf_t powY4;		mpf_init(powY4);		mpf_pow_ui(powY4, yn, 4);
		mpf_t oneMinY4;		mpf_init(oneMinY4);		mpf_sub(oneMinY4, one, powY4);
		mpf_t big2Root;		mpf_init(big2Root);		mpf_sqrt(big2Root, oneMinY4);
		mpf_t big4Root;		mpf_init(big4Root);		mpf_sqrt(big4Root, big2Root);
		mpf_t ynNumerator;	mpf_init(ynNumerator);	mpf_sub(ynNumerator, one, big4Root);
		mpf_t ynDenom;		mpf_init(ynDenom);		mpf_add(ynDenom, one, big4Root);

		mpf_div(yn, ynNumerator, ynDenom);

		//ai
		mpf_t onePlusY;		mpf_init(onePlusY);		mpf_add(onePlusY, one, yn); // 1 + yi
		mpf_t onePlusTo4;	mpf_init(onePlusTo4);	mpf_pow_ui(onePlusTo4, onePlusY, 4); // (1 + yi)^4
		mpf_t powY2;		mpf_init(powY2);		mpf_pow_ui(powY2, yn, 2); // yi^2
		mpf_t onePlusYPlus;	mpf_init(onePlusYPlus);	mpf_add(onePlusYPlus, onePlusY, powY2); // 1 + yi + yi^2
		mpf_t aFirstHalf;	mpf_init(aFirstHalf);	mpf_mul(aFirstHalf, an, onePlusTo4); // a(i-1) * (1+yi)^4
		mpf_t twoExponent;	mpf_init(twoExponent);	mpf_pow_ui(twoExponent, two, (2*i) + 1); // 2^(2i+1)
		mpf_t aSecondSub;	mpf_init(aSecondSub);	mpf_mul(aSecondSub, yn, onePlusYPlus); // yi * (1 + yi + yi^2)
		mpf_t aSecondHalf; 	mpf_init(aSecondHalf);	mpf_mul(aSecondHalf, twoExponent, aSecondSub); // 2^(2i+1) * yi * (1 + yi + yi^2)


		mpf_sub(an, aFirstHalf, aSecondHalf);

	}

	mpf_init(pi);
	mpf_div(pi, one, an);
	mp_exp_t* expptr = new long;
	char* piStr = mpf_get_str(NULL, expptr, BASE, PRECISION, pi);
	string str = piStr;
	cout << str.substr(0,1) << ".";
	int countPerBlock = 0;
	int blockCount = 0;
	int lineCount = 0;
	for (int i = 1; i < str.length(); i++){
		cout << str.substr(i, 1);
		countPerBlock++;
		if (countPerBlock == BLOCK_SIZE){
			cout << " ";
			blockCount++;
			countPerBlock = 0;
		}
		if (blockCount == BLOCK_SIZE){
			cout << endl;
			cout << setw(3);
			blockCount = 0;
			lineCount++;
		}
		if (lineCount == GROUP_SIZE){
			cout << endl;
			lineCount = 0;
		}
	}

	steady_clock::time_point end = steady_clock::now();
	duration<double> elapsed = end - start;
	cout << endl;
	return elapsed;
}

duration<double> compute_pi(mpf_class& pi) {
	steady_clock::time_point start = steady_clock::now();

	mpf_class one(1);
	mpf_class two(2);
	mpf_class four(4);
	mpf_class six(6);
	mpf_class sqrt2(sqrt(two));
	mpf_class an(6 - (4 * sqrt2));
	mpf_class yn(sqrt2 - 1);

	for (int i = 1; i <= MAX_ITERATIONS; i++){
		// yi
		mpf_class inside4Root(1 - (yn * yn * yn * yn));
		mpf_class big2Root(sqrt(inside4Root));
		mpf_class big4Root(sqrt(big2Root));
		mpf_class ynNumerator(1 - big4Root);
		mpf_class ynDenom(1 + big4Root);
		yn = ynNumerator / ynDenom;

		// ai
		mpf_class onePlusY4((1 + yn) * (1 + yn) * (1 + yn) * (1 + yn));
		mpf_class anFirstHalf(an * onePlusY4);
		double exponent = pow(2.0, (2.0 * i) + 1);
		mpf_class twoExp(exponent);
		mpf_class anSecondHalf(twoExp * yn * (1 + yn + (yn * yn)));
		an = anFirstHalf - anSecondHalf;
	}

	pi = 1/an;
	mp_exp_t exp;
	string str = pi.get_str(exp, 10, PRECISION);
	cout << str.substr(0,1) << ".";
	int countPerBlock = 0;
	int blockCount = 0;
	int lineCount = 0;
	for (int i = 1; i < str.length(); i++){
		cout << str.substr(i, 1);
		countPerBlock++;
		if (countPerBlock == BLOCK_SIZE){
			cout << " ";
			blockCount++;
			countPerBlock = 0;
		}
		if (blockCount == BLOCK_SIZE){
			cout << endl;
			cout << setw(3);
			blockCount = 0;
			lineCount++;
		}
		if (lineCount == GROUP_SIZE){
			cout << endl;
			lineCount = 0;
		}
	}



	steady_clock::time_point end = steady_clock::now();
	duration<double> time = end - start;
	return time;
}
