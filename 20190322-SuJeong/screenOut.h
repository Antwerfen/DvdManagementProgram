#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo * pCus);
void ShowDVDInfo(dvdInfo * pDVD);
void ShowGenre(int gen);
void ShowRent_Return_list(dvdRentInfo *dvd, cusInfo *cus);
void Show_Gigan_Search(dvdRentInfo *dvd);

#endif


