
#include "staticscreenadt.h"


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



//----------------------------------双向链表部分
//新增、删除、交换、顺序输出


//传入链表首地址，尾地址，长度，创建链表的位置
//还需要两个函数指针
//1.在内存空间中分配一个新的节点，返回新节点的地址  FnCreObtNode   创建（分配）并返回节点
//2.设置节点的上一个地址和下一个地址（合集）    FnAddNode_Rne 修改上和下一个地址
//3.设置节点的上一个地址，和下一个地址（单独，两个函数）  FnAddNode_previous   FnAddNode_next  修改上，或者下
//4.获取节点的上一个地址，和下一个地址（单独，两个函数）  FnObtNode_previous  FnObtNode_next 获得上，或者下
//返回一个结构体指针
//新的首地址，尾地址，长度，和新节点的地址，封装到一个结构体中，通过函数的调用分别获得
//如果增加失败，返回NULL
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou, //给链表新增一个节点，通用
	void* (*FnCreObtNode)(void), void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node)) {

	void* iresult = (int)NULL + 1;


	//首先判断传入参数是否正确
	if (HNode == NULL && ENode == NULL) {// 首地址和尾地址为空，表示这是一个空链表

		//如果这是一个空链表，那么长度肯定是0，新节点位置只能是首部或者尾部
		if (!(Cou == 0 && (LocCou == _HEAD_ || LocCou == _END_))) {
			iresult = NULL;
		}
		else if (LocCou == _END_) {  //如果在最后面添加，且链表长度为0(上个if已经判断)，就不同意添加
			LocCou = _HEAD_;
		}


	}
	else if (HNode != NULL && ENode != NULL) { //如果两个都不为空，那么检测长度，和新节点的位置



		//如果这不是一个空链表，长度肯定大于0，新节点的位置在0到长度之间
		if (!(Cou >= 1 && (LocCou >= 0 && LocCou <= Cou || LocCou == _END_))) {
			iresult = NULL;
		}
		else if (LocCou == Cou) {

			LocCou = _END_;

		}

	}
	else {// 除此之外，不会有第三种情况
		iresult = NULL;
	}

	if (iresult) {  //传入的参数没有问题，判断是哪一种情况

		void* newnode;  //新节点
		void* newHNode; //新首地址
		void* newENode;  //新尾地址
		ULength newCou;  //新长度

		newnode = FnCreObtNode(); //获得一个新的节点

		if (!newnode) { //分配失败
			iresult = NULL;
		}
		else {  //分配成功


			if (LocCou == _HEAD_) {// 在最前面添加

				if (Cou == 0) {  //空链表，增加一个节点，首地址尾地址新节点地址都一样，长度为0+1


					FnRevNode_Rne(newnode, NULL, NULL);  //新节点的前一个和后一个节点设置为空，链表的第一个节点

					newHNode = newENode = newnode;  //新首和尾节点，设置为新节点，链表只有一个节点
				}
				else { //链表不为空


					FnRevNode_Rne(newnode, NULL, HNode);  //上一个为空，因为是首，下一个为旧首节点
					FnRevNode_Previous(HNode, newnode);
					//将旧首节点移动到第二个，把他的上一个节点从NULL改为，新节点



					newHNode = newnode;  //首节点设为新节点地址，因为在首添加
					newENode = ENode;  //尾节点不变
				}



			}
			else if (LocCou == _END_) { //在最后面添加   链表肯定不为空


				FnRevNode_Rne(newnode, ENode, NULL);  //下一个为空，因为是尾节点，上一个为旧尾节点
				FnRevNode_Next(ENode, newnode);
				//将旧尾节点移动到-1个，把他的下一个节点从NULL改为，新节点


				newHNode = HNode;  //首节点不变
				newENode = newnode;  //尾节点设为新节点地址，因为在尾部添加

			}
			else { //在中间添加


				void* LocCounode = FnSeaObtCouNode(HNode, ENode, Cou, LocCou, FnObtNode_Previous, FnObtNode_Next);
				//首先在链表中，找到这一个节点

				//设置新的节点，上一个和下一个,上一个为原节点的上一个，下一个为原节点
				FnRevNode_Rne(newnode, FnObtNode_Previous(LocCounode), LocCounode);
				//设置原节点上一个，的下一个，为新节点
				FnRevNode_Next(FnObtNode_Previous(LocCounode), newnode);
				//设置原节点的上一个，为新节点
				FnRevNode_Previous(LocCounode, newnode);



				newHNode = HNode;  //首节点不变
				newENode = ENode;  //尾节点不变


			}



			newCou = Cou + 1;  //链表长度+1
			iresult = FnCreObtnewNodeStorage();  //分配内存
			FnRevnewNode_Storage(iresult, newnode, newHNode, newENode, newCou);  //将节点和长度放入
		}


	}

	return iresult;

}

//传入链表首地址，尾地址，长度，删除节点的位置
//还需要两个函数指针
//3.设置节点的上一个地址，和下一个地址（单独，两个函数）  FnAddNode_previous   FnAddNode_next  修改上，或者下
//4.获取节点的上一个地址，和下一个地址（单独，两个函数）  FnObtNode_previous  FnObtNode_next 获得上，或者下
//返回一个结构体指针
//新的首地址，尾地址，长度，封装到一个结构体中，通过函数的调用分别获得
//如果删除失败，返回NULL
//FnFreNode  将要删除的节点放入进去，由该函数负责释放内存
p_newNodeStorage FnFreDelNode(void* HNode, void* ENode, ULength Cou, Length LocCou,//删除双向链表中的一个节点
	void (*FnFreNode)(void* node),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node)) {

	void* iresult = (int)NULL + 1;

	//首先判断传入参数是否正确
	if (HNode == NULL || ENode == NULL) {// 首地址或尾地址为空，那么传入参数错误

		iresult = NULL;

	}
	else if (HNode != NULL && ENode != NULL) { //如果两个都不为空，那么检测长度

		//如果这不是一个空链表，长度肯定大于0，新节点的位置在0到长度之间
		if (!(Cou > 0 && (LocCou >= 0 && LocCou < Cou || LocCou == _END_))) {
			iresult = NULL;
		}


		if (LocCou == Cou - 1) {  //如果选择的是尾地址

			LocCou = _END_;   //设置为尾地址

		}

		if (LocCou == _END_ && Cou == 1) {  //如果选择的是尾地址，且只剩下了最后一个
			LocCou = _HEAD_;   //设为首地址

		}



	}
	else {// 除此之外，不会有第三种情况
		iresult = NULL;
	}

	if (iresult) {

		void* newnode = NULL;  //新节点
		void* newHNode; //新首地址
		void* newENode;  //新尾地址
		ULength newCou;  //新长度

		if (LocCou == _HEAD_) {// 删除首节点


			if (Cou == 1) {   //只剩下一个节点了



				newHNode = NULL;   //啥都没有了，首尾设为NULL
				newENode = NULL;

				FnFreNode(HNode);//删除节点
			}
			else {


				newHNode = FnObtNode_Next(HNode);   //首节点变为旧首节点的下一个
				newENode = ENode;   //尾节点不变

				FnRevNode_Previous(FnObtNode_Next(HNode), NULL); //将旧首节点的下一个节点，的上一个节点设为NULL

				FnFreNode(HNode);  //删除节点
			}

		}
		else if (LocCou == _END_) {   //删掉尾节点的话，节点数量肯定大于1



			newHNode = HNode;   //首节点不变
			newENode = FnObtNode_Previous(ENode);   //新尾节点变为旧尾节点的上一个

			FnRevNode_Next(FnObtNode_Previous(ENode), NULL);//设置旧尾节点的上一个，下一个为空，上一个不变

			FnFreNode(ENode);  //删除节点
		}
		else {  //节点数量大于等于3

			newHNode = HNode;   //首节点不变
			newENode = ENode;   //尾节点不变

			void* LocCounode = FnSeaObtCouNode(HNode, ENode, Cou, LocCou, FnObtNode_Previous, FnObtNode_Next);
			//首先在链表中，找到这一个节点

			//设置要删除节点的上一个，的下一个，变成要删除节点的下一个
			FnRevNode_Next(FnObtNode_Previous(LocCounode), FnObtNode_Next(LocCounode));
			//设置要删除节点的下一个，的上一个，变成要删除节点的上一个
			FnRevNode_Previous(FnObtNode_Next(LocCounode), FnObtNode_Previous(LocCounode));

			FnFreNode(LocCounode);  //删除节点
		}

		newCou = Cou - 1;  //链表长度+1
		iresult = FnCreObtnewNodeStorage();  //分配内存
		FnRevnewNode_Storage(iresult, newnode, newHNode, newENode, newCou);  //将节点和长度放入

	}

	return iresult;

}

//传入链表首地址，尾地址，长度，要交换两个节点的位置
//还需要两个函数指针
// //1.在内存空间中分配一个新的节点，返回新节点的地址  FnCreObtNode   创建（分配）并返回节点
// //2.设置节点的上一个地址和下一个地址（合集）    FnAddNode_Rne 修改上和下一个地址
//3.设置节点的上一个地址，和下一个地址（单独，两个函数）  FnAddNode_previous   FnAddNode_next  修改上，或者下
//4.获取节点的上一个地址，和下一个地址（单独，两个函数）  FnObtNode_previous  FnObtNode_next 获得上，或者下
//FnFreNode_Dir  将要删除的节点放入进去，由该函数负责释放内存,直接释放内存，无需额外操作
//成功返回1 失败返回0
p_newNodeStorage FnFreMovNode(void* HNode, void* ENode, ULength Cou, ULength LocCou_one, ULength LocCou_two,
	void* (*FnCreObtNode)(void), void (*FnFreNode_Dir)(void* node),
	void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node)) {



	p_newNodeStorage iresult = (void*)1;  //位置不是同一个

	if (!(LocCou_one != LocCou_two) || !(LocCou_one >= 0 && LocCou_one < Cou && LocCou_two >= 0 && LocCou_two)) {//判断两个位置是否存在
		iresult = NULL;
	}

	if (iresult) { //两个位置都存在，且不同

		if (LocCou_one > LocCou_two) {
			ULength tmp = LocCou_one;
			LocCou_one = LocCou_two;
			LocCou_two = tmp;

		}

		void* node_one = FnSeaObtCouNode(HNode, ENode, Cou, LocCou_one, FnObtNode_Previous, FnObtNode_Next);
		void* node_two = FnSeaObtCouNode(HNode, ENode, Cou, LocCou_two, FnObtNode_Previous, FnObtNode_Next);

		void* newnode = NULL;  //新节点
		void* newHNode; //新首地址
		void* newENode;  //新尾地址
		ULength newCou = 0;  //新长度


		if (LocCou_one == 0 && LocCou_two == Cou - 1) {   //头尾交换


			if (LocCou_two - LocCou_one > 1) {  //头尾交换 中间有相隔的节点


				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);

				void* tmpnode = FnCreObtNode(); //获得一个新的节点
				if (tmpnode) {   //通过一个新节点，交换两个节点
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //首尾交换，中间没有间隔

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//设置新的首尾
			newHNode = node_two;
			newENode = node_one;

		}
		else if (LocCou_one == 0) {  //头 中间交换



			if (LocCou_two - LocCou_one > 1) {  //头 中间交换 中间有相隔的节点

				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);
				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				void* tmpnode = FnCreObtNode(); //获得一个新的节点
				if (tmpnode) {   //通过一个新节点，交换两个节点
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //头 中间交换，中间没有间隔

				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//设置新的首尾
			newHNode = node_two;
			newENode = ENode;

		}
		else if (LocCou_two == Cou - 1) {  //尾 中间交换



			if (LocCou_two - LocCou_one > 1) {  //头 中间交换 中间有相隔的节点

				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);
				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);


				void* tmpnode = FnCreObtNode(); //获得一个新的节点
				if (tmpnode) {   //通过一个新节点，交换两个节点
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //头 中间交换，中间没有间隔

				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//设置新的首尾
			newHNode = HNode;
			newENode = node_one;

		}
		else {  //中间和中间交换


			if (LocCou_two - LocCou_one > 1) {  //头 中间交换 中间有相隔的节点


				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);
				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);
				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				void* tmpnode = FnCreObtNode(); //获得一个新的节点
				if (tmpnode) {   //通过一个新节点，交换两个节点
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //头 中间交换，中间没有间隔

				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);
				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//设置新的首尾
			newHNode = HNode;
			newENode = ENode;

		}

		if (iresult) {

			iresult = FnCreObtnewNodeStorage();  //分配内存
			FnRevnewNode_Storage(iresult, newnode, newHNode, newENode, newCou);  //将节点和长度放入

		}


	}

	return iresult;
}

//顺序输出链表中的数据
//传入，首地址，尾地址，链表长度，顺序数组长度，顺序数组，是否需要补全
//上一个地址函数，下一个地址函数，获得数据函数，输出数据函数
bool FnFreOptNode_Data(void* HNode, void* ENode, ULength Cou, ULength LocCou_Len, ULength* LocCou, bool Com,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node),
	void* (*FnObtNode_Title)(void* node), void* (*FnObtNode_Data)(void* node), bool (*FnOptNode_Data)(char* title, void* data)) {

	bool iresult = false;

	if (HNode && ENode && Cou >= 1 && LocCou_Len >= 1 && LocCou) {//检查参数是否正确

		//输出个数计数
		int i;
		//当前位置
		ULength Cur = 0;
		//当前节点
		void* Curnode = HNode;

		for (i = 0; i < LocCou_Len; i++) {


			//依次获得每一项顺序
			ULength iLocCou = LocCou[i];


			//顺序是否在合理范围内
			if (!(iLocCou >= 0 && iLocCou < Cou)) {

				break;
			}

			//判断谁理他最近，然后去到下一个顺序的节点
			if (abs(Cur - iLocCou) <= ((abs(0 - iLocCou) < (Cou - iLocCou) ? abs(0 - iLocCou) : (Cou - iLocCou))) ? 1 : 0) {
				//从当前位置开始

				if (Cur > iLocCou) {  //向前

					Curnode = FnMovObtCouNode_Previous(Curnode, abs(Cur - iLocCou), FnObtNode_Previous);
					Cur = iLocCou;

				}
				else if (Cur < iLocCou) {  //向后

					Curnode = FnMovObtCouNode_Next(Curnode, abs(Cur - iLocCou), FnObtNode_Next);
					Cur = iLocCou;

				}
				else {  //位置未改变
					;
					//节点位置不用比那

				}

			}
			else {//从首或尾部开始

				Curnode = FnSeaObtCouNode(HNode, ENode, Cou, iLocCou, FnObtNode_Previous, FnObtNode_Next);
				Cur = iLocCou;

			}


			//移动到了下一个节点
			//拿到数据，然后提交给输出函数

			if (!FnOptNode_Data(FnObtNode_Title(Curnode), FnObtNode_Data(Curnode))) { //输出失败

				break;
			}


		}

		if (i == LocCou_Len) {  ///全部输出成功

			if (Com == 1) {  //开启补全

				for (i = 0; i < Cou; i++) {

					int j;

					for (j = 0; j < LocCou_Len; j++) {

						if (i == LocCou[j]) {

							break;
						}

					}

					if (j == LocCou_Len) {  //这个节点没有被输出


						//判断谁理他最近，然后去到下一个顺序的节点
						if (abs(Cur - i) <= ((abs(0 - i) < (Cou - i) ? abs(0 - i) : (Cou - i))) ? 1 : 0) {
							//从当前位置开始

							if (Cur > i) {  //向前

								Curnode = FnMovObtCouNode_Previous(Curnode, abs(Cur - i), FnObtNode_Previous);
								Cur = i;

							}
							else if (Cur < i) {  //向后

								Curnode = FnMovObtCouNode_Next(Curnode, abs(Cur - i), FnObtNode_Next);
								Cur = i;

							}
							else {  //位置未改变
								;
								//节点位置不用比那

							}

						}
						else {//从首或尾部开始

							Curnode = FnSeaObtCouNode(HNode, ENode, Cou, i, FnObtNode_Previous, FnObtNode_Next);
							Cur = i;

						}

						//调用函数输出
						if (!FnOptNode_Data(FnObtNode_Title(Curnode), FnObtNode_Data(Curnode))) { //输出失败

							break;
						}

					}
				}

				if (i == Cou) {  //补全输出成功

					iresult = true;
				}

			}
			else {  //没开补全，任务结束
				iresult = true;
			}


		}

	}

}


//----------------------------------双向链表辅助结构体部分   一
//结构体、结构体内存分配、结构体内容的添加（修改），返回新的节点，新的首地址，新的尾地址，新的长度

/*

struct newNodeStorage {   //链表新地址长度存储的结构体

	void* newnode; //新增节点地址
	void* newHNode;   //新链表新首地址
	void* newENode;  //链表新尾地址
	ULength newCou;  //链表新长度
};

*/

//newNodeStorage结构体分配内存
newNodeStorage FnCreObtnewNodeStorage(void) {  

	return (newNodeStorage)malloc(BytenewNodeStorage);

}

//FnRevnewNode_Storage  结构体内容添加（修改）
bool FnRevnewNode_Storage(newNodeStorage node, void* newnode, void* newHNode, void* newENode, ULength newCou) {

	bool iresult = false;

	if (node) {
		node->newnode = newnode;
		node->newHNode = newHNode;
		node->newENode = newENode;
		node->newCou = newCou;
		iresult = true;
	}

	return iresult;

};

//返回新节点地址
void* FnObtnewNodeStorage_Newnode(newNodeStorage varnewNode) {

	return varnewNode->newnode;

}

//返回新首地址
void* FnObtnewNodeStorage_NewHNode(newNodeStorage varnewNode) {

	return varnewNode->newHNode;

}

//返回新尾地址
void* FnObtnewNodeStorage_NewENode(newNodeStorage varnewNode) {

	return varnewNode->newENode;

}

//返回新链表长度
ULength FnObtnewNodeStorage_NewCou(newNodeStorage varnewNode) {

	return varnewNode->newCou;

}



//----------------------------------双向链表辅助部分    二
//到达指定位置、向上移动n个节点、向下移动n个节点


//传入首节点，尾节点，链表长度，数到从前面到后面第LocCou个
//获取节点的上一个地址，和下一个地址（单独，两个函数）  FnObtNode_previous  FnObtNode_next 获得上，或者下
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node)) {

	void* iresult = (int)NULL + 1;

	if (!(HNode != NULL && ENode != NULL && Cou > 0 && LocCou >= 0 && LocCou < Cou)) {
		iresult = NULL;
	}

	if (iresult) {

		if (LocCou <= Cou / 2) {//从前面数

			iresult = FnMovObtCouNode_Next(HNode, LocCou, FnObtNode_next);

		}
		else {//从后面数

			LocCou = Cou - LocCou - 1;
			iresult = FnMovObtCouNode_Previous(ENode, LocCou, FnObtNode_Previous);

		}

	}

	return iresult;

}

//向上一个节点移动count个节点
void* FnMovObtCouNode_Previous(void* node, ULength LocCou, void* (*FnObtNode_Previous)(void* node)) {


	int i;

	for (i = 0; i < LocCou && node; i++) {

		node = FnObtNode_Previous(node);   //FnObtNode_Previous()函数，返回当前节点的上一个节点

	}

	return node;
	//移动成功，返回移动到的节点地址，移动失败返回NULL
}

//向下一个节点移动count个节点
void* FnMovObtCouNode_Next(void* Node, ULength LocCou, void* (*FnObtNode_Next)(void* Node)) {


	int i;

	for (i = 0; i < LocCou && Node; i++) {

		Node = FnObtNode_Next(Node);  //FnObtNode_Next()函数，返回当前节点的下一个节点

	}

	return Node;
	//移动成功，返回移动到的节点地址，移动失败返回NULL
}


//----------------------------------字符串部分
//将字符串1从n到n+m拷贝到字符串2、生成字符串副本、删除字符串副本


//将字符串1从n到n+m拷贝到字符串2
char* FnCreFinObtCopy(char* str, int n, int m) {

	char* newStr = (char*)malloc(m + 1);

	if (newStr) {

		int i;

		for (i = 0; i < m; i++) {

			newStr[i] = str[n + i];

		}

		newStr[m] = '\0';

	}

	return newStr;
}

//传入一个字符串，为字符串创建副本，返回副本地址
char* FnCreObtStrCopy(char* str) {

	char* newStr = (char*)malloc(strlen(str) + 1);
	if (newStr) {
		strcpy_s(newStr, strlen(str) + 1, str);
	}
	return newStr;
}

//释放字符串副本
void FnDelStrCopy(char* str) {

	free(str);
	return;
}


//----------------------------------其他辅助部分
//判断标题、判断字符串是否为纯数字、判断SLoc是标题还是位置、判断SLoc是否正确

//data和order 标题 字符串处理部分   判断标题是否符合要求
bool FnSurObtString_Title(char* title) {

	bool iresult = false;

	if (title) {

		ULength Coustring = strlen(title) + 1;

		if (*title == '_' || isalpha(*title)) {   //首字母为字母或者下划线
			iresult = true;
		}

		if (iresult) {

			for (int i = 1; i < Coustring; i++) {

				char Cha = *(title + i);

				if (Cha == '/') {
					;
				}
				else if (Cha == '\\') {
					;
				}
				else if (Cha == ':') {
					;
				}
				else if (Cha == '*') {
					;
				}
				else if (Cha == '?') {
					;
				}
				else if (Cha == '"') {
					;
				}
				else if (Cha == '<') {
					;
				}
				else if (Cha == '>') {
					;
				}
				else if (Cha == '|') {
					;
				}
				else {  //当前字符符合规则，进行下一项检测
					continue;
				}

				iresult = false;
				break;
			}

		}

	}

	return iresult;

}

//判断字符串位置，是否为纯数字
bool FnSurObtString_LocCou(char* SLoc) {

	bool iresult = true;

	if (SLoc) {
		ULength loccoustring = strlen(SLoc);

		for (int i = 0; i < loccoustring; i++) {

			if (!(*(SLoc + i) >= '0' && *(SLoc + i) <= '9')) {
				iresult = false;
				break;
			}

		}
	}

	return iresult;
}

//判断SLoc是标题还是位置  -1 错误  0 标题  1位置
Length FnSurObtString_TLoc(char* SLoc) {

	Length iresult = -1;  //不知道是什么东西，标题或者位置的要求都不满足

	if (SLoc && *SLoc == '_' || isalpha(*SLoc)) {  //标题

		iresult = FnSurObtString_Title(SLoc);//标题是否符合要求

		if (iresult == 1) {
			iresult = 0;
		}
		else {
			iresult = -1;
		}
	}
	else {  //位置

		iresult = FnSurObtString_LocCou(SLoc);//纯数字位置是否符合要求

		if (!iresult) {
			iresult = -1;
		}
	}

	return iresult;
}

//判断SLoc是否正确
bool FnSurObtString_SLoc(char* SLoc) {

	bool iresult = false; 

	if (SLoc) {

		Length i = FnSurObtString_TLoc(SLoc);//判断是 标题 还是位置

		if (i == 0 || i == 1) {  //是标题，也是位置，满足
			iresult = true;
		}

		return iresult;

	}

	
}

