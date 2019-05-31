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
		p = (PersonalData *)malloc(sizeof(PersonalData));  /* メモリ領域の確保 */
		// 37byte
		printf("nameを入力してください。");
		scanf("%s", name);
		printf("phoneNoを入力してください。");
		scanf("%s", phoneNo);
		// データセット関数呼び出し
		check = SetPersonalData(p, id, name, phoneNo);

		if (check == FALSE){
			printf("データセットに失敗しました\n");
		}

		printf("データセットを続けない 1 続ける else \n");
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

	printf("データを%d個セットしました\n", (num + 1));


	/*応用課題4*/
	OneWayList list;
	// STEP1関数呼び出し
	OWLInitList(&list);
	//　初期化
	OWLInsertObjToFirst(&list, (data));
	// 先頭ノードに挿入

	OWLAddObjToLast(&list, (data));
	OWLAddObjToLast(&list, (data));

	// 後ろのノードに挿入

	// デバック用
	PrintAllNode(&list);

	void ** DataPtr1;
	// ポインタメモリの動的確保
	DataPtr1 = (int *)malloc(sizeof(int));
	//OWLGetFirstObj(&list, DataPtr1);

	void ** DataPtr2;
	// ポインタメモリの動的確保
	DataPtr2 = (int *)malloc(sizeof(int));
	//OWLGetNextObj(&list, DataPtr2);

	void ** DataPtr3;
	// ポインタメモリの動的確保
	DataPtr3 = (int *)malloc(sizeof(int));

	//OWLReleaseFirstNode(&list);

	//PrintAllNode(&list);
	// 先頭ノード解放3-2

	//OWLReleaseLastNode(&list);
	//PrintAllNode(&list);
	// ラストノード解放3-2


	//OWLReleaseAllNode(&list);
	//PrintAllNode(&list);
	// 全ノード解放3-1


	// 4-1 データを現在位置の前に挿入する関数
	//OWLInsertObjBeforeCurrent(&list, (data));
	printf("関数後");
	PrintAllNode(&list);

	// 4-2 現在位置のノードを解放する関数
	//OWLReleaseCurrentNode(&list);



	getchar();
	getchar();
	return 0;
}
