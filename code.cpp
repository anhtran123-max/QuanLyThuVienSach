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
	char maSach[30];
	char tenSach[50];
	char theLoai[30];
	char nxb[60];
	int tongSoLuong;
};
typedef book_st Sach;
void tacGia();
void nhapSach(Sach *sach);
void nhapDanhSach(Sach *&danhsach, int &soluong);
void inSachTheoHangDoc(Sach *sach);
void inDanhSach(Sach *danhsach, int soluong);
void sapXepMaSach(Sach *sach, int soluong);
void hienthiThongtinTheoHangNgang(Sach *sach, int soluong);
void timSachTheoMaSach(Sach *sach, int soluong);
void thongKeSachTheoTheLoai(Sach *sach,int soluong);
void xoaSach(Sach *sach,int soluong);
void suaTenSach(Sach *sach,int soluong);
void ghiFile(Sach *sach, int n);
void pressAnyKey();
void menu();
int main(){
	system("color 72");
	int pass=1234;
    do{
		printf("\n     Nhap mat khau de chay chuong trinh (mat khau co 4 so): ");
		scanf("%d",&pass);
		if(pass != 1234)
			printf("\n     Moi ban nhap lai!");	    		  	
	}while( pass != 1234);
	giaoDien:
    menu();
	return 0;
}
void menu(){
	Sach *sach;
	int soluong,key;
	sach = (Sach*) malloc(sizeof(Sach));
    int flat = 1;
    bool daNhap = false;
    while(flat){
        system("cls");
        printf("\n 		####################### QUAN LY SACH ######################");
	    printf("\n 		#=========================================================#");
		printf("\n 		###     Lop :CNTT K61  BM CNTT - DH GTVT PH.TPHCM       ###");
		printf("\n 		#=========================================================#");
		printf("\n 		#=========================================================#");
		printf("\n 		# 1-Them sach moi               ## 5-Sua ten sach         #");
		printf("\n 		# 2-Muc luc sach                ## 6-Xoa sach             #");
		printf("\n 		# 3-Tim sach                    ## 7-Ghi file             #");
		printf("\n 		# 4-Thong ke sach theo the loai ## 8-Thong tin tac gia    #");
		printf("\n 		#                 0-Thoat chuong trinh                    #");
		printf("\n 		#=========================================================#");
		printf("\n 		###########################################################");
		printf("\n  Nhap lua chon : ");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\n   Ban da chon them sach moi!");
                printf("\n");
                nhapDanhSach(sach,soluong);
                printf("\n   Ban da nhap thanh cong!");
                printf("\n");
                daNhap = true;
                pressAnyKey();
				break;
			case 2:
                if(daNhap){
                    printf("\n   Ban da chon in ra muc luc sach!\n");
                    printf("\n");
                    printf("\n%-15s|| %-15s|| %-15s|| %-15s|| %-15s\n", "Ma sach", "Ten sach", "The loai", "Nha xuat ban", "Tong so luong");
                    sapXepMaSach(sach,soluong);
                    hienthiThongtinTheoHangNgang(sach,soluong);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
            case 3:
                if(daNhap){
                    printf("\n   Ban da chon tim sach!");
                    timSachTheoMaSach(sach,soluong);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;         
            case 4:
                if(daNhap){
                    printf("\n   Ban da chon thong ke sach theo the loai!");
                    thongKeSachTheoTheLoai(sach,soluong);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
            case 5:
                if(daNhap){
                    printf("\n   Ban da chon sua sach!");
                    suaTenSach(sach,soluong);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
			case 6:
                if(daNhap){
                    printf("\n   Ban da chon xoa sach!");
                    xoaSach(sach,soluong);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;	
            case 7:
                if(daNhap){
                    printf("\n   Ban da chon luu file!");
                    ghiFile(sach,soluong);
                }else{
                    printf("\n   Nhap danh sach sach truoc!!!!");
                }
                pressAnyKey();
                break;
			case 8:
                printf("\n   Ban da chon hien thi thong tin!");
                tacGia();
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
	if(sach == NULL){
        free(sach);
	}      
}
void nhapSach(Sach *sach){
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
void nhapDanhSach(Sach *&danhsach, int &soluong){
    printf("\n   Nhap so luong sach: ");
    scanf("%d",&soluong);
	danhsach=(Sach*)malloc(soluong*sizeof(Sach));
    for(int i=0;i<soluong;i++){
       printf("\n   Nhap quyen sach thu %d: ",i+1);
       nhapSach(&*(danhsach+i));
    }
}
void inSachTheoHangDoc(Sach *sach){
	printf("\n +============================================+");
	printf("\n # 	Ma sach: %s",sach->maSach);
	printf("\n # 	Ten sach: %s",sach->tenSach);
	printf("\n # 	The loai: %s",sach->theLoai);
	printf("\n # 	Nha xuat ban: %s",sach->nxb);
	printf("\n # 	Tong so luong: %d",sach->tongSoLuong);
	printf("\n +============================================+");
}
void inDanhSach(Sach *danhsach, int soluong){
	printf("\n +===============DANH SACH QUYEN SACH===============+");
    for(int i=0;i<soluong;i++){
	    printf("\n   Quyen sach thu %d:",i+1);
        inSachTheoHangDoc(danhsach+i);	
	}
}
void sapXepMaSach(Sach *sach, int soluong){
	Sach temp;
	for(int i=0; i<soluong-1; i++){
		for(int j=i+1; j<soluong; j++){
			if(strcmp((sach+i)->maSach,(sach+j)->maSach)>0){
				temp = *(sach+i);
				*(sach+i)=*(sach+j);
				*(sach+j)=temp;
			}
		}
	}
}
void hienthiThongtinTheoHangNgang(Sach *sach, int soluong){
	for (int i=0;i<soluong; i++){
		printf("\n%-15s|| %-15s|| %-15s|| %-15s|| %-15d\n",(sach+i)->maSach, (sach+i)->tenSach, (sach+i)->theLoai, (sach+i)->nxb, (sach+i)->tongSoLuong);
	}
}
void tacGia(){
	printf("\n 		Chuong Trinh Quan Ly Thu Vien  ");
	printf("\n 		Sinh vien: TRAN DUC ANH ");
	printf("\n 		MSSV : 6151071034");
	printf("\n 		Lop : CNTT K61 - Truong GTVT PH.TPHCM");
}
void timSachTheoMaSach(Sach *sach, int soluong){
	int bienKT=0;
	char maSach[30];
	printf("\n   Tim sach");
	printf("\n   Nhap ma sach can tim:");
	fflush(stdin);
	gets(maSach);
	for(int i=0;i<soluong;i++){
		if(strcmp((sach+i)->maSach,maSach)==0){
			inSachTheoHangDoc(sach+i);
			bienKT++;
		}
	}
	if(bienKT==0){
		printf("\n   Ma sach khong ton tai!!!");
	}
}
void thongKeSachTheoTheLoai(Sach *sach,int soluong){
	char theLoaiSach[30];
	int bienKT=0;
	printf("\n   Nhap the loai muon thong ke: ");
	fflush(stdin);
	gets(theLoaiSach);
	printf("\n +========THONG TIN SACH THEO THE LOAI========+");
	printf("\n +============================================+");
	for(int i=0;i<soluong;i++){
		if(strcmp((sach+i)->theLoai,theLoaiSach)==0){
			bienKT++;
			printf("\n # Sach tim thay thu %d: ",bienKT);
			inSachTheoHangDoc(sach+i);
		}
	}
	printf("\nTheLoai %s co %d quyen.",theLoaiSach,bienKT);
	if(bienKT == 0)
	{
		printf("   Khong co the loai sach nay ");
	}
}
void xoaSach(Sach *sach,int soluong){
	char maSach[30];
	int bienKT=0,bienLap;
	printf("\n   Xoa sach...");
	printf("\n   Nhap ma sach:");
	fflush(stdin);
	gets(maSach);
	for(int i=0;i<soluong;i++){
		if(strcmp((sach+i)->maSach,maSach)==0){
	        for(bienLap=i;bienLap<soluong;i++){
	            *(sach+bienLap)=*(sach+bienLap+1);
	            soluong=soluong-1;  
	        }
		printf("\n   Da xoa xong");
		bienKT++;
		}
	}
	if(bienKT==0){
		printf("\n   Ma sach khong ton tai!!!");
    }
}
void suaTenSach(Sach *sach,int soluong){
	int bienKT=0;
	char maSach[30];
	printf("\n   SUA CHI TIET SACH ");
	printf("\n   Nhap ma sach can sua :");
	fflush(stdin);
	gets(maSach);
	for(int i=0;i<soluong;i++){
		if(strcmp((sach+i)->maSach,maSach)==0){	        
	        printf("\n   Nhap ten sach: ");	
		    gets((sach+i)->tenSach);
	        printf("\n   Da sua xong ");
		    bienKT++;
		}    
	}
    if(bienKT==0){
	    printf("\n   Ma sach khong ton tai!!!");
	}
}
void ghiFile(Sach *danhsach, int soluong){
	getchar();
    char fPath[100]="sach.bin";       
	FILE* fOut = fopen(fPath, "wb");
	if(fOut==NULL){
		printf("\n Loi tao, mo file!");
		exit(1);
	}
	fprintf(fOut, "%-15s|| %-10s|| %-10s|| %-10s|| %-10s\n", "Ma sach", "Ten sach", "The loai", "Nha xuat ban", "Tong so luong");
	for(int i = 0;i<soluong; i++) {
		fprintf(fOut, "%-15s|| %-10s|| %-10s|| %-10s|| %-10d\n", (danhsach+i)->maSach, (danhsach+i)->tenSach, (danhsach+i)->theLoai, (danhsach+i)->nxb, (danhsach+i)->tongSoLuong);
	}
	printf("\n  Luu file thanh cong");
	fclose(fOut);
}
void pressAnyKey(){
    printf("\n\n   Bam phim bat ky de tiep tuc...");
    getch();
    system("cls");
}



