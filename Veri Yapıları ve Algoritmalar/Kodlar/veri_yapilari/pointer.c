#include <stdio.h>

void callByValue(int p, int q) {
	p++; q++;
	printf("yeni degerler %d, %d\n",p,q);
}

void callByReference(int *p, int *q) {
	(*p)++; (*q)++;
	printf("yeni degerler %d, %d\n", *p, *q);
}

void value(int *p, int *q) {
	(*p)++; (*q)++;
	printf("p ve q nun degerleri %d, %d\n", p, q);
}

int main() {

	/*int a[] = { 1,2,3 };
	for (int i = 0; i < 3; i++) {
		printf("a nin degeri = %d\n", a[i]);
		printf("a nin adresi = %u\n", &a[i]);
	}*/


	//int a = 2;
	//int *b, **c;
	//b = &a;
	//// c = &a; yapamayız, cunku a'in icinde deger var, adres yok
	//c = &b;

	//// &a = b = *c
	//// &b = c
	//printf("a, b ve c degerleri %d,%d,%d\n", &a, b, *c);
	//printf("a, b ve c degerleri %d,%d,%d\n", a, b, *c);
	//printf("a, b ve c degerleri %d,%d,%d\n", a, *b, *c);
	//printf("a, b ve c degerleri %d,%d,%d", a, *b, **c);


	// deger ile cagirma
	int a = 2;
	int b = 1;
	printf("deger ile cagirilmadan once %d, %d\n", a, b);
	callByValue(a, b);
	printf("deger ile cagirildiktan sonra %d, %d\n", a, b);

	printf("\n");

	// referans ile cagirma
	printf("referans ile cagirilmadan once %d, %d\n", a, b);
	callByReference(&a, &b);
	printf("referans ile cagirildiktan sonra %d, %d\n", a, b);

	printf("\na ve b nin adresleri %d, %d\n", &a, &b);
	value(&a,&b);

	getch();
	return 0;
}