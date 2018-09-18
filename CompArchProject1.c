#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* question 0*/
int ques0(int x, int y)
{
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return !(temp);
}

/* question 0 answer */
int ans0(int x, int y){
    int z=0;
    if (x==y)  z= 0;
    else z= 1;

    return z;
}

/* QUESTIONS */
/* question 1 */
int ques1(int x) {
    int z;
    //twos complement of x
    int y  = ~x+1;
    //z is always going to start with 0 unless x = 0
    //because of two's complement
    z= (~(y|x));
    //shift a number that starts with 0, 31 times will always be 0
    //if the number starts with 1 then it will be all 1's
    z = (z >> 31);

    //AND by 1 will only make the last bit become 1 if in z the last bit is 1.
    //the answer will be 1 when x started off as 0, and will be 0 for any other number
    return (z & 1);
}

/* question 1 answer */
int ans1(int x) {
    if(x == 0) return 1;
    else return 0;
}

/* question 2 */
int ques2(int x) {
	// if the input is negative, the mask is -1
	// if the input is 0 or positive, the mask is 0
    int mask = x>>31;
	// input 'XOR'ed with the mask (either 0 or -1)
    int y= (x ^ mask);
	// if the mask is -1, z equals 1
	// if the mask is 0, z equals 0
    int z = (~mask + 1);

	// return (y+z)
    return (y+z);
}

/* question 2 answer */
int ans2(int x) {
  // the output is just the absolute value of the input x
  return abs(x);
}

/* question 3 */
int ques3(int x) {
    //if you 'NOT' a nonzero number, you get 0
    // if you 'NOT' zero, you get 1
    int y = !x;
    
    // if the number is positive or 0 (leftmost bit = 0), z = 0
    // if the number is negative (leftmost bit = 1), z = -1 (all 1's in binary)
    int z = x >> 31;
  
    // 'OR' function, if z & y are both 0, z = 0
    // otherwise, z = 1
    z = z | y;

    // returns 'NOT' z
    // if z & y both equal 0, returns 1
    // otherwise, the return function returns 0
    return !z;
}

/* question 3 answer */
int ans3(int x) {
  // if x is positive, return 1
  if (x > 0) return 1;
  // if x is negative or 0, return 0
  else return 0;
}

/* question 4 */
/* Assume 0 <= n <= 32 */
int ques4(int n) {
    //!! makes the number either 1 or 0
    //(!!n) = 1 if n is 1 <= n <= 32
    //(!!n) = 0 if n is 0
    //shifts the number to the left 31 bits
    //if (!!n) = 1 then the number will be 1000...0000
    //else it will be 0000....0000
    int x = (!!n) << 31;

    //shifting it back will make it 1111...1111 if (!!n) = 1
    //or 0000.....0000 if (!!n) = 0
    x = x >> 31;
    
    //int y = 1000...0000
    int y = (1 << 31);

    //shifts y to the left by n-1 amount
    y = y >> (n + (~0));

    //x & y 
    //divides y by 2^n-1
    return x & y;
}

/* question 4 answer */
int ans4(int n) {
    int y = -2147483648;
    int value = n-1;
    double power;
    power = pow(2,value);
    if(n == 0) {
      return 0;
    } else {
      y = y / power;
      return y;
    }
}

/* question 5 */
int ques5(int x) {
    //if x is odd then result is 1000...0000
    //if x is even then result is 0000....0000
    int result = (x<<31);
    
    //if result is 1000....0000 (i.e. odd) then the number will be 1111....1111
    //if result is 0000....0000 (i.e. even) then the number will be 0000....0000
    result = (result >> 31);

    //will return either -1 or 0 depending on if its even or odd
    return result;
}

/* question 5 answer */
int ans5(int x) {
    if(x % 2 == 0) {
        return 0;
    } 
    if (x % 2 == 1) {
        return -1;
    }
}

/* question 6 */
int ques6(void) {
    int byte = 0x55;
    int word = byte | byte<<8;

    return word | word<<16;
}

/* question 6 answer */
int ans6() {
	return 1431655765;
}

/* question 7 */
int ques7(int x) {
  return x & (~x+1);
}

/* question 7 answer */
int ans7(int x) {
	return x & (~x+1); //takes x and 2's complement of x and returns the GCF of both decimal versions of the numbers
}  

/* question 8 */
int ques8(int x) {
    // if input is positive, y is 0
    // if input is negative, y is -1
    // if input is 0, y is 0
    int y = x >> 31;
  
    // if input is positive/negative, z is 1
    // if input is 0, z is 0
    int z = !!x;

    // positive input: 0 OR 1 returns 1
    // negative input: -1 OR 1 returns -1
    // 0 input: 0 OR 0 returns 0
    return y | z;
}

/* question 8 answer */
int ans8(int x) {
  // if x is positive, return 1
  if (x > 0) return 1;
  // if x is 0, return 0
  else if (x == 0) return 0;
  // if x is negative, return -1
  else if (x < 0) return -1;
}

/* question 9 */
int ques9(int x, int n, int c) {
    int n8 = n << 3; //calculates number of bits in a byte when multiplying by 8
    int mask = 0xff << n8;
    int cshift = c << n8;
    int z= (x & ~mask);

    return (z  | cshift);
}

/* question 9 answer */
int ans9(int x, int n, int c) {
  int y = n<<3;
  int mask = 0xff << y;
  int cshift = c << y;
  int z = (x & ~mask);
  return (z | cshift);
}

/* question 10 */
int ques10(int x) {
	int y = !!x;
	int z = (!(x+x));
  return y & z;
}

/* question 10 answer */
int ans10(int x) {
  if(x==0) {
    return x;
  } else {
    return(!x);
  }
}

/* question 11 */
int ques11(int x, int y) {
	int a = x >> 31;
	int b = y >> 31;
  return !((!a & b) | (!(a ^ b) & (y+~x)>>31));
}

/* question 11 answer */
int ans11(int x, int y) {
  //when input x is either 0 or positive
  if (x >= 0 && y >= 0) {
     x = 0;
     y = 0;
  } else {
     x = -1;
     y = -1;
  }
  return (x && !y);

}

/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1; //takes 2's complement of input m
    int b = ~x +1; //takes 2's complement of input x
    a = x + a; //does x-m in adding x+a since 2's complement of m produces -m
    b = b + n; //adds b + n or n-x because 2's complement produces -x

    return !((a|b) >> 31); //OR's a and b and shifts 31 positions, then inverts that value
}

/* question 12  answer*/
int ans12(int x, int m, int n) {
   return (n >= x && x >= m);
}


/* question 13 */
int ques13(int x) {
    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8);
    mask2 += mask2 << 16;
    mask1 = mask2 ^ (mask2 << 1);
    mask4 = 0x0F + (0x0F << 8);
    mask4 += mask4 << 16;
    mask8 = 0xFF + (0xFF << 16);
    mask16 = 0xFF + (0xFF << 8);

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}

/* question 13 answer */
int ans13(int x) {
  int cursor = 0;
  while (x) {
    cursor += x&1; //searches for if there is a 1 in the binary number and sums up number of them
    x >>= 1; //shifts to next bit to search again
  }
  return cursor;
}

/* question 14 */
int ques14(int x) {
    int result = 0;
    int i;

    for (i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;

    return result;
}

/* question 14 answer */
int ans14(int x) {
  int temp = 0; 
  int count = 0;
  for(int i = 0; i < 32; i++) {
    temp = x&1;
     x = x>>1;

    if(temp == 1)
        count++;
  }
  if (count%2 == 1) {
	  return 1;
  } else {
	  return 0;
  }
  return 0;
}

/* question 15 */
int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

// temp is set to 2^n
    int temp = (1 << n); 
// z is set to temp minus 1, in other words, z equals 2^n - 1
    int z = temp + ~0;
// the 'AND' between z & x is x mod 2^n, essentially the remainder of x/2^n or x/temp
    return (z & x);
}

/* question 15 answer */
int ans15(int x, int n) {
  if (x < 0) {
	  // if x < 0, absolute value x mod 2^n 
    return abs(x % (1 << n));
  } else { 
	 // if x >= 0,  x mod 2^n
	return (x % (1 << n));
  }
}


int main() {
  int a, b, c;
  int t1;

 	printf("Enter First Number (int 1 - 20):");
 	scanf ("%d",&a);
	printf("\n");
 	printf("Enter Second Number (int 1 - 20):");
 	scanf ("%d", &b);
  printf("Enter Third Number (int 1 - 20):");
 	scanf ("%d", &c);
	printf("\n");
  
	printf("You entered a= %d b= %d c=%d\n", a,b,c);

  // Question 1
  t1 = ques1(a);
  printf("Question 1: %d\n", t1);
  t1 = ans1(a);
  printf("Question 1 Answer: %d\n", t1);
  
  // Question 2
  t1 = ques2(a);
  printf("Question 2: %d\n", t1);
  t1 = ans2(a);
  printf("Question 2 Answer: %d\n", t1);
  
  // Question 3
  t1 = ques3(a);
  printf("Question 3: %d\n", t1);
  t1 = ans3(a);
  printf("Question 3 Answer: %d\n", t1);
  
  // Question 4
  t1 = ques4(a);
  printf("Question 4: %d\n", t1);
  t1 = ans4(a);
  printf("Question 4 Answer: %d\n", t1);
  
  // Question 5
  t1 = ques5(a);
  printf("Question 5: %d\n", t1);
  t1 = ans5(a);
  printf("Question 5 Answer: %d\n", t1);
  
  // Question 6
  t1 = ques6();
  printf("Question 6: %d\n", t1);
  t1 = ans6();
  printf("Question 6 Answer: %d\n", t1);
  
  // Question 7
  t1 = ques7(a);
  printf("Question 7: %d\n", t1);
  t1 = ans7(a);
  printf("Question 7 Answer: %d\n", t1);
  
  // Question 8
  t1 = ques8(a);
  printf("Question 8: %d\n", t1);
  t1 = ans8(a);
  printf("Question 8 Answer: %d\n", t1);
  
  // Question 9
  t1 = ques9(a,b,c);
  printf("Question 9: %d\n", t1);
  t1 = ans9(a,b,c);
  printf("Question 9 Answer: %d\n", t1);
  
  // Question 10
  t1 = ques10(a);
  printf("Question 10: %d\n", t1);
  t1 = ans10(a);
  printf("Question 10 Answer: %d\n", t1);
  
  // Question 11
  t1 = ques11(a,b);
  printf("Question 11: %d\n", t1);
  t1 = ans11(a,b);
  printf("Question 11 Answer: %d\n", t1);
  
  // Question 12
  t1 = ques12(a,b,c);
  printf("Question 12: %d\n", t1);
  t1 = ans12(a,b,c);
  printf("Question 12 Answer: %d\n", t1);
  
  // Question 13
  t1 = ques13(a);
  printf("Question 13: %d\n", t1);
  t1 = ans13(a);
  printf("Question 13 Answer: %d\n", t1);
  
  // Question 14
  t1 = ques14(a);
  printf("Question 14: %d\n", t1);
  t1 = ans14(a);
  printf("Question 14 Answer: %d\n", t1);
  
  // Question 15
  t1 = ques15(a,b);
  printf("Question 15: %d\n", t1);
  t1 = ans15(a,b);
  printf("Question 15 Answer: %d\n", t1);

	return 0;
}