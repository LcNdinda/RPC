/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "product.h"


void
product_1(char *host, float a, float b)
{
	CLIENT *clnt;
	float  *result_1;
	product  multiply_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PRODUCT, PRODUCT_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	multiply_1_arg.x=a;
	multiply_1_arg.y=b;
	result_1 = multiply_1(&multiply_1_arg, clnt);
	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("The result:%f\n", *result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 4) {
		printf ("usage: %s server_host NUMBER NUMBER\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	product_1 (host, atof(argv[2]), atof(argv[3]));
exit (0);
}
