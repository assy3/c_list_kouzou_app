#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "PersonalData_func.h"
#include "OneWayList_func.h"

int main(void){
	PersonalData data[10];
	unsigned short id = 1;
	int m = 0;
	int flag = 0;
	int select = 0;
	char name[20];
	char phoneNo[15];
	BOOL check;
	//g_packed_kouzoutai = sizeof(data->usID) + sizeof(data->cName) + sizeof(data->cPhoneNo);

	while (m < 10) {
		PersonalData *p;
		p = (PersonalData *)malloc(sizeof(PersonalData));  /* �������̈�̊m�� */
		// 37byte
		printf("name����͂��Ă��������B");
		scanf("%s", name);
		printf("phoneNo����͂��Ă��������B");
		scanf("%s", phoneNo);
		// �f�[�^�Z�b�g�֐��Ăяo��
		check = SetPersonalData(p, id, name, phoneNo);

		if (check == FALSE){
			printf("�f�[�^�Z�b�g�Ɏ��s���܂���\n");
		}

		printf("�f�[�^�Z�b�g�𑱂��Ȃ� 1 ������ else \n");
		scanf("%d", &flag);
		if (flag == 1){
			break;
		}
		else{
			m++;
			id++;
		}
	}

	unsigned short num = m;

	printf("�f�[�^��%d�Z�b�g���܂���\n", (num + 1));


	/*���p�ۑ�4*/
	OneWayList list;
	// STEP1�֐��Ăяo��
	OWLInitList(&list);
	//�@������
	OWLInsertObjToFirst(&list, (data));
	// �擪�m�[�h�ɑ}��

	OWLAddObjToLast(&list, (data));
	OWLAddObjToLast(&list, (data));

	// ���̃m�[�h�ɑ}��

	// �f�o�b�N�p
	PrintAllNode(&list);

	void ** DataPtr1;
	// �|�C���^�������̓��I�m��
	DataPtr1 = (int *)malloc(sizeof(int));
	//OWLGetFirstObj(&list, DataPtr1);

	void ** DataPtr2;
	// �|�C���^�������̓��I�m��
	DataPtr2 = (int *)malloc(sizeof(int));
	//OWLGetNextObj(&list, DataPtr2);

	void ** DataPtr3;
	// �|�C���^�������̓��I�m��
	DataPtr3 = (int *)malloc(sizeof(int));

	//OWLReleaseFirstNode(&list);

	//PrintAllNode(&list);
	// �擪�m�[�h���3-2

	//OWLReleaseLastNode(&list);
	//PrintAllNode(&list);
	// ���X�g�m�[�h���3-2


	//OWLReleaseAllNode(&list);
	//PrintAllNode(&list);
	// �S�m�[�h���3-1


	// 4-1 �f�[�^�����݈ʒu�̑O�ɑ}������֐�
	//OWLInsertObjBeforeCurrent(&list, (data));
	printf("�֐���");
	PrintAllNode(&list);

	// 4-2 ���݈ʒu�̃m�[�h���������֐�
	//OWLReleaseCurrentNode(&list);



	getchar();
	getchar();
	return 0;
}
