					
#include "staticscreenadt.h"

/*

struct ScreenADT {  //ԭ ScreenADT(һ��)

	DataStorage pHDAL;   //DataStorage ���׵�ַ   ԭ pHeadData
	DataStorage pEDAL;   // β��ַ   ԭpEndData
	ULength ULDACou;   //����  ԭdatacount
	OrderStorage pHORL;  //OrderStorage �׵�ַ  ԭpHeadOrder
	OrderStorage pEORL;  //β��ַ   ԭpEndOrder
	ULength ULORCou;   //����   ԭordercount

};

*/

/*

struct DataStorage {  //ԭ DataList

	char* title;
	void* data;
	struct DataStorage* previous;
	struct DataStorage* next;

};

*/

/*

struct newNodeStorage {   //�����µ�ַ���ȴ洢�Ľṹ��

	void* newnode; //�����ڵ��ַ
	void* newHNode;   //���������׵�ַ
	void* newENode;  //������β��ַ
	ULength newCou;  //�����³���
};

*/

/*
���õĴ�����ԭ��
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnCreObtNode)(void), void (FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
*/

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






//--------------------------------------data�ṹ���ʼ����ز���
//�����ڴ桢ֱ���ͷ��ڴ桢��ȫ�ͷ��ڴ桢��ñ��⣬���ݣ���һ���ڵ㣬��һ���ڵ�

//ΪDataStorage�����µ��ڴ浥Ԫ
DataStorage FnCreObtDataStorage(void) {

	return (DataStorage)malloc(ByteDataStorage);

}

//�ͷ�DataStorage���ڴ浥Ԫ
void FnFreDataStorage(DataStorage node) {

	return free(node); //free�޷���ֵ
}

//�ͷ�DataStorage���ڴ浥Ԫ �� title����
void FnFreDataStorage_TAD(DataStorage node) {

	if (node) {
		FnDelStrCopy(node->title);
		FnFreDataStorage(node);
	}


	return;
}

//��ȡ��ǰ�ڵ��title����
char* FnObtDataStorage_Title(DataStorage node) {

	return node->title;

}

//��ȡ��ǰ�ڵ��data����
void* FnObtDataStorage_Data(DataStorage node) {

	return node->data;

}

//��ȡ��ǰ�ڵ��previous����һ���ڵ�
DataStorage FnObtDataStorage_Previous(DataStorage node) {

	return node->previous;

}

//��ȡ��ǰ�ڵ��next����һ���ڵ�
DataStorage FnObtDataStorage_Next(DataStorage node) {

	return node->next;

}


//--------------------------------------data�ṹ�����ݵ��޸�
//�����data����һ���ڵ����һ���ڵ㡢��һ���ڵ㡢��һ���ڵ�

//�޸�Data�ṹ�� �����data�ĵ�ַ
void FnRevDataStorage_TAD(DataStorage node, char* title, void* data) {

	if (node) {
		node->title = title;
		node->data = data;
	}

	return;
}

//�޸�Data�ṹ�� ��һ�ڵ㣬����һ���ڵ�ĵ�ַ
void FnRevDataStorage_Rne(DataStorage node, DataStorage previous, DataStorage next) {

	if (node) {
		node->previous = previous;
		node->next = next;
	}

	return;
}

//�޸�Data�ṹ�� ��һ�ڵ�ĵ�ַ
void FnRevDataStorage_Previous(DataStorage node, DataStorage previous) {

	if (node) {
		node->previous = previous;
	}

	return;
}

//�޸�Data�ṹ�� ��һ���ڵ�ĵ�ַ
void FnRevDataStorage_Next(DataStorage node, DataStorage next) {

	if (node) {
		node->next = next;
	}

	return;
}


//--------------------------------------data˫������Ĳ���
//������ɾ����������˳�����

//��data��������һ���ڵ�
p_newNodeStorage FnCreAddDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title, void* data, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;


	if (FnSurObtString_Title(title)) {


		//�����׵�ַ��β��ַ�������ȣ����ӵ�λ�ã��Լ���Ҫ�ĺ���   ����һ���ڵ�
		newNode_iresult = FnCreAddObtNode(pHDAL, pEDAL, Cou, LocCou,
			FnCreObtDataStorage, FnRevDataStorage_Rne,
			FnRevDataStorage_Previous, FnRevDataStorage_Next,
			FnObtDataStorage_Previous, FnObtDataStorage_Next);

		if (newNode_iresult) {
			FnRevDataStorage_TAD(FnObtnewNodeStorage_Newnode(newNode_iresult), FnCreObtStrCopy(title), data); //����һ������
		}

	}

	return newNode_iresult;
}

/*

//-----˫�������ɾ����ͨ��
p_newNodeStorage FnFreDelNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void (*FnFreNode)(void* node),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));

*/

//��data����ɾ��һ���ڵ�
p_newNodeStorage FnFreDelDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHDAL && pEDAL && Cou && (LocCou >= 0 && LocCou < Cou || LocCou == _END_)) {   //ɾ���Ľڵ�λ�ò���ȷ

		//�����׵�ַ��β��ַ�������ȣ�ɾ����λ�ã�ɾ��һ���ڵ�
		newNode_iresult = FnFreDelNode(pHDAL, pEDAL, Cou, LocCou,
			FnFreDataStorage_TAD,
			FnRevDataStorage_Previous, FnRevDataStorage_Next,
			FnObtDataStorage_Previous, FnObtDataStorage_Next);

	}

	return newNode_iresult;
}

/*

p_newNodeStorage FnFreMovNode(void* HNode, void* ENode, ULength Cou, ULength LocCou_one, ULength LocCou_two,
	void* (*FnCreObtNode)(void), void (*FnFreNode_Dir)(void* node),
	void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node))

*/

//����data�����������ڵ��λ��
p_newNodeStorage FnFreMovDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou_one, ULength LocCou_two) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHDAL && pEDAL && Cou >= 2 && (LocCou_one >= 0 && LocCou_one < Cou && LocCou_two >= 0 && LocCou_two < Cou)) {//�ж�����λ���Ƿ����

		//�����׵�ַ��β��ַ�������ȣ�Ҫ���������ڵ��λ�ã����������ڵ�
		newNode_iresult = FnFreMovNode(pHDAL, pEDAL, Cou, LocCou_one, LocCou_two,
			FnCreObtDataStorage, FnFreDataStorage, FnRevDataStorage_Rne,
			FnRevDataStorage_Previous, FnRevDataStorage_Next,
			FnObtDataStorage_Previous, FnObtDataStorage_Next);

	}

	return newNode_iresult;
}

/*

bool FnFreOptNode_Data(void* HNode, void* ENode, ULength Cou, ULength LocCou_Len,ULength* LocCou,bool Com,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node),
	void* (*FnObtNode_Title)(void* node),void* (*FnObtNode_Data)(void *node),bool (*FnOptNode_Data)(char* title, void *data))

*/

//data˳�����
bool FnFreOptDataStorage_Data(DataStorage* HNode, DataStorage* ENode, ULength Cou, char* order,
	bool (*FnOptNode_Data)(char* title, void* data)) {

	bool iresult = false;

	if (HNode && ENode && Cou >= 1 && order) {

		//����order
		ULength* iorder = FnExpFinObtOrderStorage_Order(order, HNode, ENode, Cou);

		//���ͳɹ�
		if (iorder[0] >= 3 && iorder[1] != -1) {

			ULength LocCou_Len = iorder[0] - 2;
			ULength* LocCou = iorder + 2;
			bool Com = iorder[1];

			iresult = FnFreOptNode_Data(HNode, ENode, Cou, LocCou_Len, LocCou, Com,
				FnObtDataStorage_Previous, FnObtDataStorage_Next,
				FnObtDataStorage_Title, FnObtDataStorage_Data, FnOptNode_Data);


		}


	}

	return iresult;
}




//--------------------------------------data˫����������ݶ�ȡ
//�����ȡλ�ã������ȡ���ݣ�λ�ö�ȡ���⣬λ�ö�ȡ����

//ͨ�������ȡλ��
//���ڷ���λ�ã������ڷ���-1
Length FnFinObtDataStorage_TLCou(DataStorage pHDAL, ULength Cou, char* title) {

	Length iresult = 0;

	if (!(pHDAL && FnSurObtString_Title(title) && Cou > 0)) {   //�����Ƿ���Ϲ淶�������Ƿ����0���׵�ַ�Ƿ����

		iresult = -1;


	}

	if (!iresult) {  //�����������

		DataStorage node = pHDAL;

		ULength i;  //������

		//��ǰλ��С�ڳ��ȣ��ڵ�û�е�ĩβ������δ�ҵ�
		for (i = 0; node && i < Cou && strcmp(title, FnObtDataStorage_Title(node));i++) {

			node = FnObtDataStorage_Next(node);

		}
		
		if (i != Cou) {  //�ҵ�������

			iresult = i;

		}
		else {  //û�ҵ�

			iresult = -1;
		}

	}
	
	return iresult;

}

//ͨ�������ȡ����
void* FnFinObtDataStorage_TDATA(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title) {

	//���ú���ͨ�������ȡλ�ã���ͨ��λ�ö�ȡ����
	return FnFinObtDataStorage_LCouD(pHDAL, pEDAL, Cou, FnFinObtDataStorage_TLCou(pHDAL, Cou, title));

}

/*

//�����׽ڵ㣬β�ڵ㣬�����ȣ�������ǰ�浽�����LocCou��
//��ȡ�ڵ����һ����ַ������һ����ַ������������������  FnObtNode_previous  FnObtNode_next ����ϣ�������
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node))

*/

//ͨ��λ�ö�ȡ����
//�ҵ��˾������ݵĵ�ַ��û�ҵ�����NULL;
void* FnFinObtDataStorage_LCouD(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou) {

	void* iresult = (void*)1;

	if (!(pHDAL && Cou > 0 && LocCou >= 0 && LocCou < Cou)) {

		iresult = NULL;

	}

	if (iresult) {

		DataStorage node = FnSeaObtCouNode(pHDAL, pEDAL, Cou, LocCou, FnObtDataStorage_Previous,
			FnObtDataStorage_Next);

		iresult = FnObtDataStorage_Data(node);

	}

	return iresult;

}

//ͨ��λ�ö�ȡ����
//�ҵ��˾������ݵĵ�ַ��û�ҵ�����NULL;
char* FnFinObtDataStorage_LCouT(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou) {

	char* iresult = (char*)1;

	if (!(pHDAL && Cou > 0 && LocCou >= 0 && LocCou < Cou)) {

		iresult = NULL;

	}

	if (iresult) {

		DataStorage node = FnSeaObtCouNode(pHDAL, pEDAL, Cou, LocCou, FnObtDataStorage_Previous,
			FnObtDataStorage_Next);

		iresult = FnObtDataStorage_Title(node);

	}

	return iresult;

}

//--------------------------------------data�����SLoc����

//DataStorage����SLoc,������ת��Ϊλ�ã���λ���ַ���ת��Ϊ����λ��,��ȷ����λ�ã����󷵻�-1
Length FnFinEvpObtDataStorage_SLoc(DataStorage pHDAL, ULength Cou,char* SLoc) {

	Length iresult = -1;

	if ( SLoc) {

		iresult = FnSurObtString_TLoc(SLoc);

		if (iresult == 0 && pHDAL && Cou >= 1) {   //���ͱ���

			iresult = FnFinObtDataStorage_TLCou(pHDAL, Cou, SLoc);

		}
		else if (iresult == 1) {   //����λ��

			iresult = atoll(SLoc);

		}
	}

	


	return iresult;
}

