#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

void AddRentInfo(char * ISBN, char * cusId, unsigned int rentDay);
int R_R_Listt(char * ISBN);
void Real_Gigan_Search(char * id, unsigned int start, unsigned int end);

/* �뿩 �̷� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�*/
void StoreRentListToFile(void);

/* �뿩 �̷� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�*/
void LoadRentListFromFile(void);


#endif // !__RENTACCESS_H__
