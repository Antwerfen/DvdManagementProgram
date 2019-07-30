#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

void AddRentInfo(char * ISBN, char * cusId, unsigned int rentDay);
int R_R_Listt(char * ISBN);
void Real_Gigan_Search(char * id, unsigned int start, unsigned int end);

/* 대여 이력 리스트를 파일에 백업하는 함수*/
void StoreRentListToFile(void);

/* 대여 이력 리스트를 파일로부터 복구하는 함수*/
void LoadRentListFromFile(void);


#endif // !__RENTACCESS_H__
