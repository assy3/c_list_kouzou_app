#ifndef ONE_WAY_LIST_FUNC_H
#define ONE_WAY_LIST_FUNC_H

typedef struct tagOneWayListNode
{
	struct tagOneWayListNode * NextNodePtr;
	void * ObjNodePtr;
}OneWayListNode;

typedef struct tagOneWayList
{
	OneWayListNode * FirstNodePtr;
	OneWayListNode * CurrentNodePtr;
	OneWayListNode * LastNodePtr;
}OneWayList;


// 課題4関数
// 関数宣言
// Step1
BOOL OWLInitList(OneWayList * list);
BOOL OWLInsertObjToFirst(OneWayList * list, void * obj);
BOOL OWLAddObjToLast(OneWayList * list, void * obj);
// Step2
BOOL OWLGetFirstObj(OneWayList * list, void ** obj);
BOOL OWLGetNextObj(OneWayList * list, void ** obj);
BOOL OWLGetLastObj(OneWayList * list, void ** obj);
// Step3
BOOL OWLReleaseAllNode(OneWayList * list);
BOOL OWLReleaseFirstNode(OneWayList * list);
BOOL OWLReleaseLastNode(OneWayList * list);
// Step4
BOOL OWLInsertObjBeforeCurrent(OneWayList * list, void * obj);
BOOL OWLReleaseCurrentNode(OneWayList * list);

// デバック用関数
BOOL PrintAllNode(OneWayList * list);

#endif /* OUYO_KADAI3_PDFUNC_H */