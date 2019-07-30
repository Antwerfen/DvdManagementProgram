#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDVDPtrByISBN(char * ISBN);
int IsRegistISBN(char * ISBN);
dvdInfo* StateGumsa(char * ISBN);
void StateInput(char * ISBN);
void State_state(char * ISBN);

/* DVD ����Ʈ�� ���Ͽ� ����ϴ� �Լ�*/
void StoreDVDListToFile(void);

/* DVD ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�*/
void LoadDVDListFromFile(void);



#endif