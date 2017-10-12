#include <stdint.h>		//Brian Ryan 03/12/2016  
#include <stdlib.h>			//Library functions & include files declare the standard functions
#include <stdio.h>			//and constants of the API
#include <limits.h>			//we utilise our own include file here practical.h, which has
#include "Practical.h"		//prototypes for functions
//Integer variables with values to be encoded
const uint8_t val8 = 101; // One hundred and one
const uint16_t val16 = 10001; // Ten thousand and one
const uint32_t val32 = 100000001; // One hundred million and one
const uint64_t val64 = 1000000000001L; // One trillion and one
const int MESSAGELENGTH = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint32_t)//message length computation
    + sizeof(uint64_t);

static char stringBuf[BUFSIZE];//take an array of bytes and its length and return a string
char *BytesToDecString(uint8_t *byteArray, int arrayLength) {
  char *cp = stringBuf;
  size_t bufSpaceLeft = BUFSIZE;
  for (int i = 0; i < arrayLength && bufSpaceLeft > 0; i++) {
    int strl = snprintf(cp, bufSpaceLeft, "%u ", byteArray[i]);
    bufSpaceLeft -= strl;
    cp += strl;
  }
  return stringBuf;//value of each byte as a decimal integer in range 0 - 255
}

// Warning:  Untested preconditions (e.g., 0 <= size <= 8)
//On each iteration, the right-hand side of the assignment shifts the value to be encoded to the right,
int EncodeIntBigEndian(uint8_t dst[], uint64_t val, int offset, int size) {//resulting value is then cast to the type uint8_t,
  for (int i = 0; i < size; i++) {
    dst[offset++] = (uint8_t) (val >> ((size - 1) - i) * CHAR_BIT);
  }//ending value of offset is returned so that the caller does not have to recompute it when
  return offset;//encoding a sequence of integers
}

// Warning:  Untested preconditions (e.g., 0 <= size <= 8)
uint64_t DecodeIntBigEndian(uint8_t val[], int offset, int size) {//value in 64 bit integer variable
  uint64_t rtn = 0;//iterate size times, each time shift the accumulated value left and bitwise ORing the next
  for (int i = 0; i < size; i++) {//bytes value
    rtn = (rtn << CHAR_BIT) | val[offset + i];
  }
  return rtn;
}

int main(int argc, char *argv[]) {//BELOW Declare buffer (array of bytes) to receive series of integers:
  uint8_t message[MESSAGELENGTH]; // Big enough to hold all four values

  // Encode the integers in sequence in the message buffer
  int offset = 0;//integers encoded into array
  offset = EncodeIntBigEndian(message, val8, offset, sizeof(uint8_t));
  offset = EncodeIntBigEndian(message, val16, offset, sizeof(uint16_t));
  offset = EncodeIntBigEndian(message, val32, offset, sizeof(uint32_t));
  offset = EncodeIntBigEndian(message, val64, offset, sizeof(uint64_t));
  printf("Encoded message:\n%s\n", BytesToDecString(message, MESSAGELENGTH));//print contents of encoded array

  uint64_t value =//Extract and display some values from encoded message
      DecodeIntBigEndian(message, sizeof(uint8_t), sizeof(uint16_t));
  printf("Decoded 2-byte integer = %u\n", (unsigned int) value);
  value = DecodeIntBigEndian(message, sizeof(uint8_t) + sizeof(uint16_t)
      + sizeof(uint32_t), sizeof(uint64_t));//Output should show the decoded values 
  printf("Decoded 8-byte integer = %llu\n", value);//equal to the original constants.

  // Show signedness
  offset = 4;//byte value here is 245
  int iSize = sizeof(int32_t);
  value = DecodeIntBigEndian(message, offset, iSize);//place the result into botha signed int 
  printf("Decoded value (offset %d, size %d) = %lld\n", offset, iSize, value);//& unsigned int
  int signedVal = DecodeIntBigEndian(message, offset, iSize);
  printf("...same as signed value %d\n", signedVal);
}
