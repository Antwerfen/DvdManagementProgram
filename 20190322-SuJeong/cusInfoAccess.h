
#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsregistID(char * ID);

/* �� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�*/
void StoreCusListToFile(void);

/* �� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�*/
void LoadCusListFromFile(void);

#endif
