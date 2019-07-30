#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDVDPtrByISBN(char * ISBN);
int IsRegistISBN(char * ISBN);
dvdInfo* StateGumsa(char * ISBN);
void StateInput(char * ISBN);
void State_state(char * ISBN);

/* DVD 리스트를 파일에 백업하는 함수*/
void StoreDVDListToFile(void);

/* DVD 리스트를 파일로부터 복구하는 함수*/
void LoadDVDListFromFile(void);



#endif