
#include "staticscreenadt.h"

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






//--------------------------------------order�ṹ���ʼ����ز���
//�����ڴ桢ֱ���ͷ��ڴ桢��ȫ�ͷ��ڴ桢��ñ��⣬���ݣ���һ���ڵ㣬��һ���ڵ�

//ΪOrderStorage�����µ��ڴ浥Ԫ
OrderStorage FnCreObtOrderStorage(void) {

	return (OrderStorage)malloc(ByteOrderStorage);

}

//�ͷ�OrderStorage���ڴ浥Ԫ
void FnFreOrderStorage(OrderStorage node) {

	return free(node); //free�޷���ֵ
}

//�ͷ�OrderStorage���ڴ浥Ԫ �� title���� �� order˳��
void FnFreOrderStorage_TADOR(OrderStorage node) {


	if (node) {
		FnDelStrCopy(node->title);//�ͷű���
		FnDelStrCopy(node->order);//�ͷ�˳��
		FnFreOrderStorage(node);
	}

	return;
}

//��ȡ��ǰ�ڵ��title����
char* FnObtOrderStorage_Title(OrderStorage node) {

	return node->title;

}
//��ȡ��ǰ�ڵ��order˳��
char* FnObtOrderStorage_Order(OrderStorage node) {

	return node->order;

}
//��ȡ��ǰ�ڵ��previous����һ���ڵ�
OrderStorage FnObtOrderStorage_Previous(OrderStorage node) {

	return node->previous;

}
//��ȡ��ǰ�ڵ��next����һ���ڵ�
OrderStorage FnObtOrderStorage_Next(OrderStorage node) {

	return node->next;

}





//--------------------------------------order�ṹ�����ݵ��޸�
//�����data����һ���ڵ����һ���ڵ㡢��һ���ڵ㡢��һ���ڵ�

//�޸�OrderStorage�ṹ�� �����order˳��ĵ�ַ
void FnRevOrderStorage_TAO(OrderStorage node, char* title, char* order) {

	if (node) {
		node->title = title;
		node->order = order;
	}

	return;
}


//�޸�OrderStorage�ṹ�� ��һ�ڵ㣬����һ���ڵ�ĵ�ַ
void FnRevOrderStorage_Rne(OrderStorage node, OrderStorage previous, OrderStorage next) {

	if (node) {
		node->previous = previous;
		node->next = next;
	}

	return;
}

//�޸�OrderStorage�ṹ�� ��һ�ڵ�ĵ�ַ
void FnRevOrderStorage_Previous(OrderStorage node, OrderStorage previous) {

	if (node) {
		node->previous = previous;
	}

	return;
}

//�޸�OrderStorage�ṹ�� ��һ���ڵ�ĵ�ַ
void FnRevOrderStorage_Next(OrderStorage node, OrderStorage next) {

	if (node) {
		node->next = next;
	}

	return;
}




//--------------------------------------order˫������Ĳ���
//������ɾ��������

/*
���õĴ�����ԭ��
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnCreObtNode)(void), void (FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node));
*/

//��OrderStorage����һ���ڵ�
p_newNodeStorage FnCreAddOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title, char* order, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;

	if (FnSurObtString_Title(title) && FnExpSurOrderStorage_Order(order)) {

		//�����׵�ַ��β��ַ�������ȣ����ӵ�λ�ã��Լ���Ҫ�ĺ���   ����һ���ڵ�
		newNode_iresult = FnCreAddObtNode(pHORL, pEORL, Cou, LocCou,
			FnCreObtOrderStorage, FnRevOrderStorage_Rne,
			FnRevOrderStorage_Previous, FnRevOrderStorage_Next,
			FnObtOrderStorage_Previous, FnObtOrderStorage_Next);

		if (newNode_iresult) {
			FnRevOrderStorage_TAO(FnObtnewNodeStorage_Newnode(newNode_iresult), FnCreObtStrCopy(title), FnCreObtStrCopy(order)); //����һ������
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

//��OrderStorage����ɾ��һ���ڵ�
p_newNodeStorage FnFreDelOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, Length LocCou) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHORL && pEORL && Cou && (LocCou >= 0 && LocCou < Cou || LocCou == _END_)) {   //ɾ���Ľڵ�λ�ò���ȷ

		//�����׵�ַ��β��ַ�������ȣ�ɾ����λ�ã�ɾ��һ���ڵ�
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

//����OrderStorage�ṹ���������ڵ��λ��
p_newNodeStorage FnFreMovOrderStorage(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, ULength LocCou_one, ULength LocCou_two) {

	p_newNodeStorage newNode_iresult = NULL;

	if (pHORL && pEORL && Cou >= 2 && (LocCou_one >= 0 && LocCou_one < Cou && LocCou_two >= 0 && LocCou_two < Cou)) {//�ж�����λ���Ƿ����

		//�����׵�ַ��β��ַ�������ȣ�Ҫ���������ڵ��λ�ã����������ڵ�
		newNode_iresult = FnFreMovNode(pHORL, pEORL, Cou, LocCou_one, LocCou_two,
			FnCreObtOrderStorage, FnFreOrderStorage, FnRevOrderStorage_Rne,
			FnRevOrderStorage_Previous, FnRevOrderStorage_Next,
			FnObtOrderStorage_Previous, FnObtOrderStorage_Next);


	}

	return newNode_iresult;
}




//--------------------------------------order˫����������ݶ�ȡ
//�����ȡλ�ã������ȡ���ݣ�λ�ö�ȡ���⣬λ�ö�ȡ����

/*

struct OrderStorage {

	char* title;
	char* order;
	struct OrderStorage* previous;
	struct OrderStorage* next;
	
};

*/

//ͨ�������ȡλ��
//���ڷ���λ�ã������ڷ���-1
Length FnFinObtOrderStorage_TLCou(OrderStorage pHORL, ULength Cou, char* title) {

	Length iresult = 0;

	if (!(pHORL && FnSurObtString_Title(title) && Cou >= 1)) {   //�����Ƿ���Ϲ淶�������Ƿ����0���׵�ַ�Ƿ����

		iresult = -1;


	}

	if (!iresult) {  //�����������

		OrderStorage node = pHORL;

		ULength i;  //������

		//��ǰλ��С�ڳ��ȣ��ڵ�û�е�ĩβ������δ�ҵ�
		for (i = 0; node && i < Cou && strcmp(title, FnObtOrderStorage_Title(node)); i++) {

			node = FnObtOrderStorage_Next(node);

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

//ͨ�������ȡ˳��
char* FnFinObtOrderStorage_TORDER(OrderStorage pHORL, OrderStorage pEORL, ULength Cou, char* title) {

	//���ú���ͨ�������ȡλ�ã���ͨ��λ�ö�ȡ˳��
	return FnFinObtOrderStorage_LCouO(pHORL, pEORL, Cou, FnFinObtOrderStorage_TLCou(pHORL, Cou, title));

}

//ͨ��λ�ö�ȡ����
//�ҵ��˾������ݵĵ�ַ��û�ҵ�����NULL;
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

//�����׽ڵ㣬β�ڵ㣬�����ȣ�������ǰ�浽�����LocCou��
//��ȡ�ڵ����һ����ַ������һ����ַ������������������  FnObtNode_previous  FnObtNode_next ����ϣ�������
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node))

*/

//ͨ��λ�ö�ȡ˳��
//�ҵ��˾���˳���ַ��û�ҵ�����NULL;
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


//--------------------------------------order�����SLoc����

//OrderStorage����SLoc,������ת��Ϊλ�ã���λ���ַ���ת��Ϊ����λ��,��ȷ����λ�ã����󷵻�-1
Length FnFinEvpObtOrderStorage_SLoc(OrderStorage pHORL, ULength Cou, char* SLoc) {
	
	Length iresult = -1;

	if (SLoc) {

		iresult = FnSurObtString_TLoc(SLoc);

		if (iresult == 0 && pHORL && Cou >= 1) {   //���ͱ���

			iresult = FnFinObtOrderStorage_TLCou(pHORL, Cou, SLoc);

		}
		else if (iresult == 1) {   //����λ��

			iresult = atoll(SLoc);

		}
	}

	
	return iresult;
}

//--------------------------------------order�����˳���жϺͽ���

//�ж�order˳���Ƿ���ȷ
bool FnExpSurOrderStorage_Order(char* order) {

	bool iresult = false;

	if (order) {

		Length order_len = strlen(order);

		if (order_len >= 3) {

			if (*order == '|') { //�жϵ�һ���Ƿ�Ϊ|��ͷ

				char* SLoc = NULL;

				int Cou = 0; //ͳ��SLoc�ĳ���
				int LocCou = 1;//�ʼ��λ��

				for (int i = 1; i < order_len; i++) { //��ʼ��֤


					if (*(order + i) != '|') {
						Cou++;
					}
					else {

						if (Cou >= 1) {  //SLoc���ȡ�1

							SLoc = FnCreFinObtCopy(order, LocCou, Cou); //���SLoc

							//�ж�SLoc�Ƿ���ȷ
							if (!FnSurObtString_SLoc(SLoc)) {  //����ȷ


								//�ͷ�SLoc
								FnDelStrCopy(SLoc);
								//iresult = false;
								break;

							}

							//SLoc��ȷ

							//�ͷ�SLoc
							FnDelStrCopy(SLoc);


							if (i + 1 == order_len) {//����ĩβ����Ҫ��ȫ

								iresult = true;
								break;

							}
							else if (i + 2 == order_len && *(order + i) == '|') {  //����ĩβ������Ҫ��ȫ��

								iresult = true;
								break;

							}
							else if (i + 2 == order_len) {  //����ĩβ�����ǳ���������


								//iresult = false;
								break;
							}
							else {  //����

								Cou = 0;  //����������Ϊ0
								LocCou = i + 1; //����������ʼλ��
							}

						}
						else { //��������  SLoc�ĳ���Ϊ0�����ⲻ����

							//iresult = false;
							break;

						}

					}


				}

			}
			else { //��ͷ���ԣ�����|
				;
				//iresult = false;

			}

		}

	}

	return iresult;
}

//����˳��,��λ��װ�������У�
ULength* FnExpFinObtOrderStorage_Order(char* order, OrderStorage pHORL, ULength Cou) {

	int iorder_len = 2;
	ULength* iorder = (ULength*)malloc((sizeof(ULength) * iorder_len));
	iorder[0] = 2;  //����Ϊ2
	iorder[1] = -1; //����ʧ��

	//��һ������������ĳ��ȣ��ڶ������ж���Ϣ��-1Ϊ����ʧ�ܣ����ִ���0Ϊ����Ҫ��ȫ��1Ϊ��Ҫ��ȫ���ӵ�������ʼ���˳��

	if (order && pHORL && Cou >= 1) {

		Length order_len = strlen(order);
		iorder[0] = 2;  //����Ϊ2
		iorder[1] = -1; //����ʧ��

		if (iorder && order_len >= 3) {

			if (*order == '|') { //�жϵ�һ���Ƿ�Ϊ|��ͷ

				char* SLoc = NULL;

				int Cou = 0; //ͳ��SLoc�ĳ���
				int LocCou = 1;//�ʼ��λ��
				//int SLoc_len = 0; //SLoc_len�ĳ���

				for (int i = 1; i < order_len; i++) { //��ʼ��֤


					if (*(order + i) != '|') {
						Cou++;
					}
					else {

						if (Cou >= 1) {  //SLoc���ȡ�1

							SLoc = FnCreFinObtCopy(order, LocCou, Cou); //���SLoc

							//�ж�SLoc�Ƿ���ȷ
							if (!FnSurObtString_SLoc(SLoc)) {  //����ȷ


								//�ͷ�SLoc
								FnDelStrCopy(SLoc);
								//iresult = false;
								break;

							}

							//SLoc��ȷ


							//����SLoc
							int iSLoc = FnFinEvpObtOrderStorage_SLoc(pHORL, Cou, SLoc);

							if (iSLoc == -1) {

								//������
								iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //��С�ռ�
								iorder[0] = 2;  //����Ϊ2
								iorder[1] = -1; //����ʧ��
								break;
							}

							//���ڣ�SLoc ����+1
							//SLoc_len++;
							iorder_len++;

							//����Ҫ���صĵط�
							iorder = (ULength*)realloc(iorder, (sizeof(ULength) * iorder_len));  //�ӿ�һ�¿ռ�
							if (iorder) {
								iorder[0]++;  //��������
								iorder[iorder_len - 1] = iSLoc;
							}
							else {
								break;
							}
							

							//�ͷ�SLoc
							FnDelStrCopy(SLoc);


							if (i + 1 == order_len) {//����ĩβ����Ҫ��ȫ

								iorder[1] = 1; //��Ҫ��ȫ
								//iresult = true;
								break;

							}
							else if (i + 2 == order_len && *(order + i + 1) == '|') {  //����ĩβ������Ҫ��ȫ��

								iorder[1] = 0; //����Ҫ��ȫ
								//iresult = true;
								break;

							}
							else if (i + 2 == order_len) {  //����ĩβ�����ǳ���������

								iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //��С�ռ�
								iorder[0] = 2;  //����Ϊ2
								iorder[1] = -1; //����ʧ��
								//iresult = false;
								break;
							}
							else {  //����

								Cou = 0;  //����������Ϊ0
								LocCou = i + 1; //����������ʼλ��
							}

						}
						else { //��������  SLoc�ĳ���Ϊ0�����ⲻ����

							iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //��С�ռ�
							iorder[0] = 2;  //����Ϊ2
							iorder[1] = -1; //����ʧ��
							break;

						}

					}


				}

				if (iorder[1] == -1) {

					iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //��С�ռ�
					iorder[0] = 2;  //����Ϊ2
					iorder[1] = -1; //����ʧ��

				}


			}
			else { //��ͷ���ԣ�����|
				;
			//iorder = (ULength*)realloc(iorder, (sizeof(ULength) * 2));  //��С�ռ�
			//iorder[0] = 2;  //����Ϊ2
			//iorder[1] = -1; //����ʧ��
				//iresult = false;

			}

		}

	}

	return iorder;

}