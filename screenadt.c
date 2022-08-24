
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








//--------------------------------��ʼ������
//��ʼ����������
//�����ڴ浥Ԫ


//��ʼ��ScreenADT ������������
ScreenADT IniScreenADT(void) {

	/*
	���������void
	����ֵ��ָ�����
	����ɹ����׵�ַ
	����ʧ�ܣ�NULL
	*/

	ScreenADT VarScreenADT = FnCreObtScreenADT(); //�����ڴ浥Ԫ

	if (VarScreenADT) {  //����ɹ�

		VarScreenADT->pHDAL = NULL;
		VarScreenADT->pEDAL = NULL;
		VarScreenADT->ULDACou = 0;
		VarScreenADT->pHORL = NULL;
		VarScreenADT->pEORL = NULL;
		VarScreenADT->ULORCou = 0;

	}

	return VarScreenADT;
}

//ΪScreenADT �����ڴ浥Ԫ
ScreenADT FnCreObtScreenADT(void) {

	return (ScreenADT)malloc(ByteScreenADT);  //�����ڴ浥Ԫ

}




//--------------------------------�ṹ�����޸Ĳ���

//�޸�ScreenADT�ṹ�� data�׵�ַ β��ַ ����
void FnRevScreenADT_DHECou(ScreenADT VarScreenADT, DataStorage pHDAL, DataStorage pEDAL, ULength ULDACou) {


	if (VarScreenADT) {

		VarScreenADT->pHDAL = pHDAL;
		VarScreenADT->pEDAL = pEDAL;
		VarScreenADT->ULDACou = ULDACou;
	}

	return;
}

//�޸�ScreenADT�ṹ�� order�׵�ַ β��ַ ����
void FnRevScreenADT_OHECou(ScreenADT VarScreenADT, OrderStorage pHDAL, OrderStorage pEDAL, ULength ULORCou) {


	if (VarScreenADT) {

		VarScreenADT->pHORL = pHDAL;
		VarScreenADT->pEORL = pEDAL;
		VarScreenADT->ULORCou = ULORCou;
	}

	return;
}

 //����data�׵�ַ
void* FnObtScrA_pHDAL(ScreenADT VarScreenADT) {

	return VarScreenADT->pHDAL;

}
//����dataβ��ַ
void* FnObtScrA_pEDAL(ScreenADT VarScreenADT) {  

	return VarScreenADT->pEDAL;

}
//����data������
void* FnObtScrA_ULDACou(ScreenADT VarScreenADT) {  

	return VarScreenADT->ULDACou;

}
//����order�׵�ַ
void* FnObtScrA_pHORL(ScreenADT VarScreenADT) {  

	return VarScreenADT->pHORL;

}
//����orderβ��ַ
void* FnObtScrA_pEORL(ScreenADT VarScreenADT) {  

	return VarScreenADT->pEORL;

}
//����order������
void* FnObtScrA_ULORCou(ScreenADT VarScreenADT) {  

	return VarScreenADT->ULORCou;

}





//--------------------------------����������������������Ĳ���
//data���ӣ�ɾ����������SLoc��ñ��⣬���ݣ����������˳�򣬰���˳�����

//data����
bool ScreenAddData(ScreenADT VarScreenADT, char* title, void* data, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && title && SLoc) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength Cou = VarScreenADT->ULDACou;


		ULength iSLoc = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc);//����SLoc

		//���ⲻ���ظ�
		if (iSLoc != -1 && FnFinObtDataStorage_TLCou(pHDAL, Cou, title) == -1 && FnSurObtString_Title(title)) {

			p_newNodeStorage newNode_iresult = FnCreAddDataStorage(pHDAL, pEDAL, Cou, title, data, iSLoc);

			if (newNode_iresult) {  //��ӳɹ�
				//�����µ��׵�ַ��β��ַ��������
				FnRevScreenADT_DHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//���Ҫ�ͷ��ڴ�

				iresult = true;
			}

		}

	}

	return iresult;
}

//dataɾ��
bool ScreenDelData(ScreenADT VarScreenADT, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && SLoc) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength Cou = VarScreenADT->ULDACou;


		ULength iSLoc = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc);//����SLoc

		if (iSLoc != -1) {

			p_newNodeStorage newNode_iresult = FnFreDelDataStorage(pHDAL, pEDAL, Cou, iSLoc);

			if (newNode_iresult) {  //ɾ���ɹ�
				//�����µ��׵�ַ��β��ַ��������
				FnRevScreenADT_DHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//���Ҫ�ͷ��ڴ�
				iresult = true;
			}

		}

	}

	return iresult;

}

//data����
bool ScreenMovData(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two) {

	bool iresult = false;

	if (VarScreenADT && SLoc_one && SLoc_two) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength Cou = VarScreenADT->ULDACou;


		ULength iSLoc_one = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc_one);//����SLoc_one
		ULength iSLoc_two = FnFinEvpObtDataStorage_SLoc(pHDAL, Cou, SLoc_two);//����SLoc_two

		if (iSLoc_one != -1 && iSLoc_two != -1 && iSLoc_one != iSLoc_two) {

			p_newNodeStorage newNode_iresult = FnFreMovDataStorage(pHDAL, pEDAL, Cou, iSLoc_one, iSLoc_two);

			if (newNode_iresult) {  //�����ɹ�
				//�����µ��׵�ַ��β��ַ��������
				FnRevScreenADT_DHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));
				
				free(newNode_iresult);//���Ҫ�ͷ��ڴ�
				iresult = true;
			}

		}

	}

	return iresult;

}

/*

//data˳�����
bool FnFreOptDataStorage_Data(DataStorage* HNode, DataStorage* ENode, ULength Cou,char* order,
	bool (*FnOptNode_Data)(char* title, void* data))

*/

//data���
bool ScreenOptData(ScreenADT VarScreenADT, char* OrderSLoc, bool (*FnOptNode_Data)(char* title, void* data)) {

	bool iresult = false;

	if (VarScreenADT && OrderSLoc) {

		DataStorage pHDAL = VarScreenADT->pHDAL;
		DataStorage pEDAL = VarScreenADT->pEDAL;
		ULength DCou = VarScreenADT->ULDACou;

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength OCou = VarScreenADT->ULORCou;

		//����SLoc
		ULength iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, DCou, OrderSLoc);

		//ȡ��˳��
		char* order = FnFinObtOrderStorage_LCouO(pHORL, pEORL, OCou, iSLoc);


		//���ú������
		iresult = FnFreOptDataStorage_Data(pHDAL, pEDAL, DCou, order, FnOptNode_Data);
	}

	return iresult;
}

//data��SLoc��ȡ���⣬��ȡ���ݣ���ȡλ��

//data SLocȡ����
char* ScreenObtData_Tile(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtDataStorage_LCouT(VarScreenADT->pHDAL, VarScreenADT->pEDAL, VarScreenADT->ULDACou,
		FnFinEvpObtDataStorage_SLoc(VarScreenADT->pHDAL, VarScreenADT->ULDACou, SLoc));

}


//data SLocȡ����
void* ScreenObtData_Data(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtDataStorage_LCouD(VarScreenADT->pHDAL, VarScreenADT->pEDAL, VarScreenADT->ULDACou,
		FnFinEvpObtDataStorage_SLoc(VarScreenADT->pHDAL, VarScreenADT->ULDACou, SLoc));

}

//data SLocȡλ��
Length* ScreenObtData_LocCou(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinEvpObtDataStorage_SLoc(VarScreenADT->pHDAL, VarScreenADT->ULDACou, SLoc);

}

//order���ӣ�����˳���Ƿ���ȷ����ɾ����������SLoc��ñ��⣬˳��


//order����
bool ScreenAddOrder(ScreenADT VarScreenADT, char* title, void* order, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && title && order && SLoc) {

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength Cou = VarScreenADT->ULORCou;


		ULength iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc);//����SLoc

		if (iSLoc != -1 && FnFinObtOrderStorage_TLCou(pHORL, Cou, title) == -1 && FnSurObtString_Title(title) && FnExpSurOrderStorage_Order(order)) {

			p_newNodeStorage newNode_iresult = FnCreAddOrderStorage(pHORL, pEORL, Cou, title, order, iSLoc);


			if (newNode_iresult) {  //��ӳɹ�
				//�����µ��׵�ַ��β��ַ��������
				FnRevScreenADT_OHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//���Ҫ�ͷ��ڴ�
				iresult = true;
			}

		}

	}

	return iresult;
}

//orderɾ��
bool ScreenDelOrder(ScreenADT VarScreenADT, char* SLoc) {

	bool iresult = false;

	if (VarScreenADT && SLoc) {

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength Cou = VarScreenADT->ULORCou;


		ULength iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc);//����SLoc

		if (iSLoc != -1) {

			p_newNodeStorage newNode_iresult = FnFreDelOrderStorage(pHORL, pEORL, Cou, iSLoc);

			if (newNode_iresult) {  //��ӳɹ�
				//�����µ��׵�ַ��β��ַ��������
				FnRevScreenADT_OHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//���Ҫ�ͷ��ڴ�
				iresult = true;
			}

		}

	}

	return iresult;
}

//order����
bool ScreenMovOrder(ScreenADT VarScreenADT, char* SLoc_one, char* SLoc_two) {

	bool iresult = false;

	if (VarScreenADT && SLoc_one && SLoc_two) {

		OrderStorage pHORL = VarScreenADT->pHORL;
		OrderStorage pEORL = VarScreenADT->pEORL;
		ULength Cou = VarScreenADT->ULORCou;


		ULength iSLoc_one = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc_one);//����SLoc_one
		ULength iSLoc_two = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc_two);//����SLoc_two

		if (iSLoc_one != -1 && iSLoc_two != -1) {

			p_newNodeStorage newNode_iresult = FnFreMovOrderStorage(pHORL, pEORL, Cou, iSLoc_one, iSLoc_two);

			if (newNode_iresult) {  //��ӳɹ�
				//�����µ��׵�ַ��β��ַ��������
				FnRevScreenADT_OHECou(VarScreenADT, FnObtnewNodeStorage_NewHNode(newNode_iresult),
					FnObtnewNodeStorage_NewENode(newNode_iresult),
					FnObtnewNodeStorage_NewCou(newNode_iresult));

				free(newNode_iresult);//���Ҫ�ͷ��ڴ�
				iresult = true;
			}

		}

	}

	return iresult;
}

//Order��SLoc��ȡ���⣬��ȡ˳�򣬶�ȡλ��


//order SLocȡ����
char* ScreenObtOrder_Tile(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtOrderStorage_LCouT(VarScreenADT->pHORL, VarScreenADT->pEORL, VarScreenADT->ULORCou,
		FnFinEvpObtOrderStorage_SLoc(VarScreenADT->pHORL, VarScreenADT->ULORCou, SLoc));

}

//order SLocȡ˳��
void* ScreenObtOrder_Order(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinObtOrderStorage_LCouO(VarScreenADT->pHORL, VarScreenADT->pEORL, VarScreenADT->ULORCou,
		FnFinEvpObtOrderStorage_SLoc(VarScreenADT->pHORL, VarScreenADT->ULORCou, SLoc));

}

//order SLocȡλ��
Length* ScreenObtOrder_LocCou(ScreenADT VarScreenADT, char* SLoc) {

	return FnFinEvpObtOrderStorage_SLoc(VarScreenADT->pHORL, VarScreenADT->ULORCou, SLoc);

}

