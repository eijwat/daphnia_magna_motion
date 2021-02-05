//Powered by Matsunaga & Watanabe, NIBB, Japan

#include <psychlops.h>
#include <fstream>
#include <iomanip>

using namespace Psychlops;	// Initially developed with Psychlops Win32 1.0 / 20080214
using namespace std;

Psychlops::Rectangle rect1,rect2,rect3,rect4,rect5,rect6;
Psychlops::Color col1,col2,col3,col4

double s1,s2; //size of dot
double xpos,ypos;//center of display
double xpos1,xpos2,xpos3,xpos4,xpos5,xpos6; //x position of dots
double ypos1,ypos2,ypos3,ypos4,ypos5,ypos6; //y position of dots
double xpos_limit_left,xpos_limit_right,ypos_limit_top,ypos_limit_bottom; //size limitation of active area
int time_counter;// time counter
int speed;//speed control parameter
int flip_number;//flip frames
int loop_number;//loop number
int seed_i;//seed data counter
double a1[5000],a2[5000],a3[5000],a4[5000],a5[5000],a6[5000];//x data (max_5000_data)
double b1[5000],b2[5000],b3[5000],b4[5000],b5[5000],b6[5000];//y data (max_5000_data)

void psychlops_main() {

	//initial values
	Canvas okazaemon(Canvas::fullscreen);

	xpos= okazaemon.getHcenter();//center of display
	ypos= okazaemon.getVcenter();//center of display

    col1.set(0.0,0.0,0.0);//colors
	col2.set(1.0,1.0,1.0);//colors
	col3.set(1.0,1.0,1.0);//colors
	col4.set(1.0,1.0,1.0);//colors

	time_counter=350; //time counter
	speed=4; //speed control parameter

	s1=6;//size of dot
	s2=6;//size of dot

	//size limitation of active area
	xpos_limit_left=xpos-250;
	xpos_limit_right=xpos+250;
	ypos_limit_top=ypos+70;
	ypos_limit_bottom=ypos+300;
	
	loop_number=10;

	rect1.set(s1,s2);
	rect1.shift(xpos1,ypos1);
	okazaemon.oval(rect1,Color::black);
	okazaemon.flip();


	while(1){
		if(Input::get(Keyboard::a)){col2.set(1.0,1.0,1.0);col3.set(1.0,1.0,1.0);col4.set(1.0,1.0,1.0);break;}
		if(Input::get(Keyboard::q)){col3.set(0.0,0.0,0.0);break;}
        if(Input::get(Keyboard::spc)){col4.set(0.0,0.0,0.0);col3.set(0.0,0.0,0.0);break;}
	};

	//start key
	while(!Input::get(Keyboard::spc));

	//seed position data from txt
    ifstream fin;
	fin.open("seed.txt");
	
	for (int i=1; i<=4096; i++)
		{
			fin>>a1[i]>>b1[i]>>a2[i]>>b2[i]>>a3[i]>>b3[i]>>a4[i]>>b4[i]>>a5[i]>>b5[i]>>a6[i]>>b6[i];
		}
		
    fin.close();
    Input::refresh();


    //start loop!
    for (int j=1; j<=loop_number; j++){
		xpos1=xpos+25;
		ypos1=ypos+200;
		xpos2=xpos-25;
		ypos2=ypos+200;
		xpos3=xpos+105;
		ypos3=ypos+200;
		xpos4=xpos-105;
		ypos4=ypos+200;
		xpos5=xpos+185;
		ypos5=ypos+200;
		xpos6=xpos-185;
		ypos6=ypos+200;
		
		for (int i=1; i<=time_counter; i++){
			
			seed_i=i + (j-1)*time_counter
			
			xpos1=xpos1+(a1[seed_i]/speed);
			if (xpos1<xpos_limit_left){
			xpos1=xpos_limit_right;}
			if (xpos1>xpos_limit_right){
			xpos1=xpos_limit_left;}
			ypos1=ypos1+(b1[seed_i]/speed);
			if (ypos1>ypos_limit_bottom){
			ypos1=ypos_limit_top;}
			if (ypos1<ypos_limit_top){
			ypos1=ypos_limit_bottom;}
			rect1.set(s1,s1);
			rect1.shift(xpos1,ypos1);
			
			xpos2=xpos2+(a2[seed_i]/speed);
			if (xpos2<xpos_limit_left){
			xpos2=xpos_limit_right;}
			if (xpos2>xpos_limit_right){
			xpos2=xpos_limit_left;}
			ypos2=ypos2+(b2[seed_i]/speed);
			if (ypos2>ypos_limit_bottom){
			ypos2=ypos_limit_top;}
			if (ypos2<ypos_limit_top){
			ypos2=ypos_limit_bottom;}
			rect2.set(s1,s2);
			rect2.shift(xpos2,ypos2);
			
			xpos3=xpos3+(a3[seed_i]/speed);
			if (xpos3<xpos_limit_left){
			xpos3=xpos_limit_right;}
			if (xpos3>xpos_limit_right){
			xpos3=xpos_limit_left;}
			ypos3=ypos3+(b3[seed_i]/speed);
			if (ypos3>ypos_limit_bottom){
			ypos3=ypos_limit_top;}
			if (ypos3<ypos_limit_top){
			ypos3=ypos_limit_bottom;}
			rect3.set(s1,s1);
			rect3.shift(xpos3,ypos3);
			
			xpos4=xpos4+(a4[seed_i]/speed);
			if (xpos4<xpos_limit_left){
			xpos4=xpos_limit_right;}
			if (xpos4>xpos_limit_right){
			xpos4=xpos_limit_left;}
			ypos4=ypos4+(b4[seed_i]/speed);
			if (ypos4>ypos_limit_bottom){
			ypos4=ypos_limit_top;}
			if (ypos4<ypos_limit_top){
			ypos4=ypos_limit_bottom;}
			rect4.set(s1,s1);
			rect4.shift(xpos4,ypos4);
			
			xpos5=xpos5+(a5[seed_i]/speed);
			if (xpos5<xpos_limit_left){
			xpos5=xpos_limit_right;}
			if (xpos5>xpos_limit_right){
			xpos5=xpos_limit_left;}
			ypos5=ypos5+(b5[seed_i]/speed);
			if (ypos5>ypos_limit_bottom){
			ypos5=ypos_limit_top;}
			if (ypos5<ypos_limit_top){
			ypos5=ypos_limit_bottom;}
			rect5.set(s1,s1);
			rect5.shift(xpos5,ypos5);
			
			xpos6=xpos6+(a6[seed_i]/speed);
			if (xpos6<xpos_limit_left){
			xpos6=xpos_limit_right;}
			if (xpos6>xpos_limit_right){
			xpos6=xpos_limit_left;}
			ypos6=ypos6+(b6[seed_i]/speed);
			if (ypos6>ypos_limit_bottom){
			ypos6=ypos_limit_top;}
			if (ypos6<ypos_limit_top){
			ypos6=ypos_limit_bottom;}
			rect6.set(s1,s1);
			rect6.shift(xpos6,ypos6);
			
			okazaemon.clear(Canvas::ALL);//memory clear
			
			okazaemon.oval(rect1,col2);//set ovals
			okazaemon.oval(rect2,col2);
			okazaemon.oval(rect3,col2);
			okazaemon.oval(rect4,col2);
			okazaemon.oval(rect5,col2);
			okazaemon.oval(rect6,col2);
			
			okazaemon.flip(flip_number);//flip!!!

			if(Input::get(Keyboard::esc)){exit(0);};//key trap
		}
	}
}
