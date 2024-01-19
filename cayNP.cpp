	﻿#define _CRT_SECURE_NO_WARNINGS
 
	#include<iostream>
 
	#include<stdio.h>
 
	#include<stdlib.h>
 
	#include<time.h>
 
	#include<queue>
 
	#include<stack>
 
	using namespace std;
 
	struct TNode
 
	{//Định nghĩa kiểu dữ liệu cho 1 nút của cây nhị phân là TNode
 
		int Info;
 
		TNode* Left;
 
		TNode* Right;
 
	};
 
	struct BTree
 
	{//Định nghĩa kiểu dữ liệu cho cây nhị phân (Cây NPTK)
 
		TNode* Root;
 
	};
 
	TNode* CreateTNode(int x)
 
	{
 
		TNode* p = new TNode;
 
		if(p == NULL)
 
		{
 
			printf("khong du bo nho de cap phat");
 
			return NULL;
 
		}
 
		p->Info = x;
 
		p->Left = NULL;
 
		p->Right = NULL;
 
		return p;
 
	}
 
	void ShowTNode(TNode* T)
 
	{
 
		printf("%4d", T->Info);
 
	}
 
	//tạo cây rỗng
 
	void InitBTree(BTree &bt)
 
	{ 
 
		bt.Root = NULL;
 
	}
 
	//chèn nút p bên trái T
 
	void InsertTNode(TNode* &root, TNode* p)
 
	{
 
		//if(p == NULL)
 
		//	return 0; //Thực hiện không thành công
 
		if(root == NULL) //Cây rỗng, nên thêm vào gốc
 
		{
 
			root = p;
 
			return ; //Thực hiện thành công
 
		}
 
		if(root->Info==p->Info)
 
			return ;
 
		if(p->Info<root->Info)
 
			InsertTNode(root->Left, p); //Them ben trái
 
		else
 
			InsertTNode(root->Right,p);	 //Thực hiện thành công
 
	}
 
	void CreateBTreeFromArray(BTree &bt, int a[])
 
	{//Ham tao cay NPTK tu mang a
 
	InitBTree(bt);

		for(int i = 0; i < 10; i++)
 
		{
 
			TNode* p = CreateTNode(a[i]);
 
			InsertTNode(bt.Root, p);
 
	}
 
	}
 
	void CreatBTree(BTree &bt)
 
	{
 
		int n,x;
 
		TNode* p;
 
		InitBTree(bt);
 
		printf("Nhap n: ");
 
		scanf("%d",&n);
 
		printf("nhap gia tri nut");
 
		for(int i=0;i<n;i++)
 
		{
 
				scanf("%d",&x);
 
				p=CreateTNode(x);
 
				InsertTNode(bt.Root,p);
 
		}
 
		
 
	}
 
	void CreateBTree_Automatic(BTree &bt)
 
	{
 
		int n;
 
		int x;
 
		printf("cho biet nut cua cay: ");
 
		scanf_s("%d", &n);
 
		InitBTree(bt);
 
		srand((unsigned)time(NULL));//Tạo số mới sau mỗi lần thực hiện
 
		for(int i = 1; i <= n; i++)
 
		{
 
			x = (rand()%199)-99 ; //Tạo 1 số ngẫu nhiên trong [-99, 99]
 
			TNode* p = CreateTNode(x);
 
			InsertTNode(bt.Root, p);
 
		}
 
	}
 
	TNode *Maxam(TNode *root)
 
	{
 
		TNode *p=root;
 
		if(root->Info<0)
 
		{
 
			while(p->Right!=NULL&&p->Info<0)
 
				p=p->Right;
 
			return p;
 
		}
 
		else
 
		{
 
				while(p->Left!=NULL&&p->Info<0)
 
				p=p->Left;
 
					return p;
 
		}
 
	}
 
	//đoc file 
 
	void taoDSTuFileText(BTree &bt, char fileName[]) {
    FILE *f = fopen(fileName, "r+");
    if (f == NULL) {
        printf("\nLoi doc file!");
        return;
    }
    int x;
    InitBTree(bt);
    int n;
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++) {
        fscanf(f, "%d", &x);
        InsertTNode(bt.Root,CreateTNode(x));
    }
    fclose(f);
}

 
	//duyet cay NLR
 
	void NLR(TNode* root)
 
	{
 
		if(root == NULL) return;
 
		printf("%4d", root->Info);
 
		NLR(root->Left);
 
		NLR(root->Right);
 
	}
 
	//duyet cay LNR
 
	void LNR(TNode* root)
 
	{
 
		if(root == NULL) 
 
			return;
 
		LNR(root->Left);
 
		printf("%4d", root->Info);
 
		LNR(root->Right);
 
	}
 
	//duyet cay LRN
 
	void LRN(TNode* root)
 
	{
 
		if(root == NULL) 
 
			return;
 
		LRN(root->Left);
 
		LRN(root->Right);
 
		printf("%4d", root->Info);
 
	}
 
	void NRL(TNode* root)
 
	{
 
		if(root == NULL) return;

		printf("%4d", root->Info);
 
		NRL(root->Right);
 
		NRL(root->Left);
 
	}
 
	void RNL(TNode* root)
 
	{
 
		if(root == NULL) return;
 
		RNL(root->Right);
 
		printf("%4d", root->Info);
 
		RNL(root->Left);
 
	}
 
	void RLN(TNode* root) {
    if(root == NULL) return;
    RLN(root->Right);
    RLN(root->Left);
    printf("%4d", root->Info);
}

 
	//duyet theo chieu rong
 
void BreadthNLR(TNode *root) {
    if(root==NULL)
        return;
    queue <TNode *> q;
    q.push(root);
    while(!q.empty()) {
        TNode *p;
        p=q.front();
        q.pop();
        ShowTNode(p);
        if(p->Left!=NULL)
            q.push(p->Left);
        if(p->Right!=NULL)
            q.push(p->Right);
    }
}

 
void BreadthNRL(TNode *root) {
    if(root==NULL)
        return;
    queue <TNode *> q;
    q.push(root);
    while(!q.empty()) {
        TNode *p;
        p=q.front(); //nhận giá trị nút trên cùng
        q.pop(); //xóa giá trị trên cùng
        ShowTNode(p);
        if(p->Right!=NULL)
            q.push(p->Right);
        if(p->Left!=NULL)
            q.push(p->Left);
    }
}

 
void DepthNLR(TNode *root) {
    stack<TNode *>q;
    TNode *p;
    q.push(root);
    while (!q.empty()) {
        p =q.top();
        q.pop();
        ShowTNode(p);
        if (p->Right != NULL) 
            q.push(p->Right);
        if(p->Left!=NULL)
            q.push(p->Left);
    }
}

 
2//void depthLNR(TNode *root) {
//    TNode *p;
//    while(root) {
//        if(root->Left==NULL) {
//            printf("%d  ",root->Info);
//            root=root->Right;
//        } else {
//            p=root->Left;
//            while(p->Right && p->Right!=root) {
//                p=p->Right;
//            }
//            //if(
//        }
//    }
//}

TNode* FindTNode(TNode* root, int x) {
    if(root == NULL) 
        return NULL;
    if(root->Info == x) 
        return root;
    else if(root->Info > x)
        return FindTNode(root->Left, x);
    else
        return FindTNode(root->Right, x);
}
 
TNode* FindTNodeTheMang(TNode* &p) {
    //Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
    TNode* f = p; //30
    TNode* q = p->Right; //35
    while(q->Left != NULL) {
        f = q; //Lưu nút cha của q 
        q = q->Left; //q qua bên trái
    }
    p->Info = q->Info; //Tìm được phần tử thế mạng cho p là q
    if(f == p) //Nếu cha của q là p
        f->Right = q->Right;
    else
        f->Left = q->Right;
    return q; //trả về nút q là nút thế mạng cho p
}
 
int DeleteTNodeX(TNode* &root, int x) {
    //Hàm xóa nút có giá trị là x
    if(root == NULL) //Khi cây rỗng
        return 0; //Xóa không thành công
    if(root->Info > x)
        return DeleteTNodeX(root->Left, x);
    else if(root->Info < x)
        return DeleteTNodeX(root->Right, x);
    else { //rootInfo = x, tìm nút thế mạng cho root
        TNode* p = root;
        if(root->Left == NULL) { //khi cây con không có nhánh trái
            root = root->Right;
            delete p;
        } else if(root->Right == NULL) { //khi cây con không có nhánh phải
            root = root->Left;
            delete p;
        } else { //khi cây con có cả 2 nhánh, chọn min của nhánh phải để thế mạng
            TNode* q = FindTNodeTheMang(p);
            delete q; //Xóa nút q là nút thế mạng cho p
        }
        return 1; //Xóa thành công
    }
}
 
int DemNodeLonhonx(TNode *root,int x) {
    int KQ=0;
    if(root==NULL)
        return 0;
    if(root->Info>x)
        KQ++;
    KQ+=DemNodeLonhonx(root->Left,x);
    KQ+=DemNodeLonhonx(root->Right,x);
    return KQ;
}

 
int DemNodeNhohonx(TNode *root,int x) {
    int KQ=0;
    if(root==NULL)
        return 0;
    if(root->Info<x)
        KQ++;
    KQ+=DemNodeNhohonx(root->Left,x);
    KQ+=DemNodeNhohonx(root->Right,x);
    return KQ;
}

 
int DemNodechan(TNode *root) {
    int KQ=0;
    if(root==NULL)
        return 0;
    if(root->Info%2==0)
        KQ++;
    KQ+=DemNodechan(root->Left);
    KQ+=DemNodechan(root->Right);
    return KQ;
}

 
int DemNodelonhonXnhohonY(TNode *root,int x,int y) {
    int KQ=0;
    if(root==NULL)
        return 0;
    if(root->Info>x && root->Info<y)
        KQ++;
    KQ+=DemNodelonhonXnhohonY(root->Left,x,y);
    KQ+=DemNodelonhonXnhohonY(root->Right,x,y);
    return KQ;
}

 
void ShowTNodeOfLevelK(TNode *root, int k) {
    if(!root) 
        return;
    if(k == 0) //đến mức cần tìm
        printf("%4d", root->Info);
    k--; //Mức k giảm dần về 0
    ShowTNodeOfLevelK(root->Left, k); //đệ quy trái
    ShowTNodeOfLevelK(root->Right, k);//đệ quy phải
}

 
void ShowTNodeIsLeafOfLevelK(TNode *root, int k) {
    if(!root) 
        return;
    if(k == 0 && !root->Left && !root->Right) //đến mức cần tìm
        printf("%4d", root->Info);
    k--; //Mức k giảm dần về 0
    ShowTNodeIsLeafOfLevelK(root->Left, k); //đệ quy trái
    ShowTNodeIsLeafOfLevelK(root->Right, k);//đệ quy phải
}

void ShowTNode1conOfLevelK(TNode *root, int k) {
    if(!root) 
        return;
    if(k == 0 && ((!root->Left &&root->Right) || (root->Left&&!root->Right))) //đến mức cần tìm
        printf("%4d", root->Info);
    k--; //Mức k giảm dần về 0
    ShowTNode1conOfLevelK(root->Left, k); //đệ quy trái
    ShowTNode1conOfLevelK(root->Right, k);//đệ quy phải
}

 
void ShowTNode2conOfLevelK(TNode *root, int k) {
    if(!root) 
        return;
    if(k == 0 && root->Left && root->Right) //đến mức cần tìm
        printf("%4d", root->Info);
    k--; //Mức k giảm dần về 0
    ShowTNode2conOfLevelK(root->Left, k); //đệ quy trái
    ShowTNode2conOfLevelK(root->Right, k);//đệ quy phải
}

 
int countTNodeOfLevelK(TNode *root, int k) {
    int KQ=0;
    if(!root) 
        return 0;
    if(k == 0) //đến mức cần tìm
        KQ++;
    k--; //Mức k giảm dần về 0
    KQ+=countTNodeOfLevelK(root->Left, k); //đệ quy trái
    KQ+=countTNodeOfLevelK(root->Right, k);//đệ quy phải
    return KQ;
}

 
int countTNodeIsLeafOfLevelK(TNode *root, int k) {
    int KQ=0;
    if(!root) 
        return 0;
    if(k == 0 && !root->Left && !root->Right) //đến mức cần tìm
        KQ++;
    // Code is incomplete here
}
