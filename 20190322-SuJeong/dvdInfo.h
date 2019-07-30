#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN   30
#define TITLE_LEN  30
#define RENT_LEN  100

enum { ACTION = 1, COMIC, SF, ROMANTIC };    // 장르 정보
enum { RENTED, RETURNED };    // 대여 상태를 나타내는 상수!


//DVD 중심의 데이터 모델임으로
//고객 기준의 조회가 힘들다.
//그래서, 처음부터 고개과 DVD 모두를 고려한
//이력 데이터 모델이 필요.
typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	int rentState;
	
}dvdInfo;

#endif
