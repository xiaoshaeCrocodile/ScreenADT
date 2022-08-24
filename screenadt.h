#ifndef _STATIC_SCREENADT_

#define _STATIC_SCREENADT_

#include <stdbool.h > //bool类型


typedef unsigned long long int ULength;  //无符号常常整型
typedef long long int Length;   //有符号长长整型



struct DataStorage {  //原 DataList

	char* title;
	void* data;
	struct DataStorage* previous;
	struct DataStorage* next;

};

struct OrderStorage {  //原 OrderList

	char* title;
	char* order;
	struct OrderStorage* previous;
	struct OrderStorage* next;

};


typedef struct DataStorage* DataStorage;   //是一个指针 原DataList
typedef struct OrderStorage* OrderStorage; //是一个指针 原OrderList

struct ScreenADT {  //原 ScreenADT(一致)

	DataStorage pHDAL;   //DataStorage 的首地址   原 pHeadData
	DataStorage pEDAL;   // 尾地址   原pEndData
	ULength ULDACou;   //长度  原datacount
	OrderStorage pHORL;  //OrderStorage 首地址  原pHeadOrder
	OrderStorage pEORL;  //尾地址   原pEndOrder
	ULength ULORCou;   //长度   原ordercount

};

typedef struct ScreenADT* ScreenADT; //是一个指针  原 ScreenADT(一致)

//--------------------------------初始化部分
//初始化数据类型
//分配内存单元

//初始化ScreenADT 抽象数据类型
ScreenADT IniScreenADT(void);

//--------------------------------调用其他函数，完成其他的部分
//data增加，删除，交换，SLoc获得标题，数据，输出，传入顺序，按照顺序输出

//data增加
bool ScreenAddData(ScreenADT VarScreenADT, char* title, void* data, char* SLoc);
//data删除
bool ScreenDelData(ScreenADT VarScreenADT, char* SLoc);
//data交换
bool ScreenMovData(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two);
//data输出
bool ScreenOptData(ScreenADT VarScreenADT, char* OrderSLoc, bool (*FnOptNode_Data)(char* title, void* data));

//data SLoc取标题
char* ScreenObtData_Tile(ScreenADT VarScreenADT, char* SLoc);
//data SLoc取数据
void* ScreenObtData_Data(ScreenADT VarScreenADT, char* SLoc);
//data SLoc取位置
Length* ScreenObtData_LocCou(ScreenADT VarScreenADT, char* SLoc);

//order增加
bool ScreenAddOrder(ScreenADT VarScreenADT, char* title, void* order, char* SLoc);
//order删除
bool ScreenDelOrder(ScreenADT VarScreenADT, char* SLoc);
//order交换
bool ScreenMovOrder(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two);

//order SLoc取标题
char* ScreenObtOrder_Tile(ScreenADT VarScreenADT, char* SLoc);
//order SLoc取顺序
void* ScreenObtOrder_Order(ScreenADT VarScreenADT, char* SLoc);
//order SLoc取位置
Length* ScreenObtOrder_LocCou(ScreenADT VarScreenADT, char* SLoc);


#endif