/////#####################################################################
/////#######			PLEASE DO NOT COPYRIGHT IN MANY FORMS      #######
/////#####################################################################
/////###		Ho ten:  Tran Duc Anh         MSSV:6151071034          ###
/////###		Lop :CNTT K61                                          ###
/////###		BAI TAP LON LAP TRINH NANG CAO                         ###
/////###		Moi truong thuc hien: DEV C++                          ###
/////###  BM CNTT - DH GIAO THONG VAN TAI PHAN HIEU TAI TP.HCM       ###
/////#####################################################################
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
//============khai bao dulieu=========
struct book_st{
	char maSach[6];
	char tenSach[50];
	char theLoai[30];
	char nxb[60];
	int tongSoLuong;
};
typedef book_st bookList;
//====het du lieu sach================
//====het phan khai bao du lieu========
/*===================================================================*/
//====khai bao ham==================
void nhapMotQuyenSach(bookList *sach);
void nhapDanhSach(bookList *sach, int &n);
void inMotQuyenSach(bookList *sach);
void inDanhSach(bookList *sach, int n);
void hienthiThongtin(bookList *sach, int n);
void thongTin();
void timSach(bookList *sach, int n);
void sachTheLoai(bookList *sach,int n);
void sapXepMaSach(bookList *sach, int n);
void xoaSach(bookList *sach,int n);
void suaSach(bookList *sach,int n);
void ghiFile(bookList *sach, int n);
void pressAnyKey();
void menu();
void SetColor(WORD color);
//====ket thuc khai bao ham===========================
/*======================================================================*/
//=================HAM MAIN===========================
//#######################################################################
int main(){
	system("color 72");
	int pass=1234;
    do{
		printf("\n     Nhap mat khau de chay chuong trinh (mat khau co 4 so): ");
		scanf("%d",&pass);
		if(pass != 1234)
			printf("\n     Moi ban nhap lai!");	    		  	
	}while( pass != 1234);
	SetColor(240);
    giaoDien:
    menu();
}
//====het ham main================
/*===================================================================*/
//====ham nhap mot quyen sach========
void nhapMotQuyenSach(bookList *sach){
	fflush(stdin);
	printf("\n   Nhap ma sach: ");
	gets(sach->maSach);
	printf("\n   Nhap ten sach: ");
	gets(sach->tenSach);
	printf("\n   Nhap the loai: ");
	gets(sach->theLoai);
	printf("\n   Nhap ten nha xuat ban: ");
	gets(sach->nxb);	
	printf("\n   Nhap so luong sach: ");
	scanf("%d",&sach->tongSoLuong);
}
//====het ham nhap mot quyen sach================
/*===================================================================*/
//====ham nhap danh sach=========================
void nhapDanhSach(bookList *sach, int &n){
    printf("\n   Nhap so luong sach: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       printf("\n   Nhap quyen sach thu %d: ",i+1);
       sach=(bookList*)realloc(sach,n*sizeof(bookList));
       nhapMotQuyenSach(&*(sach+i));
    }
}
//====het ham nhap danh sach================
/*===================================================================*/
//====ham in mot quyen sach=================
void inMotQuyenSach(bookList *sach){
	printf("\n +============================================+");
	printf("\n # 	Ma sach: %s",sach->maSach);
	printf("\n # 	Ten sach: %s",sach->tenSach);
	printf("\n # 	The loai: %s",sach->theLoai);
	printf("\n # 	Nha xuat ban: %s",sach->nxb);
	printf("\n # 	Tong so luong: %d",sach->tongSoLuong);
	printf("\n +============================================+");
}
//====het ham in mot quyen sach================
/*===================================================================*/
//====ham in danh sach=========================
void inDanhSach(bookList *sach, int n){
	printf("\n +===============DANH SACH QUYEN SACH===============+");
    for(int i=0;i<n;i++){
	    printf("\n   Quyen sach thu %d:",i+1);
        inMotQuyenSach(sach+i);	
	}
}
//====het ham in danh sach================
/*===================================================================*/
//====ham hien thi thong tin==============
void hienthiThongtin(bookList *sach, int n){
	for (int i=0; i<n; i++){
		printf("\n%-15s|| %-15s|| %-15s|| %-15s|| %-15d\n",(sach+i)->maSach, (sach+i)->tenSach, (sach+i)->theLoai, (sach+i)->nxb, (sach+i)->tongSoLuong);
	}
}
//====het ham hien thi thong tin================
/*===================================================================*/
//====ham thong tin=============================
void thongTin(){
	printf("\n 		Chuong Trinh Quan Ly Thu Vien  ");
	printf("\n 		Sinh vien: TRAN DUC ANH ");
	printf("\n 		MSSV : 6151071034");
	printf("\n 		Lop : CNTT K61 - Truong GTVT PH.TPHCM");
}
//====het ham thong tin================
/*===================================================================*/
//====ham tim sach=====================
void timSach(bookList *sach, int n){
	int bienKT=0;
	bookList sachTim;
	printf("\n   Tim sach");
	printf("\n   Nhap ma sach can tim:");
	fflush(stdin);
	gets(sachTim.maSach);
	for(int i=0;i<n;i++){
		if(strcmp((sach+i)->maSach,sachTim.maSach)==0){
			inMotQuyenSach(sach+i);
			bienKT++;
		}
	}
	if(bienKT==0){
		printf("\n   Ma sach khong ton tai!!!");
	}
}
//====het ham tim sach================
/*===================================================================*/
//====ham sach the loai===============
void sachTheLoai(bookList *sach,int n){
	char theLoaiSach[30];
	int bienKT=0;
	printf("\n   Nhap the loai muon thong ke: ");
	fflush(stdin);
	gets(theLoaiSach);
	printf("\n +========THONG TIN SACH THEO THE LOAI========+");
	printf("\n +============================================+");
	for(int i=0;i<n;i++){
		if(strcmp((sach+i)->theLoai,theLoaiSach)==0){
			bienKT++;
			printf("\n # Sach tim thay thu %d: ",bienKT);
			inMotQuyenSach(sach+i);
		}
	}
	if(bienKT == 0)
	{
		printf("   Khong co the loai sach nay ");
	}
}
//====het ham sach the loai================
/*===================================================================*/
//====ham sap xep ma sach==================
void sapXepMaSach(bookList *sach, int n){
	bookList temp;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp((sach+i)->maSach,(sach+j)->maSach)>0){
				temp = *(sach+i);
				*(sach+i)=*(sach+j);
				*(sach+j)=temp;
			}
		}
	}
}
//====het ham sap xep ma sach================
/*===================================================================*/
//====ham xoa sach===========================
void xoaSach(bookList *sach,int n){
	bookList sachCanXoa;
	int bienKT=0,bienLap;
	printf("\n   Xoa sach...");
	printf("\n   Nhap ma sach:");
	fflush(stdin);
	gets(sachCanXoa.maSach);
	for(int i=0;i<n;i++){
		if(strcmp((sach+i)->maSach,sachCanXoa.maSach)==0){
	        for(bienLap=i;bienLap<n;i++){
	            *(sach+bienLap)=*(sach+bienLap+1);
	            n=n-1;
	            printf("\n   Da xoa xong");
	        }
		bienKT++;
		}
	}
	if(bienKT==0){
		printf("\n   Ma sach khong ton tai!!!");
    }
}
//====het ham xoa sach================
/*===================================================================*/
//====ham sua sach====================
void suaSach(bookList *sach,int n){
	int dem=0;
	bookList sachCanSua;
	printf("\n   SUA CHI TIET SACH ");
	printf("\n   Nhap ma sach can sua :");
	fflush(stdin);
	gets(sachCanSua.maSach);
	for(int i=0;i<n;i++){
		if(strcmp((sach+i)->maSach,sachCanSua.maSach)==0){
			printf("\n   Tim thay ma sach -lan luot sua thong tin:");
			fflush(stdin);	        
	        printf("\n   Nhap ten sach: ");	
		    gets(sachCanSua.tenSach);
		    printf("\n   Nhap the loai: ");
		    gets(sachCanSua.theLoai);
		    printf("\n   Nhap ten nha xuat ban: ");
		    gets(sachCanSua.nxb);	
		    printf("\n   Nhap so luong sach: "); 
		    scanf("%d",sachCanSua.tongSoLuong);
		    *(sach+i)=sachCanSua;
	        printf("\n   Da sua xong ");
		    dem++;
		}    
	}
    if(dem==0){
	    printf("\n   Ma sach khong ton tai!!!");
	}
}
//====het ham sua sach================
/*===================================================================*/
//====ham ghi file====================
void ghiFile(bookList *sach, int n){
	getchar();
	char fName[26];
    char fPath[100]="sach.txt";       
	FILE* fOut = fopen(fPath, "w");
	fprintf(fOut, "%-15s|| %-10s|| %-10s|| %-10s|| %-10s\n", "Ma sach", "Ten sach", "The loai", "Nha xuat ban", "Tong so luong");
	for(int i = 0;i<n; i++) {
		fprintf(fOut, "%-15s|| %-10s|| %-10s|| %-10s|| %-10d\n", (sach+i)->maSach, (sach+i)->tenSach, (sach+i)->theLoai, (sach+i)->nxb, (sach+i)->tongSoLuong);
	}
	printf("\n  Luu file thanh cong");
	fclose(fOut);
}

//====het ham ghi file================
/*===================================================================*/
//====ham pressAnyKey=================
void pressAnyKey(){
    printf("\n\n   Bam phim bat ky de tiep tuc...");
    getch();
    system("cls");
}
//====het ham pressAnyKey================
/*===================================================================*/
//====ham menu======
void menu(){
	bookList *sach;
	int n,key;
	sach = (bookList*) malloc(sizeof(bookList));
    int flat = 1;
    bool daNhap = false;
    while(flat){
        system("cls");
        printf("\n 		################### QUAN LY THU VIEN ###################");
	    printf("\n 		#======================================================#");
		printf("\n 		###  Lop :CNTT K61  BM CNTT - DH GTVT PH.TPHCM       ###");
		printf("\n 		#======================================================#");
		printf("\n 		#=====================Quan Ly Sach=====================#");
		printf("\n 		#======================================================#");
		printf("\n 		# 1-Them sach moi         ## 5-Sua sach                #");
		printf("\n 		# 2-Muc luc sach          ## 6-Xoa sach                #");
		printf("\n 		# 3-Tim sach              ## 7-Ghi file                #");
		printf("\n 		# 4-Sach theo the loai    ## 8-Thong Tin               #");
		printf("\n 		#              ## 0-Thoat chuong trinh                    #");
		printf("\n 		#======================================================#");
		printf("\n 		########################################################");
		printf("\nNhap lua chon : ");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\n   Ban da chon them sach moi!");
                printf("\n");
                nhapDanhSach(sach,n);
                printf("\n   Ban da nhap thanh cong!");
                printf("\n");
                daNhap = true;
                pressAnyKey();
				break;
			case 2:
                if(daNhap){
                    printf("\n   Ban da chon in ra muc luc sach.\n");
                    printf("\n");
                    printf("\n%-15s|| %-15s|| %-15s|| %-15s|| %-15s\n", "Ma sach", "Ten sach", "The loai", "Nha xuat ban", "Tong so luong");
                    sapXepMaSach(sach,n);
                    hienthiThongtin(sach,n);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
            case 3:
                if(daNhap){
                    printf("\n   Ban da chon tim sach!");
                    timSach(sach,n);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;         
            case 4:
                if(daNhap){
                    printf("\n   Ban da chon tim sach theo the loai");
                    sachTheLoai(sach,n);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
            case 5:
                if(daNhap){
                    printf("\n   Ban da chon sua sach.");
                    suaSach(sach,n);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
			case 6:
                if(daNhap){
                    printf("\n   Ban da chon xoa sach");
                    xoaSach(sach,n);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;	
            case 7:
                if(daNhap){
                    printf("\n   Ban da chon luu file ");
                    ghiFile(sach,n);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
			case 8:
                printf("\n   Ban da chon hien thi thong tin  ");
                thongTin();
                pressAnyKey();
                break;
            default:
                printf("\n   Khong co chuc nang nay!");
                printf("\n   Bam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
			case 0:
                printf("\n   Ban da chon thoat chuong trinh!");
                flat =0;
                false;       
        }
    }
    free(sach);
}
//====het ham menu================
/*===================================================================*/
//====ham SetColor================
void SetColor(WORD color){ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
