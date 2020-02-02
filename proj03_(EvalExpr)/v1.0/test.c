#include "header.h"

int main()
{
	int count = 0;
	int cmp = 0;
	int testcount = 10;
	int i = 1;


	printf("TEST %d/%d\t\t3 + 42 * (1 - 2 / (3 + 4) - 1 %% 21) + 1\n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1"));
	printf("\tActual result:\t%d\n", 3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1);
	cmp = 3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1;
	if (cmp == eval_expr("3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;


	printf("TEST %d/%d\t\t (((78 - 2) * -5 %% 889) / 4) \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("(((78 - 2) * -5 % 889) / 4)"));
	printf("\tActual result:\t%d\n", (((78 - 2) * -5 % 889) / 4));
	cmp = (((78 - 2) * -5 % 889) / 4);
	if (cmp == eval_expr("(((78 - 2) * -5 % 889) / 4)")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;

	printf("TEST %d/%d\t\t 1 - (78 - -87 + -9 * -99) - (4 * (4 - -8)) \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("1 - (78 - -87 + -9 * -99) - (4 * (4 - -8))"));
	printf("\tActual result:\t%d\n", 1 - (78 - -87 + -9 * -99) - (4 * (4 - -8)));
	cmp = 1 - (78 - -87 + -9 * -99) - (4 * (4 - -8));
	if (cmp == eval_expr("1 - (78 - -87 + -9 * -99) - (4 * (4 - -8))")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;


	printf("TEST %d/%d\t\t (5 + 6) - (12 / 6) \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("(5 + 6) - (12 / 6)"));
	printf("\tActual result:\t%d\n", (5 + 6) - (12 / 6));
	cmp = (5 + 6) - (12 / 6);
	if (cmp == eval_expr("(5 + 6) - (12 / 6)")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;


	printf("TEST %d/%d\t\t (256 %% 16) - ((45 * -9) - 6) + 6 - 8 * 7 * 7 / 9 * 1 \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("(256 % 16) - ((45 * -9) - 6) + 6 - 8 * 7 * 7 / 9 * 1"));
	printf("\tActual result:\t%d\n", (256 % 16) - ((45 * -9) - 6) + 6 - 8 * 7 * 7 / 9 * 1);
	cmp = (256 % 16) - ((45 * -9) - 6) + 6 - 8 * 7 * 7 / 9 * 1;
	if (cmp == eval_expr("(256 % 16) - ((45 * -9) - 6) + 6 - 8 * 7 * 7 / 9 * 1")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;


	printf("TEST %d/%d\t\t 1 + 2 * 3 / 4 * 5 + 6 - 7 * 8 / 9 - 1 + 2 + 7 * 8 * 5 - 9 / 9 * 7 * 7 * 7 \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("1 + 2 * 3 / 4 * 5 + 6 - 7 * 8 / 9 - 1 + 2 + 7 * 8 * 5 - 9 / 9 * 7 * 7 * 7"));
	printf("\tActual result:\t%d\n", 1 + 2 * 3 / 4 * 5 + 6 - 7 * 8 / 9 - 1 + 2 + 7 * 8 * 5 - 9 / 9 * 7 * 7 * 7);
	cmp = 1 + 2 * 3 / 4 * 5 + 6 - 7 * 8 / 9 - 1 + 2 + 7 * 8 * 5 - 9 / 9 * 7 * 7 * 7;
	if (cmp == eval_expr("1 + 2 * 3 / 4 * 5 + 6 - 7 * 8 / 9 - 1 + 2 + 7 * 8 * 5 - 9 / 9 * 7 * 7 * 7")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;



	printf("TEST %d/%d\t\t 3 + 3 \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("3 + 3"));
	printf("\tActual result:\t%d\n", 3 + 3);
	cmp = 3 + 3;
	if (cmp == eval_expr("3 + 3")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;

	printf("TEST %d/%d\t\t 5 + (5 * 4 - (6 * 7)) - 54 * -9 \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("5 + (5 * 4 - (6 * 7)) - 54 * -9"));
	printf("\tActual result:\t%d\n", 5 + (5 * 4 - (6 * 7)) - 54 * -9);
	cmp = 5 + (5 * 4 - (6 * 7)) - 54 * -9;
	if (cmp == eval_expr("5 + (5 * 4 - (6 * 7)) - 54 * -9")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;

	printf("TEST %d/%d\t\t -54 * 98 + 6 * -9 + (45 / 8 * -62) - -88 + ((74 - 61) * -9) \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("-54 * 98 + 6 * -9 + (45 / 8 * -62) - -88 + ((74 - 61) * -9)"));
	printf("\tActual result:\t%d\n", -54 * 98 + 6 * -9 + (45 / 8 * -62) - -88 + ((74 - 61) * -9));
	cmp = -54 * 98 + 6 * -9 + (45 / 8 * -62) - -88 + ((74 - 61) * -9);
	if (cmp == eval_expr("-54 * 98 + 6 * -9 + (45 / 8 * -62) - -88 + ((74 - 61) * -9)")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;


	printf("TEST %d/%d\t\t ((1 + ((((2 * ((((((-4 * 6))))))) + 2)))) * -1) \n", i, testcount);
	printf("\tYour result:\t%d\n", eval_expr("((1 + ((((2 * ((((((-4 * 6))))))) + 2)))) * -1)"));
	printf("\tActual result:\t%d\n", ((1 + ((((2 * ((((((-4 * 6))))))) + 2)))) * -1));
	cmp = ((1 + ((((2 * ((((((-4 * 6))))))) + 2)))) * -1);
	if (cmp == eval_expr("((1 + ((((2 * ((((((-4 * 6))))))) + 2)))) * -1)")) {
		printf("\t\x1b[32mPASSED\x1b[0m\n");
	}
	else {
		printf("\t\x1b[31mFAILED\x1b[0m - you suck\n");
		count++;
	}

	i++;



	if (count != 0) {
		printf("\n\n\x1b[31mSorry. Failed %d tests out of %d 😞 😞 😞 😞 😞  Fix your code and try again, you can do it!\x1b[0m\n", count, i);
	} else {
		printf("\n\n\t\x1b[32mPASSED ALL TESTS - You Rock ! 🍺 💯 🍺 💯 🍺 💯 🍺\x1b[0m\n");
	}
}
