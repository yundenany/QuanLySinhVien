



#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
//#define max 100;

//----Ham khai bao bien nhap danh sach quan ly sinh vien----
typedef struct sv {
    int mssv;
    char name[50];
    float dtb;
}sv;

//----Khai bao cau truc cua 1 node trong danh sach lien ket don----
typedef struct node
{
    sv info;//node chua cac thong tin da nhap vao danh sach
    struct node* pnext;//con tro de lien ket cac node danh sach thong tin voi nhau
}Node;

//----Ham nhap thong tin danh sach 1 sinh vien----
void nhap1sv(sv& x) 
{
    cout << "Nhap MSSV: ";
    cin >> x.mssv;
    cout << endl << "Nhap ten sinh vien: ";
    cin.ignore(1);
    cin.getline(x.name, 30);
    cout << endl << "Nhap diem trung binh cua sinh vien: ";
    cin >> x.dtb;
}

//----Ham xuat thong tin danh sach 1 sinh vien----
void xuat1sv(sv x)
{
    cout << "\nMSSV la : " << x.mssv;
    cout << "\nHo va Ten : " << x.name;
    cout << "\nDiemTB la : " << x.dtb;
}

//----Ham khoi tao node----
void init(Node* &phead) 
{
    phead = NULL;//cho node dau bang NULL la bang rong
}

//----Ham tra ve node dau co gia tri NULL----
int isempty(Node* phead) 
{
    return(phead == NULL);//tra ve node dau de lat kiem tra xem 
    					  //node dau co rong hay khong	
}
//----Ham khoi tao 1 cai node----
Node* creatnode(sv x) 
{
    Node* p;
    p = new Node;//cap phat vung nho cho node p
    if (p == NULL)  //de luu y nguoi dung khi bo nho may khong du de cap phat 
    			   // cho viec tao node moi
    {
        cout << "\nKhong du bo nho de cap phat!";
        return NULL;
    }
    p->info = x;//truyen thong tin sinh vien cho x
    p->pnext = NULL;//dau tien khai bao node thi node do chua lien ket den node nao het
    				 //=>con tro cua no se tro den NULL
    return p;//tra ve node p vua khoi tao
}

//----Ham them node p vao cuoi danh sach lien ket----
void insertfirst(Node* &phead, sv x) 
{
    Node* p = creatnode(x);//dau tien tao 1 node moi
    p->pnext = phead; //cho node moi tao tro toi node ke tiep bang node dau
    phead = p; //cap nhat lai node moi tao la node dau
}

//----Ham them node p vao cuoi danh sach lien ket----
void insertlast(Node* &phead,sv x){
	Node* q = creatnode(x);//dau tien tao 1 node moi
	//kiem tra neu node dau rong
	if(isempty(phead) == true)
	{
		insertfirst(phead,x);//thi them node moi khoi tao vao node dau
	}
	else//neu khong
	{
		Node* p = phead;//khai bao node p la node dau
		while(p->pnext != NULL)//duyet tu dau danh sach toi khi gap danh sach co node = NULL
		{
			p = p->pnext; //cap nhat node ke tiep bang node dau
		}
		p->pnext = q;//cap nhat node moi tao bang node dau tro toi node ke tiep
	}
}

//----Ham nhap vao danh sach sinh vien----
void nhapds(Node* &phead) 
{
	int n;
    sv x;
    cout << endl << "nhap so luong danh sach: ";
    cin >> n;
	for (int i = 0; i < n; i++)
    {
    	cout << "\nnhap thong tin sinh vien thu " << i << " " << endl;
    	nhap1sv(x);//
    	insertfirst(phead, x);//them vao dau danh sach
    	cout << endl;
    }
}

//----Ham nhap them 1 sinh vien vao danh sach sinh vien----
void nhapdsthem(Node* &phead) 
{
    sv y;
    cout << "\nnhap thong tin sinh vien tiep theo " << endl;
    nhap1sv(y);
    insertlast(phead, y);//khi nhap them, them vao cuoi danh sach
    cout << endl;  
}

//----Ham xuat danh sach sinh vien----
void output(Node *phead) {
    Node *p = phead;//tao 1 node p bang node dau
    //kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
    {
    	cout << "\ndanh sach rong";
    }
	else//neu khong rong thi duyet danh sach va xuat danh sach 
		//cho toi khi gap node co gia tri NULL
    {
		while (p != NULL)
        {
    		xuat1sv(p->info);
    		p = p->pnext;
    		cout << endl;
        }
    }
}

//----Ham tim va xuat nhung sinh vien co diem trung binh duoi 5 de xep lai hoc sinh----
void timdtb(Node *phead) 
{
    //kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
    {
    	cout << "\ndanh sach rong";
    }
	else //neu khong rong thi duyet tu dau cho den khi node bang NULL thi dung
    {
		for (Node *p = phead; p != NULL; p = p->pnext)
        {
			if(p->info.dtb < 5)//neu thong tin danh sach dang duyet co diem trung binh duoi 5
			{
    			xuat1sv(p->info);//thi xuat sinh vien do ra
        	}
        }
    }
}

//----Ham chuc nang tim ten sinh vien----
void timten(Node* &phead, char y[20]) {
    Node *p = phead;//tao 1 node p bang node dau
    //kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
    {
    	cout << "\ndanh sach rong";
    }
	else//neu khong rong thi duyet tu dau cho den khi node bang NULL thi dung
    {
		for (Node *p = phead; p != NULL; p = p->pnext)
        {
			if(strcmp(y, p->info.name) == 0)//neu thong tin danh sach dang duyet co ten trung 
											//trung voi ten nhap tu ban phim
			{
    			xuat1sv(p->info);//thi xuat thong tin do ra
        	}
        }
    }
}

//----Khai bao ham hoan vi de su dung cho chuc nang quan li danh sach----
void hoanvi(sv &a, sv &b)
{
	sv t = a;//khai bao 1 bien tam va truyen thong tin dau vao bien tam do
	a = b;//cap nhap lai thong tin sau len thong tin dau
	b = t;//cap lai thong tin dau vua khai bao o bien tam ra thong tin phia sau
}


//----Ham chuc nang sap xep thong tin sinh vien theo diem----
void sort(Node* &phead)
{
	//kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
    {
    	cout << "\ndanh sach rong";
    }
    else
    {
		for(Node *p = phead; p != NULL; p=p->pnext)
		{
			for(Node *q = phead; q != NULL; q = q->pnext)
			{	
			//vi la danh sach lien ket don nen khi khai bao p, q la danh sach dau
			//no se lay tung node co diem sinh vien di so sanh voi nhau
				if(q->info.dtb > p->info.dtb)
				{
				//cai node nao co diem sinh vien nho hon thi se dua len dau 
					hoanvi(q->info ,p->info);//goi lai ham hoan vi de sap xep	
				}		
			}
		}
	}
}

//----Ham chuc nang xoa sinh vien dung dau danh sach----
void xoadau(Node* &phead) 
{
	//neu danh sach rong
	if(isempty(phead) == true)
    {
    	cout << "\ndanh sach rong";
    }
	else
    {
    	Node *p = phead;//node p la node se xoa
    	phead = phead->pnext;//cap nhat lai node dau la phan tu ke tiep
		delete p;//sau do xoa no di
	}
}

//----Ham chuc nang xoa sinh vien dung cuoi danh sach----
void xoacuoi(Node* &phead) 
{
	//neu danh sach rong
	if(isempty(phead))
    {
    	cout << "\ndanh sach rong";
    }
	else//neu khong rong
    {
    	Node *p = phead;//node p la node dau danh sach
    	Node *q = p->pnext;//node q la node ke cuoi danh sach
		while(q->pnext != NULL)//duyet cho den khi node cuoi co gia tri bang NULL 
		{
			q = q->pnext;//cap nhat lai node ke tiep
			p = p->pnext;//cap nhat lai node dau la node ke tiep
		}
		delete q;//den khi gap node cuoi thi xoa di
		p->pnext = NULL;//cap nhat node p ke tiep bang NULL
	}
}

void xoaall(Node * &phead)
{
	Node *p;
	for(Node *p = phead; p != NULL; p = p->pnext)
	{
		p = phead;
		phead = p->pnext;
		delete p;
	}
}

void Xoaall(Node * &phead, char mssv[10])
{
	Node *p = phead;
	if(phead == NULL)
	{
		cout << "\ndanh sach rong\n";
		return;
	}
	if(p->info.mssv == p->pnext->info.mssv)
	{
		phead = p->pnext;
		delete p;
		return;
	}
	Xoaall(p->pnext, mssv);
}

//----Ham chuc nang sap xep thong tin sinh vien theo Ma Sinh Vien----
void sort1(Node* &phead)
{
	for(Node *p = phead; p != NULL; p=p->pnext)
	{
		for(Node *q = phead; q != NULL; q = q->pnext)
	    {	
	    //vi la danh sach lien ket don nen khi khai bao p, q la danh sach dau
		//no se lay tung node co ma sinh vien di so sanh voi nhau
			if(q->info.mssv > p->info.mssv)
			{
				//cai node nao co ma sinh vien nho hon thi se dua len dau 
				hoanvi(q->info ,p->info);//goi lai ham hoan vi de sap xep	
			}		
		}
	}
}

//----Ham xuat cac sinh vien xep loai kha(co diem trung binh hon hoac bang 7)
void xeploaikha(Node* &phead)
{
	//kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
	{
		cout << "\nDanh Sach rong\n";	
	}
	else//neu khong rong thi duyet tu dau cho den khi node bang NULL thi dung
	{
		for(Node *p = phead; p != NULL; p=p->pnext)
		{	
			if(p->info.dtb >= 7)//neu thong tin danh sach dang duyet co diem sinh vien tren >=7
			{
				xuat1sv(p->info);//thi xuat sinh vien do ra
				cout << endl;	
			}			
		}
	}
}

//----Ham chuc nang tim sinh viem co diem trung binh cao nhat----
void maxsv(Node* &phead)
{
	//kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
	{
		cout << "\nDanh Sach rong\n";	
	}
	else//neu khong rong thi duyet tu dau cho den khi node bang NULL thi dung
	{
		for(Node *p = phead; p != NULL; p = p->pnext )
		{
			if(phead->info.dtb < p->info.dtb)//neu thong tin danh sach co sinh vien diem trung binh 
											//thap hon so voi sinh vien ke tiep
			{
				phead->info.dtb = p->info.dtb;//thi cap nhat lai sinh vien co diem lon hon 
											  //se bang voi diem sinh vien co diem thap
			}
			xuat1sv(p->info);//sau do xuat sinh vien do ra
		}
	}
}

//----Ham chuc nang tim sinh viem co diem trung binh thap nhat----
void minsv(Node* &phead)
{
	//kiem tra xem node dau co rong hay khong
	if(isempty(phead) == true)
	{
		cout << "\nDanh Sach rong\n";	
	}
	else//neu khong rong thi duyet tu dau cho den khi node bang NULL thi dung
	{
		for(Node *p = phead; p != NULL; p = p->pnext)
		{
			if(phead->info.dtb > p->info.dtb)//neu thong tin danh sach co sinh vien diem trung binh 
											//cao hon so voi sinh vien ke tiep
			{	
				phead->info.dtb = p->info.dtb;//thi cap nhat lai sinh vien co diem thap hon 
											  //se bang voi diem sinh vien co diem cao
			}
			xuat1sv(p->info);//duyet den khi node = NULL se cho ra sinh vien co diem trung binh cao nhat
		}
	}
}

//----Ham chuc nang xoa 1 sinh vien bat ki----
void delsv(Node* &phead) {
    Node *p = phead;//tao 1 node p bang node dau 
	string del;
	cin.ignore();
	cout << "Nhap ma so hoac ten sinh vien bat ki can xoa : \n";
	fflush(stdin);
	getline(cin, del);
	//tao node moi de gan gia tri can xoa
	Node* g = new Node;
if (del.compare(phead->pnext->info.name) == 0 && phead->pnext ==NULL) {
	phead = NULL;
}
else{
    //duyet ds de tim` node can` xoa
for (Node* k = phead; k != NULL; k = k->pnext) {
	//phat hien phan tu can xoa
if (del.compare(k->pnext->info.name) == 0) {
	g->pnext = k->pnext;
	k = g;
}
	g = k;
if(isempty(phead) == true)
{
    cout << "\ndanh sach rong";
}
else//neu khong rong thi duyet danh sach va xuat danh sach 
	//cho toi khi gap node co gia tri NULL
{
while (p != NULL)
{
    xuat1sv(p->info);
    cout << endl;
            }
	    }
   }
 }
}
int main()
{
    sv x;
    int n, key;
    char y[50];
    Node* phead;
    init(phead);
    nhapds(phead);
    cout << endl;
    system("cls");
    do
	{
		cout << "\n*************************MENU*************************\n";
		cout << "** 0. Thoat                                           **\n";
		cout << "** 1. Xuat danh sach cac sinh vien.                   **\n";
		cout << "** 2. Xuat danh sach cac sinh vien co dtb duoi 5.     **\n";
		cout << "** 3. Tim sinh vien co ten x.                         **\n";
		cout << "** 4. Sap xep danh sach theo diem                     **\n";
		cout << "** 5. Them sinh vien va xuat danh sach sau khi them.  **\n";
		cout << "** 6. Sap Xep DSSV tang dan theo MSSV                 **\n";
		cout << "** 7. Xuat danh sach cac Sinh Vien xep loai Kha.      **\n";
		cout << "** 8. Sinh Vien Co DTB cao nhat.                      **\n";
		cout << "** 9. Sinh Vien Co DTB thap nhat.                     **\n";
		cout << "** 10.Xoa 1 sinh vien bat ki                          **\n";
		cout << "********************************************************\n";
		cout << "\nNhap tuy chon: ";
		cin >> key;
		switch (key)
		{
			case 0:break;
			case 1:
			{
				system("cls");
				cout << "\nDanh Sach Cac Sinh Vien La\n";
    			output(phead);
				break;
			}
						
			case 2:
			{
				system("cls");
				cout << "\nDanh Sach Sinh Vien Co Diem Trung Binh Duoi 5 la : \n";
    			timdtb(phead);
				break;
			}				
			case 3:
			{
				system("cls");
				cout << "\nNhap ten muon tim: ";
    			cin.ignore();
    			cin.getline(y, 20);
    			timten(phead, y);
    			cout << endl;
				break;
			}						
			case 4:
			{
    			system("cls");
    			sort(phead);
    			cout << "\nDanh Sach Sau Khi Sap Xep La : \n";
    			output(phead);
				break;
			}			
			case 5:
			{
    			system("cls");
    			nhapdsthem(phead);
    			cout << "\nDanh Sach Sau Khi Them la : \n";
    			output(phead);
				break;
			}							
			case 6:
			{
    			system("cls");
    			sort1(phead);
    			cout << "\nDanh sach sau khi sap xep theo ma so la : \n";
    			output(phead);
				break;
			}		
			case 7:
			{			
				system("cls");
				cout << "\nDanh sach Cac Sinh Vien Xep Loai Kha la :\n";
				xeploaikha(phead);
				break;
			}
			case 8:
			{
    			system("cls");
    			cout << "\nSinh Vien co DTB cao nhat la : \n";	
    			maxsv(phead);
				break;
			}
			case 9:
			{
				system("cls");
    			cout << "\nSinh Vien co DTB thap nhat la : \n";   					
    			minsv(phead);
				break;
			}	
			case 10:
			{
				system("cls");
    			cout << "\nNhap ten sinh vien can xoa: \n";   					
    			delsv(phead);
				break;
			}											
			default: cout << "\nNhap Lai!";	
	    }
	}while(key );
	return 0;
}


