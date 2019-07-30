#include "common.h"
#include "unionManager.h"
#include "screenOut.h"


enum { CUS_REGIST = 1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH,
	DVD_RENT, DVD_RETURN, DVD_R_R_LIST, DVD_GIGAN, QUIT };

int main(void)
{
	int intputMenu = 0;
	initData();

	while (1)
	{
		ShowMenu();
		scanf("%d", &intputMenu);
		getchar();

		switch (intputMenu)
		{
		case CUS_REGIST:
			RegisterCustomer();
			break;

		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;

		case DVD_RENT:
			RentHanda();
			break;

		case DVD_RETURN:
			BannabHanda();
			break;

		case DVD_R_R_LIST:
			R_R_List();
			break;

		case DVD_GIGAN:
			Gigan_Search();
			break;

		}

		if (intputMenu == QUIT)
		{
			
			puts("이용해주셔서 감사합니다.");
			break;
		}


	}
	return 0;
}