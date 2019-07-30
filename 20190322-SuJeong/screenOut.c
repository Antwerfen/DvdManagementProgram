#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h

	printf("----- �� �� -----\n");
	printf(" 1. �� �� �� �� \n");
	printf(" 2. ȸ �� �� ȸ \n");
	printf(" 3. D V D  ��� \n");
	printf(" 4. D V D  ��ȸ \n");
	printf(" 5. D V D  �뿩 \n");
	printf(" 6. D V D  �ݳ� \n");
	printf(" 7. D V D  �̷� \n");
	printf(" 8. �Ⱓ���˻� \n");
	printf(" 9. ��       �� \n");
	printf("-----------------");
	printf("���� >> ");
}

void ShowCustomerInfo(cusInfo * pCus)
{
	printf("");
	printf("-----------------\n");
	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n", pCus->name);
	printf(" Phone : %s \n", pCus->phoneNum);
	printf("-----------------");

	getchar();
}

void ShowDVDInfo(dvdInfo * pDVD)
{
	printf("");
	printf("-----------------\n");
	printf(" I S  B  N : %s \n", pDVD->ISBN);
	printf(" t i t l e : %s \n", pDVD->title);
	printf(" g e n r e :  ");
	ShowGenre(pDVD->genre);
	printf("\n-----------------\n");


	getchar();
}

void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		printf("�׼�");
		break;
	case COMIC:
		printf("�ڹ�");
		break;
	case SF:
		printf("SF");
		break;

	case ROMANTIC:
		printf("�θǽ�");
		break;

	}

}

void ShowRent_Return_list(dvdRentInfo *dvd, cusInfo *cus)
{
	printf(" \n");
	printf("�� ��    ID : %s\n", cus->ID);
	printf("�� �� �� �� : %s\n", cus->name);
	printf("�� �� �� �� : %u\n", dvd->rentDay);
	printf("����ȭ��ȣ: %s\n", cus->phoneNum);
	printf(" \n");

}

void Show_Gigan_Search(dvdRentInfo *dvd)
{
	printf("");
	printf("-----------------\n");
	printf("  I  S  B  N : %s \n", dvd->ISBN);
	printf(" �� �� �� �� : %d \n", dvd->rentDay);
	printf("-----------------\n");
}




