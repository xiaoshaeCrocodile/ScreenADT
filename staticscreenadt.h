
#ifndef _STATIC_SCREENADT_

#define _STATIC_SCREENADT_

#include <stddef.h>  //size_t 类型
#include <stdbool.h > //bool类型
#include <stdlib.h> //malloc函数、free函数、atoi函数
#include <string.h>  //字符串函数
#include <ctype.h>   //判断数字和字母的函数
#include <math.h>

#define _CONS_ -1                                                               
#define _HEAD_ 0
#define _END_ -1

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

typedef struct DataStorage CDataStorage;  //DataStorage结构体
typedef struct OrderStorage COrderStorage;  //COrderStorage结构体

typedef CDataStorage* DataStorage;   //是一个指针 原DataList
typedef COrderStorage* OrderStorage; //是一个指针 原OrderList

struct ScreenADT {  //原 ScreenADT(一致)

	DataStorage pHDAL;   //DataStorage 的首地址   原 pHeadData
	DataStorage pEDAL;   // 尾地址   原pEndData
	ULength ULDACou;   //长度  原datacount
	OrderStorage pHORL;  //OrderStorage 首地址  原pHeadOrder
	OrderStorage pEORL;  //尾地址   原pEndOrder
	ULength ULORCou;   //长度   原ordercount

};

typedef struct ScreenADT  CScreenADT;  //ScreenADT结构体
typedef CScreenADT* ScreenADT; //是一个指针  原 ScreenADT(一致)

struct newNodeStorage {   //链表新地址长度存储的结构体

	void* newnode; //新增节点地址
	void* newHNode;   //新链表新首地址
	void* newENode;  //链表新尾地址
	ULength newCou;  //链表新长度
};

typedef void* p_newNodeStorage;
typedef struct newNodeStorage  CnewNodeStorage;  //newNodeStorage结构体
typedef CnewNodeStorage* newNodeStorage; //是一个指针  原 newNodeStorage(一致)

static size_t ByteScreenADT = sizeof(CScreenADT);  //ScreenADT结构体的字节数
static size_t ByteDataStorage = sizeof(CDataStorage);  //DataStorage结构体的字节数
static size_t ByteOrderStorage = sizeof(COrderStorage);  //OrderStorage结构体的字节数
static size_t BytenewNodeStorage = sizeof(CnewNodeStorage); //newNodeStorage结构体的字节数

//---------------------------------------------------------------------------------------------------------
//新的函数声明-------screenadt

//--------------------------------初始化部分
//初始化数据类型
//分配内存单元

//初始化ScreenADT 抽象数据类型
ScreenADT IniScreenADT(void);
//为ScreenADT 分配内存单元
ScreenADT FnCreObtScreenADT(void);

//--------------------------------结构内容修改部分

//修改ScreenADT结构体 data首地址 尾地址 长度
void FnRevScreenADT_DHECou(ScreenADT VarScreenADT, DataStorage pHDAL, DataStorage pEDAL, ULength ULDACou);
//修改ScreenADT结构体 order首地址 尾地址 长度
void FnRevScreenADT_OHECou(ScreenADT VarScreenADT, OrderStorage pHDAL, OrderStorage pEDAL, ULength ULORCou);
//返回data首地址
void* FnObtScrA_pHDAL(ScreenADT VarScreenADT);
//返回data尾地址
void* FnObtScrA_pEDAL(ScreenADT VarScreenADT);
//返回data链表长度
void* FnObtScrA_ULDACou(ScreenADT VarScreenADT);
//返回order首地址
void* FnObtScrA_pHORL(ScreenADT VarScreenADT);
//返回order尾地址
void* FnObtScrA_pEORL(ScreenADT VarScreenADT);
//返回order链表长度
void* FnObtScrA_ULORCou(ScreenADT VarScreenADT);

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

//---------------------------------------------------------------新的函数声明
//universal 通用函数

//----------------------------------双向链表部分
//新增、删除、交换、顺序输出

//新增
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou, //给链表新增一个节点，通用
	void* (*FnCreObtNode)(void), void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
//删除
p_newNodeStorage FnFreDelNode(void* HNode, void* ENode, ULength Cou, Length LocCou,//删除双向链表中的一个节点
	void (*FnFreNode)(void* node),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
//交换
p_newNodeStorage FnFreMovNode(void* HNode, void* ENode, ULength Cou, ULength LocCou_one, ULength LocCou_two,
	void* (*FnCreObtNode)(void), void (*FnFreNode_Dir)(void* node),
	void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
//输出
bool FnFreOptNode_Data(void* HNode, void* ENode, ULength Cou, ULength LocCou_Len, ULength* LocCou, bool Com,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node),
	void* (*FnObtNode_Title)(void* node), void* (*FnObtNode_Data)(void* node), bool (*FnOptNode_Data)(char* title, void* data));

//----------------------------------双向链表辅助结构体部分   一
//结构体、结构体内存分配、结构体内容的添加（修改），返回新的节点，新的首地址，新的尾地址，新的长度
//返回数据  结构体分配内存

newNodeStorage FnCreObtnewNodeStorage(void);
//结构体内容添加（修改）
bool FnRevnewNode_Storage(newNodeStorage node, void* newnode, void* newHNode, void* newENode, ULength newCou);
//返回新节点地址
void* FnObtnewNodeStorage_Newnode(newNodeStorage varnewNode);
//返回新首地址
void* FnObtnewNodeStorage_NewHNode(newNodeStorage varnewNode);
//返回新尾地址
void* FnObtnewNodeStorage_NewENode(newNodeStorage varnewNode);
//返回新链表长度
ULength FnObtnewNodeStorage_NewCou(newNodeStorage varnewNode);

//----------------------------------双向链表辅助部分    二
//到达指定位置、向上移动n个节点、向下移动n个节点

//返回链表中第n个节点地址
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node));
//链表向上n个节点的地址
void* FnMovObtCouNode_Previous(void* node, ULength LocCou, void* (*FnObtNode_Previous)(void* node));
//链表向下n个节点的地址
void* FnMovObtCouNode_Next(void* Node, ULength LocCou, void* (*FnObtNode_Next)(void* Node));

//----------------------------------字符串部分
//将字符串1从n到n+m拷贝到字符串2、生成字符串副本、删除字符串副本

////将字符串1从n到n+m拷贝到字符串2
char* FnCreFinObtCopy(char* str, int n, int m);
//生成字符串副本
char* FnCreObtStrCopy(char* str);
//删除字符串副本
void FnDelStrCopy(char* str);

//----------------------------------其他辅助部分
//判断标题、判断字符串是否为纯数字、判断SLoc是标题还是位置、判断SLoc是否正确

//判断标题
bool FnSurObtString_Title(char* title);
//判断字符串是否为纯数字
bool FnSurObtString_LocCou(char* SLoc);
//是标题还是位置
Length FnSurObtString_TLoc(char* SLoc);
//判断SLoc是否正确
bool FnSurObtString_SLoc(char* SLoc);

//----------------------------------------------------新的函数声明
//datastorage

//--------------------------------------data结构体初始化相关操作
//分配内存、直接释放内存、完全释放内存、获得标题，数据，上一个节点，下一个节点

//为DataStorage分配新的内存单元
DataStorage FnCreObtDataStorage(void);
//释放DataStorage的内存单元
void FnFreDataStorage(DataStorage node);
//释放DataStorage的内存单元 和 title标题
void FnFreDataStorage_TAD(DataStorage node);
//获取当前节点的title标题
char* FnObtDataStorage_Title(DataStorage node);
//获取当前节点的data数据
void* FnObtDataStorage_Data(DataStorage node);
//获取当前节点的previous的上一个节点
DataStorage FnObtDataStorage_Previous(DataStorage node);
//获取当前节点的next的下一个节点
DataStorage FnObtDataStorage_Next(DataStorage node);

//--------------------------------------data结构体内容的修改
//标题和data、上一个节点和下一个节点、上一个节点、下一个节点

//修改Data结构体 标题和data的地址
void FnRevDataStorage_TAD(DataStorage node, char* title, void* data);
//修改Data结构体 上一节点，和下一个节点的地址
void FnRevDataStorage_Rne(DataStorage node, DataStorage previous, DataStorage next);
//修改Data结构体 上一节点的地址
void FnRevDataStorage_Previous(DataStorage node, DataStorage previous);
//修改Data结构体 下一个节点的地址
void FnRevDataStorage_Next(DataStorage node, DataStorage next);


//--------------------------------------data双向链表的操作
//新增、删除、交换、顺序输出

//给data链表新增一个节点
p_newNodeStorage FnCreAddDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title, void* data, Length LocCou);
//给data链表删除一个节点
p_newNodeStorage FnFreDelDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, Length LocCou);
//交换data链表中两个节点的位置
p_newNodeStorage FnFreMovDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou_one, ULength LocCou_two);
//data顺序输出
bool FnFreOptDataStorage_Data(DataStorage* HNode, DataStorage* ENode, ULength Cou, char* order,
	bool (*FnOptNode_Data)(char* title, void* data));


//--------------------------------------data双向链表的数据读取
//标题读取位置，标题读取数据，位置读取标题，位置读取数据

//通过标题读取位置
Length FnFinObtDataStorage_TLCou(DataStorage pHDAL, ULength Cou, char* title);
//通过标题读取数据
void* FnFinObtDataStorage_TDATA(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title);
//通过位置读取数据
void* FnFinObtDataStorage_LCouD(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou);
//通过位置读取标题
char* FnFinObtDataStorage_LCouT(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou);

//--------------------------------------data链表的SLoc解释

//DataStorage解释SLoc,将标题转化为位置，将位置字符，转化为数字位置,正确返回位置，错误返回-1
Length FnFinEvpObtDataStorage_SLoc(DataStorage pHDAL, ULength Cou, char* SLoc);

//----------------------------------------------------新的函数声明
//orderstorage

//--------------------------------------order结构体初始化相关操作
//分配内存、直接释放内存、完全释放内存、获得标题，数据，上一个节点，下一个节点

//为OrderStorage分配新的内存单元
OrderStorage FnCreObtOrderStorage(void);
//释放OrderStorage的内存单元
void FnFreOrderStorage(OrderStorage node);
//释放OrderStorage的内存单元 和 title标题 和 order顺序
void FnFreOrderStorage_TADOR(OrderStorage node);
//获取当前节点的title标题
char* FnObtOrderStorage_Title(OrderStorage node);
//获取当前节点的order顺序
char* FnObtOrderStorage_Order(OrderStorage node);
//获取当前节点的previous的上一个节点
OrderStorage FnObtOrderStorage_Previous(OrderStorage node);
//获取当前节点的next的下一个节点
OrderStorage FnObtOrderStorage_Next(OrderStorage node);

//--------------------------------------order结构体内容的修改
//标题和data、上一个节点和下一个节点、上一个节点、下一个节点

//修改OrderStorage结构体 标题和order顺序的地址
void FnRevOrderStorage_TAO(OrderStorage node, char* title, char* order);
//修改OrderStorage结构体 上一节点，和下一个节点的地址
void FnRevOrderStorage_Rne(OrderStorage node, OrderStorage previous, OrderStorage next);
//修改OrderStorage结构体 上一节点的地址
void FnRevOrderStorage_Previous(OrderStorage node, OrderStorage previous);
//修改OrderStorage结构体 下一个节点的地址
void FnRevOrderStorage_Next(OrderStorage node, OrderStorage next);

//--------------------------------------order双向链表的操作
//新增、删除、交换

//新增
p_newNodeStorage FnCreAddOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title, char* order, Length LocCou);
//删除
p_newNodeStorage FnFreDelOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, Length LocCou);
//交换
p_newNodeStorage FnFreMovOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou_one, ULength LocCou_two);


//--------------------------------------order双向链表的数据读取
//标题读取位置，标题读取数据，位置读取标题，位置读取数据

//通过标题读取位置
Length FnFinObtOrderStorage_TLCou(OrderStorage pHORL, ULength Cou, char* title);
//通过标题读取顺序
char* FnFinObtOrderStorage_TORDER(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title);
//通过位置读取标题
char* FnFinObtOrderStorage_LCouT(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou);
//通过位置读取顺序
char* FnFinObtOrderStorage_LCouO(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou);

//--------------------------------------order链表的SLoc解释

//OrderStorage解释SLoc,将标题转化为位置，将位置字符，转化为数字位置,正确返回位置，错误返回-1
Length FnFinEvpObtOrderStorage_SLoc(OrderStorage pHORL, ULength Cou, char* SLoc);

//--------------------------------------order链表的顺序判断和解释

//判断order顺序是否正确
bool FnExpSurOrderStorage_Order(char* order);
//解释顺序,将位置装入数组中，
ULength* FnExpFinObtOrderStorage_Order(char* order, OrderStorage pHORL, ULength Cou);

#endif // !
