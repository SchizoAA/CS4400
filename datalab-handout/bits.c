/* 
 * CS:APP Data Lab 
 * 
 * Kyle Erickson u0461601
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	int r1 = ~x | ~y;
	return ~r1;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	n = n << 3;
	int r1 = x >> n;
	r1 = r1 & 0xff
	return r1;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	x = x >> n;
	int mask = ((1 << (32 + (~n+1))) + ~0);
	return x & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	//Hamming weight algorithm
	int first = 0x55;
	first = (first << 8) | first;
	first = (first << 16) | first;//creates 0x55555555
	int second = 0x33;
	second = (second << 8) | second;
	second = (second << 16) | second;//creates 0x33333333
	int third = 0x0f;
	third = (third << 8) | third;
	third = (third << 16) | third;//creates 0x0f0f0f0f
	int fourth = 0xff;
	fourth = (fourth << 16) | fourth;//creates 0x00ff00ff
	int fifth = 0xff;
	fifth = (fifth << 8) | fifth;//creates 0x0000ffff
	x = (x & first) + ((x >> 1) & first);
	x = (x & second) + ((x >> 2) & second);
	x = (x & third) + ((x >> 4) & third);
	x = (x & fourth) + ((x >> 8) & fourth);
	x = (x & fifth) + ((x >> 16) & fifth);
	return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	x = x | (~x + 1); //adding 1 handles case of 0. If > 0, all 1's. If = 0, all 0's
	x = x >> 31; //fills msb
	return x + 1; //add 1 to achieve correct result
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int m = x >> 31;
	int r1 = (~x & m)+(x & ~m);//get highest bit
  return !(r1 >> (n + ~0));//see if it fits in n bits.
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	/*Mask bits, round, and divide*/
	int mask = (1 << n) + ~0;
    return (x + ((x >> 31) & mask)) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	/*Invert x and add 1*/
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	/*Mask highest bit and check if it is negative or number = 0*/
	int mask = 1 << 31;
	int res = !(x & mask);
	int zero = !x;
  return res ^ zero;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int signs = x ^ y;//check if signs are same
	int diff = y + (~x+1);//y-x
	result = ~signs & ~diff; //Check difference
	signs = signs & x; //is x negative?
	result = result & signs; //Check sign of x
	result = result & (1 << 31); //is difference negative?
	return (!!result) & (!(!diff));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	/*Fill all bits below highest 1*/
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	
	/*Hamming weight algorithm counts number of 1 bits*/
	int first = 0x55;
	first = (first << 8) | first;
	first = (first << 16) | first;//creates 0x55555555
	int second = 0x33;
	second = (second << 8) | second;
	second = (second << 16) | second;//creates 0x33333333
	int third = 0x0f;
	third = (third << 8) | third;
	third = (third << 16) | third;//creates 0x0f0f0f0f
	int fourth = 0xff;
	fourth = (fourth << 16) | fourth;//creates 0x00ff00ff
	int fifth = 0xff;
	fifth = (fifth << 8) | fifth;//creates 0x0000ffff
	
	x = (x & first) + ((x >> 1) & first);
	x = (x & second) + ((x >> 2) & second);
	x = (x & third) + ((x >> 4) & third);
	x = (x & fourth) + ((x >> 8) & fourth);
	x = (x & fifth) + ((x >> 16) & fifth);
  return x + ~0;//subtract 1 from result for floor
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	/*Check if argument is NaN*/
	if((uf << 1) > 0xff000000){
		return uf;
	}
	return (uf ^ (1 << 31));
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	unsigned sign = 0;
	unsigned abs = x;
	unsigned exp = 158;
	
	if(x){
		/*If x is negative, save sign bit and take absolute value.*/
		if(x < 0)
		{
			sign = 0x80000000;
			abs = -x;
		}
		while((abs & 0x80000000)== 0)
		{
			exp--;
			abs = abs << 1;
		}
		
		unsigned man = abs >> 8;
		return sign | (exp << 23) | (man & 0x7fffff)
	}
	else
		return x;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	unsigned sign = uf & 0x80000000;
	unsigned exp = (uf >> 23) & 0xff;
	unsigned man = uf & 0x7fffff;
	
	/*Check if NaN*/
    if (exp >= 0xff || exp == 0 && man == 0) { 
        return uf;
    } 
	/*Normalized - increase exponent*/
	else if (exp) {
        exp++;
    } 
	/*edge - reduce fraction, increase exponent*/
	else if (man == 0x7fffff) {
		exp++;
		man--;
    } 
	/*shift fraction one bit left*/
	else {
        man = man << 1;
    }
	return sign | (exp << 23) | (man);
}
