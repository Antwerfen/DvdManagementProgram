#include "common.h"
#include "dvdInfo.h"
#include "screenOut.h"
#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "cusInfo.h"

#define MAX_DVD 100
#define DVD_BACKUP_FILE "dvdInfo.dat"

int numOfDvd = 0;
dvdInfo *dvdList[MAX_DVD];
int numOfRDvd = 0;
//dvdRentInfo *dvdRentList[MAX_DVD];
extern cusInfo * cusList[];
extern int numOfCustomer;

int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if (numOfDvd >= MAX_DVD)
		return 0;

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;
	pDVD->rentState = 1; // 1 = 대여가능
	


	dvdList[numOfDvd++] = pDVD;

	//DVD가 신규 등록될 경우, 파일에 백업.
	StoreDVDListToFile();

	return numOfDvd;
}

dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
	int i;

	for (i = 0; i < numOfDvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
			return dvdList[i];
	}

	return (dvdInfo *)0;

}

int IsRegistISBN(char * ISBN)//등록 1, 미등록 0
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;
	else
		return 1;

}



dvdInfo* StateGumsa(char * ISBN)//상태조사
{
	int i;

	for (i = 0; i < numOfDvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN)) {

			if (dvdList[i]->rentState == RETURNED)
				return dvdList[i];
		}
	}

	return (dvdInfo *)0;
}

void StateInput(char * ISBN)//대여
{
	int i;


	for (i = 0; i < numOfDvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
		{
			dvdList[i]->rentState = RENTED;
			
			StoreDVDListToFile();
			
		}
	}
	//상태 변화가 두 개로 나뉘어있고 둘이서 저장하는걸 불러서 에러가 나는 건가?

}

void State_state(char * ISBN)//반납
{
	int i;

	for (i = 0; i < numOfDvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
			if (dvdList[i]->rentState == RENTED)
			{
				dvdList[i]->rentState = RETURNED;
				StoreDVDListToFile();
			}
	}

}


/* DVD 리스트를 파일에 백업하는 함수*/
void StoreDVDListToFile(void)
{
	int i;

	FILE *fp = fopen(DVD_BACKUP_FILE, "wb");
	if (fp == NULL)
		return;

	fwrite(&numOfDvd, sizeof(int), 1, fp);

	for (i = 0; i < numOfDvd; i++)
	{
		fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);
	}
	fclose(fp);
}

/* DVD 리스트를 파일로부터 복구하는 함수*/
void LoadDVDListFromFile(void)
{
	int i;
	FILE *fp = fopen(DVD_BACKUP_FILE, "rb");
	if (fp == NULL)
		return;

	fread(&numOfDvd, sizeof(int), 1, fp);

	for (i = 0; i < numOfDvd; i++)
	{
		dvdList[i] = (dvdInfo *)malloc(sizeof(dvdInfo));
		fread(dvdList[i], sizeof(dvdInfo), 1, fp);
	}
	fclose(fp);
}







