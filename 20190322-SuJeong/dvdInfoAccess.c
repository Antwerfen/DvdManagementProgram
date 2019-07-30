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
	pDVD->rentState = 1; // 1 = �뿩����
	


	dvdList[numOfDvd++] = pDVD;

	//DVD�� �ű� ��ϵ� ���, ���Ͽ� ���.
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

int IsRegistISBN(char * ISBN)//��� 1, �̵�� 0
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;
	else
		return 1;

}



dvdInfo* StateGumsa(char * ISBN)//��������
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

void StateInput(char * ISBN)//�뿩
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
	//���� ��ȭ�� �� ���� �������ְ� ���̼� �����ϴ°� �ҷ��� ������ ���� �ǰ�?

}

void State_state(char * ISBN)//�ݳ�
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


/* DVD ����Ʈ�� ���Ͽ� ����ϴ� �Լ�*/
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

/* DVD ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�*/
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







