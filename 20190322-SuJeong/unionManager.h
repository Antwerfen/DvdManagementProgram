#ifndef __UNIONMANAGER_H__
#define __UNIONMANAGER_H__



#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"


//==================�� �κ�

void RegisterCustomer(void);
void SearchCusInfo(void);



//====================dvd�����κ�
void RegistDVD(void);
void SearchDVDInfo(void);
void RentHanda(void);
void BannabHanda(void);
void R_R_List(void);
void Gigan_Search(void);


void initData(void);

#endif