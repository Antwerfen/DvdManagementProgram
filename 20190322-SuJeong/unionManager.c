#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"


//=================�� ���� �κ�

void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	printf("ID �Է� : ");
	gets(ID);

	if (IsregistID(ID))
	{
		puts("�ش� ID�� ������Դϴ�.");
		getchar();
		return;
	}

	printf("�̸� �Է� : ");
	gets(name);

	printf("��ȭ��ȣ �Է� : ");
	gets(phoneNum);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("������ ���忡 �����߽��ϴ�.");
		getchar();
		return;
	}

	puts("ȸ�� ������ �Ǿ����ϴ�.");
	getchar();
}


void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * cusPtr;

	printf("ã�� ID �Է� : ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("�������� �ʴ� ID�Դϴ�.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}







//====================dvd�����κ�



void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN�� �Է��ϼ���. : ");
	gets(ISBN);
	//scanf("%s", ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("�̹� ��ϵ� ISBN�Դϴ�. ");
		getchar();
		return;
	}

	printf("title�� �Է��ϼ���. : ");
	gets(title);

	printf("genre�� �Է��ϼ���.[1. �׼�, 2.�ڹ�, 3.SF, 4.�θǽ�]  : ");
	scanf("%d", &genre);
	if ((genre >= 5) || (genre < 1))
	{
		printf("�߸��� �Է��Դϴ�.");
		getch();
		return;
	}

	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
	{
		puts("DVD��Ͽ� �����Ͽ����ϴ�.");
		getchar();
		return;
	}

	puts("DVD��Ͽ� �����ϼ̽��ϴ�.");
	getchar();
}
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;

	printf("ã�� ISBN �Է� : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0)
	{
		puts("�������� �ʴ� ISBN�Դϴ�.");
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

	printf("ID�� �Է��ϼ��� : ");
	gets(cusId);

	cusPtr = GetCusPtrByID(cusId);
	if (cusPtr == 0)
	{
		puts("�������� �ʴ� ID�Դϴ�.");
		getchar();
		return;
	}


	printf("�뿩�Ϸ��� DVD�� ISBN�� �Է��ϼ���. ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);//ISBN �ߺ� üũ 1 �뿩�� 0 �̸� �뿩����
	if (dvdPtr == 0)
	{
		puts("�������� �ʴ� ISBN�Դϴ�.");
		getchar();
		return;
	}

	else
	{
		if (StateGumsa(ISBN) != 0)
		{
			printf("�뿩 ��¥�� �Է��ϼ���. ");
			scanf("%u", &rentDay);

			StateInput(ISBN);
			AddRentInfo(ISBN, cusId, rentDay);
			
		}
		else
		{

			puts("�̹� �뿩�� ISBN�Դϴ�.");
			getchar();
			return;
		}

	}


	puts("DVD�뿩�� �����Ͽ����ϴ�.");
	getchar();
	getchar();
}

void BannabHanda(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;

	printf("ã�� ISBN �Է� : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN); //�ֳ�����
	if (dvdPtr == 0)
	{
		puts("�������� �ʴ� ISBN�Դϴ�.");
		getchar();
		return;
	}

	else
	{
		if (StateGumsa(ISBN) != NULL) //���ȳ� �� ���ȳ� null�� ���ȴ�
		{
			printf("�뿩���� ���� ISBN�Դϴ�.\n");
			getchar();
			return;
		}
		else
			State_state(ISBN);
	}


	puts("DVD�ݳ��� �����Ͽ����ϴ�.");
	getchar();

}



void R_R_List(void)
{
	char ISBN[ISBN_LEN];
	dvdRentInfo * pISBN;
	

	printf("�̷��� Ȯ���� ISBN�Է� : ");
	gets(ISBN);

	pISBN = GetDVDPtrByISBN(ISBN);
	if (pISBN == 0)
	{
		puts("�������� �ʴ� ISBN�Դϴ�.");
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

	printf("�˻� �������� �Է��ϼ���.(yyyymmdd) : ");
	scanf("%u", &start_gigan);

	printf("\n�˻� �������� �Է��ϼ���.(yyyymmdd) : ");
	scanf("%u", &end_gigan);
	getchar();

	if ((end_gigan < start_gigan) || (end_gigan <= 0) || (start_gigan <= 0))
	{
		printf("�߸��� �˻��� �Է��Դϴ�.\n");
		getchar();
		return 0;
	}

	
	printf("\n�˻��� ID�� �Է��ϼ���.");
	gets(cusID);

	//�������� ����
	Real_Gigan_Search(cusID, start_gigan, end_gigan);


	ppcusID = GetCusPtrByID(cusID);

		if (ppcusID == 0)
		{
			printf("��ϵ��� ���� ID�Դϴ�.");
			getch();
			return;
		}
	
	puts("�˻��� �����Ͽ����ϴ�.");
	//��ũ���ƿ����� ����

	getchar();
}

void initData(void)
{
	LoadCusListFromFile();
	LoadDVDListFromFile();
	LoadRentListFromFile();

}