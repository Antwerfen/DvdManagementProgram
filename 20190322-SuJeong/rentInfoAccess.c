#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"
#include "rentInfoAccess.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

#define RENT_LEN 100
#define RENT_BACKUP_FILE "rentInfo.dat"
#define MAX_DVD 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;
extern int numOfDvd;
extern dvdInfo *dvdList[];
extern int numOfRDvd;
//extern dvdRentInfo *dvdRentList[];
extern cusInfo * cusList[];
extern int numOfCustomer;

/*
��� : DVD �뿩 ������ �����ϴ� �Լ�
��ȯ : void
*/


void AddRentInfo(char * ISBN, char * cusId, unsigned int rentDay)
{
	/*
	dvdRentInfo * pRent;

	if (numOfRentCus >= MAX_DVD)
		return 0;

	pRent = (dvdRentInfo *)malloc(sizeof(dvdRentInfo));
	
	strcpy(pRent->ISBN, ISBN);
	strcpy(pRent->cusID, cusId);
	pRent->rentDay = rentDay;

	dvdRentList[numOfRentCus] = pRent;
	
	numOfRentCus++;
	*/

	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusId);
	rentList[numOfRentCus].rentDay = rentDay;

	numOfRentCus++;
	
	

	StoreRentListToFile();

}

/*
��� : Ư�� ISBN�� DVD �뿩 �� ���� ��� �Լ�
*/

int R_R_Listt(char * ISBN)
{

	int i = 0;
	int b = 0;

	if (numOfRentCus > 0)
	{

		for (i = 0; i < numOfRentCus; i++)
		{
			if (!strcmp(rentList[i].ISBN, ISBN))
			{
				for (b = 0; b < numOfCustomer; b++)

				{

					if (!strcmp(rentList[i].cusID, cusList[b]->ID))
					{

						ShowRent_Return_list(rentList[i].cusID, cusList[b]);

					}
				}

			}
			
		}
		printf("��ȸ������ ���� �����ϴ�.\n");
		getch();
		return 0;
	}
	
	else
	{
		printf("�뿩 ������ ����� ���� �����ϴ�.");
		getch();
		return 1;
	}

	printf("��ȸ�� �����Ͽ����ϴ�.\n");
	getch();
	return 0;
}


/*
��� : ���� �Ⱓ �ȿ� �̷��� Ư�� ����
DVD �뿩 ���� ���
*/

void Real_Gigan_Search(char * id, unsigned int start, unsigned int end)
{
	unsigned int i = start;
	unsigned int b = end;
	int x = 0;
	

	for (x = 0; x < numOfRentCus; x++)
	{
		if (!strcmp(rentList[x].cusID, id))//id�� ã�Ƽ�
		{
			if ((rentList[x].rentDay >= i)
				&& (rentList[x].rentDay <= b))
				//id�� ����ִ� ���� ��¥�� �˻� �Ⱓ�� ��

				Show_Gigan_Search(rentList[x].cusID);

		}

		else
			printf("�ش��ϴ� �뿩�̷��� �����ϴ�.");
	}


}


/* �뿩 �̷� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�*/


/* �뿩 �̷� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�*/
void LoadRentListFromFile(void)
{
	
	FILE *fp = fopen(RENT_BACKUP_FILE, "rb");
	if (fp == NULL)
		return;

	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
	
	fclose(fp);

}

void StoreRentListToFile(void)
{


	FILE *fp = fopen(RENT_BACKUP_FILE, "wb");
	if (fp == NULL)
		return;

	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);

	fclose(fp);

}
