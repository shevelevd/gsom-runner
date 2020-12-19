void outputlvl()
{
	int a;
 for(int n=0;n<33;n++)
 {
  for(int m=0;m<66;m++)
  {
   switch(lv[n][m])      //левел рисуется ТУТ!!!
   {
	case 49:gsom->LoadFromResourceName((unsigned int)new_style,"a3");break;     //1 кирпич
	case 50:if(random(2)==1) gsom->LoadFromResourceName((unsigned int)new_style,"a1");else gsom->LoadFromResourceName((unsigned int)new_style,"aa1");break;       //2  алмаз
	case 51:gsom->LoadFromResourceName((unsigned int)dll,"a5");break;    //3 лестница
	case 52:gsom->LoadFromResourceName((unsigned int)png_storage,"4g");break;   //4 лазейка
	case 0:gsom->LoadFromResourceName((unsigned int)dll,"a6");break; //фон
	case 48:gsom->LoadFromResourceName((unsigned int)dll,"a6");break; //фон
	default:gsom->LoadFromResourceName((unsigned int)dll,"a6");break; //5 лестница(конечная)
   }
   Im1->Canvas->StretchDraw(Rect(m*(gx/66)+v,n*(gy/33),(m*(gx/66))+(gx/66)+v,(n*(gy/33))+(gy/33)),gsom);
   Im3->Canvas->StretchDraw(Rect(m*(gx/66)+v,n*(gy/33),(m*(gx/66))+(gx/66)+v,(n*(gy/33))+(gy/33)),f_);
  }
 }
}
void Question__(TLabel *Label)
{
 if(prezent == true)
 {
  rand_q = current_quest++;//random(maxquest);
  if(maxquest==current_quest)
   current_quest = 0;
  sprintf(Str_Question, "%s\n\n1) %s\n2) %s\n3) %s\n4) %s",Question[rand_q].quest,Question[rand_q].v1,Question[rand_q].v2,Question[rand_q].v3,Question[rand_q].v4);
  Label->Caption = Str_Question;
 }
}



void lvlload()
{
 for(int n=0;n<33;n++)
  for(int m=0;m<66;m++)
  {
lv1[n][m]=0;
 b1[n][m]=0;
  }

 for(int n=0;n<99;n++)
  for(int m=0;m<198;m++)
   vxy2[n][m]=0;
  FILE *f1;

 switch(lvl)
 {
  case 1:f1 = fopen("lvl1.txt", "r");break;
  case 2:f1 = fopen("lvl2.txt", "r");break;
  case 3:f1 = fopen("lvl3.txt", "r");break;
  case 4:return;
  case 5:return;
 }
 //int zz;
 fscanf(f1, "%i", &vhard);
 char asddfgh;
 fscanf(f1, "%c", &asddfgh);
 char hh1;
  for(char n=0;n<33;n++)
  {
   for(char m=0;m<67;m++)
   {
	//fscanf(f1, "%c", &lv[n][m]);
	fscanf(f1, "%c", &hh1); //  fprintf(f1, "%c", (int(lv[n][m])*n)+m);
	lv[n][m] = hh1-m-n;
   }
   //fprintf(f1,"%c",p);
  }
  fclose(f1);
  f1=NULL;
  delete f1;
  char p=10;
	FILE *f2;
 switch(lvl)
 {
  case 1:f2 = fopen("lvl1.txt", "w");break;
  case 2:f2 = fopen("lvl2.txt", "w");break;
  case 3:f2 = fopen("lvl3.txt", "w");break;
  case 4:return;
  case 5:return;
 }

  fprintf(f2, "%i", vhard);
  char rnd = (char)random(60)+65;
  fprintf(f2, "%c", rnd);
  for(char n=0;n<33;n++)
  {
   for(char m=0;m<66;m++)
   {
	fprintf(f2, "%c", lv[n][m]+m+n);
   }
   fprintf(f2,"%c",p);
  }
  fclose(f2);
  f2=NULL;
  delete f2;


 for(int n=0;n<10;n++)     //обнуляем всякую ...
 {
  Na[n]=1;
  ax[n]=0;
  ay[n]=0;
 }
 for(int n=0;n<30;n++)
 {
  bx[n]=0;
  by[n]=0;
  btime[n]=0;
  ba[n]=1;
 }
 for(int n=0;n<vhard;n++)
 {
  vx[n]=random(66);
  vy[n]=1;
  vx1[n]=0;
  vy1[n]=0;
  va[n]=random(3);
  vnp[n]=1;
 }


 X=4;Y=22; // коордионаты в массиве
 X1=0;Y1=0;     //3*5=15 - переменные на анимацию (-3 - 3)    */
	   /*
 for(int n=0;n<33;n++)
 {
  for(int m=0;m<67;m++)
  {
   fscanf(f1, "%c", &lv[n][m]);
  }
 }
  fclose(f1);
 f1=NULL;
 delete f1;  //*/

}
void scrl()
{
 for(int n=0;n<33;n++)            //щитаем сколько алмазиков в массиве
  for(int m=0;m<66;m++)
   if(lv[n][m]==50)
	scrlvl++;
}
void frendlvl()
{

for(int n=0;n<33;n++)            //первый раз обрабатываем возможные пути
 {
  for(int m=1;m<66;m++)
  {
   if((lv[n+1][m]==49 && (lv[n][m]==48 || lv[n][m]==0 || lv[n][m]==53 || lv[n][m]==50))
   || lv[n+1][m]==51 || lv[n][m]==51 || ((lv[n][m]==48
   || lv[n][m]==0 || lv[n][m]==53 || lv[n][m]==50) && lv[n+1][m-1]==49) || ((lv[n][m]==48
   || lv[n][m]==0 || lv[n][m]==53 || lv[n][m]==50) && lv[n+1][m+1]==49))
   {
	b1[n][m]=1;
   }
  }
 }

  for(int n=0;n<33;n++)            //тот самый апгрейд... теперь ai очень силён
 {                           //и может пользоваться любыми лазейками
  for(int m=1;m<66;m++)          //добавляем в b1 значение "2" где можно спрыгнуть
  {
   if(((lv[n][m+1]==49 && lv[n-1][m]!=49 && (lv[n-1][m+1]==48 || lv[n-1][m+1]==51 || lv[n-1][m+1]==50 || lv[n-1][m+1]==53))
   || (lv[n][m-1]==49 && lv[n-1][m]!=49 && (lv[n-1][m-1]==48 || lv[n-1][m-1]==51 || lv[n-1][m-1]==50 || lv[n-1][m-1]==53)))
	&& (lv[n][m]==48 || lv[n][m]==0 || lv[n][m]==53 || lv[n][m]==50))
   {
	b1[n-1][m]=2;
	for(int ii=n;lv[ii+1][m]!=49 && lv[ii+1][m]!=51 && ii<33;ii++)
	 b1[ii][m]=2;
   }
  }
 }

}
int min(int a,int b)
{
 if(a>b)
 {
  if(b!=0) {return b;} else {return a;}
 }
 else
 {
  if(a!=0) {return a;} else {return b;}
 }
 return 0;
}
//++++++++++++++++++++++++++
void func1()
{
 /*
 FILE *Fl;
 Fl = fopen("1.txt","w+");
  for(int n=0;n<33;n++)
  {
   for(int m=0;m<66;m++)
   {
	fprintf(Fl,"%3i",c[n][m]);
   }
   fprintf(Fl,"\n");
  }
 fclose(Fl);
   //*/

 for(int n=0;n<33;n++)      //чистим массив
  for(int m=0;m<66;m++)
   c[n][m]=0;

 c[Y][X]=1;
 if(b1[Y][X+1]==1 && c[Y][X+1]==0)
 {
  c[Y][X+1]=2;
 }
 if(b1[Y][X-1]==1 && c[Y][X-1]==0)
 {
  c[Y][X-1]=2;
 }
 if(b1[Y+1][X]==1 && c[Y+1][X]==0)
 {
  c[Y+1][X]=2;
 }
 if(b1[Y-1][X]==1 && c[Y-1][X]==0)
 {
  c[Y-1][X]=2;
 }

}
//+++++++++++++++++++++++++++++++++++++++++++
void func()
{
 int  hardlevel=1; // сложность прориcовки уровня путей (насколько сложен наш уровень)
 for(int hard=0;hard<hardlevel;hard++)
 {
 for(int n=0;n<33;n++)
 {
  for(int m=0;m<66;m++)
  {
   if(c[n][m]>0)
   {
	 sx=c[n][m];
	 sx++;
	 if(b1[n][m+1]==1 && (lv[n+1][m]==51 || lv[n+1][m]==49) &&
	  (c[n][m+1]==0 || c[n][m]<c[n][m+1]))
	 {
	  c[n][m+1]=sx;
	 }
	 if(b1[n][m-1]==1 && (lv[n+1][m]==51 || lv[n+1][m]==49) && (c[n][m-1]==0 || c[n][m]<c[n][m-1]))
	 {
	  c[n][m-1]=sx;
	 }
	 if(b1[n+1][m]==1 && (c[n+1][m]==0 || c[n][m]<c[n+1][m]))
	 {
	  c[n+1][m]=sx;
	 }
	 if(b1[n-1][m]==1 && lv[n][m]==51 && (c[n-1][m]==0 || c[n][m]<c[n-1][m]))  //
	 {
	  c[n-1][m]=sx;
	 }

   }
  }
 }
 for(int n=32;n>0;n--)
 {
  for(int m=65;m>0;m--)
  {
   if(c[n][m]>0)
   {
	 sx=c[n][m];
	 sx++;
	 if(b1[n][m+1]==1 && (lv[n+1][m]==51 || lv[n+1][m]==49 || lv1[n+1][m]==20) && (c[n][m+1]==0 || c[n][m]<c[n][m+1]))
	 {
	  c[n][m+1]=sx;
	 }
	 if(b1[n][m-1]==1 && (lv[n+1][m]==51 || lv[n+1][m]==49 || lv1[n+1][m]==20) && (c[n][m-1]==0 || c[n][m]<c[n][m-1]))
	 {
	  c[n][m-1]=sx;
	 }
	 if(b1[n+1][m]==1 && (c[n+1][m]==0 || c[n][m]<c[n+1][m]))
	 {
	  c[n+1][m]=sx;
	 }
	 if(b1[n-1][m]==1 && lv[n][m]==51 && (c[n-1][m]==0 || c[n][m]<c[n-1][m]))//
	 {
	  c[n-1][m]=sx;
	 }
   }
  }
 }
 }

 ///////////  то что ниже - гениально!!11
 int qw;
 for(int n=0;n<33;n++)
 {
  for(int m=0;m<66;m++)
  {
///////////////   целый день думал
   if(b1[n][m]==2 && b1[n+1][m]==1)
   {
	for(int i=n;b1[i][m]==2 && c[i+1][m]!=0;i--)
	{
	 c[i][m]=c[i+1][m]+1;
	 qw=i;
	 if(/*n-i>2 &&*/ (b1[i][m+1]==1 || b1[i][m-1]==1))
	 {
	  qwe(qw,m);   // рекурсия
	 }                //поднимаясь выше и выше анализируем только те моменты где можно упасть
	}                 // вызывая каждый раз рекурсивную функцию
   }
 ///////////
  }
 }
   //*/
}
   //это тоже немного гениально
void qwe(qw,m)
{
 if(b1[qw][m+1]==1 && (c[qw][m+1]>c[qw][m] || c[qw][m+1]==0))     //смотрим обе стороны
	for(int i=m+1;b1[qw][i]==1 && (c[qw][i]==0 || c[qw][i]>c[qw][i-1]);i++)
	 c[qw][i]=c[qw][i-1]+1;
 if(b1[qw][m-1]==1 && (c[qw][m-1]>c[qw][m] || c[qw][m-1]==0))
	for(int i=m-1;b1[qw][i]==1 && (c[qw][i]==0 || c[qw][i]>c[qw][i+1]);i--)
	 c[qw][i]=c[qw][i+1]+1;
}
void animR()  // функция прорисовки персонажа вправо
{
 switch(anim) // свич на анимацию
 {
  case 0:Im2->Canvas->Draw(0,0,a1_);anim++;break; //нулевая анимация
  case 1:Im2->Canvas->Draw(0,0,a2_);anim++;break;
  case 2:Im2->Canvas->Draw(0,0,a3_);anim++;break;
  case 3:Im2->Canvas->Draw(0,0,a4_);anim=1;break;
  default:Im2->Canvas->Draw(0,0,a1_);anim++;break;
 }
}
//+++++++++++++++++++++++++++++++++++++++++++
void animL()       // функция прорисовки персонажа влево
{
 switch(anim) // свич на анимацию
 {
  case 0:Im2->Canvas->Draw(0,0,a1_);anim++;break; //нулевая анимация
  case 1:Im2->Canvas->Draw(0,0,a6_);anim++;break;
  case 2:Im2->Canvas->Draw(0,0,a7_);anim++;break;
  case 3:Im2->Canvas->Draw(0,0,a8_);anim=1;break;
 }
}
//++++++++++++++++++++++++++++++++++++++
void wa(int n)     //функция анимации челов
{

 switch(va[n]) // свич на анимацию
 {
  case 0:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b0_);va[n]++;break; //нулевая анимация
  case 1:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b2_);va[n]++;break;
  case 2:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b3_);va[n]++;break;
  case 3:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b4_);va[n]=1;break;
 }
}
//+++++++++++++++++++++++++++++
void waL(int n)     //функция анимации челов
{
 switch(va[n]) // свич на анимацию
 {
  case 0:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b5_);va[n]++;break;
  case 1:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b6_);va[n]++;break;
  case 2:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b7_);va[n]++;break;
  case 3:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),b8_);va[n]=1;break;
 }
}
//+++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++
void lopata(int n)    //начинаем копать
{
 switch(Na[n])
 {
  case 1:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP1_);break;
  case 2:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP2_);break;
  case 3:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP3_);break;
  case 4:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP4_);break;
  case 5:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP5_);break;
  case 6:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP6_);break;
  case 7:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP7_);break;
  case 8:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP8_);break;
  case 9:Im1->Canvas->Draw(ax[n]*(gx/mx)+v,ay[n]*(gy/my),LP9_);break;
  default:break;
 }
}
void antilopata(int n)     // зарастание
{
 switch(ba[n])
 {
  case 1:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L1P_);break;
  case 2:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L2P_);break;
  case 3:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L3P_);break;
  case 4:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L4P_);break;
  case 5:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L5P_);break;
  case 6:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L6P_);break;
  case 7:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L7P_);break;
  case 8:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L8P_);break;
  case 9:Im1->Canvas->Draw(bx[n]*(gx/mx)+v,by[n]*(gy/my),L9P_);break;
  default:break;
 }
}
void death()
{
  for(int n=0;n<vhard;n++)
  {
   if(Y==vy[n] && X==vx[n])
   {
	Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),f_);
	vxy2f_0(n);
	lv1[vy[n]][vx[n]]=0;
	vx[n]=random(65)+1;
	vy[n]=1;
	vx1[n]=0;
	vy1[n]=0;
	vnp[n]=1;

	if(prezent == false)
	{
	 lives--;
	 X=4;
	 Y=22; // коордионаты в массиве
	 X1=0;
	 Y1=0;
		if(lives==0)
		{
			Form1->Close();
		}
	 ///
	}

   }
  }
  if(lv[Y][X]=='1')
  {
   X=4;
   Y=22; // коордионаты в массиве
   X1=0;
   Y1=0;
   if(prezent == false)
   {
	lives--;
	if(lives==0)
	 Form1->Close();
   }
  }

}

//евгений игоревич
void init_img()
{
  /*

*/
 LP1->LoadFromResourceName((unsigned int)new_style,"z1");
 LP2->LoadFromResourceName((unsigned int)new_style,"z2");
 LP3->LoadFromResourceName((unsigned int)new_style,"z3");
 LP4->LoadFromResourceName((unsigned int)new_style,"z4");
 LP5->LoadFromResourceName((unsigned int)new_style,"z5");
 LP6->LoadFromResourceName((unsigned int)new_style,"z6");
 LP7->LoadFromResourceName((unsigned int)new_style,"z7");
 LP8->LoadFromResourceName((unsigned int)new_style,"z9");
 LP9->LoadFromResourceName((unsigned int)dll,"a6");

 L1P->LoadFromResourceName((unsigned int)new_style,"x8");
 L2P->LoadFromResourceName((unsigned int)new_style,"x7");
 L3P->LoadFromResourceName((unsigned int)new_style,"x6");
 L4P->LoadFromResourceName((unsigned int)new_style,"x5");
 L5P->LoadFromResourceName((unsigned int)new_style,"x4");
 L6P->LoadFromResourceName((unsigned int)new_style,"x3");
 L7P->LoadFromResourceName((unsigned int)new_style,"x2");
 L8P->LoadFromResourceName((unsigned int)new_style,"x1");
 L9P->LoadFromResourceName((unsigned int)new_style,"a3");

 LP1_->SetSize(gx/mx,gy/my);
 LP2_->SetSize(gx/mx,gy/my);
 LP3_->SetSize(gx/mx,gy/my);
 LP4_->SetSize(gx/mx,gy/my);
 LP5_->SetSize(gx/mx,gy/my);
 LP6_->SetSize(gx/mx,gy/my);
 LP7_->SetSize(gx/mx,gy/my);
 LP8_->SetSize(gx/mx,gy/my);
 LP9_->SetSize(gx/mx,gy/my);

 L1P_->SetSize(gx/mx,gy/my);
 L2P_->SetSize(gx/mx,gy/my);
 L3P_->SetSize(gx/mx,gy/my);
 L4P_->SetSize(gx/mx,gy/my);
 L5P_->SetSize(gx/mx,gy/my);
 L6P_->SetSize(gx/mx,gy/my);
 L7P_->SetSize(gx/mx,gy/my);
 L8P_->SetSize(gx/mx,gy/my);
 L9P_->SetSize(gx/mx,gy/my);

 LP1_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP1);   delete LP1;
 LP2_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP2);   delete LP2;
 LP3_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP3);   delete LP3;
 LP4_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP4);   delete LP4;
 LP5_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP5);   delete LP5;
 LP6_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP6);   delete LP6;
 LP7_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP7);   delete LP7;
 LP8_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP8);   delete LP8;
 LP9_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),LP9);   delete LP9;

 L1P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L1P);   delete L1P;
 L2P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L2P);   delete L2P;
 L3P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L3P);   delete L3P;
 L4P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L4P);   delete L4P;
 L5P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L5P);   delete L5P;
 L6P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L6P);   delete L6P;
 L7P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L7P);   delete L7P;
 L8P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L8P);   delete L8P;
 L9P_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),L9P);   delete L9P;


 a1->LoadFromResourceName((unsigned int)dll,"g1");
 a2->LoadFromResourceName((unsigned int)dll,"e1");
 a3->LoadFromResourceName((unsigned int)dll,"e2");
 a4->LoadFromResourceName((unsigned int)dll,"e3");

 a1_->SetSize(gx/mx,gy/my);
 a2_->SetSize(gx/mx,gy/my);
 a3_->SetSize(gx/mx,gy/my);
 a4_->SetSize(gx/mx,gy/my);

 a1_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a1);   delete a1;
 a2_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a2);   delete a2;
 a3_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a3);   delete a3;
 a4_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a4);   delete a4;

 a5->LoadFromResourceName((unsigned int)dll,"g1");
 a6->LoadFromResourceName((unsigned int)dll,"f1");
 a7->LoadFromResourceName((unsigned int)dll,"f2");
 a8->LoadFromResourceName((unsigned int)dll,"f3");

 a5_->SetSize(gx/mx,gy/my);
 a6_->SetSize(gx/mx,gy/my);
 a7_->SetSize(gx/mx,gy/my);
 a8_->SetSize(gx/mx,gy/my);

 a5_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a5);  delete a5;
 a6_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a6);  delete a6;
 a7_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a7);  delete a7;
 a8_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),a8);  delete a8;

 b0->LoadFromResourceName((unsigned int)png_storage,"a1");
 b2->LoadFromResourceName((unsigned int)png_storage,"a1");
 b3->LoadFromResourceName((unsigned int)png_storage,"a2");
 b4->LoadFromResourceName((unsigned int)png_storage,"a3");

 b0_->SetSize(gx/mx,gy/my);
 b2_->SetSize(gx/mx,gy/my);
 b3_->SetSize(gx/mx,gy/my);
 b4_->SetSize(gx/mx,gy/my);

 b0_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b0); delete b0;
 b2_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b2); delete b2;
 b3_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b3); delete b3;
 b4_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b4); delete b4;

 b5->LoadFromResourceName((unsigned int)png_storage,"b1");
 b6->LoadFromResourceName((unsigned int)png_storage,"b1");
 b7->LoadFromResourceName((unsigned int)png_storage,"b2");
 b8->LoadFromResourceName((unsigned int)png_storage,"b3");

 b5_->SetSize(gx/mx,gy/my);
 b6_->SetSize(gx/mx,gy/my);
 b7_->SetSize(gx/mx,gy/my);
 b8_->SetSize(gx/mx,gy/my);

 b5_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b5);  delete b5;
 b6_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b6);  delete b6;
 b7_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b7);  delete b7;
 b8_->Canvas->StretchDraw(Rect(0,0,gx/mx,gy/my),b8);  delete b8;
}
void vxy2f_1(int n)
{
 int x = vx[n]*3,y = vy[n]*3;
 x = x + vx1[n];
 y = y + vy1[n];
 vxy2[y-1][x-1]=true;
 vxy2[y-1][x]=true;
 vxy2[y-1][x+1]=true;
 vxy2[y][x+1]=true;
 vxy2[y+1][x+1]=true;
 vxy2[y+1][x]=true;
 vxy2[y+1][x-1]=true;
 vxy2[y][x-1]=true;
 vxy2[y][x]=true;
}
void vxy2f_0(int n)
{
 int x = vx[n]*3,y = vy[n]*3;
 x = x + vx1[n];
 y = y + vy1[n];
 vxy2[y-1][x-1]=false;
 vxy2[y-1][x]=false;
 vxy2[y-1][x+1]=false;
 vxy2[y][x+1]=false;
 vxy2[y+1][x+1]=false;
 vxy2[y+1][x]=false;
 vxy2[y+1][x-1]=false;
 vxy2[y][x-1]=false;
 vxy2[y][x-1]=false;
}      ///*
void animR1()
{      /*
 switch(va[n]) // свич на анимацию
 {
  case 0:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),al1_);va[n]++;break;
  case 1:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),al2_);va[n]++;break;
  case 2:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),al3_);va[n]++;break;
  case 3:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),al4_);va[n]=1;break;
 }   */
}
void animL1()
{  /*
 switch(va[n]) // свич на анимацию
 {
  case 0:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),ar1_);va[n]++;break;
  case 1:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),ar2_);va[n]++;break;
  case 2:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),ar3_);va[n]++;break;
  case 3:Im3->Canvas->Draw((vx[n]*(gx/mx)+v)+(vx1[n]*((gx/mx)/3)),vy[n]*(gy/my)+(vy1[n]*((gy/my)/3)),ar4_);va[n]=1;break;
 }     */
}     // */
void local_give_str()
{                     /*
 char str[35];
 for(int i = 0;i<35;i++)
 {
  str[i]='0';
 }
   //это стек (сервер)
	 stck.push(X);
	  stck.push(Y);
	  stck.push(X1+2);
	  stck.push(Y1+2);
	  stck.push(np+1);
	  stck.push(Xl);
	  stck.push(Yl);
	  stck.push(Xl1+2);
	  stck.push(Yl1+2);
	 stck.push(local_np+1);
	  stck.push(ax[0]);
	  stck.push(ay[0]);
 ////////////
  int tmp;
  for(int i = 0;i<35;i+=2)
  {
   tmp = stck.top(); stck.pop();
   if(tmp>10)
   {
	str[i] = (tmp/10)+48; str[i+1] = (tmp-((tmp/10)*10))+48;
   }
   else
   {
	str[i] = '0'; str[i+1] = tmp+48;
   }

  }
	   //	*/

}
void bombs()
{

}

void ServerReadThread(void* pParams)
{
	sock=accept(listener,NULL,NULL);
	while(true)
	{

		bytes_read=recv(sock,buff,strlen("Hello! i am client!"),0); //вернули кол-во принятых байт
		ShowMessage(buff);/*
		if(buff[0] == 'H' && buff[1] == 'e' && buff[2] == 'l')//первая встреча клиента и сервера
		{
				/*
				for(int y = 0;y<33;y++)
					for(int x = 0;x<66;x++)
					{
						buff[66*y+x] = lv[y][x];
					}
			   //	send(sock,buff,66*33,0);      //

		 memset(&buff,0,sizeof(buff));
		}                                //*/
	}
}
void ClientReadThread(void* pParams)
{
	while(true)
	{
	try{
		bytes_read=recv(sock,buff,strlen("Hello! i am client!"),0); //вернули кол-во принятых байт
		ShowMessage(buff);
	  }
	  catch(...)
	  {
		  unsigned long a = GetLastError();
  ShowMessage(a);
      }
	   /*	if(bytes_read>100)
		{
			load_local_lvl = 1;
			Tim1->Enabled = 1;
			Tim2->Enabled = 0;      //
			Tim3->Enabled = 0;
			Tim4->Enabled = 0;
			Tim5->Enabled = 1;
			Tim6->Enabled = 0;
			Tim7->Enabled = 0;
			for(int i = 0 ; i < 66*33;i++)     //
			{
				switch(buff[i])      //левел рисуется ТУТ!!!
				{
					case 49:Im5->Canvas->Draw(i%66*(gx/66)+v,i/66*(gy/33),gsom49);break;     //1 кирпич
					case 51:Im5->Canvas->Draw(i%66*(gx/66)+v,i/66*(gy/33),gsom51);break;    //3 лестница
					case 52:Im5->Canvas->Draw(i%66*(gx/66)+v,i/66*(gy/33),gsom52);break;   //4 лазейка
					case 48:Im5->Canvas->Draw(i%66*(gx/66)+v,i/66*(gy/33),gsom48);break; //фон
					default:Im5->Canvas->Draw(i%66*(gx/66)+v,i/66*(gy/33),gsom48);break; //5 лестница(конечная)
				}
				lv[i/66][i%66] = buff[i];
			}
			Im5->Visible = false;Im9->Visible = false;Im11->Visible = false;Im10->Visible = false;Im12->Visible = false;Im13->Visible = false;Im14->Visible = false;Im15->Visible = 0; Im7->Visible = true;Im6->Visible = true;Im16->Visible = 1;
			Ed1->Visible = 0;
			logic=1;buff[0]=0;buff[1]='\0';
		}//*/
	}
}
void quest_(int q_lvl) //вопросы для каждого уровня
{
	 //.. */
   //	  /*////////////шифрование
 char a[] = "gsom_.gsom";
 a[4]=q_lvl+48;
 FILE *f2;
 f2 = fopen(a, "r+");
 char *temp_char = new char[30000];
 for(int i=0;i<30000;i++)
  temp_char[i] = 0;
 for(int n=0;!feof(f2);n++)
  fscanf(f2, "%c",&temp_char[n]);
 fclose(f2);


 for(int i=0;i<strlen(temp_char);i++)
  temp_char[i] ^= 0x11;

 FILE *f3;
 f3 = fopen(a, "w");
 for(int i=0;i<strlen(temp_char);i++)
  fprintf(f3, "%c",temp_char[i]);
 fclose(f3);
 delete temp_char;
	  /////////////конец шифрование
				 // /
 int u;
 char chq;  ///*
 FILE *f1;
 f1 = fopen(a, "r");
 //////
 fscanf(f1, "%i",&maxquest); //самое первое что берём
 fscanf(f1, "%c",&chq);  //разграничитель

 for(int n=0;n<maxquest-1;n++)
 {
  fscanf(f1, "%i",&u);    //длина текста
  fscanf(f1, "%c",&chq);  //разграничитель
  if(chq != '?') ShowMessage("Ошибка в вопросах.\nВозможно, были внесены изменения в файл иным способом или файл базы данных вопросов пуст.\nТакже, возможно, что вы не прочитали предупреждение о пустых полях и что-то пропустили; не нервничайте, успокойтесь, соберитесь и попробуйте сделать всё заного.\n\n\nВнимание!!! Данные будут утеряны, чтобы вы не предприняли.");
  for(int i=0;i<u;i++)
   fscanf(f1, "%c",&Question[n].quest[i]);   //читаем вопросы

 }

 for(int n=0;n<maxquest-1;n++)
 {
  for(int m=0;m<4;m++)
  {
   fscanf(f1, "%i",&u);
   fscanf(f1, "%c",&chq);
   if(chq != '?') ShowMessage("Ошибка в ответах.\nВозможно, были внесены изменения в файл иным способом или файл базы данных вопросов пуст.\nТакже, возможно, что вы не прочитали предупреждение о пустых полях и что-то пропустили; не нервничайте, успокойтесь, соберитесь и попробуйте сделать всё заного.\n\n\nВнимание!!! Данные будут утеряны, чтобы вы не предприняли.");
   for(int i=0;i<u;i++)
   {
	switch(m)
	{
	 case 0:fscanf(f1, "%c",&Question[n].v1[i]);break;
	 case 1:fscanf(f1, "%c",&Question[n].v2[i]);break;
	 case 2:fscanf(f1, "%c",&Question[n].v3[i]);break;
	 case 3:fscanf(f1, "%c",&Question[n].v4[i]);break;
	}
   }
   //question[n].option[m] = temp;
 //  delete temp;
  }
 }
 for(int n=0;n<maxquest-1;n++)
 {
  fscanf(f1, "%i",&Question[n].option);
  //question[n].yes = chq;
  fscanf(f1, "%c",&chq);
 }

  fclose(f1);     //     */
 maxquest--;


		 // /*////////////шифрование
 FILE *f4;
 f4 = fopen(a, "r+");
 char *temp_char1 = new char[30000];
 for(int i=0;i<30000;i++)
  temp_char1[i] = 0;
 for(int n=0;!feof(f4);n++)
  fscanf(f4, "%c",&temp_char1[n]);
 fclose(f4);

 for(int i=0;i<strlen(temp_char1);i++)
  temp_char1[i] ^= 0x11;

 FILE *f5;
 f5 = fopen(a, "w");
 for(int i=0;i<strlen(temp_char1);i++)
  fprintf(f5, "%c",temp_char1[i]);
 fclose(f5);
  delete temp_char1;
	  ////*/////////конец шифрование

 for(int n=0;n<maxquest;n++)
 {
   if(strlen(Question[n].quest)>70)
   {
	for(int i=70;i<strlen(Question[n].quest);i++)
	{
	 if(Question[n].quest[i]==' ')
	 {
	  Question[n].quest[i]='\n';break;
	 }
	}          //
   }
   if(strlen(Question[n].v1)>70)
   {
	for(int i=70;i<strlen(Question[n].v1);i++)
	{
	 if(Question[n].v1[i]==' ')
	 {
	  Question[n].v1[i]='\n';break;
	 }
	}
   }
   if(strlen(Question[n].v2)>70)
   {
	for(int i=70;i<strlen(Question[n].v2);i++)
	{
	 if(Question[n].v2[i]==' ')
	 {
	  Question[n].v2[i]='\n';break;
	 }
	}
   }
   if(strlen(Question[n].v3)>70)
   {
	for(int i=70;i<strlen(Question[n].v3);i++)
	{
	 if(Question[n].v3[i]==' ')
	 {
	  Question[n].v3[i]='\n';break;
	 }
	}
   }
   if(strlen(Question[n].v4)>70)
   {
	for(int i=70;i<strlen(Question[n].v4);i++)
	{
	 if(Question[n].v4[i]==' ')
	 {
	  Question[n].v4[i]='\n';break;
	 }
	}
   }      //
  }
}





