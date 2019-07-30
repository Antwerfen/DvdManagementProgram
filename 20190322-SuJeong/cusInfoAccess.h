
#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsregistID(char * ID);

/* 고객 리스트를 파일에 백업하는 함수*/
void StoreCusListToFile(void);

/* 고객 리스트를 파일로부터 복구하는 함수*/
void LoadCusListFromFile(void);

#endif
