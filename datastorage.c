					
#include "staticscreenadt.h"

/*

struct ScreenADT {  //原 ScreenADT(一致)

	DataStorage pHDAL;   //DataStorage 的首地址   原 pHeadData
	DataStorage pEDAL;   // 尾地址   原pEndData
	ULength ULDACou;   //长度  原datacount
	OrderStorage pHORL;  //OrderStorage 首地址  原pHeadOrder
	OrderStorage pEORL;  //尾地址   原pEndOrder
	ULength ULORCou;   //长度   原ordercount

};

*/

/*

struct DataStorage {  //原 DataList

	char* title;
	void* data;
	struct DataStorage* previous;
	struct DataStorage* next;

};

*/

/*

struct newNodeStorage {   //链表新地址长度存储的结构体

	void* newnode; //新增节点地址
	void* newHNode;   //新链表新首地址
	void* newENode;  //链表新尾地址
	ULength newCou;  //链表新长度
};

*/

/*
调用的大函数的原型
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnCreObtNode)(void), void (FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
*/

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






//--------------------------------------data结构体初始化相关操作
//分配内存、直接释放内存、完全释放内存、获得标题，数据，上一个节点，下一个节点

//为DataStorage分配新的内存单元
DataStorage FnCreObtDataStorage(void) {

	return (DataStorage)malloc(ByteDataStorage);

}

//释放DataStorage的内存单元
void FnFreDataStorage(DataStorage node) {

	return free(node); //free无返回值
}

//释放DataStorage的内存单元 和 title标题
void FnFreDataStorage_TAD(DataStorage node) {

	if (node) {
		FnDelStrCopy(node->title);
		FnFreDataStorage(node);
	}


	return;
}

//获取当前节点的title标题
char* FnObtDataStorage_Title(DataStorage node) {

	return node->title;

}

//获取当前节点的data数据
void* FnObtDataStorage_Data(DataStorage node) {

	return node->data;

}

//获取当前节点的previous的上一个节点
DataStorage FnObtDataStorage_Previous(DataStorage node) {

	return node->previous;

}

//获取当前节点的next的下一个节点
DataStorage FnObtDataStorage_Next(DataStorage node) {

	return node->next;

}


//--------------------------------------data结构体内容的修改
//标题和data、上一个节点和下一个节点、上一个节点、下一个节点

//修改Data结构体 标题和data的地址
void FnRevDataStorage_TAD(DataStorage node, char* title, void* data) {

	if (node) {
		node->title = title;
		node->data = data;
	}

	return;
}

//修改Data结构体 上一节点，和下一个节点的地址
void FnRevDataStorage_Rne(DataStorage node, DataStorage previous, DataStorage next) {

	if (node) {
		node->previous = previous;
		node->next = next;
	}

	return;
}

//修改Data结构体 上一节点的地址
void FnRevDataStorage_Previous(DataStorage node, DataStorage previous) {

	if (node) {
		node->previous = previous;
	}

	return;
}

//修改Data结构体 下一个节点的地址
void FnRevDataStorage_Next(DataStorage node, DataStorage next) {

	if (node) {
		node->next = next;
	}

	return;
}


//--------------------------------------data双向链表的操作
//新增、删除、交换、顺序输出

//给data链表新增一个节点
p_newNodeStorage FnCreAddDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title, void* data, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;


	if (FnSurObtString_Title(title)) {


		//传入首地址，尾地址，链表长度，增加的位置，以及需要的函数   增加一个节点
		newNode_iresult = FnCreAddObtNode(pHDAL, pEDAL, Cou, LocCou,
			FnCreObtDataStorage, FnRevDataStorage_Rne,
			FnRevDataStorage_Previous, FnRevDataStorage_Next,
			FnObtDataStorage_Previous, FnObtDataStorage_Next);

		if (newNode_iresult) {
			FnRevDataStorage_TAD(FnObtnewNodeStorage_Newnode(newNode_iresult), FnCreObtStrCopy(title), data); //设置一下数据
		}

	}

	return newNode_iresult;
}

/*

//-----双向链表的删除，通用
p_newNodeStorage FnFreDelNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void (*FnFreNode)(void* node),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));

*/

//给data链表删除一个节点
p_newNodeStorage FnFreDelDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHDAL && pEDAL && Cou && (LocCou >= 0 && LocCou < Cou || LocCou == _END_)) {   //删除的节点位置不正确

		//传入首地址，尾地址，链表长度，删除的位置，删除一个节点
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

//交换data链表中两个节点的位置
p_newNodeStorage FnFreMovDataStorage(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, ULength LocCou_one, ULength LocCou_two) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHDAL && pEDAL && Cou >= 2 && (LocCou_one >= 0 && LocCou_one < Cou && LocCou_two >= 0 && LocCou_two < Cou)) {//判断两个位置是否存在

		//传入首地址，尾地址，链表长度，要交换两个节点的位置，交换两个节点
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

//data顺序输出
bool FnFreOptDataStorage_Data(DataStorage* HNode, DataStorage* ENode, ULength Cou, char* order,
	bool (*FnOptNode_Data)(char* title, void* data)) {

	bool iresult = false;

	if (HNode && ENode && Cou >= 1 && order) {

		//解释order
		ULength* iorder = FnExpFinObtOrderStorage_Order(order, HNode, ENode, Cou);

		//解释成功
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




//--------------------------------------data双向链表的数据读取
//标题读取位置，标题读取数据，位置读取标题，位置读取数据

//通过标题读取位置
//存在返回位置，不存在返回-1
Length FnFinObtDataStorage_TLCou(DataStorage pHDAL, ULength Cou, char* title) {

	Length iresult = 0;

	if (!(pHDAL && FnSurObtString_Title(title) && Cou > 0)) {   //名称是否符合规范，长度是否大于0，首地址是否存在

		iresult = -1;


	}

	if (!iresult) {  //传入参数无误

		DataStorage node = pHDAL;

		ULength i;  //计数器

		//当前位置小于长度，节点没有到末尾，标题未找到
		for (i = 0; node && i < Cou && strcmp(title, FnObtDataStorage_Title(node));i++) {

			node = FnObtDataStorage_Next(node);

		}
		
		if (i != Cou) {  //找到标题了

			iresult = i;

		}
		else {  //没找到

			iresult = -1;
		}

	}
	
	return iresult;

}

//通过标题读取数据
void* FnFinObtDataStorage_TDATA(DataStorage pHDAL, DataStorage pEDAL, ULength Cou, char* title) {

	//调用函数通过标题读取位置，在通过位置读取数据
	return FnFinObtDataStorage_LCouD(pHDAL, pEDAL, Cou, FnFinObtDataStorage_TLCou(pHDAL, Cou, title));

}

/*

//传入首节点，尾节点，链表长度，数到从前面到后面第LocCou个
//获取节点的上一个地址，和下一个地址（单独，两个函数）  FnObtNode_previous  FnObtNode_next 获得上，或者下
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node))

*/

//通过位置读取数据
//找到了就是数据的地址，没找到就是NULL;
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

//通过位置读取标题
//找到了就是数据的地址，没找到就是NULL;
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

//--------------------------------------data链表的SLoc解释

//DataStorage解释SLoc,将标题转化为位置，将位置字符，转化为数字位置,正确返回位置，错误返回-1
Length FnFinEvpObtDataStorage_SLoc(DataStorage pHDAL, ULength Cou,char* SLoc) {

	Length iresult = -1;

	if ( SLoc) {

		iresult = FnSurObtString_TLoc(SLoc);

		if (iresult == 0 && pHDAL && Cou >= 1) {   //解释标题

			iresult = FnFinObtDataStorage_TLCou(pHDAL, Cou, SLoc);

		}
		else if (iresult == 1) {   //解释位置

			iresult = atoll(SLoc);

		}
	}

	


	return iresult;
}

