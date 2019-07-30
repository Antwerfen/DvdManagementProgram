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
기능 : DVD 대여 정보를 저장하는 함수
반환 : void
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
기능 : 특정 ISBN의 DVD 대여 고객 정보 출력 함수
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
		printf("조회내역은 위와 같습니다.\n");
		getch();
		return 0;
	}
	
	else
	{
		printf("대여 절차가 진행된 적이 없습니다.");
		getch();
		return 1;
	}

	printf("조회에 실패하였습니다.\n");
	getch();
	return 0;
}


/*
기능 : 일정 기간 안에 이뤄진 특정 고객의
DVD 대여 정보 출력
*/

void Real_Gigan_Search(char * id, unsigned int start, unsigned int end)
{
	unsigned int i = start;
	unsigned int b = end;
	int x = 0;
	

	for (x = 0; x < numOfRentCus; x++)
	{
		if (!strcmp(rentList[x].cusID, id))//id를 찾아서
		{
			if ((rentList[x].rentDay >= i)
				&& (rentList[x].rentDay <= b))
				//id가 들어있는 곳의 날짜를 검색 기간과 비교

				Show_Gigan_Search(rentList[x].cusID);

		}

		else
			printf("해당하는 대여이력이 없습니다.");
	}


}


/* 대여 이력 리스트를 파일에 백업하는 함수*/


/* 대여 이력 리스트를 파일로부터 복구하는 함수*/
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
