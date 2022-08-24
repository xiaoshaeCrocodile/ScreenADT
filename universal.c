
#include "staticscreenadt.h"


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



//----------------------------------˫��������
//������ɾ����������˳�����


//���������׵�ַ��β��ַ�����ȣ����������λ��
//����Ҫ��������ָ��
//1.���ڴ�ռ��з���һ���µĽڵ㣬�����½ڵ�ĵ�ַ  FnCreObtNode   ���������䣩�����ؽڵ�
//2.���ýڵ����һ����ַ����һ����ַ���ϼ���    FnAddNode_Rne �޸��Ϻ���һ����ַ
//3.���ýڵ����һ����ַ������һ����ַ������������������  FnAddNode_previous   FnAddNode_next  �޸��ϣ�������
//4.��ȡ�ڵ����һ����ַ������һ����ַ������������������  FnObtNode_previous  FnObtNode_next ����ϣ�������
//����һ���ṹ��ָ��
//�µ��׵�ַ��β��ַ�����ȣ����½ڵ�ĵ�ַ����װ��һ���ṹ���У�ͨ�������ĵ��÷ֱ���
//�������ʧ�ܣ�����NULL
p_newNodeStorage FnCreAddObtNode(void* HNode, void* ENode, ULength Cou, Length LocCou, //����������һ���ڵ㣬ͨ��
	void* (*FnCreObtNode)(void), void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node)) {

	void* iresult = (int)NULL + 1;


	//�����жϴ�������Ƿ���ȷ
	if (HNode == NULL && ENode == NULL) {// �׵�ַ��β��ַΪ�գ���ʾ����һ��������

		//�������һ����������ô���ȿ϶���0���½ڵ�λ��ֻ�����ײ�����β��
		if (!(Cou == 0 && (LocCou == _HEAD_ || LocCou == _END_))) {
			iresult = NULL;
		}
		else if (LocCou == _END_) {  //������������ӣ���������Ϊ0(�ϸ�if�Ѿ��ж�)���Ͳ�ͬ�����
			LocCou = _HEAD_;
		}


	}
	else if (HNode != NULL && ENode != NULL) { //�����������Ϊ�գ���ô��ⳤ�ȣ����½ڵ��λ��



		//����ⲻ��һ�����������ȿ϶�����0���½ڵ��λ����0������֮��
		if (!(Cou >= 1 && (LocCou >= 0 && LocCou <= Cou || LocCou == _END_))) {
			iresult = NULL;
		}
		else if (LocCou == Cou) {

			LocCou = _END_;

		}

	}
	else {// ����֮�⣬�����е��������
		iresult = NULL;
	}

	if (iresult) {  //����Ĳ���û�����⣬�ж�����һ�����

		void* newnode;  //�½ڵ�
		void* newHNode; //���׵�ַ
		void* newENode;  //��β��ַ
		ULength newCou;  //�³���

		newnode = FnCreObtNode(); //���һ���µĽڵ�

		if (!newnode) { //����ʧ��
			iresult = NULL;
		}
		else {  //����ɹ�


			if (LocCou == _HEAD_) {// ����ǰ�����

				if (Cou == 0) {  //����������һ���ڵ㣬�׵�ַβ��ַ�½ڵ��ַ��һ��������Ϊ0+1


					FnRevNode_Rne(newnode, NULL, NULL);  //�½ڵ��ǰһ���ͺ�һ���ڵ�����Ϊ�գ�����ĵ�һ���ڵ�

					newHNode = newENode = newnode;  //���׺�β�ڵ㣬����Ϊ�½ڵ㣬����ֻ��һ���ڵ�
				}
				else { //����Ϊ��


					FnRevNode_Rne(newnode, NULL, HNode);  //��һ��Ϊ�գ���Ϊ���ף���һ��Ϊ���׽ڵ�
					FnRevNode_Previous(HNode, newnode);
					//�����׽ڵ��ƶ����ڶ�������������һ���ڵ��NULL��Ϊ���½ڵ�



					newHNode = newnode;  //�׽ڵ���Ϊ�½ڵ��ַ����Ϊ�������
					newENode = ENode;  //β�ڵ㲻��
				}



			}
			else if (LocCou == _END_) { //����������   ����϶���Ϊ��


				FnRevNode_Rne(newnode, ENode, NULL);  //��һ��Ϊ�գ���Ϊ��β�ڵ㣬��һ��Ϊ��β�ڵ�
				FnRevNode_Next(ENode, newnode);
				//����β�ڵ��ƶ���-1������������һ���ڵ��NULL��Ϊ���½ڵ�


				newHNode = HNode;  //�׽ڵ㲻��
				newENode = newnode;  //β�ڵ���Ϊ�½ڵ��ַ����Ϊ��β�����

			}
			else { //���м����


				void* LocCounode = FnSeaObtCouNode(HNode, ENode, Cou, LocCou, FnObtNode_Previous, FnObtNode_Next);
				//�����������У��ҵ���һ���ڵ�

				//�����µĽڵ㣬��һ������һ��,��һ��Ϊԭ�ڵ����һ������һ��Ϊԭ�ڵ�
				FnRevNode_Rne(newnode, FnObtNode_Previous(LocCounode), LocCounode);
				//����ԭ�ڵ���һ��������һ����Ϊ�½ڵ�
				FnRevNode_Next(FnObtNode_Previous(LocCounode), newnode);
				//����ԭ�ڵ����һ����Ϊ�½ڵ�
				FnRevNode_Previous(LocCounode, newnode);



				newHNode = HNode;  //�׽ڵ㲻��
				newENode = ENode;  //β�ڵ㲻��


			}



			newCou = Cou + 1;  //������+1
			iresult = FnCreObtnewNodeStorage();  //�����ڴ�
			FnRevnewNode_Storage(iresult, newnode, newHNode, newENode, newCou);  //���ڵ�ͳ��ȷ���
		}


	}

	return iresult;

}

//���������׵�ַ��β��ַ�����ȣ�ɾ���ڵ��λ��
//����Ҫ��������ָ��
//3.���ýڵ����һ����ַ������һ����ַ������������������  FnAddNode_previous   FnAddNode_next  �޸��ϣ�������
//4.��ȡ�ڵ����һ����ַ������һ����ַ������������������  FnObtNode_previous  FnObtNode_next ����ϣ�������
//����һ���ṹ��ָ��
//�µ��׵�ַ��β��ַ�����ȣ���װ��һ���ṹ���У�ͨ�������ĵ��÷ֱ���
//���ɾ��ʧ�ܣ�����NULL
//FnFreNode  ��Ҫɾ���Ľڵ�����ȥ���ɸú��������ͷ��ڴ�
p_newNodeStorage FnFreDelNode(void* HNode, void* ENode, ULength Cou, Length LocCou,//ɾ��˫�������е�һ���ڵ�
	void (*FnFreNode)(void* node),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node)) {

	void* iresult = (int)NULL + 1;

	//�����жϴ�������Ƿ���ȷ
	if (HNode == NULL || ENode == NULL) {// �׵�ַ��β��ַΪ�գ���ô�����������

		iresult = NULL;

	}
	else if (HNode != NULL && ENode != NULL) { //�����������Ϊ�գ���ô��ⳤ��

		//����ⲻ��һ�����������ȿ϶�����0���½ڵ��λ����0������֮��
		if (!(Cou > 0 && (LocCou >= 0 && LocCou < Cou || LocCou == _END_))) {
			iresult = NULL;
		}


		if (LocCou == Cou - 1) {  //���ѡ�����β��ַ

			LocCou = _END_;   //����Ϊβ��ַ

		}

		if (LocCou == _END_ && Cou == 1) {  //���ѡ�����β��ַ����ֻʣ�������һ��
			LocCou = _HEAD_;   //��Ϊ�׵�ַ

		}



	}
	else {// ����֮�⣬�����е��������
		iresult = NULL;
	}

	if (iresult) {

		void* newnode = NULL;  //�½ڵ�
		void* newHNode; //���׵�ַ
		void* newENode;  //��β��ַ
		ULength newCou;  //�³���

		if (LocCou == _HEAD_) {// ɾ���׽ڵ�


			if (Cou == 1) {   //ֻʣ��һ���ڵ���



				newHNode = NULL;   //ɶ��û���ˣ���β��ΪNULL
				newENode = NULL;

				FnFreNode(HNode);//ɾ���ڵ�
			}
			else {


				newHNode = FnObtNode_Next(HNode);   //�׽ڵ��Ϊ���׽ڵ����һ��
				newENode = ENode;   //β�ڵ㲻��

				FnRevNode_Previous(FnObtNode_Next(HNode), NULL); //�����׽ڵ����һ���ڵ㣬����һ���ڵ���ΪNULL

				FnFreNode(HNode);  //ɾ���ڵ�
			}

		}
		else if (LocCou == _END_) {   //ɾ��β�ڵ�Ļ����ڵ������϶�����1



			newHNode = HNode;   //�׽ڵ㲻��
			newENode = FnObtNode_Previous(ENode);   //��β�ڵ��Ϊ��β�ڵ����һ��

			FnRevNode_Next(FnObtNode_Previous(ENode), NULL);//���þ�β�ڵ����һ������һ��Ϊ�գ���һ������

			FnFreNode(ENode);  //ɾ���ڵ�
		}
		else {  //�ڵ��������ڵ���3

			newHNode = HNode;   //�׽ڵ㲻��
			newENode = ENode;   //β�ڵ㲻��

			void* LocCounode = FnSeaObtCouNode(HNode, ENode, Cou, LocCou, FnObtNode_Previous, FnObtNode_Next);
			//�����������У��ҵ���һ���ڵ�

			//����Ҫɾ���ڵ����һ��������һ�������Ҫɾ���ڵ����һ��
			FnRevNode_Next(FnObtNode_Previous(LocCounode), FnObtNode_Next(LocCounode));
			//����Ҫɾ���ڵ����һ��������һ�������Ҫɾ���ڵ����һ��
			FnRevNode_Previous(FnObtNode_Next(LocCounode), FnObtNode_Previous(LocCounode));

			FnFreNode(LocCounode);  //ɾ���ڵ�
		}

		newCou = Cou - 1;  //������+1
		iresult = FnCreObtnewNodeStorage();  //�����ڴ�
		FnRevnewNode_Storage(iresult, newnode, newHNode, newENode, newCou);  //���ڵ�ͳ��ȷ���

	}

	return iresult;

}

//���������׵�ַ��β��ַ�����ȣ�Ҫ���������ڵ��λ��
//����Ҫ��������ָ��
// //1.���ڴ�ռ��з���һ���µĽڵ㣬�����½ڵ�ĵ�ַ  FnCreObtNode   ���������䣩�����ؽڵ�
// //2.���ýڵ����һ����ַ����һ����ַ���ϼ���    FnAddNode_Rne �޸��Ϻ���һ����ַ
//3.���ýڵ����һ����ַ������һ����ַ������������������  FnAddNode_previous   FnAddNode_next  �޸��ϣ�������
//4.��ȡ�ڵ����һ����ַ������һ����ַ������������������  FnObtNode_previous  FnObtNode_next ����ϣ�������
//FnFreNode_Dir  ��Ҫɾ���Ľڵ�����ȥ���ɸú��������ͷ��ڴ�,ֱ���ͷ��ڴ棬����������
//�ɹ�����1 ʧ�ܷ���0
p_newNodeStorage FnFreMovNode(void* HNode, void* ENode, ULength Cou, ULength LocCou_one, ULength LocCou_two,
	void* (*FnCreObtNode)(void), void (*FnFreNode_Dir)(void* node),
	void (*FnRevNode_Rne)(void* node, void* previous, void* next),
	void (*FnRevNode_Previous)(void* node, void* previous), void (*FnRevNode_Next)(void* node, void* next),
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node)) {



	p_newNodeStorage iresult = (void*)1;  //λ�ò���ͬһ��

	if (!(LocCou_one != LocCou_two) || !(LocCou_one >= 0 && LocCou_one < Cou && LocCou_two >= 0 && LocCou_two)) {//�ж�����λ���Ƿ����
		iresult = NULL;
	}

	if (iresult) { //����λ�ö����ڣ��Ҳ�ͬ

		if (LocCou_one > LocCou_two) {
			ULength tmp = LocCou_one;
			LocCou_one = LocCou_two;
			LocCou_two = tmp;

		}

		void* node_one = FnSeaObtCouNode(HNode, ENode, Cou, LocCou_one, FnObtNode_Previous, FnObtNode_Next);
		void* node_two = FnSeaObtCouNode(HNode, ENode, Cou, LocCou_two, FnObtNode_Previous, FnObtNode_Next);

		void* newnode = NULL;  //�½ڵ�
		void* newHNode; //���׵�ַ
		void* newENode;  //��β��ַ
		ULength newCou = 0;  //�³���


		if (LocCou_one == 0 && LocCou_two == Cou - 1) {   //ͷβ����


			if (LocCou_two - LocCou_one > 1) {  //ͷβ���� �м�������Ľڵ�


				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);

				void* tmpnode = FnCreObtNode(); //���һ���µĽڵ�
				if (tmpnode) {   //ͨ��һ���½ڵ㣬���������ڵ�
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //��β�������м�û�м��

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//�����µ���β
			newHNode = node_two;
			newENode = node_one;

		}
		else if (LocCou_one == 0) {  //ͷ �м佻��



			if (LocCou_two - LocCou_one > 1) {  //ͷ �м佻�� �м�������Ľڵ�

				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);
				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				void* tmpnode = FnCreObtNode(); //���һ���µĽڵ�
				if (tmpnode) {   //ͨ��һ���½ڵ㣬���������ڵ�
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //ͷ �м佻�����м�û�м��

				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//�����µ���β
			newHNode = node_two;
			newENode = ENode;

		}
		else if (LocCou_two == Cou - 1) {  //β �м佻��



			if (LocCou_two - LocCou_one > 1) {  //ͷ �м佻�� �м�������Ľڵ�

				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);
				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);


				void* tmpnode = FnCreObtNode(); //���һ���µĽڵ�
				if (tmpnode) {   //ͨ��һ���½ڵ㣬���������ڵ�
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //ͷ �м佻�����м�û�м��

				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//�����µ���β
			newHNode = HNode;
			newENode = node_one;

		}
		else {  //�м���м佻��


			if (LocCou_two - LocCou_one > 1) {  //ͷ �м佻�� �м�������Ľڵ�


				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);
				FnRevNode_Previous(FnObtNode_Next(node_one), node_two);
				FnRevNode_Next(FnObtNode_Previous(node_two), node_one);
				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				void* tmpnode = FnCreObtNode(); //���һ���µĽڵ�
				if (tmpnode) {   //ͨ��һ���½ڵ㣬���������ڵ�
					FnRevNode_Rne(tmpnode, FnObtNode_Previous(node_one), FnObtNode_Next(node_one));
					FnRevNode_Rne(node_one, FnObtNode_Previous(node_two), FnObtNode_Next(node_two));
					FnRevNode_Rne(node_two, FnObtNode_Previous(tmpnode), FnObtNode_Next(tmpnode));
					FnFreNode_Dir(tmpnode);
				}
				else {
					iresult = NULL;
				}


			}
			else {  //ͷ �м佻�����м�û�м��

				FnRevNode_Next(FnObtNode_Previous(node_one), node_two);
				FnRevNode_Previous(FnObtNode_Next(node_two), node_one);

				FnRevNode_Rne(node_one, node_two, FnObtNode_Next(node_two));
				FnRevNode_Rne(node_two, FnObtNode_Previous(node_one), node_one);

			}

			//�����µ���β
			newHNode = HNode;
			newENode = ENode;

		}

		if (iresult) {

			iresult = FnCreObtnewNodeStorage();  //�����ڴ�
			FnRevnewNode_Storage(iresult, newnode, newHNode, newENode, newCou);  //���ڵ�ͳ��ȷ���

		}


	}

	return iresult;
}

//˳����������е�����
//���룬�׵�ַ��β��ַ�������ȣ�˳�����鳤�ȣ�˳�����飬�Ƿ���Ҫ��ȫ
//��һ����ַ��������һ����ַ������������ݺ�����������ݺ���
bool FnFreOptNode_Data(void* HNode, void* ENode, ULength Cou, ULength LocCou_Len, ULength* LocCou, bool Com,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_Next)(void* node),
	void* (*FnObtNode_Title)(void* node), void* (*FnObtNode_Data)(void* node), bool (*FnOptNode_Data)(char* title, void* data)) {

	bool iresult = false;

	if (HNode && ENode && Cou >= 1 && LocCou_Len >= 1 && LocCou) {//�������Ƿ���ȷ

		//�����������
		int i;
		//��ǰλ��
		ULength Cur = 0;
		//��ǰ�ڵ�
		void* Curnode = HNode;

		for (i = 0; i < LocCou_Len; i++) {


			//���λ��ÿһ��˳��
			ULength iLocCou = LocCou[i];


			//˳���Ƿ��ں���Χ��
			if (!(iLocCou >= 0 && iLocCou < Cou)) {

				break;
			}

			//�ж�˭���������Ȼ��ȥ����һ��˳��Ľڵ�
			if (abs(Cur - iLocCou) <= ((abs(0 - iLocCou) < (Cou - iLocCou) ? abs(0 - iLocCou) : (Cou - iLocCou))) ? 1 : 0) {
				//�ӵ�ǰλ�ÿ�ʼ

				if (Cur > iLocCou) {  //��ǰ

					Curnode = FnMovObtCouNode_Previous(Curnode, abs(Cur - iLocCou), FnObtNode_Previous);
					Cur = iLocCou;

				}
				else if (Cur < iLocCou) {  //���

					Curnode = FnMovObtCouNode_Next(Curnode, abs(Cur - iLocCou), FnObtNode_Next);
					Cur = iLocCou;

				}
				else {  //λ��δ�ı�
					;
					//�ڵ�λ�ò��ñ���

				}

			}
			else {//���׻�β����ʼ

				Curnode = FnSeaObtCouNode(HNode, ENode, Cou, iLocCou, FnObtNode_Previous, FnObtNode_Next);
				Cur = iLocCou;

			}


			//�ƶ�������һ���ڵ�
			//�õ����ݣ�Ȼ���ύ���������

			if (!FnOptNode_Data(FnObtNode_Title(Curnode), FnObtNode_Data(Curnode))) { //���ʧ��

				break;
			}


		}

		if (i == LocCou_Len) {  ///ȫ������ɹ�

			if (Com == 1) {  //������ȫ

				for (i = 0; i < Cou; i++) {

					int j;

					for (j = 0; j < LocCou_Len; j++) {

						if (i == LocCou[j]) {

							break;
						}

					}

					if (j == LocCou_Len) {  //����ڵ�û�б����


						//�ж�˭���������Ȼ��ȥ����һ��˳��Ľڵ�
						if (abs(Cur - i) <= ((abs(0 - i) < (Cou - i) ? abs(0 - i) : (Cou - i))) ? 1 : 0) {
							//�ӵ�ǰλ�ÿ�ʼ

							if (Cur > i) {  //��ǰ

								Curnode = FnMovObtCouNode_Previous(Curnode, abs(Cur - i), FnObtNode_Previous);
								Cur = i;

							}
							else if (Cur < i) {  //���

								Curnode = FnMovObtCouNode_Next(Curnode, abs(Cur - i), FnObtNode_Next);
								Cur = i;

							}
							else {  //λ��δ�ı�
								;
								//�ڵ�λ�ò��ñ���

							}

						}
						else {//���׻�β����ʼ

							Curnode = FnSeaObtCouNode(HNode, ENode, Cou, i, FnObtNode_Previous, FnObtNode_Next);
							Cur = i;

						}

						//���ú������
						if (!FnOptNode_Data(FnObtNode_Title(Curnode), FnObtNode_Data(Curnode))) { //���ʧ��

							break;
						}

					}
				}

				if (i == Cou) {  //��ȫ����ɹ�

					iresult = true;
				}

			}
			else {  //û����ȫ���������
				iresult = true;
			}


		}

	}

}


//----------------------------------˫���������ṹ�岿��   һ
//�ṹ�塢�ṹ���ڴ���䡢�ṹ�����ݵ���ӣ��޸ģ��������µĽڵ㣬�µ��׵�ַ���µ�β��ַ���µĳ���

/*

struct newNodeStorage {   //�����µ�ַ���ȴ洢�Ľṹ��

	void* newnode; //�����ڵ��ַ
	void* newHNode;   //���������׵�ַ
	void* newENode;  //������β��ַ
	ULength newCou;  //�����³���
};

*/

//newNodeStorage�ṹ������ڴ�
newNodeStorage FnCreObtnewNodeStorage(void) {  

	return (newNodeStorage)malloc(BytenewNodeStorage);

}

//FnRevnewNode_Storage  �ṹ��������ӣ��޸ģ�
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

//�����½ڵ��ַ
void* FnObtnewNodeStorage_Newnode(newNodeStorage varnewNode) {

	return varnewNode->newnode;

}

//�������׵�ַ
void* FnObtnewNodeStorage_NewHNode(newNodeStorage varnewNode) {

	return varnewNode->newHNode;

}

//������β��ַ
void* FnObtnewNodeStorage_NewENode(newNodeStorage varnewNode) {

	return varnewNode->newENode;

}

//������������
ULength FnObtnewNodeStorage_NewCou(newNodeStorage varnewNode) {

	return varnewNode->newCou;

}



//----------------------------------˫������������    ��
//����ָ��λ�á������ƶ�n���ڵ㡢�����ƶ�n���ڵ�


//�����׽ڵ㣬β�ڵ㣬�����ȣ�������ǰ�浽�����LocCou��
//��ȡ�ڵ����һ����ַ������һ����ַ������������������  FnObtNode_previous  FnObtNode_next ����ϣ�������
void* FnSeaObtCouNode(void* HNode, void* ENode, ULength Cou, Length LocCou,
	void* (*FnObtNode_Previous)(void* node), void* (*FnObtNode_next)(void* node)) {

	void* iresult = (int)NULL + 1;

	if (!(HNode != NULL && ENode != NULL && Cou > 0 && LocCou >= 0 && LocCou < Cou)) {
		iresult = NULL;
	}

	if (iresult) {

		if (LocCou <= Cou / 2) {//��ǰ����

			iresult = FnMovObtCouNode_Next(HNode, LocCou, FnObtNode_next);

		}
		else {//�Ӻ�����

			LocCou = Cou - LocCou - 1;
			iresult = FnMovObtCouNode_Previous(ENode, LocCou, FnObtNode_Previous);

		}

	}

	return iresult;

}

//����һ���ڵ��ƶ�count���ڵ�
void* FnMovObtCouNode_Previous(void* node, ULength LocCou, void* (*FnObtNode_Previous)(void* node)) {


	int i;

	for (i = 0; i < LocCou && node; i++) {

		node = FnObtNode_Previous(node);   //FnObtNode_Previous()���������ص�ǰ�ڵ����һ���ڵ�

	}

	return node;
	//�ƶ��ɹ��������ƶ����Ľڵ��ַ���ƶ�ʧ�ܷ���NULL
}

//����һ���ڵ��ƶ�count���ڵ�
void* FnMovObtCouNode_Next(void* Node, ULength LocCou, void* (*FnObtNode_Next)(void* Node)) {


	int i;

	for (i = 0; i < LocCou && Node; i++) {

		Node = FnObtNode_Next(Node);  //FnObtNode_Next()���������ص�ǰ�ڵ����һ���ڵ�

	}

	return Node;
	//�ƶ��ɹ��������ƶ����Ľڵ��ַ���ƶ�ʧ�ܷ���NULL
}


//----------------------------------�ַ�������
//���ַ���1��n��n+m�������ַ���2�������ַ���������ɾ���ַ�������


//���ַ���1��n��n+m�������ַ���2
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

//����һ���ַ�����Ϊ�ַ����������������ظ�����ַ
char* FnCreObtStrCopy(char* str) {

	char* newStr = (char*)malloc(strlen(str) + 1);
	if (newStr) {
		strcpy_s(newStr, strlen(str) + 1, str);
	}
	return newStr;
}

//�ͷ��ַ�������
void FnDelStrCopy(char* str) {

	free(str);
	return;
}


//----------------------------------������������
//�жϱ��⡢�ж��ַ����Ƿ�Ϊ�����֡��ж�SLoc�Ǳ��⻹��λ�á��ж�SLoc�Ƿ���ȷ

//data��order ���� �ַ���������   �жϱ����Ƿ����Ҫ��
bool FnSurObtString_Title(char* title) {

	bool iresult = false;

	if (title) {

		ULength Coustring = strlen(title) + 1;

		if (*title == '_' || isalpha(*title)) {   //����ĸΪ��ĸ�����»���
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
				else {  //��ǰ�ַ����Ϲ��򣬽�����һ����
					continue;
				}

				iresult = false;
				break;
			}

		}

	}

	return iresult;

}

//�ж��ַ���λ�ã��Ƿ�Ϊ������
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

//�ж�SLoc�Ǳ��⻹��λ��  -1 ����  0 ����  1λ��
Length FnSurObtString_TLoc(char* SLoc) {

	Length iresult = -1;  //��֪����ʲô�������������λ�õ�Ҫ�󶼲�����

	if (SLoc && *SLoc == '_' || isalpha(*SLoc)) {  //����

		iresult = FnSurObtString_Title(SLoc);//�����Ƿ����Ҫ��

		if (iresult == 1) {
			iresult = 0;
		}
		else {
			iresult = -1;
		}
	}
	else {  //λ��

		iresult = FnSurObtString_LocCou(SLoc);//������λ���Ƿ����Ҫ��

		if (!iresult) {
			iresult = -1;
		}
	}

	return iresult;
}

//�ж�SLoc�Ƿ���ȷ
bool FnSurObtString_SLoc(char* SLoc) {

	bool iresult = false; 

	if (SLoc) {

		Length i = FnSurObtString_TLoc(SLoc);//�ж��� ���� ����λ��

		if (i == 0 || i == 1) {  //�Ǳ��⣬Ҳ��λ�ã�����
			iresult = true;
		}

		return iresult;

	}

	
}

