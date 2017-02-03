#include <stdio.h>

//Mehrshad Matin
//301117102
///CMPT - 295
///Assignment - 1

typedef unsigned int bit32;
typedef unsigned int bit16;

void printhex32(bit32 x) {
	printf("%.12x ", x);
}

void printhex16(bit16 x) {
	printf("%.8x ", x);
}

unsigned int get_sign(bit16 x) {
	if(x & 0x8000) {
		return 1;
	}
	return 0;
}

unsigned int get_exp(bit16 x) {
	return (x & 0x7f00) >> 8;
}

unsigned int get_frac(bit16 x) {
	return x & 0xff;
}

bit16 float_16(unsigned sign, unsigned exp, unsigned frac) {
	if(sign) {
		sign = 0x8000; // if the sign is minus, set bit 15 to one
	}
	return sign | (exp << 8) | frac; // or everything together
}

bit16 fp_mult(bit16 x, bit16 y) {
	bit16 p = 0; // set product to 0
	p |= (x & 0x8000) ^ (y & 0x8000); // set the sign of the result number
	if((x == 0x0000) || (y == 0x0000)) { // if one of the numbers is zero
		return 0x0000; // return zero
	}
	unsigned int exp = ((x & 0x7f00) + (y & 0x7f00)) >> 8; // sum of exps
	unsigned int prod = ((x & 0xff) | 0x100) * ((y & 0xff) | 0x100);
	if(prod & 0x20000) { // if 17's bit of that prod is set
		p |= ((prod & 0x1fe00) >> 9);
		++exp; // adjust exponent
	} else {
		p |= ((prod & 0xff00) >> 8);
	}
	// set the exponent:
	if(exp > (126 + 63) || exp < (1 + 63)) {
		return 0x7f00;
	} else {
		p |= ((exp - 63) << 8);
	}
	return p;
}