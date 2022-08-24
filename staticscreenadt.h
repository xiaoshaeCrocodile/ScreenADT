
#ifndef _STATIC_SCREENADT_

#define _STATIC_SCREENADT_

#include <stddef.h>  //size_t ����
#include <stdbool.h > //bool����
#include <stdlib.h> //malloc������free������atoi����
#include <string.h>  //�ַ�������
#include <ctype.h>   //�ж����ֺ���ĸ�ĺ���
#include <math.h>

#define _CONS_ -1                                                               
#define _HEAD_ 0
#define _END_ -1

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

typedef struct DataStorage CDataStorage;  //DataStorage�ṹ��
typedef struct OrderStorage COrderStorage;  //COrderStorage�ṹ��

typedef CDataStorage* DataStorage;   //��һ��ָ�� ԭDataList
typedef COrderStorage* OrderStorage; //��һ��ָ�� ԭOrderList

struct ScreenADT {  //ԭ ScreenADT(һ��)

	DataStorage pHDAL;   //DataStorage ���׵�ַ   ԭ pHeadData
	DataStorage pEDAL;   // β��ַ   ԭpEndData
	ULength ULDACou;   //����  ԭdatacount
	OrderStorage pHORL;  //OrderStorage �׵�ַ  ԭpHeadOrder
	OrderStorage pEORL;  //β��ַ   ԭpEndOrder
	ULength ULORCou;   //����   ԭordercount

};

typedef struct ScreenADT  CScreenADT;  //ScreenADT�ṹ��
typedef CScreenADT* ScreenADT; //��һ��ָ��  ԭ ScreenADT(һ��)

struct newNodeStorage {   //�����µ�ַ���ȴ洢�Ľṹ��

	void* newnode; //�����ڵ��ַ
	void* newHNode;   //���������׵�ַ
	void* newENode;  //������β��ַ
	ULength newCou;  //�����³���
};

typedef void* p_newNodeStorage;
typedef struct newNodeStorage  CnewNodeStorage;  //newNodeStorage�ṹ��
typedef CnewNodeStorage* newNodeStorage; //��һ��ָ��  ԭ newNodeStorage(һ��)

static size_t ByteScreenADT = sizeof(CScreenADT);  //ScreenADT�ṹ����ֽ���
static size_t ByteDataStorage = sizeof(CDataStorage);  //DataStorage�ṹ����ֽ���
static size_t ByteOrderStorage = sizeof(COrderStorage);  //OrderStorage�ṹ����ֽ���
static size_t BytenewNodeStorage = sizeof(CnewNodeStorage); //newNodeStorage�ṹ����ֽ���

//---------------------------------------------------------------------------------------------------------
//�µĺ�������-------screenadt

//--------------------------------��ʼ������
//��ʼ����������
//�����ڴ浥Ԫ

//��ʼ��ScreenADT ������������
ScreenADT IniScreenADT(void);
//ΪScreenADT �����ڴ浥Ԫ
ScreenADT FnCreObtScreenADT(void);

//--------------------------------�ṹ�����޸Ĳ���

//�޸�ScreenADT�ṹ�� data�׵�ַ β��ַ ����
void FnRevScreenADT_DHECou(ScreenADT VarScreenADT, DataStorage pHDAL, DataStorage pEDAL, ULength ULDACou);
//�޸�ScreenADT�ṹ�� order�׵�ַ β��ַ ����
void FnRevScreenADT_OHECou(ScreenADT VarScreenADT, OrderStorage pHDAL, OrderStorage pEDAL, ULength ULORCou);
//����data�׵�ַ
void* FnObtScrA_pHDAL(ScreenADT VarScreenADT);
//����dataβ��ַ
void* FnObtScrA_pEDAL(ScreenADT VarScreenADT);
//����data������
void* FnObtScrA_ULDACou(ScreenADT VarScreenADT);
//����order�׵�ַ
void* FnObtScrA_pHORL(ScreenADT VarScreenADT);
//����orderβ��ַ
void* FnObtScrA_pEORL(ScreenADT VarScreenADT);
//����order������
void* FnObtScrA_ULORCou(ScreenADT VarScreenADT);

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

//---------------------------------------------------------------�µĺ�������
//universal ͨ�ú���

//----------------------------------˫��������
//������ɾ����������˳�����

//����
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou, //����������һ���ڵ㣬ͨ��
	void* (*FnCreObtNode)(void), void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
//ɾ��
p_newNodeStorage FnFreDelNode(void* HNode, void* ENode, ULength Cou, Length LocCou,//ɾ��˫�������е�һ���ڵ�
	void (*FnFreNode)(void* node),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
//����
p_newNodeStorage FnFreMovNode(void* HNode, void* ENode, ULength Cou, ULength LocCou_one, ULength LocCou_two,
	void* (*FnCreObtNode)(void), void (*FnFreNode_Dir)(void* node),
	void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
//���
bool FnFreOptNode_Data(void* HNode, void* ENode, ULength Cou, ULength LocCou_Len, ULength* LocCou, bool Com,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node),
	void* (*FnObtNode_Title)(void* node), void* (*FnObtNode_Data)(void* node), bool (*FnOptNode_Data)(char* title, void* data));

//----------------------------------˫���������ṹ�岿��   һ
//�ṹ�塢�ṹ���ڴ���䡢�ṹ�����ݵ���ӣ��޸ģ��������µĽڵ㣬�µ��׵�ַ���µ�β��ַ���µĳ���
//��������  �ṹ������ڴ�

newNodeStorage FnCreObtnewNodeStorage(void);
//�ṹ��������ӣ��޸ģ�
bool FnRevnewNode_Storage(newNodeStorage node, void* newnode, void* newHNode, void* newENode, ULength newCou);
//�����½ڵ��ַ
void* FnObtnewNodeStorage_Newnode(newNodeStorage varnewNode);
//�������׵�ַ
void* FnObtnewNodeStorage_NewHNode(newNodeStorage varnewNode);
//������β��ַ
void* FnObtnewNodeStorage_NewENode(newNodeStorage varnewNode);
//������������
ULength FnObtnewNodeStorage_NewCou(newNodeStorage varnewNode);

//----------------------------------˫������������    ��
//����ָ��λ�á������ƶ�n���ڵ㡢�����ƶ�n���ڵ�

//���������е�n���ڵ��ַ
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node));
//��������n���ڵ�ĵ�ַ
void* FnMovObtCouNode_Previous(void* node, ULength LocCou, void* (*FnObtNode_Previous)(void* node));
//��������n���ڵ�ĵ�ַ
void* FnMovObtCouNode_Next(void* Node, ULength LocCou, void* (*FnObtNode_Next)(void* Node));

//----------------------------------�ַ�������
//���ַ���1��n��n+m�������ַ���2�������ַ���������ɾ���ַ�������

////���ַ���1��n��n+m�������ַ���2
char* FnCreFinObtCopy(char* str, int n, int m);
//�����ַ�������
char* FnCreObtStrCopy(char* str);
//ɾ���ַ�������
void FnDelStrCopy(char* str);

//----------------------------------������������
//�жϱ��⡢�ж��ַ����Ƿ�Ϊ�����֡��ж�SLoc�Ǳ��⻹��λ�á��ж�SLoc�Ƿ���ȷ

//�жϱ���
bool FnSurObtString_Title(char* title);
//�ж��ַ����Ƿ�Ϊ������
bool FnSurObtString_LocCou(char* SLoc);
//�Ǳ��⻹��λ��
Length FnSurObtString_TLoc(char* SLoc);
//�ж�SLoc�Ƿ���ȷ
bool FnSurObtString_SLoc(char* SLoc);

//----------------------------------------------------�µĺ�������
//datastorage

//--------------------------------------data�ṹ���ʼ����ز���
//�����ڴ桢ֱ���ͷ��ڴ桢��ȫ�ͷ��ڴ桢��ñ��⣬���ݣ���һ���ڵ㣬��һ���ڵ�

//ΪDataStorage�����µ��ڴ浥Ԫ
DataStorage FnCreObtDataStorage(void);
//�ͷ�DataStorage���ڴ浥Ԫ
void FnFreDataStorage(DataStorage node);
//�ͷ�DataStorage���ڴ浥Ԫ �� title����
void FnFreDataStorage_TAD(DataStorage node);
//��ȡ��ǰ�ڵ��title����
char* FnObtDataStorage_Title(DataStorage node);
//��ȡ��ǰ�ڵ��data����
void* FnObtDataStorage_Data(DataStorage node);
//��ȡ��ǰ�ڵ��previous����һ���ڵ�
DataStorage FnObtDataStorage_Previous(DataStorage node);
//��ȡ��ǰ�ڵ��next����һ���ڵ�
DataStorage FnObtDataStorage_Next(DataStorage node);

//--------------------------------------data�ṹ�����ݵ��޸�
//�����data����һ���ڵ����һ���ڵ㡢��һ���ڵ㡢��һ���ڵ�

//�޸�Data�ṹ�� �����data�ĵ�ַ
void FnRevDataStorage_TAD(DataStorage node, char* title, void* data);
//�޸�Data�ṹ�� ��һ�ڵ㣬����һ���ڵ�ĵ�ַ
void FnRevDataStorage_Rne(DataStorage node, DataStorage previous, DataStorage next);
//�޸�Data�ṹ�� ��һ�ڵ�ĵ�ַ
void FnRevDataStorage_Previous(DataStorage node, DataStorage previous);
//�޸�Data�ṹ�� ��һ���ڵ�ĵ�ַ
void FnRevDataStorage_Next(DataStorage node, DataStorage next);


//--------------------------------------data˫������Ĳ���
//������ɾ����������˳�����

//��data��������һ���ڵ�
p_newNodeStorage FnCreAddDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title, void* data, Length LocCou);
//��data����ɾ��һ���ڵ�
p_newNodeStorage FnFreDelDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, Length LocCou);
//����data�����������ڵ��λ��
p_newNodeStorage FnFreMovDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou_one, ULength LocCou_two);
//data˳�����
bool FnFreOptDataStorage_Data(DataStorage* HNode, DataStorage* ENode, ULength Cou, char* order,
	bool (*FnOptNode_Data)(char* title, void* data));


//--------------------------------------data˫����������ݶ�ȡ
//�����ȡλ�ã������ȡ���ݣ�λ�ö�ȡ���⣬λ�ö�ȡ����

//ͨ�������ȡλ��
Length FnFinObtDataStorage_TLCou(DataStorage pHDAL, ULength Cou, char* title);
//ͨ�������ȡ����
void* FnFinObtDataStorage_TDATA(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title);
//ͨ��λ�ö�ȡ����
void* FnFinObtDataStorage_LCouD(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou);
//ͨ��λ�ö�ȡ����
char* FnFinObtDataStorage_LCouT(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou);

//--------------------------------------data�����SLoc����

//DataStorage����SLoc,������ת��Ϊλ�ã���λ���ַ���ת��Ϊ����λ��,��ȷ����λ�ã����󷵻�-1
Length FnFinEvpObtDataStorage_SLoc(DataStorage pHDAL, ULength Cou, char* SLoc);

//----------------------------------------------------�µĺ�������
//orderstorage

//--------------------------------------order�ṹ���ʼ����ز���
//�����ڴ桢ֱ���ͷ��ڴ桢��ȫ�ͷ��ڴ桢��ñ��⣬���ݣ���һ���ڵ㣬��һ���ڵ�

//ΪOrderStorage�����µ��ڴ浥Ԫ
OrderStorage FnCreObtOrderStorage(void);
//�ͷ�OrderStorage���ڴ浥Ԫ
void FnFreOrderStorage(OrderStorage node);
//�ͷ�OrderStorage���ڴ浥Ԫ �� title���� �� order˳��
void FnFreOrderStorage_TADOR(OrderStorage node);
//��ȡ��ǰ�ڵ��title����
char* FnObtOrderStorage_Title(OrderStorage node);
//��ȡ��ǰ�ڵ��order˳��
char* FnObtOrderStorage_Order(OrderStorage node);
//��ȡ��ǰ�ڵ��previous����һ���ڵ�
OrderStorage FnObtOrderStorage_Previous(OrderStorage node);
//��ȡ��ǰ�ڵ��next����һ���ڵ�
OrderStorage FnObtOrderStorage_Next(OrderStorage node);

//--------------------------------------order�ṹ�����ݵ��޸�
//�����data����һ���ڵ����һ���ڵ㡢��һ���ڵ㡢��һ���ڵ�

//�޸�OrderStorage�ṹ�� �����order˳��ĵ�ַ
void FnRevOrderStorage_TAO(OrderStorage node, char* title, char* order);
//�޸�OrderStorage�ṹ�� ��һ�ڵ㣬����һ���ڵ�ĵ�ַ
void FnRevOrderStorage_Rne(OrderStorage node, OrderStorage previous, OrderStorage next);
//�޸�OrderStorage�ṹ�� ��һ�ڵ�ĵ�ַ
void FnRevOrderStorage_Previous(OrderStorage node, OrderStorage previous);
//�޸�OrderStorage�ṹ�� ��һ���ڵ�ĵ�ַ
void FnRevOrderStorage_Next(OrderStorage node, OrderStorage next);

//--------------------------------------order˫������Ĳ���
//������ɾ��������

//����
p_newNodeStorage FnCreAddOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title, char* order, Length LocCou);
//ɾ��
p_newNodeStorage FnFreDelOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, Length LocCou);
//����
p_newNodeStorage FnFreMovOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou_one, ULength LocCou_two);


//--------------------------------------order˫����������ݶ�ȡ
//�����ȡλ�ã������ȡ���ݣ�λ�ö�ȡ���⣬λ�ö�ȡ����

//ͨ�������ȡλ��
Length FnFinObtOrderStorage_TLCou(OrderStorage pHORL, ULength Cou, char* title);
//ͨ�������ȡ˳��
char* FnFinObtOrderStorage_TORDER(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title);
//ͨ��λ�ö�ȡ����
char* FnFinObtOrderStorage_LCouT(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou);
//ͨ��λ�ö�ȡ˳��
char* FnFinObtOrderStorage_LCouO(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou);

//--------------------------------------order�����SLoc����

//OrderStorage����SLoc,������ת��Ϊλ�ã���λ���ַ���ת��Ϊ����λ��,��ȷ����λ�ã����󷵻�-1
Length FnFinEvpObtOrderStorage_SLoc(OrderStorage pHORL, ULength Cou, char* SLoc);

//--------------------------------------order�����˳���жϺͽ���

//�ж�order˳���Ƿ���ȷ
bool FnExpSurOrderStorage_Order(char* order);
//����˳��,��λ��װ�������У�
ULength* FnExpFinObtOrderStorage_Order(char* order, OrderStorage pHORL, ULength Cou);

#endif // !
