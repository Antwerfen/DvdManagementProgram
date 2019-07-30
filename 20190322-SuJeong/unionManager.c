#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"


//=================고객 관리 부분

void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	printf("ID 입력 : ");
	gets(ID);

	if (IsregistID(ID))
	{
		puts("해당 ID는 사용중입니다.");
		getchar();
		return;
	}

	printf("이름 입력 : ");
	gets(name);

	printf("전화번호 입력 : ");
	gets(phoneNum);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("데이터 저장에 실패했습니다.");
		getchar();
		return;
	}

	puts("회원 가입이 되었습니다.");
	getchar();
}


void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * cusPtr;

	printf("찾을 ID 입력 : ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("존재하지 않는 ID입니다.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}







//====================dvd관리부분



void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN을 입력하세요. : ");
	gets(ISBN);
	//scanf("%s", ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("이미 등록된 ISBN입니다. ");
		getchar();
		return;
	}

	printf("title을 입력하세요. : ");
	gets(title);

	printf("genre를 입력하세요.[1. 액션, 2.코믹, 3.SF, 4.로맨스]  : ");
	scanf("%d", &genre);
	if ((genre >= 5) || (genre < 1))
	{
		printf("잘못된 입력입니다.");
		getch();
		return;
	}

	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
	{
		puts("DVD등록에 실패하였습니다.");
		getchar();
		return;
	}

	puts("DVD등록에 성공하셨습니다.");
	getchar();
}
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;

	printf("찾는 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0)
	{
		puts("존재하지 않는 ISBN입니다.");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

void RentHanda(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;
	char cusId[ID_LEN];
	cusInfo * cusPtr;
	unsigned int rentDay;

	printf("ID를 입력하세요 : ");
	gets(cusId);

	cusPtr = GetCusPtrByID(cusId);
	if (cusPtr == 0)
	{
		puts("존재하지 않는 ID입니다.");
		getchar();
		return;
	}


	printf("대여하려는 DVD의 ISBN을 입력하세요. ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);//ISBN 중복 체크 1 대여중 0 이면 대여가능
	if (dvdPtr == 0)
	{
		puts("존재하지 않는 ISBN입니다.");
		getchar();
		return;
	}

	else
	{
		if (StateGumsa(ISBN) != 0)
		{
			printf("대여 날짜를 입력하세요. ");
			scanf("%u", &rentDay);

			StateInput(ISBN);
			AddRentInfo(ISBN, cusId, rentDay);
			
		}
		else
		{

			puts("이미 대여된 ISBN입니다.");
			getchar();
			return;
		}

	}


	puts("DVD대여에 성공하였습니다.");
	getchar();
	getchar();
}

void BannabHanda(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;

	printf("찾는 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN); //있나없나
	if (dvdPtr == 0)
	{
		puts("존재하지 않는 ISBN입니다.");
		getchar();
		return;
	}

	else
	{
		if (StateGumsa(ISBN) != NULL) //빌렸나 안 빌렸나 null은 빌렸다
		{
			printf("대여되지 않은 ISBN입니다.\n");
			getchar();
			return;
		}
		else
			State_state(ISBN);
	}


	puts("DVD반납에 성공하였습니다.");
	getchar();

}



void R_R_List(void)
{
	char ISBN[ISBN_LEN];
	dvdRentInfo * pISBN;
	

	printf("이력을 확인할 ISBN입력 : ");
	gets(ISBN);

	pISBN = GetDVDPtrByISBN(ISBN);
	if (pISBN == 0)
	{
		puts("존재하지 않는 ISBN입니다.");
		getchar();
		return;
	}

	else
		
		R_R_Listt(ISBN);
	
	
}

void Gigan_Search(void)
{
	unsigned int start_gigan;
	unsigned int end_gigan;
	char cusID[ID_LEN];
	cusInfo * ppcusID;

	printf("검색 시작일을 입력하세요.(yyyymmdd) : ");
	scanf("%u", &start_gigan);

	printf("\n검색 종료일을 입력하세요.(yyyymmdd) : ");
	scanf("%u", &end_gigan);
	getchar();

	if ((end_gigan < start_gigan) || (end_gigan <= 0) || (start_gigan <= 0))
	{
		printf("잘못된 검색일 입력입니다.\n");
		getchar();
		return 0;
	}

	
	printf("\n검색할 ID를 입력하세요.");
	gets(cusID);

	//인포에서 구현
	Real_Gigan_Search(cusID, start_gigan, end_gigan);


	ppcusID = GetCusPtrByID(cusID);

		if (ppcusID == 0)
		{
			printf("등록되지 않은 ID입니다.");
			getch();
			return;
		}
	
	puts("검색에 성공하였습니다.");
	//스크린아웃에서 구현

	getchar();
}

void initData(void)
{
	LoadCusListFromFile();
	LoadDVDListFromFile();
	LoadRentListFromFile();

}