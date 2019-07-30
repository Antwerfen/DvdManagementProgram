#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h

	printf("----- 메 뉴 -----\n");
	printf(" 1. 신 규 가 입 \n");
	printf(" 2. 회 원 조 회 \n");
	printf(" 3. D V D  등록 \n");
	printf(" 4. D V D  조회 \n");
	printf(" 5. D V D  대여 \n");
	printf(" 6. D V D  반납 \n");
	printf(" 7. D V D  이력 \n");
	printf(" 8. 기간별검색 \n");
	printf(" 9. 종       료 \n");
	printf("-----------------");
	printf("선택 >> ");
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
		printf("액션");
		break;
	case COMIC:
		printf("코믹");
		break;
	case SF:
		printf("SF");
		break;

	case ROMANTIC:
		printf("로맨스");
		break;

	}

}

void ShowRent_Return_list(dvdRentInfo *dvd, cusInfo *cus)
{
	printf(" \n");
	printf("고 객    ID : %s\n", cus->ID);
	printf("고 객 성 명 : %s\n", cus->name);
	printf("대 여 기 간 : %u\n", dvd->rentDay);
	printf("고객전화번호: %s\n", cus->phoneNum);
	printf(" \n");

}

void Show_Gigan_Search(dvdRentInfo *dvd)
{
	printf("");
	printf("-----------------\n");
	printf("  I  S  B  N : %s \n", dvd->ISBN);
	printf(" 대 여 기 간 : %d \n", dvd->rentDay);
	printf("-----------------\n");
}




