#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define oxp 110
#define oxt 3
#define oyd 25
#define oyt 1
#define ngan 40
int diem=0,m=0;
void ClearConsoleToColors(int ForgC, int BackC);//
void xoacontro();//
void TextColor(int x);//
void ToaDo(int x,int y);//
void vetuong();//
void vitridoituong(int x0,int y0,int toadox[],int toadoy[]);//
void taodoituong(int toadox[],int toadoy[]);//
void khoitaodoituong(int x0,int y0,int toadox[],int toadoy[]);//
void xoa(int toadox[],int toadoy[]);//
void taovatcan(int ycan,int dodai);//
void xoavatcan(int ycan,int dodai);//
void hamhuy();//
void sl(int &dodai);//
void sulyvacham();//
void tinhdiem(int ycan,int ycan1,int ycan2,int can3);//



int main(){
	int menu,luachon=4,p,level;
	char tennguoichoi[100];
	ClearConsoleToColors(4,11);
	
		
	 do{
	 fflush(stdin);
	 ToaDo(50,3);
	 printf("GameNgu");
	 ToaDo(50,4);
	 printf("Huong dan cach choi(1)");
	 ToaDo(50,5);
	 printf("Bat dau choi(2)");
	 ToaDo(50,7);
	 printf("Lua chon nao :");
	 do{
	 
	  scanf("%d",&luachon);
	  if(luachon!=1&&luachon!=2){
	  	ToaDo(50,7);
	    printf("Lua chon lai nao :");
	  }
      }while(luachon!=1&&luachon!=2);
      if(luachon==1){
      	system("cls");
      	printf("dung phim mui ten sang trai hoac sang phai de dieu khien \nthang ngu tranh va phai nhung vat dang chay xuong \nbam phim mui ten di len de tang toc do chay cua thang ngu");
      	printf("\n\nbam mot so bat ki de quay lai ");
      	scanf("%d",&p);
      	
	  }
	  else if(luachon==2){
	  	ToaDo(50,9);
	  	fflush(stdin);
	  	printf("Nhap ten nguoi choi :");
	  	fgets(tennguoichoi,99,stdin);
	  	ToaDo(50,11);
	  	printf("Cac cap do choi");
	  	ToaDo(50,12);
	  	printf("De(7)");
	  	ToaDo(50,13);
	  	printf("Kho vd(8)");
	  	ToaDo(50,14);
	  	printf("lua chon cap do :");
	  	do{
		  
	  	 scanf("%d",&level);
	  	 if(level!=7&&level!=8){
	  	 	ToaDo(50,14);
	  	    printf("lua chon lai cap do :");
		   }
	  	 
	    }while(level!=7&&level!=8);
	  }
	  system("cls");
    }while(luachon!=2);
    do{
	
    if(luachon==2){
	
	vetuong();
	char kitu;
	int i=0,x0=20,y0=20,toadox[100],toadoy[100],check=0,speed;
	int dodai,dodai1,dodai2,dodai3,a=1,ycan=13,ycan1=8,ycan2=3,ycan3=2,k=0;
	ToaDo(60,11);
    printf("diem %d",diem);	
    ToaDo(60,9);
    printf("Nguoi choi : %s\n",tennguoichoi);
    if(level==7){
    	ToaDo(60,13);
    	printf("Level easy vl");
    	speed=250;
	}
	else if(level==8){
		ToaDo(60,13);
		printf("Level hard");
		speed=200;
	}
    
    
    khoitaodoituong(x0, y0, toadox,toadoy);
	xoacontro();
	srand(time(NULL));
	dodai=5+rand()%16;
	dodai1=5+rand()%16;
	dodai2=5+rand()%16;
	dodai3=5+rand()%16;
	taovatcan(ycan,dodai);
	taovatcan(ycan1,dodai1);
	taovatcan(ycan2,dodai2);
	
	while(1){
		Sleep(speed);
		
		if(ycan<=21){
			xoavatcan(ycan,dodai);
			ycan++;
			taovatcan(ycan,dodai);
			
		}
		if(ycan1<=21){
			xoavatcan(ycan1,dodai1);
			ycan1++;
			taovatcan(ycan1,dodai1);
			
		}
		if(ycan2<=21){
			xoavatcan(ycan2,dodai2);
			ycan2++;
			taovatcan(ycan2,dodai2);
			
		}
		if(k!=0){
			xoavatcan(ycan3,dodai3);
			ycan3++;
			taovatcan(ycan3,dodai3);
		}
		if(ycan==22){
			ycan=2;
			sl(dodai);
		}
		if(ycan1==22){
			ycan1=2;
			sl(dodai1);
		}
		if(ycan2==22){
			ycan2=2;
			sl(dodai2);
		}
		if(ycan==17||ycan1==17||ycan2==17||ycan3==17){
			k++;
		}
		if(ycan3==22){
			ycan3=2;
			sl(dodai3);
		}
	
		while(kbhit()){
			Sleep(0);
    		kitu=getch();
    		if(kitu==-32){
    			kitu=getch();
    			if(kitu==75){//sang trai
    			check=0;
				}
				else if(kitu==77){//sang phai
				    check=1;
				}
				else if(kitu==72&&check==0){
					x0=x0-2;
				}
				else if(kitu==72&&check==1){
					x0=x0+2;
				}
			}
		}
		    xoa(toadox,toadoy);
		if(check==0){//sang trai
				x0=x0-1;
			}
    	else if(check==1){//sang phai
				x0=x0+1;
			}
		
		khoitaodoituong(x0,y0,toadox,toadoy);
		
		if((ycan==20&&(dodai+5>toadox[i]||dodai+9<=toadox[1]))||(ycan1==20&&(dodai1+5>toadox[i]||dodai1+9<=toadox[1]))||(ycan2==20&&(dodai2+5>toadox[i]||dodai2+9<=toadox[1]))||(ycan3==20&&(dodai3+5>toadox[i]||dodai3+9<=toadox[1])))
		{
		ToaDo(20,10);
		printf("GameOver");
		ToaDo(60,15);
		printf("bam 0 de thoat hoac bam 9 de choi lai :");
		do{
			scanf("%d",&menu);
			if(menu!=0&&menu!=9){
				ToaDo(60,15);
		        printf("bam 0 de thoat hoac bam 9 de choi lai :");
			}
		}while(menu!=0&&menu!=9);
		 if(menu==0){
		 	break;
		 }
		 else if(menu==9){
		 	diem=0;
		 	break;
		 }
	    }

		tinhdiem(ycan,ycan1,ycan2,ycan3);
		hamhuy();
	    }
       }
       system("cls");
 }while(menu==9);
 
 // da thoat game
	system("cls");
	ToaDo(50,10);
	printf("GameOver");
	if(diem>=0&&diem<20){
		ToaDo(50,12);
		printf("Choi ga vl");
	}
	else {
		ToaDo(50,12);
		printf("Choi kha ra phet day");
	}
	ToaDo(0,27);
	printf("");
	getch();
	return 0;
}




void tinhdiem(int ycan,int ycan1,int ycan2,int ycan3)
{
	if(ycan==20||ycan1==20||ycan2==20||ycan3==20){
		diem=diem+1;
		printf("\a");
	}
	ToaDo(60,11);
	printf("diem %d",diem);
}
void sl(int &dodai)
{
	srand(time(NULL));
	dodai=5+rand()%16;
}
void hamhuy(){
	int i=0;
	ToaDo(5,22);
	for(i;i<35;i++){
		printf(" ");
	}
}
void taovatcan(int ycan,int dodai)
{    
    int i;
	ToaDo(5,ycan);//(4;11)
	for(i=0;i<dodai;i++){
		Sleep(0);
		printf("=");
	}
	ToaDo(dodai+9,ycan);
	for(i=0;i<31-dodai;i++){
		Sleep(0);
		printf("=");
	}
}
void xoavatcan(int ycan,int dodai)
{
	int i;
	ToaDo(5,ycan);//(4;11)
	for(i=0;i<dodai;i++){
		Sleep(0);
		printf(" ");
	}
	ToaDo(dodai+9,ycan);
	for(i=0;i<31-dodai;i++){
		Sleep(0);
		printf(" ");
	}
}
void xoa(int toadox[],int toadoy[])
{
	int i=0;
	for(i;i<4;i++){
		ToaDo(toadox[i],toadoy[i]);
		printf(" ");
	}
}
void khoitaodoituong(int x0,int y0,int toadox[],int toadoy[]){
	vitridoituong(x0,y0,toadox,toadoy);
	taodoituong(toadox,toadoy);
}
void vetuong(){
	int i=0;
	//ve tuong tren
	for(i=oxt;i<oxp;i++){
		ToaDo(i,oyt);
		printf("=");
	}
	//ve tuong duoi
	for(i=oxt;i<oxp;i++){
		ToaDo(i,oyd);
		printf("=");
	}
	//ve tuong trai
	for(i=oyt+1;i<oyd;i++){
		ToaDo(oxt,i);
		printf("||");
	}
	//ve tuong phai
	for(i=oyt+1;i<oyd;i++){
		ToaDo(oxp-2,i);
		printf("||");
	}
	//ve o ngan diem
	for(i=oyt+1;i<oyd;i++){
		ToaDo(ngan,i);
		printf("||");
	}
}


void xoacontro()
{
 CONSOLE_CURSOR_INFO Info;
 Info.bVisible = FALSE;
 Info.dwSize = 20;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void ToaDo(int x,int y)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tinh = {x,y} ;
	SetConsoleCursorPosition(mau,tinh ) ;
}
void taodoituong(int toadox[],int toadoy[]){
	int i=0;
	for(i;i<4;i++){
		if(i>=0&&i<=1){
			ToaDo(toadox[i],toadoy[i]);
			printf("#");
		}
		else {
			ToaDo(toadox[i],toadoy[i]);
			printf("@");
		}
	}
	
}
void vitridoituong(int x0,int y0,int toadox[],int toadoy[]){
	int i=0;
	for(i;i<2;i++){
		// gan toa do x
		toadox[i]=x0;
		toadoy[i]=y0;
		x0++;
	}
	for(i=3;i>=2;i--){
		toadox[i]=x0-1;
		toadoy[i]=y0+1;
		x0--;
	}
}
void ClearConsoleToColors(int ForgC, int BackC)
{// doi mau console
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;            
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {                         
         FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
         FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );                       
         SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
} 
