//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop		 //
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <process.h>
#pragma resource "*.dfm"
#include "PngImage.hpp"
#include <stdio.h>
#include <conio.h>                            //
#include <string.h>
HANDLE dll = LoadLibrary("GsomRunner.dll");
HANDLE png_storage = LoadLibrary("Png_Storage.dll");
HANDLE new_style = LoadLibrary("new_style.dll");
HANDLE zzz = LoadLibrary("zst.dll");
using namespace std;
//local                              //      //
int bytes_read;
char buff[1024]; //
SOCKET sock,listener;
void ServerReadThread(void* pParams);
void ClientReadThread(void* pParams);
struct TQuestion
{
 char quest[500]; //
 char v1[450];
 char v2[450];
 char v3[450];
 char v4[450];             //
 int option;
};
TQuestion Question[50];
struct TAch
{
 int Number;
 String Rank;
};
struct TDescription
{
 String Description;
 int Number;
 int NumAll[10];
};
struct TAchievement
{
 TAch Kill[6];
 TAch Plazm[6];
 TAch Luck[5];
 TAch Good[5];
 TAch MoneyMan[4];
 TDescription Option[6];
};
TAchievement Rank;
struct TBomb          ////
{
 int index_bomb;
 int bomb_x;
 int bomb_y;
 bool active;
};
TBomb Bomb[50];
//void** array = (void**)malloc(70 * sizeof(Graphics::TBitmap*));//выделели место для массива битмап 
char str_bomb[8] = {"bomb_a1"};
int max_bomb = 0;
TForm1 *Form1;

/////////ВЫДЕЛЕНИЕ МЕСТА ПОД ПНГ!1 
Graphics::TBitmap *test = new Graphics::TBitmap();
//Graphics::TBitmap *test1 = new Graphics::TBitmap();
TPngImage* saver_png = new TPngImage;
Graphics::TBitmap* saver_bmp = new Graphics::TBitmap();
TPngImage *test2= new TPngImage;
Graphics::TBitmap *f_ = new Graphics::TBitmap();  //invisible
TPngImage *knopk = new TPngImage;
TPngImage *FON_BIT = new TPngImage;
TPngImage *gsom = new TPngImage;
TPngImage *ex1 = new TPngImage;
TPngImage *ex2 = new TPngImage;
Graphics::TBitmap* qaz = new Graphics::TBitmap();
//дальше идёт увеличение быстродействия
//засчёт выделения большего объёма оперативной памяти
//анимация чела!!1
TPngImage *a1 = new TPngImage;TPngImage *a2 = new TPngImage;TPngImage *a3 = new TPngImage;TPngImage *a4 = new TPngImage;TPngImage *a5 = new TPngImage;TPngImage *a6 = new TPngImage;TPngImage *a7 = new TPngImage;TPngImage *a8 = new TPngImage;
Graphics::TBitmap *a1_ = new Graphics::TBitmap();Graphics::TBitmap *a2_ = new Graphics::TBitmap();Graphics::TBitmap *a3_ = new Graphics::TBitmap();Graphics::TBitmap *a4_ = new Graphics::TBitmap();Graphics::TBitmap *a5_ = new Graphics::TBitmap();Graphics::TBitmap *a6_ = new Graphics::TBitmap();Graphics::TBitmap *a7_ = new Graphics::TBitmap();Graphics::TBitmap *a8_ = new Graphics::TBitmap();
//анимация челов!!1
TPngImage *b0 = new TPngImage;TPngImage *b2 = new TPngImage;TPngImage *b3 = new TPngImage;TPngImage *b4 = new TPngImage;TPngImage *b5 = new TPngImage;TPngImage *b6 = new TPngImage;TPngImage *b7 = new TPngImage;TPngImage *b8 = new TPngImage;
Graphics::TBitmap *b0_ = new Graphics::TBitmap();Graphics::TBitmap *b2_ = new Graphics::TBitmap();Graphics::TBitmap *b3_ = new Graphics::TBitmap();Graphics::TBitmap *b4_ = new Graphics::TBitmap();Graphics::TBitmap *b5_ = new Graphics::TBitmap();Graphics::TBitmap *b6_ = new Graphics::TBitmap();Graphics::TBitmap *b7_ = new Graphics::TBitmap();Graphics::TBitmap *b8_ = new Graphics::TBitmap();
// ЛАПАТА!! (тут надо смеяться)
TPngImage *LP1 = new TPngImage;TPngImage *LP2 = new TPngImage;TPngImage *LP3 = new TPngImage;TPngImage *LP4 = new TPngImage;TPngImage *LP5 = new TPngImage;TPngImage *LP6 = new TPngImage;TPngImage *LP7 = new TPngImage;TPngImage *LP8 = new TPngImage;TPngImage *LP9 = new TPngImage;Graphics::TBitmap *LP1_ = new Graphics::TBitmap();
Graphics::TBitmap *LP2_ = new Graphics::TBitmap();Graphics::TBitmap *LP3_ = new Graphics::TBitmap();Graphics::TBitmap *LP4_ = new Graphics::TBitmap();Graphics::TBitmap *LP5_ = new Graphics::TBitmap();Graphics::TBitmap *LP6_ = new Graphics::TBitmap();Graphics::TBitmap *LP7_ = new Graphics::TBitmap();Graphics::TBitmap *LP8_ = new Graphics::TBitmap();Graphics::TBitmap *LP9_ = new Graphics::TBitmap();
////////////////////////// // наоборот
TPngImage *L1P = new TPngImage;TPngImage *L2P = new TPngImage;TPngImage *L3P = new TPngImage;TPngImage *L4P = new TPngImage;TPngImage *L5P = new TPngImage;TPngImage *L6P = new TPngImage;TPngImage *L7P = new TPngImage;TPngImage *L8P = new TPngImage;TPngImage *L9P = new TPngImage;
Graphics::TBitmap *L1P_ = new Graphics::TBitmap();Graphics::TBitmap *L2P_ = new Graphics::TBitmap();Graphics::TBitmap *L3P_ = new Graphics::TBitmap();Graphics::TBitmap *L4P_ = new Graphics::TBitmap();Graphics::TBitmap *L5P_ = new Graphics::TBitmap();Graphics::TBitmap *L6P_ = new Graphics::TBitmap();Graphics::TBitmap *L7P_ = new Graphics::TBitmap();Graphics::TBitmap *L8P_ = new Graphics::TBitmap();Graphics::TBitmap *L9P_ = new Graphics::TBitmap();
//для лазейки
TPngImage *l1 = new TPngImage;TPngImage *l2 = new TPngImage;TPngImage *l3 = new TPngImage;TPngImage *r1 = new TPngImage;TPngImage *r2 = new TPngImage;TPngImage *r3 = new TPngImage;TPngImage *g4 = new TPngImage;
Graphics::TBitmap *l1_ = new Graphics::TBitmap();Graphics::TBitmap *l2_ = new Graphics::TBitmap();Graphics::TBitmap *l3_ = new Graphics::TBitmap();Graphics::TBitmap *r1_ = new Graphics::TBitmap();Graphics::TBitmap *r2_ = new Graphics::TBitmap();Graphics::TBitmap *r3_ = new Graphics::TBitmap();Graphics::TBitmap *g4_ = new Graphics::TBitmap();
TPngImage *vr1 = new TPngImage;TPngImage *vr2 = new TPngImage;TPngImage *vr3 = new TPngImage;TPngImage *vl1 = new TPngImage;TPngImage *vl2 = new TPngImage;TPngImage *vl3 = new TPngImage;
Graphics::TBitmap *vr1_ = new Graphics::TBitmap();Graphics::TBitmap *vr2_ = new Graphics::TBitmap();Graphics::TBitmap *vr3_ = new Graphics::TBitmap();Graphics::TBitmap *vl1_ = new Graphics::TBitmap();Graphics::TBitmap *vl2_ = new Graphics::TBitmap();Graphics::TBitmap *vl3_ = new Graphics::TBitmap();
//для локалки
//лазейка
TPngImage *vr1l = new TPngImage;TPngImage *vr2l = new TPngImage;TPngImage *vr3l = new TPngImage;TPngImage *vl1l = new TPngImage;TPngImage *vl2l = new TPngImage;TPngImage *vl3l = new TPngImage;
Graphics::TBitmap *vr1l_ = new Graphics::TBitmap();Graphics::TBitmap *vr2l_ = new Graphics::TBitmap();Graphics::TBitmap *vr3l_ = new Graphics::TBitmap();Graphics::TBitmap *vl1l_ = new Graphics::TBitmap();Graphics::TBitmap *vl2l_ = new Graphics::TBitmap();Graphics::TBitmap *vl3l_ = new Graphics::TBitmap();
//фиолетовый чел
TPngImage *al1 = new TPngImage;TPngImage *al2 = new TPngImage;TPngImage *al3 = new TPngImage;TPngImage *bl1 = new TPngImage;TPngImage *bl2 = new TPngImage;TPngImage *bl3 = new TPngImage;
Graphics::TBitmap *al1_ = new Graphics::TBitmap();Graphics::TBitmap *al2_ = new Graphics::TBitmap();Graphics::TBitmap *al3_ = new Graphics::TBitmap();Graphics::TBitmap *bl1_ = new Graphics::TBitmap();Graphics::TBitmap *bl2_ = new Graphics::TBitmap();Graphics::TBitmap *bl3_ = new Graphics::TBitmap();
TPngImage *bl5 = new TPngImage;
//////////
TPngImage *gsom49_ = new TPngImage;TPngImage *gsom50_ = new TPngImage;TPngImage *gsom51_ = new TPngImage;TPngImage *gsom52_ = new TPngImage;TPngImage *gsom48_ = new TPngImage;
Graphics::TBitmap *gsom49 = new Graphics::TBitmap();Graphics::TBitmap *gsom50 = new Graphics::TBitmap();Graphics::TBitmap *gsom51 = new Graphics::TBitmap();Graphics::TBitmap *gsom52 = new Graphics::TBitmap();Graphics::TBitmap *gsom48 = new Graphics::TBitmap();
TPngImage *g1 = new TPngImage;TPngImage *g2 = new TPngImage;			////
Graphics::TBitmap *g1_ = new Graphics::TBitmap();Graphics::TBitmap *g2_ = new Graphics::TBitmap();
  //отведение места под велосипед
int X=4,Y=22; // коордионаты в массиве                                                                                                                               //
int X1=0,Y1=0;     //3*5=15 - переменные на анимацию (-3 - 3)
int anim=0;//номер иконки анимации
int score=0;    //очки
int lives = 5;                      //////
int scrlvl =0;
int lvl=1;
int logic=0; //пауза
//Разрешение экрана!!
int gx=1024;//будет смена в опциях
int gy=758;
int mx=66;
int my=33;
int zs_i = 1;
//для нажатия кнопок
bool key_;
int v = (gx-((gx/mx)*mx))/2;//для того чтоб было посередине(для красоты)

int screenH;
int screenW;
//
//const int LvlExpMax[50]= {0,10,12,14,16,18,20,22,24};

int timem=0,times=0;
AnsiString timestr;

bool local_lp = 0;

int herolvl=1;   int exp_ = 0;
int exp_point = 0;

int np=0; //направление (-1 - 1)
		 //анимация лопаты (открыть)
int Nl=0;           //сколько одновременно выполняющихся анимаций
int Na[10];         //номер кадра
int ax[10];    //х
int ay[10];        //у
  //анимация лопаты (закрыть)
int bx[30];    //х
int by[30];        //у
int btime[30];               //время до закрытия дыр
int ba[30];        //  //анимация покадрово
int b=0;          //счётчик (сколько дыр)
//выделение места под плохих челов
int vx[50];
int vy[50];
int vnp[50];    // направление движения
int vx1[50];               //
int vy1[50];
int va[50];     //анимация
int vhard=0;     //
bool vxy2[99][198]; //массив также для врагов, с его помощью они не накладываются друг на друга
int maxquest=0;
char Str_Question[500];
bool prezent = 1;
int current_quest=0;
int true_question = 0;  //
WORD Key;                //служебная (обработчик нажатия кнопок)
WORD key_local;
bool capt[33][66];      // анимация вывода лвла на экран
int max_captС=0;
int trening = 0;
bool zst=0;
int kick = 0;
//тут для локальной сети
bool local_seting = 0;     //подключен ли клиент?(для клиента)
AnsiString local_key;      //какая кнопочка у нас нажата в клиенте(для сервера)
bool conecting = 0;        //подключен ли клиент?(для сервера)
bool load_local_lvl = 0;   //загружен ли левел(для клиента и сервера) больше ненужна??
int llx = 0;
int lly = 0;
int anim1=1;
bool local_lopata = 0;
int Xl=15,Yl=1,Yl1=0,Xl1=0;
bool local_logic_key = 0;   //логическая для кнопок, нажата ли кнопка?(для клиента)
int local_np;
int menu = 0;
//0 стопэ
//1 влево                                                //
//2 вправо
//3 вверх
//4 вниз
char lv1[33][66];
char b1[33][66];  // ai     возможные пути
int c[33][66];    //массив с готовым путём
int sx=0;        //служебная для ai
//уровень.. они будут в файликах
char lv[33][66]; //тут наш лвл

///*				 //прототипы функций
void vxy2f_0(int);
void frendlvl();
void scrl();//функция подсчёта алмазов на уровне
void animR(); // объявление функции прорисовки персонажа вправо
void animL();
void lopata(int);
void antilopata(int);
void animL1();
void animR1();
//void LOCAL_BIN_OFF();
//void LOCAL_BIN_ON();     ////
void local_give_str();
void bombs();
void wa(int);
void waL(int);
void func1(); //изначально возможные пути из начальных коордионат
void func();    //прощитывание всех возможных путей в масиве
int min(int,int);            //
void lvlload();
void qwe(int, int);
int rand_q=-1;       //*/
TImage *Im1;// указатели на компоненты!!!
TImage *Im2;
TImage *Im3;
TImage *Im4;
TImage *Im5;
TImage *Im6;
TImage *Im7;
TImage *Im8;
TImage *Im9;
TLabel *Lb10;
TImage *Im10;
TImage *Im11;
TImage *Im12;
TImage *Im13;
TImage *Im14;
TImage *Im15;
TImage *Im16;
TTimer *Tim1;
TTimer *Tim2;
TTimer *Tim3;
TTimer *Tim4;
TTimer *Tim5;
TTimer *Tim6;         ///
TTimer *Tim7;
TEdit *Ed1;
#include "Gsom_Class.h"
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) //ОСНОВНАЯ программа (ВЫПОЛНЯЕТСЯ 1 РАЗ)
	: TForm(Owner)
{
  screenW = GetSystemMetrics(SM_CXSCREEN);//Получить ширину экрана
  screenH = GetSystemMetrics(SM_CYSCREEN);//Получить высоту экрана
   DEVMODE dm;
 dm.dmPelsWidth = 1024;
 dm.dmPelsHeight = 768;       //разрешение   и подобные дальше строки тоже разрешения
 dm.dmFields = DM_PELSWIDTH |DM_PELSHEIGHT;
 ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY);//
  knopk->LoadFromResourceName((unsigned int)new_style,"exit_up");
 Image13->Canvas->Draw(0,0,knopk);          //кнопочки
  knopk->LoadFromResourceName((unsigned int)new_style,"upd_up");
 Image14->Canvas->Draw(0,0,knopk);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)   //ПАДЕНИЕ!!!!!!!!!
{  ///*
// if(ClientSocket1->Active == 0)//
 if((lv[Y+1][X]!=49 && lv1[Y+1][X]!=20 && Y!=32 && lv[Y+1][X]!=51 && (lv[Y][X]!='4' || (lv[Y][X]=='4' && Y1>0 ))) ||
 (lv[Y][X]!=51 && Y1<=-1) )
 {
  if(lv[Y][X]==50)     //очки score   //
  {
   Image1->Canvas->StretchDraw(Rect(X*(gx/mx)+v,Y*(gy/my),(X*(gx/mx))+(gx/mx)+v,(Y*(gy/my))+(gy/my)),FON_BIT);
   score++;
   lv[Y][X]=0;
  }
  Y1++;
  if(Y1==3) {Y1=0;Y++;}  //0-3 позиций иконки(5*3=15)
  Image2->Top = ((Y*(gy/my))+(Y1*((gy/my)/3)));
  Image2->Left = ((X*(gx/mx)+v)+(X1*((gx/mx)/3)));
  anim=0;
  animR();
 }
 //серверная часть
 /*
 if(local_seting == 1 && ClientSocket1->Active == 0)
 if((lv[Yl+1][Xl]!=49 && lv1[Yl+1][Xl]!=20 && Yl!=32 && lv[Yl+1][Xl]!=51 && (lv[Yl][Xl]!='4')) || (lv[Yl][Xl]!=51 && Yl1<=-1))
 if(vxy2[(Yl*3)+Yl1+2][(Xl*3)+Xl1+1]!=true && vxy2[(Yl*3)+Yl1+2][(Xl*3)+Xl1-1]!=true)
 {    //падение локального чела
  lv1[Yl][Xl] = 0;
 // LOCAL_BIN_OFF();
  Yl1++;
  lv1[Yl][Xl] = 20;
  if(Yl1==3) {lv1[Yl+1][Xl] = 20;lv1[Yl][Xl] = 0;Yl1=0;Yl++;}  //0-3 позиций иконки(5*3=15)
 // LOCAL_BIN_ON();
  Image4->Top = ((Yl*(gy/my))+(Yl1*((gy/my)/3)));
  Image4->Left = ((Xl*(gx/mx)+v)+(Xl1*((gx/mx)/3)));
  anim1=0;
  animR1();
 }    // */

//начало велосипеда с анимацией..
 if(Nl>0)
 {                          //
  for(int n=0;n<Nl;n++)
  {
  //гдето выше или ниже косяк который я так и ненашёл
   if(ax[n]>0 && ay[n]<33)//он не исправлен, и этот иф исправляет его(но не предотвращает)
	lopata(n);  //функция выводит на экран кадр анимации
   Na[n]++;
   if(Na[n]==11)
   {
	Nl--;
	if(n!=0)
	 n--;
	for(int m=1;m<10;m++)
	{
	 ax[m-1]=ax[m];
	 ay[m-1]=ay[m]; //можно было лучше очередь сделать
	 Na[m-1]=Na[m];
	}
   }
  }
 }
  for(int n=0;n<b;n++)
  {
   if(btime[n]<=0)
   {
	if(by[n]>0 && by[n]<33)  //таже коляска... непойму где баг
	 antilopata(n);
	ba[n]++;
	if(ba[n]==11)
	{
	 lv[by[n]][bx[n]]=49; //чтото невероятное
	 b--;
	 if(n==0)
	 {
	  n--;
	  for(int m=1;m<30;m++)  //это стек ... сортируем
	  {                      //это не стек... это хуйня
	   bx[m-1]=bx[m];        //вместе этого надо сделать очередь нормальную
	   by[m-1]=by[m];
	   btime[m-1]=btime[m];
	   ba[m-1]=ba[m];
	  }
	 }
	}
   }
  }
}
//---------------------------------------------------------------------------

				////
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 //Label1->Caption = lv[Y][X-1];
 int n=0;
 static int *badboys = new int [vhard];  //очень интересная переменная, без неё челы будут застревать
 for(n=0;n<vhard;n++)
  badboys[n]++;
 for(n=0;n<vhard;n++)
 if(lv[vy[n]][vx[n]]==49)      //убийство челов
 {
  vxy2f_0(n);
  Rank.Option[0].Number++; //досижения
  Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
  lv1[vy[n]][vx[n]]=0;
  vx[n]=random(65)+1;
  vy[n]=1;
  vx1[n]=0;
  vy1[n]=0;
  vnp[n]=1;
  //ниже добавление exp
  /*
  exp_++;
  Image7->Width = ((200/LvlExpMax[lvl])*exp_);
  if(exp_>=LvlExpMax[lvl])
  {
   exp_=0;
   hero_lvl++;
   Label7->Caption = lvl;
   exp_point++;
   current_quest=0;
   Image7->Width = ((200/LvlExpMax[lvl])*exp_);
  }  //   /     */
 }        /*
 if(lv[Yl][Xl]==49)
 {
 // LOCAL_BIN_OFF();
  lv1[Yl][Xl]=0;
	 Xl = random(65)+1;
	 Yl = 1;
	 Yl1 = 0;
	 Xl1 = 0;
 }           */
 if(Y<=1)    //переход лвл на другой
 {
 lvl++;

  quest_(lvl);
  if(lvl==4)
  {
	Image8->Visible = true;
	Label10->Caption = "Правельных ответов "+(AnsiString)true_question+"\nПроцент правильности ответов "+FloatToStrF(((float)(true_question/(float)(5+true_question)*100)), ffFixed, 10, 2)+"\nРекомендуемая оценка "+(AnsiString)(1+lvl);
	Timer1->Enabled = false;
	Timer2->Enabled = false;
	Timer3->Enabled = false;                                                                                                //      8/13*100
	Timer4->Enabled = false;
	if(Key == VK_RETURN)
	{
		//Label1->Caption = (String)(int)(Timer5->Enabled);
		Image5->Visible = false;Image8->Visible = false;Image9->Visible = false;Image11->Visible = false;Image10->Visible = false;Image12->Visible = false;Image13->Visible = false;Image14->Visible = false;Image15->Visible = 0; Image7->Visible = true;Image6->Visible = true;Image16->Visible = 1;
		Timer1->Enabled=true;Timer2->Enabled=true;Timer3->Enabled=true;Timer4->Enabled=true;
		logic=1;local_seting = 0;
		anim=0;score=0;lives=5;scrlvl=0;current_quest=0;timem=0;times=0;np=0;lvl=1;exp_=0;herolvl=1;
		lvlload();outputlvl();rand_q=-1;return;
	}
  }


 lvlload();  //из файла
 gsom->LoadFromResourceName((unsigned int)dll,"a6");
 FON_BIT->LoadFromResourceName((unsigned int)dll,"a6");
 for(int y1=0;y1<33;y1++)
 {
  for(int x1=0;x1<66;x1++)
  {
   lv1[y1][x1]=0;
   b1[y1][x1]=0;
   c[y1][x1]=0;       //
  }
 }
  outputlvl();
   //Timer1->Enabled=false;
 //Timer2->Enabled=false;
 //Timer3->Enabled=false;
 //Timer4->Enabled=false;
  frendlvl();
  scrl();
 }
 int cx[50]; //конечное
 int cx1[50];
 int min1,min2;   // промежуточное
 for(n=0;n<vhard;n++)
 {
  min1=min(c[vy[n]+1][vx[n]],c[vy[n]-1][vx[n]]);   //тупейший алгоритм нахождения мнимального числа среди 4
  min2=min(c[vy[n]][vx[n]+1],c[vy[n]][vx[n]-1]);   //надо будет это переписать как нибудь
  cx1[n]=min(min1,min2);
   if(cx1[n]==c[vy[n]][vx[n]+1]){cx[n]=2;} //печалька
   if(cx1[n]==c[vy[n]][vx[n]-1]){cx[n]=1;}
   if(cx1[n]==c[vy[n]+1][vx[n]]){cx[n]=4;}
   if(cx1[n]==c[vy[n]-1][vx[n]]){cx[n]=3;}

   if(cx1[n]==0){cx[n]=0;}
 }
//движение ниже
 for(n=0;n<vhard;n++) //поднимаемся
 if(cx[n]!=3)
 {
 }
 else
 {
  if(lv1[vy[n]-1][vx[n]]!=20 && vx1[n]==0 && lv[vy[n]][vx[n]]==51)
  {
   if((vxy2[(vy[n]*3)-2+vy1[n]][(vx[n]*3)+1]!=true && vxy2[(vy[n]*3)-2+vy1[n]][(vx[n]*3)-1]!=true) || badboys[n] >= 3)
   {
	lv1[vy[n]][vx[n]] = 0;
	Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	vxy2f_0(n);
	vy1[n]--;  //пиксели
	vxy2f_1(n);   //функция против сталкивания и тп
	lv1[vy[n]][vx[n]] = 20;   // нах ненадо, нужно убрать
	if(vy1[n]==-3) {lv1[vy[n]-1][vx[n]] = 20;lv1[vy[n]][vx[n]] = 0;vy1[n]=0;vy[n]--;}
	vnp[n]=0;
	wa(n);
	badboys[n] = 0;
   }
  }
 }
  for(n=0;n<vhard;n++)           //опускаемся
  if(cx[n]!=4)
  {
  }
  else
  {      //lv1[vy[n]+1][vx[n]]!=20 &&
	 if((lv[vy[n]][vx[n]]==51 || lv[vy[n]+1][vx[n]]==51 || lv[vy[n]][vx[n]] == '4')  && vx1[n]==0 && lv[vy[n]+1][vx[n]]!=49)
	 {
	  if((vxy2[(vy[n]*3)+2+vy1[n]][(vx[n]*3)+1]!=true && vxy2[(vy[n]*3)+2+vy1[n]][(vx[n]*3)-1]!=true) || badboys[n] >= 3)
	  {
	   lv1[vy[n]][vx[n]] = 0;
	   Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	   vxy2f_0(n);
	   vy1[n]++;
	   vxy2f_1(n);
	   lv1[vy[n]][vx[n]] = 20;
	   if(vy1[n]==3) {lv1[vy[n]+1][vx[n]] = 20;lv1[vy[n]][vx[n]] = 0;vy1[n]=0;vy[n]++;}
	   vnp[n]=0;
	   wa(n);
	   badboys[n] = 0;          //
	  }
	 }
  }
 for(n=0;n<vhard;n++)          //ДВИЖЕНИЕ ВПРАВО!!!
 {
  if(cx[n]!=2 || (vy1[n]!=0 && lv[vy[n]][vx[n]]==51))
  {
  }
  else
  if(vy1[n]==0 && lv[vy[n]][vx[n]+1]!=49 && vx[n]<65 && (lv[vy[n]][vx[n]]== '4' || lv[vy[n]][vx[n]]==51 || lv[vy[n]+1][vx[n]]==49  || lv[vy[n]+1][vx[n]]==51 || lv1[vy[n]+1][vx[n]]==20 ||
  (vx1[n]!=0 && (lv[vy[n]+1][vx[n]+1]==49 || lv[vy[n]+1][vx[n]+1]==51))))
   if((vxy2[(vy[n]*3)+vy1[n]+1][(vx[n]*3)+vx1[n]+2]!=true && vxy2[(vy[n]*3)+vy1[n]-1][(vx[n]*3)+vx1[n]+2]!=true) || badboys[n] >= 3)
   {
	lv1[vy[n]][vx[n]] = 0;
	Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	vxy2f_0(n);
	vx1[n]++;
	vxy2f_1(n);
	lv1[vy[n]][vx[n]] = 20;
	cx[n]=0;
	if(vx1[n]==3) {lv1[vy[n]][vx[n]+1] = 20;lv1[vy[n]][vx[n]] = 0;vx1[n]=0;vx[n]++;}
	wa(n);
	  badboys[n] = 0;
   }
  }
 for(n=0;n<vhard;n++) // ДВИЖЕНИЕ ВЛЕВО!!
 {
  if(cx[n]!=1 || (vy1[n]!=0 && lv[vy[n]][vx[n]]==51))
  {
  }
  else
  if(vy1[n]==0 && lv[vy[n]][vx[n]-1]!=49 && vx[n]>1 && (lv[vy[n]][vx[n]]== '4' || lv[vy[n]][vx[n]]==51 || lv[vy[n]+1][vx[n]]==49 || lv[vy[n]+1][vx[n]]==51 || lv1[vy[n]+1][vx[n]]==20 ||
  (vx1[n]!=0 && (lv[vy[n]+1][vx[n]-1]==49 || lv[vy[n]+1][vx[n]-1]==51))))
   if((vxy2[(vy[n]*3)+vy1[n]+1][(vx[n]*3)+vx1[n]-2]!=true && vxy2[(vy[n]*3)+vy1[n]-1][(vx[n]*3)+vx1[n]-2]!=true)  || badboys[n] >= 3)
   {
	lv1[vy[n]][vx[n]] = 0;
	Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	vxy2f_0(n);
	vx1[n]--;
	vxy2f_1(n);
	lv1[vy[n]][vx[n]] = 20;
	cx[n]=0;
	if(vx1[n]==-3) {lv1[vy[n]][vx[n]-1] = 20;lv1[vy[n]][vx[n]] = 0;vx1[n]=0;vx[n]--;}
	waL(n);
	  badboys[n] = 0;
   }
  }
 for(n=0;n<vhard;n++) //ПАДЕНИЕ!!!                                //
  if(lv1[vy[n]+1][vx[n]]==20  || lv[vy[n]][vx[n]]=='4' || vx1[n]!=0)
  {
  }
  else
  if(lv[vy[n]+1][vx[n]]!=51 && lv[vy[n]+1][vx[n]]!=49 && vy[n]<32)
  {
   if((vxy2[(vy[n]*3)+vy1[n]+2][(vx[n]*3)+vx1[n]+1]!=true && vxy2[(vy[n]*3)+vy1[n]+2][(vx[n]*3)+vx1[n]-1]!=true) || badboys[n] >= 3)
   lv1[vy[n]][vx[n]] = 0;
   Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
   vxy2f_0(n);
   vy1[n]++;
   vxy2f_1(n);
   if(vy1[n]==3) {vy1[n]=0;vy[n]++;}
   lv1[vy[n]][vx[n]] = 20;
   va[n] = 0;
   wa(n);
   badboys[n] = 0;
  }          //   */ //дальше ВЫРАВНИВАЕМ всяких тормознутых чубриков
 // Label1->Caption = badboys[0]; (ЭТО ВЫРАВНИВАНИЕ И ВСЁ!!1)
  for(n=0;n<vhard;n++)
  {
   if((cx[n] == 4 || cx[n] == 3) && badboys[n] >= 3)
   {
	if(vx1[n]<0)            //вправо
	 if((vxy2[(vy[n]*3)+vy1[n]+1][(vx[n]*3)+vx1[n]+2]!=true && vxy2[(vy[n]*3)+vy1[n]-1][(vx[n]*3)+vx1[n]+2]!=true) || badboys[n]>=3)
	 {
	 lv1[vy[n]][vx[n]] = 0;
	 Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	 vxy2f_0(n);
	 vx1[n]++;
	 vxy2f_1(n);
	 lv1[vy[n]][vx[n]] = 20;
	 cx[n]=0;
	 if(vx1[n]==3) {lv1[vy[n]][vx[n]+1] = 20;lv1[vy[n]][vx[n]] = 0;vx1[n]=0;vx[n]++;}
	 wa(n);
	 badboys[n] = 0;
	}
   if(vx1[n]>0)      //влево
	if((vxy2[(vy[n]*3)+vy1[n]+1][(vx[n]*3)+vx1[n]-2]!=true && vxy2[(vy[n]*3)+vy1[n]-1][(vx[n]*3)+vx1[n]-2]!=true) || badboys[n]>=3)
	{
	lv1[vy[n]][vx[n]] = 0;
	Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	vxy2f_0(n);
	vx1[n]--;
	vxy2f_1(n);
	lv1[vy[n]][vx[n]] = 20;
	cx[n]=0;
	if(vx1[n]==-3) {lv1[vy[n]][vx[n]-1] = 20;lv1[vy[n]][vx[n]] = 0;vx1[n]=0;vx[n]--;}
	waL(n);
	badboys[n] = 0;
   }
  }
 }
   for(n=0;n<vhard;n++)
   {
	if(badboys[n] >=3 && (cx[n] == 2 || cx[n] == 1))
	{
	 if(vy1[n]<0)     //вниз
	  if((vxy2[(vy[n]*3)+2+vy1[n]][(vx[n]*3)+1]!=true && vxy2[(vy[n]*3)+2+vy1[n]][(vx[n]*3)-1]!=true) || badboys[n] >=3)
	 {
	  lv1[vy[n]][vx[n]] = 0;
	  Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	  vxy2f_0(n);
	  vy1[n]++;
	  vxy2f_1(n);
	  lv1[vy[n]][vx[n]] = 20;
	  if(vy1[n]==3) {lv1[vy[n]+1][vx[n]] = 20;lv1[vy[n]][vx[n]] = 0;vy1[n]=0;vy[n]++;}
	  vnp[n]=0;
	  wa(n);
	  badboys[n] = 0;
	 }
	 if(vy1[n]>0)       //вверх
	 if((vxy2[(vy[n]*3)-2+vy1[n]][(vx[n]*3)+1]!=true && vxy2[(vy[n]*3)-2+vy1[n]][(vx[n]*3)-1]!=true) || badboys[n] >=3)
	 {
	  lv1[vy[n]][vx[n]] = 0;
	  Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	  vxy2f_0(n);
	  vy1[n]--;
	  vxy2f_1(n);
	  lv1[vy[n]][vx[n]] = 20;
	  if(vy1[n]==-3) {lv1[vy[n]-1][vx[n]] = 20;lv1[vy[n]][vx[n]] = 0;vy1[n]=0;vy[n]--;}
	  vnp[n]=0;
	  wa(n);
	  badboys[n] = 0;
	 }
	}    //
   }///*
 if(lv1[Y][X]==20 || lv[Y][X]==49 || (lv[Y+1][X]==49 && Y1>0) || (lv[Y-1][X]==49 && Y1<0) || (lv[Y][X+1]==49 && X1>0) || (lv[Y][X-1]=='1' && X1<0)) //убийство
 {
  if(prezent == true)
  {
   Timer1->Enabled = false;
   Timer2->Enabled = false;
   Timer3->Enabled = false;
   Timer4->Enabled = false;
   Image8->Visible = true;
   Question__(Label10);
  }
  death();

 } //
  /*
 FILE *Fl;
 Fl = fopen("test.txt","w+");
  for(int n=0;n<33;n++)
  {
   for(int m=0;m<66;m++)
   {
	fprintf(Fl,"%3i",c[n][m]);
   }
   fprintf(Fl,"\n");
  }
 fclose(Fl);
 /*
  FILE *F2;
 F2 = fopen("test.txt","w+");
  for(int n=0;n<33;n++)
  {
   for(int m=0;m<66;m++)
   {
	fprintf(F2,"%3i",c[n][m]);
   }
   fprintf(F2,"\n");
  }
 fclose(F2);
   //*/



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
 if(b>0)
  for(int n=0;n<b;n++)
   btime[n]--;
 ////////////
 static char bin_s=0;
 if(bin_s==1) {times++;bin_s=0;timestr=":";} else {bin_s=1;timestr=" ";}  // для красоты
 if(times==60)
 {
  timem++;
  times=0;
 }
  Label4->Caption = IntToStr(timem)+"  "+IntToStr(times);    //красота то какая
  Label8->Caption = timestr;
 //upd
 //Label1->Caption = scrlvl;
 //незнал куда засунуть... засунул сюда...
 if(score>=scrlvl)
 {
 score = 0;
  gsom->LoadFromResourceName((unsigned int)dll,"a5");
  for(int n=0;n<33;n++)            //рисуем лесенку
   for(int m=0;m<66;m++)
   {
	if(lv[n][m]==53)
	{
	 lv[n][m]=51;
	 Image1->Canvas->StretchDraw(Rect(m*(gx/mx)+v,n*(gy/my),(m*(gx/mx))+(gx/mx)+v,(n*(gy/my))+(gy/my)),gsom);
	 Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	}
   }
	frendlvl();
 }           //*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{

  //дальше идёт генерация пути
  func1();                  //прощитывание изначально возможных путей
 for(int n=0;n<15;n++)
  func();                 //щитаем возможные пути во всём массиве    f
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   DEVMODE dm;
 dm.dmPelsWidth = screenW;
 dm.dmPelsHeight = screenH;
 dm.dmFields = DM_PELSWIDTH |DM_PELSHEIGHT;
 ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY);
 //ServerSocket1->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	DEVMODE dm;
 dm.dmPelsWidth = screenW;
 dm.dmPelsHeight = screenH;
 dm.dmFields = DM_PELSWIDTH |DM_PELSHEIGHT;
 ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY);
 //ServerSocket1->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{  /////* //дальше идёт перенос строк для вопросов, иначе будет всё печально

					  //*/

 /*
 String str;
 char* a = new char[33*66];
 for(int y = 0;y<33;y++)
  for(int x = 0;x<66;x++)
  {
   a[66*y+x] = lv[y][x];
  }
 //a[33*66] = '\n';
 str = a;
 Label1->Caption = str;*/
///*

 Rank.Option[0].Description = "Даётся за 20,100,300,600,1000 убитых врагов";
 Rank.Option[1].Description = "Даётся за 50,200,500,1000,2000 расплавленных стен";
 Rank.Option[2].Description = "Даётся за пройденый уровень без потери жизни 3,8,15,30";
 Rank.Option[3].Description = "Даётся за прохождение уровня не убив никого 1,3,6,10";
 Rank.Option[4].Description = "Даётся за сбор алмазов 100,500,1000";
 Rank.Option[0].NumAll[0] = 20; Rank.Option[0].NumAll[1] = 100; Rank.Option[0].NumAll[2] = 300; Rank.Option[0].NumAll[3] = 600; Rank.Option[0].NumAll[4] = 1000;
 Rank.Option[1].NumAll[0] = 50; Rank.Option[1].NumAll[1] = 200; Rank.Option[1].NumAll[2] = 500; Rank.Option[1].NumAll[3] = 1000; Rank.Option[1].NumAll[4] = 2000;
 Rank.Option[2].NumAll[0] = 3; Rank.Option[2].NumAll[1] = 8; Rank.Option[2].NumAll[2] = 15; Rank.Option[2].NumAll[3] = 30;
 Rank.Option[3].NumAll[0] = 1; Rank.Option[3].NumAll[1] = 3; Rank.Option[3].NumAll[2] = 6; Rank.Option[3].NumAll[3] = 10;
 Rank.Option[4].NumAll[0] = 100; Rank.Option[4].NumAll[1] = 500; Rank.Option[4].NumAll[2] = 1000; //
 Rank.Kill[0].Rank = "Охотник за головами";
 Rank.Kill[1].Rank = "Безжалостный Убийца";
 Rank.Kill[2].Rank = "Прирождённый Маньяк";
 Rank.Kill[3].Rank = "Жестокий Каратель";
 Rank.Kill[4].Rank = "Неумолимый";
 Rank.Plazm[0].Rank = "Раскопщик";     //
 Rank.Plazm[1].Rank = "Газосварщик";
 Rank.Plazm[2].Rank = "Асфальтоукладчик";
 Rank.Plazm[3].Rank = "Расщипитель";
 Rank.Plazm[4].Rank = "Плазморазрыхлитель";
 Rank.Luck[0].Rank = "Везунчик";
 Rank.Luck[1].Rank = "Неуловимый";
 Rank.Luck[2].Rank = "Бессмертный";
 Rank.Luck[3].Rank = "Теневой Мастер";
 Rank.Good[0].Rank = "Жалостливый";
 Rank.Good[1].Rank = "Добродушный";
 Rank.Good[2].Rank = "Милосердный";
 Rank.Good[3].Rank = "Святой";
///////////////////////////////////////////////////////////////////////
quest_(lvl);    //

 test2->LoadFromResourceName((unsigned int)dll,"a7");//синий фон
 f_->SetSize(gx/mx,gy/my);
 f_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),test2);
 knopk->LoadFromResourceName((unsigned int)new_style,"resume_up");Image9->Canvas->Draw(0,0,knopk);
 knopk->LoadFromResourceName((unsigned int)new_style,"new_up");Image11->Canvas->Draw(0,0,knopk);
 knopk->LoadFromResourceName((unsigned int)new_style,"save_up");Image10->Canvas->Draw(0,0,knopk);
 knopk->LoadFromResourceName((unsigned int)new_style,"load_up");Image12->Canvas->Draw(0,0,knopk);
 knopk->LoadFromResourceName((unsigned int)new_style,"local_up");Image15->Canvas->Draw(0,0,knopk);
 Image9->Visible = false;
 Image10->Visible = false;
 Image3->Transparent = true;

 BorderStyle = bsNone;
 WindowState = wsMaximized;

 Image1->Align = alClient;
 Image3->Align = alClient;
 Image5->Align = alClient;
 Image16->Align = alClient;


 Image2->Height = gy/my;
 Image2->Width = gx/mx;
 Image4->Height = gy/my;
 Image4->Width = gx/mx;
 Image7->Visible = false;
 Image6->Visible = false;
 Graphics::TBitmap *TmpBitmap;
 TmpBitmap = new Graphics::TBitmap();
 TmpBitmap->Width=1024;
 TmpBitmap->Height=768;
 TmpBitmap->Canvas->StretchDraw(TRect(0,0,1024,768),Form1->Image5->Picture->Graphic);
 Form1->Image5->Picture->Graphic=TmpBitmap;
 Form1->Image5->Refresh();
 delete TmpBitmap;
	DEVMODE pm;
 pm.dmPelsWidth = 1024;
 pm.dmPelsHeight = 768;
 pm.dmFields = DM_PELSWIDTH |DM_PELSHEIGHT;
 ChangeDisplaySettings(&pm, CDS_UPDATEREGISTRY);

 ex1->LoadFromResourceName((unsigned int)png_storage,"expbar1");
 ex2->LoadFromResourceName((unsigned int)png_storage,"expbar2");
 randomize();
 lvlload();
 Label7->Caption = lvl;
 Image7->Width = 1;
 Image6->Canvas->Draw(0,0,ex2);   //
 Image7->Canvas->Draw(0,0,ex1);
 Image2->Transparent = true;    //
 Image2->Top = Y*(gy/my);
 Image2->Left = X*(gx/mx)+v;
 Image4->Transparent = true;
 Image4->Top = Y1*(gy/my);
 Image4->Left = X1*(gx/mx)+v;
 Image3->Transparent = true;
 Label1->Top = 740;
 Label2->Top = 740;
 Label3->Top = 740;
 Label4->Top = 740;
 Label5->Top = 740;
 Label6->Top = 740;
 Label7->Top = 740;
 Label8->Top = 740;
 Image7->Top = 740;
 Image6->Top = 740;
 Image8->Transparent = true;
 //остальное перенёс в "начать новую игру"
  //увеличение производительности засчёт выделения большего кол-ва RAM
 init_img();

Image13->Top = 700;
Image12->Top = 665;
Image14->Top = 630;
Image15->Top = 595;
Image11->Top = 560;
Image10->Top = 525;
Image9->Top = 490;
Edit1->Top = 600;
 Im1 = &*Image1;
 Im2 = &*Image2;    //
 Im3 = &*Image3;
 Im4 = &*Image4;
 Im5 = &*Image5;
 Im6 = &*Image6;
 Im7 = &*Image7;
 Im8 = &*Image8;
 Im9 = &*Image9;
 Lb10 = &*Label10;
 Im10 = &*Image10;
 Im11 = &*Image11;
 Im12 = &*Image12;
 Im13 = &*Image13;
 Im14 = &*Image14;
 Im15 = &*Image15;
 Im16 = &*Image16;
 Tim1 = &*Timer1;  //
 Tim2 = &*Timer2;
 Tim3 = &*Timer3;
 Tim4 = &*Timer4;
 Tim5 = &*Timer5;
 Tim6 = &*Timer6;
 Ed1 = &*Edit1;
 Timer8->Enabled = 1;
}                   //
//---------------------------------------------------------------------------
	  //+++++++++++++++++++++++++//
void __fastcall TForm1::Image9MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{

 knopk->LoadFromResourceName((unsigned int)new_style,"resume_down");
 Image9->Canvas->Draw(0,0,knopk);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{

 knopk->LoadFromResourceName((unsigned int)new_style,"resume_up");
 Image9->Canvas->Draw(0,0,knopk);
   Image5->Visible = false;
   Timer1->Enabled = true;
   Timer2->Enabled = true;
   Timer3->Enabled = true;
   Timer4->Enabled = true;
   logic=1;
   Image9->Visible = false;
   Image10->Visible = false;
   Image11->Visible = false;
   Image12->Visible = false;
   Image13->Visible = false;
   Image14->Visible = false;
   Image16->Visible = 1;
   Image15->Visible = 0;
   Image7->Visible = true;
   Image6->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{

 knopk->LoadFromResourceName((unsigned int)new_style,"save_down");
 Image10->Canvas->Draw(0,0,knopk);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image10MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 knopk->LoadFromResourceName((unsigned int)new_style,"save_up");
 Image10->Canvas->Draw(0,0,knopk);
  ///*
 FILE *f;
 f = fopen("save.txt", "w+");
 fprintf(f, "%i %i %i %i %i %i %i %i %i ",lvl,lives,score,exp,herolvl,::X,::Y,X1,Y1);
 for(int n=0;n<vhard;n++)
  fprintf(f, "%i ",vx[n]);
 for(int n=0;n<vhard;n++)
  fprintf(f, "%i ",vy[n]);
 for(int n=0;n<33;n++)
   for(int m=0;m<66;m++)
	if(lv[n][m]=='2')
	 fprintf(f, "%c ",lv[n][m]);
	else
	 fprintf(f, "0 ");
	 fclose(f);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image11MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 knopk->LoadFromResourceName((unsigned int)new_style,"new_down");
 Image11->Canvas->Draw(0,0,knopk);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image11MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 if(menu == 0) //старт обычной новой игры
 {
  knopk->LoadFromResourceName((unsigned int)new_style,"new_up");
  Image11->Canvas->Draw(0,0,knopk);
  Image5->Visible = false;Image9->Visible = false;Image11->Visible = false;Image10->Visible = false;Image12->Visible = false;Image13->Visible = false;Image14->Visible = false;Image15->Visible = 0; Image7->Visible = true;Image6->Visible = true;Image16->Visible = 1;
  Timer1->Enabled=true;Timer2->Enabled=true;Timer3->Enabled=true;Timer4->Enabled=true;
  logic=1;  local_seting = 0;
  anim=0;score=0;lives=5;scrlvl=0;timem=0;times=0;np=0;lvl=1;exp_=0;herolvl=1;
  lvlload();
  FON_BIT->LoadFromResourceName((unsigned int)dll,"a6");
  for(int y1=0;y1<33;y1++)  // 33 и 66 зависит от размеров имаге 1 и 3
   for(int x1=0;x1<66;x1++)
   {
	lv1[y1][x1]=0;
	b1[y1][x1]=0;
	c[y1][x1]=0;
   }
  outputlvl();  //выводит уровень на экран
  Timer1->Enabled=1;
  Timer2->Enabled=1;
  Timer3->Enabled=1;
  Timer4->Enabled=1;
  Timer5->Enabled=1;
  frendlvl(); //первый раз общитываем все возможные пути
  scrl();  // /функция подсчёта алмазов на уровне     */
 }
 if(menu == 1)
 {
	WSADATA wData;//серверная часть
	int socket_name_size;
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	WSAStartup(MAKEWORD(2,0),&wData);
	listener=socket(AF_INET,SOCK_STREAM,NULL);	//create socket
	addr.sin_family=AF_INET;
	addr.sin_port=htons(3123);	//number port
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	socket_name_size=sizeof(addr);
	if(bind(listener,(struct sockaddr *)&addr,socket_name_size)<0){}
	listen(listener,1);
	_beginthread(ServerReadThread, 0, NULL);
	unsigned long a = GetLastError();
	Label1->Caption = a;
	//wData = NULL;
	//delete wData;
	logic=1;
	send(sock,"Hello! i am client!",strlen("Hello! i am client!"),0);
  Image5->Visible = false;Image11->Visible = false;Image13->Visible = false;Image15->Visible = 0;
  Image7->Visible = true;Image6->Visible = true;Image16->Visible = 1;

  //
  //logic=1;local_seting = 1;
  menu = 3;
  //send(sock,"Hello! i am server!",strlen("Hello! i am server!"),0);
  anim=0;score=0;lives = 5;scrlvl =0;timem=0;times=0;np=0;lvl=1;exp_=0;herolvl=1;
  lvlload();//
  FON_BIT->LoadFromResourceName((unsigned int)dll,"a6");
  for(int y1=0;y1<33;y1++)  // 33 и 66 зависит от размеров имаге 1 и 3
   for(int x1=0;x1<66;x1++)
   {
	lv1[y1][x1]=0;
	b1[y1][x1]=0;
	c[y1][x1]=0;
   }
  outputlvl();  //выводит уровень на экран
  Timer1->Enabled=true;Timer2->Enabled=true;Timer3->Enabled=true;Timer4->Enabled=true;Timer5->Enabled=true;
  frendlvl(); //первый раз общитываем все возможные пути
  scrl();  // /функция подсчёта алмазов на уровне
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image12MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 knopk->LoadFromResourceName((unsigned int)new_style,"load_up");
 Image12->Canvas->Draw(0,0,knopk);
  FILE *f;
 f = fopen("save.txt", "r+");
 fscanf(f, "%i",&lvl);
 lvlload();
 frendlvl();   //первый раз общитываем все возможные пути
 fscanf(f, "%i%i%i%i%i%i%i%i",&lives,&score,&exp,&herolvl,&::X,&::Y,&X1,&Y1);
 for(int n=0;n<vhard;n++)
  fscanf(f, "%i",&vx[n]);
 for(int n=0;n<vhard;n++)
  fscanf(f, "%i",&vy[n]);
  int hh;
 for(int n=0;n<33;n++)
  for(int m=0;m<66;m++)
  {
   fscanf(f, "%i",&hh);
   if(hh==0 && lv[n][m]==50)
	lv[n][m]=0;
  }                           // */
 fclose(f);
 f=NULL;
 delete f;
 outputlvl();
  Timer1->Enabled=false;
 Timer2->Enabled=false;
 Timer3->Enabled=false;
 Timer4->Enabled=false;
 scrl();
 animR();//вызов ф-ции анимация
 Image2->Top = ((::Y*(gy/my))+(Y1*((gy/my)/3)));
 Image2->Left = ((::X*(gx/mx)+v)+(X1*((gx/mx)/3)));
 for(int n=0;n<vhard;n++)
  wa(n);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image13MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 if(menu == 0)
 {
  knopk->LoadFromResourceName((unsigned int)new_style,"exit_up");Image13->Canvas->Draw(0,0,knopk);
  DEVMODE dm;
  dm.dmPelsWidth = screenW;
  dm.dmPelsHeight = screenH;
  dm.dmFields = DM_PELSWIDTH |DM_PELSHEIGHT;
  ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY);
  Form1->Close();
 }
 if(menu == 1)
 {
  knopk->LoadFromResourceName((unsigned int)new_style,"new_up");Image11->Canvas->Draw(0,0,knopk);
  Image12->Visible = 1;Image14->Visible = 1;//Image10->Visible = 1;
  menu = 0;
  knopk->LoadFromResourceName((unsigned int)new_style,"local_up");Image15->Canvas->Draw(0,0,knopk);
  knopk->LoadFromResourceName((unsigned int)new_style,"exit_up");Image13->Canvas->Draw(0,0,knopk);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image13MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 if(menu == 0)
 {
  knopk->LoadFromResourceName((unsigned int)new_style,"exit_down");Image13->Canvas->Draw(0,0,knopk);
 }
 if(menu == 1)
 {
  knopk->LoadFromResourceName((unsigned int)png_storage,"back_down");Image13->Canvas->Draw(0,0,knopk);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 knopk->LoadFromResourceName((unsigned int)png_storage,"load_down");
 Image12->Canvas->Draw(0,0,knopk);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
 if(trening > 0)
 {
  for(int n=0;n<33;n++)  // 33 и 66 зависит от размеров имаге 1 и 3
   for(int m=0;m<66;m++)
    Image1->Canvas->StretchDraw(Rect(m*(gx/66)+v,n*(gy/33),(m*(gx/66))+(gx/66)+v,(n*(gy/33))+(gy/33)),FON_BIT);
  switch(trening)
  {
   case 1:Label10->Caption = "Кнопка E или F отвечает за создание ловушки для преподователя!";knopk->LoadFromResourceName((unsigned int)png_storage,"scr2");trening++;Key=NULL;break;
   case 2:Label10->Caption = "Студент должен убегать от преподователей, или отвечать на их вопросы";trening++;Key=NULL;break;
   case 3:Label10->Caption = "Cтудент должен собрать все знания";knopk->LoadFromResourceName((unsigned int)png_storage,"scr3");trening++;Key=NULL;break;
   case 4:Label10->Caption = "После сбора знаний студент должен подняться выше на следующий уровень";trening++;Key=NULL;break;
   case 5:Image8->Visible = false;
   trening=0;
   Timer5->Enabled=0;
   Image5->Visible = true;
   logic=0;
   Image7->Visible = false;
   Image11->Visible = true;
   Image12->Visible = true;
   Image13->Visible = true;
   Image16->Visible = 0;
   Image14->Visible = true;
   Image15->Visible = 1;
   break;
  }
  Image1->Canvas->Draw(gx/2,gy/2,knopk);
 }
 key_ = true;
 ::Key=Key;
 if((Key == '1' || Key == '2' || Key == '3' || Key == '4' || Key == VK_RETURN) && rand_q!=-1 && prezent == true)
 {
  int asdfgjk = ((int)Key)-48;
  if(asdfgjk==Question[rand_q].option && lives>0)
  {
   true_question++;
  }
  else// if()
  {
   if(asdfgjk!=-35 && lives>0)
   {
	X=4;
	Y=22; // коордионаты в массиве
	X1=0;
	Y1=0;
	lives--;          //
  for(int n=0;n<vhard;n++)
  {
   if(Y==vy[n] && X==vx[n])
   {
		vxy2f_0(n);
	 lv1[vy[n]][vx[n]]=0;
	}
   }

   }
  }
   if(lives<1)
   {
	Image8->Visible = true;
	Label10->Caption = "Правельных ответов "+(AnsiString)true_question+"\nПроцент правильности ответов "+FloatToStrF(((float)(true_question/(float)(5+true_question)*100)), ffFixed, 10, 2)+"\nРекомендуемая оценка "+(AnsiString)(1+lvl);
	Timer1->Enabled = false;
	Timer2->Enabled = false;
	Timer3->Enabled = false;                                                                                                //      8/13*100
	Timer4->Enabled = false;
	if(Key == VK_RETURN)
	{
		//Label1->Caption = (String)(int)(Timer5->Enabled);
		Image5->Visible = false;Image8->Visible = false;Image9->Visible = false;Image11->Visible = false;Image10->Visible = false;Image12->Visible = false;Image13->Visible = false;Image14->Visible = false;Image15->Visible = 0; Image7->Visible = true;Image6->Visible = true;Image16->Visible = 1;
		Timer1->Enabled=true;Timer2->Enabled=true;Timer3->Enabled=true;Timer4->Enabled=true;
		logic=1;local_seting = 0;
		anim=0;score=0;lives=5;current_quest=0;timem=0;times=0;np=0;lvl=1;exp_=0;herolvl=1;
		scrl();lvlload();outputlvl();rand_q=-1;




   Image5->Visible = true;
   Timer1->Enabled = false;
   Timer2->Enabled = false;
   Timer3->Enabled = false;
   Timer4->Enabled = false;
   logic=0;
	  Image7->Visible = false;
   Image6->Visible = false;
   //Image9->Visible = true;
   //Image10->Visible = true;
   Image11->Visible = true;
   Image12->Visible = true;
   Image13->Visible = true;
   Image16->Visible = 0;
   Image14->Visible = true;
   Image15->Visible = 1;
   Key=NULL;

				   return;


	}
   }
			  /*

  */
  if(lives>0 && Key != VK_RETURN)
  {
	Image8->Visible = false;
	Timer1->Enabled = true;
	Timer2->Enabled = true;
	Timer3->Enabled = true;
	Timer4->Enabled = true;   // */
	rand_q=-1;
	Label10->Caption = "";
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
 key_ = false;
 //local_logic_key = 1;      ClientSocket1->Socket->SendText("0");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //if(local_logic_key == 0)
 if(rand_q!=-1)
 {
  Key = NULL;
 }
 if(key_==true)    //НАЧАЛО ОБРАБОТКИ НАЖАТИЯ КНОПОК!!!!!!!!!!!!!!!!!!!!!!
 {    if(Image8->Visible!=1)              //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 if(Key == 'Q')
 {
  kick++;
 // Key = NULL;
  if(kick == 10)
  {
   death();
   kick = 0;
  }          //
 }
 else
 {
  kick = 0;
 }
 if(Key == 'L')
 {
  score++;
 }
 for(int n=0;n<vhard && prezent==0;n++)
 {
  if(((X1<0 && vx[n]>0) || (X1>0 && vx[n]<0)) && (X+vx[n]==1 || X+vx[n]==-1))
  {
  Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
  X=4;
  Y=22; //коордионаты в массиве
  X1=0;
  Y1=0;
  lives--;
  for(n=0;n<vhard;n++)
  {
   Image3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
   lv1[vy[n]][vx[n]]=0;
   vx[n]=random(65)+1;
   vy[n]=1;
   vx1[n]=0;
   vy1[n]=0;
   vnp[n]=1;
  }
  for(int n=0;n<33;n++)
   for(int m=0;m<66;m++)
	lv1[n][m]=0;
  }                       //  //
 }
  if(Key != VK_ESCAPE && logic==0)
  Key=NULL;
 //if(ClientSocket1->Active != 1)
 if(Image8->Visible!=1)
 if((Key == VK_RIGHT || Key == 'D' || (Key == VK_RIGHT && Key == VK_UP)) && (lv[Y][X+1]!='1' || X1<0)
 && ((lv[Y+1][X]!='0' && lv[Y+1][X]!= 50 && Y1 == 0) || lv[Y][X]=='4' ||
 (lv[Y][X]=='3' && Y1>0 && (lv[Y+1][X+1]!='1' || X1<0)) || (lv[Y][X]=='3' && Y1<0 && (lv[Y-1][X+1]!='1' || X1<0)) || lv1[Y+1][X]==20 )) //КНОПКА ВПРАВО!!!!!!!!!!!!!!
 {
  np=1;							   ///////////
   if(lv[Y][X]==50)                //очки score
   {
   Image1->Canvas->StretchDraw(Rect(X*(gx/mx)+v,Y*(gy/my),(X*(gx/mx))+(gx/mx)+v,(Y*(gy/my))+(gy/my)),FON_BIT);
	score++;                                       ////////////
	//Label1->Caption = score;     ////                     //////////
	lv[Y][X]=0;                             //////////////////
   }                                                 ////////////////////												/////////////////
   X1++;      //0-3 позиций иконки(5*3=15)                ///////////
   if(X1==3) {X1=0;X++;}  //0-3 позиций иконки(5*3=15)      ///////////
   animR();//вызов ф-ции анимация                       //////////
	 Image2->Top = ((Y*(gy/my))+(Y1*((gy/my)/3)));    /////////////////
  Image2->Left = ((X*(gx/mx)+v)+(X1*((gx/mx)/3)));      //////////
 } ///*
 //if(ClientSocket1->Active != 1)
 if(Image8->Visible!=1)
 if((Key == VK_LEFT || Key == 'A') && (lv[Y][X-1]!=49 || X1>0)
 && ((lv[Y+1][X]!='0' && lv[Y+1][X]!= 50 && Y1 == 0) || lv[Y][X]=='4' ||
 (lv[Y][X]=='3' && Y1>0 && (lv[Y+1][X-1]!='1' || X1>0)) || (lv[Y][X]=='3' && Y1<0 && (lv[Y-1][X-1]!='1' || X1>0)) || lv1[Y+1][X]==20))   //КНОПКА ВЛЕВО!!!!!!!!!!!!!!
 {
  np=-1;									  ////////
   if(lv[Y][X]==50)           //очки score
   {
	Image1->Canvas->StretchDraw(Rect(X*(gx/mx)+v,Y*(gy/my),(X*(gx/mx))+(gx/mx)+v,(Y*(gy/my))+(gy/my)),FON_BIT);
	score++;
	//Label1->Caption = score;
	lv[Y][X]=0;
   }
   X1--;       //0-3 позиций иконки(5*3=15)
   if(X1==-3) {X1=0;X--;}    //0-3 позиций иконки(5*3=15)в пикселях
   animL();//вызов ф-ции анимация
   Image2->Top = ((Y*(gy/my))+(Y1*((gy/my)/3)));
   Image2->Left = ((X*(gx/mx)+v)+(X1*((gx/mx)/3)));
 }  // */
 //if(ClientSocket1->Active != 1)
 if(Image8->Visible!=1)
 if((Key == VK_UP || Key == 'W') && X1==0 && lv[Y][X]==51)//dВИЖЕНИЕ ПО ЛЕСТНИЦЕ
 {
  Y1--;       //0-3 позиций иконки(5*3=15)
  if(Y1==-3) {Y1=0;Y--;}    //0-3 позиций иконки(5*3=15)в пикселях
  animL();//вызов ф-ции анимация
	Image2->Top = ((Y*(gy/my))+(Y1*((gy/my)/3)));
  Image2->Left = ((X*(gx/mx)+v)+(X1*((gx/mx)/3)));
 }
 if(Image8->Visible!=1)
 if((Key == VK_DOWN || Key == 'S') && lv[Y+1][X]!=49 &&
 ((lv[Y][X]=='4' && ((X1<0 && lv[Y+1][X-1]!='1') || (X1>0 && lv[Y+1][X+1]!='1')) || X1==0) ||
 (X1==0 && (lv[Y][X]==51 || lv[Y+1][X]==51))))//dВИЖЕНИЕ ПО ЛЕСТНИЦЕ
 {
  Y1++;       //0-3 позиций иконки(5*3=15)
  if(Y1==3) {Y1=0;Y++;}    //0-3 позиций иконки(5*3=15)в пикселях
  animR();//вызов ф-ции анимация
  Image2->Top = ((Y*(gy/my))+(Y1*((gy/my)/3)));
  Image2->Left = ((X*(gx/mx)+v)+(X1*((gx/mx)/3)));
 }
 //if(ClientSocket1->Active != 1)
 if(Image8->Visible!=1)
 if((Key == 'E') && lv[Y+1][X+np]==49 && Nl<9 && b<30)
 {
  ax[Nl]=X+np;      //анимация раскопки
  ay[Nl]=Y+1;
  llx = X+np;
  lly = Y+1;
  Nl++;
  lv[Y+1][X+np]=0;
  ////////////////////
  bx[b]=X+np;       //анимация закопки
  by[b]=Y+1;
  btime[b]=10;      // ВРЕМЯ ЗАРАСТАНИЕ ДЫР!! ЕДЕНИЦА = 0,45 СЕК
  ba[b]=1;
  b++;
  local_lopata = 1;
 }
///*
 //if(ClientSocket1->Active != 1)
 if(Image8->Visible!=1)
 if(Key == 'F' && lv[Y][X] == '0')
 {
  Bomb[max_bomb].active = 1;
  Bomb[max_bomb].index_bomb = 1;
  Bomb[max_bomb].bomb_x = X;
  Bomb[max_bomb].bomb_y = Y;
  max_bomb++;
 }
  //  */

  Label2->Caption = score;
  Label6->Caption = lives;
 if(Image8->Visible!=1)
 if(Key==VK_ESCAPE)
  if(logic==1)       //нажать
  {
   Image5->Visible = true;
   Timer1->Enabled = false;
   Timer2->Enabled = false;
   Timer3->Enabled = false;
   Timer4->Enabled = false;
   logic=0;
	  Image7->Visible = false;
   Image6->Visible = false;
   Image9->Visible = true;
   Image10->Visible = true;
   Image11->Visible = true;
   Image12->Visible = true;
   Image13->Visible = true;
   Image16->Visible = 0;
   Image14->Visible = true;
   Image15->Visible = 1;
   Key=NULL;
  } if(Image8->Visible!=1)
  if(Key==VK_ESCAPE)
  if(logic==0)               //отжать
  {
   Image5->Visible = false;
   Timer1->Enabled = true;
   Timer2->Enabled = true;
   Timer3->Enabled = true;
   Timer4->Enabled = true;
   logic=1;
   Image9->Visible = false;
   Image10->Visible = false;
   Image11->Visible = false;
   Image12->Visible = false;
   Image13->Visible = false;
   Image14->Visible = false;
   Image16->Visible = 0;
   Image15->Visible = 0;
   Image7->Visible = true;
   Image6->Visible = true;
   Key=NULL;
  }
 }    //!!!!!!!!!!!!!!!!
	//КОНЕЦ ОБРАБОТКИ НАЖАТИЯ КНОПОК!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	   //!!!!!!!!!!!!!!!!!


  ///////////////////////////////////
  ////////////////////////////////////   локальная сеть
  ////////////////////////////////////
  /*
   if(local_seting == 1)
   if((local_key == '2') && (lv[Yl][Xl+1]!='1' || Xl1<0)
 && ((lv[Yl+1][Xl]!='0' && lv[Yl+1][Xl]!= 50 && Yl1 == 0) || lv[Yl][Xl]=='4' ||
 (lv[Yl][Xl]=='3' && Yl1>0 && (lv[Yl+1][Xl+1]!='1' || Xl1<0)) || (lv[Yl][Xl]=='3' && Yl1<0 && (lv[Yl-1][Xl+1]!='1' || Xl1<0)) || lv1[Yl+1][Xl]==20 )) //КНОПКА ВПРАВО!!!!!!!!!!!!!!
 if(vxy2[(Yl*3)+Yl1+1][(Xl*3)+Xl1+2]!=true && vxy2[(Yl*3)+Yl1-1][(Xl*3)+Xl1+2]!=true)
 {
  local_np = 1;
  lv1[Yl][Xl] = 0;									//////////////
//  LOCAL_BIN_OFF();								///////////////////////////////												/////////////////
  Xl1++;      //0-3 позиций иконки(5*3=15)                ///////////
  lv1[Yl][Xl] = 20;
  if(Xl1==3) {lv1[Yl][Xl+1] = 20;lv1[Yl][Xl] = 0;Xl1=0;Xl++;}  //0-3 позиций иконки(5*3=15)      ///////////
 // LOCAL_BIN_ON();
  animR1();//вызов ф-ции анимация                       //////////
  Image4->Top = ((Yl*(gy/my))+(Yl1*((gy/my)/3)));    /////////////////
  Image4->Left = ((Xl*(gx/mx)+v)+(Xl1*((gx/mx)/3)));      //////////
 }              //
 if(local_seting == 1)
 if((local_key == '1') && (lv[Yl][Xl-1]!=49 || Xl1>0)
 && ((lv[Yl+1][Xl]!='0' && lv[Yl+1][Xl]!= 50 && Yl1 == 0) || lv[Yl][Xl]=='4' ||
 (lv[Yl][Xl]=='3' && Yl1>0 && (lv[Yl+1][Xl-1]!='1' || Xl1>0)) || (lv[Yl][Xl]=='3' && Yl1<0 && (lv[Yl-1][Xl-1]!='1' || Xl1>0)) || lv1[Yl+1][Xl]==20))   //КНОПКА ВЛЕВО!!!!!!!!!!!!!!
 if(vxy2[(Yl*3)+Yl1+1][(Xl*3)+Xl1-2]!=true && vxy2[(Yl*3)+Yl1-1][(Xl*3)+Xl1-2]!=true)
 { ////////
  local_np = -1;
  lv1[Yl][Xl] = 0;
 // LOCAL_BIN_OFF();
  Xl1--;       //0-3 позиций иконки(5*3=15)
  lv1[Yl][Xl] = 20;
  if(Xl1==-3) {lv1[Yl][Xl-1] = 20;lv1[Yl][Xl] = 0;Xl1=0;Xl--;}    //0-3 позиций иконки(5*3=15)в пикселях
//  LOCAL_BIN_ON(); //
  animL1();//вызов ф-ции анимация
  Image4->Top = ((Yl*(gy/my))+(Yl1*((gy/my)/3)));
  Image4->Left = ((Xl*(gx/mx)+v)+(Xl1*((gx/mx)/3)));
 }
 if(local_seting == 1)
 if((local_key == '3') && Xl1==0 && lv[Yl][Xl]==51)//dВИЖЕНИЕ ПО ЛЕСТНИЦЕ
 {
  lv1[Yl][Xl] = 0;
 // LOCAL_BIN_OFF();
  Yl1--;       //0-3 позиций иконки(5*3=15)
  lv1[Yl][Xl] = 20;
  if(Yl1==-3) {lv1[Yl-1][Xl] = 20;lv1[Yl][Xl] = 0;Yl1=0;Yl--;}    //0-3 позиций иконки(5*3=15)в пикселях
 // LOCAL_BIN_ON();       //
  animL1();//вызов ф-ции анимация
  Image4->Top = ((Yl*(gy/my))+(Yl1*((gy/my)/3)));
  Image4->Left = ((Xl*(gx/mx)+v)+(Xl1*((gx/mx)/3)));
 }
 if(local_seting == 1)
 if((local_key == '4') && lv[Yl+1][Xl]!=49 &&
 ((lv[Yl][Xl]=='4' && ((Xl1<0 && lv[Yl+1][Xl-1]!='1') || (Xl1>0 && lv[Yl+1][Xl+1]!='1')) || Xl1==0) ||
 (Xl1==0 && (lv[Yl][Xl]==51 || lv[Yl+1][Xl]==51))))//dВИЖЕНИЕ ПО ЛЕСТНИЦЕ
 {
  lv1[Yl][Xl] = 0;
//  LOCAL_BIN_OFF();
  Yl1++;       //0-3 позиций иконки(5*3=15)
  lv1[Yl][Xl] = 20;
  if(Yl1==3) {lv1[Yl+1][Xl] = 20;lv1[Yl][Xl] = 0;Yl1=0;Yl++;}    //0-3 позиций иконки(5*3=15)в пикселях
//  LOCAL_BIN_ON();
  animR1();//вызов ф-ции анимация  //
  Image4->Top = ((Yl*(gy/my))+(Yl1*((gy/my)/3)));
  Image4->Left = ((Xl*(gx/mx)+v)+(Xl1*((gx/mx)/3)));
 }
 if(local_seting == 1)
 if((local_key == '5') && lv[Yl+1][Xl+local_np]==49 && Nl<9 && b<30)
 {
  ax[Nl]=Xl+local_np;      //анимация раскопки
  ay[Nl]=Yl+1;
  Nl++;
  lv[Yl+1][Xl+local_np]=0;
  ////////////////////
  bx[b]=Xl+local_np;       //анимация закопки
  by[b]=Yl+1;
  btime[b]=10;      // ВРЕМЯ ЗАРАСТАНИЕ ДЫР!! ЕДЕНИЦА = 0,5 СЕК
  ba[b]=1;
  b++;
  local_lp = 1;
 }


 ///*
 if(conecting == 1)
 {
  local_give_str();
 }	  /**/
		   //	*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 knopk->LoadFromResourceName((unsigned int)new_style,"upd_down");
 Image14->Canvas->Draw(0,0,knopk);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 logic = 1;
 knopk->LoadFromResourceName((unsigned int)new_style,"upd_up");
 Image14->Canvas->Draw(0,0,knopk);
 Label10->Caption = "Управление студентом: стрелки на клавиатуре и буквы wasd отвечают за движение";
 Image5->Visible = false;
 Image9->Visible = false;
 Image11->Visible = false;
 Image10->Visible = false;
 Image12->Visible = false;
 Image3->Visible = false;
 Image2->Visible = false;
 Image13->Visible = false;
 Image14->Visible = false;
 Image16->Visible = 0;
 Image15->Visible = 0;
 Timer1->Enabled=false;
 Timer2->Enabled=false;
 Timer3->Enabled=false;
 Timer4->Enabled=false;
 Timer5->Enabled=true;
 Timer6->Enabled=false;
 //logic=1;
 Image7->Visible = true;
 Image6->Visible = true;
 FON_BIT->LoadFromResourceName((unsigned int)dll,"a6");
 trening = 1;
 for(int n=0;n<33;n++)  // 33 и 66 зависит от размеров имаге 1 и 3
  for(int m=0;m<66;m++)
   Image1->Canvas->StretchDraw(Rect(m*(gx/66)+v,n*(gy/33),(m*(gx/66))+(gx/66)+v,(n*(gy/33))+(gy/33)),FON_BIT);
 knopk->LoadFromResourceName((unsigned int)png_storage,"scr1");
 Image1->Canvas->Draw(gx/2,gy/2,knopk);
 Image8->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer6Timer(TObject *Sender)
{                     /*
 static int n=0,m=0;
 static int y=0,x=0;
 for(int p=0;p<10;p++)
 {
 y=0;x=0;

 if(y != 0 && x != 0 && y!= 32 && x!=65)
 Image1->Canvas->Draw(x*(gx/66)+v,y*(gy/33),gsom49);    //1 кирпич
  if(y == 0 && x == 0)
  {
 for(int i=0;i<3 && max_captС < 66*33-1;i++)
 {
  do
  {
   m = random(66);      ////
   n = random(33);
  }
  while(capt[n][m] == true);
  capt[n][m] = true;
  max_captС++;

   switch(lv[n][m])
   {
	case 49:Image1->Canvas->Draw(m*(gx/66)+v,n*(gy/33),gsom49);break;     //1 кирпич
	case 50:Image1->Canvas->Draw(m*(gx/66)+v,n*(gy/33),gsom50);break;       //2  алмаз
	case 51:Image1->Canvas->Draw(m*(gx/66)+v,n*(gy/33),gsom51);break;    //3 лестница
	case 52:Image1->Canvas->Draw(m*(gx/66)+v,n*(gy/33),gsom52);break;   //4 лазейка
	case 48:Image1->Canvas->Draw(m*(gx/66)+v,n*(gy/33),gsom48);break; //фон
	default:Image1->Canvas->Draw(m*(gx/66)+v,n*(gy/33),gsom48);break; //5 лестница(конечная)
   }
	 ///*              //
	  if(max_captС>66*33-1000)
	  {
	Timer1->Enabled = true;
	Timer2->Enabled = true;      //
	Timer3->Enabled = true;
	Timer4->Enabled = true;
	Timer5->Enabled = true;
	  }
   if(max_captС>66*32+32)
   {                            //
	max_captС = 0;
	for(int i=0;i<33;i++)
	 for(int j=0;j<66;j++)
	 switch(lv[i][j])      //левел рисуется ТУТ!!!
	 {
	case 49:Image1->Canvas->Draw(j*(gx/66)+v,i*(gy/33),gsom49);break;     //1 кирпич
	case 50:Image1->Canvas->Draw(j*(gx/66)+v,i*(gy/33),gsom50);break;       //2  алмаз
	case 51:Image1->Canvas->Draw(j*(gx/66)+v,i*(gy/33),gsom51);break;    //3 лестница
	case 52:Image1->Canvas->Draw(j*(gx/66)+v,i*(gy/33),gsom52);break;   //4 лазейка
	case 48:Image1->Canvas->Draw(j*(gx/66)+v,i*(gy/33),gsom48);break; //фон
	default:Image1->Canvas->Draw(j*(gx/66)+v,i*(gy/33),gsom48);break; //5 лестница(конечная)
	 }

	Timer6->Enabled = false;
	break;
   }
   }
  }

   }         //*///

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image15MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 if(menu == 0)
 {
  knopk->LoadFromResourceName((unsigned int)new_style,"local_down");Image15->Canvas->Draw(0,0,knopk);
 }
 if(menu ==1)
 {
  knopk->LoadFromResourceName((unsigned int)png_storage,"connect_down");Image15->Canvas->Draw(0,0,knopk);
 }
 if(menu == 5 )
 {
  knopk->LoadFromResourceName((unsigned int)png_storage,"connect_down");Image15->Canvas->Draw(0,0,knopk);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image15MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 wchar_t *wc = Edit1->Text.t_str();
 char ip[20];
 wcstombs(ip, wc, wcslen(wc)+1);
 //char temp_text[100] = {"Hello! i am client!"};

 switch(menu)
 {
  case 1:
  knopk->LoadFromResourceName((unsigned int)png_storage,"connect_up");Image15->Canvas->Draw(0,0,knopk);
  Edit1->Visible = 1;
  menu = 5;
  Image11->Visible = 0;
  break;
  case 5:  //
  //подключение по локалочке   client
  knopk->LoadFromResourceName((unsigned int)png_storage,"connect_up");Image15->Canvas->Draw(0,0,knopk);
  try
  {
	WSADATA wData;
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));      ///apd
	WSAStartup(MAKEWORD(2,0),&wData);          //apd
	sock=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(3123);
	addr.sin_addr.s_addr=inet_addr(ip);   //apd
	bind(sock,(struct sockaddr *)&addr,sizeof(addr));
	connect(sock,(struct sockaddr *)&addr,sizeof(addr));  //apd
	_beginthread(ClientReadThread, 0, NULL);//   ////
   //	local_seting == 1;
	//серверу надо узнать что к нему подключился клиент  //////
	send(sock,"Hello! i am client!",strlen("Hello! i am client!"),MSG_DONTROUTE);//приветливый клиент
  }
  catch(...)
  {unsigned long a = GetLastError();
  ShowMessage(a);}
  //
  break;
  case 0:
  menu = 1;
  knopk->LoadFromResourceName((unsigned int)new_style,"local_up");Image15->Canvas->Draw(0,0,knopk);
  knopk->LoadFromResourceName((unsigned int)png_storage,"back_up");Image13->Canvas->Draw(0,0,knopk);
  knopk->LoadFromResourceName((unsigned int)png_storage,"create_up");Image11->Canvas->Draw(0,0,knopk);
  knopk->LoadFromResourceName((unsigned int)png_storage,"connect_up");Image15->Canvas->Draw(0,0,knopk);
  Image9->Visible = false; Image12->Visible = false;Image10->Visible = false;Image14->Visible = false;
  break;
  default: break;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer8Timer(TObject *Sender)     //суперпупер заставка
{
 static unsigned char zs_i = 0;
 static String str = "PngImage_1";
 static String str1 = "PngImage_10";
 static String str2 = "PngImage_101";
 if(zs_i<100 && zs_i>9)
 {
  saver_png->LoadFromResourceName((unsigned int)zzz,str1);
  saver_bmp->SetSize(gx,gy);
  saver_bmp->Canvas->StretchDraw(Rect(0,0,gx,gy),saver_png);
  Image16->Canvas->Draw(0,0,saver_bmp);
 }
 if(zs_i<10)
 {
  saver_png->LoadFromResourceName((unsigned int)zzz,str);
  saver_bmp->SetSize(720,480);
  saver_bmp->Canvas->Draw(0,0,saver_png);
  Image16->Canvas->Draw(0,0,saver_bmp);
  Image16->Canvas->StretchDraw(TRect(0,0,1024,768),saver_bmp);
 }
 if(zs_i>100)
 {
  saver_png->LoadFromResourceName((unsigned int)zzz,str2);
  saver_bmp->SetSize(gx,gy);
  saver_bmp->Canvas->StretchDraw(Rect(0,0,gx,gy),saver_png);
  Image16->Canvas->Draw(0,0,saver_bmp);
 }

  if(zs_i != 138) zs_i++;


  if(zs_i>100 && zs_i < 138)
  {
   str2[10] = int(zs_i/100)+48;
   str2[11] = int(zs_i/10)-(int(zs_i/100)*10)+48;
   str2[12] = int(int(zs_i%100)%10)+48;

   if(zs_i == 137)
   {
	Image16->Visible = 0;
 //	for(int i = 0 ;i< 1024;i+=15)
  //	 for(int j = 0 ;j<768;j+=22)
	 {
	  Image16->Canvas->StretchDraw(Rect(0,0,1024,768),f_);
	 }
	Image16->Transparent = 1;  delete saver_png; delete saver_bmp; Timer8->Enabled = 0;
   }
  }

  if(zs_i>9 && zs_i<100)
  {
   str1[10] = int(zs_i/10)+48;
   str1[11] = int(zs_i%10)+48;
  }
  else
  {
   if(zs_i<10)
	str[10] = int(zs_i)+48;
  }
}
//---------------------------------------------------------------------------











