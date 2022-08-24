#ifndef _STATIC_SCREENADT_

#define _STATIC_SCREENADT_

#include <stdbool.h > //bool����


typedef unsigned long long int ULength;  //�޷��ų�������
typedef long long int Length;   //�з��ų�������



struct DataStorage {  //ԭ DataList

	char* title;
	void* data;
	struct DataStorage* previous;
	struct DataStorage* next;

};

struct OrderStorage {  //ԭ OrderList

	char* title;
	char* order;
	struct OrderStorage* previous;
	struct OrderStorage* next;

};


typedef struct DataStorage* DataStorage;   //��һ��ָ�� ԭDataList
typedef struct OrderStorage* OrderStorage; //��һ��ָ�� ԭOrderList

struct ScreenADT {  //ԭ ScreenADT(һ��)

	DataStorage pHDAL;   //DataStorage ���׵�ַ   ԭ pHeadData
	DataStorage pEDAL;   // β��ַ   ԭpEndData
	ULength ULDACou;   //����  ԭdatacount
	OrderStorage pHORL;  //OrderStorage �׵�ַ  ԭpHeadOrder
	OrderStorage pEORL;  //β��ַ   ԭpEndOrder
	ULength ULORCou;   //����   ԭordercount

};

typedef struct ScreenADT* ScreenADT; //��һ��ָ��  ԭ ScreenADT(һ��)

//--------------------------------��ʼ������
//��ʼ����������
//�����ڴ浥Ԫ

//��ʼ��ScreenADT ������������
ScreenADT IniScreenADT(void);

//--------------------------------����������������������Ĳ���
//data���ӣ�ɾ����������SLoc��ñ��⣬���ݣ����������˳�򣬰���˳�����

//data����
bool ScreenAddData(ScreenADT VarScreenADT, char* title, void* data, char* SLoc);
//dataɾ��
bool ScreenDelData(ScreenADT VarScreenADT, char* SLoc);
//data����
bool ScreenMovData(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two);
//data���
bool ScreenOptData(ScreenADT VarScreenADT, char* OrderSLoc, bool (*FnOptNode_Data)(char* title, void* data));

//data SLocȡ����
char* ScreenObtData_Tile(ScreenADT VarScreenADT, char* SLoc);
//data SLocȡ����
void* ScreenObtData_Data(ScreenADT VarScreenADT, char* SLoc);
//data SLocȡλ��
Length* ScreenObtData_LocCou(ScreenADT VarScreenADT, char* SLoc);

//order����
bool ScreenAddOrder(ScreenADT VarScreenADT, char* title, void* order, char* SLoc);
//orderɾ��
bool ScreenDelOrder(ScreenADT VarScreenADT, char* SLoc);
//order����
bool ScreenMovOrder(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two);

//order SLocȡ����
char* ScreenObtOrder_Tile(ScreenADT VarScreenADT, char* SLoc);
//order SLocȡ˳��
void* ScreenObtOrder_Order(ScreenADT VarScreenADT, char* SLoc);
//order SLocȡλ��
Length* ScreenObtOrder_LocCou(ScreenADT VarScreenADT, char* SLoc);


#endif