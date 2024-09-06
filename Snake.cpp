#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
 
main()
{
   int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");

   int x1=70,x2=80,y1=90,y2=100,m=3,p=0,xc,yc,ix,iy,iq,i,i1,i2,i3,q1=5,dl=100,po=0,go=0,ci=0;
   srand (time(NULL));
   int x[90000],y[90000],x0[90000],y0[90000];
   char pontos[50],fg[50],instr[100],co[100],cri[100];
   
   sprintf(cri,"Criado por Jos%c Augusto",'é');
   sprintf(co,"Pressione qualquer tecla para come%car.",'ç');
   sprintf(instr,"Use as setas ou W/A/S/D para se locomover.");
   
   
	xc=40+(rand()%(getmaxx()-80));
	yc=40+(rand()%(getmaxy()-80));
	
	/*Começo*/
	setfillstyle(SOLID_FILL, 10);
	bar(0,0,getmaxx(),10);
	bar(0,10,10,getmaxy());
	bar(10,getmaxy()-10,getmaxx(),getmaxy());
	bar(getmaxx()-10,10,getmaxx(),getmaxy());
	setcolor(10);
	settextstyle(10,0,4);
	outtextxy((getmaxx()-textwidth("Snake Game"))/2,((getmaxy()-textheight("Snake Game"))/2)-80,"Snake Game");
	setcolor(GREEN);
	settextstyle(1,0,2);
	outtextxy((getmaxx()-textwidth(cri))/2,((getmaxy()-textheight(cri))/2),cri);
	settextstyle(1,0,1);
	outtextxy((getmaxx()-textwidth(co))/2,((getmaxy()-textheight(co))/2)+80,co);
	getch();
	
	
		
   while (1){
   	setactivepage(p);
   	setvisualpage(1-p);
   	cleardevice();
   	
   	if(go==0){
   	setcolor(BLACK);
   	setfillstyle(SOLID_FILL, BLACK);
   	bar(11,11,getmaxx()-11,getmaxy()-11);
   	
 
   	
	sprintf(pontos,"Pontos: %i",po);
	   
	 /*Comida*/  
	setcolor(GREEN);
   	setfillstyle(SOLID_FILL, GREEN);
	circle(xc,yc,3);
	floodfill(xc,yc,GREEN);
	for(ix=x1;ix<=x2;ix++){
		for(iy=y1;iy<=y2;iy++){
		if((ix==xc)&&(iy==yc)){
	xc=40+(rand()%(getmaxx()-80));
	yc=40+(rand()%(getmaxy()-80));
	
	q1++;
	do{
	if (ci!=0){
		xc=40+(rand()%(getmaxx()-80));
		yc=40+(rand()%(getmaxy()-80));
		ci=0;
	}
	for(i3=0;i3<=q1;i3++){
		for(ix=x0[i3];ix<=x[i3];ix++){
			for(iy=y0[i3];iy<=y[i3];iy++){
				if((ix==xc)&&(iy==yc)){
				ci++;
				}
			}
		}
	}
	
	}
	while(ci!=0);
	switch (m){
		case 0:
		y0[q1]=y0[0]+(10*q1);
		y[q1]=y[0]+(10*i);
	
		break;
		case 1:
		y0[q1]=y0[0]-(10*q1);
		y[q1]=y[0]-(10*q1);

		break;
		case 2:
		x0[q1]=x0[0]+(10*q1);
		x[q1]=x[0]+(10*q1);

		break;
		case 3:
		x0[q1]=x0[0]-(10*q1);
		x[q1]=x[0]-(10*q1);

		break;
	}
	if(dl>20){
	dl=dl-5;
	}
	po=po+20;
	}}}
	
		
	
	/*Borda*/
	setfillstyle(SOLID_FILL, RED);
	bar(0,0,getmaxx(),10);
	bar(0,10,10,getmaxy());
	bar(10,getmaxy()-10,getmaxx(),getmaxy());
	bar(getmaxx()-10,10,getmaxx(),getmaxy());
	
	
	/*Textos*/
	
	setbkcolor(RED);
	settextstyle(0,0,1);
	setcolor(BLACK);
   	outtextxy(15,getmaxy()-10,instr);
   	outtextxy(15,0,pontos);
		
	
	/*Cabeça*/
	setfillstyle(SOLID_FILL, BLUE);
	bar(x1,y1,x2,y2);
	if ((GetAsyncKeyState(VK_UP))||(GetAsyncKeyState(0x57))){
	if (m==1){go++;}
	m=0;}
	if ((GetAsyncKeyState(VK_DOWN))||(GetAsyncKeyState(0x53))){
	if (m==0){go++;}
	m=1;}
	if ((GetAsyncKeyState(VK_LEFT))||(GetAsyncKeyState(0x41))){
	if (m==3){go++;}
	m=2;}
	if ((GetAsyncKeyState(VK_RIGHT))||(GetAsyncKeyState(0x44))){
	if (m==2){go++;}
	m=3;}
	
	
	switch (m){
		case 0:
			y1=y1-10;
			y2=y2-10;
			break;
		case 1:
			y1=y1+10;
			y2=y2+10;
			break;
		case 2:
			x1=x1-10;
			x2=x2-10;
			break;
		case 3:
			x1=x1+10;
			x2=x2+10;
			break;
	}
	
		
	
		
		
	
		for(i2=5;i2<=q1;i2++){
		if(((x1==x0[i2])&&(x2==x[i2]))&&((y1==y0[i2])&&(y2==y[i2]))){
			go++;
		}
	}
	
	
	
	/*Corpo*/
	
	x0[0]=x1;
	y0[0]=y1;
	x[0]=x2;
	y[0]=y2;
   	
	

	for(i=q1;i>0;i--){
		x0[i]=x0[i-1];
		y0[i]=y0[i-1];
		x[i]=x[i-1];
		y[i]=y[i-1];}
	for(i1=2;i1<q1;i1++){
		setcolor(BLUE);
		rectangle(x0[i1],y0[i1],x[i1],y[i1]);}
		
	
	 
	
	if (y1<=10){
		go++;
	}
	if (x1<=10){
		go++;
	}
	if (y2>=getmaxy()-10){
		go++;
	}
	if (x2>=getmaxx()-10){
		go++;
	}
	
	p=1-p;
	delay(dl);
	}
	if(go!=0){
   		
	
		sprintf(fg,"Aperte x para sair.");
		setbkcolor(BLACK);
		setcolor(RED);
		settextstyle(0,0,5);
		outtextxy((getmaxx()-textwidth("Fim de Jogo!"))/2,(getmaxy()-textheight("Fim de Jogo!"))/2,"Fim de Jogo!");
		settextstyle(0,0,3);
		outtextxy((getmaxx()-textwidth(fg))/2,((getmaxy()-textheight(fg))/2)+80,fg);
		getch();
		if(GetAsyncKeyState(0x58)){
			exit(0);
		}
		
	
	}
	
	}

}
  

