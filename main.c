#include <stdio.h>
//Mehrshad Matin
//301117102
///CMPT - 295
///Assignment - 1
int main() {
	
	printf("\n1.25 * 3.75 =\t0x");
	printhex16(fp_mult(float_16(0, 63, 0x40), float_16(0, 64, 0xe0)));
	printf("\n0 * 3.75 =\t0x");
	printhex16(fp_mult(float_16(0, 0, 0x00), float_16(0, 64, 0xe0)));
	printf("\n0 * 0 = \t0x");
	printhex16(fp_mult(float_16(0, 0, 0x00), float_16(0, 0, 0x00)));
	printf("\n2^7 * 1 =\t0x");
	printhex16(fp_mult(float_16(0, 70, 0x00), float_16(0, 63, 0x00)));
	printf("\n2^7 * 2^-7 =\t0x");
	printhex16(fp_mult(float_16(0, 70, 0x00), float_16(0, 56, 0x00)));
	printf("\n2^63 * 2 =\t0x");
	printhex16(fp_mult(float_16(0, 126, 0x00), float_16(0, 64, 0x00)));
	printf("\n2^32 * 2^31 =\t0x");
	printhex16(fp_mult(float_16(0, 96, 0x00), float_16(0, 95, 0x00)));
	printf("\n2^-62 * 2^-62 =\t0x");
	printhex16(fp_mult(float_16(0, 1, 0x00), float_16(0, 1, 0x00)));
	printf("\n");
}
