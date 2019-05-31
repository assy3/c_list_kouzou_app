# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <windows.h>
# include <string.h>
# include "PersonalData_func.h"
# include "OneWayList_func.h"

// ここから課題4
//グローバルで定義
// STEP1-1
BOOL OWLInitList(OneWayList * list){
	if (list == NULL){
		goto l_Error;
	}
	BOOL ret;
	// 各メンバにNULLをセット
	list->FirstNodePtr = NULL;
	list->CurrentNodePtr = NULL;
	list->LastNodePtr = NULL;
	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}
// STEP1-2
BOOL OWLInsertObjToFirst(OneWayList * list, void * obj){
	if (list == NULL || obj == NULL){
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode * newNodePos;
	OneWayListNode * TempNodePos;
	//8バイト分の領域確保
	newNodePos = (OneWayListNode *)malloc(sizeof(OneWayListNode));
	TempNodePos = list->FirstNodePtr;

	if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL))
	{
		list->FirstNodePtr = newNodePos;
		list->CurrentNodePtr = newNodePos;
		list->LastNodePtr = newNodePos;

		newNodePos->ObjNodePtr = obj;
		newNodePos->NextNodePtr = NULL;

	}
	else{
		list->FirstNodePtr = newNodePos;
		list->CurrentNodePtr = newNodePos;

		newNodePos->ObjNodePtr = obj;
		newNodePos->NextNodePtr = TempNodePos;

	}

	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP1-3
BOOL OWLAddObjToLast(OneWayList * list, void * obj){
	if (list == NULL || obj == NULL){
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode * newNodePos;
	OneWayListNode * TempNodePos;
	//8バイト
	newNodePos = (OneWayListNode *)malloc(sizeof(OneWayListNode));
	TempNodePos = list->LastNodePtr;
	if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL))
	{
		list->FirstNodePtr = newNodePos;
		list->CurrentNodePtr = newNodePos;
		list->LastNodePtr = newNodePos;

		newNodePos->ObjNodePtr = obj;
		newNodePos->NextNodePtr = NULL;
	}
	else{
		list->CurrentNodePtr = newNodePos;
		list->LastNodePtr = newNodePos;

		newNodePos->ObjNodePtr = obj;
		newNodePos->NextNodePtr = NULL;
		TempNodePos->NextNodePtr = newNodePos;
	}

	ret = TRUE;

l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP2-1
BOOL OWLGetFirstObj(OneWayList * list, void ** obj){
	if (list == NULL || obj == NULL) {
		goto l_Error;
	}
	else if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL)) {
		*obj = NULL;
	}
	else {
		// nop
	}
	BOOL ret;
	obj = list->FirstNodePtr->ObjNodePtr;
	list->CurrentNodePtr = list->FirstNodePtr;

	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP2-2
BOOL OWLGetNextObj(OneWayList * list, void ** obj){
	if (list == NULL || obj == NULL) {
		goto l_Error;
	}
	else if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL)) {
		*obj = NULL;
	}
	else {
		// nop
	}
	BOOL ret;
	obj = list->CurrentNodePtr->NextNodePtr->ObjNodePtr;
	list->CurrentNodePtr = list->CurrentNodePtr->NextNodePtr;
	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP2-3
BOOL OWLGetLastObj(OneWayList * list, void ** obj){
	if (list == NULL || obj == NULL) {
		goto l_Error;
	}
	else if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL)) {
		*obj = NULL;
	}
	else {
		// nop
	}
	BOOL ret;
	obj = list->LastNodePtr->ObjNodePtr;
	list->CurrentNodePtr = list->LastNodePtr;
	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP3-1
BOOL OWLReleaseAllNode(OneWayList * list){
	if (list == NULL) {
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode *p, *temp;
	p = list->FirstNodePtr;
	OWLInitList(list);
	while (p != NULL) {
		temp = p->NextNodePtr; //次のデータの参照を取っておく
		free(p);
		p = temp;       //tempを次の処理対象に
	}
	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP3-2
BOOL OWLReleaseFirstNode(OneWayList * list){
	if (list == NULL) {
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode *p;
	p = list->FirstNodePtr;
	list->FirstNodePtr = p->NextNodePtr;
	free(p);

	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP3-3
BOOL OWLReleaseLastNode(OneWayList * list){
	if (list->LastNodePtr == NULL) {
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode *p = list->FirstNodePtr; //リストの先頭を指すように
	OneWayListNode * tmp = list->LastNodePtr;

	while (1) {
		if (p->NextNodePtr == list->LastNodePtr){
			p->NextNodePtr = NULL;
			free(tmp);
			list->LastNodePtr = p;
			break;
		}
		p = p->NextNodePtr;
	}

	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP4-1 データを現在位置より前に挿入
BOOL OWLInsertObjBeforeCurrent(OneWayList * list, void * obj){
	if (list == NULL || obj == NULL) {
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode * newNodePos;
	OneWayListNode *p;
	p = list->FirstNodePtr;
	OneWayListNode *c;
	c = list->CurrentNodePtr;
	//8バイト
	newNodePos = (OneWayListNode *)malloc(sizeof(OneWayListNode));

	while (1) {
		if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL))
		{
			list->FirstNodePtr = newNodePos;
			list->CurrentNodePtr = newNodePos;
			list->LastNodePtr = newNodePos;
		}
		else if(p->NextNodePtr == c){
			p->NextNodePtr = newNodePos;
			newNodePos->ObjNodePtr = obj;
			newNodePos->NextNodePtr = c;
			break;
		}
		else{
			// nop
		}
		p = p->NextNodePtr;

	}
	printf("無事終了\n");
	list->CurrentNodePtr = newNodePos;

	ret = TRUE;
l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}

// STEP4-2 現在のノード解放
BOOL OWLReleaseCurrentNode(OneWayList * list){
	if (list == NULL) {
		goto l_Error;
	}
	BOOL ret;
	OneWayListNode *p = list->FirstNodePtr;
	OneWayListNode * tmp = list->CurrentNodePtr;
	OneWayListNode * next_node = list->CurrentNodePtr->NextNodePtr;
	while (1) {
		if (p->NextNodePtr == list->CurrentNodePtr) {
			p->NextNodePtr = next_node;
			free(tmp);
			break;
		}
		p = p->NextNodePtr;
	}


	ret = TRUE;

l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}




BOOL PrintAllNode(OneWayList * list){
	BOOL ret = TRUE;
	if ((list->FirstNodePtr == NULL) && (list->LastNodePtr == NULL)){
		printf("リストは空です\n");
		goto l_EXIT;
	}
	int count = 1;
	OneWayListNode *current;
	current = list->FirstNodePtr;
	PersonalData * robj;
	while (1)
	{
		printf("node%d--------------------------------------------\n", count);
		//キャスト
		robj = (PersonalData *)(current->ObjNodePtr);
		printf("%d\n", robj->usID);
		printf("%s\n", robj->cName);
		printf("%s\n", robj->cPhoneNo);
		printf("--------------------------------------------node%d\n\n", count);
		if (current->NextNodePtr != NULL){
			current = (OneWayListNode *)(current->NextNodePtr);
			count++;
		}
		else{
			printf("出力完了\n");
			break;
		}
	}

	ret = TRUE;

l_EXIT:
	return ret;
l_Error:
	ret = FALSE;
	goto l_EXIT;
}
