
#include "staticscreenadt.h"

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






//--------------------------------------order结构体初始化相关操作
//分配内存、直接释放内存、完全释放内存、获得标题，数据，上一个节点，下一个节点

//为OrderStorage分配新的内存单元
OrderStorage FnCreObtOrderStorage(void) {

	return (OrderStorage)malloc(ByteOrderStorage);

}

//释放OrderStorage的内存单元
void FnFreOrderStorage(OrderStorage node) {

	return free(node); //free无返回值
}

//释放OrderStorage的内存单元 和 title标题 和 order顺序
void FnFreOrderStorage_TADOR(OrderStorage node) {


	if (node) {
		FnDelStrCopy(node->title);//释放标题
		FnDelStrCopy(node->order);//释放顺序
		FnFreOrderStorage(node);
	}

	return;
}

//获取当前节点的title标题
char* FnObtOrderStorage_Title(OrderStorage node) {

	return node->title;

}
//获取当前节点的order顺序
char* FnObtOrderStorage_Order(OrderStorage node) {

	return node->order;

}
//获取当前节点的previous的上一个节点
OrderStorage FnObtOrderStorage_Previous(OrderStorage node) {

	return node->previous;

}
//获取当前节点的next的下一个节点
OrderStorage FnObtOrderStorage_Next(OrderStorage node) {

	return node->next;

}





//--------------------------------------order结构体内容的修改
//标题和data、上一个节点和下一个节点、上一个节点、下一个节点

//修改OrderStorage结构体 标题和order顺序的地址
void FnRevOrderStorage_TAO(OrderStorage node, char* title, char* order) {

	if (node) {
		node->title = title;
		node->order = order;
	}

	return;
}


//修改OrderStorage结构体 上一节点，和下一个节点的地址
void FnRevOrderStorage_Rne(OrderStorage node, OrderStorage previous, OrderStorage next) {

	if (node) {
		node->previous = previous;
		node->next = next;
	}

	return;
}

//修改OrderStorage结构体 上一节点的地址
void FnRevOrderStorage_Previous(OrderStorage node, OrderStorage previous) {

	if (node) {
		node->previous = previous;
	}

	return;
}

//修改OrderStorage结构体 下一个节点的地址
void FnRevOrderStorage_Next(OrderStorage node, OrderStorage next) {

	if (node) {
		node->next = next;
	}

	return;
}




//--------------------------------------order双向链表的操作
//新增、删除、交换

/*
调用的大函数的原型
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnCreObtNode)(void), void (FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
*/

//给OrderStorage新增一个节点
p_newNodeStorage FnCreAddOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title, char* order, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;

	if (FnSurObtString_Title(title) && FnExpSurOrderStorage_Order(order)) {

		//传入首地址，尾地址，链表长度，增加的位置，以及需要的函数   增加一个节点
		newNode_iresult = FnCreAddObtNode(pHORL, pEORL, Cou, LocCou,
			FnCreObtOrderStorage, FnRevOrderStorage_Rne,
			FnRevOrderStorage_Previous, FnRevOrderStorage_Next,
			FnObtOrderStorage_Previous, FnObtOrderStorage_Next);

		if (newNode_iresult) {
			FnRevOrderStorage_TAO(FnObtnewNodeStorage_Newnode(newNode_iresult), FnCreObtStrCopy(title), FnCreObtStrCopy(order)); //设置一下数据
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

//给OrderStorage链表删除一个节点
p_newNodeStorage FnFreDelOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHORL && pEORL && Cou && (LocCou >= 0 && LocCou < Cou || LocCou == _END_)) {   //删除的节点位置不正确

		//传入首地址，尾地址，链表长度，删除的位置，删除一个节点
		newNode_iresult = FnFreDelNode(pHORL, pEORL, Cou, LocCou,
			FnFreOrderStorage_TADOR,
			FnRevOrderStorage_Previous, FnRevOrderStorage_Next,
			FnObtOrderStorage_Previous, FnObtOrderStorage_Next);

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

//交换OrderStorage结构体中两个节点的位置
p_newNodeStorage FnFreMovOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou_one, ULength LocCou_two) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHORL && pEORL && Cou >= 2 && (LocCou_one >= 0 && LocCou_one < Cou && LocCou_two >= 0 && LocCou_two < Cou)) {//判断两个位置是否存在

		//传入首地址，尾地址，链表长度，要交换两个节点的位置，交换两个节点
		newNode_iresult = FnFreMovNode(pHORL, pEORL, Cou, LocCou_one, LocCou_two,
			FnCreObtOrderStorage, FnFreOrderStorage, FnRevOrderStorage_Rne,
			FnRevOrderStorage_Previous, FnRevOrderStorage_Next,
			FnObtOrderStorage_Previous, FnObtOrderStorage_Next);


	}

	return newNode_iresult;
}




//--------------------------------------order双向链表的数据读取
//标题读取位置，标题读取数据，位置读取标题，位置读取数据

/*

struct OrderStorage {

	char* title;
	char* order;
	struct OrderStorage* previous;
	struct OrderStorage* next;
	
};

*/

//通过标题读取位置
//存在返回位置，不存在返回-1
Length FnFinObtOrderStorage_TLCou(OrderStorage pHORL, ULength Cou, char* title) {

	Length iresult = 0;

	if (!(pHORL && FnSurObtString_Title(title) && Cou >= 1)) {   //名称是否符合规范，长度是否大于0，首地址是否存在

		iresult = -1;


	}

	if (!iresult) {  //传入参数无误

		OrderStorage node = pHORL;

		ULength i;  //计数器

		//当前位置小于长度，节点没有到末尾，标题未找到
		for (i = 0; node && i < Cou && strcmp(title, FnObtOrderStorage_Title(node)); i++) {

			node = FnObtOrderStorage_Next(node);

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

//通过标题读取顺序
char* FnFinObtOrderStorage_TORDER(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title) {

	//调用函数通过标题读取位置，在通过位置读取顺序
	return FnFinObtOrderStorage_LCouO(pHORL, pEORL, Cou, FnFinObtOrderStorage_TLCou(pHORL, Cou, title));

}

//通过位置读取标题
//找到了就是数据的地址，没找到就是NULL;
char* FnFinObtOrderStorage_LCouT(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou) {

	char* iresult = (char*)1;

	if (!(pHORL && Cou > 0 && LocCou >= 0 && LocCou < Cou)) {

		iresult = NULL;

	}

	if (iresult) {

		OrderStorage node = FnSeaObtCouNode(pHORL, pEORL, Cou, LocCou, FnObtOrderStorage_Previous,
			FnObtOrderStorage_Next);

		iresult = FnObtOrderStorage_Title(node);

	}

	return iresult;

}

/*

//传入首节点，尾节点，链表长度，数到从前面到后面第LocCou个
//获取节点的上一个地址，和下一个地址（单独，两个函数）  FnObtNode_previous  FnObtNode_next 获得上，或者下
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node))

*/

//通过位置读取顺序
//找到了就是顺序地址，没找到就是NULL;
char* FnFinObtOrderStorage_LCouO(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou) {

	char* iresult = (char*)1;

	if (!(pHORL && Cou > 0 && LocCou >= 0 && LocCou < Cou)) {

		iresult = NULL;

	}

	if (iresult) {

		OrderStorage node = FnSeaObtCouNode(pHORL, pEORL, Cou, LocCou, FnObtOrderStorage_Previous,
			FnObtOrderStorage_Next);

		iresult = FnObtOrderStorage_Order(node);

	}

	return iresult;

}


//--------------------------------------order链表的SLoc解释

//OrderStorage解释SLoc,将标题转化为位置，将位置字符，转化为数字位置,正确返回位置，错误返回-1
Length FnFinEvpObtOrderStorage_SLoc(OrderStorage pHORL, ULength Cou, char* SLoc) {
	
	Length iresult = -1;

	if (SLoc) {

		iresult = FnSurObtString_TLoc(SLoc);

		if (iresult == 0 && pHORL && Cou >= 1) {   //解释标题

			iresult = FnFinObtOrderStorage_TLCou(pHORL, Cou, SLoc);

		}
		else if (iresult == 1) {   //解释位置

			iresult = atoll(SLoc);

		}
	}

	
	return iresult;
}

//--------------------------------------order链表的顺序判断和解释

//判断order顺序是否正确
bool FnExpSurOrderStorage_Order(char* order) {

	bool iresult = false;

	if (order) {

		Length order_len = strlen(order);

		if (order_len >= 3) {

			if (*order == '|') { //判断第一个是否为|开头

				char* SLoc = NULL;

				int Cou = 0; //统计SLoc的长度
				int LocCou = 1;//最开始的位置

				for (int i = 1; i < order_len; i++) { //开始验证


					if (*(order + i) != '|') {
						Cou++;
					}
					else {

						if (Cou >= 1) {  //SLoc长度≥1

							SLoc = FnCreFinObtCopy(order, LocCou, Cou); //获得SLoc

							//判断SLoc是否正确
							if (!FnSurObtString_SLoc(SLoc)) {  //不正确


								//释放SLoc
								FnDelStrCopy(SLoc);
								//iresult = false;
								break;

							}

							//SLoc正确

							//释放SLoc
							FnDelStrCopy(SLoc);


							if (i + 1 == order_len) {//到达末尾，需要补全

								iresult = true;
								break;

							}
							else if (i + 2 == order_len && *(order + i) == '|') {  //到达末尾，不需要补全。

								iresult = true;
								break;

							}
							else if (i + 2 == order_len) {  //到达末尾，但是出现了问题


								//iresult = false;
								break;
							}
							else {  //继续

								Cou = 0;  //长度重新设为0
								LocCou = i + 1; //重新设置起始位置
							}

						}
						else { //出现问题  SLoc的长度为0，标题不成立

							//iresult = false;
							break;

						}

					}


				}

			}
			else { //开头不对，不是|
				;
				//iresult = false;

			}

		}

	}

	return iresult;
}

//解释顺序,将位置装入数组中，
ULength* FnExpFinObtOrderStorage_Order(char* order, OrderStorage pHORL, ULength Cou) {

	int iorder_len = 2;
	ULength* iorder = (ULength*)malloc((sizeof(ULength) * iorder_len));
	iorder[0] = 2;  //长度为2
	iorder[1] = -1; //解释失败

	//第一个放整个数组的长度，第二个放判断信息，-1为解释失败，出现错误，0为不需要补全，1为需要补全，从第三个开始存放顺序

	if (order && pHORL && Cou >= 1) {

		Length order_len = strlen(order);
		iorder[0] = 2;  //长度为2
		iorder[1] = -1; //解释失败

		if (iorder && order_len >= 3) {

			if (*order == '|') { //判断第一个是否为|开头

				char* SLoc = NULL;

				int Cou = 0; //统计SLoc的长度
				int LocCou = 1;//最开始的位置
				//int SLoc_len = 0; //SLoc_len的长度

				for (int i = 1; i < order_len; i++) { //开始验证


					if (*(order + i) != '|') {
						Cou++;
					}
					else {

						if (Cou >= 1) {  //SLoc长度≥1

							SLoc = FnCreFinObtCopy(order, LocCou, Cou); //获得SLoc

							//判断SLoc是否正确
							if (!FnSurObtString_SLoc(SLoc)) {  //不正确


								//释放SLoc
								FnDelStrCopy(SLoc);
								//iresult = false;
								break;

							}

							//SLoc正确


							//解释SLoc
							int iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc);

							if (iSLoc == -1) {

								//不存在
								iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //缩小空间
								iorder[0] = 2;  //长度为2
								iorder[1] = -1; //解释失败
								break;
							}

							//存在，SLoc 长度+1
							//SLoc_len++;
							iorder_len++;

							//放入要返回的地方
							iorder = (ULength*)realloc(iorder, (sizeof(ULength) * iorder_len));  //加宽一下空间
							if (iorder) {
								iorder[0]++;  //个数增加
								iorder[iorder_len - 1] = iSLoc;
							}
							else {
								break;
							}
							

							//释放SLoc
							FnDelStrCopy(SLoc);


							if (i + 1 == order_len) {//到达末尾，需要补全

								iorder[1] = 1; //需要补全
								//iresult = true;
								break;

							}
							else if (i + 2 == order_len && *(order + i + 1) == '|') {  //到达末尾，不需要补全。

								iorder[1] = 0; //不需要补全
								//iresult = true;
								break;

							}
							else if (i + 2 == order_len) {  //到达末尾，但是出现了问题

								iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //缩小空间
								iorder[0] = 2;  //长度为2
								iorder[1] = -1; //解释失败
								//iresult = false;
								break;
							}
							else {  //继续

								Cou = 0;  //长度重新设为0
								LocCou = i + 1; //重新设置起始位置
							}

						}
						else { //出现问题  SLoc的长度为0，标题不成立

							iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //缩小空间
							iorder[0] = 2;  //长度为2
							iorder[1] = -1; //解释失败
							break;

						}

					}


				}

				if (iorder[1] == -1) {

					iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //缩小空间
					iorder[0] = 2;  //长度为2
					iorder[1] = -1; //解释失败

				}


			}
			else { //开头不对，不是|
				;
			//iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //缩小空间
			//iorder[0] = 2;  //长度为2
			//iorder[1] = -1; //解释失败
				//iresult = false;

			}

		}

	}

	return iorder;

}