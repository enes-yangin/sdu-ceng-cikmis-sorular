#include <stdio.h>
#include <conio.h>

typedef struct
{
	int real, img;
} karmasik;

karmasik topla(karmasik sayi1, karmasik sayi2)
{
	karmasik sonuc;
	sonuc.real = sayi1.real + sayi2.real;
	sonuc.img = sayi1.img + sayi2.img;
	return sonuc;
}

karmasik cikar(karmasik sayi1, karmasik sayi2)
{
	karmasik sonuc;
	sonuc.real = sayi1.real - sayi2.real;
	sonuc.img = sayi1.img - sayi2.img;
	return sonuc;
}

// ac - bd + (ad + bc)i
karmasik carp(karmasik sayi1, karmasik sayi2)
{
	karmasik sonuc;
	sonuc.real = (sayi1.real * sayi2.real) - (sayi1.img * sayi2.img);
	sonuc.img = (sayi1.real * sayi2.img) + (sayi1.img * sayi2.real);
	return sonuc;
}

// [(ac + bd) / (c^2 + d^2)] + [(bc - ad) / (c^2 + d^2)]i
karmasik bol(karmasik sayi1, karmasik sayi2)
{
	karmasik sonuc;
	sonuc.real = ((sayi1.real * sayi2.real) + (sayi1.img * sayi2.img)) /
				 ((sayi2.real * sayi2.real) + (sayi2.img * sayi2.img));
	sonuc.img = ((sayi1.img * sayi2.real) - (sayi1.real * sayi2.img)) /
				((sayi2.real * sayi2.real) + (sayi2.img * sayi2.img));
	return sonuc;
}

int main()
{
	karmasik sayi1, sayi2, toplam, cikartma, carpim, bolme;
	int secim;

	printf("islem seciniz: \n1 - toplama\n2 - cikarma\n3 - carpma\n4 - bolme\n");
	scanf("%d", &secim);

	printf("sayi1.real: ");
	scanf("%d", &sayi1.real);

	printf("sayi1.img: ");
	scanf("%d", &sayi1.img);

	printf("sayi2.real: ");
	scanf("%d", &sayi2.real);

	printf("sayi2.img: ");
	scanf("%d", &sayi2.img);

	switch (secim){
	case 1:
		toplam = topla(sayi1, sayi2);
		if (toplam.img < 0)
			printf("toplam	: %d%di\n", toplam.real, toplam.img);
		else
			printf("toplam	: %d+%di\n", toplam.real, toplam.img);
		break;
	case 2:
		cikartma = cikar(sayi1, sayi2);
		if (cikartma.img < 0)
			printf("cikartma: %d%di\n", cikartma.real, cikartma.img);
		else
			printf("cikartma: %d+%di\n", cikartma.real, cikartma.img);
		break;
	case 3:
		carpim = carp(sayi1, sayi2);
		if (carpim.img < 0)
			printf("carpim	: %d%di\n", carpim.real, carpim.img);
		else
			printf("carpim	: %d+%di\n", carpim.real, carpim.img);
		break;
	case 4:
		bolme = bol(sayi1, sayi2);
		if (bolme.img == 0)
			printf("bolme	: %d\n", bolme.real);
		else if (bolme.img < 0)
			printf("bolme	: %d%di\n", bolme.real, bolme.img);
		else
			printf("bolme	: %d+%di\n", bolme.real, bolme.img);
		break;
	default:
		printf("1-2-3-4 seceneklerinden birini seciniz");
		break;
	}

	getch();
	return 0;
}