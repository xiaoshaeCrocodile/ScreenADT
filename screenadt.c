
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








//--------------------------------初始化部分
//初始化数据类型
//分配内存单元


//初始化ScreenADT 抽象数据类型
ScreenADT IniScreenADT(void) {

	/*
	传入参数：void
	返回值：指针变量
	分配成功：首地址
	分配失败：NULL
	*/

	ScreenADT VarScreenADT = FnCreObtScreenADT(); //分配内存单元

	if (VarScreenADT) {  //分配成功

		VarScreenADT->pHDAL = NULL;
		VarScreenADT->pEDAL = NULL;
		VarScreenADT->ULDACou = 0;
		VarScreenADT->pHORL = NULL;
		VarScreenADT->pEORL = NULL;
		VarScreenADT->ULORCou = 0;

	}

	return VarScreenADT;
}

//为ScreenADT 分配内存单元
ScreenADT FnCreObtScreenADT(void) {

	return (ScreenADT)malloc(ByteScreenADT);  //分配内存单元

}




//--------------------------------结构内容修改部分

//修改ScreenADT结构体 data首地址 尾地址 长度
void FnRevScreenADT_DHECou(ScreenADT VarScreenADT, DataStorage pHDAL, DataStorage pEDAL, ULength ULDACou) {


	if (VarScreenADT) {

		VarScreenADT->pHDAL = pHDAL;
		VarScreenADT->pEDAL = pEDAL;
		VarScreenADT->ULDACou = ULDACou;
	}

	return;
}

//修改ScreenADT结构体 order首地址 尾地址 长度
void FnRevScreenADT_OHECou(ScreenADT VarScreenADT, OrderStorage pHDAL, OrderStorage pEDAL, ULength ULORCou) {


	if (VarScreenADT) {

		VarScreenADT->pHORL = pHDAL;
		VarScreenADT->pEORL = pEDAL;
		VarScreenADT->ULORCou = ULORCou;
	}

	return;
}

 //返回data首地址
void* FnObtScrA_pHDAL(ScreenADT VarScreenADT) {

	return VarScreenADT->pHDAL;

}
//返回data尾地址
void* FnObtScrA_pEDAL(ScreenADT VarScreenADT) {  

	return VarScreenADT->pEDAL;

}
//返回data链表长度
void* FnObtScrA_ULDACou(ScreenADT VarScreenADT) {  

	return VarScreenADT->ULDACou;

}
//返回order首地址
void* FnObtScrA_pHORL(ScreenADT VarScreenADT) {  

	return VarScreenADT->pHORL;

}
//返回order尾地址
void* FnObtScrA_pEORL(ScreenADT VarScreenADT) {  

	return VarScreenADT->pEORL;

}
//返回order链表长度
void* FnObtScrA_ULORCou(ScreenADT VarScreenADT) {  

	return VarScreenADT->ULORCou;

}





//--------------------------------调用其他函数，完成其他的部分
//data增加，删除，交换，SLoc获得标题，数据，输出，传入顺序，按照顺序输出

//data增加
bool ScreenAddData(ScreenADT VarScreenADT, char* title, void* data, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && title && SLoc) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength Cou = VarScreenADT->ULDACou;


		ULength iSLoc = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc);//解释SLoc

		//标题不能重复
		if (iSLoc != -1 && FnFinObtDataStorage_TLCou(pHDAL, Cou, title) == -1 && FnSurObtString_Title(title)) {

			p_newNodeStorage newNode_iresult = FnCreAddDataStorage(pHDAL, pEDAL, Cou, title, data, iSLoc);

			if (newNode_iresult) {  //添加成功
				//设置新的首地址，尾地址，链表长度
				FnRevScreenADT_DHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//最后要释放内存

				iresult = true;
			}

		}

	}

	return iresult;
}

//data删除
bool ScreenDelData(ScreenADT VarScreenADT, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && SLoc) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength Cou = VarScreenADT->ULDACou;


		ULength iSLoc = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc);//解释SLoc

		if (iSLoc != -1) {

			p_newNodeStorage newNode_iresult = FnFreDelDataStorage(pHDAL, pEDAL, Cou, iSLoc);

			if (newNode_iresult) {  //删除成功
				//设置新的首地址，尾地址，链表长度
				FnRevScreenADT_DHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//最后要释放内存
				iresult = true;
			}

		}

	}

	return iresult;

}

//data交换
bool ScreenMovData(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two) {

	bool iresult = false;

	if (VarScreenADT && SLoc_one && SLoc_two) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength Cou = VarScreenADT->ULDACou;


		ULength iSLoc_one = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc_one);//解释SLoc_one
		ULength iSLoc_two = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc_two);//解释SLoc_two

		if (iSLoc_one != -1 && iSLoc_two != -1 && iSLoc_one != iSLoc_two) {

			p_newNodeStorage newNode_iresult = FnFreMovDataStorage(pHDAL, pEDAL, Cou, iSLoc_one, iSLoc_two);

			if (newNode_iresult) {  //交换成功
				//设置新的首地址，尾地址，链表长度
				FnRevScreenADT_DHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));
				
				free(newNode_iresult);//最后要释放内存
				iresult = true;
			}

		}

	}

	return iresult;

}

/*

//data顺序输出
bool FnFreOptDataStorage_Data(DataStorage* HNode, DataStorage* ENode, ULength Cou,char* order,
	bool (*FnOptNode_Data)(char* title, void* data))

*/

//data输出
bool ScreenOptData(ScreenADT VarScreenADT, char* OrderSLoc, bool (*FnOptNode_Data)(char* title, void* data)) {

	bool iresult = false;

	if (VarScreenADT && OrderSLoc) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength DCou = VarScreenADT->ULDACou;

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength OCou = VarScreenADT->ULORCou;

		//解释SLoc
		ULength iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, DCou, OrderSLoc);

		//取出顺序
		char* order = FnFinObtOrderStorage_LCouO(pHORL, pEORL, OCou, iSLoc);


		//调用函数输出
		iresult = FnFreOptDataStorage_Data(pHDAL, pEDAL, DCou, order, FnOptNode_Data);
	}

	return iresult;
}

//data中SLoc读取标题，读取数据，读取位置

//data SLoc取标题
char* ScreenObtData_Tile(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtDataStorage_LCouT(VarScreenADT->pHDAL, VarScreenADT->pEDAL, VarScreenADT->ULDACou,
		FnFinEvpObtDataStorage_SLoc(VarScreenADT->pHDAL, VarScreenADT->ULDACou, SLoc));

}


//data SLoc取数据
void* ScreenObtData_Data(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtDataStorage_LCouD(VarScreenADT->pHDAL, VarScreenADT->pEDAL, VarScreenADT->ULDACou,
		FnFinEvpObtDataStorage_SLoc(VarScreenADT->pHDAL, VarScreenADT->ULDACou, SLoc));

}

//data SLoc取位置
Length* ScreenObtData_LocCou(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinEvpObtDataStorage_SLoc(VarScreenADT->pHDAL, VarScreenADT->ULDACou, SLoc);

}

//order增加（检验顺序是否正确），删除，交换，SLoc获得标题，顺序


//order增加
bool ScreenAddOrder(ScreenADT VarScreenADT, char* title, void* order, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && title && order && SLoc) {

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength Cou = VarScreenADT->ULORCou;


		ULength iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc);//解释SLoc

		if (iSLoc != -1 && FnFinObtOrderStorage_TLCou(pHORL, Cou, title) == -1 && FnSurObtString_Title(title) && FnExpSurOrderStorage_Order(order)) {

			p_newNodeStorage newNode_iresult = FnCreAddOrderStorage(pHORL, pEORL, Cou, title, order, iSLoc);


			if (newNode_iresult) {  //添加成功
				//设置新的首地址，尾地址，链表长度
				FnRevScreenADT_OHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//最后要释放内存
				iresult = true;
			}

		}

	}

	return iresult;
}

//order删除
bool ScreenDelOrder(ScreenADT VarScreenADT, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && SLoc) {

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength Cou = VarScreenADT->ULORCou;


		ULength iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc);//解释SLoc

		if (iSLoc != -1) {

			p_newNodeStorage newNode_iresult = FnFreDelOrderStorage(pHORL, pEORL, Cou, iSLoc);

			if (newNode_iresult) {  //添加成功
				//设置新的首地址，尾地址，链表长度
				FnRevScreenADT_OHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//最后要释放内存
				iresult = true;
			}

		}

	}

	return iresult;
}

//order交换
bool ScreenMovOrder(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two) {

	bool iresult = false;

	if (VarScreenADT && SLoc_one && SLoc_two) {

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength Cou = VarScreenADT->ULORCou;


		ULength iSLoc_one = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc_one);//解释SLoc_one
		ULength iSLoc_two = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc_two);//解释SLoc_two

		if (iSLoc_one != -1 && iSLoc_two != -1) {

			p_newNodeStorage newNode_iresult = FnFreMovOrderStorage(pHORL, pEORL, Cou, iSLoc_one, iSLoc_two);

			if (newNode_iresult) {  //添加成功
				//设置新的首地址，尾地址，链表长度
				FnRevScreenADT_OHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//最后要释放内存
				iresult = true;
			}

		}

	}

	return iresult;
}

//Order中SLoc读取标题，读取顺序，读取位置


//order SLoc取标题
char* ScreenObtOrder_Tile(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtOrderStorage_LCouT(VarScreenADT->pHORL, VarScreenADT->pEORL, VarScreenADT->ULORCou,
		FnFinEvpObtOrderStorage_SLoc(VarScreenADT->pHORL, VarScreenADT->ULORCou, SLoc));

}

//order SLoc取顺序
void* ScreenObtOrder_Order(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtOrderStorage_LCouO(VarScreenADT->pHORL, VarScreenADT->pEORL, VarScreenADT->ULORCou,
		FnFinEvpObtOrderStorage_SLoc(VarScreenADT->pHORL, VarScreenADT->ULORCou, SLoc));

}

//order SLoc取位置
Length* ScreenObtOrder_LocCou(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinEvpObtOrderStorage_SLoc(VarScreenADT->pHORL, VarScreenADT->ULORCou, SLoc);

}

