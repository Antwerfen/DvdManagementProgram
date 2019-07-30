#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "dvdInfo.h"
#include "cusInfo.h"

// 향후 추가적인 검색기능의 확장성을 위해서
// 검색조건의 기준이 되는 키들을
// 한 곳에 구조체의 멤버로 관리함.
// 그러면, 새로운 검색조건의 키가 추가가
// 되더라도 기존의 프로그램의 수정없이
// 새로운 검색 기능의 구현에 집중할 수 있음.

typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;
} dvdRentInfo;

#endif // !__RENTINFO_H__
