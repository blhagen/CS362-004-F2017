/************************************************************************************
  Author: Brook Hagen
  Date: 10/19/2017
  Course: CS 362
  Description:
  1) Implement a random tester for the function testme() in testme.c that is capable
    of printing the error message.  You should implement inputChar() and inputString()
    to produce random values.
  2) Create a Makefile and add a rule in the Makefile that will compile and execute 
    the testme.c file.
  3) Submit testme.c and the Makefile under your onid directory in a directory quiz 
    in the class GitHub (under your onid directory and not under dominion directory).
  ************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


 /************************************************************************************
  Function: inputChar
  Parameters: none
  Description:
  Calling the inputChar() function will select a random character from the designated
  ASCII range. The characters of interest are within the ASCII range of 32 - 125 
  inclusive. Thus, the inputChar function should be capable of producing a character 
  of interest ('[', '(', '{', ' ', 'a', 'x', '}', ')', ']') upon each call.
  ************************************************************************************/
char inputChar()
{
  //randomly produce a character in the ASCII range of 32 - 126
  char c = (rand() % (127 - 32)) + 32;
  return c;
}

/************************************************************************************
  Function: inputChar
  Parameters: none
  Description:
  Calling the inputString() function generates a randome string that is six characters
  long. The 'string of interest' for the testMe() method is "reset\0", so the 
  inputChar function must be capable of producing this string. In order to increase
  the chances of producing "reset\0", the following have been implemented:
  1. The ASCII range from which random characters may be selected is limited to 
    101 - 116 (e - t), inclusive.
  2. The last character in the string of 6 will be hard-coded to '\0'.
  ************************************************************************************/
char *inputString()
{
  int length = 6;
  char *s = malloc(length); //allocate memory for our string
  int i;                    //loop counter
  
  // randomly produce a string of five characters within ASCII range 101 - 116
  for (i = 0; i < length - 1; i++)
  {
    s[i] = (rand() % (117 - 101) + 101);
  }

  //set the last character to '\0\'
  s[5] = '\0';

  return s;
}

/************************************************************************************
  Function: testme()
  Parameters: none
  Description:
  The testme function is a loop that calls inputChar() and inputString() through each
  iteration. 
  - The char* variable 's' holds the result of inputString().
  - The char variable 'c' holds the result of inputChar().
  The integer variables 'state' and 'tcCount' are initialized to 0. 
  - The 'tcCount' variable tracks the number of iterations.
  - The 'state' variable is incremented when a character of interest is encountered,
    in the predetermined order listed below in the function.
  The function exits when 'state' == 9 and the 's' variable = 'reset\0'.
  ************************************************************************************/
void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    //printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      //print statement to let me know when (ie, iteration number) the function finishes.
      printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
      printf("error \n");
      free(s);
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
