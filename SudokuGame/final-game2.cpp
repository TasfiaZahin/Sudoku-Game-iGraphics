#include "iGraphics.h"
# include "gl.h"

#define grid yo

int flagmouse = 0,flagkeyboard = 0, checkflag=0,flagremove=0,checkallryt = -1 ,page1=1,page2=0,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0,leader=0; double x,y;

int countscore=100;
int update_update ; 
int bro_pos ;
char name[10][100] ;
int score[10] ;
int mode ;
char str2[100] , str[100] ;
int len ;
int take_result ;

int f11=0,f12=0,f13=0,f14=0,f15=0,f16=0,f17=0,f18=0,f19=0,f20=0,f21=0,f22=0,f23=0,f24=0,f25=0,f26=0,f27=0,f28=0,f29=0,f30=0,f31=0,f32=0,f33=0,f34=0,f35=0,f36=0,f37=0,f38=0,f39=0,f40=0,f41=0,f42=0,f43=0,f44=0,f45=0,f46=0;
int f47=0,f48=0,f49=0,f50=0,f51=0,f52=0,f53=0,f54=0,f55=0,f56=0,f57=0,f58=0,f59=0,f60=0,f61=0,f62=0,f63=0,f64=0,f65=0,f66=0,f67=0,f68=0,f69=0,f70=0,f71=0,f72=0,f73=0,f74=0,f75=0,f76=0,f77=0,f78=0,f79=0,f80=0,f81=0,f82=0;
int f83=0,f84=0,f85=0,f86=0,f87=0,f88=0,f89=0,f90=0,f91=0,f92=0,f93=0,f94=0,f95=0,f96=0,f97=0,f98=0,f99=0;

int stage5_values[10][10];
int stage4_values[10][10];
int stage3_values[10][10];
int stage2_values[10][10];
int stage1_values[10][10];

int stage_sol_5[10][10];
int stage_sol_4[10][10];
int stage_sol_3[10][10];
int stage_sol_2[10][10];
int stage_sol_1[10][10];
int show_result ; 
//int check_stage[15] ;


char printscore[10];
void drawTextBox() ;
void stage_5();
void stage_1();
void stage_2();
void stage_3();
void stage_4();
void soln_stage5();
void soln_stage4();
void soln_stage3();
void soln_stage2();
void soln_stage1();
void leaderboard_update() ;
void leaderboard_update2() ;
void leaderboard_show() ;
void tarnsit();

void transit(void)
{

	f11=0,f12=0,f13=0,f14=0,f15=0,f16=0,f17=0,f18=0,f19=0,f20=0,f21=0,f22=0,f23=0,f24=0,f25=0,f26=0,f27=0,f28=0,f29=0,f30=0,f31=0,f32=0,f33=0,f34=0,f35=0,f36=0,f37=0,f38=0,f39=0,f40=0,f41=0,f42=0,f43=0,f44=0,f45=0,f46=0;
	f47=0,f48=0,f49=0,f50=0,f51=0,f52=0,f53=0,f54=0,f55=0,f56=0,f57=0,f58=0,f59=0,f60=0,f61=0,f62=0,f63=0,f64=0,f65=0,f66=0,f67=0,f68=0,f69=0,f70=0,f71=0,f72=0,f73=0,f74=0,f75=0,f76=0,f77=0,f78=0,f79=0,f80=0,f81=0,f82=0;
	f83=0,f84=0,f85=0,f86=0,f87=0,f88=0,f89=0,f90=0,f91=0,f92=0,f93=0,f94=0,f95=0,f96=0,f97=0,f98=0,f99=0;

}
void iDraw(void)
{
	iClear();
	printf("yoyo %d \n",show_result  ) ;
	if(show_result && page1 == 0 ){
		iClear();
		iShowBMP(0,0,"difficullty.bmp");
		iShowBMP(1000,600,"goback.bmp");
		iText(20, 100, " score") ;
		leaderboard_show() ;
	}
	if(page1==1)
	{
		iClear();
		iShowBMP(0,0,"difficullty.bmp");
		iShowBMP(0,350,"sudoku_title.bmp");
		iShowBMP(20,250,"newgame.bmp");
		iShowBMP(890,250,"leaderboard.bmp");
		//iShowBMP(20,110,"loadgame.bmp");
		iShowBMP(890,110,"exit.bmp");
		iShowBMP(475,70,"tom2.bmp");
	}
	

	if(page2==1){
		iClear();
	iShowBMP(0,0,"difficullty.bmp");
	iShowBMP(225,550,"difficultylevel.bmp");
	iShowBMP(475,450,"level1.bmp");
	iShowBMP(475,360,"level2.bmp");
	iShowBMP(475,270,"level3.bmp");
	iShowBMP(475,180,"level4.bmp");
	iShowBMP(475,90,"level5.bmp");
	iShowBMP(50,70,"goback.bmp");
	}


	if (page3==1 && !show_result ){
		iClear();
	//int countscore=500;
	sprintf(printscore, "%d", countscore);
	iSetColor(255,50,255);
	iShowBMP(0,0,"back1.bmp");
	iSetColor(0,0,255);
	stage_5();
	
	if(checkflag==1)
	{
			soln_stage5();
	}

		iSetColor(0,0,0);
		iFilledRectangle(493,84,7,580);
		iFilledRectangle(688,84,7,580);
		iFilledRectangle(305,466,582,8);
		iFilledRectangle(305,271,582,8);

		iShowBMP(55,598,"check.bmp");
		iShowBMP(55,510,"goback.bmp");
		//iShowBMP(55,510-88,"next.bmp");
		iSetColor(0,0,0);
		sprintf(printscore, "%d", countscore);
		printf("score :: %d", countscore ) ;
		iText(60,510-150,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(60,510-196,printscore, GLUT_BITMAP_TIMES_ROMAN_24);
		//checkflag = 1 , checkallryt = 0 ; // eta fao 
		if( checkallryt==0) checkflag =1  ;
		if(checkflag==1 && checkallryt==0)
		{
			printf("up = %d\n", update_update ) ;
				 if( !show_result) iClear();
				 if( update_update == 0) iShowBMP(0,0,"congrats.bmp");
				 if( update_update == 0)iText( 10 , 200 , "press c to see leaderboard") ;

				 if( update_update && take_result)
				 {
					   iSetColor( 0 , 0 , 255) ;
		              iShowBMP( 0 , 0 , "write_name.bmp") ;

		               drawTextBox() ;
		              iSetColor( 255 , 0 , 0 ) ;
                      iText( 10 , 50 , "please enter your name : ") ;
	
	      	          iText(10, 10, "Click to activate the box, enter to finish.");
		              printf("str name:: %s\n", str) ;//iSetColor( 0 , 0 , 255) ;//............................................................................
	           
            iSetColor(0, 0, 255 );
            iText(80, 110, str);
            //printf("str === %s\n", str) ;
        
     
				 }
			
		}
	}


	if(page4==1 && !show_result )
	{
		iClear();
		//countscore=500;
	iSetColor(255,50,255);
	iShowBMP(0,0,"back2.bmp");
	iSetColor(0,0,255);
	stage_1();

	if(checkflag==1)
	{
		soln_stage1();
	}

	iSetColor(0,0,0);
	iFilledRectangle(493,84,7,580);
	iFilledRectangle(688,84,7,580);
	iFilledRectangle(305,466,582,8);
	iFilledRectangle(305,271,582,8);

	iShowBMP(55,598,"check.bmp");
	iShowBMP(55,510,"goback.bmp");
	//iShowBMP(55,510-88,"next.bmp");
	iSetColor(0,0,0);
		sprintf(printscore, "%d", countscore);
		printf("score :: %d", countscore ) ;
		iText(60,510-150,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(60,510-196,printscore, GLUT_BITMAP_TIMES_ROMAN_24);

	if( checkallryt==0) checkflag =1  ;
		if(checkflag==1 && checkallryt==0)
		{
			printf("up = %d\n", update_update ) ;
				 if( !show_result) iClear();
				 if( update_update == 0) iShowBMP(0,0,"congrats.bmp");
				 if( update_update == 0)iText( 10 , 200 , "press c to see leaderboard") ;

				 if( update_update && take_result)
				 {
					   iSetColor( 0 , 0 , 255) ;
		              iShowBMP( 0 , 0 , "write_name.bmp") ;

		               drawTextBox() ;
		              iSetColor( 255 , 0 , 0 ) ;
                      iText( 10 , 50 , "please enter your name : ") ;
	
	      	          iText(10, 10, "Click to activate the box, enter to finish.");
		              printf("str name:: %s\n", str) ;//iSetColor( 0 , 0 , 255) ;//............................................................................
	           
            iSetColor(0, 0, 255 );
            iText(80, 110, str);
            //printf("str === %s\n", str) ;
        
     
				 }
			
		}
	}


	if(page5==1 && !show_result ){
		iClear();
		//countscore=500;
		iSetColor(255,50,255);
		iShowBMP(0,0,"back3.bmp");
		iSetColor(0,0,255);
		stage_2();

		if(checkflag==1)
		{
			soln_stage2();
		}

		iSetColor(0,0,0);
		iFilledRectangle(493,84,7,580);
		iFilledRectangle(688,84,7,580);
		iFilledRectangle(305,466,582,8);
		iFilledRectangle(305,271,582,8);

		iShowBMP(55,598,"check.bmp");
		iShowBMP(55,510,"goback.bmp");
		//iShowBMP(55,510-88,"next.bmp");
		iSetColor(0,0,0);
		sprintf(printscore, "%d", countscore);
		printf("score :: %d", countscore ) ;
		iText(60,510-150,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(60,510-196,printscore, GLUT_BITMAP_TIMES_ROMAN_24);

		if( checkallryt==0) checkflag =1  ;
		if(checkflag==1 && checkallryt==0)
		{
			printf("up = %d\n", update_update ) ;
				 if( !show_result) iClear();
				 if( update_update == 0) iShowBMP(0,0,"congrats.bmp");
				 if( update_update == 0)iText( 10 , 200 , "press c to see leaderboard") ;

				 if( update_update && take_result)
				 {
					   iSetColor( 0 , 0 , 255) ;
		              iShowBMP( 0 , 0 , "write_name.bmp") ;

		               drawTextBox() ;
		              iSetColor( 255 , 0 , 0 ) ;
                      iText( 10 , 50 , "please enter your name : ") ;
	
	      	          iText(10, 10, "Click to activate the box, enter to finish.");
		              printf("str name:: %s\n", str) ;//iSetColor( 0 , 0 , 255) ;//............................................................................
	           
            iSetColor(0, 0, 255 );
            iText(80, 110, str);
            //printf("str === %s\n", str) ;
        
     
				 }
			
		}
		
	}

	if(page6==1 && !show_result )
	{
		iClear();
		//countscore=500;
		iSetColor(255,50,255);
		iShowBMP(0,0,"back4.bmp");
		iSetColor(0,0,255);
		stage_4();

		if(checkflag==1)
		{
			soln_stage4();
		}

		iSetColor(0,0,0);
		iFilledRectangle(493,84,7,580);
		iFilledRectangle(688,84,7,580);
		iFilledRectangle(305,466,582,8);
		iFilledRectangle(305,271,582,8);

		iShowBMP(55,598,"check.bmp");
		iShowBMP(55,510,"goback.bmp");
		//iShowBMP(55,510-88,"next.bmp");
		iSetColor(0,0,0);
		sprintf(printscore, "%d", countscore);
		printf("score :: %d", countscore ) ;
		iText(60,510-150,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(60,510-196,printscore, GLUT_BITMAP_TIMES_ROMAN_24);

		if( checkallryt==0) checkflag =1  ;
		if(checkflag==1 && checkallryt==0)
		{
			printf("up = %d\n", update_update ) ;
				 if( !show_result) iClear();
				 if( update_update == 0) iShowBMP(0,0,"congrats.bmp");
				 if( update_update == 0)iText( 10 , 200 , "press c to see leaderboard") ;

				 if( update_update && take_result)
				 {
					   iSetColor( 0 , 0 , 255) ;
		              iShowBMP( 0 , 0 , "write_name.bmp") ;

		               drawTextBox() ;
		              iSetColor( 255 , 0 , 0 ) ;
                      iText( 10 , 50 , "please enter your name : ") ;
	
	      	          iText(10, 10, "Click to activate the box, enter to finish.");
		              printf("str name:: %s\n", str) ;//iSetColor( 0 , 0 , 255) ;//............................................................................
	           
            iSetColor(0, 0, 255 );
            iText(80, 110, str);
            //printf("str === %s\n", str) ;
        
     
				 }
			
		}
	}

	if(page7==1 && !show_result )
	{
		iClear();
		//countscore=500;
		iSetColor(255,50,255);
		iShowBMP(0,0,"back5.bmp");
		iSetColor(0,0,255);
		stage_3();

		if(checkflag==1)
		{
			soln_stage3();
		}

		iSetColor(0,0,0);
		iFilledRectangle(493,84,7,580);
		iFilledRectangle(688,84,7,580);
		iFilledRectangle(305,466,582,8);
		iFilledRectangle(305,271,582,8);

		iShowBMP(55,598,"check.bmp");
		iShowBMP(55,510,"goback.bmp");

		iSetColor(0,0,0);
		sprintf(printscore, "%d", countscore);
		printf("score :: %d", countscore ) ;
		iText(60,510-150,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(60,510-196,printscore, GLUT_BITMAP_TIMES_ROMAN_24);

		if( checkallryt==0) checkflag =1  ;
		if(checkflag==1 && checkallryt==0)
		{
			printf("up = %d\n", update_update ) ;
				 if( !show_result) iClear();
				 if( update_update == 0) iShowBMP(0,0,"congrats.bmp");
				 if( update_update == 0)iText( 10 , 200 , "press c to see leaderboard") ;

				 if( update_update && take_result)
				 {
					   iSetColor( 0 , 0 , 255) ;
		              iShowBMP( 0 , 0 , "write_name.bmp") ;

		               drawTextBox() ;
		              iSetColor( 255 , 0 , 0 ) ;
                      iText( 10 , 50 , "please enter your name : ") ;
	
	      	          iText(10, 10, "Click to activate the box, enter to finish.");
		              printf("str name:: %s\n", str) ;//iSetColor( 0 , 0 , 255) ;//............................................................................
	           
            iSetColor(0, 0, 255 );
            iText(80, 110, str);
            //printf("str === %s\n", str) ;
        
     
				 }
			
		}
	}

	if(page8==1  ){
		iClear();
		iShowBMP(0,0,"difficullty.bmp");
		iShowBMP(1000,600,"goback.bmp");
		iText(20, 100, " score") ;
		leaderboard_show() ;
	}


}

void iMouseMove(int mx, int my)
{
	x=mx;
	y=my;
	//place your codes here
}

	
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx >= 50 && mx <= 300 && my >= 100 && my <= 280 && mode == 0 )//arekta flag 
	{
		//place your codes here	
		
			mode = 1;
		
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(page1==1){

			if((mx>20 && mx<20+500) && (my>250 && my<250+100)) page1=0,page2=1,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;		
			if((mx>890 && mx<800+530) && (my>110 && my<110+100)) exit(0);
			if((mx>890 && mx<880+450) && (my>250 && my<250+100)) leader=1,leaderboard_show(),page1=0,page2=0,page3=0,page4=0,page5=0,page6=0,page7=0,page8=1;
			//iShowBMP(890,250,"leaderboard.bmp");
		}

		if(page2==1){ //click happens in page 2 diffficulty level page


			if((mx>475 && mx<475+400) && (my>450 && my<450+70)) flagmouse=0,transit(),page1=0,page2=0,page3=1,page4=0,page5=0,page6=0,page7=0,page8=0,countscore = 100 ; 
			if((mx>475 && mx<475+400) && (my>360 && my<360+70)) flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=1,page5=0,page6=0,page7=0,page8=0, countscore = 200;

			if((mx>475 && mx<475+400) && (my>270 && my<270+70)) flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=0,page5=1,page6=0,page7=0,page8=0, countscore = 300;	

			if((mx>475 && mx<475+400) && (my>180 && my<180+70)) flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=0,page5=0,page6=1,page7=0,page8=0, countscore = 400;	
			if((mx>475 && mx<475+400) && (my>90 && my<90+70)) flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=0,page5=0,page6=0,page7=1,page8=0, countscore = 500;

			if((mx>50 && mx<50+180) && (my>70 && my<70+65)) flagmouse=0,transit(),page1=1,page2=0,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;//back
		}

		if(page3==1){
		//iShowBMP2( 300, 470 , "grid2.bmp", 0) ;
		//1st column
		if((mx>300 && mx<365) && (my>600 && my<600+65)) flagmouse=11;
		if((mx>300 && mx<365) && (my>470 && my<470+65)) flagmouse=13;
		if((mx>300 && mx<365) && (my>405 && my<405+65)) flagmouse=14;
		if((mx>300 && mx<365) && (my>340 && my<340+65)) flagmouse=15;
		if((mx>300 && mx<365) && (my>145 && my<145+65)) flagmouse=18;

		//2nd column
		if((mx>365 && mx<365+65) && (my>340 && my<340+65)) flagmouse=25;
		if((mx>365 && mx<365+65) && (my>210 && my<210+65)) flagmouse=27;
		if((mx>365 && mx<365+65) && (my>145 && my<145+65)) flagmouse=28;
		if((mx>365 && mx<365+65) && (my>80 && my<80+65)) flagmouse=29;

		//3rd column
		if((mx>430 && mx<430+65) && (my>535 && my<600+65)) flagmouse=31;
		if((mx>430 && mx<430+65) && (my>470 && my<470+65)) flagmouse=33;
		if((mx>430 && mx<430+65) && (my>405 && my<405+65)) flagmouse=34;
		if((mx>430 && mx<430+65) && (my>340 && my<340+65)) flagmouse=35;
		if((mx>430 && mx<430+65) && (my>145 && my<145+65)) flagmouse=38;

		//4th column
		if((mx>495 && mx<495+65) && (my>535 && my<535+65)) flagmouse=42; 
		if((mx>495 && mx<495+65) && (my>470 && my<470+65)) flagmouse=43;
		if((mx>495 && mx<495+65) && (my>405 && my<405+65)) flagmouse=44;
		if((mx>495 && mx<495+65) && (my>340 && my<340+65)) flagmouse=45;
		if((mx>495 && mx<495+65) && (my>145 && my<145+65)) flagmouse=48;
		if((mx>495 && mx<495+65) && (my>80 && my<80+65)) flagmouse=49;

		//5th column
		if((mx>560 && mx<560+65) && (my>600 && my<600+65)) flagmouse=51;
		if((mx>560 && mx<560+65) && (my>470 && my<470+65)) flagmouse=53;
		if((mx>560 && mx<560+65) && (my>340 && my<340+65)) flagmouse=55;
		if((mx>560 && mx<560+65) && (my>210 && my<210+65)) flagmouse=57;
		if((mx>560 && mx<560+65) && (my>80 && my<80+65)) flagmouse=59;

		//6th column
		if((mx>625 && mx<625+65) && (my>600 && my<600+65)) flagmouse = 61;
		if((mx>625 && mx<625+65) && (my>535 && my<535+65)) flagmouse = 62;
		if((mx>625 && mx<625+65) && (my>340 && my<340+65)) flagmouse = 65;
		if((mx>625 && mx<625+65) && (my>275 && my<275+65)) flagmouse = 66;
		if((mx>625 && mx<625+65) && (my>210 && my<210+65)) flagmouse = 67;
		if((mx>625 && mx<625+65) && (my>145 && my<145+65)) flagmouse = 68;

		//7th column
		if((mx>690 && mx<690+65) && (my>535 && my<535+65)) flagmouse = 72;
		if((mx>690 && mx<690+65) && (my>340 && my<340+65)) flagmouse = 75;
		if((mx>690 && mx<690+65) && (my>275 && my<275+65)) flagmouse = 76;
		if((mx>690 && mx<690+65) && (my>210 && my<210+65)) flagmouse = 77;
		if((mx>690 && mx<690+65) && (my>80 && my<80+65)) flagmouse = 79;
		

		//8th column
		if((mx>755 && mx<755+65) && (my>600 && my<600+65)) flagmouse = 81;
		if((mx>755 && mx<755+65) && (my>535 && my<535+65)) flagmouse = 82;
		if((mx>755 && mx<755+65) && (my>470 && my<470+65)) flagmouse = 83;
		if((mx>755 && mx<755+65) && (my>340 && my<340+65)) flagmouse = 85;

		//9th column
		if((mx>820 && mx<820+65) && (my>535 && my<535+65)) flagmouse = 92;
		if((mx>820 && mx<820+65) && (my>340 && my<340+65)) flagmouse = 95;
		if((mx>820 && mx<820+65) && (my>275 && my<275+65)) flagmouse = 96;
		if((mx>820 && mx<820+65) && (my>210 && my<210+65)) flagmouse = 97;
		if((mx>820 && mx<820+65) && (my>80 && my<80+65)) flagmouse = 99;

//for cicking on check
		if((mx>55 && mx<55+180) && (my>598 && my<598+65)) checkflag=1,countscore-=10;
		if((mx<55 || mx>55+180) || (my<598 || my>598+65)) checkflag=0;

		if((mx>55 && mx<55+180) && (my>510 && my<510+65))  flagmouse=0,transit(),page1=0,page2=1,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;//back
	//	if((mx>55 && mx<55+180) && (my>510-88 && my<510-88+65))  flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=1,page5=0,page6=0,page7=0,page8=0;//next
		//iShowBMP(55,510-88,"next.bmp");

		}																

		if(page4==1){

			//1st column
			if((mx>300 && mx<365) && (my>470 && my<470+65)) flagmouse=13;
			if((mx>300 && mx<365) && (my>210 && my<210+65)) flagmouse=17;
			if((mx>300 && mx<365) && (my>145 && my<145+65)) flagmouse=18;
			if((mx>300 && mx<365) && (my>80 && my<80+65)) flagmouse=19;

			//2nd column
			if((mx>365 && mx<365+65) && (my>535 && my<535+65)) flagmouse=22;
			if((mx>365 && mx<365+65) && (my>405 && my<405+65)) flagmouse=24;
			if((mx>365 && mx<365+65) && (my>340 && my<340+65)) flagmouse=25;
			if((mx>365 && mx<365+65) && (my>275 && my<275+65)) flagmouse=26;
			if((mx>365 && mx<365+65) && (my>145 && my<145+65)) flagmouse=28;
			if((mx>365 && mx<365+65) && (my>80 && my<80+65)) flagmouse=29;

			//3rd column
			if((mx>430 && mx<430+65) && (my>600 && my<600+65)) flagmouse=31;
			if((mx>430 && mx<430+65) && (my>535 && my<535+65)) flagmouse=32;
			if((mx>430 && mx<430+65) && (my>405 && my<405+65)) flagmouse=34;
			if((mx>430 && mx<430+65) && (my>340 && my<340+65)) flagmouse=35;
			if((mx>430 && mx<430+65) && (my>275 && my<275+65)) flagmouse=36;
			if((mx>430 && mx<430+65) && (my>210 && my<210+65)) flagmouse=37;
			if((mx>430 && mx<430+65) && (my>145 && my<145+65)) flagmouse=38;
			if((mx>430 && mx<430+65) && (my>80&& my<80+65)) flagmouse=39;

			//4th column
			if((mx>495 && mx<495+65) && (my>600 && my<600+65)) flagmouse=41;
			if((mx>495 && mx<495+65) && (my>470 && my<470+65)) flagmouse=43;
			if((mx>495 && mx<495+65) && (my>405 && my<405+65)) flagmouse=44;
			if((mx>495 && mx<495+65) && (my>275 && my<275+65)) flagmouse=46;
			if((mx>495 && mx<495+65) && (my>210 && my<210+65)) flagmouse=47;
			if((mx>495 && mx<495+65) && (my>80 && my<80+65)) flagmouse=49;

			//5th column
			if((mx>560 && mx<560+65) && (my>470 && my<470+65)) flagmouse=53;
			if((mx>560 && mx<560+65) && (my>340 && my<340+65)) flagmouse=55;
			if((mx>560 && mx<560+65) && (my>210 && my<210+65)) flagmouse=57;

			//6th column
			if((mx>625 && mx<625+65) && (my>600 && my<600+65)) flagmouse = 61;
			if((mx>625 && mx<625+65) && (my>470 && my<470+65)) flagmouse = 63;
			if((mx>625 && mx<625+65) && (my>405 && my<405+65)) flagmouse = 64;
			if((mx>625 && mx<625+65) && (my>275 && my<275+65)) flagmouse = 66;
			if((mx>625 && mx<625+65) && (my>210 && my<210+65)) flagmouse = 67;
			if((mx>625 && mx<625+65) && (my>80 && my<80+65)) flagmouse = 69;

			//7th column
			if((mx>690 && mx<690+65) && (my>600 && my<600+65)) flagmouse = 71;
			if((mx>690 && mx<690+65) && (my>535 && my<535+65)) flagmouse = 72;
			if((mx>690 && mx<690+65) && (my>470 && my<470+65)) flagmouse = 73;
			if((mx>690 && mx<690+65) && (my>405 && my<405+65)) flagmouse = 74;
			if((mx>690 && mx<690+65) && (my>340 && my<340+65)) flagmouse = 75;
			if((mx>690 && mx<690+65) && (my>275 && my<275+65)) flagmouse = 76;
			if((mx>690 && mx<690+65) && (my>145 && my<145+65)) flagmouse = 78;
			if((mx>690 && mx<690+65) && (my>80 && my<80+65)) flagmouse = 79;

			//8th column
			if((mx>755 && mx<755+65) && (my>600 && my<600+65)) flagmouse = 81;
			if((mx>755 && mx<755+65) && (my>535 && my<535+65)) flagmouse = 82;
			if((mx>755 && mx<755+65) && (my>405 && my<405+65)) flagmouse = 84;
			if((mx>755 && mx<755+65) && (my>340 && my<340+65)) flagmouse = 85;
			if((mx>755 && mx<755+65) && (my>275 && my<275+65)) flagmouse = 86;
			if((mx>755 && mx<755+65) && (my>145 && my<145+65)) flagmouse = 88;

			//9th column
			if((mx>820 && mx<820+65) && (my>600 && my<600+65)) flagmouse = 91;
			if((mx>820 && mx<820+65) && (my>535 && my<535+65)) flagmouse = 92;
			if((mx>820 && mx<820+65) && (my>470 && my<470+65)) flagmouse = 93;
			if((mx>820 && mx<820+65) && (my>210 && my<210+65)) flagmouse = 97;

		//for cicking on check
			if((mx>55 && mx<55+180) && (my>598 && my<598+65)) checkflag=1,countscore-=10;
			if((mx<55 || mx>55+180) || (my<598 || my>598+65)) checkflag=0;

			if((mx>55 && mx<55+180) && (my>510 && my<510+65)) flagmouse=0,transit(),page1=0,page2=1,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;//back
			//if((mx>55 && mx<55+180) && (my>510-88 && my<510-88+65)) flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=0,page5=1,page6=0,page7=0,page8=0;//next
		}

		if(page5==1)
		{
				//1st column 11 12 14 16 17
			if((mx>300 && mx<365) && (my>600 && my<600+65)) flagmouse=11;
			if((mx>300 && mx<365) && (my>535 && my<535+65)) flagmouse=12;
			if((mx>300 && mx<365) && (my>405 && my<405+65)) flagmouse=14;
			if((mx>300 && mx<365) && (my>275 && my<275+65)) flagmouse=16;
			if((mx>300 && mx<365) && (my>210 && my<210+65)) flagmouse=17;

			//2nd column 21 22 23 24 25 26 28 
			if((mx>365 && mx<365+65) && (my>600 && my<600+65)) flagmouse=21;
			if((mx>365 && mx<365+65) && (my>535 && my<535+65)) flagmouse=22;
			if((mx>365 && mx<365+65) && (my>470 && my<470+65)) flagmouse=23;
			if((mx>365 && mx<365+65) && (my>405 && my<405+65)) flagmouse=24;
			if((mx>365 && mx<365+65) && (my>340 && my<340+65)) flagmouse=25;
			if((mx>365 && mx<365+65) && (my>275 && my<275+65)) flagmouse=26;
			if((mx>365 && mx<365+65) && (my>145 && my<145+65)) flagmouse=28;

			//3rd column 31 32 35 36 37 39
			if((mx>430 && mx<430+65) && (my>600 && my<600+65)) flagmouse=31;
			if((mx>430 && mx<430+65) && (my>535 && my<535+65)) flagmouse=32;
			if((mx>430 && mx<430+65) && (my>340 && my<340+65)) flagmouse=35;
			if((mx>430 && mx<430+65) && (my>275 && my<275+65)) flagmouse=36;
			if((mx>430 && mx<430+65) && (my>210 && my<210+65)) flagmouse=37;
			if((mx>430 && mx<430+65) && (my>80&& my<80+65)) flagmouse=39;

			//4th column 42 43 44 45 47 48 
			if((mx>495 && mx<495+65) && (my>535 && my<535+65)) flagmouse=42;
			if((mx>495 && mx<495+65) && (my>470 && my<470+65)) flagmouse=43;
			if((mx>495 && mx<495+65) && (my>405 && my<405+65)) flagmouse=44;
			if((mx>495 && mx<495+65) && (my>340 && my<340+65)) flagmouse=45;
			if((mx>495 && mx<495+65) && (my>210 && my<210+65)) flagmouse=47;
			if((mx>495 && mx<495+65) && (my>145 && my<145+65)) flagmouse=48;

			//5th column 51 52 53 55 57 58 59
			if((mx>560 && mx<560+65) && (my>600 && my<600+65)) flagmouse=51;
			if((mx>560 && mx<560+65) && (my>535 && my<535+65)) flagmouse=52;
			if((mx>560 && mx<560+65) && (my>470 && my<470+65)) flagmouse=53;
			if((mx>560 && mx<560+65) && (my>340 && my<340+65)) flagmouse=55;
			if((mx>560 && mx<560+65) && (my>210 && my<210+65)) flagmouse=57;
			if((mx>560 && mx<560+65) && (my>145 && my<145+65)) flagmouse=58;
			if((mx>560 && mx<560+65) && (my>80 && my<80+65)) flagmouse=59;

			//6th  62 63 65 66 67 68
			if((mx>625 && mx<625+65) && (my>535 && my<535+65)) flagmouse = 62;
			if((mx>625 && mx<625+65) && (my>470 && my<470+65)) flagmouse = 63;
			if((mx>625 && mx<625+65) && (my>340 && my<340+65)) flagmouse = 65;
			if((mx>625 && mx<625+65) && (my>275 && my<275+65)) flagmouse = 66;
			if((mx>625 && mx<625+65) && (my>210 && my<210+65)) flagmouse = 67;
			if((mx>625 && mx<625+65) && (my>145 && my<145+65)) flagmouse = 68;

			//7th column 71 73 74 75 78 79
			if((mx>690 && mx<690+65) && (my>600 && my<600+65)) flagmouse = 71;
			if((mx>690 && mx<690+65) && (my>470 && my<470+65)) flagmouse = 73;
			if((mx>690 && mx<690+65) && (my>405 && my<405+65)) flagmouse = 74;
			if((mx>690 && mx<690+65) && (my>340 && my<340+65)) flagmouse = 75;
			if((mx>690 && mx<690+65) && (my>145 && my<145+65)) flagmouse = 78;
			if((mx>690 && mx<690+65) && (my>80 && my<80+65)) flagmouse = 79;

			//8th column 82 84 85 86 87 88 89
			if((mx>755 && mx<755+65) && (my>535 && my<535+65)) flagmouse = 82;
			if((mx>755 && mx<755+65) && (my>405 && my<405+65)) flagmouse = 84;
			if((mx>755 && mx<755+65) && (my>340 && my<340+65)) flagmouse = 85;
			if((mx>755 && mx<755+65) && (my>275 && my<275+65)) flagmouse = 86;
			if((mx>755 && mx<755+65) && (my>210 && my<210+65)) flagmouse = 87;
			if((mx>755 && mx<755+65) && (my>145 && my<145+65)) flagmouse = 88;
			if((mx>755 && mx<755+65) && (my>80 && my<80+65)) flagmouse = 89;

			//9th column 93 94 96 98 99
			if((mx>820 && mx<820+65) && (my>470 && my<470+65)) flagmouse = 93;
			if((mx>820 && mx<820+65) && (my>405 && my<405+65)) flagmouse = 94;
			if((mx>820 && mx<820+65) && (my>275 && my<275+65)) flagmouse = 96;
			if((mx>820 && mx<820+65) && (my>145 && my<145+65)) flagmouse = 98;
			if((mx>820 && mx<820+65) && (my>80 && my<80+65)) flagmouse = 99;

			//for cicking on check
			if((mx>55 && mx<55+180) && (my>598 && my<598+65)) checkflag=1,countscore-=10;
			if((mx<55 || mx>55+180) || (my<598 || my>598+65)) checkflag=0;

			if((mx>55 && mx<55+180) && (my>510 && my<510+65)) flagmouse=0,transit(),page1=0,page2=1,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;
			//if((mx>55 && mx<55+180) && (my>510-88 && my<510-88+65)) flagmouse=0,transit(),page1=0,page2=0,page3=0,page4=0,page5=0,page6=1,page7=0,page8=0;

		}

		if(page6==1)
		{
			//1st column
		if((mx>300 && mx<365) && (my>600 && my<600+65)) flagmouse=11;
		if((mx>300 && mx<365) && (my>535 && my<535+65)) flagmouse=12;
		if((mx>300 && mx<365) && (my>470 && my<470+65)) flagmouse=13;
		if((mx>300 && mx<365) && (my>405 && my<405+65)) flagmouse=14;
		if((mx>300 && mx<365) && (my>340 && my<340+65)) flagmouse=15;
		if((mx>300 && mx<365) && (my>210 && my<210+65)) flagmouse=17;
		if((mx>300 && mx<365) && (my>80 && my<80+65)) flagmouse=19;

		//2nd column
		if((mx>365 && mx<365+65) && (my>535 && my<535+65)) flagmouse=22;
		if((mx>365 && mx<365+65) && (my>470 && my<470+65)) flagmouse=23;
		if((mx>365 && mx<365+65) && (my>405 && my<405+65)) flagmouse=24;
		if((mx>365 && mx<365+65) && (my>275 && my<275+65)) flagmouse=26;
		if((mx>365 && mx<365+65) && (my>210 && my<210+65)) flagmouse=27;
		if((mx>365 && mx<365+65) && (my>145 && my<145+65)) flagmouse=28;

		//3rd column
		if((mx>430 && mx<430+65) && (my>600 && my<600+65)) flagmouse=31;
		if((mx>430 && mx<430+65) && (my>470 && my<470+65)) flagmouse=33;
		if((mx>430 && mx<430+65) && (my>340 && my<340+65)) flagmouse=35;
		if((mx>430 && mx<430+65) && (my>275 && my<275+65)) flagmouse=36;
		if((mx>430 && mx<430+65) && (my>145 && my<145+65)) flagmouse=38;
		if((mx>430 && mx<430+65) && (my>80&& my<80+65)) flagmouse=39;

		//4th column
		if((mx>495 && mx<495+65) && (my>600 && my<600+65)) flagmouse=41;
		if((mx>495 && mx<495+65) && (my>470 && my<470+65)) flagmouse=43;
		if((mx>495 && mx<495+65) && (my>405 && my<405+65)) flagmouse=44;
		if((mx>495 && mx<495+65) && (my>340 && my<340+65)) flagmouse=45;
		if((mx>495 && mx<495+65) && (my>275 && my<275+65)) flagmouse=46;
		if((mx>495 && mx<495+65) && (my>210 && my<210+65)) flagmouse=47;
		if((mx>495 && mx<495+65) && (my>145 && my<145+65)) flagmouse=48;

		//5th column
		if((mx>560 && mx<560+65) && (my>600 && my<600+65)) flagmouse=51;
		if((mx>560 && mx<560+65) && (my>535 && my<535+65)) flagmouse=52;
		if((mx>560 && mx<560+65) && (my>340 && my<470+65)) flagmouse=55;
		if((mx>560 && mx<560+65) && (my>145 && my<145+65)) flagmouse=58;
		if((mx>560 && mx<560+65) && (my>80 && my<80+65)) flagmouse=59;

		//6th column
		if((mx>625 && mx<625+65) && (my>535 && my<535+65)) flagmouse = 62;
		if((mx>625 && mx<625+65) && (my>470 && my<470+65)) flagmouse = 63;
		if((mx>625 && mx<625+65) && (my>405 && my<405+65)) flagmouse = 64;
		if((mx>625 && mx<625+65) && (my>210 && my<210+65)) flagmouse = 67;
		if((mx>625 && mx<625+65) && (my>80 && my<80+65)) flagmouse = 69;

		//7th column
		if((mx>690 && mx<690+65) && (my>600 && my<600+65)) flagmouse = 71;
		if((mx>690 && mx<690+65) && (my>535 && my<535+65)) flagmouse = 72;
		if((mx>690 && mx<690+65) && (my>405 && my<405+65)) flagmouse = 74;
		if((mx>690 && mx<690+65) && (my>340 && my<340+65)) flagmouse = 75;
		if((mx>690 && mx<690+65) && (my>210 && my<210+65)) flagmouse = 77;
		if((mx>690 && mx<690+65) && (my>80 && my<80+65)) flagmouse = 79;

		//8th column
		if((mx>755 && mx<755+65) && (my>535 && my<535+65)) flagmouse = 82;
		if((mx>755 && mx<755+65) && (my>470 && my<470+65)) flagmouse = 83;
		if((mx>755 && mx<755+65) && (my>405 && my<405+65)) flagmouse = 84;
		if((mx>755 && mx<755+65) && (my>275 && my<275+65)) flagmouse = 86;
		if((mx>755 && mx<755+65) && (my>210 && my<210+65)) flagmouse = 87;
		if((mx>755 && mx<755+65) && (my>145 && my<145+65)) flagmouse = 88;

		//9th column
		if((mx>820 && mx<820+65) && (my>600 && my<600+65)) flagmouse = 91;
		if((mx>820 && mx<820+65) && (my>470 && my<470+65)) flagmouse = 93;
		if((mx>820 && mx<820+65) && (my>340 && my<340+65)) flagmouse = 95;
		if((mx>820 && mx<820+65) && (my>275 && my<275+65)) flagmouse = 96;
		if((mx>820 && mx<820+65) && (my>210 && my<210+65)) flagmouse = 97;
		if((mx>820 && mx<820+65) && (my>145 && my<145+65)) flagmouse = 98;
		if((mx>820 && mx<820+65) && (my>80 && my<80+65)) flagmouse = 99;

		//for cicking on check
		if((mx>55 && mx<55+180) && (my>598 && my<598+65)) checkflag=1,countscore-=10;
		if((mx<55 || mx>55+180) || (my<598 || my>598+65)) checkflag=0;

		if((mx>55 && mx<55+180) && (my>510 && my<510+65)) flagmouse=0,transit(),page1=0,page2=1,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;//back
		//if((mx>55 && mx<55+180) && (my>510-88 && my<510-88+65))flagmouse=0,transit(), page1=0,page2=0,page3=0,page4=0,page5=0,page6=0,page7=1,page8=0;//next
		}

		if(page7==1)
		{
			//1st column
		if((mx>300 && mx<365) && (my>600 && my<600+65)) flagmouse=11;
		if((mx>300 && mx<365) && (my>470 && my<470+65)) flagmouse=13;
		if((mx>300 && mx<365) && (my>405 && my<405+65)) flagmouse=14;
		if((mx>300 && mx<365) && (my>340 && my<340+65)) flagmouse=15;
		if((mx>300 && mx<365) && (my>275 && my<275+65)) flagmouse=16;
		if((mx>300 && mx<365) && (my>210 && my<210+65)) flagmouse=17;
		if((mx>300 && mx<365) && (my>145 && my<145+65)) flagmouse=18;
		if((mx>300 && mx<365) && (my>80 && my<80+65)) flagmouse=19;

		//2nd column
		if((mx>365 && mx<365+65) && (my>600 && my<600+65)) flagmouse=21;
		if((mx>365 && mx<365+65) && (my>535 && my<535+65)) flagmouse=22;
		if((mx>365 && mx<365+65) && (my>470 && my<470+65)) flagmouse=23;
		if((mx>365 && mx<365+65) && (my>405 && my<405+65)) flagmouse=24;
		if((mx>365 && mx<365+65) && (my>340 && my<340+65)) flagmouse=25;
		if((mx>365 && mx<365+65) && (my>275 && my<275+65)) flagmouse=26;
		if((mx>365 && mx<365+65) && (my>210 && my<210+65)) flagmouse=27;
		if((mx>365 && mx<365+65) && (my>145 && my<145+65)) flagmouse=28;

		//3rd column
		if((mx>430 && mx<430+65) && (my>535 && my<600+65)) flagmouse=31;
		if((mx>430 && mx<430+65) && (my>535 && my<535+65)) flagmouse=32;
		if((mx>430 && mx<430+65) && (my>470 && my<470+65)) flagmouse=33;
		if((mx>430 && mx<430+65) && (my>405 && my<405+65)) flagmouse=34;
		if((mx>430 && mx<430+65) && (my>340 && my<340+65)) flagmouse=35;
		if((mx>430 && mx<430+65) && (my>275 && my<275+65)) flagmouse=36;
		if((mx>430 && mx<430+65) && (my>210 && my<210+65)) flagmouse=37;
		if((mx>430 && mx<430+65) && (my>80&& my<80+65)) flagmouse=39;

		//4th column
		if((mx>495 && mx<495+65) && (my>535 && my<535+65)) flagmouse=42; 
		if((mx>495 && mx<495+65) && (my>405 && my<405+65)) flagmouse=44;
		if((mx>495 && mx<495+65) && (my>275 && my<275+65)) flagmouse=46;
		if((mx>495 && mx<495+65) && (my>210 && my<210+65)) flagmouse=47;
		if((mx>495 && mx<495+65) && (my>145 && my<145+65)) flagmouse=48;
		if((mx>495 && mx<495+65) && (my>80 && my<80+65)) flagmouse=49;

		//5th column
		if((mx>560 && mx<560+65) && (my>600 && my<600+65)) flagmouse=51;
		if((mx>560 && mx<560+65) && (my>535 && my<535+65)) flagmouse=52;
		if((mx>560 && mx<560+65) && (my>405 && my<405+65)) flagmouse=54;
		if((mx>560 && mx<560+65) && (my>340 && my<340+65)) flagmouse=55;
		if((mx>560 && mx<560+65) && (my>275 && my<275+65)) flagmouse=56;
		if((mx>560 && mx<560+65) && (my>145 && my<145+65)) flagmouse=58;
		if((mx>560 && mx<560+65) && (my>80 && my<80+65)) flagmouse=59;

		//6th column
		if((mx>625 && mx<625+65) && (my>600 && my<600+65)) flagmouse = 61;
		if((mx>625 && mx<625+65) && (my>535 && my<535+65)) flagmouse = 62;
		if((mx>625 && mx<625+65) && (my>470 && my<470+65)) flagmouse = 63;
		if((mx>625 && mx<625+65) && (my>405 && my<405+65)) flagmouse = 64;
		if((mx>625 && mx<625+65) && (my>275 && my<275+65)) flagmouse = 66;
		if((mx>625 && mx<625+65) && (my>145 && my<145+65)) flagmouse = 68;
		if((mx>625 && mx<625+65) && (my>80 && my<80+65)) flagmouse = 69;

		//7th column
		if((mx>690 && mx<690+65) && (my>600 && my<600+65)) flagmouse = 71;
		if((mx>690 && mx<690+65) && (my>535 && my<535+65)) flagmouse = 72;
		if((mx>690 && mx<690+65) && (my>405 && my<405+65)) flagmouse = 74;
		if((mx>690 && mx<690+65) && (my>340 && my<340+65)) flagmouse = 75;
		if((mx>690 && mx<690+65) && (my>210 && my<210+65)) flagmouse = 77;
		if((mx>690 && mx<690+65) && (my>145 && my<145+65)) flagmouse = 78;
		

		//8th column
		if((mx>755 && mx<755+65) && (my>600 && my<600+65)) flagmouse = 81;
		if((mx>755 && mx<755+65) && (my>535 && my<535+65)) flagmouse = 82;
		if((mx>755 && mx<755+65) && (my>470 && my<470+65)) flagmouse = 83;
		if((mx>755 && mx<755+65) && (my>405 && my<405+65)) flagmouse = 84;
		if((mx>755 && mx<755+65) && (my>340 && my<340+65)) flagmouse = 85;
		if((mx>755 && mx<755+65) && (my>210 && my<210+65)) flagmouse = 87;
		if((mx>755 && mx<755+65) && (my>80 && my<80+65)) flagmouse = 89;

		//9th column
		if((mx>820 && mx<820+65) && (my>600 && my<600+65)) flagmouse = 91;
		if((mx>820 && mx<820+65) && (my>535 && my<535+65)) flagmouse = 92;
		if((mx>820 && mx<820+65) && (my>470 && my<470+65)) flagmouse = 93;
		if((mx>820 && mx<820+65) && (my>340 && my<340+65)) flagmouse = 95;
		if((mx>820 && mx<820+65) && (my>210 && my<210+65)) flagmouse = 97;
		if((mx>820 && mx<820+65) && (my>145 && my<145+65)) flagmouse = 98;
		if((mx>820 && mx<820+65) && (my>80 && my<80+65)) flagmouse = 99;

	//for cicking on check
		if((mx>55 && mx<55+180) && (my>598 && my<598+65)) checkflag=1,countscore-=10;
		if((mx<55 || mx>55+180) || (my<598 || my>598+65)) checkflag=0;

		if((mx>55 && mx<55+180) && (my>510 && my<510+65)) page1=0,page2=1,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;//back
		}
		if(page8==1){
			
			if((mx>1000 && mx<1000+180) && (my>600 && my<600+65)) flagmouse=0,show_result = 0 , transit(),page1=1,page2=0,page3=0,page4=0,page5=0,page6=0,page7=0,page8=0;//back
		}

	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;

			leaderboard_update2() ;


		}
		else
		{
			str[len] = key;
			len++;
			
		}
	}
	if( key == 'c' && checkallryt == 0 )
	{
		
		leaderboard_update() ;
	}
	if(page3==1){
	if (key == '1' )
	{
		if(flagmouse==11) f11=1, stage5_values[1][1]=1;
		if(flagmouse==13) f13=1, stage5_values[3][1]=1;
		if(flagmouse==14) f14=1, stage5_values[4][1]=1;
		if(flagmouse==15) f15=1, stage5_values[5][1]=1;
		if(flagmouse==18) f18=1, stage5_values[8][1]=1;
		if(flagmouse==25) f25=1, stage5_values[5][2]=1;
		if(flagmouse==27) f27=1, stage5_values[7][2]=1;
		if(flagmouse==28) f28=1, stage5_values[8][2]=1;
		if(flagmouse==29) f29=1, stage5_values[9][2]=1;
		if(flagmouse==31) f31=1, stage5_values[1][3]=1;
		if(flagmouse==33) f33=1, stage5_values[3][3]=1;
		if(flagmouse==34) f34=1, stage5_values[4][3]=1;
		if(flagmouse==35) f35=1, stage5_values[5][3]=1;
		if(flagmouse==38) f38=1, stage5_values[8][3]=1;
		if(flagmouse==42) f42=1, stage5_values[2][4]=1;
		if(flagmouse==43) f43=1, stage5_values[3][4]=1;
		if(flagmouse==44) f44=1, stage5_values[4][4]=1;
		if(flagmouse==45) f45=1, stage5_values[5][4]=1;
		if(flagmouse==48) f48=1, stage5_values[8][4]=1;
		if(flagmouse==49) f49=1, stage5_values[9][4]=1;
		if(flagmouse==51) f51=1, stage5_values[1][5]=1;
		if(flagmouse==53) f53=1, stage5_values[3][5]=1;
		if(flagmouse==55) f55=1, stage5_values[5][5]=1;
		if(flagmouse==57) f57=1, stage5_values[7][5]=1;
		if(flagmouse==59) f59=1, stage5_values[9][5]=1;
		if(flagmouse==61) f61=1, stage5_values[1][6]=1;
		if(flagmouse==62) f62=1, stage5_values[2][6]=1;
		if(flagmouse==65) f65=1, stage5_values[5][6]=1;
		if(flagmouse==66) f66=1, stage5_values[6][6]=1;
		if(flagmouse==67) f67=1, stage5_values[7][6]=1;
		if(flagmouse==68) f68=1, stage5_values[8][6]=1;
		if(flagmouse==72) f72=1, stage5_values[2][7]=1;
		if(flagmouse==75) f75=1, stage5_values[5][7]=1;
		if(flagmouse==76) f76=1, stage5_values[6][7]=1;
		if(flagmouse==77) f77=1, stage5_values[7][7]=1;
		if(flagmouse==79) f79=1, stage5_values[9][7]=1;
		if(flagmouse==81) f81=1, stage5_values[1][8]=1;
		if(flagmouse==82) f82=1, stage5_values[2][8]=1;
		if(flagmouse==83) f83=1, stage5_values[3][8]=1;
		if(flagmouse==85) f85=1, stage5_values[5][8]=1;
		if(flagmouse==92) f92=1, stage5_values[2][9]=1;
		if(flagmouse==95) f95=1, stage5_values[5][9]=1;
		if(flagmouse==96) f96=1, stage5_values[6][9]=1;
		if(flagmouse==97) f97=1, stage5_values[7][9]=1;
		if(flagmouse==99) f99=1, stage5_values[9][9]=1;
	}
	
	if (key == '2')
	{
		if(flagmouse==11) f11=2, stage5_values[1][1]=2;
		if(flagmouse==13) f13=2, stage5_values[3][1]=2;
		if(flagmouse==14) f14=2, stage5_values[4][1]=2;
		if(flagmouse==15) f15=2, stage5_values[5][1]=2;
		if(flagmouse==18) f18=2, stage5_values[8][1]=2;
		if(flagmouse==25) f25=2, stage5_values[5][2]=2;
		if(flagmouse==27) f27=2, stage5_values[7][2]=2;
		if(flagmouse==28) f28=2, stage5_values[8][2]=2;
		if(flagmouse==29) f29=2, stage5_values[9][2]=2;
		if(flagmouse==31) f31=2, stage5_values[1][3]=2;
		if(flagmouse==33) f33=2, stage5_values[3][3]=2;
		if(flagmouse==34) f34=2, stage5_values[4][3]=2;
		if(flagmouse==35) f35=2, stage5_values[5][3]=2;
		if(flagmouse==38) f38=2, stage5_values[8][3]=2;
		if(flagmouse==42) f42=2, stage5_values[2][4]=2;
		if(flagmouse==43) f43=2, stage5_values[3][4]=2;
		if(flagmouse==44) f44=2, stage5_values[4][4]=2;
		if(flagmouse==45) f45=2, stage5_values[5][4]=2;
		if(flagmouse==48) f48=2, stage5_values[8][4]=2;
		if(flagmouse==49) f49=2, stage5_values[9][4]=2;
		if(flagmouse==51) f51=2, stage5_values[1][5]=2;
		if(flagmouse==53) f53=2, stage5_values[3][5]=2;
		if(flagmouse==55) f55=2, stage5_values[5][5]=2;
		if(flagmouse==57) f57=2, stage5_values[7][5]=2;
		if(flagmouse==59) f59=2, stage5_values[9][5]=2;
		if(flagmouse==61) f61=2, stage5_values[1][6]=2;
		if(flagmouse==62) f62=2, stage5_values[2][6]=2;
		if(flagmouse==65) f65=2, stage5_values[5][6]=2;
		if(flagmouse==66) f66=2, stage5_values[6][6]=2;
		if(flagmouse==67) f67=2, stage5_values[7][6]=2;
		if(flagmouse==68) f68=2, stage5_values[8][6]=2;
		if(flagmouse==72) f72=2, stage5_values[2][7]=2;
		if(flagmouse==75) f75=2, stage5_values[5][7]=2;
		if(flagmouse==76) f76=2, stage5_values[6][7]=2;
		if(flagmouse==77) f77=2, stage5_values[7][7]=2;
		if(flagmouse==79) f79=2, stage5_values[9][7]=2;
		if(flagmouse==81) f81=2, stage5_values[1][8]=2;
		if(flagmouse==82) f82=2, stage5_values[2][8]=2;
		if(flagmouse==83) f83=2, stage5_values[3][8]=2;
		if(flagmouse==85) f85=2, stage5_values[5][8]=2;
		if(flagmouse==92) f92=2, stage5_values[2][9]=2;
		if(flagmouse==95) f95=2, stage5_values[5][9]=2;
		if(flagmouse==96) f96=2, stage5_values[6][9]=2;
		if(flagmouse==97) f97=2, stage5_values[7][9]=2;
		if(flagmouse==99) f99=2, stage5_values[9][9]=2;
	}

	if (key == '3')
	{
		if(flagmouse==11) f11=3, stage5_values[1][1]=3;
		if(flagmouse==13) f13=3, stage5_values[3][1]=3;
		if(flagmouse==14) f14=3, stage5_values[4][1]=3;
		if(flagmouse==15) f15=3, stage5_values[5][1]=3;
		if(flagmouse==18) f18=3, stage5_values[8][1]=3;
		if(flagmouse==25) f25=3, stage5_values[5][2]=3;
		if(flagmouse==27) f27=3, stage5_values[7][2]=3;
		if(flagmouse==28) f28=3, stage5_values[8][2]=3;
		if(flagmouse==29) f29=3, stage5_values[9][2]=3;
		if(flagmouse==31) f31=3, stage5_values[1][3]=3;
		if(flagmouse==33) f33=3, stage5_values[3][3]=3;
		if(flagmouse==34) f34=3, stage5_values[4][3]=3;
		if(flagmouse==35) f35=3, stage5_values[5][3]=3;
		if(flagmouse==38) f38=3, stage5_values[8][3]=3;
		if(flagmouse==42) f42=3, stage5_values[2][4]=3;
		if(flagmouse==43) f43=3, stage5_values[3][4]=3;
		if(flagmouse==44) f44=3, stage5_values[4][4]=3;
		if(flagmouse==45) f45=3, stage5_values[5][4]=3;
		if(flagmouse==48) f48=3, stage5_values[8][4]=3;
		if(flagmouse==49) f49=3, stage5_values[9][4]=3;
		if(flagmouse==51) f51=3, stage5_values[1][5]=3;
		if(flagmouse==53) f53=3, stage5_values[3][5]=3;
		if(flagmouse==55) f55=3, stage5_values[5][5]=3;
		if(flagmouse==57) f57=3, stage5_values[7][5]=3;
		if(flagmouse==59) f59=3, stage5_values[9][5]=3;
		if(flagmouse==61) f61=3, stage5_values[1][6]=3;
		if(flagmouse==62) f62=3, stage5_values[2][6]=3;
		if(flagmouse==65) f65=3, stage5_values[5][6]=3;
		if(flagmouse==66) f66=3, stage5_values[6][6]=3;
		if(flagmouse==67) f67=3, stage5_values[7][6]=3;
		if(flagmouse==68) f68=3, stage5_values[8][6]=3;
		if(flagmouse==72) f72=3, stage5_values[2][7]=3;
		if(flagmouse==75) f75=3, stage5_values[5][7]=3;
		if(flagmouse==76) f76=3, stage5_values[6][7]=3;
		if(flagmouse==77) f77=3, stage5_values[7][7]=3;
		if(flagmouse==79) f79=3, stage5_values[9][7]=3;
		if(flagmouse==81) f81=3, stage5_values[1][8]=3;
		if(flagmouse==82) f82=3, stage5_values[2][8]=3;
		if(flagmouse==83) f83=3, stage5_values[3][8]=3;
		if(flagmouse==85) f85=3, stage5_values[5][8]=3;
		if(flagmouse==92) f92=3, stage5_values[2][9]=3;
		if(flagmouse==95) f95=3, stage5_values[5][9]=3;
		if(flagmouse==96) f96=3, stage5_values[6][9]=3;
		if(flagmouse==97) f97=3, stage5_values[7][9]=3;
		if(flagmouse==99) f99=3, stage5_values[9][9]=3;
	}

	if (key == '4')
	{
		if(flagmouse==11) f11=4, stage5_values[1][1]=4;
		if(flagmouse==13) f13=4, stage5_values[3][1]=4;
		if(flagmouse==14) f14=4, stage5_values[4][1]=4;
		if(flagmouse==15) f15=4, stage5_values[5][1]=4;
		if(flagmouse==18) f18=4, stage5_values[8][1]=4;
		if(flagmouse==25) f25=4, stage5_values[5][2]=4;
		if(flagmouse==27) f27=4, stage5_values[7][2]=4;
		if(flagmouse==28) f28=4, stage5_values[8][2]=4;
		if(flagmouse==29) f29=4, stage5_values[9][2]=4;
		if(flagmouse==31) f31=4, stage5_values[1][3]=4;
		if(flagmouse==33) f33=4, stage5_values[3][3]=4;
		if(flagmouse==34) f34=4, stage5_values[4][3]=4;
		if(flagmouse==35) f35=4, stage5_values[5][3]=4;
		if(flagmouse==38) f38=4, stage5_values[8][3]=4;
		if(flagmouse==42) f42=4, stage5_values[2][4]=4;
		if(flagmouse==43) f43=4, stage5_values[3][4]=4;
		if(flagmouse==44) f44=4, stage5_values[4][4]=4;
		if(flagmouse==45) f45=4, stage5_values[5][4]=4;
		if(flagmouse==48) f48=4, stage5_values[8][4]=4;
		if(flagmouse==49) f49=4, stage5_values[9][4]=4;
		if(flagmouse==51) f51=4, stage5_values[1][5]=4;
		if(flagmouse==53) f53=4, stage5_values[3][5]=4;
		if(flagmouse==55) f55=4, stage5_values[5][5]=4;
		if(flagmouse==57) f57=4, stage5_values[7][5]=4;
		if(flagmouse==59) f59=4, stage5_values[9][5]=4;
		if(flagmouse==61) f61=4, stage5_values[1][6]=4;
		if(flagmouse==62) f62=4, stage5_values[2][6]=4;
		if(flagmouse==65) f65=4, stage5_values[5][6]=4;
		if(flagmouse==66) f66=4, stage5_values[6][6]=4;
		if(flagmouse==67) f67=4, stage5_values[7][6]=4;
		if(flagmouse==68) f68=4, stage5_values[8][6]=4;
		if(flagmouse==72) f72=4, stage5_values[2][7]=4;
		if(flagmouse==75) f75=4, stage5_values[5][7]=4;
		if(flagmouse==76) f76=4, stage5_values[6][7]=4;
		if(flagmouse==77) f77=4, stage5_values[7][7]=4;
		if(flagmouse==79) f79=4, stage5_values[9][7]=4;
		if(flagmouse==81) f81=4, stage5_values[1][8]=4;
		if(flagmouse==82) f82=4, stage5_values[2][8]=4;
		if(flagmouse==83) f83=4, stage5_values[3][8]=4;
		if(flagmouse==85) f85=4, stage5_values[5][8]=4;
		if(flagmouse==92) f92=4, stage5_values[2][9]=4;
		if(flagmouse==95) f95=4, stage5_values[5][9]=4;
		if(flagmouse==96) f96=4, stage5_values[6][9]=4;
		if(flagmouse==97) f97=4, stage5_values[7][9]=4;
		if(flagmouse==99) f99=4, stage5_values[9][9]=4;
	}
	if (key == '5')
	{
		if(flagmouse==11) f11=5, stage5_values[1][1]=5;
		if(flagmouse==13) f13=5, stage5_values[3][1]=5;
		if(flagmouse==14) f14=5, stage5_values[4][1]=5;
		if(flagmouse==15) f15=5, stage5_values[5][1]=5;
		if(flagmouse==18) f18=5, stage5_values[8][1]=5;
		if(flagmouse==25) f25=5, stage5_values[5][2]=5;
		if(flagmouse==27) f27=5, stage5_values[7][2]=5;
		if(flagmouse==28) f28=5, stage5_values[8][2]=5;
		if(flagmouse==29) f29=5, stage5_values[9][2]=5;
		if(flagmouse==31) f31=5, stage5_values[1][3]=5;
		if(flagmouse==33) f33=5, stage5_values[3][3]=5;
		if(flagmouse==34) f34=5, stage5_values[4][3]=5;
		if(flagmouse==35) f35=5, stage5_values[5][3]=5;
		if(flagmouse==38) f38=5, stage5_values[8][3]=5;
		if(flagmouse==42) f42=5, stage5_values[2][4]=5;
		if(flagmouse==43) f43=5, stage5_values[3][4]=5;
		if(flagmouse==44) f44=5, stage5_values[4][4]=5;
		if(flagmouse==45) f45=5, stage5_values[5][4]=5;
		if(flagmouse==48) f48=5, stage5_values[8][4]=5;
		if(flagmouse==49) f49=5, stage5_values[9][4]=5;
		if(flagmouse==51) f51=5, stage5_values[1][5]=5;
		if(flagmouse==53) f53=5, stage5_values[3][5]=5;
		if(flagmouse==55) f55=5, stage5_values[5][5]=5;
		if(flagmouse==57) f57=5, stage5_values[7][5]=5;
		if(flagmouse==59) f59=5, stage5_values[9][5]=5;
		if(flagmouse==61) f61=5, stage5_values[1][6]=5;
		if(flagmouse==62) f62=5, stage5_values[2][6]=5;
		if(flagmouse==65) f65=5, stage5_values[5][6]=5;
		if(flagmouse==66) f66=5, stage5_values[6][6]=5;
		if(flagmouse==67) f67=5, stage5_values[7][6]=5;
		if(flagmouse==68) f68=5, stage5_values[8][6]=5;
		if(flagmouse==72) f72=5, stage5_values[2][7]=5;
		if(flagmouse==75) f75=5, stage5_values[5][7]=5;
		if(flagmouse==76) f76=5, stage5_values[6][7]=5;
		if(flagmouse==77) f77=5, stage5_values[7][7]=5;
		if(flagmouse==79) f79=5, stage5_values[9][7]=5;
		if(flagmouse==81) f81=5, stage5_values[1][8]=5;
		if(flagmouse==82) f82=5, stage5_values[2][8]=5;
		if(flagmouse==83) f83=5, stage5_values[3][8]=5;
		if(flagmouse==85) f85=5, stage5_values[5][8]=5;
		if(flagmouse==92) f92=5, stage5_values[2][9]=5;
		if(flagmouse==95) f95=5, stage5_values[5][9]=5;
		if(flagmouse==96) f96=5, stage5_values[6][9]=5;
		if(flagmouse==97) f97=5, stage5_values[7][9]=5;
		if(flagmouse==99) f99=5, stage5_values[9][9]=5;
	}
	if (key == '6')
	{
		if(flagmouse==11) f11=6, stage5_values[1][1]=6;
		if(flagmouse==13) f13=6, stage5_values[3][1]=6;
		if(flagmouse==14) f14=6, stage5_values[4][1]=6;
		if(flagmouse==15) f15=6, stage5_values[5][1]=6;
		if(flagmouse==18) f18=6, stage5_values[8][1]=6;
		if(flagmouse==25) f25=6, stage5_values[5][2]=6;
		if(flagmouse==27) f27=6, stage5_values[7][2]=6;
		if(flagmouse==28) f28=6, stage5_values[8][2]=6;
		if(flagmouse==29) f29=6, stage5_values[9][2]=6;
		if(flagmouse==31) f31=6, stage5_values[1][3]=6;
		if(flagmouse==33) f33=6, stage5_values[3][3]=6;
		if(flagmouse==34) f34=6, stage5_values[4][3]=6;
		if(flagmouse==35) f35=6, stage5_values[5][3]=6;
		if(flagmouse==38) f38=6, stage5_values[8][3]=6;
		if(flagmouse==42) f42=6, stage5_values[2][4]=6;
		if(flagmouse==43) f43=6, stage5_values[3][4]=6;
		if(flagmouse==44) f44=6, stage5_values[4][4]=6;
		if(flagmouse==45) f45=6, stage5_values[5][4]=6;
		if(flagmouse==48) f48=6, stage5_values[8][4]=6;
		if(flagmouse==49) f49=6, stage5_values[9][4]=6;
		if(flagmouse==51) f51=6, stage5_values[1][5]=6;
		if(flagmouse==53) f53=6, stage5_values[3][5]=6;
		if(flagmouse==55) f55=6, stage5_values[5][5]=6;
		if(flagmouse==57) f57=6, stage5_values[7][5]=6;
		if(flagmouse==59) f59=6, stage5_values[9][5]=6;
		if(flagmouse==61) f61=6, stage5_values[1][6]=6;
		if(flagmouse==62) f62=6, stage5_values[2][6]=6;
		if(flagmouse==65) f65=6, stage5_values[5][6]=6;
		if(flagmouse==66) f66=6, stage5_values[6][6]=6;
		if(flagmouse==67) f67=6, stage5_values[7][6]=6;
		if(flagmouse==68) f68=6, stage5_values[8][6]=6;
		if(flagmouse==72) f72=6, stage5_values[2][7]=6;
		if(flagmouse==75) f75=6, stage5_values[5][7]=6;
		if(flagmouse==76) f76=6, stage5_values[6][7]=6;
		if(flagmouse==77) f77=6, stage5_values[7][7]=6;
		if(flagmouse==79) f79=6, stage5_values[9][7]=6;
		if(flagmouse==81) f81=6, stage5_values[1][8]=6;
		if(flagmouse==82) f82=6, stage5_values[2][8]=6;
		if(flagmouse==83) f83=6, stage5_values[3][8]=6;
		if(flagmouse==85) f85=6, stage5_values[5][8]=6;
		if(flagmouse==92) f92=6, stage5_values[2][9]=6;
		if(flagmouse==95) f95=6, stage5_values[5][9]=6;
		if(flagmouse==96) f96=6, stage5_values[6][9]=6;
		if(flagmouse==97) f97=6, stage5_values[7][9]=6;
		if(flagmouse==99) f99=6, stage5_values[9][9]=6;
	}
	if (key == '7')
	{
		if(flagmouse==11) f11=7, stage5_values[1][1]=7;
		if(flagmouse==13) f13=7, stage5_values[3][1]=7;
		if(flagmouse==14) f14=7, stage5_values[4][1]=7;
		if(flagmouse==15) f15=7, stage5_values[5][1]=7;
		if(flagmouse==18) f18=7, stage5_values[8][1]=7;
		if(flagmouse==25) f25=7, stage5_values[5][2]=7;
		if(flagmouse==27) f27=7, stage5_values[7][2]=7;
		if(flagmouse==28) f28=7, stage5_values[8][2]=7;
		if(flagmouse==29) f29=7, stage5_values[9][2]=7;
		if(flagmouse==31) f31=7, stage5_values[1][3]=7;
		if(flagmouse==33) f33=7, stage5_values[3][3]=7;
		if(flagmouse==34) f34=7, stage5_values[4][3]=7;
		if(flagmouse==35) f35=7, stage5_values[5][3]=7;
		if(flagmouse==38) f38=7, stage5_values[8][3]=7;
		if(flagmouse==42) f42=7, stage5_values[2][4]=7;
		if(flagmouse==43) f43=7, stage5_values[3][4]=7;
		if(flagmouse==44) f44=7, stage5_values[4][4]=7;
		if(flagmouse==45) f45=7, stage5_values[5][4]=7;
		if(flagmouse==48) f48=7, stage5_values[8][4]=7;
		if(flagmouse==49) f49=7, stage5_values[9][4]=7;
		if(flagmouse==51) f51=7, stage5_values[1][5]=7;
		if(flagmouse==53) f53=7, stage5_values[3][5]=7;
		if(flagmouse==55) f55=7, stage5_values[5][5]=7;
		if(flagmouse==57) f57=7, stage5_values[7][5]=7;
		if(flagmouse==59) f59=7, stage5_values[9][5]=7;
		if(flagmouse==61) f61=7, stage5_values[1][6]=7;
		if(flagmouse==62) f62=7, stage5_values[2][6]=7;
		if(flagmouse==65) f65=7, stage5_values[5][6]=7;
		if(flagmouse==66) f66=7, stage5_values[6][6]=7;
		if(flagmouse==67) f67=7, stage5_values[7][6]=7;
		if(flagmouse==68) f68=7, stage5_values[8][6]=7;
		if(flagmouse==72) f72=7, stage5_values[2][7]=7;
		if(flagmouse==75) f75=7, stage5_values[5][7]=7;
		if(flagmouse==76) f76=7, stage5_values[6][7]=7;
		if(flagmouse==77) f77=7, stage5_values[7][7]=7;
		if(flagmouse==79) f79=7, stage5_values[9][7]=7;
		if(flagmouse==81) f81=7, stage5_values[1][8]=7;
		if(flagmouse==82) f82=7, stage5_values[2][8]=7;
		if(flagmouse==83) f83=7, stage5_values[3][8]=7;
		if(flagmouse==85) f85=7, stage5_values[5][8]=7;
		if(flagmouse==92) f92=7, stage5_values[2][9]=7;
		if(flagmouse==95) f95=7, stage5_values[5][9]=7;
		if(flagmouse==96) f96=7, stage5_values[6][9]=7;
		if(flagmouse==97) f97=7, stage5_values[7][9]=7;
		if(flagmouse==99) f99=7, stage5_values[9][9]=7;
 	}
	if (key == '8')
	{
		if(flagmouse==11) f11=8, stage5_values[1][1]=8;
		if(flagmouse==13) f13=8, stage5_values[3][1]=8;
		if(flagmouse==14) f14=8, stage5_values[4][1]=8;
		if(flagmouse==15) f15=8, stage5_values[5][1]=8;
		if(flagmouse==18) f18=8, stage5_values[8][1]=8;
		if(flagmouse==25) f25=8, stage5_values[5][2]=8;
		if(flagmouse==27) f27=8, stage5_values[7][2]=8;
		if(flagmouse==28) f28=8, stage5_values[8][2]=8;
		if(flagmouse==29) f29=8, stage5_values[9][2]=8;
		if(flagmouse==31) f31=8, stage5_values[1][3]=8;
		if(flagmouse==33) f33=8, stage5_values[3][3]=8;
		if(flagmouse==34) f34=8, stage5_values[4][3]=8;
		if(flagmouse==35) f35=8, stage5_values[5][3]=8;
		if(flagmouse==38) f38=8, stage5_values[8][3]=8;
		if(flagmouse==42) f42=8, stage5_values[2][4]=8;
		if(flagmouse==43) f43=8, stage5_values[3][4]=8;
		if(flagmouse==44) f44=8, stage5_values[4][4]=8;
		if(flagmouse==45) f45=8, stage5_values[5][4]=8;
		if(flagmouse==48) f48=8, stage5_values[8][4]=8;
		if(flagmouse==49) f49=8, stage5_values[9][4]=8;
		if(flagmouse==51) f51=8, stage5_values[1][5]=8;
		if(flagmouse==53) f53=8, stage5_values[3][5]=8;
		if(flagmouse==55) f55=8, stage5_values[5][5]=8;
		if(flagmouse==57) f57=8, stage5_values[7][5]=8;
		if(flagmouse==59) f59=8, stage5_values[9][5]=8;
		if(flagmouse==61) f61=8, stage5_values[1][6]=8;
		if(flagmouse==62) f62=8, stage5_values[2][6]=8;
		if(flagmouse==65) f65=8, stage5_values[5][6]=8;
		if(flagmouse==66) f66=8, stage5_values[6][6]=8;
		if(flagmouse==67) f67=8, stage5_values[7][6]=8;
		if(flagmouse==68) f68=8, stage5_values[8][6]=8;
		if(flagmouse==72) f72=8, stage5_values[2][7]=8;
		if(flagmouse==75) f75=8, stage5_values[5][7]=8;
		if(flagmouse==76) f76=8, stage5_values[6][7]=8;
		if(flagmouse==77) f77=8, stage5_values[7][7]=8;
		if(flagmouse==79) f79=8, stage5_values[9][7]=8;
		if(flagmouse==81) f81=8, stage5_values[1][8]=8;
		if(flagmouse==82) f82=8, stage5_values[2][8]=8;
		if(flagmouse==83) f83=8, stage5_values[3][8]=8;
		if(flagmouse==85) f85=8, stage5_values[5][8]=8;
		if(flagmouse==92) f92=8, stage5_values[2][9]=8;
		if(flagmouse==95) f95=8, stage5_values[5][9]=8;
		if(flagmouse==96) f96=8, stage5_values[6][9]=8;
		if(flagmouse==97) f97=8, stage5_values[7][9]=8;
		if(flagmouse==99) f99=8, stage5_values[9][9]=8;
	}

	if (key == '9')
	{
		if(flagmouse==11) f11=9, stage5_values[1][1]=9;
		if(flagmouse==13) f13=9, stage5_values[3][1]=9;
		if(flagmouse==14) f14=9, stage5_values[4][1]=9;
		if(flagmouse==15) f15=9, stage5_values[5][1]=9;
		if(flagmouse==18) f18=9, stage5_values[8][1]=9;
		if(flagmouse==25) f25=9, stage5_values[5][2]=9;
		if(flagmouse==27) f27=9, stage5_values[7][2]=9;
		if(flagmouse==28) f28=9, stage5_values[8][2]=9;
		if(flagmouse==29) f29=9, stage5_values[9][2]=9;
		if(flagmouse==31) f31=9, stage5_values[1][3]=9;
		if(flagmouse==33) f33=9, stage5_values[3][3]=9;
		if(flagmouse==34) f34=9, stage5_values[4][3]=9;
		if(flagmouse==35) f35=9, stage5_values[5][3]=9;
		if(flagmouse==38) f38=9, stage5_values[8][3]=9;
		if(flagmouse==42) f42=9, stage5_values[2][4]=9;
		if(flagmouse==43) f43=9, stage5_values[3][4]=9;
		if(flagmouse==44) f44=9, stage5_values[4][4]=9;
		if(flagmouse==45) f45=9, stage5_values[5][4]=9;
		if(flagmouse==48) f48=9, stage5_values[8][4]=9;
		if(flagmouse==49) f49=9, stage5_values[9][4]=9;
		if(flagmouse==51) f51=9, stage5_values[1][5]=9;
		if(flagmouse==53) f53=9, stage5_values[3][5]=9;
		if(flagmouse==55) f55=9, stage5_values[5][5]=9;
		if(flagmouse==57) f57=9, stage5_values[7][5]=9;
		if(flagmouse==59) f59=9, stage5_values[9][5]=9;
		if(flagmouse==61) f61=9, stage5_values[1][6]=9;
		if(flagmouse==62) f62=9, stage5_values[2][6]=9;
		if(flagmouse==65) f65=9, stage5_values[5][6]=9;
		if(flagmouse==66) f66=9, stage5_values[6][6]=9;
		if(flagmouse==67) f67=9, stage5_values[7][6]=9;
		if(flagmouse==68) f68=9, stage5_values[8][6]=9;
		if(flagmouse==72) f72=9, stage5_values[2][7]=9;
		if(flagmouse==75) f75=9, stage5_values[5][7]=9;
		if(flagmouse==76) f76=9, stage5_values[6][7]=9;
		if(flagmouse==77) f77=9, stage5_values[7][7]=9;
		if(flagmouse==79) f79=9, stage5_values[9][7]=9;
		if(flagmouse==81) f81=9, stage5_values[1][8]=9;
		if(flagmouse==82) f82=9, stage5_values[2][8]=9;
		if(flagmouse==83) f83=9, stage5_values[3][8]=9;
		if(flagmouse==85) f85=9, stage5_values[5][8]=9;
		if(flagmouse==92) f92=9, stage5_values[2][9]=9;
		if(flagmouse==95) f95=9, stage5_values[5][9]=9;
		if(flagmouse==96) f96=9, stage5_values[6][9]=9;
		if(flagmouse==97) f97=9, stage5_values[7][9]=9;
		if(flagmouse==99) f99=9, stage5_values[9][9]=9;
	}
	if(key=='e')
	{
		if(flagmouse==11) f11=100, stage5_values[1][1]=0;
		if(flagmouse==12) f12=100, stage5_values[2][1]=0;
		if(flagmouse==13) f13=100, stage5_values[3][1]=0;
		if(flagmouse==14) f14=100, stage5_values[4][1]=0;
		if(flagmouse==15) f15=100, stage5_values[5][1]=0;
		if(flagmouse==16) f16=100, stage5_values[6][1]=0;
		if(flagmouse==17) f17=100, stage5_values[7][1]=0;
		if(flagmouse==18) f18=100, stage5_values[8][1]=0;
		if(flagmouse==19) f19=100, stage5_values[9][1]=0;
		if(flagmouse==21) f21=100, stage5_values[1][2]=0;
		if(flagmouse==22) f22=100, stage5_values[2][2]=0;
		if(flagmouse==23) f23=100, stage5_values[3][2]=0;
		if(flagmouse==24) f24=100, stage5_values[4][2]=0;
		if(flagmouse==25) f25=100, stage5_values[5][2]=0;
		if(flagmouse==26) f26=100, stage5_values[6][2]=0;
		if(flagmouse==27) f27=100, stage5_values[7][2]=0;
		if(flagmouse==28) f28=100, stage5_values[8][2]=0;
		if(flagmouse==29) f29=100, stage5_values[9][2]=0;
		if(flagmouse==31) f31=100, stage5_values[1][3]=0;
		if(flagmouse==32) f32=100, stage5_values[2][3]=0;
		if(flagmouse==33) f33=100, stage5_values[3][3]=0;
		if(flagmouse==34) f34=100, stage5_values[4][3]=0;
		if(flagmouse==35) f35=100, stage5_values[5][3]=0;
		if(flagmouse==36) f36=100, stage5_values[6][3]=0;
		if(flagmouse==37) f37=100, stage5_values[7][3]=0;
		if(flagmouse==38) f38=100, stage5_values[8][3]=0;
		if(flagmouse==39) f39=100, stage5_values[9][3]=0;
		if(flagmouse==41) f41=100, stage5_values[1][4]=0;
		if(flagmouse==42) f42=100, stage5_values[2][4]=0;
		if(flagmouse==43) f43=100, stage5_values[3][4]=0;
		if(flagmouse==44) f44=100, stage5_values[4][4]=0;
		if(flagmouse==45) f45=100, stage5_values[5][4]=0;
		if(flagmouse==46) f46=100, stage5_values[6][4]=0;
		if(flagmouse==47) f47=100, stage5_values[7][4]=0;
		if(flagmouse==48) f48=100, stage5_values[8][4]=0;
		if(flagmouse==49) f49=100, stage5_values[9][4]=0;
		if(flagmouse==51) f51=100, stage5_values[1][5]=0;
		if(flagmouse==52) f52=100, stage5_values[2][5]=0;
		if(flagmouse==53) f53=100, stage5_values[3][5]=0;
		if(flagmouse==54) f54=100, stage5_values[4][5]=0;
		if(flagmouse==55) f55=100, stage5_values[5][5]=0;
		if(flagmouse==56) f56=100, stage5_values[6][5]=0;
		if(flagmouse==57) f57=100, stage5_values[7][5]=0;
		if(flagmouse==58) f58=100, stage5_values[8][5]=0;
		if(flagmouse==59) f59=100, stage5_values[9][5]=0;
		if(flagmouse==61) f61=100, stage5_values[1][6]=0;
		if(flagmouse==62) f62=100, stage5_values[2][6]=0;
		if(flagmouse==63) f63=100, stage5_values[3][6]=0;
		if(flagmouse==64) f64=100, stage5_values[4][6]=0;
		if(flagmouse==65) f65=100, stage5_values[5][6]=0;
		if(flagmouse==66) f66=100, stage5_values[6][6]=0;
		if(flagmouse==67) f67=100, stage5_values[7][6]=0;
		if(flagmouse==68) f68=100, stage5_values[8][6]=0;
		if(flagmouse==69) f69=100, stage5_values[9][6]=0;
		if(flagmouse==71) f71=100, stage5_values[1][7]=0;
		if(flagmouse==72) f72=100, stage5_values[2][7]=0;
		if(flagmouse==73) f73=100, stage5_values[3][7]=0;
		if(flagmouse==74) f74=100, stage5_values[4][7]=0;
		if(flagmouse==75) f75=100, stage5_values[5][7]=0;
		if(flagmouse==76) f76=100, stage5_values[6][7]=0;
		if(flagmouse==77) f77=100, stage5_values[7][7]=0;
		if(flagmouse==78) f78=100, stage5_values[8][7]=0;
		if(flagmouse==79) f79=100, stage5_values[9][7]=0;
		if(flagmouse==81) f81=100, stage5_values[1][8]=0;
		if(flagmouse==82) f82=100, stage5_values[2][8]=0;
		if(flagmouse==83) f83=100, stage5_values[3][8]=0;
		if(flagmouse==84) f84=100, stage5_values[4][8]=0;
		if(flagmouse==85) f85=100, stage5_values[5][8]=0;
		if(flagmouse==86) f86=100, stage5_values[6][8]=0;
		if(flagmouse==87) f87=100, stage5_values[7][8]=0;
		if(flagmouse==88) f88=100, stage5_values[8][8]=0;
		if(flagmouse==89) f89=100, stage5_values[9][8]=0;
		if(flagmouse==91) f91=100, stage5_values[1][9]=0;
		if(flagmouse==92) f92=100, stage5_values[2][9]=0;
		if(flagmouse==93) f93=100, stage5_values[3][9]=0;
		if(flagmouse==94) f94=100, stage5_values[4][9]=0;
		if(flagmouse==95) f95=100, stage5_values[5][9]=0;
		if(flagmouse==96) f96=100, stage5_values[6][9]=0;
		if(flagmouse==97) f97=100, stage5_values[7][9]=0;
		if(flagmouse==98) f98=100, stage5_values[8][9]=0;
		if(flagmouse==99) f99=100, stage5_values[9][9]=0;
	}

	}


	if(page4==1){
		if (key == '1')
	{
		if(flagmouse==13) f13=1, stage1_values[3][1]=1;
		if(flagmouse==17) f17=1, stage1_values[7][1]=1;
		if(flagmouse==18) f18=1, stage1_values[8][1]=1;
		if(flagmouse==19) f19=1, stage1_values[9][1]=1;
		if(flagmouse==22) f22=1, stage1_values[2][2]=1;
		if(flagmouse==24) f24=1, stage1_values[4][2]=1;
		if(flagmouse==25) f25=1, stage1_values[5][2]=1;
		if(flagmouse==26) f26=1, stage1_values[6][2]=1;
		if(flagmouse==28) f28=1, stage1_values[8][2]=1;
		if(flagmouse==29) f29=1, stage1_values[9][2]=1;
		if(flagmouse==31) f31=1, stage1_values[1][3]=1;
		if(flagmouse==32) f32=1, stage1_values[2][3]=1;
		if(flagmouse==34) f34=1, stage1_values[4][3]=1;
		if(flagmouse==35) f35=1, stage1_values[5][3]=1;
		if(flagmouse==36) f36=1, stage1_values[6][3]=1;
		if(flagmouse==37) f37=1, stage1_values[7][3]=1;
		if(flagmouse==38) f38=1, stage1_values[8][3]=1;
		if(flagmouse==39) f39=1, stage1_values[9][3]=1;
		if(flagmouse==41) f41=1, stage1_values[1][4]=1;
		if(flagmouse==43) f43=1, stage1_values[3][4]=1;
		if(flagmouse==44) f44=1, stage1_values[4][4]=1;
		if(flagmouse==46) f46=1, stage1_values[6][4]=1;
		if(flagmouse==47) f47=1, stage1_values[7][4]=1;
		if(flagmouse==49) f49=1, stage1_values[9][4]=1;
		if(flagmouse==53) f53=1, stage1_values[3][5]=1;
		if(flagmouse==55) f55=1, stage1_values[5][5]=1;
		if(flagmouse==57) f57=1, stage1_values[7][5]=1;
		if(flagmouse==61) f61=1, stage1_values[1][6]=1;
		if(flagmouse==63) f63=1, stage1_values[3][6]=1;
		if(flagmouse==64) f64=1, stage1_values[4][6]=1;
		if(flagmouse==66) f66=1, stage1_values[6][6]=1;
		if(flagmouse==67) f67=1, stage1_values[7][6]=1;
		if(flagmouse==69) f69=1, stage1_values[9][6]=1;
		if(flagmouse==71) f71=1, stage1_values[1][7]=1;
		if(flagmouse==72) f72=1, stage1_values[2][7]=1;
		if(flagmouse==73) f73=1, stage1_values[3][7]=1;
		if(flagmouse==74) f74=1, stage1_values[4][7]=1;
		if(flagmouse==75) f75=1, stage1_values[5][7]=1;
		if(flagmouse==76) f76=1, stage1_values[6][7]=1;
		if(flagmouse==78) f78=1, stage1_values[8][7]=1;
		if(flagmouse==79) f79=1, stage1_values[9][7]=1;
		if(flagmouse==81) f81=1, stage1_values[1][8]=1;
		if(flagmouse==82) f82=1, stage1_values[2][8]=1;
		if(flagmouse==84) f84=1, stage1_values[4][8]=1;
		if(flagmouse==85) f85=1, stage1_values[5][8]=1;
		if(flagmouse==86) f86=1, stage1_values[6][8]=1;
		if(flagmouse==88) f88=1, stage1_values[8][8]=1;
		if(flagmouse==91) f91=1, stage1_values[1][9]=1;
		if(flagmouse==92) f92=1, stage1_values[2][9]=1;
		if(flagmouse==93) f93=1, stage1_values[3][9]=1;
		if(flagmouse==97) f97=1, stage1_values[7][9]=1;
	}

	
	if (key == '2')
	{
		if(flagmouse==13) f13=2, stage1_values[3][1]=2;
		if(flagmouse==17) f17=2, stage1_values[7][1]=2;
		if(flagmouse==18) f18=2, stage1_values[8][1]=2;
		if(flagmouse==19) f19=2, stage1_values[9][1]=2;
		if(flagmouse==22) f22=2, stage1_values[2][2]=2;
		if(flagmouse==24) f24=2, stage1_values[4][2]=2;
		if(flagmouse==25) f25=2, stage1_values[5][2]=2;
		if(flagmouse==26) f26=2, stage1_values[6][2]=2;
		if(flagmouse==28) f28=2, stage1_values[8][2]=2;
		if(flagmouse==29) f29=2, stage1_values[9][2]=2;
		if(flagmouse==31) f31=2, stage1_values[1][3]=2;
		if(flagmouse==32) f32=2, stage1_values[2][3]=2;
		if(flagmouse==34) f34=2, stage1_values[4][3]=2;
		if(flagmouse==35) f35=2, stage1_values[5][3]=2;
		if(flagmouse==36) f36=2, stage1_values[6][3]=2;
		if(flagmouse==37) f37=2, stage1_values[7][3]=2;
		if(flagmouse==38) f38=2, stage1_values[8][3]=2;
		if(flagmouse==39) f39=2, stage1_values[9][3]=2;
		if(flagmouse==41) f41=2, stage1_values[1][4]=2;
		if(flagmouse==43) f43=2, stage1_values[3][4]=2;
		if(flagmouse==44) f44=2, stage1_values[4][4]=2;
		if(flagmouse==46) f46=2, stage1_values[6][4]=2;
		if(flagmouse==47) f47=2, stage1_values[7][4]=2;
		if(flagmouse==49) f49=2, stage1_values[9][4]=2;
		if(flagmouse==53) f53=2, stage1_values[3][5]=2;
		if(flagmouse==55) f55=2, stage1_values[5][5]=2;
		if(flagmouse==57) f57=2, stage1_values[7][5]=2;
		if(flagmouse==61) f61=2, stage1_values[1][6]=2;
		if(flagmouse==63) f63=2, stage1_values[3][6]=2;
		if(flagmouse==64) f64=2, stage1_values[4][6]=2;
		if(flagmouse==66) f66=2, stage1_values[6][6]=2;
		if(flagmouse==67) f67=2, stage1_values[7][6]=2;
		if(flagmouse==69) f69=2, stage1_values[9][6]=2;
		if(flagmouse==71) f71=2, stage1_values[1][7]=2;
		if(flagmouse==72) f72=2, stage1_values[2][7]=2;
		if(flagmouse==73) f73=2, stage1_values[3][7]=2;
		if(flagmouse==74) f74=2, stage1_values[4][7]=2;
		if(flagmouse==75) f75=2, stage1_values[5][7]=2;
		if(flagmouse==76) f76=2, stage1_values[6][7]=2;
		if(flagmouse==78) f78=2, stage1_values[8][7]=2;
		if(flagmouse==79) f79=2, stage1_values[9][7]=2;
		if(flagmouse==81) f81=2, stage1_values[1][8]=2;
		if(flagmouse==82) f82=2, stage1_values[2][8]=2;
		if(flagmouse==84) f84=2, stage1_values[4][8]=2;
		if(flagmouse==85) f85=2, stage1_values[5][8]=2;
		if(flagmouse==86) f86=2, stage1_values[6][8]=2;
		if(flagmouse==88) f88=2, stage1_values[8][8]=2;
		if(flagmouse==91) f91=2, stage1_values[1][9]=2;
		if(flagmouse==92) f92=2, stage1_values[2][9]=2;
		if(flagmouse==93) f93=2, stage1_values[3][9]=2;
		if(flagmouse==97) f97=2, stage1_values[7][9]=2;
	}

	if (key == '3')
	{
		if(flagmouse==13) f13=3, stage1_values[3][1]=3;
		if(flagmouse==17) f17=3, stage1_values[7][1]=3;
		if(flagmouse==18) f18=3, stage1_values[8][1]=3;
		if(flagmouse==19) f19=3, stage1_values[9][1]=3;
		if(flagmouse==22) f22=3, stage1_values[2][2]=3;
		if(flagmouse==24) f24=3, stage1_values[4][2]=3;
		if(flagmouse==25) f25=3, stage1_values[5][2]=3;
		if(flagmouse==26) f26=3, stage1_values[6][2]=3;
		if(flagmouse==28) f28=3, stage1_values[8][2]=3;
		if(flagmouse==29) f29=3, stage1_values[9][2]=3;
		if(flagmouse==31) f31=3, stage1_values[1][3]=3;
		if(flagmouse==32) f32=3, stage1_values[2][3]=3;
		if(flagmouse==34) f34=3, stage1_values[4][3]=3;
		if(flagmouse==35) f35=3, stage1_values[5][3]=3;
		if(flagmouse==36) f36=3, stage1_values[6][3]=3;
		if(flagmouse==37) f37=3, stage1_values[7][3]=3;
		if(flagmouse==38) f38=3, stage1_values[8][3]=3;
		if(flagmouse==39) f39=3, stage1_values[9][3]=3;
		if(flagmouse==41) f41=3, stage1_values[1][4]=3;
		if(flagmouse==43) f43=3, stage1_values[3][4]=3;
		if(flagmouse==44) f44=3, stage1_values[4][4]=3;
		if(flagmouse==46) f46=3, stage1_values[6][4]=3;
		if(flagmouse==47) f47=3, stage1_values[7][4]=3;
		if(flagmouse==49) f49=3, stage1_values[9][4]=3;
		if(flagmouse==53) f53=3, stage1_values[3][5]=3;
		if(flagmouse==55) f55=3, stage1_values[5][5]=3;
		if(flagmouse==57) f57=3, stage1_values[7][5]=3;
		if(flagmouse==61) f61=3, stage1_values[1][6]=3;
		if(flagmouse==63) f63=3, stage1_values[3][6]=3;
		if(flagmouse==64) f64=3, stage1_values[4][6]=3;
		if(flagmouse==66) f66=3, stage1_values[6][6]=3;
		if(flagmouse==67) f67=3, stage1_values[7][6]=3;
		if(flagmouse==69) f69=3, stage1_values[9][6]=3;
		if(flagmouse==71) f71=3, stage1_values[1][7]=3;
		if(flagmouse==72) f72=3, stage1_values[2][7]=3;
		if(flagmouse==73) f73=3, stage1_values[3][7]=3;
		if(flagmouse==74) f74=3, stage1_values[4][7]=3;
		if(flagmouse==75) f75=3, stage1_values[5][7]=3;
		if(flagmouse==76) f76=3, stage1_values[6][7]=3;
		if(flagmouse==78) f78=3, stage1_values[8][7]=3;
		if(flagmouse==79) f79=3, stage1_values[9][7]=3;
		if(flagmouse==81) f81=3, stage1_values[1][8]=3;
		if(flagmouse==82) f82=3, stage1_values[2][8]=3;
		if(flagmouse==84) f84=3, stage1_values[4][8]=3;
		if(flagmouse==85) f85=3, stage1_values[5][8]=3;
		if(flagmouse==86) f86=3, stage1_values[6][8]=3;
		if(flagmouse==88) f88=3, stage1_values[8][8]=3;
		if(flagmouse==91) f91=3, stage1_values[1][9]=3;
		if(flagmouse==92) f92=3, stage1_values[2][9]=3;
		if(flagmouse==93) f93=3, stage1_values[3][9]=3;
		if(flagmouse==97) f97=3, stage1_values[7][9]=3;
	}

	if (key == '4')
	{
		if(flagmouse==13) f13=4, stage1_values[3][1]=4;
		if(flagmouse==17) f17=4, stage1_values[7][1]=4;
		if(flagmouse==18) f18=4, stage1_values[8][1]=4;
		if(flagmouse==19) f19=4, stage1_values[9][1]=4;
		if(flagmouse==22) f22=4, stage1_values[2][2]=4;
		if(flagmouse==24) f24=4, stage1_values[4][2]=4;
		if(flagmouse==25) f25=4, stage1_values[5][2]=4;
		if(flagmouse==26) f26=4, stage1_values[6][2]=4;
		if(flagmouse==28) f28=4, stage1_values[8][2]=4;
		if(flagmouse==29) f29=4, stage1_values[9][2]=4;
		if(flagmouse==31) f31=4, stage1_values[1][3]=4;
		if(flagmouse==32) f32=4, stage1_values[2][3]=4;
		if(flagmouse==34) f34=4, stage1_values[4][3]=4;
		if(flagmouse==35) f35=4, stage1_values[5][3]=4;
		if(flagmouse==36) f36=4, stage1_values[6][3]=4;
		if(flagmouse==37) f37=4, stage1_values[7][3]=4;
		if(flagmouse==38) f38=4, stage1_values[8][3]=4;
		if(flagmouse==39) f39=4, stage1_values[9][3]=4;
		if(flagmouse==41) f41=4, stage1_values[1][4]=4;
		if(flagmouse==43) f43=4, stage1_values[3][4]=4;
		if(flagmouse==44) f44=4, stage1_values[4][4]=4;
		if(flagmouse==46) f46=4, stage1_values[6][4]=4;
		if(flagmouse==47) f47=4, stage1_values[7][4]=4;
		if(flagmouse==49) f49=4, stage1_values[9][4]=4;
		if(flagmouse==53) f53=4, stage1_values[3][5]=4;
		if(flagmouse==55) f55=4, stage1_values[5][5]=4;
		if(flagmouse==57) f57=4, stage1_values[7][5]=4;
		if(flagmouse==61) f61=4, stage1_values[1][6]=4;
		if(flagmouse==63) f63=4, stage1_values[3][6]=4;
		if(flagmouse==64) f64=4, stage1_values[4][6]=4;
		if(flagmouse==66) f66=4, stage1_values[6][6]=4;
		if(flagmouse==67) f67=4, stage1_values[7][6]=4;
		if(flagmouse==69) f69=4, stage1_values[9][6]=4;
		if(flagmouse==71) f71=4, stage1_values[1][7]=4;
		if(flagmouse==72) f72=4, stage1_values[2][7]=4;
		if(flagmouse==73) f73=4, stage1_values[3][7]=4;
		if(flagmouse==74) f74=4, stage1_values[4][7]=4;
		if(flagmouse==75) f75=4, stage1_values[5][7]=4;
		if(flagmouse==76) f76=4, stage1_values[6][7]=4;
		if(flagmouse==78) f78=4, stage1_values[8][7]=4;
		if(flagmouse==79) f79=4, stage1_values[9][7]=4;
		if(flagmouse==81) f81=4, stage1_values[1][8]=4;
		if(flagmouse==82) f82=4, stage1_values[2][8]=4;
		if(flagmouse==84) f84=4, stage1_values[4][8]=4;
		if(flagmouse==85) f85=4, stage1_values[5][8]=4;
		if(flagmouse==86) f86=4, stage1_values[6][8]=4;
		if(flagmouse==88) f88=4, stage1_values[8][8]=4;
		if(flagmouse==91) f91=4, stage1_values[1][9]=4;
		if(flagmouse==92) f92=4, stage1_values[2][9]=4;
		if(flagmouse==93) f93=4, stage1_values[3][9]=4;
		if(flagmouse==97) f97=4, stage1_values[7][9]=4;
	}
	if (key == '5')
	{
		if(flagmouse==13) f13=5, stage1_values[3][1]=5;
		if(flagmouse==17) f17=5, stage1_values[7][1]=5;
		if(flagmouse==18) f18=5, stage1_values[8][1]=5;
		if(flagmouse==19) f19=5, stage1_values[9][1]=5;
		if(flagmouse==22) f22=5, stage1_values[2][2]=5;
		if(flagmouse==24) f24=5, stage1_values[4][2]=5;
		if(flagmouse==25) f25=5, stage1_values[5][2]=5;
		if(flagmouse==26) f26=5, stage1_values[6][2]=5;
		if(flagmouse==28) f28=5, stage1_values[8][2]=5;
		if(flagmouse==29) f29=5, stage1_values[9][2]=5;
		if(flagmouse==31) f31=5, stage1_values[1][3]=5;
		if(flagmouse==32) f32=5, stage1_values[2][3]=5;
		if(flagmouse==34) f34=5, stage1_values[4][3]=5;
		if(flagmouse==35) f35=5, stage1_values[5][3]=5;
		if(flagmouse==36) f36=5, stage1_values[6][3]=5;
		if(flagmouse==37) f37=5, stage1_values[7][3]=5;
		if(flagmouse==38) f38=5, stage1_values[8][3]=5;
		if(flagmouse==39) f39=5, stage1_values[9][3]=5;
		if(flagmouse==41) f41=5, stage1_values[1][4]=5;
		if(flagmouse==43) f43=5, stage1_values[3][4]=5;
		if(flagmouse==44) f44=5, stage1_values[4][4]=5;
		if(flagmouse==46) f46=5, stage1_values[6][4]=5;
		if(flagmouse==47) f47=5, stage1_values[7][4]=5;
		if(flagmouse==49) f49=5, stage1_values[9][4]=5;
		if(flagmouse==53) f53=5, stage1_values[3][5]=5;
		if(flagmouse==55) f55=5, stage1_values[5][5]=5;
		if(flagmouse==57) f57=5, stage1_values[7][5]=5;
		if(flagmouse==61) f61=5, stage1_values[1][6]=5;
		if(flagmouse==63) f63=5, stage1_values[3][6]=5;
		if(flagmouse==64) f64=5, stage1_values[4][6]=5;
		if(flagmouse==66) f66=5, stage1_values[6][6]=5;
		if(flagmouse==67) f67=5, stage1_values[7][6]=5;
		if(flagmouse==69) f69=5, stage1_values[9][6]=5;
		if(flagmouse==71) f71=5, stage1_values[1][7]=5;
		if(flagmouse==72) f72=5, stage1_values[2][7]=5;
		if(flagmouse==73) f73=5, stage1_values[3][7]=5;
		if(flagmouse==74) f74=5, stage1_values[4][7]=5;
		if(flagmouse==75) f75=5, stage1_values[5][7]=5;
		if(flagmouse==76) f76=5, stage1_values[6][7]=5;
		if(flagmouse==78) f78=5, stage1_values[8][7]=5;
		if(flagmouse==79) f79=5, stage1_values[9][7]=5;
		if(flagmouse==81) f81=5, stage1_values[1][8]=5;
		if(flagmouse==82) f82=5, stage1_values[2][8]=5;
		if(flagmouse==84) f84=5, stage1_values[4][8]=5;
		if(flagmouse==85) f85=5, stage1_values[5][8]=5;
		if(flagmouse==86) f86=5, stage1_values[6][8]=5;
		if(flagmouse==88) f88=5, stage1_values[8][8]=5;
		if(flagmouse==91) f91=5, stage1_values[1][9]=5;
		if(flagmouse==92) f92=5, stage1_values[2][9]=5;
		if(flagmouse==93) f93=5, stage1_values[3][9]=5;
		if(flagmouse==97) f97=5, stage1_values[7][9]=5;
	}
	if (key == '6')
	{
		if(flagmouse==13) f13=6, stage1_values[3][1]=6;
		if(flagmouse==17) f17=6, stage1_values[7][1]=6;
		if(flagmouse==18) f18=6, stage1_values[8][1]=6;
		if(flagmouse==19) f19=6, stage1_values[9][1]=6;
		if(flagmouse==22) f22=6, stage1_values[2][2]=6;
		if(flagmouse==24) f24=6, stage1_values[4][2]=6;
		if(flagmouse==25) f25=6, stage1_values[5][2]=6;
		if(flagmouse==26) f26=6, stage1_values[6][2]=6;
		if(flagmouse==28) f28=6, stage1_values[8][2]=6;
		if(flagmouse==29) f29=6, stage1_values[9][2]=6;
		if(flagmouse==31) f31=6, stage1_values[1][3]=6;
		if(flagmouse==32) f32=6, stage1_values[2][3]=6;
		if(flagmouse==34) f34=6, stage1_values[4][3]=6;
		if(flagmouse==35) f35=6, stage1_values[5][3]=6;
		if(flagmouse==36) f36=6, stage1_values[6][3]=6;
		if(flagmouse==37) f37=6, stage1_values[7][3]=6;
		if(flagmouse==38) f38=6, stage1_values[8][3]=6;
		if(flagmouse==39) f39=6, stage1_values[9][3]=6;
		if(flagmouse==41) f41=6, stage1_values[1][4]=6;
		if(flagmouse==43) f43=6, stage1_values[3][4]=6;
		if(flagmouse==44) f44=6, stage1_values[4][4]=6;
		if(flagmouse==46) f46=6, stage1_values[6][4]=6;
		if(flagmouse==47) f47=6, stage1_values[7][4]=6;
		if(flagmouse==49) f49=6, stage1_values[9][4]=6;
		if(flagmouse==53) f53=6, stage1_values[3][5]=6;
		if(flagmouse==55) f55=6, stage1_values[5][5]=6;
		if(flagmouse==57) f57=6, stage1_values[7][5]=6;
		if(flagmouse==61) f61=6, stage1_values[1][6]=6;
		if(flagmouse==63) f63=6, stage1_values[3][6]=6;
		if(flagmouse==64) f64=6, stage1_values[4][6]=6;
		if(flagmouse==66) f66=6, stage1_values[6][6]=6;
		if(flagmouse==67) f67=6, stage1_values[7][6]=6;
		if(flagmouse==69) f69=6, stage1_values[9][6]=6;
		if(flagmouse==71) f71=6, stage1_values[1][7]=6;
		if(flagmouse==72) f72=6, stage1_values[2][7]=6;
		if(flagmouse==73) f73=6, stage1_values[3][7]=6;
		if(flagmouse==74) f74=6, stage1_values[4][7]=6;
		if(flagmouse==75) f75=6, stage1_values[5][7]=6;
		if(flagmouse==76) f76=6, stage1_values[6][7]=6;
		if(flagmouse==78) f78=6, stage1_values[8][7]=6;
		if(flagmouse==79) f79=6, stage1_values[9][7]=6;
		if(flagmouse==81) f81=6, stage1_values[1][8]=6;
		if(flagmouse==82) f82=6, stage1_values[2][8]=6;
		if(flagmouse==84) f84=6, stage1_values[4][8]=6;
		if(flagmouse==85) f85=6, stage1_values[5][8]=6;
		if(flagmouse==86) f86=6, stage1_values[6][8]=6;
		if(flagmouse==88) f88=6, stage1_values[8][8]=6;
		if(flagmouse==91) f91=6, stage1_values[1][9]=6;
		if(flagmouse==92) f92=6, stage1_values[2][9]=6;
		if(flagmouse==93) f93=6, stage1_values[3][9]=6;
		if(flagmouse==97) f97=6, stage1_values[7][9]=6;
	}
	if (key == '7')
	{
		if(flagmouse==13) f13=7, stage1_values[3][1]=7;
		if(flagmouse==17) f17=7, stage1_values[7][1]=7;
		if(flagmouse==18) f18=7, stage1_values[8][1]=7;
		if(flagmouse==19) f19=7, stage1_values[9][1]=7;
		if(flagmouse==22) f22=7, stage1_values[2][2]=7;
		if(flagmouse==24) f24=7, stage1_values[4][2]=7;
		if(flagmouse==25) f25=7, stage1_values[5][2]=7;
		if(flagmouse==26) f26=7, stage1_values[6][2]=7;
		if(flagmouse==28) f28=7, stage1_values[8][2]=7;
		if(flagmouse==29) f29=7, stage1_values[9][2]=7;
		if(flagmouse==31) f31=7, stage1_values[1][3]=7;
		if(flagmouse==32) f32=7, stage1_values[2][3]=7;
		if(flagmouse==34) f34=7, stage1_values[4][3]=7;
		if(flagmouse==35) f35=7, stage1_values[5][3]=7;
		if(flagmouse==36) f36=7, stage1_values[6][3]=7;
		if(flagmouse==37) f37=7, stage1_values[7][3]=7;
		if(flagmouse==38) f38=7, stage1_values[8][3]=7;
		if(flagmouse==39) f39=7, stage1_values[9][3]=7;
		if(flagmouse==41) f41=7, stage1_values[1][4]=7;
		if(flagmouse==43) f43=7, stage1_values[3][4]=7;
		if(flagmouse==44) f44=7, stage1_values[4][4]=7;
		if(flagmouse==46) f46=7, stage1_values[6][4]=7;
		if(flagmouse==47) f47=7, stage1_values[7][4]=7;
		if(flagmouse==49) f49=7, stage1_values[9][4]=7;
		if(flagmouse==53) f53=7, stage1_values[3][5]=7;
		if(flagmouse==55) f55=7, stage1_values[5][5]=7;
		if(flagmouse==57) f57=7, stage1_values[7][5]=7;
		if(flagmouse==61) f61=7, stage1_values[1][6]=7;
		if(flagmouse==63) f63=7, stage1_values[3][6]=7;
		if(flagmouse==64) f64=7, stage1_values[4][6]=7;
		if(flagmouse==66) f66=7, stage1_values[6][6]=7;
		if(flagmouse==67) f67=7, stage1_values[7][6]=7;
		if(flagmouse==69) f69=7, stage1_values[9][6]=7;
		if(flagmouse==71) f71=7, stage1_values[1][7]=7;
		if(flagmouse==72) f72=7, stage1_values[2][7]=7;
		if(flagmouse==73) f73=7, stage1_values[3][7]=7;
		if(flagmouse==74) f74=7, stage1_values[4][7]=7;
		if(flagmouse==75) f75=7, stage1_values[5][7]=7;
		if(flagmouse==76) f76=7, stage1_values[6][7]=7;
		if(flagmouse==78) f78=7, stage1_values[8][7]=7;
		if(flagmouse==79) f79=7, stage1_values[9][7]=7;
		if(flagmouse==81) f81=7, stage1_values[1][8]=7;
		if(flagmouse==82) f82=7, stage1_values[2][8]=7;
		if(flagmouse==84) f84=7, stage1_values[4][8]=7;
		if(flagmouse==85) f85=7, stage1_values[5][8]=7;
		if(flagmouse==86) f86=7, stage1_values[6][8]=7;
		if(flagmouse==88) f88=7, stage1_values[8][8]=7;
		if(flagmouse==91) f91=7, stage1_values[1][9]=7;
		if(flagmouse==92) f92=7, stage1_values[2][9]=7;
		if(flagmouse==93) f93=7, stage1_values[3][9]=7;
		if(flagmouse==97) f97=7, stage1_values[7][9]=7;
	}
	if (key == '8')
	{
		if(flagmouse==13) f13=8, stage1_values[3][1]=8;
		if(flagmouse==17) f17=8, stage1_values[7][1]=8;
		if(flagmouse==18) f18=8, stage1_values[8][1]=8;
		if(flagmouse==19) f19=8, stage1_values[9][1]=8;
		if(flagmouse==22) f22=8, stage1_values[2][2]=8;
		if(flagmouse==24) f24=8, stage1_values[4][2]=8;
		if(flagmouse==25) f25=8, stage1_values[5][2]=8;
		if(flagmouse==26) f26=8, stage1_values[6][2]=8;
		if(flagmouse==28) f28=8, stage1_values[8][2]=8;
		if(flagmouse==29) f29=8, stage1_values[9][2]=8;
		if(flagmouse==31) f31=8, stage1_values[1][3]=8;
		if(flagmouse==32) f32=8, stage1_values[2][3]=8;
		if(flagmouse==34) f34=8, stage1_values[4][3]=8;
		if(flagmouse==35) f35=8, stage1_values[5][3]=8;
		if(flagmouse==36) f36=8, stage1_values[6][3]=8;
		if(flagmouse==37) f37=8, stage1_values[7][3]=8;
		if(flagmouse==38) f38=8, stage1_values[8][3]=8;
		if(flagmouse==39) f39=8, stage1_values[9][3]=8;
		if(flagmouse==41) f41=8, stage1_values[1][4]=8;
		if(flagmouse==43) f43=8, stage1_values[3][4]=8;
		if(flagmouse==44) f44=8, stage1_values[4][4]=8;
		if(flagmouse==46) f46=8, stage1_values[6][4]=8;
		if(flagmouse==47) f47=8, stage1_values[7][4]=8;
		if(flagmouse==49) f49=8, stage1_values[9][4]=8;
		if(flagmouse==53) f53=8, stage1_values[3][5]=8;
		if(flagmouse==55) f55=8, stage1_values[5][5]=8;
		if(flagmouse==57) f57=8, stage1_values[7][5]=8;
		if(flagmouse==61) f61=8, stage1_values[1][6]=8;
		if(flagmouse==63) f63=8, stage1_values[3][6]=8;
		if(flagmouse==64) f64=8, stage1_values[4][6]=8;
		if(flagmouse==66) f66=8, stage1_values[6][6]=8;
		if(flagmouse==67) f67=8, stage1_values[7][6]=8;
		if(flagmouse==69) f69=8, stage1_values[9][6]=8;
		if(flagmouse==71) f71=8, stage1_values[1][7]=8;
		if(flagmouse==72) f72=8, stage1_values[2][7]=8;
		if(flagmouse==73) f73=8, stage1_values[3][7]=8;
		if(flagmouse==74) f74=8, stage1_values[4][7]=8;
		if(flagmouse==75) f75=8, stage1_values[5][7]=8;
		if(flagmouse==76) f76=8, stage1_values[6][7]=8;
		if(flagmouse==78) f78=8, stage1_values[8][7]=8;
		if(flagmouse==79) f79=8, stage1_values[9][7]=8;
		if(flagmouse==81) f81=8, stage1_values[1][8]=8;
		if(flagmouse==82) f82=8, stage1_values[2][8]=8;
		if(flagmouse==84) f84=8, stage1_values[4][8]=8;
		if(flagmouse==85) f85=8, stage1_values[5][8]=8;
		if(flagmouse==86) f86=8, stage1_values[6][8]=8;
		if(flagmouse==88) f88=8, stage1_values[8][8]=8;
		if(flagmouse==91) f91=8, stage1_values[1][9]=8;
		if(flagmouse==92) f92=8, stage1_values[2][9]=8;
		if(flagmouse==93) f93=8, stage1_values[3][9]=8;
		if(flagmouse==97) f97=8, stage1_values[7][9]=8;
	}

	if (key == '9')
	{
		if(flagmouse==13) f13=9, stage1_values[3][1]=9;
		if(flagmouse==17) f17=9, stage1_values[7][1]=9;
		if(flagmouse==18) f18=9, stage1_values[8][1]=9;
		if(flagmouse==19) f19=9, stage1_values[9][1]=9;
		if(flagmouse==22) f22=9, stage1_values[2][2]=9;
		if(flagmouse==24) f24=9, stage1_values[4][2]=9;
		if(flagmouse==25) f25=9, stage1_values[5][2]=9;
		if(flagmouse==26) f26=9, stage1_values[6][2]=9;
		if(flagmouse==28) f28=9, stage1_values[8][2]=9;
		if(flagmouse==29) f29=9, stage1_values[9][2]=9;
		if(flagmouse==31) f31=9, stage1_values[1][3]=9;
		if(flagmouse==32) f32=9, stage1_values[2][3]=9;
		if(flagmouse==34) f34=9, stage1_values[4][3]=9;
		if(flagmouse==35) f35=9, stage1_values[5][3]=9;
		if(flagmouse==36) f36=9, stage1_values[6][3]=9;
		if(flagmouse==37) f37=9, stage1_values[7][3]=9;
		if(flagmouse==38) f38=9, stage1_values[8][3]=9;
		if(flagmouse==39) f39=9, stage1_values[9][3]=9;
		if(flagmouse==41) f41=9, stage1_values[1][4]=9;
		if(flagmouse==43) f43=9, stage1_values[3][4]=9;
		if(flagmouse==44) f44=9, stage1_values[4][4]=9;
		if(flagmouse==46) f46=9, stage1_values[6][4]=9;
		if(flagmouse==47) f47=9, stage1_values[7][4]=9;
		if(flagmouse==49) f49=9, stage1_values[9][4]=9;
		if(flagmouse==53) f53=9, stage1_values[3][5]=9;
		if(flagmouse==55) f55=9, stage1_values[5][5]=9;
		if(flagmouse==57) f57=9, stage1_values[7][5]=9;
		if(flagmouse==61) f61=9, stage1_values[1][6]=9;
		if(flagmouse==63) f63=9, stage1_values[3][6]=9;
		if(flagmouse==64) f64=9, stage1_values[4][6]=9;
		if(flagmouse==66) f66=9, stage1_values[6][6]=9;
		if(flagmouse==67) f67=9, stage1_values[7][6]=9;
		if(flagmouse==69) f69=9, stage1_values[9][6]=9;
		if(flagmouse==71) f71=9, stage1_values[1][7]=9;
		if(flagmouse==72) f72=9, stage1_values[2][7]=9;
		if(flagmouse==73) f73=9, stage1_values[3][7]=9;
		if(flagmouse==74) f74=9, stage1_values[4][7]=9;
		if(flagmouse==75) f75=9, stage1_values[5][7]=9;
		if(flagmouse==76) f76=9, stage1_values[6][7]=9;
		if(flagmouse==78) f78=9, stage1_values[8][7]=9;
		if(flagmouse==79) f79=9, stage1_values[9][7]=9;
		if(flagmouse==81) f81=9, stage1_values[1][8]=9;
		if(flagmouse==82) f82=9, stage1_values[2][8]=9;
		if(flagmouse==84) f84=9, stage1_values[4][8]=9;
		if(flagmouse==85) f85=9, stage1_values[5][8]=9;
		if(flagmouse==86) f86=9, stage1_values[6][8]=9;
		if(flagmouse==88) f88=9, stage1_values[8][8]=9;
		if(flagmouse==91) f91=9, stage1_values[1][9]=9;
		if(flagmouse==92) f92=9, stage1_values[2][9]=9;
		if(flagmouse==93) f93=9, stage1_values[3][9]=9;
		if(flagmouse==97) f97=9, stage1_values[7][9]=9;
	}
	if(key=='e')
	{
		if(flagmouse==11) f11=100, stage1_values[1][1]=0;
		if(flagmouse==12) f12=100, stage1_values[2][1]=0;
		if(flagmouse==13) f13=100, stage1_values[3][1]=0;
		if(flagmouse==14) f14=100, stage1_values[4][1]=0;
		if(flagmouse==15) f15=100, stage1_values[5][1]=0;
		if(flagmouse==16) f16=100, stage1_values[6][1]=0;
		if(flagmouse==17) f17=100, stage1_values[7][1]=0;
		if(flagmouse==18) f18=100, stage1_values[8][1]=0;
		if(flagmouse==19) f19=100, stage1_values[9][1]=0;
		if(flagmouse==21) f21=100, stage1_values[1][2]=0;
		if(flagmouse==22) f22=100, stage1_values[2][2]=0;
		if(flagmouse==23) f23=100, stage1_values[3][2]=0;
		if(flagmouse==24) f24=100, stage1_values[4][2]=0;
		if(flagmouse==25) f25=100, stage1_values[5][2]=0;
		if(flagmouse==26) f26=100, stage1_values[6][2]=0;
		if(flagmouse==27) f27=100, stage1_values[7][2]=0;
		if(flagmouse==28) f28=100, stage1_values[8][2]=0;
		if(flagmouse==29) f29=100, stage1_values[9][2]=0;
		if(flagmouse==31) f31=100, stage1_values[1][3]=0;
		if(flagmouse==32) f32=100, stage1_values[2][3]=0;
		if(flagmouse==33) f33=100, stage1_values[3][3]=0;
		if(flagmouse==34) f34=100, stage1_values[4][3]=0;
		if(flagmouse==35) f35=100, stage1_values[5][3]=0;
		if(flagmouse==36) f36=100, stage1_values[6][3]=0;
		if(flagmouse==37) f37=100, stage1_values[7][3]=0;
		if(flagmouse==38) f38=100, stage1_values[8][3]=0;
		if(flagmouse==39) f39=100, stage1_values[9][3]=0;
		if(flagmouse==41) f41=100, stage1_values[1][4]=0;
		if(flagmouse==42) f42=100, stage1_values[2][4]=0;
		if(flagmouse==43) f43=100, stage1_values[3][4]=0;
		if(flagmouse==44) f44=100, stage1_values[4][4]=0;
		if(flagmouse==45) f45=100, stage1_values[5][4]=0;
		if(flagmouse==46) f46=100, stage1_values[6][4]=0;
		if(flagmouse==47) f47=100, stage1_values[7][4]=0;
		if(flagmouse==48) f48=100, stage1_values[8][4]=0;
		if(flagmouse==49) f49=100, stage1_values[9][4]=0;
		if(flagmouse==51) f51=100, stage1_values[1][5]=0;
		if(flagmouse==52) f52=100, stage1_values[2][5]=0;
		if(flagmouse==53) f53=100, stage1_values[3][5]=0;
		if(flagmouse==54) f54=100, stage1_values[4][5]=0;
		if(flagmouse==55) f55=100, stage1_values[5][5]=0;
		if(flagmouse==56) f56=100, stage1_values[6][5]=0;
		if(flagmouse==57) f57=100, stage1_values[7][5]=0;
		if(flagmouse==58) f58=100, stage1_values[8][5]=0;
		if(flagmouse==59) f59=100, stage1_values[9][5]=0;
		if(flagmouse==61) f61=100, stage1_values[1][6]=0;
		if(flagmouse==62) f62=100, stage1_values[2][6]=0;
		if(flagmouse==63) f63=100, stage1_values[3][6]=0;
		if(flagmouse==64) f64=100, stage1_values[4][6]=0;
		if(flagmouse==65) f65=100, stage1_values[5][6]=0;
		if(flagmouse==66) f66=100, stage1_values[6][6]=0;
		if(flagmouse==67) f67=100, stage1_values[7][6]=0;
		if(flagmouse==68) f68=100, stage1_values[8][6]=0;
		if(flagmouse==69) f69=100, stage1_values[9][6]=0;
		if(flagmouse==71) f71=100, stage1_values[1][7]=0;
		if(flagmouse==72) f72=100, stage1_values[2][7]=0;
		if(flagmouse==73) f73=100, stage1_values[3][7]=0;
		if(flagmouse==74) f74=100, stage1_values[4][7]=0;
		if(flagmouse==75) f75=100, stage1_values[5][7]=0;
		if(flagmouse==76) f76=100, stage1_values[6][7]=0;
		if(flagmouse==77) f77=100, stage1_values[7][7]=0;
		if(flagmouse==78) f78=100, stage1_values[8][7]=0;
		if(flagmouse==79) f79=100, stage1_values[9][7]=0;
		if(flagmouse==81) f81=100, stage1_values[1][8]=0;
		if(flagmouse==82) f82=100, stage1_values[2][8]=0;
		if(flagmouse==83) f83=100, stage1_values[3][8]=0;
		if(flagmouse==84) f84=100, stage1_values[4][8]=0;
		if(flagmouse==85) f85=100, stage1_values[5][8]=0;
		if(flagmouse==86) f86=100, stage1_values[6][8]=0;
		if(flagmouse==87) f87=100, stage1_values[7][8]=0;
		if(flagmouse==88) f88=100, stage1_values[8][8]=0;
		if(flagmouse==89) f89=100, stage1_values[9][8]=0;
		if(flagmouse==91) f91=100, stage1_values[1][9]=0;
		if(flagmouse==92) f92=100, stage1_values[2][9]=0;
		if(flagmouse==93) f93=100, stage1_values[3][9]=0;
		if(flagmouse==94) f94=100, stage1_values[4][9]=0;
		if(flagmouse==95) f95=100, stage1_values[5][9]=0;
		if(flagmouse==96) f96=100, stage1_values[6][9]=0;
		if(flagmouse==97) f97=100, stage1_values[7][9]=0;
		if(flagmouse==98) f98=100, stage1_values[8][9]=0;
		if(flagmouse==99) f99=100, stage1_values[9][9]=0;
	}
	
	}

	if(page5==1)
	{
		if (key == '1')
	{
		if(flagmouse==11) f11=1, stage2_values[1][1]=1;
		if(flagmouse==12) f12=1, stage2_values[2][1]=1;
		if(flagmouse==14) f14=1, stage2_values[4][1]=1;
		if(flagmouse==16) f16=1, stage2_values[6][1]=1;
		if(flagmouse==17) f17=1, stage2_values[7][1]=1;
		if(flagmouse==21) f21=1, stage2_values[1][2]=1;
		if(flagmouse==22) f22=1, stage2_values[2][2]=1;
		if(flagmouse==23) f23=1, stage2_values[3][2]=1;
		if(flagmouse==24) f24=1, stage2_values[4][2]=1;
		if(flagmouse==25) f25=1, stage2_values[5][2]=1;
		if(flagmouse==26) f26=1, stage2_values[6][2]=1;
		if(flagmouse==28) f28=1, stage2_values[8][2]=1;
		if(flagmouse==31) f31=1, stage2_values[1][3]=1;
		if(flagmouse==32) f32=1, stage2_values[2][3]=1;
		if(flagmouse==35) f35=1, stage2_values[5][3]=1;
		if(flagmouse==36) f36=1, stage2_values[6][3]=1;
		if(flagmouse==37) f37=1, stage2_values[7][3]=1;
		if(flagmouse==39) f39=1, stage2_values[9][3]=1;
		if(flagmouse==42) f42=1, stage2_values[2][4]=1;
		if(flagmouse==43) f43=1, stage2_values[3][4]=1;
		if(flagmouse==44) f44=1, stage2_values[4][4]=1;
		if(flagmouse==45) f45=1, stage2_values[5][4]=1;
		if(flagmouse==47) f47=1, stage2_values[7][4]=1;
		if(flagmouse==48) f48=1, stage2_values[8][4]=1;
		if(flagmouse==51) f51=1, stage2_values[1][5]=1;
		if(flagmouse==52) f52=1, stage2_values[2][5]=1;
		if(flagmouse==53) f53=1, stage2_values[3][5]=1;
		if(flagmouse==55) f55=1, stage2_values[5][5]=1;
		if(flagmouse==57) f57=1, stage2_values[7][5]=1;
		if(flagmouse==58) f58=1, stage2_values[8][5]=1;
		if(flagmouse==59) f59=1, stage2_values[9][5]=1;
		if(flagmouse==62) f62=1, stage2_values[2][6]=1;
		if(flagmouse==63) f63=1, stage2_values[3][6]=1;
		if(flagmouse==65) f65=1, stage2_values[5][6]=1;
		if(flagmouse==66) f66=1, stage2_values[6][6]=1;
		if(flagmouse==67) f67=1, stage2_values[7][6]=1;
		if(flagmouse==68) f68=1, stage2_values[8][6]=1;
		if(flagmouse==71) f71=1, stage2_values[1][7]=1;
		if(flagmouse==73) f73=1, stage2_values[3][7]=1;
		if(flagmouse==74) f74=1, stage2_values[4][7]=1;
		if(flagmouse==75) f75=1, stage2_values[5][7]=1;
		if(flagmouse==78) f78=1, stage2_values[8][7]=1;
		if(flagmouse==79) f79=1, stage2_values[9][7]=1;
		if(flagmouse==82) f82=1, stage2_values[2][8]=1;
		if(flagmouse==84) f84=1, stage2_values[4][8]=1;
		if(flagmouse==85) f85=1, stage2_values[5][8]=1;
		if(flagmouse==86) f86=1, stage2_values[6][8]=1;
		if(flagmouse==87) f87=1, stage2_values[7][8]=1;
		if(flagmouse==88) f88=1, stage2_values[8][8]=1;
		if(flagmouse==89) f89=1, stage2_values[9][8]=1;
		if(flagmouse==93) f93=1, stage2_values[3][9]=1;
		if(flagmouse==94) f94=1, stage2_values[4][9]=1;
		if(flagmouse==96) f96=1, stage2_values[6][9]=1;
		if(flagmouse==98) f98=1, stage2_values[8][9]=1;
		if(flagmouse==99) f99=1, stage2_values[9][9]=1;
	}
	if (key == '2')
	{
		if(flagmouse==11) f11=2, stage2_values[1][1]=2;
		if(flagmouse==12) f12=2, stage2_values[2][1]=2;
		if(flagmouse==14) f14=2, stage2_values[4][1]=2;
		if(flagmouse==16) f16=2, stage2_values[6][1]=2;
		if(flagmouse==17) f17=2, stage2_values[7][1]=2;
		if(flagmouse==21) f21=2, stage2_values[1][2]=2;
		if(flagmouse==22) f22=2, stage2_values[2][2]=2;
		if(flagmouse==23) f23=2, stage2_values[3][2]=2;
		if(flagmouse==24) f24=2, stage2_values[4][2]=2;
		if(flagmouse==25) f25=2, stage2_values[5][2]=2;
		if(flagmouse==26) f26=2, stage2_values[6][2]=2;
		if(flagmouse==28) f28=2, stage2_values[8][2]=2;
		if(flagmouse==31) f31=2, stage2_values[1][3]=2;
		if(flagmouse==32) f32=2, stage2_values[2][3]=2;
		if(flagmouse==35) f35=2, stage2_values[5][3]=2;
		if(flagmouse==36) f36=2, stage2_values[6][3]=2;
		if(flagmouse==37) f37=2, stage2_values[7][3]=2;
		if(flagmouse==39) f39=2, stage2_values[9][3]=2;
		if(flagmouse==42) f42=2, stage2_values[2][4]=2;
		if(flagmouse==43) f43=2, stage2_values[3][4]=2;
		if(flagmouse==44) f44=2, stage2_values[4][4]=2;
		if(flagmouse==45) f45=2, stage2_values[5][4]=2;
		if(flagmouse==47) f47=2, stage2_values[7][4]=2;
		if(flagmouse==48) f48=2, stage2_values[8][4]=2;
		if(flagmouse==51) f51=2, stage2_values[1][5]=2;
		if(flagmouse==52) f52=2, stage2_values[2][5]=2;
		if(flagmouse==53) f53=2, stage2_values[3][5]=2;
		if(flagmouse==55) f55=2, stage2_values[5][5]=2;
		if(flagmouse==57) f57=2, stage2_values[7][5]=2;
		if(flagmouse==58) f58=2, stage2_values[8][5]=2;
		if(flagmouse==59) f59=2, stage2_values[9][5]=2;
		if(flagmouse==62) f62=2, stage2_values[2][6]=2;
		if(flagmouse==63) f63=2, stage2_values[3][6]=2;
		if(flagmouse==65) f65=2, stage2_values[5][6]=2;
		if(flagmouse==66) f66=2, stage2_values[6][6]=2;
		if(flagmouse==67) f67=2, stage2_values[7][6]=2;
		if(flagmouse==68) f68=2, stage2_values[8][6]=2;
		if(flagmouse==71) f71=2, stage2_values[1][7]=2;
		if(flagmouse==73) f73=2, stage2_values[3][7]=2;
		if(flagmouse==74) f74=2, stage2_values[4][7]=2;
		if(flagmouse==75) f75=2, stage2_values[5][7]=2;
		if(flagmouse==78) f78=2, stage2_values[8][7]=2;
		if(flagmouse==79) f79=2, stage2_values[9][7]=2;
		if(flagmouse==82) f82=2, stage2_values[2][8]=2;
		if(flagmouse==84) f84=2, stage2_values[4][8]=2;
		if(flagmouse==85) f85=2, stage2_values[5][8]=2;
		if(flagmouse==86) f86=2, stage2_values[6][8]=2;
		if(flagmouse==87) f87=2, stage2_values[7][8]=2;
		if(flagmouse==88) f88=2, stage2_values[8][8]=2;
		if(flagmouse==89) f89=2, stage2_values[9][8]=2;
		if(flagmouse==93) f93=2, stage2_values[3][9]=2;
		if(flagmouse==94) f94=2, stage2_values[4][9]=2;
		if(flagmouse==96) f96=2, stage2_values[6][9]=2;
		if(flagmouse==98) f98=2, stage2_values[8][9]=2;
		if(flagmouse==99) f99=2, stage2_values[9][9] =2;
	}
	if (key == '3')
	{
		if(flagmouse==11) f11=3, stage2_values[1][1]=3;
		if(flagmouse==12) f12=3, stage2_values[2][1]=3;
		if(flagmouse==14) f14=3, stage2_values[4][1]=3;
		if(flagmouse==16) f16=3, stage2_values[6][1]=3;
		if(flagmouse==17) f17=3, stage2_values[7][1]=3;
		if(flagmouse==21) f21=3, stage2_values[1][2]=3;
		if(flagmouse==22) f22=3, stage2_values[2][2]=3;
		if(flagmouse==23) f23=3, stage2_values[3][2]=3;
		if(flagmouse==24) f24=3, stage2_values[4][2]=3;
		if(flagmouse==25) f25=3, stage2_values[5][2]=3;
		if(flagmouse==26) f26=3, stage2_values[6][2]=3;
		if(flagmouse==28) f28=3, stage2_values[8][2]=3;
		if(flagmouse==31) f31=3, stage2_values[1][3]=3;
		if(flagmouse==32) f32=3, stage2_values[2][3]=3;
		if(flagmouse==35) f35=3, stage2_values[5][3]=3;
		if(flagmouse==36) f36=3, stage2_values[6][3]=3;
		if(flagmouse==37) f37=3, stage2_values[7][3]=3;
		if(flagmouse==39) f39=3, stage2_values[9][3]=3;
		if(flagmouse==42) f42=3, stage2_values[2][4]=3;
		if(flagmouse==43) f43=3, stage2_values[3][4]=3;
		if(flagmouse==44) f44=3, stage2_values[4][4]=3;
		if(flagmouse==45) f45=3, stage2_values[5][4]=3;
		if(flagmouse==47) f47=3, stage2_values[7][4]=3;
		if(flagmouse==48) f48=3, stage2_values[8][4]=3;
		if(flagmouse==51) f51=3, stage2_values[1][5]=3;
		if(flagmouse==52) f52=3, stage2_values[2][5]=3;
		if(flagmouse==53) f53=3, stage2_values[3][5]=3;
		if(flagmouse==55) f55=3, stage2_values[5][5]=3;
		if(flagmouse==57) f57=3, stage2_values[7][5]=3;
		if(flagmouse==58) f58=3, stage2_values[8][5]=3;
		if(flagmouse==59) f59=3, stage2_values[9][5]=3;
		if(flagmouse==62) f62=3, stage2_values[2][6]=3;
		if(flagmouse==63) f63=3, stage2_values[3][6]=3;
		if(flagmouse==65) f65=3, stage2_values[5][6]=3;
		if(flagmouse==66) f66=3, stage2_values[6][6]=3;
		if(flagmouse==67) f67=3, stage2_values[7][6]=3;
		if(flagmouse==68) f68=3, stage2_values[8][6]=3;
		if(flagmouse==71) f71=3, stage2_values[1][7]=3;
		if(flagmouse==73) f73=3, stage2_values[3][7]=3;
		if(flagmouse==74) f74=3, stage2_values[4][7]=3;
		if(flagmouse==75) f75=3, stage2_values[5][7]=3;
		if(flagmouse==78) f78=3, stage2_values[8][7]=3;
		if(flagmouse==79) f79=3, stage2_values[9][7]=3;
		if(flagmouse==82) f82=3, stage2_values[2][8]=3;
		if(flagmouse==84) f84=3, stage2_values[4][8]=3;
		if(flagmouse==85) f85=3, stage2_values[5][8]=3;
		if(flagmouse==86) f86=3, stage2_values[6][8]=3;
		if(flagmouse==87) f87=3, stage2_values[7][8]=3;
		if(flagmouse==88) f88=3, stage2_values[8][8]=3;
		if(flagmouse==89) f89=3, stage2_values[9][8]=3;
		if(flagmouse==93) f93=3, stage2_values[3][9]=3;
		if(flagmouse==94) f94=3, stage2_values[4][9]=3;
		if(flagmouse==96) f96=3, stage2_values[6][9]=3;
		if(flagmouse==98) f98=3, stage2_values[8][9]=3;
		if(flagmouse==99) f99=3, stage2_values[9][9]=3;
	}
	if (key == '4')
	{
		if(flagmouse==11) f11=4, stage2_values[1][1]=4;
		if(flagmouse==12) f12=4, stage2_values[2][1]=4;
		if(flagmouse==14) f14=4, stage2_values[4][1]=4;
		if(flagmouse==16) f16=4, stage2_values[6][1]=4;
		if(flagmouse==17) f17=4, stage2_values[7][1]=4;
		if(flagmouse==21) f21=4, stage2_values[1][2]=4;
		if(flagmouse==22) f22=4, stage2_values[2][2]=4;
		if(flagmouse==23) f23=4, stage2_values[3][2]=4;
		if(flagmouse==24) f24=4, stage2_values[4][2]=4;
		if(flagmouse==25) f25=4, stage2_values[5][2]=4;
		if(flagmouse==26) f26=4, stage2_values[6][2]=4;
		if(flagmouse==28) f28=4, stage2_values[8][2]=4;
		if(flagmouse==31) f31=4, stage2_values[1][3]=4;
		if(flagmouse==32) f32=4, stage2_values[2][3]=4;
		if(flagmouse==35) f35=4, stage2_values[5][3]=4;
		if(flagmouse==36) f36=4, stage2_values[6][3]=4;
		if(flagmouse==37) f37=4, stage2_values[7][3]=4;
		if(flagmouse==39) f39=4, stage2_values[9][3]=4;
		if(flagmouse==42) f42=4, stage2_values[2][4]=4;
		if(flagmouse==43) f43=4, stage2_values[3][4]=4;
		if(flagmouse==44) f44=4, stage2_values[4][4]=4;
		if(flagmouse==45) f45=4, stage2_values[5][4]=4;
		if(flagmouse==47) f47=4, stage2_values[7][4]=4;
		if(flagmouse==48) f48=4, stage2_values[8][4]=4;
		if(flagmouse==51) f51=4, stage2_values[1][5]=4;
		if(flagmouse==52) f52=4, stage2_values[2][5]=4;
		if(flagmouse==53) f53=4, stage2_values[3][5]=4;
		if(flagmouse==55) f55=4, stage2_values[5][5]=4;
		if(flagmouse==57) f57=4, stage2_values[7][5]=4;
		if(flagmouse==58) f58=4, stage2_values[8][5]=4;
		if(flagmouse==59) f59=4, stage2_values[9][5]=4;
		if(flagmouse==62) f62=4, stage2_values[2][6]=4;
		if(flagmouse==63) f63=4, stage2_values[3][6]=4;
		if(flagmouse==65) f65=4, stage2_values[5][6]=4;
		if(flagmouse==66) f66=4, stage2_values[6][6]=4;
		if(flagmouse==67) f67=4, stage2_values[7][6]=4;
		if(flagmouse==68) f68=4, stage2_values[8][6]=4;
		if(flagmouse==71) f71=4, stage2_values[1][7]=4;
		if(flagmouse==73) f73=4, stage2_values[3][7]=4;
		if(flagmouse==74) f74=4, stage2_values[4][7]=4;
		if(flagmouse==75) f75=4, stage2_values[5][7]=4;
		if(flagmouse==78) f78=4, stage2_values[8][7]=4;
		if(flagmouse==79) f79=4, stage2_values[9][7]=4;
		if(flagmouse==82) f82=4, stage2_values[2][8]=4;
		if(flagmouse==84) f84=4, stage2_values[4][8]=4;
		if(flagmouse==85) f85=4, stage2_values[5][8]=4;
		if(flagmouse==86) f86=4, stage2_values[6][8]=4;
		if(flagmouse==87) f87=4, stage2_values[7][8]=4;
		if(flagmouse==88) f88=4, stage2_values[8][8]=4;
		if(flagmouse==89) f89=4, stage2_values[9][8]=4;
		if(flagmouse==93) f93=4, stage2_values[3][9]=4;
		if(flagmouse==94) f94=4, stage2_values[4][9]=4;
		if(flagmouse==96) f96=4, stage2_values[6][9]=4;
		if(flagmouse==98) f98=4, stage2_values[8][9]=4;
		if(flagmouse==99) f99=4, stage2_values[9][9]=4;
	}
	if (key == '5')
	{
		if(flagmouse==11) f11=5, stage2_values[1][1]=5;
		if(flagmouse==12) f12=5, stage2_values[2][1]=5;
		if(flagmouse==14) f14=5, stage2_values[4][1]=5;
		if(flagmouse==16) f16=5, stage2_values[6][1]=5;
		if(flagmouse==17) f17=5, stage2_values[7][1]=5;
		if(flagmouse==21) f21=5, stage2_values[1][2]=5;
		if(flagmouse==22) f22=5, stage2_values[2][2]=5;
		if(flagmouse==23) f23=5, stage2_values[3][2]=5;
		if(flagmouse==24) f24=5, stage2_values[4][2]=5;
		if(flagmouse==25) f25=5, stage2_values[5][2]=5;
		if(flagmouse==26) f26=5, stage2_values[6][2]=5;
		if(flagmouse==28) f28=5, stage2_values[8][2]=5;
		if(flagmouse==31) f31=5, stage2_values[1][3]=5;
		if(flagmouse==32) f32=5, stage2_values[2][3]=5;
		if(flagmouse==35) f35=5, stage2_values[5][3]=5;
		if(flagmouse==36) f36=5, stage2_values[6][3]=5;
		if(flagmouse==37) f37=5, stage2_values[7][3]=5;
		if(flagmouse==39) f39=5, stage2_values[9][3]=5;
		if(flagmouse==42) f42=5, stage2_values[2][4]=5;
		if(flagmouse==43) f43=5, stage2_values[3][4]=5;
		if(flagmouse==44) f44=5, stage2_values[4][4]=5;
		if(flagmouse==45) f45=5, stage2_values[5][4]=5;
		if(flagmouse==47) f47=5, stage2_values[7][4]=5;
		if(flagmouse==48) f48=5, stage2_values[8][4]=5;
		if(flagmouse==51) f51=5, stage2_values[1][5]=5;
		if(flagmouse==52) f52=5, stage2_values[2][5]=5;
		if(flagmouse==53) f53=5, stage2_values[3][5]=5;
		if(flagmouse==55) f55=5, stage2_values[5][5]=5;
		if(flagmouse==57) f57=5, stage2_values[7][5]=5;
		if(flagmouse==58) f58=5, stage2_values[8][5]=5;
		if(flagmouse==59) f59=5, stage2_values[9][5]=5;
		if(flagmouse==62) f62=5, stage2_values[2][6]=5;
		if(flagmouse==63) f63=5, stage2_values[3][6]=5;
		if(flagmouse==65) f65=5, stage2_values[5][6]=5;
		if(flagmouse==66) f66=5, stage2_values[6][6]=5;
		if(flagmouse==67) f67=5, stage2_values[7][6]=5;
		if(flagmouse==68) f68=5, stage2_values[8][6]=5;
		if(flagmouse==71) f71=5, stage2_values[1][7]=5;
		if(flagmouse==73) f73=5, stage2_values[3][7]=5;
		if(flagmouse==74) f74=5, stage2_values[4][7]=5;
		if(flagmouse==75) f75=5, stage2_values[5][7]=5;
		if(flagmouse==78) f78=5, stage2_values[8][7]=5;
		if(flagmouse==79) f79=5, stage2_values[9][7]=5;
		if(flagmouse==82) f82=5, stage2_values[2][8]=5;
		if(flagmouse==84) f84=5, stage2_values[4][8]=5;
		if(flagmouse==85) f85=5, stage2_values[5][8]=5;
		if(flagmouse==86) f86=5, stage2_values[6][8]=5;
		if(flagmouse==87) f87=5, stage2_values[7][8]=5;
		if(flagmouse==88) f88=5, stage2_values[8][8]=5;
		if(flagmouse==89) f89=5, stage2_values[9][8]=5;
		if(flagmouse==93) f93=5, stage2_values[3][9]=5;
		if(flagmouse==94) f94=5, stage2_values[4][9]=5;
		if(flagmouse==96) f96=5, stage2_values[6][9]=5;
		if(flagmouse==98) f98=5, stage2_values[8][9]=5;
		if(flagmouse==99) f99=5, stage2_values[9][9]=5;
	}
	if (key == '6')
	{
		if(flagmouse==11) f11=6, stage2_values[1][1]=6;
		if(flagmouse==12) f12=6, stage2_values[2][1]=6;
		if(flagmouse==14) f14=6, stage2_values[4][1]=6;
		if(flagmouse==16) f16=6, stage2_values[6][1]=6;
		if(flagmouse==17) f17=6, stage2_values[7][1]=6;
		if(flagmouse==21) f21=6, stage2_values[1][2]=6;
		if(flagmouse==22) f22=6, stage2_values[2][2]=6;
		if(flagmouse==23) f23=6, stage2_values[3][2]=6;
		if(flagmouse==24) f24=6, stage2_values[4][2]=6;
		if(flagmouse==25) f25=6, stage2_values[5][2]=6;
		if(flagmouse==26) f26=6, stage2_values[6][2]=6;
		if(flagmouse==28) f28=6, stage2_values[8][2]=6;
		if(flagmouse==31) f31=6, stage2_values[1][3]=6;
		if(flagmouse==32) f32=6, stage2_values[2][3]=6;
		if(flagmouse==35) f35=6, stage2_values[5][3]=6;
		if(flagmouse==36) f36=6, stage2_values[6][3]=6;
		if(flagmouse==37) f37=6, stage2_values[7][3]=6;
		if(flagmouse==39) f39=6, stage2_values[9][3]=6;
		if(flagmouse==42) f42=6, stage2_values[2][4]=6;
		if(flagmouse==43) f43=6, stage2_values[3][4]=6;
		if(flagmouse==44) f44=6, stage2_values[4][4]=6;
		if(flagmouse==45) f45=6, stage2_values[5][4]=6;
		if(flagmouse==47) f47=6, stage2_values[7][4]=6;
		if(flagmouse==48) f48=6, stage2_values[8][4]=6;
		if(flagmouse==51) f51=6, stage2_values[1][5]=6;
		if(flagmouse==52) f52=6, stage2_values[2][5]=6;
		if(flagmouse==53) f53=6, stage2_values[3][5]=6;
		if(flagmouse==55) f55=6, stage2_values[5][5]=6;
		if(flagmouse==57) f57=6, stage2_values[7][5]=6;
		if(flagmouse==58) f58=6, stage2_values[8][5]=6;
		if(flagmouse==59) f59=6, stage2_values[9][5]=6;
		if(flagmouse==62) f62=6, stage2_values[2][6]=6;
		if(flagmouse==63) f63=6, stage2_values[3][6]=6;
		if(flagmouse==65) f65=6, stage2_values[5][6]=6;
		if(flagmouse==66) f66=6, stage2_values[6][6]=6;
		if(flagmouse==67) f67=6, stage2_values[7][6]=6;
		if(flagmouse==68) f68=6, stage2_values[8][6]=6;
		if(flagmouse==71) f71=6, stage2_values[1][7]=6;
		if(flagmouse==73) f73=6, stage2_values[3][7]=6;
		if(flagmouse==74) f74=6, stage2_values[4][7]=6;
		if(flagmouse==75) f75=6, stage2_values[5][7]=6;
		if(flagmouse==78) f78=6, stage2_values[8][7]=6;
		if(flagmouse==79) f79=6, stage2_values[9][7]=6;
		if(flagmouse==82) f82=6, stage2_values[2][8]=6;
		if(flagmouse==84) f84=6, stage2_values[4][8]=6;
		if(flagmouse==85) f85=6, stage2_values[5][8]=6;
		if(flagmouse==86) f86=6, stage2_values[6][8]=6;
		if(flagmouse==87) f87=6, stage2_values[7][8]=6;
		if(flagmouse==88) f88=6, stage2_values[8][8]=6;
		if(flagmouse==89) f89=6, stage2_values[9][8]=6;
		if(flagmouse==93) f93=6, stage2_values[3][9]=6;
		if(flagmouse==94) f94=6, stage2_values[4][9]=6;
		if(flagmouse==96) f96=6, stage2_values[6][9]=6;
		if(flagmouse==98) f98=6, stage2_values[8][9]=6;
		if(flagmouse==99) f99=6, stage2_values[9][9]=6;
	}
	if (key == '7')
	{
		if(flagmouse==11) f11=7, stage2_values[1][1]=7;
		if(flagmouse==12) f12=7, stage2_values[2][1]=7;
		if(flagmouse==14) f14=7, stage2_values[4][1]=7;
		if(flagmouse==16) f16=7, stage2_values[6][1]=7;
		if(flagmouse==17) f17=7, stage2_values[7][1]=7;
		if(flagmouse==21) f21=7, stage2_values[1][2]=7;
		if(flagmouse==22) f22=7, stage2_values[2][2]=7;
		if(flagmouse==23) f23=7, stage2_values[3][2]=7;
		if(flagmouse==24) f24=7, stage2_values[4][2]=7;
		if(flagmouse==25) f25=7, stage2_values[5][2]=7;
		if(flagmouse==26) f26=7, stage2_values[6][2]=7;
		if(flagmouse==28) f28=7, stage2_values[8][2]=7;
		if(flagmouse==31) f31=7, stage2_values[1][3]=7;
		if(flagmouse==32) f32=7, stage2_values[2][3]=7;
		if(flagmouse==35) f35=7, stage2_values[5][3]=7;
		if(flagmouse==36) f36=7, stage2_values[6][3]=7;
		if(flagmouse==37) f37=7, stage2_values[7][3]=7;
		if(flagmouse==39) f39=7, stage2_values[9][3]=7;
		if(flagmouse==42) f42=7, stage2_values[2][4]=7;
		if(flagmouse==43) f43=7, stage2_values[3][4]=7;
		if(flagmouse==44) f44=7, stage2_values[4][4]=7;
		if(flagmouse==45) f45=7, stage2_values[5][4]=7;
		if(flagmouse==47) f47=7, stage2_values[7][4]=7;
		if(flagmouse==48) f48=7, stage2_values[8][4]=7;
		if(flagmouse==51) f51=7, stage2_values[1][5]=7;
		if(flagmouse==52) f52=7, stage2_values[2][5]=7;
		if(flagmouse==53) f53=7, stage2_values[3][5]=7;
		if(flagmouse==55) f55=7, stage2_values[5][5]=7;
		if(flagmouse==57) f57=7, stage2_values[7][5]=7;
		if(flagmouse==58) f58=7, stage2_values[8][5]=7;
		if(flagmouse==59) f59=7, stage2_values[9][5]=7;
		if(flagmouse==62) f62=7, stage2_values[2][6]=7;
		if(flagmouse==63) f63=7, stage2_values[3][6]=7;
		if(flagmouse==65) f65=7, stage2_values[5][6]=7;
		if(flagmouse==66) f66=7, stage2_values[6][6]=7;
		if(flagmouse==67) f67=7, stage2_values[7][6]=7;
		if(flagmouse==68) f68=7, stage2_values[8][6]=7;
		if(flagmouse==71) f71=7, stage2_values[1][7]=7;
		if(flagmouse==73) f73=7, stage2_values[3][7]=7;
		if(flagmouse==74) f74=7, stage2_values[4][7]=7;
		if(flagmouse==75) f75=7, stage2_values[5][7]=7;
		if(flagmouse==78) f78=7, stage2_values[8][7]=7;
		if(flagmouse==79) f79=7, stage2_values[9][7]=7;
		if(flagmouse==82) f82=7, stage2_values[2][8]=7;
		if(flagmouse==84) f84=7, stage2_values[4][8]=7;
		if(flagmouse==85) f85=7, stage2_values[5][8]=7;
		if(flagmouse==86) f86=7, stage2_values[6][8]=7;
		if(flagmouse==87) f87=7, stage2_values[7][8]=7;
		if(flagmouse==88) f88=7, stage2_values[8][8]=7;
		if(flagmouse==89) f89=7, stage2_values[9][8]=7;
		if(flagmouse==93) f93=7, stage2_values[3][9]=7;
		if(flagmouse==94) f94=7, stage2_values[4][9]=7;
		if(flagmouse==96) f96=7, stage2_values[6][9]=7;
		if(flagmouse==98) f98=7, stage2_values[8][9]=7;
		if(flagmouse==99) f99=7, stage2_values[9][9]=7;
	}
	if (key == '8')
	{
		if(flagmouse==11) f11=8, stage2_values[1][1]=8;
		if(flagmouse==12) f12=8, stage2_values[2][1]=8;
		if(flagmouse==14) f14=8, stage2_values[4][1]=8;
		if(flagmouse==16) f16=8, stage2_values[6][1]=8;
		if(flagmouse==17) f17=8, stage2_values[7][1]=8;
		if(flagmouse==21) f21=8, stage2_values[1][2]=8;
		if(flagmouse==22) f22=8, stage2_values[2][2]=8;
		if(flagmouse==23) f23=8, stage2_values[3][2]=8;
		if(flagmouse==24) f24=8, stage2_values[4][2]=8;
		if(flagmouse==25) f25=8, stage2_values[5][2]=8;
		if(flagmouse==26) f26=8, stage2_values[6][2]=8;
		if(flagmouse==28) f28=8, stage2_values[8][2]=8;
		if(flagmouse==31) f31=8, stage2_values[1][3]=8;
		if(flagmouse==32) f32=8, stage2_values[2][3]=8;
		if(flagmouse==35) f35=8, stage2_values[5][3]=8;
		if(flagmouse==36) f36=8, stage2_values[6][3]=8;
		if(flagmouse==37) f37=8, stage2_values[7][3]=8;
		if(flagmouse==39) f39=8, stage2_values[9][3]=8;
		if(flagmouse==42) f42=8, stage2_values[2][4]=8;
		if(flagmouse==43) f43=8, stage2_values[3][4]=8;
		if(flagmouse==44) f44=8, stage2_values[4][4]=8;
		if(flagmouse==45) f45=8, stage2_values[5][4]=8;
		if(flagmouse==47) f47=8, stage2_values[7][4]=8;
		if(flagmouse==48) f48=8, stage2_values[8][4]=8;
		if(flagmouse==51) f51=8, stage2_values[1][5]=8;
		if(flagmouse==52) f52=8, stage2_values[2][5]=8;
		if(flagmouse==53) f53=8, stage2_values[3][5]=8;
		if(flagmouse==55) f55=8, stage2_values[5][5]=8;
		if(flagmouse==57) f57=8, stage2_values[7][5]=8;
		if(flagmouse==58) f58=8, stage2_values[8][5]=8;
		if(flagmouse==59) f59=8, stage2_values[9][5]=8;
		if(flagmouse==62) f62=8, stage2_values[2][6]=8;
		if(flagmouse==63) f63=8, stage2_values[3][6]=8;
		if(flagmouse==65) f65=8, stage2_values[5][6]=8;
		if(flagmouse==66) f66=8, stage2_values[6][6]=8;
		if(flagmouse==67) f67=8, stage2_values[7][6]=8;
		if(flagmouse==68) f68=8, stage2_values[8][6]=8;
		if(flagmouse==71) f71=8, stage2_values[1][7]=8;
		if(flagmouse==73) f73=8, stage2_values[3][7]=8;
		if(flagmouse==74) f74=8, stage2_values[4][7]=8;
		if(flagmouse==75) f75=8, stage2_values[5][7]=8;
		if(flagmouse==78) f78=8, stage2_values[8][7]=8;
		if(flagmouse==79) f79=8, stage2_values[9][7]=8;
		if(flagmouse==82) f82=8, stage2_values[2][8]=8;
		if(flagmouse==84) f84=8, stage2_values[4][8]=8;
		if(flagmouse==85) f85=8, stage2_values[5][8]=8;
		if(flagmouse==86) f86=8, stage2_values[6][8]=8;
		if(flagmouse==87) f87=8, stage2_values[7][8]=8;
		if(flagmouse==88) f88=8, stage2_values[8][8]=8;
		if(flagmouse==89) f89=8, stage2_values[9][8]=8;
		if(flagmouse==93) f93=8, stage2_values[3][9]=8;
		if(flagmouse==94) f94=8, stage2_values[4][9]=8;
		if(flagmouse==96) f96=8, stage2_values[6][9]=8;
		if(flagmouse==98) f98=8, stage2_values[8][9]=8;
		if(flagmouse==99) f99=8, stage2_values[9][9]=8;
	}
	if (key == '9')
	{
		if(flagmouse==11) f11=9, stage2_values[1][1]=9;
		if(flagmouse==12) f12=9, stage2_values[2][1]=9;
		if(flagmouse==14) f14=9, stage2_values[4][1]=9;
		if(flagmouse==16) f16=9, stage2_values[6][1]=9;
		if(flagmouse==17) f17=9, stage2_values[7][1]=9;
		if(flagmouse==21) f21=9, stage2_values[1][2]=9;
		if(flagmouse==22) f22=9, stage2_values[2][2]=9;
		if(flagmouse==23) f23=9, stage2_values[3][2]=9;
		if(flagmouse==24) f24=9, stage2_values[4][2]=9;
		if(flagmouse==25) f25=9, stage2_values[5][2]=9;
		if(flagmouse==26) f26=9, stage2_values[6][2]=9;
		if(flagmouse==28) f28=9, stage2_values[8][2]=9;
		if(flagmouse==31) f31=9, stage2_values[1][3]=9;
		if(flagmouse==32) f32=9, stage2_values[2][3]=9;
		if(flagmouse==35) f35=9, stage2_values[5][3]=9;
		if(flagmouse==36) f36=9, stage2_values[6][3]=9;
		if(flagmouse==37) f37=9, stage2_values[7][3]=9;
		if(flagmouse==39) f39=9, stage2_values[9][3]=9;
		if(flagmouse==42) f42=9, stage2_values[2][4]=9;
		if(flagmouse==43) f43=9, stage2_values[3][4]=9;
		if(flagmouse==44) f44=9, stage2_values[4][4]=9;
		if(flagmouse==45) f45=9, stage2_values[5][4]=9;
		if(flagmouse==47) f47=9, stage2_values[7][4]=9;
		if(flagmouse==48) f48=9, stage2_values[8][4]=9;
		if(flagmouse==51) f51=9, stage2_values[1][5]=9;
		if(flagmouse==52) f52=9, stage2_values[2][5]=9;
		if(flagmouse==53) f53=9, stage2_values[3][5]=9;
		if(flagmouse==55) f55=9, stage2_values[5][5]=9;
		if(flagmouse==57) f57=9, stage2_values[7][5]=9;
		if(flagmouse==58) f58=9, stage2_values[8][5]=9;
		if(flagmouse==59) f59=9, stage2_values[9][5]=9;
		if(flagmouse==62) f62=9, stage2_values[2][6]=9;
		if(flagmouse==63) f63=9, stage2_values[3][6]=9;
		if(flagmouse==65) f65=9, stage2_values[5][6]=9;
		if(flagmouse==66) f66=9, stage2_values[6][6]=9;
		if(flagmouse==67) f67=9, stage2_values[7][6]=9;
		if(flagmouse==68) f68=9, stage2_values[8][6]=9;
		if(flagmouse==71) f71=9, stage2_values[1][7]=9;
		if(flagmouse==73) f73=9, stage2_values[3][7]=9;
		if(flagmouse==74) f74=9, stage2_values[4][7]=9;
		if(flagmouse==75) f75=9, stage2_values[5][7]=9;
		if(flagmouse==78) f78=9, stage2_values[8][7]=9;
		if(flagmouse==79) f79=9, stage2_values[9][7]=9;
		if(flagmouse==82) f82=9, stage2_values[2][8]=9;
		if(flagmouse==84) f84=9, stage2_values[4][8]=9;
		if(flagmouse==85) f85=9, stage2_values[5][8]=9;
		if(flagmouse==86) f86=9, stage2_values[6][8]=9;
		if(flagmouse==87) f87=9, stage2_values[7][8]=9;
		if(flagmouse==88) f88=9, stage2_values[8][8]=9;
		if(flagmouse==89) f89=9, stage2_values[9][8]=9;
		if(flagmouse==93) f93=9, stage2_values[3][9]=9;
		if(flagmouse==94) f94=9, stage2_values[4][9]=9;
		if(flagmouse==96) f96=9, stage2_values[6][9]=9;
		if(flagmouse==98) f98=9, stage2_values[8][9]=9;
		if(flagmouse==99) f99=9, stage2_values[9][9]=9;
	}
	
	if(key =='e')
	{
		if(flagmouse==11) f11=100, stage2_values[1][1]=0;
		if(flagmouse==12) f12=100, stage2_values[2][1]=0;
		if(flagmouse==13) f13=100, stage2_values[3][1]=0;
		if(flagmouse==14) f14=100, stage2_values[4][1]=0;
		if(flagmouse==15) f15=100, stage2_values[5][1]=0;
		if(flagmouse==16) f16=100, stage2_values[6][1]=0;
		if(flagmouse==17) f17=100, stage2_values[7][1]=0;
		if(flagmouse==18) f18=100, stage2_values[8][1]=0;
		if(flagmouse==19) f19=100, stage2_values[9][1]=0;
		if(flagmouse==21) f21=100, stage2_values[1][2]=0;
		if(flagmouse==22) f22=100, stage2_values[2][2]=0;
		if(flagmouse==23) f23=100, stage2_values[3][2]=0;
		if(flagmouse==24) f24=100, stage2_values[4][2]=0;
		if(flagmouse==25) f25=100, stage2_values[5][2]=0;
		if(flagmouse==26) f26=100, stage2_values[6][2]=0;
		if(flagmouse==27) f27=100, stage2_values[7][2]=0;
		if(flagmouse==28) f28=100, stage2_values[8][2]=0;
		if(flagmouse==29) f29=100, stage2_values[9][2]=0;
		if(flagmouse==31) f31=100, stage2_values[1][3]=0;
		if(flagmouse==32) f32=100, stage2_values[2][3]=0;
		if(flagmouse==33) f33=100, stage2_values[3][3]=0;
		if(flagmouse==34) f34=100, stage2_values[4][3]=0;
		if(flagmouse==35) f35=100, stage2_values[5][3]=0;
		if(flagmouse==36) f36=100, stage2_values[6][3]=0;
		if(flagmouse==37) f37=100, stage2_values[7][3]=0;
		if(flagmouse==38) f38=100, stage2_values[8][3]=0;
		if(flagmouse==39) f39=100, stage2_values[9][3]=0;
		if(flagmouse==41) f41=100, stage2_values[1][4]=0;
		if(flagmouse==42) f42=100, stage2_values[2][4]=0;
		if(flagmouse==43) f43=100, stage2_values[3][4]=0;
		if(flagmouse==44) f44=100, stage2_values[4][4]=0;
		if(flagmouse==45) f45=100, stage2_values[5][4]=0;
		if(flagmouse==46) f46=100, stage2_values[6][4]=0;
		if(flagmouse==47) f47=100, stage2_values[7][4]=0;
		if(flagmouse==48) f48=100, stage2_values[8][4]=0;
		if(flagmouse==49) f49=100, stage2_values[9][4]=0;
		if(flagmouse==51) f51=100, stage2_values[1][5]=0;
		if(flagmouse==52) f52=100, stage2_values[2][5]=0;
		if(flagmouse==53) f53=100, stage2_values[3][5]=0;
		if(flagmouse==54) f54=100, stage2_values[4][5]=0;
		if(flagmouse==55) f55=100, stage2_values[5][5]=0;
		if(flagmouse==56) f56=100, stage2_values[6][5]=0;
		if(flagmouse==57) f57=100, stage2_values[7][5]=0;
		if(flagmouse==58) f58=100, stage2_values[8][5]=0;
		if(flagmouse==59) f59=100, stage2_values[9][5]=0;
		if(flagmouse==61) f61=100, stage2_values[1][6]=0;
		if(flagmouse==62) f62=100, stage2_values[2][6]=0;
		if(flagmouse==63) f63=100, stage2_values[3][6]=0;
		if(flagmouse==64) f64=100, stage2_values[4][6]=0;
		if(flagmouse==65) f65=100, stage2_values[5][6]=0;
		if(flagmouse==66) f66=100, stage2_values[6][6]=0;
		if(flagmouse==67) f67=100, stage2_values[7][6]=0;
		if(flagmouse==68) f68=100, stage2_values[8][6]=0;
		if(flagmouse==69) f69=100, stage2_values[9][6]=0;
		if(flagmouse==71) f71=100, stage2_values[1][7]=0;
		if(flagmouse==72) f72=100, stage2_values[2][7]=0;
		if(flagmouse==73) f73=100, stage2_values[3][7]=0;
		if(flagmouse==74) f74=100, stage2_values[4][7]=0;
		if(flagmouse==75) f75=100, stage2_values[5][7]=0;
		if(flagmouse==76) f76=100, stage2_values[6][7]=0;
		if(flagmouse==77) f77=100, stage2_values[7][7]=0;
		if(flagmouse==78) f78=100, stage2_values[8][7]=0;
		if(flagmouse==79) f79=100, stage2_values[9][7]=0;
		if(flagmouse==81) f81=100, stage2_values[1][8]=0;
		if(flagmouse==82) f82=100, stage2_values[2][8]=0;
		if(flagmouse==83) f83=100, stage2_values[3][8]=0;
		if(flagmouse==84) f84=100, stage2_values[4][8]=0;
		if(flagmouse==85) f85=100, stage2_values[5][8]=0;
		if(flagmouse==86) f86=100, stage2_values[6][8]=0;
		if(flagmouse==87) f87=100, stage2_values[7][8]=0;
		if(flagmouse==88) f88=100, stage2_values[8][8]=0;
		if(flagmouse==89) f89=100, stage2_values[9][8]=0;
		if(flagmouse==91) f91=100, stage2_values[1][9]=0;
		if(flagmouse==92) f92=100, stage2_values[2][9]=0;
		if(flagmouse==93) f93=100, stage2_values[3][9]=0;
		if(flagmouse==94) f94=100, stage2_values[4][9]=0;
		if(flagmouse==95) f95=100, stage2_values[5][9]=0;
		if(flagmouse==96) f96=100, stage2_values[6][9]=0;
		if(flagmouse==97) f97=100, stage2_values[7][9]=0;
		if(flagmouse==98) f98=100, stage2_values[8][9]=0;
		if(flagmouse==99) f99=100, stage2_values[9][9]=0;
	}
	}

	if(page6==1)
	{
		if (key == '1')
	{
		if(flagmouse==11) f11=1, stage4_values[1][1]=1;
		if(flagmouse==12) f12=1, stage4_values[2][1]=1;
		if(flagmouse==13) f13=1, stage4_values[3][1]=1;
		if(flagmouse==14) f14=1, stage4_values[4][1]=1;
		if(flagmouse==15) f15=1, stage4_values[5][1]=1;
		if(flagmouse==17) f17=1, stage4_values[7][1]=1;
		if(flagmouse==19) f19=1, stage4_values[9][1]=1;
		if(flagmouse==22) f22=1, stage4_values[2][2]=1;
		if(flagmouse==23) f23=1, stage4_values[3][2]=1;
		if(flagmouse==24) f24=1, stage4_values[4][2]=1;
		if(flagmouse==26) f26=1, stage4_values[6][2]=1;
		if(flagmouse==27) f27=1, stage4_values[7][2]=1;
		if(flagmouse==28) f28=1, stage4_values[8][2]=1;
		if(flagmouse==31) f31=1, stage4_values[1][3]=1;
		if(flagmouse==33) f33=1, stage4_values[3][3]=1;
		if(flagmouse==35) f35=1, stage4_values[5][3]=1;
		if(flagmouse==36) f36=1, stage4_values[6][3]=1;
		if(flagmouse==38) f38=1, stage4_values[8][3]=1;
		if(flagmouse==39) f39=1, stage4_values[9][3]=1;
		if(flagmouse==41) f41=1, stage4_values[1][4]=1;
		if(flagmouse==43) f43=1, stage4_values[3][4]=1;
		if(flagmouse==44) f44=1, stage4_values[4][4]=1;
		if(flagmouse==45) f45=1, stage4_values[5][4]=1;
		if(flagmouse==46) f46=1, stage4_values[6][4]=1;
		if(flagmouse==47) f47=1, stage4_values[7][4]=1;
		if(flagmouse==48) f48=1, stage4_values[8][4]=1;
		if(flagmouse==51) f51=1, stage4_values[1][5]=1;
		if(flagmouse==52) f52=1, stage4_values[2][5]=1;
		if(flagmouse==55) f55=1, stage4_values[5][5]=1;
		if(flagmouse==58) f58=1, stage4_values[8][5]=1;
		if(flagmouse==59) f59=1, stage4_values[9][5]=1;
		if(flagmouse==62) f62=1, stage4_values[2][6]=1;
		if(flagmouse==63) f63=1, stage4_values[3][6]=1;
		if(flagmouse==64) f64=1, stage4_values[4][6]=1;
		if(flagmouse==67) f67=1, stage4_values[7][6]=1;
		if(flagmouse==69) f69=1, stage4_values[9][6]=1;
		if(flagmouse==71) f71=1, stage4_values[1][7]=1;
		if(flagmouse==72) f72=1, stage4_values[2][7]=1;
		if(flagmouse==74) f74=1, stage4_values[4][7]=1;
		if(flagmouse==75) f75=1, stage4_values[5][7]=1;
		if(flagmouse==77) f77=1, stage4_values[7][7]=1;
		if(flagmouse==79) f79=1, stage4_values[9][7]=1;
		if(flagmouse==82) f82=1, stage4_values[2][8]=1;
		if(flagmouse==83) f83=1, stage4_values[3][8]=1;
		if(flagmouse==84) f84=1, stage4_values[4][8]=1;
		if(flagmouse==86) f86=1, stage4_values[6][8]=1;
		if(flagmouse==87) f87=1, stage4_values[7][8]=1;
		if(flagmouse==88) f88=1, stage4_values[8][8]=1;
		if(flagmouse==91) f91=1, stage4_values[1][9]=1;
		if(flagmouse==93) f93=1, stage4_values[3][9]=1;
		if(flagmouse==95) f95=1, stage4_values[5][9]=1;
		if(flagmouse==96) f96=1, stage4_values[6][9]=1;
		if(flagmouse==97) f97=1, stage4_values[7][9]=1;
		if(flagmouse==98) f98=1, stage4_values[8][9]=1;
		if(flagmouse==99) f99=1, stage4_values[9][9]=1;
	}
	
	if (key == '2')
	{
		if(flagmouse==11) f11=2, stage4_values[1][1]=2;
		if(flagmouse==12) f12=2, stage4_values[2][1]=2;
		if(flagmouse==13) f13=2, stage4_values[3][1]=2;
		if(flagmouse==14) f14=2, stage4_values[4][1]=2;
		if(flagmouse==15) f15=2, stage4_values[5][1]=2;
		if(flagmouse==17) f17=2, stage4_values[7][1]=2;
		if(flagmouse==19) f19=2, stage4_values[9][1]=2;
		if(flagmouse==22) f22=2, stage4_values[2][2]=2;
		if(flagmouse==23) f23=2, stage4_values[3][2]=2;
		if(flagmouse==24) f24=2, stage4_values[4][2]=2;
		if(flagmouse==26) f26=2, stage4_values[6][2]=2;
		if(flagmouse==27) f27=2, stage4_values[7][2]=2;
		if(flagmouse==28) f28=2, stage4_values[8][2]=2;
		if(flagmouse==31) f31=2, stage4_values[1][3]=2;
		if(flagmouse==33) f33=2, stage4_values[3][3]=2;
		if(flagmouse==35) f35=2, stage4_values[5][3]=2;
		if(flagmouse==36) f36=2, stage4_values[6][3]=2;
		if(flagmouse==38) f38=2, stage4_values[8][3]=2;
		if(flagmouse==39) f39=2, stage4_values[9][3]=2;
		if(flagmouse==41) f41=2, stage4_values[1][4]=2;
		if(flagmouse==43) f43=2, stage4_values[3][4]=2;
		if(flagmouse==44) f44=2, stage4_values[4][4]=2;
		if(flagmouse==45) f45=2, stage4_values[5][4]=2;
		if(flagmouse==46) f46=2, stage4_values[6][4]=2;
		if(flagmouse==47) f47=2, stage4_values[7][4]=2;
		if(flagmouse==48) f48=2, stage4_values[8][4]=2;
		if(flagmouse==51) f51=2, stage4_values[1][5]=2;
		if(flagmouse==52) f52=2, stage4_values[2][5]=2;
		if(flagmouse==55) f55=2, stage4_values[5][5]=2;
		if(flagmouse==58) f58=2, stage4_values[8][5]=2;
		if(flagmouse==59) f59=2, stage4_values[9][5]=2;
		if(flagmouse==62) f62=2, stage4_values[2][6]=2;
		if(flagmouse==63) f63=2, stage4_values[3][6]=2;
		if(flagmouse==64) f64=2, stage4_values[4][6]=2;
		if(flagmouse==67) f67=2, stage4_values[7][6]=2;
		if(flagmouse==69) f69=2, stage4_values[9][6]=2;
		if(flagmouse==71) f71=2, stage4_values[1][7]=2;
		if(flagmouse==72) f72=2, stage4_values[2][7]=2;
		if(flagmouse==74) f74=2, stage4_values[4][7]=2;
		if(flagmouse==75) f75=2, stage4_values[5][7]=2;
		if(flagmouse==77) f77=2, stage4_values[7][7]=2;
		if(flagmouse==79) f79=2, stage4_values[9][7]=2;
		if(flagmouse==82) f82=2, stage4_values[2][8]=2;
		if(flagmouse==83) f83=2, stage4_values[3][8]=2;
		if(flagmouse==84) f84=2, stage4_values[4][8]=2;
		if(flagmouse==86) f86=2, stage4_values[6][8]=2;
		if(flagmouse==87) f87=2, stage4_values[7][8]=2;
		if(flagmouse==88) f88=2, stage4_values[8][8]=2;
		if(flagmouse==91) f91=2, stage4_values[1][9]=2;
		if(flagmouse==93) f93=2, stage4_values[3][9]=2;
		if(flagmouse==95) f95=2, stage4_values[5][9]=2;
		if(flagmouse==96) f96=2, stage4_values[6][9]=2;
		if(flagmouse==97) f97=2, stage4_values[7][9]=2;
		if(flagmouse==98) f98=2, stage4_values[8][9]=2;
		if(flagmouse==99) f99=2, stage4_values[9][9]=2;
	}

	if (key == '3')
	{
		if(flagmouse==11) f11=3, stage4_values[1][1]=3;
		if(flagmouse==12) f12=3, stage4_values[2][1]=3;
		if(flagmouse==13) f13=3, stage4_values[3][1]=3;
		if(flagmouse==14) f14=3, stage4_values[4][1]=3;
		if(flagmouse==15) f15=3, stage4_values[5][1]=3;
		if(flagmouse==17) f17=3, stage4_values[7][1]=3;
		if(flagmouse==19) f19=3, stage4_values[9][1]=3;
		if(flagmouse==22) f22=3, stage4_values[2][2]=3;
		if(flagmouse==23) f23=3, stage4_values[3][2]=3;
		if(flagmouse==24) f24=3, stage4_values[4][2]=3;
		if(flagmouse==26) f26=3, stage4_values[6][2]=3;
		if(flagmouse==27) f27=3, stage4_values[7][2]=3;
		if(flagmouse==28) f28=3, stage4_values[8][2]=3;
		if(flagmouse==31) f31=3, stage4_values[1][3]=3;
		if(flagmouse==33) f33=3, stage4_values[3][3]=3;
		if(flagmouse==35) f35=3, stage4_values[5][3]=3;
		if(flagmouse==36) f36=3, stage4_values[6][3]=3;
		if(flagmouse==38) f38=3, stage4_values[8][3]=3;
		if(flagmouse==39) f39=3, stage4_values[9][3]=3;
		if(flagmouse==41) f41=3, stage4_values[1][4]=3;
		if(flagmouse==43) f43=3, stage4_values[3][4]=3;
		if(flagmouse==44) f44=3, stage4_values[4][4]=3;
		if(flagmouse==45) f45=3, stage4_values[5][4]=3;
		if(flagmouse==46) f46=3, stage4_values[6][4]=3;
		if(flagmouse==47) f47=3, stage4_values[7][4]=3;
		if(flagmouse==48) f48=3, stage4_values[8][4]=3;
		if(flagmouse==51) f51=3, stage4_values[1][5]=3;
		if(flagmouse==52) f52=3, stage4_values[2][5]=3;
		if(flagmouse==55) f55=3, stage4_values[5][5]=3;
		if(flagmouse==58) f58=3, stage4_values[8][5]=3;
		if(flagmouse==59) f59=3, stage4_values[9][5]=3;
		if(flagmouse==62) f62=3, stage4_values[2][6]=3;
		if(flagmouse==63) f63=3, stage4_values[3][6]=3;
		if(flagmouse==64) f64=3, stage4_values[4][6]=3;
		if(flagmouse==67) f67=3, stage4_values[7][6]=3;
		if(flagmouse==69) f69=3, stage4_values[9][6]=3;
		if(flagmouse==71) f71=3, stage4_values[1][7]=3;
		if(flagmouse==72) f72=3, stage4_values[2][7]=3;
		if(flagmouse==74) f74=3, stage4_values[4][7]=3;
		if(flagmouse==75) f75=3, stage4_values[5][7]=3;
		if(flagmouse==77) f77=3, stage4_values[7][7]=3;
		if(flagmouse==79) f79=3, stage4_values[9][7]=3;
		if(flagmouse==82) f82=3, stage4_values[2][8]=3;
		if(flagmouse==83) f83=3, stage4_values[3][8]=3;
		if(flagmouse==84) f84=3, stage4_values[4][8]=3;
		if(flagmouse==86) f86=3, stage4_values[6][8]=3;
		if(flagmouse==87) f87=3, stage4_values[7][8]=3;
		if(flagmouse==88) f88=3, stage4_values[8][8]=3;
		if(flagmouse==91) f91=3, stage4_values[1][9]=3;
		if(flagmouse==93) f93=3, stage4_values[3][9]=3;
		if(flagmouse==95) f95=3, stage4_values[5][9]=3;
		if(flagmouse==96) f96=3, stage4_values[6][9]=3;
		if(flagmouse==97) f97=3, stage4_values[7][9]=3;
		if(flagmouse==98) f98=3, stage4_values[8][9]=3;
		if(flagmouse==99) f99=3, stage4_values[9][9]=3;
	}

	if (key == '4')
	{
		if(flagmouse==11) f11=4, stage4_values[1][1]=4;
		if(flagmouse==12) f12=4, stage4_values[2][1]=4;
		if(flagmouse==13) f13=4, stage4_values[3][1]=4;
		if(flagmouse==14) f14=4, stage4_values[4][1]=4;
		if(flagmouse==15) f15=4, stage4_values[5][1]=4;
		if(flagmouse==17) f17=4, stage4_values[7][1]=4;
		if(flagmouse==19) f19=4, stage4_values[9][1]=4;
		if(flagmouse==22) f22=4, stage4_values[2][2]=4;
		if(flagmouse==23) f23=4, stage4_values[3][2]=4;
		if(flagmouse==24) f24=4, stage4_values[4][2]=4;
		if(flagmouse==26) f26=4, stage4_values[6][2]=4;
		if(flagmouse==27) f27=4, stage4_values[7][2]=4;
		if(flagmouse==28) f28=4, stage4_values[8][2]=4;
		if(flagmouse==31) f31=4, stage4_values[1][3]=4;
		if(flagmouse==33) f33=4, stage4_values[3][3]=4;
		if(flagmouse==35) f35=4, stage4_values[5][3]=4;
		if(flagmouse==36) f36=4, stage4_values[6][3]=4;
		if(flagmouse==38) f38=4, stage4_values[8][3]=4;
		if(flagmouse==39) f39=4, stage4_values[9][3]=4;
		if(flagmouse==41) f41=4, stage4_values[1][4]=4;
		if(flagmouse==43) f43=4, stage4_values[3][4]=4;
		if(flagmouse==44) f44=4, stage4_values[4][4]=4;
		if(flagmouse==45) f45=4, stage4_values[5][4]=4;
		if(flagmouse==46) f46=4, stage4_values[6][4]=4;
		if(flagmouse==47) f47=4, stage4_values[7][4]=4;
		if(flagmouse==48) f48=4, stage4_values[8][4]=4;
		if(flagmouse==51) f51=4, stage4_values[1][5]=4;
		if(flagmouse==52) f52=4, stage4_values[2][5]=4;
		if(flagmouse==55) f55=4, stage4_values[5][5]=4;
		if(flagmouse==58) f58=4, stage4_values[8][5]=4;
		if(flagmouse==59) f59=4, stage4_values[9][5]=4;
		if(flagmouse==62) f62=4, stage4_values[2][6]=4;
		if(flagmouse==63) f63=4, stage4_values[3][6]=4;
		if(flagmouse==64) f64=4, stage4_values[4][6]=4;
		if(flagmouse==67) f67=4, stage4_values[7][6]=4;
		if(flagmouse==69) f69=4, stage4_values[9][6]=4;
		if(flagmouse==71) f71=4, stage4_values[1][7]=4;
		if(flagmouse==72) f72=4, stage4_values[2][7]=4;
		if(flagmouse==74) f74=4, stage4_values[4][7]=4;
		if(flagmouse==75) f75=4, stage4_values[5][7]=4;
		if(flagmouse==77) f77=4, stage4_values[7][7]=4;
		if(flagmouse==79) f79=4, stage4_values[9][7]=4;
		if(flagmouse==82) f82=4, stage4_values[2][8]=4;
		if(flagmouse==83) f83=4, stage4_values[3][8]=4;
		if(flagmouse==84) f84=4, stage4_values[4][8]=4;
		if(flagmouse==86) f86=4, stage4_values[6][8]=4;
		if(flagmouse==87) f87=4, stage4_values[7][8]=4;
		if(flagmouse==88) f88=4, stage4_values[8][8]=4;
		if(flagmouse==91) f91=4, stage4_values[1][9]=4;
		if(flagmouse==93) f93=4, stage4_values[3][9]=4;
		if(flagmouse==95) f95=4, stage4_values[5][9]=4;
		if(flagmouse==96) f96=4, stage4_values[6][9]=4;
		if(flagmouse==97) f97=4, stage4_values[7][9]=4;
		if(flagmouse==98) f98=4, stage4_values[8][9]=4;
		if(flagmouse==99) f99=4, stage4_values[9][9]=4;
	}
	if (key == '5')
	{
		if(flagmouse==11) f11=5, stage4_values[1][1]=5;
		if(flagmouse==12) f12=5, stage4_values[2][1]=5;
		if(flagmouse==13) f13=5, stage4_values[3][1]=5;
		if(flagmouse==14) f14=5, stage4_values[4][1]=5;
		if(flagmouse==15) f15=5, stage4_values[5][1]=5;
		if(flagmouse==17) f17=5, stage4_values[7][1]=5;
		if(flagmouse==19) f19=5, stage4_values[9][1]=5;
		if(flagmouse==22) f22=5, stage4_values[2][2]=5;
		if(flagmouse==23) f23=5, stage4_values[3][2]=5;
		if(flagmouse==24) f24=5, stage4_values[4][2]=5;
		if(flagmouse==26) f26=5, stage4_values[6][2]=5;
		if(flagmouse==27) f27=5, stage4_values[7][2]=5;
		if(flagmouse==28) f28=5, stage4_values[8][2]=5;
		if(flagmouse==31) f31=5, stage4_values[1][3]=5;
		if(flagmouse==33) f33=5, stage4_values[3][3]=5;
		if(flagmouse==35) f35=5, stage4_values[5][3]=5;
		if(flagmouse==36) f36=5, stage4_values[6][3]=5;
		if(flagmouse==38) f38=5, stage4_values[8][3]=5;
		if(flagmouse==39) f39=5, stage4_values[9][3]=5;
		if(flagmouse==41) f41=5, stage4_values[1][4]=5;
		if(flagmouse==43) f43=5, stage4_values[3][4]=5;
		if(flagmouse==44) f44=5, stage4_values[4][4]=5;
		if(flagmouse==45) f45=5, stage4_values[5][4]=5;
		if(flagmouse==46) f46=5, stage4_values[6][4]=5;
		if(flagmouse==47) f47=5, stage4_values[7][4]=5;
		if(flagmouse==48) f48=5, stage4_values[8][4]=5;
		if(flagmouse==51) f51=5, stage4_values[1][5]=5;
		if(flagmouse==52) f52=5, stage4_values[2][5]=5;
		if(flagmouse==55) f55=5, stage4_values[5][5]=5;
		if(flagmouse==58) f58=5, stage4_values[8][5]=5;
		if(flagmouse==59) f59=5, stage4_values[9][5]=5;
		if(flagmouse==62) f62=5, stage4_values[2][6]=5;
		if(flagmouse==63) f63=5, stage4_values[3][6]=5;
		if(flagmouse==64) f64=5, stage4_values[4][6]=5;
		if(flagmouse==67) f67=5, stage4_values[7][6]=5;
		if(flagmouse==69) f69=5, stage4_values[9][6]=5;
		if(flagmouse==71) f71=5, stage4_values[1][7]=5;
		if(flagmouse==72) f72=5, stage4_values[2][7]=5;
		if(flagmouse==74) f74=5, stage4_values[4][7]=5;
		if(flagmouse==75) f75=5, stage4_values[5][7]=5;
		if(flagmouse==77) f77=5, stage4_values[7][7]=5;
		if(flagmouse==79) f79=5, stage4_values[9][7]=5;
		if(flagmouse==82) f82=5, stage4_values[2][8]=5;
		if(flagmouse==83) f83=5, stage4_values[3][8]=5;
		if(flagmouse==84) f84=5, stage4_values[4][8]=5;
		if(flagmouse==86) f86=5, stage4_values[6][8]=5;
		if(flagmouse==87) f87=5, stage4_values[7][8]=5;
		if(flagmouse==88) f88=5, stage4_values[8][8]=5;
		if(flagmouse==91) f91=5, stage4_values[1][9]=5;
		if(flagmouse==93) f93=5, stage4_values[3][9]=5;
		if(flagmouse==95) f95=5, stage4_values[5][9]=5;
		if(flagmouse==96) f96=5, stage4_values[6][9]=5;
		if(flagmouse==97) f97=5, stage4_values[7][9]=5;
		if(flagmouse==98) f98=5, stage4_values[8][9]=5;
		if(flagmouse==99) f99=5, stage4_values[9][9]=5;
	}
	if (key == '6')
	{
		if(flagmouse==11) f11=6, stage4_values[1][1]=6;
		if(flagmouse==12) f12=6, stage4_values[2][1]=6;
		if(flagmouse==13) f13=6, stage4_values[3][1]=6;
		if(flagmouse==14) f14=6, stage4_values[4][1]=6;
		if(flagmouse==15) f15=6, stage4_values[5][1]=6;
		if(flagmouse==17) f17=6, stage4_values[7][1]=6;
		if(flagmouse==19) f19=6, stage4_values[9][1]=6;
		if(flagmouse==22) f22=6, stage4_values[2][2]=6;
		if(flagmouse==23) f23=6, stage4_values[3][2]=6;
		if(flagmouse==24) f24=6, stage4_values[4][2]=6;
		if(flagmouse==26) f26=6, stage4_values[6][2]=6;
		if(flagmouse==27) f27=6, stage4_values[7][2]=6;
		if(flagmouse==28) f28=6, stage4_values[8][2]=6;
		if(flagmouse==31) f31=6, stage4_values[1][3]=6;
		if(flagmouse==33) f33=6, stage4_values[3][3]=6;
		if(flagmouse==35) f35=6, stage4_values[5][3]=6;
		if(flagmouse==36) f36=6, stage4_values[6][3]=6;
		if(flagmouse==38) f38=6, stage4_values[8][3]=6;
		if(flagmouse==39) f39=6, stage4_values[9][3]=6;
		if(flagmouse==41) f41=6, stage4_values[1][4]=6;
		if(flagmouse==43) f43=6, stage4_values[3][4]=6;
		if(flagmouse==44) f44=6, stage4_values[4][4]=6;
		if(flagmouse==45) f45=6, stage4_values[5][4]=6;
		if(flagmouse==46) f46=6, stage4_values[6][4]=6;
		if(flagmouse==47) f47=6, stage4_values[7][4]=6;
		if(flagmouse==48) f48=6, stage4_values[8][4]=6;
		if(flagmouse==51) f51=6, stage4_values[1][5]=6;
		if(flagmouse==52) f52=6, stage4_values[2][5]=6;
		if(flagmouse==55) f55=6, stage4_values[5][5]=6;
		if(flagmouse==58) f58=6, stage4_values[8][5]=6;
		if(flagmouse==59) f59=6, stage4_values[9][5]=6;
		if(flagmouse==62) f62=6, stage4_values[2][6]=6;
		if(flagmouse==63) f63=6, stage4_values[3][6]=6;
		if(flagmouse==64) f64=6, stage4_values[4][6]=6;
		if(flagmouse==67) f67=6, stage4_values[7][6]=6;
		if(flagmouse==69) f69=6, stage4_values[9][6]=6;
		if(flagmouse==71) f71=6, stage4_values[1][7]=6;
		if(flagmouse==72) f72=6, stage4_values[2][7]=6;
		if(flagmouse==74) f74=6, stage4_values[4][7]=6;
		if(flagmouse==75) f75=6, stage4_values[5][7]=6;
		if(flagmouse==77) f77=6, stage4_values[7][7]=6;
		if(flagmouse==79) f79=6, stage4_values[9][7]=6;
		if(flagmouse==82) f82=6, stage4_values[2][8]=6;
		if(flagmouse==83) f83=6, stage4_values[3][8]=6;
		if(flagmouse==84) f84=6, stage4_values[4][8]=6;
		if(flagmouse==86) f86=6, stage4_values[6][8]=6;
		if(flagmouse==87) f87=6, stage4_values[7][8]=6;
		if(flagmouse==88) f88=6, stage4_values[8][8]=6;
		if(flagmouse==91) f91=6, stage4_values[1][9]=6;
		if(flagmouse==93) f93=6, stage4_values[3][9]=6;
		if(flagmouse==95) f95=6, stage4_values[5][9]=6;
		if(flagmouse==96) f96=6, stage4_values[6][9]=6;
		if(flagmouse==97) f97=6, stage4_values[7][9]=6;
		if(flagmouse==98) f98=6, stage4_values[8][9]=6;
		if(flagmouse==99) f99=6, stage4_values[9][9]=6;
	}
	if (key == '7')
	{
		if(flagmouse==11) f11=7, stage4_values[1][1]=7;
		if(flagmouse==12) f12=7, stage4_values[2][1]=7;
		if(flagmouse==13) f13=7, stage4_values[3][1]=7;
		if(flagmouse==14) f14=7, stage4_values[4][1]=7;
		if(flagmouse==15) f15=7, stage4_values[5][1]=7;
		if(flagmouse==17) f17=7, stage4_values[7][1]=7;
		if(flagmouse==19) f19=7, stage4_values[9][1]=7;
		if(flagmouse==22) f22=7, stage4_values[2][2]=7;
		if(flagmouse==23) f23=7, stage4_values[3][2]=7;
		if(flagmouse==24) f24=7, stage4_values[4][2]=7;
		if(flagmouse==26) f26=7, stage4_values[6][2]=7;
		if(flagmouse==27) f27=7, stage4_values[7][2]=7;
		if(flagmouse==28) f28=7, stage4_values[8][2]=7;
		if(flagmouse==31) f31=7, stage4_values[1][3]=7;
		if(flagmouse==33) f33=7, stage4_values[3][3]=7;
		if(flagmouse==35) f35=7, stage4_values[5][3]=7;
		if(flagmouse==36) f36=7, stage4_values[6][3]=7;
		if(flagmouse==38) f38=7, stage4_values[8][3]=7;
		if(flagmouse==39) f39=7, stage4_values[9][3]=7;
		if(flagmouse==41) f41=7, stage4_values[1][4]=7;
		if(flagmouse==43) f43=7, stage4_values[3][4]=7;
		if(flagmouse==44) f44=7, stage4_values[4][4]=7;
		if(flagmouse==45) f45=7, stage4_values[5][4]=7;
		if(flagmouse==46) f46=7, stage4_values[6][4]=7;
		if(flagmouse==47) f47=7, stage4_values[7][4]=7;
		if(flagmouse==48) f48=7, stage4_values[8][4]=7;
		if(flagmouse==51) f51=7, stage4_values[1][5]=7;
		if(flagmouse==52) f52=7, stage4_values[2][5]=7;
		if(flagmouse==55) f55=7, stage4_values[5][5]=7;
		if(flagmouse==58) f58=7, stage4_values[8][5]=7;
		if(flagmouse==59) f59=7, stage4_values[9][5]=7;
		if(flagmouse==62) f62=7, stage4_values[2][6]=7;
		if(flagmouse==63) f63=7, stage4_values[3][6]=7;
		if(flagmouse==64) f64=7, stage4_values[4][6]=7;
		if(flagmouse==67) f67=7, stage4_values[7][6]=7;
		if(flagmouse==69) f69=7, stage4_values[9][6]=7;
		if(flagmouse==71) f71=7, stage4_values[1][7]=7;
		if(flagmouse==72) f72=7, stage4_values[2][7]=7;
		if(flagmouse==74) f74=7, stage4_values[4][7]=7;
		if(flagmouse==75) f75=7, stage4_values[5][7]=7;
		if(flagmouse==77) f77=7, stage4_values[7][7]=7;
		if(flagmouse==79) f79=7, stage4_values[9][7]=7;
		if(flagmouse==82) f82=7, stage4_values[2][8]=7;
		if(flagmouse==83) f83=7, stage4_values[3][8]=7;
		if(flagmouse==84) f84=7, stage4_values[4][8]=7;
		if(flagmouse==86) f86=7, stage4_values[6][8]=7;
		if(flagmouse==87) f87=7, stage4_values[7][8]=7;
		if(flagmouse==88) f88=7, stage4_values[8][8]=7;
		if(flagmouse==91) f91=7, stage4_values[1][9]=7;
		if(flagmouse==93) f93=7, stage4_values[3][9]=7;
		if(flagmouse==95) f95=7, stage4_values[5][9]=7;
		if(flagmouse==96) f96=7, stage4_values[6][9]=7;
		if(flagmouse==97) f97=7, stage4_values[7][9]=7;
		if(flagmouse==98) f98=7, stage4_values[8][9]=7;
		if(flagmouse==99) f99=7, stage4_values[9][9]=7;
	}
	if (key == '8')
	{
		if(flagmouse==11) f11=8, stage4_values[1][1]=8;
		if(flagmouse==12) f12=8, stage4_values[2][1]=8;
		if(flagmouse==13) f13=8, stage4_values[3][1]=8;
		if(flagmouse==14) f14=8, stage4_values[4][1]=8;
		if(flagmouse==15) f15=8, stage4_values[5][1]=8;
		if(flagmouse==17) f17=8, stage4_values[7][1]=8;
		if(flagmouse==19) f19=8, stage4_values[9][1]=8;
		if(flagmouse==22) f22=8, stage4_values[2][2]=8;
		if(flagmouse==23) f23=8, stage4_values[3][2]=8;
		if(flagmouse==24) f24=8, stage4_values[4][2]=8;
		if(flagmouse==26) f26=8, stage4_values[6][2]=8;
		if(flagmouse==27) f27=8, stage4_values[7][2]=8;
		if(flagmouse==28) f28=8, stage4_values[8][2]=8;
		if(flagmouse==31) f31=8, stage4_values[1][3]=8;
		if(flagmouse==33) f33=8, stage4_values[3][3]=8;
		if(flagmouse==35) f35=8, stage4_values[5][3]=8;
		if(flagmouse==36) f36=8, stage4_values[6][3]=8;
		if(flagmouse==38) f38=8, stage4_values[8][3]=8;
		if(flagmouse==39) f39=8, stage4_values[9][3]=8;
		if(flagmouse==41) f41=8, stage4_values[1][4]=8;
		if(flagmouse==43) f43=8, stage4_values[3][4]=8;
		if(flagmouse==44) f44=8, stage4_values[4][4]=8;
		if(flagmouse==45) f45=8, stage4_values[5][4]=8;
		if(flagmouse==46) f46=8, stage4_values[6][4]=8;
		if(flagmouse==47) f47=8, stage4_values[7][4]=8;
		if(flagmouse==48) f48=8, stage4_values[8][4]=8;
		if(flagmouse==51) f51=8, stage4_values[1][5]=8;
		if(flagmouse==52) f52=8, stage4_values[2][5]=8;
		if(flagmouse==55) f55=8, stage4_values[5][5]=8;
		if(flagmouse==58) f58=8, stage4_values[8][5]=8;
		if(flagmouse==59) f59=8, stage4_values[9][5]=8;
		if(flagmouse==62) f62=8, stage4_values[2][6]=8;
		if(flagmouse==63) f63=8, stage4_values[3][6]=8;
		if(flagmouse==64) f64=8, stage4_values[4][6]=8;
		if(flagmouse==67) f67=8, stage4_values[7][6]=8;
		if(flagmouse==69) f69=8, stage4_values[9][6]=8;
		if(flagmouse==71) f71=8, stage4_values[1][7]=8;
		if(flagmouse==72) f72=8, stage4_values[2][7]=8;
		if(flagmouse==74) f74=8, stage4_values[4][7]=8;
		if(flagmouse==75) f75=8, stage4_values[5][7]=8;
		if(flagmouse==77) f77=8, stage4_values[7][7]=8;
		if(flagmouse==79) f79=8, stage4_values[9][7]=8;
		if(flagmouse==82) f82=8, stage4_values[2][8]=8;
		if(flagmouse==83) f83=8, stage4_values[3][8]=8;
		if(flagmouse==84) f84=8, stage4_values[4][8]=8;
		if(flagmouse==86) f86=8, stage4_values[6][8]=8;
		if(flagmouse==87) f87=8, stage4_values[7][8]=8;
		if(flagmouse==88) f88=8, stage4_values[8][8]=8;
		if(flagmouse==91) f91=8, stage4_values[1][9]=8;
		if(flagmouse==93) f93=8, stage4_values[3][9]=8;
		if(flagmouse==95) f95=8, stage4_values[5][9]=8;
		if(flagmouse==96) f96=8, stage4_values[6][9]=8;
		if(flagmouse==97) f97=8, stage4_values[7][9]=8;
		if(flagmouse==98) f98=8, stage4_values[8][9]=8;
		if(flagmouse==99) f99=8, stage4_values[9][9]=8;
	}

	if (key == '9')
	{
		if(flagmouse==11) f11=9, stage4_values[1][1]=9;
		if(flagmouse==12) f12=9, stage4_values[2][1]=9;
		if(flagmouse==13) f13=9, stage4_values[3][1]=9;
		if(flagmouse==14) f14=9, stage4_values[4][1]=9;
		if(flagmouse==15) f15=9, stage4_values[5][1]=9;
		if(flagmouse==17) f17=9, stage4_values[7][1]=9;
		if(flagmouse==19) f19=9, stage4_values[9][1]=9;
		if(flagmouse==22) f22=9, stage4_values[2][2]=9;
		if(flagmouse==23) f23=9, stage4_values[3][2]=9;
		if(flagmouse==24) f24=9, stage4_values[4][2]=9;
		if(flagmouse==26) f26=9, stage4_values[6][2]=9;
		if(flagmouse==27) f27=9, stage4_values[7][2]=9;
		if(flagmouse==28) f28=9, stage4_values[8][2]=9;
		if(flagmouse==31) f31=9, stage4_values[1][3]=9;
		if(flagmouse==33) f33=9, stage4_values[3][3]=9;
		if(flagmouse==35) f35=9, stage4_values[5][3]=9;
		if(flagmouse==36) f36=9, stage4_values[6][3]=9;
		if(flagmouse==38) f38=9, stage4_values[8][3]=9;
		if(flagmouse==39) f39=9, stage4_values[9][3]=9;
		if(flagmouse==41) f41=9, stage4_values[1][4]=9;
		if(flagmouse==43) f43=9, stage4_values[3][4]=9;
		if(flagmouse==44) f44=9, stage4_values[4][4]=9;
		if(flagmouse==45) f45=9, stage4_values[5][4]=9;
		if(flagmouse==46) f46=9, stage4_values[6][4]=9;
		if(flagmouse==47) f47=9, stage4_values[7][4]=9;
		if(flagmouse==48) f48=9, stage4_values[8][4]=9;
		if(flagmouse==51) f51=9, stage4_values[1][5]=9;
		if(flagmouse==52) f52=9, stage4_values[2][5]=9;
		if(flagmouse==55) f55=9, stage4_values[5][5]=9;
		if(flagmouse==58) f58=9, stage4_values[8][5]=9;
		if(flagmouse==59) f59=9, stage4_values[9][5]=9;
		if(flagmouse==62) f62=9, stage4_values[2][6]=9;
		if(flagmouse==63) f63=9, stage4_values[3][6]=9;
		if(flagmouse==64) f64=9, stage4_values[4][6]=9;
		if(flagmouse==67) f67=9, stage4_values[7][6]=9;
		if(flagmouse==69) f69=9, stage4_values[9][6]=9;
		if(flagmouse==71) f71=9, stage4_values[1][7]=9;
		if(flagmouse==72) f72=9, stage4_values[2][7]=9;
		if(flagmouse==74) f74=9, stage4_values[4][7]=9;
		if(flagmouse==75) f75=9, stage4_values[5][7]=9;
		if(flagmouse==77) f77=9, stage4_values[7][7]=9;
		if(flagmouse==79) f79=9, stage4_values[9][7]=9;
		if(flagmouse==82) f82=9, stage4_values[2][8]=9;
		if(flagmouse==83) f83=9, stage4_values[3][8]=9;
		if(flagmouse==84) f84=9, stage4_values[4][8]=9;
		if(flagmouse==86) f86=9, stage4_values[6][8]=9;
		if(flagmouse==87) f87=9, stage4_values[7][8]=9;
		if(flagmouse==88) f88=9, stage4_values[8][8]=9;
		if(flagmouse==91) f91=9, stage4_values[1][9]=9;
		if(flagmouse==93) f93=9, stage4_values[3][9]=9;
		if(flagmouse==95) f95=9, stage4_values[5][9]=9;
		if(flagmouse==96) f96=9, stage4_values[6][9]=9;
		if(flagmouse==97) f97=9, stage4_values[7][9]=9;
		if(flagmouse==98) f98=9, stage4_values[8][9]=9;
		if(flagmouse==99) f99=9, stage4_values[9][9]=9;
	}

	if(key=='e')
	{
		if(flagmouse==11) f11=100, stage4_values[1][1]=0;
		if(flagmouse==12) f12=100, stage4_values[2][1]=0;
		if(flagmouse==13) f13=100, stage4_values[3][1]=0;
		if(flagmouse==14) f14=100, stage4_values[4][1]=0;
		if(flagmouse==15) f15=100, stage4_values[5][1]=0;
		if(flagmouse==16) f16=100, stage4_values[6][1]=0;
		if(flagmouse==17) f17=100, stage4_values[7][1]=0;
		if(flagmouse==18) f18=100, stage4_values[8][1]=0;
		if(flagmouse==19) f19=100, stage4_values[9][1]=0;
		if(flagmouse==21) f21=100, stage4_values[1][2]=0;
		if(flagmouse==22) f22=100, stage4_values[2][2]=0;
		if(flagmouse==23) f23=100, stage4_values[3][2]=0;
		if(flagmouse==24) f24=100, stage4_values[4][2]=0;
		if(flagmouse==25) f25=100, stage4_values[5][2]=0;
		if(flagmouse==26) f26=100, stage4_values[6][2]=0;
		if(flagmouse==27) f27=100, stage4_values[7][2]=0;
		if(flagmouse==28) f28=100, stage4_values[8][2]=0;
		if(flagmouse==29) f29=100, stage4_values[9][2]=0;
		if(flagmouse==31) f31=100, stage4_values[1][3]=0;
		if(flagmouse==32) f32=100, stage4_values[2][3]=0;
		if(flagmouse==33) f33=100, stage4_values[3][3]=0;
		if(flagmouse==34) f34=100, stage4_values[4][3]=0;
		if(flagmouse==35) f35=100, stage4_values[5][3]=0;
		if(flagmouse==36) f36=100, stage4_values[6][3]=0;
		if(flagmouse==37) f37=100, stage4_values[7][3]=0;
		if(flagmouse==38) f38=100, stage4_values[8][3]=0;
		if(flagmouse==39) f39=100, stage4_values[9][3]=0;
		if(flagmouse==41) f41=100, stage4_values[1][4]=0;
		if(flagmouse==42) f42=100, stage4_values[2][4]=0;
		if(flagmouse==43) f43=100, stage4_values[3][4]=0;
		if(flagmouse==44) f44=100, stage4_values[4][4]=0;
		if(flagmouse==45) f45=100, stage4_values[5][4]=0;
		if(flagmouse==46) f46=100, stage4_values[6][4]=0;
		if(flagmouse==47) f47=100, stage4_values[7][4]=0;
		if(flagmouse==48) f48=100, stage4_values[8][4]=0;
		if(flagmouse==49) f49=100, stage4_values[9][4]=0;
		if(flagmouse==51) f51=100, stage4_values[1][5]=0;
		if(flagmouse==52) f52=100, stage4_values[2][5]=0;
		if(flagmouse==53) f53=100, stage4_values[3][5]=0;
		if(flagmouse==54) f54=100, stage4_values[4][5]=0;
		if(flagmouse==55) f55=100, stage4_values[5][5]=0;
		if(flagmouse==56) f56=100, stage4_values[6][5]=0;
		if(flagmouse==57) f57=100, stage4_values[7][5]=0;
		if(flagmouse==58) f58=100, stage4_values[8][5]=0;
		if(flagmouse==59) f59=100, stage4_values[9][5]=0;
		if(flagmouse==61) f61=100, stage4_values[1][6]=0;
		if(flagmouse==62) f62=100, stage4_values[2][6]=0;
		if(flagmouse==63) f63=100, stage4_values[3][6]=0;
		if(flagmouse==64) f64=100, stage4_values[4][6]=0;
		if(flagmouse==65) f65=100, stage4_values[5][6]=0;
		if(flagmouse==66) f66=100, stage4_values[6][6]=0;
		if(flagmouse==67) f67=100, stage4_values[7][6]=0;
		if(flagmouse==68) f68=100, stage4_values[8][6]=0;
		if(flagmouse==69) f69=100, stage4_values[9][6]=0;
		if(flagmouse==71) f71=100, stage4_values[1][7]=0;
		if(flagmouse==72) f72=100, stage4_values[2][7]=0;
		if(flagmouse==73) f73=100, stage4_values[3][7]=0;
		if(flagmouse==74) f74=100, stage4_values[4][7]=0;
		if(flagmouse==75) f75=100, stage4_values[5][7]=0;
		if(flagmouse==76) f76=100, stage4_values[6][7]=0;
		if(flagmouse==77) f77=100, stage4_values[7][7]=0;
		if(flagmouse==78) f78=100, stage4_values[8][7]=0;
		if(flagmouse==79) f79=100, stage4_values[9][7]=0;
		if(flagmouse==81) f81=100, stage4_values[1][8]=0;
		if(flagmouse==82) f82=100, stage4_values[2][8]=0;
		if(flagmouse==83) f83=100, stage4_values[3][8]=0;
		if(flagmouse==84) f84=100, stage4_values[4][8]=0;
		if(flagmouse==85) f85=100, stage4_values[5][8]=0;
		if(flagmouse==86) f86=100, stage4_values[6][8]=0;
		if(flagmouse==87) f87=100, stage4_values[7][8]=0;
		if(flagmouse==88) f88=100, stage4_values[8][8]=0;
		if(flagmouse==89) f89=100, stage4_values[9][8]=0;
		if(flagmouse==91) f91=100, stage4_values[1][9]=0;
		if(flagmouse==92) f92=100, stage4_values[2][9]=0;
		if(flagmouse==93) f93=100, stage4_values[3][9]=0;
		if(flagmouse==94) f94=100, stage4_values[4][9]=0;
		if(flagmouse==95) f95=100, stage4_values[5][9]=0;
		if(flagmouse==96) f96=100, stage4_values[6][9]=0;
		if(flagmouse==97) f97=100, stage4_values[7][9]=0;
		if(flagmouse==98) f98=100, stage4_values[8][9]=0;
		if(flagmouse==99) f99=100, stage4_values[9][9]=0;
	}
	}

	if(page7==1)
	{
		if (key == '1')
	{
		if(flagmouse==11) f11=1, stage3_values[1][1]=1;
		if(flagmouse==13) f13=1, stage3_values[3][1]=1;
		if(flagmouse==14) f14=1, stage3_values[4][1]=1;
		if(flagmouse==15) f15=1, stage3_values[5][1]=1;
		if(flagmouse==16) f16=1, stage3_values[6][1]=1;
		if(flagmouse==17) f17=1, stage3_values[7][1]=1;
		if(flagmouse==18) f18=1, stage3_values[8][1]=1;
		if(flagmouse==19) f19=1, stage3_values[9][1]=1;
		if(flagmouse==21) f21=1, stage3_values[1][2]=1;
		if(flagmouse==22) f22=1, stage3_values[2][2]=1;
		if(flagmouse==23) f23=1, stage3_values[3][2]=1;
		if(flagmouse==24) f24=1, stage3_values[4][2]=1;
		if(flagmouse==25) f25=1, stage3_values[5][2]=1;
		if(flagmouse==26) f26=1, stage3_values[6][2]=1;
		if(flagmouse==27) f27=1, stage3_values[7][2]=1;
		if(flagmouse==28) f28=1, stage3_values[8][2]=1;
		if(flagmouse==31) f31=1, stage3_values[1][3]=1;
		if(flagmouse==32) f32=1, stage3_values[2][3]=1;
		if(flagmouse==33) f33=1, stage3_values[3][3]=1;
		if(flagmouse==34) f34=1, stage3_values[4][3]=1;
		if(flagmouse==35) f35=1, stage3_values[5][3]=1;
		if(flagmouse==36) f36=1, stage3_values[6][3]=1;
		if(flagmouse==37) f37=1, stage3_values[7][3]=1;
		if(flagmouse==39) f39=1, stage3_values[9][3]=1;
		if(flagmouse==42) f42=1, stage3_values[2][4]=1;
		if(flagmouse==44) f44=1, stage3_values[4][4]=1;
		if(flagmouse==46) f46=1, stage3_values[6][4]=1;
		if(flagmouse==47) f47=1, stage3_values[7][4]=1;
		if(flagmouse==48) f48=1, stage3_values[8][4]=1;
		if(flagmouse==49) f49=1, stage3_values[9][4]=1;
		if(flagmouse==51) f51=1, stage3_values[1][5]=1;
		if(flagmouse==52) f52=1, stage3_values[2][5]=1;
		if(flagmouse==54) f54=1, stage3_values[4][5]=1;
		if(flagmouse==55) f55=1, stage3_values[5][5]=1;
		if(flagmouse==56) f56=1, stage3_values[6][5]=1;
		if(flagmouse==58) f58=1, stage3_values[8][5]=1;
		if(flagmouse==59) f59=1, stage3_values[9][5]=1;
		if(flagmouse==61) f61=1, stage3_values[1][6]=1;
		if(flagmouse==62) f62=1, stage3_values[2][6]=1;
		if(flagmouse==63) f63=1, stage3_values[3][6]=1;
		if(flagmouse==64) f64=1, stage3_values[4][6]=1;
		if(flagmouse==66) f66=1, stage3_values[6][6]=1;
		if(flagmouse==68) f68=1, stage3_values[8][6]=1;
		if(flagmouse==69) f69=1, stage3_values[9][6]=1;
		if(flagmouse==71) f71=1, stage3_values[1][7]=1;
		if(flagmouse==72) f72=1, stage3_values[2][7]=1;
		if(flagmouse==74) f74=1, stage3_values[4][7]=1;
		if(flagmouse==75) f75=1, stage3_values[5][7]=1;
		if(flagmouse==77) f77=1, stage3_values[7][7]=1;
		if(flagmouse==78) f78=1, stage3_values[8][7]=1;
		if(flagmouse==81) f81=1, stage3_values[1][8]=1;
		if(flagmouse==82) f82=1, stage3_values[2][8]=1;
		if(flagmouse==83) f83=1, stage3_values[3][8]=1;
		if(flagmouse==84) f84=1, stage3_values[4][8]=1;
		if(flagmouse==85) f85=1, stage3_values[5][8]=1;
		if(flagmouse==87) f87=1, stage3_values[7][8]=1;
		if(flagmouse==89) f89=1, stage3_values[9][8]=1;
		if(flagmouse==91) f91=1, stage3_values[1][9]=1;
		if(flagmouse==92) f92=1, stage3_values[2][9]=1;
		if(flagmouse==93) f93=1, stage3_values[3][9]=1;
		if(flagmouse==95) f95=1, stage3_values[5][9]=1;
		if(flagmouse==97) f97=1, stage3_values[7][9]=1;
		if(flagmouse==98) f98=1, stage3_values[8][9]=1;
		if(flagmouse==99) f99=1, stage3_values[9][9]=1;
	}
	
	if (key == '2')
	{
		if(flagmouse==11) f11=2, stage3_values[1][1]=2;
		if(flagmouse==13) f13=2, stage3_values[3][1]=2;
		if(flagmouse==14) f14=2, stage3_values[4][1]=2;
		if(flagmouse==15) f15=2, stage3_values[5][1]=2;
		if(flagmouse==16) f16=2, stage3_values[6][1]=2;
		if(flagmouse==17) f17=2, stage3_values[7][1]=2;
		if(flagmouse==18) f18=2, stage3_values[8][1]=2;
		if(flagmouse==19) f19=2, stage3_values[9][1]=2;
		if(flagmouse==21) f21=2, stage3_values[1][2]=2;
		if(flagmouse==22) f22=2, stage3_values[2][2]=2;
		if(flagmouse==23) f23=2, stage3_values[3][2]=2;
		if(flagmouse==24) f24=2, stage3_values[4][2]=2;
		if(flagmouse==25) f25=2, stage3_values[5][2]=2;
		if(flagmouse==26) f26=2, stage3_values[6][2]=2;
		if(flagmouse==27) f27=2, stage3_values[7][2]=2;
		if(flagmouse==28) f28=2, stage3_values[8][2]=2;
		if(flagmouse==31) f31=2, stage3_values[1][3]=2;
		if(flagmouse==32) f32=2, stage3_values[2][3]=2;
		if(flagmouse==33) f33=2, stage3_values[3][3]=2;
		if(flagmouse==34) f34=2, stage3_values[4][3]=2;
		if(flagmouse==35) f35=2, stage3_values[5][3]=2;
		if(flagmouse==36) f36=2, stage3_values[6][3]=2;
		if(flagmouse==37) f37=2, stage3_values[7][3]=2;
		if(flagmouse==39) f39=2, stage3_values[9][3]=2;
		if(flagmouse==42) f42=2, stage3_values[2][4]=2;
		if(flagmouse==44) f44=2, stage3_values[4][4]=2;
		if(flagmouse==46) f46=2, stage3_values[6][4]=2;
		if(flagmouse==47) f47=2, stage3_values[7][4]=2;
		if(flagmouse==48) f48=2, stage3_values[8][4]=2;
		if(flagmouse==49) f49=2, stage3_values[9][4]=2;
		if(flagmouse==51) f51=2, stage3_values[1][5]=2;
		if(flagmouse==52) f52=2, stage3_values[2][5]=2;
		if(flagmouse==54) f54=2, stage3_values[4][5]=2;
		if(flagmouse==55) f55=2, stage3_values[5][5]=2;
		if(flagmouse==56) f56=2, stage3_values[6][5]=2;
		if(flagmouse==58) f58=2, stage3_values[8][5]=2;
		if(flagmouse==59) f59=2, stage3_values[9][5]=2;
		if(flagmouse==61) f61=2, stage3_values[1][6]=2;
		if(flagmouse==62) f62=2, stage3_values[2][6]=2;
		if(flagmouse==63) f63=2, stage3_values[3][6]=2;
		if(flagmouse==64) f64=2, stage3_values[4][6]=2;
		if(flagmouse==66) f66=2, stage3_values[6][6]=2;
		if(flagmouse==68) f68=2, stage3_values[8][6]=2;
		if(flagmouse==69) f69=2, stage3_values[9][6]=2;
		if(flagmouse==71) f71=2, stage3_values[1][7]=2;
		if(flagmouse==72) f72=2, stage3_values[2][7]=2;
		if(flagmouse==74) f74=2, stage3_values[4][7]=2;
		if(flagmouse==75) f75=2, stage3_values[5][7]=2;
		if(flagmouse==77) f77=2, stage3_values[7][7]=2;
		if(flagmouse==78) f78=2, stage3_values[8][7]=2;
		if(flagmouse==81) f81=2, stage3_values[1][8]=2;
		if(flagmouse==82) f82=2, stage3_values[2][8]=2;
		if(flagmouse==83) f83=2, stage3_values[3][8]=2;
		if(flagmouse==84) f84=2, stage3_values[4][8]=2;
		if(flagmouse==85) f85=2, stage3_values[5][8]=2;
		if(flagmouse==87) f87=2, stage3_values[7][8]=2;
		if(flagmouse==89) f89=2, stage3_values[9][8]=2;
		if(flagmouse==91) f91=2, stage3_values[1][9]=2;
		if(flagmouse==92) f92=2, stage3_values[2][9]=2;
		if(flagmouse==93) f93=2, stage3_values[3][9]=2;
		if(flagmouse==95) f95=2, stage3_values[5][9]=2;
		if(flagmouse==97) f97=2, stage3_values[7][9]=2;
		if(flagmouse==98) f98=2, stage3_values[8][9]=2;
		if(flagmouse==99) f99=2, stage3_values[9][9]=2;
	}

	if (key == '3')
	{
		if(flagmouse==11) f11=3, stage3_values[1][1]=3;
		if(flagmouse==13) f13=3, stage3_values[3][1]=3;
		if(flagmouse==14) f14=3, stage3_values[4][1]=3;
		if(flagmouse==15) f15=3, stage3_values[5][1]=3;
		if(flagmouse==16) f16=3, stage3_values[6][1]=3;
		if(flagmouse==17) f17=3, stage3_values[7][1]=3;
		if(flagmouse==18) f18=3, stage3_values[8][1]=3;
		if(flagmouse==19) f19=3, stage3_values[9][1]=3;
		if(flagmouse==21) f21=3, stage3_values[1][2]=3;
		if(flagmouse==22) f22=3, stage3_values[2][2]=3;
		if(flagmouse==23) f23=3, stage3_values[3][2]=3;
		if(flagmouse==24) f24=3, stage3_values[4][2]=3;
		if(flagmouse==25) f25=3, stage3_values[5][2]=3;
		if(flagmouse==26) f26=3, stage3_values[6][2]=3;
		if(flagmouse==27) f27=3, stage3_values[7][2]=3;
		if(flagmouse==28) f28=3, stage3_values[8][2]=3;
		if(flagmouse==31) f31=3, stage3_values[1][3]=3;
		if(flagmouse==32) f32=3, stage3_values[2][3]=3;
		if(flagmouse==33) f33=3, stage3_values[3][3]=3;
		if(flagmouse==34) f34=3, stage3_values[4][3]=3;
		if(flagmouse==35) f35=3, stage3_values[5][3]=3;
		if(flagmouse==36) f36=3, stage3_values[6][3]=3;
		if(flagmouse==37) f37=3, stage3_values[7][3]=3;
		if(flagmouse==39) f39=3, stage3_values[9][3]=3;
		if(flagmouse==42) f42=3, stage3_values[2][4]=3;
		if(flagmouse==44) f44=3, stage3_values[4][4]=3;
		if(flagmouse==46) f46=3, stage3_values[6][4]=3;
		if(flagmouse==47) f47=3, stage3_values[7][4]=3;
		if(flagmouse==48) f48=3, stage3_values[8][4]=3;
		if(flagmouse==49) f49=3, stage3_values[9][4]=3;
		if(flagmouse==51) f51=3, stage3_values[1][5]=3;
		if(flagmouse==52) f52=3, stage3_values[2][5]=3;
		if(flagmouse==54) f54=3, stage3_values[4][5]=3;
		if(flagmouse==55) f55=3, stage3_values[5][5]=3;
		if(flagmouse==56) f56=3, stage3_values[6][5]=3;
		if(flagmouse==58) f58=3, stage3_values[8][5]=3;
		if(flagmouse==59) f59=3, stage3_values[9][5]=3;
		if(flagmouse==61) f61=3, stage3_values[1][6]=3;
		if(flagmouse==62) f62=3, stage3_values[2][6]=3;
		if(flagmouse==63) f63=3, stage3_values[3][6]=3;
		if(flagmouse==64) f64=3, stage3_values[4][6]=3;
		if(flagmouse==66) f66=3, stage3_values[6][6]=3;
		if(flagmouse==68) f68=3, stage3_values[8][6]=3;
		if(flagmouse==69) f69=3, stage3_values[9][6]=3;
		if(flagmouse==71) f71=3, stage3_values[1][7]=3;
		if(flagmouse==72) f72=3, stage3_values[2][7]=3;
		if(flagmouse==74) f74=3, stage3_values[4][7]=3;
		if(flagmouse==75) f75=3, stage3_values[5][7]=3;
		if(flagmouse==77) f77=3, stage3_values[7][7]=3;
		if(flagmouse==78) f78=3, stage3_values[8][7]=3;
		if(flagmouse==81) f81=3, stage3_values[1][8]=3;
		if(flagmouse==82) f82=3, stage3_values[2][8]=3;
		if(flagmouse==83) f83=3, stage3_values[3][8]=3;
		if(flagmouse==84) f84=3, stage3_values[4][8]=3;
		if(flagmouse==85) f85=3, stage3_values[5][8]=3;
		if(flagmouse==87) f87=3, stage3_values[7][8]=3;
		if(flagmouse==89) f89=3, stage3_values[9][8]=3;
		if(flagmouse==91) f91=3, stage3_values[1][9]=3;
		if(flagmouse==92) f92=3, stage3_values[2][9]=3;
		if(flagmouse==93) f93=3, stage3_values[3][9]=3;
		if(flagmouse==95) f95=3, stage3_values[5][9]=3;
		if(flagmouse==97) f97=3, stage3_values[7][9]=3;
		if(flagmouse==98) f98=3, stage3_values[8][9]=3;
		if(flagmouse==99) f99=3, stage3_values[9][9]=3;
	}

	if (key == '4')
	{
		if(flagmouse==11) f11=4, stage3_values[1][1]=4;
		if(flagmouse==13) f13=4, stage3_values[3][1]=4;
		if(flagmouse==14) f14=4, stage3_values[4][1]=4;
		if(flagmouse==15) f15=4, stage3_values[5][1]=4;
		if(flagmouse==16) f16=4, stage3_values[6][1]=4;
		if(flagmouse==17) f17=4, stage3_values[7][1]=4;
		if(flagmouse==18) f18=4, stage3_values[8][1]=4;
		if(flagmouse==19) f19=4, stage3_values[9][1]=4;
		if(flagmouse==21) f21=4, stage3_values[1][2]=4;
		if(flagmouse==22) f22=4, stage3_values[2][2]=4;
		if(flagmouse==23) f23=4, stage3_values[3][2]=4;
		if(flagmouse==24) f24=4, stage3_values[4][2]=4;
		if(flagmouse==25) f25=4, stage3_values[5][2]=4;
		if(flagmouse==26) f26=4, stage3_values[6][2]=4;
		if(flagmouse==27) f27=4, stage3_values[7][2]=4;
		if(flagmouse==28) f28=4, stage3_values[8][2]=4;
		if(flagmouse==31) f31=4, stage3_values[1][3]=4;
		if(flagmouse==32) f32=4, stage3_values[2][3]=4;
		if(flagmouse==33) f33=4, stage3_values[3][3]=4;
		if(flagmouse==34) f34=4, stage3_values[4][3]=4;
		if(flagmouse==35) f35=4, stage3_values[5][3]=4;
		if(flagmouse==36) f36=4, stage3_values[6][3]=4;
		if(flagmouse==37) f37=4, stage3_values[7][3]=4;
		if(flagmouse==39) f39=4, stage3_values[9][3]=4;
		if(flagmouse==42) f42=4, stage3_values[2][4]=4;
		if(flagmouse==44) f44=4, stage3_values[4][4]=4;
		if(flagmouse==46) f46=4, stage3_values[6][4]=4;
		if(flagmouse==47) f47=4, stage3_values[7][4]=4;
		if(flagmouse==48) f48=4, stage3_values[8][4]=4;
		if(flagmouse==49) f49=4, stage3_values[9][4]=4;
		if(flagmouse==51) f51=4, stage3_values[1][5]=4;
		if(flagmouse==52) f52=4, stage3_values[2][5]=4;
		if(flagmouse==54) f54=4, stage3_values[4][5]=4;
		if(flagmouse==55) f55=4, stage3_values[5][5]=4;
		if(flagmouse==56) f56=4, stage3_values[6][5]=4;
		if(flagmouse==58) f58=4, stage3_values[8][5]=4;
		if(flagmouse==59) f59=4, stage3_values[9][5]=4;
		if(flagmouse==61) f61=4, stage3_values[1][6]=4;
		if(flagmouse==62) f62=4, stage3_values[2][6]=4;
		if(flagmouse==63) f63=4, stage3_values[3][6]=4;
		if(flagmouse==64) f64=4, stage3_values[4][6]=4;
		if(flagmouse==66) f66=4, stage3_values[6][6]=4;
		if(flagmouse==68) f68=4, stage3_values[8][6]=4;
		if(flagmouse==69) f69=4, stage3_values[9][6]=4;
		if(flagmouse==71) f71=4, stage3_values[1][7]=4;
		if(flagmouse==72) f72=4, stage3_values[2][7]=4;
		if(flagmouse==74) f74=4, stage3_values[4][7]=4;
		if(flagmouse==75) f75=4, stage3_values[5][7]=4;
		if(flagmouse==77) f77=4, stage3_values[7][7]=4;
		if(flagmouse==78) f78=4, stage3_values[8][7]=4;
		if(flagmouse==81) f81=4, stage3_values[1][8]=4;
		if(flagmouse==82) f82=4, stage3_values[2][8]=4;
		if(flagmouse==83) f83=4, stage3_values[3][8]=4;
		if(flagmouse==84) f84=4, stage3_values[4][8]=4;
		if(flagmouse==85) f85=4, stage3_values[5][8]=4;
		if(flagmouse==87) f87=4, stage3_values[7][8]=4;
		if(flagmouse==89) f89=4, stage3_values[9][8]=4;
		if(flagmouse==91) f91=4, stage3_values[1][9]=4;
		if(flagmouse==92) f92=4, stage3_values[2][9]=4;
		if(flagmouse==93) f93=4, stage3_values[3][9]=4;
		if(flagmouse==95) f95=4, stage3_values[5][9]=4;
		if(flagmouse==97) f97=4, stage3_values[7][9]=4;
		if(flagmouse==98) f98=4, stage3_values[8][9]=4;
		if(flagmouse==99) f99=4, stage3_values[9][9]=4;
	}
	if (key == '5')
	{
		if(flagmouse==11) f11=5, stage3_values[1][1]=5;
		if(flagmouse==13) f13=5, stage3_values[3][1]=5;
		if(flagmouse==14) f14=5, stage3_values[4][1]=5;
		if(flagmouse==15) f15=5, stage3_values[5][1]=5;
		if(flagmouse==16) f16=5, stage3_values[6][1]=5;
		if(flagmouse==17) f17=5, stage3_values[7][1]=5;
		if(flagmouse==18) f18=5, stage3_values[8][1]=5;
		if(flagmouse==19) f19=5, stage3_values[9][1]=5;
		if(flagmouse==21) f21=5, stage3_values[1][2]=5;
		if(flagmouse==22) f22=5, stage3_values[2][2]=5;
		if(flagmouse==23) f23=5, stage3_values[3][2]=5;
		if(flagmouse==24) f24=5, stage3_values[4][2]=5;
		if(flagmouse==25) f25=5, stage3_values[5][2]=5;
		if(flagmouse==26) f26=5, stage3_values[6][2]=5;
		if(flagmouse==27) f27=5, stage3_values[7][2]=5;
		if(flagmouse==28) f28=5, stage3_values[8][2]=5;
		if(flagmouse==31) f31=5, stage3_values[1][3]=5;
		if(flagmouse==32) f32=5, stage3_values[2][3]=5;
		if(flagmouse==33) f33=5, stage3_values[3][3]=5;
		if(flagmouse==34) f34=5, stage3_values[4][3]=5;
		if(flagmouse==35) f35=5, stage3_values[5][3]=5;
		if(flagmouse==36) f36=5, stage3_values[6][3]=5;
		if(flagmouse==37) f37=5, stage3_values[7][3]=5;
		if(flagmouse==39) f39=5, stage3_values[9][3]=5;
		if(flagmouse==42) f42=5, stage3_values[2][4]=5;
		if(flagmouse==44) f44=5, stage3_values[4][4]=5;
		if(flagmouse==46) f46=5, stage3_values[6][4]=5;
		if(flagmouse==47) f47=5, stage3_values[7][4]=5;
		if(flagmouse==48) f48=5, stage3_values[8][4]=5;
		if(flagmouse==49) f49=5, stage3_values[9][4]=5;
		if(flagmouse==51) f51=5, stage3_values[1][5]=5;
		if(flagmouse==52) f52=5, stage3_values[2][5]=5;
		if(flagmouse==54) f54=5, stage3_values[4][5]=5;
		if(flagmouse==55) f55=5, stage3_values[5][5]=5;
		if(flagmouse==56) f56=5, stage3_values[6][5]=5;
		if(flagmouse==58) f58=5, stage3_values[8][5]=5;
		if(flagmouse==59) f59=5, stage3_values[9][5]=5;
		if(flagmouse==61) f61=5, stage3_values[1][6]=5;
		if(flagmouse==62) f62=5, stage3_values[2][6]=5;
		if(flagmouse==63) f63=5, stage3_values[3][6]=5;
		if(flagmouse==64) f64=5, stage3_values[4][6]=5;
		if(flagmouse==66) f66=5, stage3_values[6][6]=5;
		if(flagmouse==68) f68=5, stage3_values[8][6]=5;
		if(flagmouse==69) f69=5, stage3_values[9][6]=5;
		if(flagmouse==71) f71=5, stage3_values[1][7]=5;
		if(flagmouse==72) f72=5, stage3_values[2][7]=5;
		if(flagmouse==74) f74=5, stage3_values[4][7]=5;
		if(flagmouse==75) f75=5, stage3_values[5][7]=5;
		if(flagmouse==77) f77=5, stage3_values[7][7]=5;
		if(flagmouse==78) f78=5, stage3_values[8][7]=5;
		if(flagmouse==81) f81=5, stage3_values[1][8]=5;
		if(flagmouse==82) f82=5, stage3_values[2][8]=5;
		if(flagmouse==83) f83=5, stage3_values[3][8]=5;
		if(flagmouse==84) f84=5, stage3_values[4][8]=5;
		if(flagmouse==85) f85=5, stage3_values[5][8]=5;
		if(flagmouse==87) f87=5, stage3_values[7][8]=5;
		if(flagmouse==89) f89=5, stage3_values[9][8]=5;
		if(flagmouse==91) f91=5, stage3_values[1][9]=5;
		if(flagmouse==92) f92=5, stage3_values[2][9]=5;
		if(flagmouse==93) f93=5, stage3_values[3][9]=5;
		if(flagmouse==95) f95=5, stage3_values[5][9]=5;
		if(flagmouse==97) f97=5, stage3_values[7][9]=5;
		if(flagmouse==98) f98=5, stage3_values[8][9]=5;
		if(flagmouse==99) f99=5, stage3_values[9][9]=5;
	}
	if (key == '6')
	{
		if(flagmouse==11) f11=6, stage3_values[1][1]=6;
		if(flagmouse==13) f13=6, stage3_values[3][1]=6;
		if(flagmouse==14) f14=6, stage3_values[4][1]=6;
		if(flagmouse==15) f15=6, stage3_values[5][1]=6;
		if(flagmouse==16) f16=6, stage3_values[6][1]=6;
		if(flagmouse==17) f17=6, stage3_values[7][1]=6;
		if(flagmouse==18) f18=6, stage3_values[8][1]=6;
		if(flagmouse==19) f19=6, stage3_values[9][1]=6;
		if(flagmouse==21) f21=6, stage3_values[1][2]=6;
		if(flagmouse==22) f22=6, stage3_values[2][2]=6;
		if(flagmouse==23) f23=6, stage3_values[3][2]=6;
		if(flagmouse==24) f24=6, stage3_values[4][2]=6;
		if(flagmouse==25) f25=6, stage3_values[5][2]=6;
		if(flagmouse==26) f26=6, stage3_values[6][2]=6;
		if(flagmouse==27) f27=6, stage3_values[7][2]=6;
		if(flagmouse==28) f28=6, stage3_values[8][2]=6;
		if(flagmouse==31) f31=6, stage3_values[1][3]=6;
		if(flagmouse==32) f32=6, stage3_values[2][3]=6;
		if(flagmouse==33) f33=6, stage3_values[3][3]=6;
		if(flagmouse==34) f34=6, stage3_values[4][3]=6;
		if(flagmouse==35) f35=6, stage3_values[5][3]=6;
		if(flagmouse==36) f36=6, stage3_values[6][3]=6;
		if(flagmouse==37) f37=6, stage3_values[7][3]=6;
		if(flagmouse==39) f39=6, stage3_values[9][3]=6;
		if(flagmouse==42) f42=6, stage3_values[2][4]=6;
		if(flagmouse==44) f44=6, stage3_values[4][4]=6;
		if(flagmouse==46) f46=6, stage3_values[6][4]=6;
		if(flagmouse==47) f47=6, stage3_values[7][4]=6;
		if(flagmouse==48) f48=6, stage3_values[8][4]=6;
		if(flagmouse==49) f49=6, stage3_values[9][4]=6;
		if(flagmouse==51) f51=6, stage3_values[1][5]=6;
		if(flagmouse==52) f52=6, stage3_values[2][5]=6;
		if(flagmouse==54) f54=6, stage3_values[4][5]=6;
		if(flagmouse==55) f55=6, stage3_values[5][5]=6;
		if(flagmouse==56) f56=6, stage3_values[6][5]=6;
		if(flagmouse==58) f58=6, stage3_values[8][5]=6;
		if(flagmouse==59) f59=6, stage3_values[9][5]=6;
		if(flagmouse==61) f61=6, stage3_values[1][6]=6;
		if(flagmouse==62) f62=6, stage3_values[2][6]=6;
		if(flagmouse==63) f63=6, stage3_values[3][6]=6;
		if(flagmouse==64) f64=6, stage3_values[4][6]=6;
		if(flagmouse==66) f66=6, stage3_values[6][6]=6;
		if(flagmouse==68) f68=6, stage3_values[8][6]=6;
		if(flagmouse==69) f69=6, stage3_values[9][6]=6;
		if(flagmouse==71) f71=6, stage3_values[1][7]=6;
		if(flagmouse==72) f72=6, stage3_values[2][7]=6;
		if(flagmouse==74) f74=6, stage3_values[4][7]=6;
		if(flagmouse==75) f75=6, stage3_values[5][7]=6;
		if(flagmouse==77) f77=6, stage3_values[7][7]=6;
		if(flagmouse==78) f78=6, stage3_values[8][7]=6;
		if(flagmouse==81) f81=6, stage3_values[1][8]=6;
		if(flagmouse==82) f82=6, stage3_values[2][8]=6;
		if(flagmouse==83) f83=6, stage3_values[3][8]=6;
		if(flagmouse==84) f84=6, stage3_values[4][8]=6;
		if(flagmouse==85) f85=6, stage3_values[5][8]=6;
		if(flagmouse==87) f87=6, stage3_values[7][8]=6;
		if(flagmouse==89) f89=6, stage3_values[9][8]=6;
		if(flagmouse==91) f91=6, stage3_values[1][9]=6;
		if(flagmouse==92) f92=6, stage3_values[2][9]=6;
		if(flagmouse==93) f93=6, stage3_values[3][9]=6;
		if(flagmouse==95) f95=6, stage3_values[5][9]=6;
		if(flagmouse==97) f97=6, stage3_values[7][9]=6;
		if(flagmouse==98) f98=6, stage3_values[8][9]=6;
		if(flagmouse==99) f99=6, stage3_values[9][9]=6;
	}
	if (key == '7')
	{
		if(flagmouse==11) f11=7, stage3_values[1][1]=7;
		if(flagmouse==13) f13=7, stage3_values[3][1]=7;
		if(flagmouse==14) f14=7, stage3_values[4][1]=7;
		if(flagmouse==15) f15=7, stage3_values[5][1]=7;
		if(flagmouse==16) f16=7, stage3_values[6][1]=7;
		if(flagmouse==17) f17=7, stage3_values[7][1]=7;
		if(flagmouse==18) f18=7, stage3_values[8][1]=7;
		if(flagmouse==19) f19=7, stage3_values[9][1]=7;
		if(flagmouse==21) f21=7, stage3_values[1][2]=7;
		if(flagmouse==22) f22=7, stage3_values[2][2]=7;
		if(flagmouse==23) f23=7, stage3_values[3][2]=7;
		if(flagmouse==24) f24=7, stage3_values[4][2]=7;
		if(flagmouse==25) f25=7, stage3_values[5][2]=7;
		if(flagmouse==26) f26=7, stage3_values[6][2]=7;
		if(flagmouse==27) f27=7, stage3_values[7][2]=7;
		if(flagmouse==28) f28=7, stage3_values[8][2]=7;
		if(flagmouse==31) f31=7, stage3_values[1][3]=7;
		if(flagmouse==32) f32=7, stage3_values[2][3]=7;
		if(flagmouse==33) f33=7, stage3_values[3][3]=7;
		if(flagmouse==34) f34=7, stage3_values[4][3]=7;
		if(flagmouse==35) f35=7, stage3_values[5][3]=7;
		if(flagmouse==36) f36=7, stage3_values[6][3]=7;
		if(flagmouse==37) f37=7, stage3_values[7][3]=7;
		if(flagmouse==39) f39=7, stage3_values[9][3]=7;
		if(flagmouse==42) f42=7, stage3_values[2][4]=7;
		if(flagmouse==44) f44=7, stage3_values[4][4]=7;
		if(flagmouse==46) f46=7, stage3_values[6][4]=7;
		if(flagmouse==47) f47=7, stage3_values[7][4]=7;
		if(flagmouse==48) f48=7, stage3_values[8][4]=7;
		if(flagmouse==49) f49=7, stage3_values[9][4]=7;
		if(flagmouse==51) f51=7, stage3_values[1][5]=7;
		if(flagmouse==52) f52=7, stage3_values[2][5]=7;
		if(flagmouse==54) f54=7, stage3_values[4][5]=7;
		if(flagmouse==55) f55=7, stage3_values[5][5]=7;
		if(flagmouse==56) f56=7, stage3_values[6][5]=7;
		if(flagmouse==58) f58=7, stage3_values[8][5]=7;
		if(flagmouse==59) f59=7, stage3_values[9][5]=7;
		if(flagmouse==61) f61=7, stage3_values[1][6]=7;
		if(flagmouse==62) f62=7, stage3_values[2][6]=7;
		if(flagmouse==63) f63=7, stage3_values[3][6]=7;
		if(flagmouse==64) f64=7, stage3_values[4][6]=7;
		if(flagmouse==66) f66=7, stage3_values[6][6]=7;
		if(flagmouse==68) f68=7, stage3_values[8][6]=7;
		if(flagmouse==69) f69=7, stage3_values[9][6]=7;
		if(flagmouse==71) f71=7, stage3_values[1][7]=7;
		if(flagmouse==72) f72=7, stage3_values[2][7]=7;
		if(flagmouse==74) f74=7, stage3_values[4][7]=7;
		if(flagmouse==75) f75=7, stage3_values[5][7]=7;
		if(flagmouse==77) f77=7, stage3_values[7][7]=7;
		if(flagmouse==78) f78=7, stage3_values[8][7]=7;
		if(flagmouse==81) f81=7, stage3_values[1][8]=7;
		if(flagmouse==82) f82=7, stage3_values[2][8]=7;
		if(flagmouse==83) f83=7, stage3_values[3][8]=7;
		if(flagmouse==84) f84=7, stage3_values[4][8]=7;
		if(flagmouse==85) f85=7, stage3_values[5][8]=7;
		if(flagmouse==87) f87=7, stage3_values[7][8]=7;
		if(flagmouse==89) f89=7, stage3_values[9][8]=7;
		if(flagmouse==91) f91=7, stage3_values[1][9]=7;
		if(flagmouse==92) f92=7, stage3_values[2][9]=7;
		if(flagmouse==93) f93=7, stage3_values[3][9]=7;
		if(flagmouse==95) f95=7, stage3_values[5][9]=7;
		if(flagmouse==97) f97=7, stage3_values[7][9]=7;
		if(flagmouse==98) f98=7, stage3_values[8][9]=7;
		if(flagmouse==99) f99=7, stage3_values[9][9]=7;
	}
	if (key == '8')
	{
		if(flagmouse==11) f11=8, stage3_values[1][1]=8;
		if(flagmouse==13) f13=8, stage3_values[3][1]=8;
		if(flagmouse==14) f14=8, stage3_values[4][1]=8;
		if(flagmouse==15) f15=8, stage3_values[5][1]=8;
		if(flagmouse==16) f16=8, stage3_values[6][1]=8;
		if(flagmouse==17) f17=8, stage3_values[7][1]=8;
		if(flagmouse==18) f18=8, stage3_values[8][1]=8;
		if(flagmouse==19) f19=8, stage3_values[9][1]=8;
		if(flagmouse==21) f21=8, stage3_values[1][2]=8;
		if(flagmouse==22) f22=8, stage3_values[2][2]=8;
		if(flagmouse==23) f23=8, stage3_values[3][2]=8;
		if(flagmouse==24) f24=8, stage3_values[4][2]=8;
		if(flagmouse==25) f25=8, stage3_values[5][2]=8;
		if(flagmouse==26) f26=8, stage3_values[6][2]=8;
		if(flagmouse==27) f27=8, stage3_values[7][2]=8;
		if(flagmouse==28) f28=8, stage3_values[8][2]=8;
		if(flagmouse==31) f31=8, stage3_values[1][3]=8;
		if(flagmouse==32) f32=8, stage3_values[2][3]=8;
		if(flagmouse==33) f33=8, stage3_values[3][3]=8;
		if(flagmouse==34) f34=8, stage3_values[4][3]=8;
		if(flagmouse==35) f35=8, stage3_values[5][3]=8;
		if(flagmouse==36) f36=8, stage3_values[6][3]=8;
		if(flagmouse==37) f37=8, stage3_values[7][3]=8;
		if(flagmouse==39) f39=8, stage3_values[9][3]=8;
		if(flagmouse==42) f42=8, stage3_values[2][4]=8;
		if(flagmouse==44) f44=8, stage3_values[4][4]=8;
		if(flagmouse==46) f46=8, stage3_values[6][4]=8;
		if(flagmouse==47) f47=8, stage3_values[7][4]=8;
		if(flagmouse==48) f48=8, stage3_values[8][4]=8;
		if(flagmouse==49) f49=8, stage3_values[9][4]=8;
		if(flagmouse==51) f51=8, stage3_values[1][5]=8;
		if(flagmouse==52) f52=8, stage3_values[2][5]=8;
		if(flagmouse==54) f54=8, stage3_values[4][5]=8;
		if(flagmouse==55) f55=8, stage3_values[5][5]=8;
		if(flagmouse==56) f56=8, stage3_values[6][5]=8;
		if(flagmouse==58) f58=8, stage3_values[8][5]=8;
		if(flagmouse==59) f59=8, stage3_values[9][5]=8;
		if(flagmouse==61) f61=8, stage3_values[1][6]=8;
		if(flagmouse==62) f62=8, stage3_values[2][6]=8;
		if(flagmouse==63) f63=8, stage3_values[3][6]=8;
		if(flagmouse==64) f64=8, stage3_values[4][6]=8;
		if(flagmouse==66) f66=8, stage3_values[6][6]=8;
		if(flagmouse==68) f68=8, stage3_values[8][6]=8;
		if(flagmouse==69) f69=8, stage3_values[9][6]=8;
		if(flagmouse==71) f71=8, stage3_values[1][7]=8;
		if(flagmouse==72) f72=8, stage3_values[2][7]=8;
		if(flagmouse==74) f74=8, stage3_values[4][7]=8;
		if(flagmouse==75) f75=8, stage3_values[5][7]=8;
		if(flagmouse==77) f77=8, stage3_values[7][7]=8;
		if(flagmouse==78) f78=8, stage3_values[8][7]=8;
		if(flagmouse==81) f81=8, stage3_values[1][8]=8;
		if(flagmouse==82) f82=8, stage3_values[2][8]=8;
		if(flagmouse==83) f83=8, stage3_values[3][8]=8;
		if(flagmouse==84) f84=8, stage3_values[4][8]=8;
		if(flagmouse==85) f85=8, stage3_values[5][8]=8;
		if(flagmouse==87) f87=8, stage3_values[7][8]=8;
		if(flagmouse==89) f89=8, stage3_values[9][8]=8;
		if(flagmouse==91) f91=8, stage3_values[1][9]=8;
		if(flagmouse==92) f92=8, stage3_values[2][9]=8;
		if(flagmouse==93) f93=8, stage3_values[3][9]=8;
		if(flagmouse==95) f95=8, stage3_values[5][9]=8;
		if(flagmouse==97) f97=8, stage3_values[7][9]=8;
		if(flagmouse==98) f98=8, stage3_values[8][9]=8;
		if(flagmouse==99) f99=8, stage3_values[9][9]=8;
	}

	if (key == '9')
	{
		if(flagmouse==11) f11=9, stage3_values[1][1]=9;
		if(flagmouse==13) f13=9, stage3_values[3][1]=9;
		if(flagmouse==14) f14=9, stage3_values[4][1]=9;
		if(flagmouse==15) f15=9, stage3_values[5][1]=9;
		if(flagmouse==16) f16=9, stage3_values[6][1]=9;
		if(flagmouse==17) f17=9, stage3_values[7][1]=9;
		if(flagmouse==18) f18=9, stage3_values[8][1]=9;
		if(flagmouse==19) f19=9, stage3_values[9][1]=9;
		if(flagmouse==21) f21=9, stage3_values[1][2]=9;
		if(flagmouse==22) f22=9, stage3_values[2][2]=9;
		if(flagmouse==23) f23=9, stage3_values[3][2]=9;
		if(flagmouse==24) f24=9, stage3_values[4][2]=9;
		if(flagmouse==25) f25=9, stage3_values[5][2]=9;
		if(flagmouse==26) f26=9, stage3_values[6][2]=9;
		if(flagmouse==27) f27=9, stage3_values[7][2]=9;
		if(flagmouse==28) f28=9, stage3_values[8][2]=9;
		if(flagmouse==31) f31=9, stage3_values[1][3]=9;
		if(flagmouse==32) f32=9, stage3_values[2][3]=9;
		if(flagmouse==33) f33=9,  stage3_values[3][3]=9;
		if(flagmouse==34) f34=9, stage3_values[4][3]=9;
		if(flagmouse==35) f35=9, stage3_values[5][3]=9;
		if(flagmouse==36) f36=9, stage3_values[6][3]=9;
		if(flagmouse==37) f37=9, stage3_values[7][3]=9;
		if(flagmouse==39) f39=9, stage3_values[9][3]=9;
		if(flagmouse==42) f42=9, stage3_values[2][4]=9;
		if(flagmouse==44) f44=9, stage3_values[4][4]=9;
		if(flagmouse==46) f46=9, stage3_values[6][4]=9;
		if(flagmouse==47) f47=9, stage3_values[7][4]=9;
		if(flagmouse==48) f48=9, stage3_values[8][4]=9;
		if(flagmouse==49) f49=9, stage3_values[9][4]=9;
		if(flagmouse==51) f51=9, stage3_values[1][5]=9;
		if(flagmouse==52) f52=9, stage3_values[2][5]=9;
		if(flagmouse==54) f54=9, stage3_values[4][5]=9;
		if(flagmouse==55) f55=9, stage3_values[5][5]=9;
		if(flagmouse==56) f56=9, stage3_values[6][5]=9;
		if(flagmouse==58) f58=9, stage3_values[8][5]=9;
		if(flagmouse==59) f59=9, stage3_values[9][5]=9;
		if(flagmouse==61) f61=9, stage3_values[1][6]=9;
		if(flagmouse==62) f62=9, stage3_values[2][6]=9;
		if(flagmouse==63) f63=9, stage3_values[3][6]=9;
		if(flagmouse==64) f64=9, stage3_values[4][6]=9;
		if(flagmouse==66) f66=9, stage3_values[6][6]=9;
		if(flagmouse==68) f68=9, stage3_values[8][6]=9;
		if(flagmouse==69) f69=9, stage3_values[9][6]=9;
		if(flagmouse==71) f71=9, stage3_values[1][7]=9;
		if(flagmouse==72) f72=9, stage3_values[2][7]=9;
		if(flagmouse==74) f74=9, stage3_values[4][7]=9;
		if(flagmouse==75) f75=9, stage3_values[5][7]=9;
		if(flagmouse==77) f77=9, stage3_values[7][7]=9;
		if(flagmouse==78) f78=9, stage3_values[8][7]=9;
		if(flagmouse==81) f81=9, stage3_values[1][8]=9;
		if(flagmouse==82) f82=9, stage3_values[2][8]=9;
		if(flagmouse==83) f83=9, stage3_values[3][8]=9;
		if(flagmouse==84) f84=9, stage3_values[4][8]=9;
		if(flagmouse==85) f85=9, stage3_values[5][8]=9;
		if(flagmouse==87) f87=9, stage3_values[7][8]=9;
		if(flagmouse==89) f89=9, stage3_values[9][8]=9;
		if(flagmouse==91) f91=9, stage3_values[1][9]=9;
		if(flagmouse==92) f92=9, stage3_values[2][9]=9;
		if(flagmouse==93) f93=9, stage3_values[3][9]=9;
		if(flagmouse==95) f95=9, stage3_values[5][9]=9;
		if(flagmouse==97) f97=9, stage3_values[7][9]=9;
		if(flagmouse==98) f98=9, stage3_values[8][9]=9;
		if(flagmouse==99) f99=9, stage3_values[9][9]=9;
	}
	
	if(key=='e')
	{
		if(flagmouse==11) f11=100, stage3_values[1][1]=0;
		if(flagmouse==12) f12=100, stage3_values[2][1]=0;
		if(flagmouse==13) f13=100, stage3_values[3][1]=0;
		if(flagmouse==14) f14=100, stage3_values[4][1]=0;
		if(flagmouse==15) f15=100, stage3_values[5][1]=0;
		if(flagmouse==16) f16=100, stage3_values[6][1]=0;
		if(flagmouse==17) f17=100, stage3_values[7][1]=0;
		if(flagmouse==18) f18=100, stage3_values[8][1]=0;
		if(flagmouse==19) f19=100, stage3_values[9][1]=0;
		if(flagmouse==21) f21=100, stage3_values[1][2]=0;
		if(flagmouse==22) f22=100, stage3_values[2][2]=0;
		if(flagmouse==23) f23=100, stage3_values[3][2]=0;
		if(flagmouse==24) f24=100, stage3_values[4][2]=0;
		if(flagmouse==25) f25=100, stage3_values[5][2]=0;
		if(flagmouse==26) f26=100, stage3_values[6][2]=0;
		if(flagmouse==27) f27=100, stage3_values[7][2]=0;
		if(flagmouse==28) f28=100, stage3_values[8][2]=0;
		if(flagmouse==29) f29=100, stage3_values[9][2]=0;
		if(flagmouse==31) f31=100, stage3_values[1][3]=0;
		if(flagmouse==32) f32=100, stage3_values[2][3]=0;
		if(flagmouse==33) f33=100, stage3_values[3][3]=0;
		if(flagmouse==34) f34=100, stage3_values[4][3]=0;
		if(flagmouse==35) f35=100, stage3_values[5][3]=0;
		if(flagmouse==36) f36=100, stage3_values[6][3]=0;
		if(flagmouse==37) f37=100, stage3_values[7][3]=0;
		if(flagmouse==38) f38=100, stage3_values[8][3]=0;
		if(flagmouse==39) f39=100, stage3_values[9][3]=0;
		if(flagmouse==41) f41=100, stage3_values[1][4]=0;
		if(flagmouse==42) f42=100, stage3_values[2][4]=0;
		if(flagmouse==43) f43=100, stage3_values[3][4]=0;
		if(flagmouse==44) f44=100, stage3_values[4][4]=0;
		if(flagmouse==45) f45=100, stage3_values[5][4]=0;
		if(flagmouse==46) f46=100, stage3_values[6][4]=0;
		if(flagmouse==47) f47=100, stage3_values[7][4]=0;
		if(flagmouse==48) f48=100, stage3_values[8][4]=0;
		if(flagmouse==49) f49=100, stage3_values[9][4]=0;
		if(flagmouse==51) f51=100, stage3_values[1][5]=0;
		if(flagmouse==52) f52=100, stage3_values[2][5]=0;
		if(flagmouse==53) f53=100, stage3_values[3][5]=0;
		if(flagmouse==54) f54=100, stage3_values[4][5]=0;
		if(flagmouse==55) f55=100, stage3_values[5][5]=0;
		if(flagmouse==56) f56=100, stage3_values[6][5]=0;
		if(flagmouse==57) f57=100, stage3_values[7][5]=0;
		if(flagmouse==58) f58=100, stage3_values[8][5]=0;
		if(flagmouse==59) f59=100, stage3_values[9][5]=0;
		if(flagmouse==61) f61=100, stage3_values[1][6]=0;
		if(flagmouse==62) f62=100, stage3_values[2][6]=0;
		if(flagmouse==63) f63=100, stage3_values[3][6]=0;
		if(flagmouse==64) f64=100, stage3_values[4][6]=0;
		if(flagmouse==65) f65=100, stage3_values[5][6]=0;
		if(flagmouse==66) f66=100, stage3_values[6][6]=0;
		if(flagmouse==67) f67=100, stage3_values[7][6]=0;
		if(flagmouse==68) f68=100, stage3_values[8][6]=0;
		if(flagmouse==69) f69=100, stage3_values[9][6]=0;
		if(flagmouse==71) f71=100, stage3_values[1][7]=0;
		if(flagmouse==72) f72=100, stage3_values[2][7]=0;
		if(flagmouse==73) f73=100, stage3_values[3][7]=0;
		if(flagmouse==74) f74=100, stage3_values[4][7]=0;
		if(flagmouse==75) f75=100, stage3_values[5][7]=0;
		if(flagmouse==76) f76=100, stage3_values[6][7]=0;
		if(flagmouse==77) f77=100, stage3_values[7][7]=0;
		if(flagmouse==78) f78=100, stage3_values[8][7]=0;
		if(flagmouse==79) f79=100, stage3_values[9][7]=0;
		if(flagmouse==81) f81=100, stage3_values[1][8]=0;
		if(flagmouse==82) f82=100, stage3_values[2][8]=0;
		if(flagmouse==83) f83=100, stage3_values[3][8]=0;
		if(flagmouse==84) f84=100, stage3_values[4][8]=0;
		if(flagmouse==85) f85=100, stage3_values[5][8]=0;
		if(flagmouse==86) f86=100, stage3_values[6][8]=0;
		if(flagmouse==87) f87=100, stage3_values[7][8]=0;
		if(flagmouse==88) f88=100, stage3_values[8][8]=0;
		if(flagmouse==89) f89=100, stage3_values[9][8]=0;
		if(flagmouse==91) f91=100, stage3_values[1][9]=0;
		if(flagmouse==92) f92=100, stage3_values[2][9]=0;
		if(flagmouse==93) f93=100, stage3_values[3][9]=0;
		if(flagmouse==94) f94=100, stage3_values[4][9]=0;
		if(flagmouse==95) f95=100, stage3_values[5][9]=0;
		if(flagmouse==96) f96=100, stage3_values[6][9]=0;
		if(flagmouse==97) f97=100, stage3_values[7][9]=0;
		if(flagmouse==98) f98=100, stage3_values[8][9]=0;
		if(flagmouse==99) f99=100, stage3_values[9][9]=0;
	}
	}

	if(key == 'p')
	{

		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here

}


	
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key==GLUT_KEY_F10)
	{
		flagremove=1;
	}
	//place your codes for other keys here
}

void stage_5()
{
	// 1st column

	if(f11==1) iShowBMP(300,600,"typedone.bmp");
	else if(f11==2) iShowBMP(300,600,"typedtwo.bmp");
	else if(f11==3) iShowBMP(300,600,"typedthree.bmp");
	else if(f11==4) iShowBMP(300,600,"typedfour.bmp");
	else if(f11==5) iShowBMP(300,600,"typedfive.bmp");
	else if(f11==6) iShowBMP(300,600,"typedsix.bmp");
	else if(f11==7) iShowBMP(300,600,"typedseven.bmp");
	else if(f11==8) iShowBMP(300,600,"typedeight.bmp");
	else if(f11==9) iShowBMP(300,600,"typednine.bmp");
	else iShowBMP(300,600,"grid.bmp");
    if(flagmouse==11) iShowBMP(350,648,"mark.bmp");
    
    iShowBMP(300,535,"five.bmp");
    
	if(f13==1) iShowBMP(300,470,"typedone.bmp");
	else if(f13==2) {iShowBMP(300,470,"typedtwo.bmp");}
	else if(f13==3) iShowBMP(300,470,"typedthree.bmp");
	else if(f13==4) iShowBMP(300,470,"typedfour.bmp");
	else if(f13==5) iShowBMP(300,470,"typedfive.bmp");
	else if(f13==6) iShowBMP(300,470,"typedsix.bmp");
	else if(f13==7) iShowBMP(300,470,"typedseven.bmp");
	else if(f13==8) iShowBMP(300,470,"typedeight.bmp");
	else if(f13==9) iShowBMP(300,470,"typednine.bmp");
	else iShowBMP(300,470,"grid.bmp");
    if(flagmouse==13) iShowBMP(350,518,"mark.bmp");
    
    if(f14==1) iShowBMP(300,405,"typedone.bmp");
	else if(f14==2) {iShowBMP(300,405,"typedtwo.bmp");}
	else if(f14==3) iShowBMP(300,405,"typedthree.bmp");
	else if(f14==4) iShowBMP(300,405,"typedfour.bmp");
	else if(f14==5) iShowBMP(300,405,"typedfive.bmp");
	else if(f14==6) iShowBMP(300,405,"typedsix.bmp");
	else if(f14==7) iShowBMP(300,405,"typedseven.bmp");
	else if(f14==8) iShowBMP(300,405,"typedeight.bmp");
	else if(f14==9) iShowBMP(300,405,"typednine.bmp");
	else iShowBMP(300,405,"grid.bmp");
    if(flagmouse==14) iShowBMP(350,453,"mark.bmp");
    
	if(f15==1) iShowBMP(300,340,"typedone.bmp");
	else if(f15==2) {iShowBMP(300,340,"typedtwo.bmp");}
	else if(f15==3) iShowBMP(300,340,"typedthree.bmp");
	else if(f15==4) iShowBMP(300,340,"typedfour.bmp");
	else if(f15==5) iShowBMP(300,340,"typedfive.bmp");
	else if(f15==6) iShowBMP(300,340,"typedsix.bmp");
	else if(f15==7) iShowBMP(300,340,"typedseven.bmp");
	else if(f15==8) iShowBMP(300,340,"typedeight.bmp");
	else if(f15==9) iShowBMP(300,340,"typednine.bmp");
	else iShowBMP(300,340,"grid.bmp");
    if(flagmouse==15) iShowBMP(350,388,"mark.bmp");
    

	iShowBMP(300,275,"seven.bmp");

	iShowBMP(300,210,"three.bmp");
	

	if(f18==1) iShowBMP(300,145,"typedone.bmp");
	else if(f18==2) {iShowBMP(300,145,"typedtwo.bmp");}
	else if(f18==3) iShowBMP(300,145,"typedthree.bmp");
	else if(f18==4) iShowBMP(300,145,"typedfour.bmp");
	else if(f18==5) iShowBMP(300,145,"typedfive.bmp");
	else if(f18==6) iShowBMP(300,145,"typedsix.bmp");
	else if(f18==7) iShowBMP(300,145,"typedseven.bmp");
	else if(f18==8) iShowBMP(300,145,"typedeight.bmp");
	else if(f18==9) iShowBMP(300,145,"typednine.bmp");
	else iShowBMP(300,145,"grid.bmp");
	if(flagmouse==18) iShowBMP(350,194,"mark.bmp");
	
	iShowBMP(300,80,"one.bmp");

	// second column

	iShowBMP(365,600,"six.bmp");

	iShowBMP(365,535,"three.bmp");


	iShowBMP(365,470,"four.bmp");

	iShowBMP(365,405,"nine.bmp");


	if(f25==1) iShowBMP(365,340,"typedone.bmp");
	else if(f25==2) iShowBMP(365,340,"typedtwo.bmp");
	else if(f25==3) iShowBMP(365,340,"typedthree.bmp");
	else if(f25==4) iShowBMP(365,340,"typedfour.bmp");
	else if(f25==5) iShowBMP(365,340,"typedfive.bmp");
	else if(f25==6) iShowBMP(365,340,"typedsix.bmp");
	else if(f25==7) iShowBMP(365,340,"typedseven.bmp");
	else if(f25==8) iShowBMP(365,340,"typedeight.bmp");
	else if(f25==9) iShowBMP(365,340,"typednine.bmp");
	else iShowBMP(365,340,"grid.bmp");
	if(flagmouse==25) iShowBMP(415,388,"mark.bmp");

	iShowBMP(365,275,"one.bmp");


	if(f27==1) iShowBMP(365,210,"typedone.bmp");
	else if(f27==2) iShowBMP(365,210,"typedtwo.bmp");
	else if(f27==3) iShowBMP(365,210,"typedthree.bmp");
	else if(f27==4) iShowBMP(365,210,"typedfour.bmp");
	else if(f27==5) iShowBMP(365,210,"typedfive.bmp");
	else if(f27==6) iShowBMP(365,210,"typedsix.bmp");
	else if(f27==7) iShowBMP(365,210,"typedseven.bmp");
	else if(f27==8) iShowBMP(365,210,"typedeight.bmp");
	else if(f27==9) iShowBMP(365,210,"typednine.bmp");
	else iShowBMP(365,210,"grid.bmp");
	if(flagmouse==27) iShowBMP(415,257,"mark.bmp");

	if(f28==1) iShowBMP(365,145,"typedone.bmp");
	else if(f28==2) iShowBMP(365,145,"typedtwo.bmp");
	else if(f28==3) iShowBMP(365,145,"typedthree.bmp");
	else if(f28==4) iShowBMP(365,145,"typedfour.bmp");
	else if(f28==5) iShowBMP(365,145,"typedfive.bmp");
	else if(f28==6) iShowBMP(365,145,"typedsix.bmp");
	else if(f28==7) iShowBMP(365,145,"typedseven.bmp");
	else if(f28==8) iShowBMP(365,145,"typedeight.bmp");
	else if(f28==9) iShowBMP(365,145,"typednine.bmp");
	else iShowBMP(365,145,"grid.bmp");
	if(flagmouse==28) iShowBMP(415,193,"mark.bmp");


	if(f29==1) iShowBMP(365,80,"typedone.bmp");
	else if(f29==2) iShowBMP(365,80,"typedtwo.bmp");
	else if(f29==3) iShowBMP(365,80,"typedthree.bmp");
	else if(f29==4) iShowBMP(365,80,"typedfour.bmp");
	else if(f29==5) iShowBMP(365,80,"typedfive.bmp");
	else if(f29==6) iShowBMP(365,80,"typedsix.bmp");
	else if(f29==7) iShowBMP(365,80,"typedseven.bmp");
	else if(f29==8) iShowBMP(365,80,"typedeight.bmp");
	else if(f29==9) iShowBMP(365,80,"typednine.bmp");
	else iShowBMP(365,80,"grid.bmp");
	if(flagmouse==29) iShowBMP(415,128,"mark.bmp");


	// 3rd column
	if(f31==1) iShowBMP(430,600,"typedone.bmp");
	else if(f31==2) iShowBMP(430,600,"typedtwo.bmp");
	else if(f31==3) iShowBMP(430,600,"typedthree.bmp");
	else if(f31==4) iShowBMP(430,600,"typedfour.bmp");
	else if(f31==5) iShowBMP(430,600,"typedfive.bmp");
	else if(f31==6) iShowBMP(430,600,"typedsix.bmp");
	else if(f31==7) iShowBMP(430,600,"typedseven.bmp");
	else if(f31==8) iShowBMP(430,600,"typedeight.bmp");
	else if(f31==9) iShowBMP(430,600,"typednine.bmp");
	else iShowBMP(430,600,"grid.bmp");
	if(flagmouse==31) iShowBMP(478,648,"mark.bmp");

	iShowBMP(430,535,"seven.bmp");

	if(f33==1) iShowBMP(430,470,"typedone.bmp");
	else if(f33==2) iShowBMP(430,470,"typedtwo.bmp");
	else if(f33==3) iShowBMP(430,470,"typedthree.bmp");
	else if(f33==4) iShowBMP(430,470,"typedfour.bmp");
	else if(f33==5) iShowBMP(430,470,"typedfive.bmp");
	else if(f33==6) iShowBMP(430,470,"typedsix.bmp");
	else if(f33==7) iShowBMP(430,470,"typedseven.bmp");
	else if(f33==8) iShowBMP(430,470,"typedeight.bmp");
	else if(f33==9) iShowBMP(430,470,"typednine.bmp");
	else iShowBMP(430,470,"grid.bmp");//iShowBMP(430,535,"grid.bmp");
	if(flagmouse==33) iShowBMP(478,516,"mark.bmp");

	if(f34==1) iShowBMP(430,405,"typedone.bmp");
	else if(f34==2) iShowBMP(430,405,"typedtwo.bmp");
	else if(f34==3) iShowBMP(430,405,"typedthree.bmp");
	else if(f34==4) iShowBMP(430,405,"typedfour.bmp");
	else if(f34==5) iShowBMP(430,405,"typedfive.bmp");
	else if(f34==6) iShowBMP(430,405,"typedsix.bmp");
	else if(f34==7) iShowBMP(430,405,"typedseven.bmp");
	else if(f34==8) iShowBMP(430,405,"typedeight.bmp");
	else if(f34==9) iShowBMP(430,405,"typednine.bmp");
	else iShowBMP(430,405,"grid.bmp");
	if(flagmouse==34) iShowBMP(478,451,"mark.bmp");

	if(f35==1) iShowBMP(430,340,"typedone.bmp");
	else if(f35==2) iShowBMP(430,340,"typedtwo.bmp");
	else if(f35==3) iShowBMP(430,340,"typedthree.bmp");
	else if(f35==4) iShowBMP(430,340,"typedfour.bmp");
	else if(f35==5) iShowBMP(430,340,"typedfive.bmp");
	else if(f35==6) iShowBMP(430,340,"typedsix.bmp");
	else if(f35==7) iShowBMP(430,340,"typedseven.bmp");
	else if(f35==8) iShowBMP(430,340,"typedeight.bmp");
	else if(f35==9) iShowBMP(430,340,"typednine.bmp");
	else iShowBMP(430,340,"grid.bmp");
	if(flagmouse==35) iShowBMP(478,388,"mark.bmp");

	iShowBMP(430,275,"three.bmp");

	iShowBMP(430,210,"six.bmp");

	if(f38==1) iShowBMP(430,145,"typedone.bmp");
	else if(f38==2) iShowBMP(430,145,"typedtwo.bmp");
	else if(f38==3) iShowBMP(430,145,"typedthree.bmp");
	else if(f38==4) iShowBMP(430,145,"typedfour.bmp");
	else if(f38==5) iShowBMP(430,145,"typedfive.bmp");
	else if(f38==6) iShowBMP(430,145,"typedsix.bmp");
	else if(f38==7) iShowBMP(430,145,"typedseven.bmp");
	else if(f38==8) iShowBMP(430,145,"typedeight.bmp");
	else if(f38==9) iShowBMP(430,145,"typednine.bmp");
	else iShowBMP(430,145,"grid.bmp");//iShowBMP(430,80,"grid.bmp");
	if(flagmouse==38) iShowBMP(478,192,"mark.bmp");
	
	iShowBMP(430,80,"two.bmp");

	// 4th column

	iShowBMP(495,600,"three.bmp");
	
	if(f42==1) iShowBMP(495,535,"typedone.bmp");
	else if(f42==2) iShowBMP(495,535,"typedtwo.bmp");
	else if(f42==3) iShowBMP(495,535,"typedthree.bmp");
	else if(f42==4) iShowBMP(495,535,"typedfour.bmp");
	else if(f42==5) iShowBMP(495,535,"typedfive.bmp");
	else if(f42==6) iShowBMP(495,535,"typedsix.bmp");
	else if(f42==7) iShowBMP(495,535,"typedseven.bmp");
	else if(f42==8) iShowBMP(495,535,"typedeight.bmp");
	else if(f42==9) iShowBMP(495,535,"typednine.bmp");
	else iShowBMP(495,535,"grid.bmp");
	if(flagmouse==42) iShowBMP(545,582,"mark.bmp");


	if(f43==1) iShowBMP(495,470,"typedone.bmp");
	else if(f43==2) iShowBMP(495,470,"typedtwo.bmp");
	else if(f43==3) iShowBMP(495,470,"typedthree.bmp");
	else if(f43==4) iShowBMP(495,470,"typedfour.bmp");
	else if(f43==5) iShowBMP(495,470,"typedfive.bmp");
	else if(f43==6) iShowBMP(495,470,"typedsix.bmp");
	else if(f43==7) iShowBMP(495,470,"typedseven.bmp");
	else if(f43==8) iShowBMP(495,470,"typedeight.bmp");
	else if(f43==9) iShowBMP(495,470,"typednine.bmp");
	else iShowBMP(495,470,"grid.bmp");
	if(flagmouse==43) iShowBMP(545,516,"mark.bmp");

	if(f44==1) iShowBMP(495,405,"typedone.bmp");
	else if(f44==2) iShowBMP(495,405,"typedtwo.bmp");
	else if(f44==3) iShowBMP(495,405,"typedthree.bmp");
	else if(f44==4) iShowBMP(495,405,"typedfour.bmp");
	else if(f44==5) iShowBMP(495,405,"typedfive.bmp");
	else if(f44==6) iShowBMP(495,405,"typedsix.bmp");
	else if(f44==7) iShowBMP(495,405,"typedseven.bmp");
	else if(f44==8) iShowBMP(495,405,"typedeight.bmp");
	else if(f44==9) iShowBMP(495,405,"typednine.bmp");
	else iShowBMP(495,405,"grid.bmp");
	if(flagmouse==44) iShowBMP(545,451,"mark.bmp");

	if(f45==1) iShowBMP(495,340,"typedone.bmp");
	else if(f45==2) iShowBMP(495,340,"typedtwo.bmp");
	else if(f45==3) iShowBMP(495,340,"typedthree.bmp");
	else if(f45==4) iShowBMP(495,340,"typedfour.bmp");
	else if(f45==5) iShowBMP(495,340,"typedfive.bmp");
	else if(f45==6) iShowBMP(495,340,"typedsix.bmp");
	else if(f45==7) iShowBMP(495,340,"typedseven.bmp");
	else if(f45==8) iShowBMP(495,340,"typedeight.bmp");
	else if(f45==9) iShowBMP(495,340,"typednine.bmp");
	else iShowBMP(495,340,"grid.bmp");
	if(flagmouse==45) iShowBMP(545,388,"mark.bmp");
	
	iShowBMP(495,275,"six.bmp");

	iShowBMP(495,210,"four.bmp");

	if(f48==1) iShowBMP(495,145,"typedone.bmp");
	else if(f48==2) iShowBMP(495,145,"typedtwo.bmp");
	else if(f48==3) iShowBMP(495,145,"typedthree.bmp");
	else if(f48==4) iShowBMP(495,145,"typedfour.bmp");
	else if(f48==5) iShowBMP(495,145,"typedfive.bmp");
	else if(f48==6) iShowBMP(495,145,"typedsix.bmp");
	else if(f48==7) iShowBMP(495,145,"typedseven.bmp");
	else if(f48==8) iShowBMP(495,145,"typedeight.bmp");
	else if(f48==9) iShowBMP(495,145,"typednine.bmp");
	else iShowBMP(495,145,"grid.bmp");
	if(flagmouse==48) iShowBMP(545,191,"mark.bmp");

	if(f49==1) iShowBMP(495,80,"typedone.bmp");
	else if(f49==2) iShowBMP(495,80,"typedtwo.bmp");
	else if(f49==3) iShowBMP(495,80,"typedthree.bmp");
	else if(f49==4) iShowBMP(495,80,"typedfour.bmp");
	else if(f49==5) iShowBMP(495,80,"typedfive.bmp");
	else if(f49==6) iShowBMP(495,80,"typedsix.bmp");
	else if(f49==7) iShowBMP(495,80,"typedseven.bmp");
	else if(f49==8) iShowBMP(495,80,"typedeight.bmp");
	else if(f49==9) iShowBMP(495,80,"typednine.bmp");
	else iShowBMP(495,80,"grid.bmp");
	if(flagmouse==49) iShowBMP(545,128,"mark.bmp");

	// 5th column
	if(f51==1) iShowBMP(560,600,"typedone.bmp");
	else if(f51==2) iShowBMP(560,600,"typedtwo.bmp");
	else if(f51==3) iShowBMP(560,600,"typedthree.bmp");
	else if(f51==4) iShowBMP(560,600,"typedfour.bmp");
	else if(f51==5) iShowBMP(560,600,"typedfive.bmp");
	else if(f51==6) iShowBMP(560,600,"typedsix.bmp");
	else if(f51==7) iShowBMP(560,600,"typedseven.bmp");
	else if(f51==8) iShowBMP(560,600,"typedeight.bmp");
	else if(f51==9) iShowBMP(560,600,"typednine.bmp");
	else iShowBMP(560,600,"grid.bmp");
	if(flagmouse==51) iShowBMP(610,648,"mark.bmp");

	iShowBMP(560,535,"nine.bmp");

	if(f53==1) iShowBMP(560,470,"typedone.bmp");
	else if(f53==2) iShowBMP(560,470,"typedtwo.bmp");
	else if(f53==3) iShowBMP(560,470,"typedthree.bmp");
	else if(f53==4) iShowBMP(560,470,"typedfour.bmp");
	else if(f53==5) iShowBMP(560,470,"typedfive.bmp");
	else if(f53==6) iShowBMP(560,470,"typedsix.bmp");
	else if(f53==7) iShowBMP(560,470,"typedseven.bmp");
	else if(f53==8) iShowBMP(560,470,"typedeight.bmp");
	else if(f53==9) iShowBMP(560,470,"typednine.bmp");
	else iShowBMP(560,470,"grid.bmp");
	if(flagmouse==53) iShowBMP(610,518,"mark.bmp");
	
	iShowBMP(560,405,"five.bmp");

	if(f55==1) iShowBMP(560,340,"typedone.bmp");
	else if(f55==2) iShowBMP(560,340,"typedtwo.bmp");
	else if(f55==3) iShowBMP(560,340,"typedthree.bmp");
	else if(f55==4) iShowBMP(560,340,"typedfour.bmp");
	else if(f55==5) iShowBMP(560,340,"typedfive.bmp");
	else if(f55==6) iShowBMP(560,340,"typedsix.bmp");
	else if(f55==7) iShowBMP(560,340,"typedseven.bmp");
	else if(f55==8) iShowBMP(560,340,"typedeight.bmp");
	else if(f55==9) iShowBMP(560,340,"typednine.bmp");
	else iShowBMP(560,340,"grid.bmp");
	if(flagmouse==55) iShowBMP(610,388,"mark.bmp");

	iShowBMP(560,275,"two.bmp");

	if(f57==1) iShowBMP(560,210,"typedone.bmp");
	else if(f57==2) iShowBMP(560,210,"typedtwo.bmp");
	else if(f57==3) iShowBMP(560,210,"typedthree.bmp");
	else if(f57==4) iShowBMP(560,210,"typedfour.bmp");
	else if(f57==5) iShowBMP(560,210,"typedfive.bmp");
	else if(f57==6) iShowBMP(560,210,"typedsix.bmp");
	else if(f57==7) iShowBMP(560,210,"typedseven.bmp");
	else if(f57==8) iShowBMP(560,210,"typedeight.bmp");
	else if(f57==9) iShowBMP(560,210,"typednine.bmp");
	else iShowBMP(560,210,"grid.bmp");
	if(flagmouse==57) iShowBMP(610,256,"mark.bmp");
	
	iShowBMP(560,145,"six.bmp");


	if(f59==1) iShowBMP(560,80,"typedone.bmp");
	else if(f59==2) iShowBMP(560,80,"typedtwo.bmp");
	else if(f59==3) iShowBMP(560,80,"typedthree.bmp");
	else if(f59==4) iShowBMP(560,80,"typedfour.bmp");
	else if(f59==5) iShowBMP(560,80,"typedfive.bmp");
	else if(f59==6) iShowBMP(560,80,"typedsix.bmp");
	else if(f59==7) iShowBMP(560,80,"typedseven.bmp");
	else if(f59==8) iShowBMP(560,80,"typedeight.bmp");
	else if(f59==9) iShowBMP(560,80,"typednine.bmp");
	else iShowBMP(560,80,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==59) iShowBMP(610,127,"mark.bmp");


	// 6th column
	if(f61==1) iShowBMP(625,600,"typedone.bmp");
	else if(f61==2) iShowBMP(625,600,"typedtwo.bmp");
	else if(f61==3) iShowBMP(625,600,"typedthree.bmp");
	else if(f61==4) iShowBMP(625,600,"typedfour.bmp");
	else if(f61==5) iShowBMP(625,600,"typedfive.bmp");
	else if(f61==6) iShowBMP(625,600,"typedsix.bmp");
	else if(f61==7) iShowBMP(625,600,"typedseven.bmp");
	else if(f61==8) iShowBMP(625,600,"typedeight.bmp");
	else if(f61==9) iShowBMP(625,600,"typednine.bmp");
	else iShowBMP(625,600,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==61) iShowBMP(673,648,"mark.bmp");

	if(f62==1) iShowBMP(625,535,"typedone.bmp");
	else if(f62==2) iShowBMP(625,535,"typedtwo.bmp");
	else if(f62==3) iShowBMP(625,535,"typedthree.bmp");
	else if(f62==4) iShowBMP(625,535,"typedfour.bmp");
	else if(f62==5) iShowBMP(625,535,"typedfive.bmp");
	else if(f62==6) iShowBMP(625,535,"typedsix.bmp");
	else if(f62==7) iShowBMP(625,535,"typedseven.bmp");
	else if(f62==8) iShowBMP(625,535,"typedeight.bmp");
	else if(f62==9) iShowBMP(625,535,"typednine.bmp");
	else iShowBMP(625,535,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==62) iShowBMP(673,582,"mark.bmp");

	iShowBMP(625,470,"six.bmp");

	iShowBMP(625,405,"one.bmp");

	if(f65==1) iShowBMP(625,340,"typedone.bmp");
	else if(f65==2) iShowBMP(625,340,"typedtwo.bmp");
	else if(f65==3) iShowBMP(625,340,"typedthree.bmp");
	else if(f65==4) iShowBMP(625,340,"typedfour.bmp");
	else if(f65==5) iShowBMP(625,340,"typedfive.bmp");
	else if(f65==6) iShowBMP(625,340,"typedsix.bmp");
	else if(f65==7) iShowBMP(625,340,"typedseven.bmp");
	else if(f65==8) iShowBMP(625,340,"typedeight.bmp");
	else if(f65==9) iShowBMP(625,340,"typednine.bmp");	
	else iShowBMP(625,340,"grid.bmp");
	if (flagmouse == 65) iShowBMP(673,388,"mark.bmp");

	if(f66==1) iShowBMP(625,275,"typedone.bmp");
	else if(f66==2) iShowBMP(625,275,"typedtwo.bmp");
	else if(f66==3) iShowBMP(625,275,"typedthree.bmp");
	else if(f66==4) iShowBMP(625,275,"typedfour.bmp");
	else if(f66==5) iShowBMP(625,275,"typedfive.bmp");
	else if(f66==6) iShowBMP(625,275,"typedsix.bmp");
	else if(f66==7) iShowBMP(625,275,"typedseven.bmp");
	else if(f66==8) iShowBMP(625,275,"typedeight.bmp");
	else if(f66==9) iShowBMP(625,275,"typednine.bmp");	
	else iShowBMP(625,275,"grid.bmp");
	if (flagmouse == 66) iShowBMP(673,323,"mark.bmp");
	
	if(f67==1) iShowBMP(625,210,"typedone.bmp");
	else if(f67==2) iShowBMP(625,210,"typedtwo.bmp");
	else if(f67==3) iShowBMP(625,210,"typedthree.bmp");
	else if(f67==4) iShowBMP(625,210,"typedfour.bmp");
	else if(f67==5) iShowBMP(625,210,"typedfive.bmp");
	else if(f67==6) iShowBMP(625,210,"typedsix.bmp");
	else if(f67==7) iShowBMP(625,210,"typedseven.bmp");
	else if(f67==8) iShowBMP(625,210,"typedeight.bmp");
	else if(f67==9) iShowBMP(625,210,"typednine.bmp");
	else iShowBMP(625,210,"grid.bmp");
	if (flagmouse == 67) iShowBMP(673,256,"mark.bmp");

	if(f68==1) iShowBMP(625,145,"typedone.bmp");
	else if(f68==2) iShowBMP(625,145,"typedtwo.bmp");
	else if(f68==3) iShowBMP(625,145,"typedthree.bmp");
	else if(f68==4) iShowBMP(625,145,"typedfour.bmp");
	else if(f68==5) iShowBMP(625,145,"typedfive.bmp");
	else if(f68==6) iShowBMP(625,145,"typedsix.bmp");
	else if(f68==7) iShowBMP(625,145,"typedseven.bmp");
	else if(f68==8) iShowBMP(625,145,"typedeight.bmp");
	else if(f68==9) iShowBMP(625,145,"typednine.bmp");
	else iShowBMP(625,145,"grid.bmp");
	if (flagmouse == 68) iShowBMP(673,193,"mark.bmp");

	iShowBMP(625,80,"nine.bmp");
	
	// 7th column

	iShowBMP(690,600,"eight.bmp");

	if(f72==1) iShowBMP(690,535,"typedone.bmp");
	else if(f72==2) iShowBMP(690,535,"typedtwo.bmp");
	else if(f72==3) iShowBMP(690,535,"typedthree.bmp");
	else if(f72==4) iShowBMP(690,535,"typedfour.bmp");
	else if(f72==5) iShowBMP(690,535,"typedfive.bmp");
	else if(f72==6) iShowBMP(690,535,"typedsix.bmp");
	else if(f72==7) iShowBMP(690,535,"typedseven.bmp");
	else if(f72==8) iShowBMP(690,535,"typedeight.bmp");
	else if(f72==9) iShowBMP(690,535,"typednine.bmp");
	else iShowBMP(690,535,"grid.bmp");
	if(flagmouse == 72) iShowBMP(740,583,"mark.bmp");

	iShowBMP(690,470,"three.bmp");

	iShowBMP(690,405,"two.bmp");

	
	if(f75==1) iShowBMP(690,340,"typedone.bmp");
	else if(f75==2) iShowBMP(690,340,"typedtwo.bmp");
	else if(f75==3) iShowBMP(690,340,"typedthree.bmp");
	else if(f75==4) iShowBMP(690,340,"typedfour.bmp");
	else if(f75==5) iShowBMP(690,340,"typedfive.bmp");
	else if(f75==6) iShowBMP(690,340,"typedsix.bmp");
	else if(f75==7) iShowBMP(690,340,"typedseven.bmp");
	else if(f75==8) iShowBMP(690,340,"typedeight.bmp");
	else if(f75==9) iShowBMP(690,340,"typednine.bmp");
	else iShowBMP(690,340,"grid.bmp");
	if(flagmouse == 75)iShowBMP(740,388,"mark.bmp");
	
	if(f76==1) iShowBMP(690,275,"typedone.bmp");
	else if(f76==2) iShowBMP(690,275,"typedtwo.bmp");
	else if(f76==3) iShowBMP(690,275,"typedthree.bmp");
	else if(f76==4) iShowBMP(690,275,"typedfour.bmp");
	else if(f76==5) iShowBMP(690,275,"typedfive.bmp");
	else if(f76==6) iShowBMP(690,275,"typedsix.bmp");
	else if(f76==7) iShowBMP(690,275,"typedseven.bmp");
	else if(f76==8) iShowBMP(690,275,"typedeight.bmp");
	else if(f76==9) iShowBMP(690,275,"typednine.bmp");
	else iShowBMP(690,275,"grid.bmp");
	if(flagmouse == 76)iShowBMP(740,323,"mark.bmp");

	if(f77==1) iShowBMP(690,210,"typedone.bmp");
	else if(f77==2) iShowBMP(690,210,"typedtwo.bmp");
	else if(f77==3) iShowBMP(690,210,"typedthree.bmp");
	else if(f77==4) iShowBMP(690,210,"typedfour.bmp");
	else if(f77==5) iShowBMP(690,210,"typedfive.bmp");
	else if(f77==6) iShowBMP(690,210,"typedsix.bmp");
	else if(f77==7) iShowBMP(690,210,"typedseven.bmp");
	else if(f77==8) iShowBMP(690,210,"typedeight.bmp");
	else if(f77==9) iShowBMP(690,210,"typednine.bmp");
	else iShowBMP(690,210,"grid.bmp");
	if(flagmouse == 77)iShowBMP(740,257,"mark.bmp");

	iShowBMP(690,145,"five.bmp");
	
	if(f79==1) iShowBMP(690,80,"typedone.bmp");
	else if(f79==2) iShowBMP(690,80,"typedtwo.bmp");
	else if(f79==3) iShowBMP(690,80,"typedthree.bmp");
	else if(f79==4) iShowBMP(690,80,"typedfour.bmp");
	else if(f79==5) iShowBMP(690,80,"typedfive.bmp");
	else if(f79==6) iShowBMP(690,80,"typedsix.bmp");
	else if(f79==7) iShowBMP(690,80,"typedseven.bmp");
	else if(f79==8) iShowBMP(690,80,"typedeight.bmp");
	else if(f79==9) iShowBMP(690,80,"typednine.bmp");
	else iShowBMP(690,80,"grid.bmp");
	if(flagmouse == 79)iShowBMP(740,128,"mark.bmp");
	
	// 8th column

	if(f81==1) iShowBMP(755,600,"typedone.bmp");
	else if(f81==2) iShowBMP(755,600,"typedtwo.bmp");
	else if(f81==3) iShowBMP(755,600,"typedthree.bmp");
	else if(f81==4) iShowBMP(755,600,"typedfour.bmp");
	else if(f81==5) iShowBMP(755,600,"typedfive.bmp");
	else if(f81==6) iShowBMP(755,600,"typedsix.bmp");
	else if(f81==7) iShowBMP(755,600,"typedseven.bmp");
	else if(f81==8) iShowBMP(755,600,"typedeight.bmp");
	else if(f81==9) iShowBMP(755,600,"typednine.bmp");
	else iShowBMP(755,600,"grid.bmp");
	if (flagmouse == 81) iShowBMP(805,648,"mark.bmp");

	if(f82==1) iShowBMP(755,535,"typedone.bmp");
	else if(f82==2) iShowBMP(755,535,"typedtwo.bmp");
	else if(f82==3) iShowBMP(755,535,"typedthree.bmp");
	else if(f82==4) iShowBMP(755,535,"typedfour.bmp");
	else if(f82==5) iShowBMP(755,535,"typedfive.bmp");
	else if(f82==6) iShowBMP(755,535,"typedsix.bmp");
	else if(f82==7) iShowBMP(755,535,"typedseven.bmp");
	else if(f82==8) iShowBMP(755,535,"typedeight.bmp");
	else if(f82==9) iShowBMP(755,535,"typednine.bmp");
	else iShowBMP(755,535,"grid.bmp");
	if(flagmouse == 82) iShowBMP(805,583,"mark.bmp");

	if(f83==1) iShowBMP(755,470,"typedone.bmp");
	else if(f83==2) iShowBMP(755,470,"typedtwo.bmp");
	else if(f83==3) iShowBMP(755,470,"typedthree.bmp");
	else if(f83==4) iShowBMP(755,470,"typedfour.bmp");
	else if(f83==5) iShowBMP(755,470,"typedfive.bmp");
	else if(f83==6) iShowBMP(755,470,"typedsix.bmp");
	else if(f83==7) iShowBMP(755,470,"typedseven.bmp");
	else if(f83==8) iShowBMP(755,470,"typedeight.bmp");
	else if(f83==9) iShowBMP(755,470,"typednine.bmp");
	else iShowBMP(755,470,"grid.bmp");
	if(flagmouse == 83) iShowBMP(805,517,"mark.bmp");

	iShowBMP(755,405,"three.bmp");

	if(f85==1) iShowBMP(755,340,"typedone.bmp");
	else if(f85==2) iShowBMP(755,340,"typedtwo.bmp");
	else if(f85==3) iShowBMP(755,340,"typedthree.bmp");
	else if(f85==4) iShowBMP(755,340,"typedfour.bmp");
	else if(f85==5) iShowBMP(755,340,"typedfive.bmp");
	else if(f85==6) iShowBMP(755,340,"typedsix.bmp");
	else if(f85==7) iShowBMP(755,340,"typedseven.bmp");
	else if(f85==8) iShowBMP(755,340,"typedeight.bmp");
	else if(f85==9) iShowBMP(755,340,"typednine.bmp");
	else iShowBMP(755,340,"grid.bmp");
	if(flagmouse == 85) iShowBMP(805,388,"mark.bmp");

	iShowBMP(755,275,"four.bmp");

	iShowBMP(755,210,"one.bmp");

	iShowBMP(755,145,"two.bmp");

	iShowBMP(755,80,"eight.bmp");
	
	// 9th column

	iShowBMP(820,600,"four.bmp");

	if(f92==1) iShowBMP(820,535,"typedone.bmp");
	else if(f92==2) iShowBMP(820,535,"typedtwo.bmp");
	else if(f92==3) iShowBMP(820,535,"typedthree.bmp");
	else if(f92==4) iShowBMP(820,535,"typedfour.bmp");
	else if(f92==5) iShowBMP(820,535,"typedfive.bmp");
	else if(f92==6) iShowBMP(820,535,"typedsix.bmp");
	else if(f92==7) iShowBMP(820,535,"typedseven.bmp");
	else if(f92==8) iShowBMP(820,535,"typedeight.bmp");
	else if(f92==9) iShowBMP(820,535,"typednine.bmp");
	else iShowBMP(820,535,"grid.bmp");
	if(flagmouse == 92) iShowBMP(872,583,"mark.bmp");
	
	iShowBMP(820,470,"seven.bmp");

	iShowBMP(820,405,"eight.bmp");
	
	if(f95==1) iShowBMP(820,340,"typedone.bmp");
	else if(f95==2) iShowBMP(820,340,"typedtwo.bmp");
	else if(f95==3) iShowBMP(820,340,"typedthree.bmp");
	else if(f95==4) iShowBMP(820,340,"typedfour.bmp");
	else if(f95==5) iShowBMP(820,340,"typedfive.bmp");
	else if(f95==6) iShowBMP(820,340,"typedsix.bmp");
	else if(f95==7) iShowBMP(820,340,"typedseven.bmp");
	else if(f95==8) iShowBMP(820,340,"typedeight.bmp");
	else if(f95==9) iShowBMP(820,340,"typednine.bmp");
	else iShowBMP(820,340,"grid.bmp");
	if(flagmouse == 95) iShowBMP(872,388,"mark.bmp");
	
	if(f96==1) iShowBMP(820,275,"typedone.bmp");
	else if(f96==2) iShowBMP(820,275,"typedtwo.bmp");
	else if(f96==3) iShowBMP(820,275,"typedthree.bmp");
	else if(f96==4) iShowBMP(820,275,"typedfour.bmp");
	else if(f96==5) iShowBMP(820,275,"typedfive.bmp");
	else if(f96==6) iShowBMP(820,275,"typedsix.bmp");
	else if(f96==7) iShowBMP(820,275,"typedseven.bmp");
	else if(f96==8) iShowBMP(820,275,"typedeight.bmp");
	else if(f96==9) iShowBMP(820,275,"typednine.bmp");
	else iShowBMP(820,275,"grid.bmp");
	if(flagmouse == 96) iShowBMP(872,323,"mark.bmp");
	

	if(f97==1) iShowBMP(820,210,"typedone.bmp");
	else if(f97==2) iShowBMP(820,210,"typedtwo.bmp");
	else if(f97==3) iShowBMP(820,210,"typedthree.bmp");
	else if(f97==4) iShowBMP(820,210,"typedfour.bmp");
	else if(f97==5) iShowBMP(820,210,"typedfive.bmp");
	else if(f97==6) iShowBMP(820,210,"typedsix.bmp");
	else if(f97==7) iShowBMP(820,210,"typedseven.bmp");
	else if(f97==8) iShowBMP(820,210,"typedeight.bmp");
	else if(f97==9) iShowBMP(820,210,"typednine.bmp");
	else iShowBMP(820,210,"grid.bmp");
	if(flagmouse == 97) iShowBMP(872,256,"mark.bmp");
	
	iShowBMP(820,145,"three.bmp");
	
	if(f99==1) iShowBMP(820,80,"typedone.bmp");
	else if(f99==2) iShowBMP(820,80,"typedtwo.bmp");
	else if(f99==3) iShowBMP(820,80,"typedthree.bmp");
	else if(f99==4) iShowBMP(820,80,"typedfour.bmp");
	else if(f99==5) iShowBMP(820,80,"typedfive.bmp");
	else if(f99==6) iShowBMP(820,80,"typedsix.bmp");
	else if(f99==7) iShowBMP(820,80,"typedseven.bmp");
	else if(f99==8) iShowBMP(820,80,"typedeight.bmp");
	else if(f99==9) iShowBMP(820,80,"typednine.bmp");
	else iShowBMP(820,80,"grid.bmp");
	if(flagmouse == 99) iShowBMP(872,128,"mark.bmp");
	
}

void soln_stage5()
{
	int i,j;
	stage_sol_5[1][1] = 2;
	stage_sol_5[1][3] = 1;
	stage_sol_5[1][5] = 7;
	stage_sol_5[1][6] = 5;
	stage_sol_5[1][8] = 9;

	stage_sol_5[2][4] = 8;
	stage_sol_5[2][6] = 4;
	stage_sol_5[2][7] = 1;
	stage_sol_5[2][8] = 6;
	stage_sol_5[2][9] = 2;

	stage_sol_5[3][1] = 9;
	stage_sol_5[3][3] = 8;
	stage_sol_5[3][4] = 2;
	stage_sol_5[3][5] = 1;
	stage_sol_5[3][8] = 5;
	
	stage_sol_5[4][1] = 6;
	stage_sol_5[4][3] = 4;
	stage_sol_5[4][4] = 7;

	stage_sol_5[5][1] = 8;
	stage_sol_5[5][2] = 2;
	stage_sol_5[5][3] = 5;
	stage_sol_5[5][4] = 9;
	stage_sol_5[5][5] = 4;
	stage_sol_5[5][6] = 3;
	stage_sol_5[5][7] = 6;
	stage_sol_5[5][8] = 7;
	stage_sol_5[5][9] = 1;

	stage_sol_5[6][6] = 8;
	stage_sol_5[6][7] = 9;
	stage_sol_5[6][9] = 5;

	stage_sol_5[7][2] = 5;
	stage_sol_5[7][5] = 8;
	stage_sol_5[7][6] = 2;
	stage_sol_5[7][7] = 7;
	stage_sol_5[7][9] = 9;

	stage_sol_5[8][1] = 4;
	stage_sol_5[8][2] = 8;
	stage_sol_5[8][3] = 9;
	stage_sol_5[8][4] = 1;
	stage_sol_5[8][6] = 7;

	stage_sol_5[9][2] = 7;
	stage_sol_5[9][4] = 5;
	stage_sol_5[9][5] = 3;
	stage_sol_5[9][7] = 4;
	stage_sol_5[9][9] = 6;

	if(checkflag==1)
	{
		checkallryt=0;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(stage_sol_5[i][j]==stage5_values[i][j])
				{
					if(i==1 && j==1) iShowBMP(305,640,"green.bmp");
					if(i==3 && j==1) iShowBMP(305,510,"green.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"green.bmp");
					if(i==5 && j==1) iShowBMP(305,380,"green.bmp");
					if(i==8 && j==1) iShowBMP(305,185,"green.bmp");

					if(i==5 && j==2) iShowBMP(370,380,"green.bmp");
					if(i==7 && j==2) iShowBMP(370,250,"green.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"green.bmp");
					if(i==9 && j==2) iShowBMP(370,120,"green.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"green.bmp");
					if(i==3 && j==3) iShowBMP(435,510,"green.bmp");
					if(i==4 && j==3) iShowBMP(435,445,"green.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"green.bmp");
					if(i==8 && j==3) iShowBMP(435,185,"green.bmp");

					if(i==2 && j==4) iShowBMP(500,575,"green.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"green.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"green.bmp");
					if(i==5 && j==4) iShowBMP(500,380,"green.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"green.bmp");
					if(i==9 && j==4) iShowBMP(500,120,"green.bmp");

					if(i==1 && j==5) iShowBMP(565,640,"green.bmp");
					if(i==3 && j==5) iShowBMP(565,510,"green.bmp"); 
					if(i==5 && j==5) iShowBMP(565,380,"green.bmp");
					if(i==7 && j==5) iShowBMP(565,250,"green.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"green.bmp");

					if(i==1 && j==6) iShowBMP(630,640,"green.bmp");
					if(i==2 && j==6) iShowBMP(630,575,"green.bmp");
					if(i==5 && j==6) iShowBMP(630,380,"green.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"green.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"green.bmp");
					if(i==8 && j==6) iShowBMP(630,185,"green.bmp");

					if(i==2 && j==7) iShowBMP(695,575,"green.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"green.bmp");
					if(i==6 && j==7) iShowBMP(695,315,"green.bmp");
					if(i==7 && j==7) iShowBMP(695,250,"green.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"green.bmp");

					if(i==1 && j==8) iShowBMP(760,640,"green.bmp"); 
					if(i==2 && j==8) iShowBMP(760,575,"green.bmp");
					if(i==3 && j==8) iShowBMP(760,510,"green.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"green.bmp");

					if(i==2 && j==9) iShowBMP(825,575,"green.bmp");
					if(i==5 && j==9) iShowBMP(825,380,"green.bmp");
					if(i==6 && j==9) iShowBMP(825,315,"green.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"green.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"green.bmp");

				}
				else if(stage_sol_5[i][j]!=stage5_values[i][j])
				{
					checkallryt=1;

					if(i==1 && j==1) iShowBMP(305,640,"red.bmp");
					if(i==3 && j==1) iShowBMP(305,510,"red.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"red.bmp");
					if(i==5 && j==1) iShowBMP(305,380,"red.bmp");
					if(i==8 && j==1) iShowBMP(305,185,"red.bmp");

					if(i==5 && j==2) iShowBMP(370,380,"red.bmp");
					if(i==7 && j==2) iShowBMP(370,250,"red.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"red.bmp");
					if(i==9 && j==2) iShowBMP(370,120,"red.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"red.bmp");
					if(i==3 && j==3) iShowBMP(435,510,"red.bmp");
					if(i==4 && j==3) iShowBMP(435,445,"red.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"red.bmp");
					if(i==8 && j==3) iShowBMP(435,185,"red.bmp");

					if(i==2 && j==4) iShowBMP(500,575,"red.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"red.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"red.bmp");
					if(i==5 && j==4) iShowBMP(500,380,"red.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"red.bmp");
					if(i==9 && j==4) iShowBMP(500,120,"red.bmp");

					if(i==1 && j==5) iShowBMP(565,640,"red.bmp");
					if(i==3 && j==5) iShowBMP(565,510,"red.bmp"); 
					if(i==5 && j==5) iShowBMP(565,380,"red.bmp");
					if(i==7 && j==5) iShowBMP(565,250,"red.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"red.bmp");

					if(i==1 && j==6) iShowBMP(630,640,"red.bmp");
					if(i==2 && j==6) iShowBMP(630,575,"red.bmp");
					if(i==5 && j==6) iShowBMP(630,380,"red.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"red.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"red.bmp");
					if(i==8 && j==6) iShowBMP(630,185,"red.bmp");

					if(i==2 && j==7) iShowBMP(695,575,"red.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"red.bmp");
					if(i==6 && j==7) iShowBMP(695,315,"red.bmp");
					if(i==7 && j==7) iShowBMP(695,250,"red.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"red.bmp");

					if(i==1 && j==8) iShowBMP(760,640,"red.bmp"); 
					if(i==2 && j==8) iShowBMP(760,575,"red.bmp");
					if(i==3 && j==8) iShowBMP(760,510,"red.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"red.bmp");

					if(i==2 && j==9) iShowBMP(825,575,"red.bmp");
					if(i==5 && j==9) iShowBMP(825,380,"red.bmp");
					if(i==6 && j==9) iShowBMP(825,315,"red.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"red.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"red.bmp");
				}
			}
		}
	}

}



void stage_1()
{
	// 1st column
    iShowBMP(300,600,"five.bmp");
	iShowBMP(300,535,"six.bmp");
	
	if(f13==1) iShowBMP(300,470,"typedone.bmp");
	else if(f13==2) iShowBMP(300,470,"typedtwo.bmp");
	else if(f13==3) iShowBMP(300,470,"typedthree.bmp");
	else if(f13==4) iShowBMP(300,470,"typedfour.bmp");
	else if(f13==5) iShowBMP(300,470,"typedfive.bmp");
	else if(f13==6) iShowBMP(300,470,"typedsix.bmp");
	else if(f13==7) iShowBMP(300,470,"typedseven.bmp");
	else if(f13==8) iShowBMP(300,470,"typedeight.bmp");
	else if(f13==9) iShowBMP(300,470,"typednine.bmp");
	else iShowBMP(300,470,"grid.bmp");
    if(flagmouse==13) iShowBMP(350,518,"mark.bmp");

	iShowBMP(300,405,"eight.bmp");
	iShowBMP(300,340,"four.bmp");
	iShowBMP(300,275,"seven.bmp");

	if(f17==1) iShowBMP(300,210,"typedone.bmp");
	else if(f17==2) {iShowBMP(300,210,"typedtwo.bmp");}
	else if(f17==3) iShowBMP(300,210,"typedthree.bmp");
	else if(f17==4) iShowBMP(300,210,"typedfour.bmp");
	else if(f17==5) iShowBMP(300,210,"typedfive.bmp");
	else if(f17==6) iShowBMP(300,210,"typedsix.bmp");
	else if(f17==7) iShowBMP(300,210,"typedseven.bmp");
	else if(f17==8) iShowBMP(300,210,"typedeight.bmp");
	else if(f17==9) iShowBMP(300,210,"typednine.bmp");
	else iShowBMP(300,210,"grid.bmp");
	if(flagmouse==17) iShowBMP(350,256,"mark.bmp");
	

	if(f18==1) iShowBMP(300,145,"typedone.bmp");
	else if(f18==2) {iShowBMP(300,145,"typedtwo.bmp");}
	else if(f18==3) iShowBMP(300,145,"typedthree.bmp");
	else if(f18==4) iShowBMP(300,145,"typedfour.bmp");
	else if(f18==5) iShowBMP(300,145,"typedfive.bmp");
	else if(f18==6) iShowBMP(300,145,"typedsix.bmp");
	else if(f18==7) iShowBMP(300,145,"typedseven.bmp");
	else if(f18==8) iShowBMP(300,145,"typedeight.bmp");
	else if(f18==9) iShowBMP(300,145,"typednine.bmp");
	else iShowBMP(300,145,"grid.bmp");
	if(flagmouse==18) iShowBMP(350,194,"mark.bmp");
	
	if(f19==1) iShowBMP(300,80,"typedone.bmp");
	else if(f19==2) {iShowBMP(300,80,"typedtwo.bmp");}
	else if(f19==3) iShowBMP(300,80,"typedthree.bmp");
	else if(f19==4) iShowBMP(300,80,"typedfour.bmp");
	else if(f19==5) iShowBMP(300,80,"typedfive.bmp");
	else if(f19==6) iShowBMP(300,80,"typedsix.bmp");
	else if(f19==7) iShowBMP(300,80,"typedseven.bmp");
	else if(f19==8) iShowBMP(300,80,"typedeight.bmp");
	else if(f19==9) iShowBMP(300,80,"typednine.bmp");
	else iShowBMP(300,80,"grid.bmp");
	if(flagmouse==19) iShowBMP(350,128,"mark.bmp");

	// second column
	iShowBMP(365,600,"three.bmp");

	if(f22==1) iShowBMP(365,535,"typedone.bmp");
	else if(f22==2) {iShowBMP(365,535,"typedtwo.bmp");}
	else if(f22==3) iShowBMP(365,535,"typedthree.bmp");
	else if(f22==4) iShowBMP(365,535,"typedfour.bmp");
	else if(f22==5) iShowBMP(365,535,"typedfive.bmp");
	else if(f22==6) iShowBMP(365,535,"typedsix.bmp");
	else if(f22==7) iShowBMP(365,535,"typedseven.bmp");
	else if(f22==8) iShowBMP(365,535,"typedeight.bmp");
	else if(f22==9) iShowBMP(365,535,"typednine.bmp");
	else iShowBMP(365,535,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==22) iShowBMP(415,584,"mark.bmp");

	iShowBMP(365,470,"nine.bmp");

	if(f24==1) iShowBMP(365,405,"typedone.bmp");
	else if(f24==2) iShowBMP(365,405,"typedtwo.bmp");
	else if(f24==3) iShowBMP(365,405,"typedthree.bmp");
	else if(f24==4) iShowBMP(365,405,"typedfour.bmp");
	else if(f24==5) iShowBMP(365,405,"typedfive.bmp");
	else if(f24==6) iShowBMP(365,405,"typedsix.bmp");
	else if(f24==7) iShowBMP(365,405,"typedseven.bmp");
	else if(f24==8) iShowBMP(365,405,"typedeight.bmp");
	else if(f24==9) iShowBMP(365,405,"typednine.bmp");
	else iShowBMP(365,405,"grid.bmp");//iShowBMP(365,405,"grid.bmp");
	if(flagmouse==24) iShowBMP(415,452,"mark.bmp");


	if(f25==1) iShowBMP(365,340,"typedone.bmp");
	else if(f25==2) iShowBMP(365,340,"typedtwo.bmp");
	else if(f25==3) iShowBMP(365,340,"typedthree.bmp");
	else if(f25==4) iShowBMP(365,340,"typedfour.bmp");
	else if(f25==5) iShowBMP(365,340,"typedfive.bmp");
	else if(f25==6) iShowBMP(365,340,"typedsix.bmp");
	else if(f25==7) iShowBMP(365,340,"typedseven.bmp");
	else if(f25==8) iShowBMP(365,340,"typedeight.bmp");
	else if(f25==9) iShowBMP(365,340,"typednine.bmp");
	else iShowBMP(365,340,"grid.bmp");//iShowBMP(365,340,"grid.bmp");
	if(flagmouse==25) iShowBMP(415,388,"mark.bmp");

	if(f26==1) iShowBMP(365,275,"typedone.bmp");
	else if(f26==2) iShowBMP(365,275,"typedtwo.bmp");
	else if(f26==3) iShowBMP(365,275,"typedthree.bmp");
	else if(f26==4) iShowBMP(365,275,"typedfour.bmp");
	else if(f26==5) iShowBMP(365,275,"typedfive.bmp");
	else if(f26==6) iShowBMP(365,275,"typedsix.bmp");
	else if(f26==7) iShowBMP(365,275,"typedseven.bmp");
	else if(f26==8) iShowBMP(365,275,"typedeight.bmp");
	else if(f26==9) iShowBMP(365,275,"typednine.bmp");
	else iShowBMP(365,275,"grid.bmp");//iShowBMP(365,275,"grid.bmp");
	if(flagmouse==26) iShowBMP(415,323,"mark.bmp");

	iShowBMP(365,210,"six.bmp");

	if(f28==1) iShowBMP(365,145,"typedone.bmp");
	else if(f28==2) iShowBMP(365,145,"typedtwo.bmp");
	else if(f28==3) iShowBMP(365,145,"typedthree.bmp");
	else if(f28==4) iShowBMP(365,145,"typedfour.bmp");
	else if(f28==5) iShowBMP(365,145,"typedfive.bmp");
	else if(f28==6) iShowBMP(365,145,"typedsix.bmp");
	else if(f28==7) iShowBMP(365,145,"typedseven.bmp");
	else if(f28==8) iShowBMP(365,145,"typedeight.bmp");
	else if(f28==9) iShowBMP(365,145,"typednine.bmp");
	
	else iShowBMP(365,145,"grid.bmp");//iShowBMP(365,145,"grid.bmp");
	if(flagmouse==28) iShowBMP(415,193,"mark.bmp");

	if(f29==1) iShowBMP(365,80,"typedone.bmp");
	else if(f29==2) iShowBMP(365,80,"typedtwo.bmp");
	else if(f29==3) iShowBMP(365,80,"typedthree.bmp");
	else if(f29==4) iShowBMP(365,80,"typedfour.bmp");
	else if(f29==5) iShowBMP(365,80,"typedfive.bmp");
	else if(f29==6) iShowBMP(365,80,"typedsix.bmp");
	else if(f29==7) iShowBMP(365,80,"typedseven.bmp");
	else if(f29==8) iShowBMP(365,80,"typedeight.bmp");
	else if(f29==9) iShowBMP(365,80,"typednine.bmp");
	else iShowBMP(365,80,"grid.bmp");//iShowBMP(365,80,"grid.bmp");
	if(flagmouse==29) iShowBMP(415,128,"mark.bmp");

	// 3rd column
	if(f31==1) iShowBMP(430,600,"typedone.bmp");
	else if(f31==2) iShowBMP(430,600,"typedtwo.bmp");
	else if(f31==3) iShowBMP(430,600,"typedthree.bmp");
	else if(f31==4) iShowBMP(430,600,"typedfour.bmp");
	else if(f31==5) iShowBMP(430,600,"typedfive.bmp");
	else if(f31==6) iShowBMP(430,600,"typedsix.bmp");
	else if(f31==7) iShowBMP(430,600,"typedseven.bmp");
	else if(f31==8) iShowBMP(430,600,"typedeight.bmp");
	else if(f31==9) iShowBMP(430,600,"typednine.bmp");
	else iShowBMP(430,600,"grid.bmp");//iShowBMP(430,600,"grid.bmp");
	if(flagmouse==31) iShowBMP(478,648,"mark.bmp");

	if(f32==1) iShowBMP(430,535,"typedone.bmp");
	else if(f32==2) iShowBMP(430,535,"typedtwo.bmp");
	else if(f32==3) iShowBMP(430,535,"typedthree.bmp");
	else if(f32==4) iShowBMP(430,535,"typedfour.bmp");
	else if(f32==5) iShowBMP(430,535,"typedfive.bmp");
	else if(f32==6) iShowBMP(430,535,"typedsix.bmp");
	else if(f32==7) iShowBMP(430,535,"typedseven.bmp");
	else if(f32==8) iShowBMP(430,535,"typedeight.bmp");
	else if(f32==9) iShowBMP(430,535,"typednine.bmp");
	else iShowBMP(430,535,"grid.bmp");//iShowBMP(430,535,"grid.bmp");
	if(flagmouse==32) iShowBMP(478,583,"mark.bmp");

	iShowBMP(430,470,"eight.bmp");

	if(f34==1) iShowBMP(430,405,"typedone.bmp");
	else if(f34==2) iShowBMP(430,405,"typedtwo.bmp");
	else if(f34==3) iShowBMP(430,405,"typedthree.bmp");
	else if(f34==4) iShowBMP(430,405,"typedfour.bmp");
	else if(f34==5) iShowBMP(430,405,"typedfive.bmp");
	else if(f34==6) iShowBMP(430,405,"typedsix.bmp");
	else if(f34==7) iShowBMP(430,405,"typedseven.bmp");
	else if(f34==8) iShowBMP(430,405,"typedeight.bmp");
	else if(f34==9) iShowBMP(430,405,"typednine.bmp");
	else iShowBMP(430,405,"grid.bmp");//iShowBMP(430,405,"grid.bmp");
	if(flagmouse==34) iShowBMP(478,451,"mark.bmp");

	if(f35==1) iShowBMP(430,340,"typedone.bmp");
	else if(f35==2) iShowBMP(430,340,"typedtwo.bmp");
	else if(f35==3) iShowBMP(430,340,"typedthree.bmp");
	else if(f35==4) iShowBMP(430,340,"typedfour.bmp");
	else if(f35==5) iShowBMP(430,340,"typedfive.bmp");
	else if(f35==6) iShowBMP(430,340,"typedsix.bmp");
	else if(f35==7) iShowBMP(430,340,"typedseven.bmp");
	else if(f35==8) iShowBMP(430,340,"typedeight.bmp");
	else if(f35==9) iShowBMP(430,340,"typednine.bmp");
	else iShowBMP(430,340,"grid.bmp");//iShowBMP(430,340,"grid.bmp");
	if(flagmouse==35) iShowBMP(478,388,"mark.bmp");

	if(f36==1) iShowBMP(430,275,"typedone.bmp");
	else if(f36==2) iShowBMP(430,275,"typedtwo.bmp");
	else if(f36==3) iShowBMP(430,275,"typedthree.bmp");
	else if(f36==4) iShowBMP(430,275,"typedfour.bmp");
	else if(f36==5) iShowBMP(430,275,"typedfive.bmp");
	else if(f36==6) iShowBMP(430,275,"typedsix.bmp");
	else if(f36==7) iShowBMP(430,275,"typedseven.bmp");
	else if(f36==8) iShowBMP(430,275,"typedeight.bmp");
	else if(f36==9) iShowBMP(430,275,"typednine.bmp");
	else iShowBMP(430,275,"grid.bmp");//iShowBMP(430,275,"grid.bmp");
	if(flagmouse==36) iShowBMP(478,323,"mark.bmp");

	if(f37==1) iShowBMP(430,210,"typedone.bmp");
	else if(f37==2) iShowBMP(430,210,"typedtwo.bmp");
	else if(f37==3) iShowBMP(430,210,"typedthree.bmp");
	else if(f37==4) iShowBMP(430,210,"typedfour.bmp");
	else if(f37==5) iShowBMP(430,210,"typedfive.bmp");
	else if(f37==6) iShowBMP(430,210,"typedsix.bmp");
	else if(f37==7) iShowBMP(430,210,"typedseven.bmp");
	else if(f37==8) iShowBMP(430,210,"typedeight.bmp");
	else if(f37==9) iShowBMP(430,210,"typednine.bmp");
	else iShowBMP(430,210,"grid.bmp");//iShowBMP(430,210,"grid.bmp");
	if(flagmouse==37) iShowBMP(478,256,"mark.bmp");

	if(f38==1) iShowBMP(430,145,"typedone.bmp");
	else if(f38==2) iShowBMP(430,145,"typedtwo.bmp");
	else if(f38==3) iShowBMP(430,145,"typedthree.bmp");
	else if(f38==4) iShowBMP(430,145,"typedfour.bmp");
	else if(f38==5) iShowBMP(430,145,"typedfive.bmp");
	else if(f38==6) iShowBMP(430,145,"typedsix.bmp");
	else if(f38==7) iShowBMP(430,145,"typedseven.bmp");
	else if(f38==8) iShowBMP(430,145,"typedeight.bmp");
	else if(f38==9) iShowBMP(430,145,"typednine.bmp");
	else iShowBMP(430,145,"grid.bmp");//iShowBMP(430,145,"grid.bmp");
	if(flagmouse==38) iShowBMP(478,193,"mark.bmp");

	if(f39==1) iShowBMP(430,80,"typedone.bmp");
	else if(f39==2) iShowBMP(430,80,"typedtwo.bmp");
	else if(f39==3) iShowBMP(430,80,"typedthree.bmp");
	else if(f39==4) iShowBMP(430,80,"typedfour.bmp");
	else if(f39==5) iShowBMP(430,80,"typedfive.bmp");
	else if(f39==6) iShowBMP(430,80,"typedsix.bmp");
	else if(f39==7) iShowBMP(430,80,"typedseven.bmp");
	else if(f39==8) iShowBMP(430,80,"typedeight.bmp");
	else if(f39==9) iShowBMP(430,80,"typednine.bmp");
	else iShowBMP(430,80,"grid.bmp");//iShowBMP(430,80,"grid.bmp");
	if(flagmouse==39) iShowBMP(478,128,"mark.bmp");

	// 4th column
	if(f41==1) iShowBMP(495,600,"typedone.bmp");
	else if(f41==2) iShowBMP(495,600,"typedtwo.bmp");
	else if(f41==3) iShowBMP(495,600,"typedthree.bmp");
	else if(f41==4) iShowBMP(495,600,"typedfour.bmp");
	else if(f41==5) iShowBMP(495,600,"typedfive.bmp");
	else if(f41==6) iShowBMP(495,600,"typedsix.bmp");
	else if(f41==7) iShowBMP(495,600,"typedseven.bmp");
	else if(f41==8) iShowBMP(495,600,"typedeight.bmp");
	else if(f41==9) iShowBMP(495,600,"typednine.bmp");
	else iShowBMP(495,600,"grid.bmp");//iShowBMP(495,600,"grid.bmp");
	if(flagmouse==41) iShowBMP(545,648,"mark.bmp");

	iShowBMP(495,535,"one.bmp");

	if(f43==1) iShowBMP(495,470,"typedone.bmp");
	else if(f43==2) iShowBMP(495,470,"typedtwo.bmp");
	else if(f43==3) iShowBMP(495,470,"typedthree.bmp");
	else if(f43==4) iShowBMP(495,470,"typedfour.bmp");
	else if(f43==5) iShowBMP(495,470,"typedfive.bmp");
	else if(f43==6) iShowBMP(495,470,"typedsix.bmp");
	else if(f43==7) iShowBMP(495,470,"typedseven.bmp");
	else if(f43==8) iShowBMP(495,470,"typedeight.bmp");
	else if(f43==9) iShowBMP(495,470,"typednine.bmp");
	else iShowBMP(495,470,"grid.bmp");//iShowBMP(495,470,"grid.bmp");
	if(flagmouse==43) iShowBMP(545,518,"mark.bmp");

	if(f44==1) iShowBMP(495,405,"typedone.bmp");
	else if(f44==2) iShowBMP(495,405,"typedtwo.bmp");
	else if(f44==3) iShowBMP(495,405,"typedthree.bmp");
	else if(f44==4) iShowBMP(495,405,"typedfour.bmp");
	else if(f44==5) iShowBMP(495,405,"typedfive.bmp");
	else if(f44==6) iShowBMP(495,405,"typedsix.bmp");
	else if(f44==7) iShowBMP(495,405,"typedseven.bmp");
	else if(f44==8) iShowBMP(495,405,"typedeight.bmp");
	else if(f44==9) iShowBMP(495,405,"typednine.bmp");
	else iShowBMP(495,405,"grid.bmp");//iShowBMP(495,405,"grid.bmp");
	if(flagmouse==44) iShowBMP(545,451,"mark.bmp");

	iShowBMP(495,340,"eight.bmp");

	if(f46==1) iShowBMP(495,275,"typedone.bmp");
	else if(f46==2) iShowBMP(495,275,"typedtwo.bmp");
	else if(f46==3) iShowBMP(495,275,"typedthree.bmp");
	else if(f46==4) iShowBMP(495,275,"typedfour.bmp");
	else if(f46==5) iShowBMP(495,275,"typedfive.bmp");
	else if(f46==6) iShowBMP(495,275,"typedsix.bmp");
	else if(f46==7) iShowBMP(495,275,"typedseven.bmp");
	else if(f46==8) iShowBMP(495,275,"typedeight.bmp");
	else if(f46==9) iShowBMP(495,275,"typednine.bmp");
	else iShowBMP(495,275,"grid.bmp");//iShowBMP(495,275,"grid.bmp");
	if(flagmouse==46) iShowBMP(545,323,"mark.bmp");

	if(f47==1) iShowBMP(495,210,"typedone.bmp");
	else if(f47==2) iShowBMP(495,210,"typedtwo.bmp");
	else if(f47==3) iShowBMP(495,210,"typedthree.bmp");
	else if(f47==4) iShowBMP(495,210,"typedfour.bmp");
	else if(f47==5) iShowBMP(495,210,"typedfive.bmp");
	else if(f47==6) iShowBMP(495,210,"typedsix.bmp");
	else if(f47==7) iShowBMP(495,210,"typedseven.bmp");
	else if(f47==8) iShowBMP(495,210,"typedeight.bmp");
	else if(f47==9) iShowBMP(495,210,"typednine.bmp");
	else iShowBMP(495,210,"grid.bmp");//iShowBMP(495,210,"grid.bmp");
	if(flagmouse==47) iShowBMP(545,256,"mark.bmp");

	iShowBMP(495,145,"four.bmp");

	if(f49==1) iShowBMP(495,80,"typedone.bmp");
	else if(f49==2) iShowBMP(495,80,"typedtwo.bmp");
	else if(f49==3) iShowBMP(495,80,"typedthree.bmp");
	else if(f49==4) iShowBMP(495,80,"typedfour.bmp");
	else if(f49==5) iShowBMP(495,80,"typedfive.bmp");
	else if(f49==6) iShowBMP(495,80,"typedsix.bmp");
	else if(f49==7) iShowBMP(495,80,"typedseven.bmp");
	else if(f49==8) iShowBMP(495,80,"typedeight.bmp");
	else if(f49==9) iShowBMP(495,80,"typednine.bmp");
	else iShowBMP(495,80,"grid.bmp");//iShowBMP(495,80,"grid.bmp");
	if(flagmouse==49) iShowBMP(545,128,"mark.bmp");

	// 5th column
	iShowBMP(560,600,"seven.bmp");
	iShowBMP(560,535,"nine.bmp");

	if(f53==1) iShowBMP(560,470,"typedone.bmp");
	else if(f53==2) iShowBMP(560,470,"typedtwo.bmp");
	else if(f53==3) iShowBMP(560,470,"typedthree.bmp");
	else if(f53==4) iShowBMP(560,470,"typedfour.bmp");
	else if(f53==5) iShowBMP(560,470,"typedfive.bmp");
	else if(f53==6) iShowBMP(560,470,"typedsix.bmp");
	else if(f53==7) iShowBMP(560,470,"typedseven.bmp");
	else if(f53==8) iShowBMP(560,470,"typedeight.bmp");
	else if(f53==9) iShowBMP(560,470,"typednine.bmp");
	else iShowBMP(560,470,"grid.bmp");//iShowBMP(560,470,"grid.bmp");
	if(flagmouse==53) iShowBMP(610,518,"mark.bmp");

	iShowBMP(560,405,"six.bmp");

	if(f55==1) iShowBMP(560,340,"typedone.bmp");
	else if(f55==2) iShowBMP(560,340,"typedtwo.bmp");
	else if(f55==3) iShowBMP(560,340,"typedthree.bmp");
	else if(f55==4) iShowBMP(560,340,"typedfour.bmp");
	else if(f55==5) iShowBMP(560,340,"typedfive.bmp");
	else if(f55==6) iShowBMP(560,340,"typedsix.bmp");
	else if(f55==7) iShowBMP(560,340,"typedseven.bmp");
	else if(f55==8) iShowBMP(560,340,"typedeight.bmp");
	else if(f55==9) iShowBMP(560,340,"typednine.bmp");
	else iShowBMP(560,340,"grid.bmp");//iShowBMP(560,340,"grid.bmp");
	if(flagmouse==55) iShowBMP(610,388,"mark.bmp");

	iShowBMP(560,275,"two.bmp");

	if(f57==1) iShowBMP(560,210,"typedone.bmp");
	else if(f57==2) iShowBMP(560,210,"typedtwo.bmp");
	else if(f57==3) iShowBMP(560,210,"typedthree.bmp");
	else if(f57==4) iShowBMP(560,210,"typedfour.bmp");
	else if(f57==5) iShowBMP(560,210,"typedfive.bmp");
	else if(f57==6) iShowBMP(560,210,"typedsix.bmp");
	else if(f57==7) iShowBMP(560,210,"typedseven.bmp");
	else if(f57==8) iShowBMP(560,210,"typedeight.bmp");
	else if(f57==9) iShowBMP(560,210,"typednine.bmp");
	else iShowBMP(560,210,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==57) iShowBMP(610,256,"mark.bmp");

	iShowBMP(560,145,"one.bmp");
	iShowBMP(560,80,"eight.bmp");

	// 6th column
	if(f61==1) iShowBMP(625,600,"typedone.bmp");
	else if(f61==2) iShowBMP(625,600,"typedtwo.bmp");
	else if(f61==3) iShowBMP(625,600,"typedthree.bmp");
	else if(f61==4) iShowBMP(625,600,"typedfour.bmp");
	else if(f61==5) iShowBMP(625,600,"typedfive.bmp");
	else if(f61==6) iShowBMP(625,600,"typedsix.bmp");
	else if(f61==7) iShowBMP(625,600,"typedseven.bmp");
	else if(f61==8) iShowBMP(625,600,"typedeight.bmp");
	else if(f61==9) iShowBMP(625,600,"typednine.bmp");
	else iShowBMP(625,600,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==61) iShowBMP(673,648,"mark.bmp");

	iShowBMP(625,535,"five.bmp");

	if(f63==1) iShowBMP(625,470,"typedone.bmp");
	else if(f63==2) iShowBMP(625,470,"typedtwo.bmp");
	else if(f63==3) iShowBMP(625,470,"typedthree.bmp");
	else if(f63==4) iShowBMP(625,470,"typedfour.bmp");
	else if(f63==5) iShowBMP(625,470,"typedfive.bmp");
	else if(f63==6) iShowBMP(625,470,"typedsix.bmp");
	else if(f63==7) iShowBMP(625,470,"typedseven.bmp");
	else if(f63==8) iShowBMP(625,470,"typedeight.bmp");
	else if(f63==9) iShowBMP(625,470,"typednine.bmp");
	else iShowBMP(625,470,"grid.bmp");
	if(flagmouse == 63) iShowBMP(673,518,"mark.bmp");

	if(f64==1) iShowBMP(625,405,"typedone.bmp");
	else if(f64==2) iShowBMP(625,405,"typedtwo.bmp");
	else if(f64==3) iShowBMP(625,405,"typedthree.bmp");
	else if(f64==4) iShowBMP(625,405,"typedfour.bmp");
	else if(f64==5) iShowBMP(625,405,"typedfive.bmp");
	else if(f64==6) iShowBMP(625,405,"typedsix.bmp");
	else if(f64==7) iShowBMP(625,405,"typedseven.bmp");
	else if(f64==8) iShowBMP(625,405,"typedeight.bmp");
	else if(f64==9) iShowBMP(625,405,"typednine.bmp");
	else iShowBMP(625,405,"grid.bmp");
	if(flagmouse == 64) iShowBMP(673,451,"mark.bmp");
	
	
	iShowBMP(625,340,"three.bmp");

	if(f66==1) iShowBMP(625,275,"typedone.bmp");
	else if(f66==2) iShowBMP(625,275,"typedtwo.bmp");
	else if(f66==3) iShowBMP(625,275,"typedthree.bmp");
	else if(f66==4) iShowBMP(625,275,"typedfour.bmp");
	else if(f66==5) iShowBMP(625,275,"typedfive.bmp");
	else if(f66==6) iShowBMP(625,275,"typedsix.bmp");
	else if(f66==7) iShowBMP(625,275,"typedseven.bmp");
	else if(f66==8) iShowBMP(625,275,"typedeight.bmp");
	else if(f66==9) iShowBMP(625,275,"typednine.bmp");	
	else iShowBMP(625,275,"grid.bmp");
	if (flagmouse == 66) iShowBMP(673,323,"mark.bmp");
	
	if(f67==1) iShowBMP(625,210,"typedone.bmp");
	else if(f67==2) iShowBMP(625,210,"typedtwo.bmp");
	else if(f67==3) iShowBMP(625,210,"typedthree.bmp");
	else if(f67==4) iShowBMP(625,210,"typedfour.bmp");
	else if(f67==5) iShowBMP(625,210,"typedfive.bmp");
	else if(f67==6) iShowBMP(625,210,"typedsix.bmp");
	else if(f67==7) iShowBMP(625,210,"typedseven.bmp");
	else if(f67==8) iShowBMP(625,210,"typedeight.bmp");
	else if(f67==9) iShowBMP(625,210,"typednine.bmp");
	else iShowBMP(625,210,"grid.bmp");
	if(flagmouse == 67) iShowBMP(673,256,"mark.bmp");

	iShowBMP(625,145,"nine.bmp");

	if(f69==1) iShowBMP(625,80,"typedone.bmp");
	else if(f69==2) iShowBMP(625,80,"typedtwo.bmp");
	else if(f69==3) iShowBMP(625,80,"typedthree.bmp");
	else if(f69==4) iShowBMP(625,80,"typedfour.bmp");
	else if(f69==5) iShowBMP(625,80,"typedfive.bmp");
	else if(f69==6) iShowBMP(625,80,"typedsix.bmp");
	else if(f69==7) iShowBMP(625,80,"typedseven.bmp");
	else if(f69==8) iShowBMP(625,80,"typedeight.bmp");
	else if(f69==9) iShowBMP(625,80,"typednine.bmp");
	else iShowBMP(625,80,"grid.bmp");
	if (flagmouse == 69) iShowBMP(673,128,"mark.bmp");
	
	// 7th column

	if(f71==1) iShowBMP(690,600,"typedone.bmp");
	else if(f71==2) iShowBMP(690,600,"typedtwo.bmp");
	else if(f71==3) iShowBMP(690,600,"typedthree.bmp");
	else if(f71==4) iShowBMP(690,600,"typedfour.bmp");
	else if(f71==5) iShowBMP(690,600,"typedfive.bmp");
	else if(f71==6) iShowBMP(690,600,"typedsix.bmp");
	else if(f71==7) iShowBMP(690,600,"typedseven.bmp");
	else if(f71==8) iShowBMP(690,600,"typedeight.bmp");
	else if(f71==9) iShowBMP(690,600,"typednine.bmp");
	else iShowBMP(690,600,"grid.bmp");
	if (flagmouse == 71) iShowBMP(740,648,"mark.bmp");

	if(f72==1) iShowBMP(690,535,"typedone.bmp");
	else if(f72==2) iShowBMP(690,535,"typedtwo.bmp");
	else if(f72==3) iShowBMP(690,535,"typedthree.bmp");
	else if(f72==4) iShowBMP(690,535,"typedfour.bmp");
	else if(f72==5) iShowBMP(690,535,"typedfive.bmp");
	else if(f72==6) iShowBMP(690,535,"typedsix.bmp");
	else if(f72==7) iShowBMP(690,535,"typedseven.bmp");
	else if(f72==8) iShowBMP(690,535,"typedeight.bmp");
	else if(f72==9) iShowBMP(690,535,"typednine.bmp");
	else iShowBMP(690,535,"grid.bmp");
	if(flagmouse == 72) iShowBMP(740,583,"mark.bmp");

	if(f73==1) iShowBMP(690,470,"typedone.bmp");
	else if(f73==2) iShowBMP(690,470,"typedtwo.bmp");
	else if(f73==3) iShowBMP(690,470,"typedthree.bmp");
	else if(f73==4) iShowBMP(690,470,"typedfour.bmp");
	else if(f73==5) iShowBMP(690,470,"typedfive.bmp");
	else if(f73==6) iShowBMP(690,470,"typedsix.bmp");
	else if(f73==7) iShowBMP(690,470,"typedseven.bmp");
	else if(f73==8) iShowBMP(690,470,"typedeight.bmp");
	else if(f73==9) iShowBMP(690,470,"typednine.bmp");
	else iShowBMP(690,470,"grid.bmp");
	if(flagmouse == 73) iShowBMP(740,518,"mark.bmp");

	if(f74==1) iShowBMP(690,405,"typedone.bmp");
	else if(f74==2) iShowBMP(690,405,"typedtwo.bmp");
	else if(f74==3) iShowBMP(690,405,"typedthree.bmp");
	else if(f74==4) iShowBMP(690,405,"typedfour.bmp");
	else if(f74==5) iShowBMP(690,405,"typedfive.bmp");
	else if(f74==6) iShowBMP(690,405,"typedsix.bmp");
	else if(f74==7) iShowBMP(690,405,"typedseven.bmp");
	else if(f74==8) iShowBMP(690,405,"typedeight.bmp");
	else if(f74==9) iShowBMP(690,405,"typednine.bmp");
	else iShowBMP(690,405,"grid.bmp");
	if(flagmouse == 74) iShowBMP(740,451,"mark.bmp");
	
	if(f75==1) iShowBMP(690,340,"typedone.bmp");
	else if(f75==2) iShowBMP(690,340,"typedtwo.bmp");
	else if(f75==3) iShowBMP(690,340,"typedthree.bmp");
	else if(f75==4) iShowBMP(690,340,"typedfour.bmp");
	else if(f75==5) iShowBMP(690,340,"typedfive.bmp");
	else if(f75==6) iShowBMP(690,340,"typedsix.bmp");
	else if(f75==7) iShowBMP(690,340,"typedseven.bmp");
	else if(f75==8) iShowBMP(690,340,"typedeight.bmp");
	else if(f75==9) iShowBMP(690,340,"typednine.bmp");
	else iShowBMP(690,340,"grid.bmp");
	if(flagmouse == 75)iShowBMP(740,388,"mark.bmp");
	
	if(f76==1) iShowBMP(690,275,"typedone.bmp");
	else if(f76==2) iShowBMP(690,275,"typedtwo.bmp");
	else if(f76==3) iShowBMP(690,275,"typedthree.bmp");
	else if(f76==4) iShowBMP(690,275,"typedfour.bmp");
	else if(f76==5) iShowBMP(690,275,"typedfive.bmp");
	else if(f76==6) iShowBMP(690,275,"typedsix.bmp");
	else if(f76==7) iShowBMP(690,275,"typedseven.bmp");
	else if(f76==8) iShowBMP(690,275,"typedeight.bmp");
	else if(f76==9) iShowBMP(690,275,"typednine.bmp");
	else iShowBMP(690,275,"grid.bmp");
	if(flagmouse == 76) iShowBMP(740,323,"mark.bmp");

	iShowBMP(690,210,"two.bmp");

	if(f78==1) iShowBMP(690,145,"typedone.bmp");
	else if(f78==2) iShowBMP(690,145,"typedtwo.bmp");
	else if(f78==3) iShowBMP(690,145,"typedthree.bmp");
	else if(f78==4) iShowBMP(690,145,"typedfour.bmp");
	else if(f78==5) iShowBMP(690,145,"typedfive.bmp");
	else if(f78==6) iShowBMP(690,145,"typedsix.bmp");
	else if(f78==7) iShowBMP(690,145,"typedseven.bmp");
	else if(f78==8) iShowBMP(690,145,"typedeight.bmp");
	else if(f78==9) iShowBMP(690,145,"typednine.bmp");
	else iShowBMP(690,145,"grid.bmp");
	if(flagmouse == 78) iShowBMP(740,193,"mark.bmp");
	
	if(f79==1) iShowBMP(690,80,"typedone.bmp");
	else if(f79==2) iShowBMP(690,80,"typedtwo.bmp");
	else if(f79==3) iShowBMP(690,80,"typedthree.bmp");
	else if(f79==4) iShowBMP(690,80,"typedfour.bmp");
	else if(f79==5) iShowBMP(690,80,"typedfive.bmp");
	else if(f79==6) iShowBMP(690,80,"typedsix.bmp");
	else if(f79==7) iShowBMP(690,80,"typedseven.bmp");
	else if(f79==8) iShowBMP(690,80,"typedeight.bmp");
	else if(f79==9) iShowBMP(690,80,"typednine.bmp");
	else iShowBMP(690,80,"grid.bmp");
	if(flagmouse == 79) iShowBMP(740,128,"mark.bmp");
	
	// 8th column

	if(f81==1) iShowBMP(755,600,"typedone.bmp");
	else if(f81==2) iShowBMP(755,600,"typedtwo.bmp");
	else if(f81==3) iShowBMP(755,600,"typedthree.bmp");
	else if(f81==4) iShowBMP(755,600,"typedfour.bmp");
	else if(f81==5) iShowBMP(755,600,"typedfive.bmp");
	else if(f81==6) iShowBMP(755,600,"typedsix.bmp");
	else if(f81==7) iShowBMP(755,600,"typedseven.bmp");
	else if(f81==8) iShowBMP(755,600,"typedeight.bmp");
	else if(f81==9) iShowBMP(755,600,"typednine.bmp");
	else iShowBMP(755,600,"grid.bmp");
	if (flagmouse == 81) iShowBMP(805,648,"mark.bmp");

	if(f82==1) iShowBMP(755,535,"typedone.bmp");
	else if(f82==2) iShowBMP(755,535,"typedtwo.bmp");
	else if(f82==3) iShowBMP(755,535,"typedthree.bmp");
	else if(f82==4) iShowBMP(755,535,"typedfour.bmp");
	else if(f82==5) iShowBMP(755,535,"typedfive.bmp");
	else if(f82==6) iShowBMP(755,535,"typedsix.bmp");
	else if(f82==7) iShowBMP(755,535,"typedseven.bmp");
	else if(f82==8) iShowBMP(755,535,"typedeight.bmp");
	else if(f82==9) iShowBMP(755,535,"typednine.bmp");
	else iShowBMP(755,535,"grid.bmp");
	if(flagmouse == 82) iShowBMP(805,583,"mark.bmp");

	iShowBMP(755,470,"six.bmp");

	if(f84==1) iShowBMP(755,405,"typedone.bmp");
	else if(f84==2) iShowBMP(755,405,"typedtwo.bmp");
	else if(f84==3) iShowBMP(755,405,"typedthree.bmp");
	else if(f84==4) iShowBMP(755,405,"typedfour.bmp");
	else if(f84==5) iShowBMP(755,405,"typedfive.bmp");
	else if(f84==6) iShowBMP(755,405,"typedsix.bmp");
	else if(f84==7) iShowBMP(755,405,"typedseven.bmp");
	else if(f84==8) iShowBMP(755,405,"typedeight.bmp");
	else if(f84==9) iShowBMP(755,405,"typednine.bmp");
	else iShowBMP(755,405,"grid.bmp");
	if(flagmouse == 84) iShowBMP(805,451,"mark.bmp");

	if(f85==1) iShowBMP(755,340,"typedone.bmp");
	else if(f85==2) iShowBMP(755,340,"typedtwo.bmp");
	else if(f85==3) iShowBMP(755,340,"typedthree.bmp");
	else if(f85==4) iShowBMP(755,340,"typedfour.bmp");
	else if(f85==5) iShowBMP(755,340,"typedfive.bmp");
	else if(f85==6) iShowBMP(755,340,"typedsix.bmp");
	else if(f85==7) iShowBMP(755,340,"typedseven.bmp");
	else if(f85==8) iShowBMP(755,340,"typedeight.bmp");
	else if(f85==9) iShowBMP(755,340,"typednine.bmp");
	else iShowBMP(755,340,"grid.bmp");
	if(flagmouse == 85) iShowBMP(805,388,"mark.bmp");

	if(f86==1) iShowBMP(755,275,"typedone.bmp");
	else if(f86==2) iShowBMP(755,275,"typedtwo.bmp");
	else if(f86==3) iShowBMP(755,275,"typedthree.bmp");
	else if(f86==4) iShowBMP(755,275,"typedfour.bmp");
	else if(f86==5) iShowBMP(755,275,"typedfive.bmp");
	else if(f86==6) iShowBMP(755,275,"typedsix.bmp");
	else if(f86==7) iShowBMP(755,275,"typedseven.bmp");
	else if(f86==8) iShowBMP(755,275,"typedeight.bmp");
	else if(f86==9) iShowBMP(755,275,"typednine.bmp");
	else iShowBMP(755,275,"grid.bmp");
	if(flagmouse == 86) iShowBMP(805,323,"mark.bmp");

	iShowBMP(755,210,"eight.bmp");

	if(f88==1) iShowBMP(755,145,"typedone.bmp");
	else if(f88==2) iShowBMP(755,145,"typedtwo.bmp");
	else if(f88==3) iShowBMP(755,145,"typedthree.bmp");
	else if(f88==4) iShowBMP(755,145,"typedfour.bmp");
	else if(f88==5) iShowBMP(755,145,"typedfive.bmp");
	else if(f88==6) iShowBMP(755,145,"typedsix.bmp");
	else if(f88==7) iShowBMP(755,145,"typedseven.bmp");
	else if(f88==8) iShowBMP(755,145,"typedeight.bmp");
	else if(f88==9) iShowBMP(755,145,"typednine.bmp");
	else iShowBMP(755,145,"grid.bmp");
	if(flagmouse == 88) iShowBMP(805,193,"mark.bmp");

	iShowBMP(755,80,"seven.bmp");

	// 9th column
	if(f91==1) iShowBMP(820,600,"typedone.bmp");
	else if(f91==2) iShowBMP(820,600,"typedtwo.bmp");
	else if(f91==3) iShowBMP(820,600,"typedthree.bmp");
	else if(f91==4) iShowBMP(820,600,"typedfour.bmp");
	else if(f91==5) iShowBMP(820,600,"typedfive.bmp");
	else if(f91==6) iShowBMP(820,600,"typedsix.bmp");
	else if(f91==7) iShowBMP(820,600,"typedseven.bmp");
	else if(f91==8) iShowBMP(820,600,"typedeight.bmp");
	else if(f91==9) iShowBMP(820,600,"typednine.bmp");
	else iShowBMP(820,600,"grid.bmp");
	if(flagmouse == 91) iShowBMP(872,648,"mark.bmp");

	if(f92==1) iShowBMP(820,535,"typedone.bmp");
	else if(f92==2) iShowBMP(820,535,"typedtwo.bmp");
	else if(f92==3) iShowBMP(820,535,"typedthree.bmp");
	else if(f92==4) iShowBMP(820,535,"typedfour.bmp");
	else if(f92==5) iShowBMP(820,535,"typedfive.bmp");
	else if(f92==6) iShowBMP(820,535,"typedsix.bmp");
	else if(f92==7) iShowBMP(820,535,"typedseven.bmp");
	else if(f92==8) iShowBMP(820,535,"typedeight.bmp");
	else if(f92==9) iShowBMP(820,535,"typednine.bmp");
	else iShowBMP(820,535,"grid.bmp");
	if(flagmouse == 92) iShowBMP(872,583,"mark.bmp");
	
	if(f93==1) iShowBMP(820,470,"typedone.bmp");
	else if(f93==2) iShowBMP(820,470,"typedtwo.bmp");
	else if(f93==3) iShowBMP(820,470,"typedthree.bmp");
	else if(f93==4) iShowBMP(820,470,"typedfour.bmp");
	else if(f93==5) iShowBMP(820,470,"typedfive.bmp");
	else if(f93==6) iShowBMP(820,470,"typedsix.bmp");
	else if(f93==7) iShowBMP(820,470,"typedseven.bmp");
	else if(f93==8) iShowBMP(820,470,"typedeight.bmp");
	else if(f93==9) iShowBMP(820,470,"typednine.bmp");
	else iShowBMP(820,470,"grid.bmp");
	if(flagmouse == 93) iShowBMP(872,518,"mark.bmp");
	

	iShowBMP(820,405,"three.bmp");
	iShowBMP(820,340,"one.bmp");
	iShowBMP(820,275,"six.bmp");

	if(f97==1) iShowBMP(820,210,"typedone.bmp");
	else if(f97==2) iShowBMP(820,210,"typedtwo.bmp");
	else if(f97==3) iShowBMP(820,210,"typedthree.bmp");
	else if(f97==4) iShowBMP(820,210,"typedfour.bmp");
	else if(f97==5) iShowBMP(820,210,"typedfive.bmp");
	else if(f97==6) iShowBMP(820,210,"typedsix.bmp");
	else if(f97==7) iShowBMP(820,210,"typedseven.bmp");
	else if(f97==8) iShowBMP(820,210,"typedeight.bmp");
	else if(f97==9) iShowBMP(820,210,"typednine.bmp");
	else iShowBMP(820,210,"grid.bmp");
	if(flagmouse == 97) iShowBMP(872,256,"mark.bmp");
	

	iShowBMP(820,145,"five.bmp");
	iShowBMP(820,80,"nine.bmp");

}


void soln_stage1()
{
	int i,j;
	stage_sol_1[1][3] = 4;
	stage_sol_1[1][4] = 6;
	stage_sol_1[1][6] = 8;
	stage_sol_1[1][7] = 9;
	stage_sol_1[1][8] = 1;
	stage_sol_1[1][9] = 2;

	stage_sol_1[2][2] = 7;
	stage_sol_1[2][3] = 2;

	stage_sol_1[2][7] = 3;
	stage_sol_1[2][8] = 4;
	stage_sol_1[2][9] = 8;

	stage_sol_1[3][1] = 1;
	stage_sol_1[3][4] = 3;
	stage_sol_1[3][5] = 4;
	stage_sol_1[3][6] = 2;
	stage_sol_1[3][7] = 5;
	stage_sol_1[3][9] = 7;

	stage_sol_1[4][2] = 5;
	stage_sol_1[4][3] = 9;
	stage_sol_1[4][4] = 7;
	stage_sol_1[4][6] = 1;
	stage_sol_1[4][7] = 4;
	stage_sol_1[4][8] = 2;

	stage_sol_1[5][2] = 2;
	stage_sol_1[5][3] = 6;
	stage_sol_1[5][5] = 5;
	stage_sol_1[5][7] = 7;
	stage_sol_1[5][8] = 9;

	stage_sol_1[6][2] = 1;
	stage_sol_1[6][3] = 3;
	stage_sol_1[6][4] = 9;
	stage_sol_1[6][6] = 4;
	stage_sol_1[6][7] = 8;
	stage_sol_1[6][8] = 5;

	stage_sol_1[7][1] = 9;
	stage_sol_1[7][3] = 1;
	stage_sol_1[7][4] = 5;
	stage_sol_1[7][5] = 3;
	stage_sol_1[7][6] = 7;
	stage_sol_1[7][9] = 4;

	stage_sol_1[8][1] = 2;
	stage_sol_1[8][2] = 8;
	stage_sol_1[8][3] = 7;
	stage_sol_1[8][7] = 6;
	stage_sol_1[8][8] = 3;

	stage_sol_1[9][1] = 3;
	stage_sol_1[9][2] = 4;
	stage_sol_1[9][3] = 5;
	stage_sol_1[9][4] = 2;
	stage_sol_1[9][6] = 6;
	stage_sol_1[9][7] = 1;

	if(checkflag==1)
	{
		checkallryt=0;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(stage_sol_1[i][j]==stage1_values[i][j])
				{
					if(i==3 && j==1) iShowBMP(305,513,"green.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"green.bmp");
					if(i==8 && j==1) iShowBMP(305,185,"green.bmp");
					if(i==9 && j==1) iShowBMP(305,120,"green.bmp");

					if(i==2 && j==2) iShowBMP(370,575,"green.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"green.bmp");
					if(i==5 && j==2) iShowBMP(370,380,"green.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"green.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"green.bmp");
					if(i==9 && j==2) iShowBMP(370,120,"green.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"green.bmp");
					if(i==2 && j==3) iShowBMP(435,575,"green.bmp");
					if(i==4 && j==3) iShowBMP(435,445,"green.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"green.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"green.bmp");
					if(i==7 && j==3) iShowBMP(435,250,"green.bmp"); 
					if(i==8 && j==3) iShowBMP(435,185,"green.bmp");
					if(i==9 && j==3) iShowBMP(435,120,"green.bmp");

					if(i==1 && j==4) iShowBMP(500,640,"green.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"green.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"green.bmp");
					if(i==6 && j==4) iShowBMP(500,315,"green.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"green.bmp");
					if(i==9 && j==4) iShowBMP(500,120,"green.bmp");

					if(i==3 && j==5) iShowBMP(565,510,"green.bmp");
					if(i==5 && j==5) iShowBMP(565,380,"green.bmp");
					if(i==7 && j==5) iShowBMP(565,250,"green.bmp");

					if(i==1 && j==6) iShowBMP(630,640,"green.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"green.bmp");
					if(i==4 && j==6) iShowBMP(630,445,"green.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"green.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"green.bmp");
					if(i==9 && j==6) iShowBMP(630,120,"green.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"green.bmp");
					if(i==2 && j==7) iShowBMP(695,575,"green.bmp");
					if(i==3 && j==7) iShowBMP(695,510,"green.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"green.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"green.bmp");
					if(i==6 && j==7) iShowBMP(695,315,"green.bmp");
					if(i==8 && j==7) iShowBMP(695,185,"green.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"green.bmp");

					if(i==1 && j==8) iShowBMP(760,640,"green.bmp"); 
					if(i==2 && j==8) iShowBMP(760,575,"green.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"green.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"green.bmp");
					if(i==6 && j==8) iShowBMP(760,315,"green.bmp");
					if(i==8 && j==8) iShowBMP(760,185,"green.bmp");

					if(i==1 && j==9) iShowBMP(825,640,"green.bmp");
					if(i==2 && j==9) iShowBMP(825,575,"green.bmp");
					if(i==3 && j==9) iShowBMP(825,510,"green.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"green.bmp");
				}

				else if(stage_sol_1[i][j]!=stage1_values[i][j])
				{
					checkallryt=1;
					if(i==3 && j==1) iShowBMP(305,513,"red.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"red.bmp");
					if(i==8 && j==1) iShowBMP(305,185,"red.bmp");
					if(i==9 && j==1) iShowBMP(305,120,"red.bmp");

					if(i==2 && j==2) iShowBMP(370,575,"red.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"red.bmp");
					if(i==5 && j==2) iShowBMP(370,380,"red.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"red.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"red.bmp");
					if(i==9 && j==2) iShowBMP(370,120,"red.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"red.bmp");
					if(i==2 && j==3) iShowBMP(435,575,"red.bmp");
					if(i==4 && j==3) iShowBMP(435,445,"red.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"red.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"red.bmp");
					if(i==7 && j==3) iShowBMP(435,250,"red.bmp"); 
					if(i==8 && j==3) iShowBMP(435,185,"red.bmp");
					if(i==9 && j==3) iShowBMP(435,120,"red.bmp");

					if(i==1 && j==4) iShowBMP(500,640,"red.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"red.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"red.bmp");
					if(i==6 && j==4) iShowBMP(500,315,"red.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"red.bmp");
					if(i==9 && j==4) iShowBMP(500,120,"red.bmp");

					if(i==3 && j==5) iShowBMP(565,510,"red.bmp");
					if(i==5 && j==5) iShowBMP(565,380,"red.bmp");
					if(i==7 && j==5) iShowBMP(565,250,"red.bmp");

					if(i==1 && j==6) iShowBMP(630,640,"red.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"red.bmp");
					if(i==4 && j==6) iShowBMP(630,445,"red.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"red.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"red.bmp");
					if(i==9 && j==6) iShowBMP(630,120,"red.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"red.bmp");
					if(i==2 && j==7) iShowBMP(695,575,"red.bmp");
					if(i==3 && j==7) iShowBMP(695,510,"red.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"red.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"red.bmp");
					if(i==6 && j==7) iShowBMP(695,315,"red.bmp");
					if(i==8 && j==7) iShowBMP(695,185,"red.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"red.bmp");

					if(i==1 && j==8) iShowBMP(760,640,"red.bmp"); 
					if(i==2 && j==8) iShowBMP(760,575,"red.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"red.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"red.bmp");
					if(i==6 && j==8) iShowBMP(760,315,"red.bmp");
					if(i==8 && j==8) iShowBMP(760,185,"red.bmp");

					if(i==1 && j==9) iShowBMP(825,640,"red.bmp");
					if(i==2 && j==9) iShowBMP(825,575,"red.bmp");
					if(i==3 && j==9) iShowBMP(825,510,"red.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"red.bmp");
				}
			}
		}
		

	}


}

void stage_2()
{
	// 1st column
	if(f11==1) iShowBMP(300,600,"typedone.bmp");
	else if(f11==2) iShowBMP(300,600,"typedtwo.bmp");
	else if(f11==3) iShowBMP(300,600,"typedthree.bmp");
	else if(f11==4) iShowBMP(300,600,"typedfour.bmp");
	else if(f11==5) iShowBMP(300,600,"typedfive.bmp");
	else if(f11==6) iShowBMP(300,600,"typedsix.bmp");
	else if(f11==7) iShowBMP(300,600,"typedseven.bmp");
	else if(f11==8) iShowBMP(300,600,"typedeight.bmp");
	else if(f11==9) iShowBMP(300,600,"typednine.bmp");
    else iShowBMP(300,600,"grid.bmp");
    if(flagmouse==11) iShowBMP(350,648,"mark.bmp");
    
    if(f12==1) iShowBMP(300,535,"typedone.bmp");
	else if(f12==2) iShowBMP(300,535,"typedtwo.bmp");
	else if(f12==3) iShowBMP(300,535,"typedthree.bmp");
	else if(f12==4) iShowBMP(300,535,"typedfour.bmp");
	else if(f12==5) iShowBMP(300,535,"typedfive.bmp");
	else if(f12==6) iShowBMP(300,535,"typedsix.bmp");
	else if(f12==7) iShowBMP(300,535,"typedseven.bmp");
	else if(f12==8) iShowBMP(300,535,"typedeight.bmp");
	else if(f12==9) iShowBMP(300,535,"typednine.bmp");
    else iShowBMP(300,535,"grid.bmp");
    if(flagmouse==12) iShowBMP(350,584,"mark.bmp");

	iShowBMP(300,470,"nine.bmp");
	
	if(f14==1)iShowBMP(300,405,"typedone.bmp");
	else if(f14==2) iShowBMP(300,405,"typedtwo.bmp");
	else if(f14==3) iShowBMP(300,405,"typedthree.bmp");
	else if(f14==4) iShowBMP(300,405,"typedfour.bmp");
	else if(f14==5) iShowBMP(300,405,"typedfive.bmp");
	else if(f14==6) iShowBMP(300,405,"typedsix.bmp");
	else if(f14==7) iShowBMP(300,405,"typedseven.bmp");
	else if(f14==8) iShowBMP(300,405,"typedeight.bmp");
	else if(f14==9) iShowBMP(300,405,"typednine.bmp");
	else iShowBMP(300,405,"grid.bmp");
    if(flagmouse==14) iShowBMP(350,452,"mark.bmp");


	iShowBMP(300,340,"five.bmp");
	
	if(f16==1) iShowBMP(300,275,"typedone.bmp");
	else if(f16==2) iShowBMP(300,275,"typedtwo.bmp");
	else if(f16==3) iShowBMP(300,275,"typedthree.bmp");
	else if(f16==4) iShowBMP(300,275,"typedfour.bmp");
	else if(f16==5) iShowBMP(300,275,"typedfive.bmp");
	else if(f16==6) iShowBMP(300,275,"typedsix.bmp");
	else if(f16==7) iShowBMP(300,275,"typedseven.bmp");
	else if(f16==8) iShowBMP(300,275,"typedeight.bmp");
	else if(f16==9) iShowBMP(300,275,"typednine.bmp");
	else iShowBMP(300,275,"grid.bmp");
	if(flagmouse==16) iShowBMP(350,323,"mark.bmp");

	if(f17==1) iShowBMP(300,210,"typedone.bmp");
	else if(f17==2) iShowBMP(300,210,"typedtwo.bmp");
	else if(f17==3) iShowBMP(300,210,"typedthree.bmp");
	else if(f17==4) iShowBMP(300,210,"typedfour.bmp");
	else if(f17==5) iShowBMP(300,210,"typedfive.bmp");
	else if(f17==6) iShowBMP(300,210,"typedsix.bmp");
	else if(f17==7) iShowBMP(300,210,"typedseven.bmp");
	else if(f17==8) iShowBMP(300,210,"typedeight.bmp");
	else if(f17==9) iShowBMP(300,210,"typednine.bmp");
	else iShowBMP(300,210,"grid.bmp");
	if(flagmouse==17) iShowBMP(350,256,"mark.bmp");
	

	iShowBMP(300,145,"one.bmp");
	
	iShowBMP(300,80,"seven.bmp");


	// second column
	if(f21==1) iShowBMP(365,600,"typedone.bmp");
	else if(f21==2) iShowBMP(365,600,"typedtwo.bmp");
	else if(f21==3) iShowBMP(365,600,"typedthree.bmp");
	else if(f21==4) iShowBMP(365,600,"typedfour.bmp");
	else if(f21==5) iShowBMP(365,600,"typedfive.bmp");
	else if(f21==6) iShowBMP(365,600,"typedsix.bmp");
	else if(f21==7) iShowBMP(365,600,"typedseven.bmp");
	else if(f21==8) iShowBMP(365,600,"typedeight.bmp");
	else if(f21==9) iShowBMP(365,600,"typednine.bmp");
	else iShowBMP(365,600,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==21) iShowBMP(415,648,"mark.bmp");

	if(f22==1) iShowBMP(365,535,"typedone.bmp");
	else if(f22==2) iShowBMP(365,535,"typedtwo.bmp");
	else if(f22==3) iShowBMP(365,535,"typedthree.bmp");
	else if(f22==4) iShowBMP(365,535,"typedfour.bmp");
	else if(f22==5) iShowBMP(365,535,"typedfive.bmp");
	else if(f22==6) iShowBMP(365,535,"typedsix.bmp");
	else if(f22==7) iShowBMP(365,535,"typedseven.bmp");
	else if(f22==8) iShowBMP(365,535,"typedeight.bmp");
	else if(f22==9) iShowBMP(365,535,"typednine.bmp");
	else iShowBMP(365,535,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==22) iShowBMP(415,584,"mark.bmp");

	if(f23==1) iShowBMP(365,470,"typedone.bmp");
	else if(f23==2) iShowBMP(365,470,"typedtwo.bmp");
	else if(f23==3) iShowBMP(365,470,"typedthree.bmp");
	else if(f23==4) iShowBMP(365,470,"typedfour.bmp");
	else if(f23==5) iShowBMP(365,470,"typedfive.bmp");
	else if(f23==6) iShowBMP(365,470,"typedsix.bmp");
	else if(f23==7) iShowBMP(365,470,"typedseven.bmp");
	else if(f23==8) iShowBMP(365,470,"typedeight.bmp");
	else if(f23==9) iShowBMP(365,470,"typednine.bmp");
	else iShowBMP(365,470,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==23) iShowBMP(415,518,"mark.bmp");

	if(f24==1) iShowBMP(365,405,"typedone.bmp");
	else if(f24==2) iShowBMP(365,405,"typedtwo.bmp");
	else if(f24==3) iShowBMP(365,405,"typedthree.bmp");
	else if(f24==4) iShowBMP(365,405,"typedfour.bmp");
	else if(f24==5) iShowBMP(365,405,"typedfive.bmp");
	else if(f24==6) iShowBMP(365,405,"typedsix.bmp");
	else if(f24==7) iShowBMP(365,405,"typedseven.bmp");
	else if(f24==8) iShowBMP(365,405,"typedeight.bmp");
	else if(f24==9) iShowBMP(365,405,"typednine.bmp");
	else iShowBMP(365,405,"grid.bmp");//iShowBMP(365,405,"grid.bmp");
	if(flagmouse==24) iShowBMP(415,452,"mark.bmp");


	if(f25==1) iShowBMP(365,340,"typedone.bmp");
	else if(f25==2) iShowBMP(365,340,"typedtwo.bmp");
	else if(f25==3) iShowBMP(365,340,"typedthree.bmp");
	else if(f25==4) iShowBMP(365,340,"typedfour.bmp");
	else if(f25==5) iShowBMP(365,340,"typedfive.bmp");
	else if(f25==6) iShowBMP(365,340,"typedsix.bmp");
	else if(f25==7) iShowBMP(365,340,"typedseven.bmp");
	else if(f25==8) iShowBMP(365,340,"typedeight.bmp");
	else if(f25==9) iShowBMP(365,340,"typednine.bmp");
	else iShowBMP(365,340,"grid.bmp");//iShowBMP(365,340,"grid.bmp");
	if(flagmouse==25) iShowBMP(415,388,"mark.bmp");

	if(f26==1) iShowBMP(365,275,"typedone.bmp");
	else if(f26==2) iShowBMP(365,275,"typedtwo.bmp");
	else if(f26==3) iShowBMP(365,275,"typedthree.bmp");
	else if(f26==4) iShowBMP(365,275,"typedfour.bmp");
	else if(f26==5) iShowBMP(365,275,"typedfive.bmp");
	else if(f26==6) iShowBMP(365,275,"typedsix.bmp");
	else if(f26==7) iShowBMP(365,275,"typedseven.bmp");
	else if(f26==8) iShowBMP(365,275,"typedeight.bmp");
	else if(f26==9) iShowBMP(365,275,"typednine.bmp");
	else iShowBMP(365,275,"grid.bmp");//iShowBMP(365,275,"grid.bmp");
	if(flagmouse==26) iShowBMP(415,323,"mark.bmp");

	iShowBMP(365,210,"three.bmp");

	if(f28==1) iShowBMP(365,145,"typedone.bmp");
	else if(f28==2) iShowBMP(365,145,"typedtwo.bmp");
	else if(f28==3) iShowBMP(365,145,"typedthree.bmp");
	else if(f28==4) iShowBMP(365,145,"typedfour.bmp");
	else if(f28==5) iShowBMP(365,145,"typedfive.bmp");
	else if(f28==6) iShowBMP(365,145,"typedsix.bmp");
	else if(f28==7) iShowBMP(365,145,"typedseven.bmp");
	else if(f28==8) iShowBMP(365,145,"typedeight.bmp");
	else if(f28==9) iShowBMP(365,145,"typednine.bmp");
	else iShowBMP(365,145,"grid.bmp");//iShowBMP(365,145,"grid.bmp");
	if(flagmouse==28) iShowBMP(415,193,"mark.bmp");

	
	iShowBMP(365,80,"nine.bmp");

	// 3rd column
	if(f31==1) iShowBMP(430,600,"typedone.bmp");
	else if(f31==2) iShowBMP(430,600,"typedtwo.bmp");
	else if(f31==3) iShowBMP(430,600,"typedthree.bmp");
	else if(f31==4) iShowBMP(430,600,"typedfour.bmp");
	else if(f31==5) iShowBMP(430,600,"typedfive.bmp");
	else if(f31==6) iShowBMP(430,600,"typedsix.bmp");
	else if(f31==7) iShowBMP(430,600,"typedseven.bmp");
	else if(f31==8) iShowBMP(430,600,"typedeight.bmp");
	else if(f31==9) iShowBMP(430,600,"typednine.bmp");
	else iShowBMP(430,600,"grid.bmp");//iShowBMP(430,600,"grid.bmp");
	if(flagmouse==31) iShowBMP(478,648,"mark.bmp");

	if(f32==1) iShowBMP(430,535,"typedone.bmp");
	else if(f32==2) iShowBMP(430,535,"typedtwo.bmp");
	else if(f32==3) iShowBMP(430,535,"typedthree.bmp");
	else if(f32==4) iShowBMP(430,535,"typedfour.bmp");
	else if(f32==5) iShowBMP(430,535,"typedfive.bmp");
	else if(f32==6) iShowBMP(430,535,"typedsix.bmp");
	else if(f32==7) iShowBMP(430,535,"typedseven.bmp");
	else if(f32==8) iShowBMP(430,535,"typedeight.bmp");
	else if(f32==9) iShowBMP(430,535,"typednine.bmp");
	else iShowBMP(430,535,"grid.bmp");//iShowBMP(430,535,"grid.bmp");
	if(flagmouse==32) iShowBMP(478,583,"mark.bmp");

	iShowBMP(430,470,"one.bmp");
	iShowBMP(430,405,"seven.bmp");

	if(f35==1) iShowBMP(430,340,"typedone.bmp");
	else if(f35==2) iShowBMP(430,340,"typedtwo.bmp");
	else if(f35==3) iShowBMP(430,340,"typedthree.bmp");
	else if(f35==4) iShowBMP(430,340,"typedfour.bmp");
	else if(f35==5) iShowBMP(430,340,"typedfive.bmp");
	else if(f35==6) iShowBMP(430,340,"typedsix.bmp");
	else if(f35==7) iShowBMP(430,340,"typedseven.bmp");
	else if(f35==8) iShowBMP(430,340,"typedeight.bmp");
	else if(f35==9) iShowBMP(430,340,"typednine.bmp");
	else iShowBMP(430,340,"grid.bmp");//iShowBMP(430,340,"grid.bmp");
	if(flagmouse==35) iShowBMP(478,388,"mark.bmp");

	if(f36==1) iShowBMP(430,275,"typedone.bmp");
	else if(f36==2) iShowBMP(430,275,"typedtwo.bmp");
	else if(f36==3) iShowBMP(430,275,"typedthree.bmp");
	else if(f36==4) iShowBMP(430,275,"typedfour.bmp");
	else if(f36==5) iShowBMP(430,275,"typedfive.bmp");
	else if(f36==6) iShowBMP(430,275,"typedsix.bmp");
	else if(f36==7) iShowBMP(430,275,"typedseven.bmp");
	else if(f36==8) iShowBMP(430,275,"typedeight.bmp");
	else if(f36==9) iShowBMP(430,275,"typednine.bmp");
	else iShowBMP(430,275,"grid.bmp");//iShowBMP(430,275,"grid.bmp");
	if(flagmouse==36) iShowBMP(478,323,"mark.bmp");

	if(f37==1) iShowBMP(430,210,"typedone.bmp");
	else if(f37==2) iShowBMP(430,210,"typedtwo.bmp");
	else if(f37==3) iShowBMP(430,210,"typedthree.bmp");
	else if(f37==4) iShowBMP(430,210,"typedfour.bmp");
	else if(f37==5) iShowBMP(430,210,"typedfive.bmp");
	else if(f37==6) iShowBMP(430,210,"typedsix.bmp");
	else if(f37==7) iShowBMP(430,210,"typedseven.bmp");
	else if(f37==8) iShowBMP(430,210,"typedeight.bmp");
	else if(f37==9) iShowBMP(430,210,"typednine.bmp");
	else iShowBMP(430,210,"grid.bmp");//iShowBMP(430,210,"grid.bmp");
	if(flagmouse==37) iShowBMP(478,256,"mark.bmp");


	iShowBMP(430,145,"five.bmp");


	if(f39==1) iShowBMP(430,80,"typedone.bmp");
	else if(f39==2) iShowBMP(430,80,"typedtwo.bmp");
	else if(f39==3) iShowBMP(430,80,"typedthree.bmp");
	else if(f39==4) iShowBMP(430,80,"typedfour.bmp");
	else if(f39==5) iShowBMP(430,80,"typedfive.bmp");
	else if(f39==6) iShowBMP(430,80,"typedsix.bmp");
	else if(f39==7) iShowBMP(430,80,"typedseven.bmp");
	else if(f39==8) iShowBMP(430,80,"typedeight.bmp");
	else if(f39==9) iShowBMP(430,80,"typednine.bmp");
	else iShowBMP(430,80,"grid.bmp");//iShowBMP(430,80,"grid.bmp");
	if(flagmouse==39) iShowBMP(478,128,"mark.bmp");

	// 4th column
	
	iShowBMP(495,600,"one.bmp");\
	
	if(f42==1) iShowBMP(495,535,"typedone.bmp");
	else if(f42==2) iShowBMP(495,535,"typedtwo.bmp");
	else if(f42==3) iShowBMP(495,535,"typedthree.bmp");
	else if(f42==4) iShowBMP(495,535,"typedfour.bmp");
	else if(f42==5) iShowBMP(495,535,"typedfive.bmp");
	else if(f42==6) iShowBMP(495,535,"typedsix.bmp");
	else if(f42==7) iShowBMP(495,535,"typedseven.bmp");
	else if(f42==8) iShowBMP(495,535,"typedeight.bmp");
	else if(f42==9) iShowBMP(495,535,"typednine.bmp");
	else iShowBMP(495,535,"grid.bmp");
	if(flagmouse==42) iShowBMP(545,583,"mark.bmp");

	if(f43==1) iShowBMP(495,470,"typedone.bmp");
	else if(f43==2) iShowBMP(495,470,"typedtwo.bmp");
	else if(f43==3) iShowBMP(495,470,"typedthree.bmp");
	else if(f43==4) iShowBMP(495,470,"typedfour.bmp");
	else if(f43==5) iShowBMP(495,470,"typedfive.bmp");
	else if(f43==6) iShowBMP(495,470,"typedsix.bmp");
	else if(f43==7) iShowBMP(495,470,"typedseven.bmp");
	else if(f43==8) iShowBMP(495,470,"typedeight.bmp");
	else if(f43==9) iShowBMP(495,470,"typednine.bmp");
	else iShowBMP(495,470,"grid.bmp");//iShowBMP(495,470,"grid.bmp");
	if(flagmouse==43) iShowBMP(545,518,"mark.bmp");

	if(f44==1) iShowBMP(495,405,"typedone.bmp");
	else if(f44==2) iShowBMP(495,405,"typedtwo.bmp");
	else if(f44==3) iShowBMP(495,405,"typedthree.bmp");
	else if(f44==4) iShowBMP(495,405,"typedfour.bmp");
	else if(f44==5) iShowBMP(495,405,"typedfive.bmp");
	else if(f44==6) iShowBMP(495,405,"typedsix.bmp");
	else if(f44==7) iShowBMP(495,405,"typedseven.bmp");
	else if(f44==8) iShowBMP(495,405,"typedeight.bmp");
	else if(f44==9) iShowBMP(495,405,"typednine.bmp");
	else iShowBMP(495,405,"grid.bmp");//iShowBMP(495,405,"grid.bmp");
	if(flagmouse==44) iShowBMP(545,451,"mark.bmp");


	if(f45==1) iShowBMP(495,340,"typedone.bmp");
	else if(f45==2) iShowBMP(495,340,"typedtwo.bmp");
	else if(f45==3) iShowBMP(495,340,"typedthree.bmp");
	else if(f45==4) iShowBMP(495,340,"typedfour.bmp");
	else if(f45==5) iShowBMP(495,340,"typedfive.bmp");
	else if(f45==6) iShowBMP(495,340,"typedsix.bmp");
	else if(f45==7) iShowBMP(495,340,"typedseven.bmp");
	else if(f45==8) iShowBMP(495,340,"typedeight.bmp");
	else if(f45==9) iShowBMP(495,340,"typednine.bmp");
	else iShowBMP(495,340,"grid.bmp");//iShowBMP(495,275,"grid.bmp");
	if(flagmouse==45) iShowBMP(545,388,"mark.bmp");
	
	iShowBMP(495,275,"eight.bmp");

	if(f47==1) iShowBMP(495,210,"typedone.bmp");
	else if(f47==2) iShowBMP(495,210,"typedtwo.bmp");
	else if(f47==3) iShowBMP(495,210,"typedthree.bmp");
	else if(f47==4) iShowBMP(495,210,"typedfour.bmp");
	else if(f47==5) iShowBMP(495,210,"typedfive.bmp");
	else if(f47==6) iShowBMP(495,210,"typedsix.bmp");
	else if(f47==7) iShowBMP(495,210,"typedseven.bmp");
	else if(f47==8) iShowBMP(495,210,"typedeight.bmp");
	else if(f47==9) iShowBMP(495,210,"typednine.bmp");
	else iShowBMP(495,210,"grid.bmp");//iShowBMP(495,210,"grid.bmp");
	if(flagmouse==47) iShowBMP(545,256,"mark.bmp");

	if(f48==1) iShowBMP(495,145,"typedone.bmp");
	else if(f48==2) iShowBMP(495,145,"typedtwo.bmp");
	else if(f48==3) iShowBMP(495,145,"typedthree.bmp");
	else if(f48==4) iShowBMP(495,145,"typedfour.bmp");
	else if(f48==5) iShowBMP(495,145,"typedfive.bmp");
	else if(f48==6) iShowBMP(495,145,"typedsix.bmp");
	else if(f48==7) iShowBMP(495,145,"typedseven.bmp");
	else if(f48==8) iShowBMP(495,145,"typedeight.bmp");
	else if(f48==9) iShowBMP(495,145,"typednine.bmp");
	else iShowBMP(495,145,"grid.bmp");//iShowBMP(495,80,"grid.bmp");
	if(flagmouse==48) iShowBMP(545,193,"mark.bmp");
	
	iShowBMP(495,80,"four.bmp");

	// 5th column
	if(f51==1) iShowBMP(560,600,"typedone.bmp");
	else if(f51==2) iShowBMP(560,600,"typedtwo.bmp");
	else if(f51==3) iShowBMP(560,600,"typedthree.bmp");
	else if(f51==4) iShowBMP(560,600,"typedfour.bmp");
	else if(f51==5) iShowBMP(560,600,"typedfive.bmp");
	else if(f51==6) iShowBMP(560,600,"typedsix.bmp");
	else if(f51==7) iShowBMP(560,600,"typedseven.bmp");
	else if(f51==8) iShowBMP(560,600,"typedeight.bmp");
	else if(f51==9) iShowBMP(560,600,"typednine.bmp");
	else iShowBMP(560,600,"grid.bmp");//iShowBMP(560,470,"grid.bmp");
	if(flagmouse==51) iShowBMP(610,648,"mark.bmp");
	
	if(f52==1) iShowBMP(560,535,"typedone.bmp");
	else if(f52==2) iShowBMP(560,535,"typedtwo.bmp");
	else if(f52==3) iShowBMP(560,535,"typedthree.bmp");
	else if(f52==4) iShowBMP(560,535,"typedfour.bmp");
	else if(f52==5) iShowBMP(560,535,"typedfive.bmp");
	else if(f52==6) iShowBMP(560,535,"typedsix.bmp");
	else if(f52==7) iShowBMP(560,535,"typedseven.bmp");
	else if(f52==8) iShowBMP(560,535,"typedeight.bmp");
	else if(f52==9) iShowBMP(560,535,"typednine.bmp");
	else iShowBMP(560,535,"grid.bmp");//iShowBMP(560,470,"grid.bmp");
	if(flagmouse==52) iShowBMP(610,583,"mark.bmp");

	if(f53==1) iShowBMP(560,470,"typedone.bmp");
	else if(f53==2) iShowBMP(560,470,"typedtwo.bmp");
	else if(f53==3) iShowBMP(560,470,"typedthree.bmp");
	else if(f53==4) iShowBMP(560,470,"typedfour.bmp");
	else if(f53==5) iShowBMP(560,470,"typedfive.bmp");
	else if(f53==6) iShowBMP(560,470,"typedsix.bmp");
	else if(f53==7) iShowBMP(560,470,"typedseven.bmp");
	else if(f53==8) iShowBMP(560,470,"typedeight.bmp");
	else if(f53==9) iShowBMP(560,470,"typednine.bmp");
	else iShowBMP(560,470,"grid.bmp");//iShowBMP(560,470,"grid.bmp");
	if(flagmouse==53) iShowBMP(610,518,"mark.bmp");

	iShowBMP(560,405,"two.bmp");

	if(f55==1) iShowBMP(560,340,"typedone.bmp");
	else if(f55==2) iShowBMP(560,340,"typedtwo.bmp");
	else if(f55==3) iShowBMP(560,340,"typedthree.bmp");
	else if(f55==4) iShowBMP(560,340,"typedfour.bmp");
	else if(f55==5) iShowBMP(560,340,"typedfive.bmp");
	else if(f55==6) iShowBMP(560,340,"typedsix.bmp");
	else if(f55==7) iShowBMP(560,340,"typedseven.bmp");
	else if(f55==8) iShowBMP(560,340,"typedeight.bmp");
	else if(f55==9) iShowBMP(560,340,"typednine.bmp");
	else iShowBMP(560,340,"grid.bmp");//iShowBMP(560,340,"grid.bmp");
	if(flagmouse==55) iShowBMP(610,388,"mark.bmp");

	iShowBMP(560,275,"seven.bmp");

	if(f57==1) iShowBMP(560,210,"typedone.bmp");
	else if(f57==2) iShowBMP(560,210,"typedtwo.bmp");
	else if(f57==3) iShowBMP(560,210,"typedthree.bmp");
	else if(f57==4) iShowBMP(560,210,"typedfour.bmp");
	else if(f57==5) iShowBMP(560,210,"typedfive.bmp");
	else if(f57==6) iShowBMP(560,210,"typedsix.bmp");
	else if(f57==7) iShowBMP(560,210,"typedseven.bmp");
	else if(f57==8) iShowBMP(560,210,"typedeight.bmp");
	else if(f57==9) iShowBMP(560,210,"typednine.bmp");
	else iShowBMP(560,210,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==57) iShowBMP(610,256,"mark.bmp");
	
	if(f58==1) iShowBMP(560,145,"typedone.bmp");
	else if(f58==2) iShowBMP(560,145,"typedtwo.bmp");
	else if(f58==3) iShowBMP(560,145,"typedthree.bmp");
	else if(f58==4) iShowBMP(560,145,"typedfour.bmp");
	else if(f58==5) iShowBMP(560,145,"typedfive.bmp");
	else if(f58==6) iShowBMP(560,145,"typedsix.bmp");
	else if(f58==7) iShowBMP(560,145,"typedseven.bmp");
	else if(f58==8) iShowBMP(560,145,"typedeight.bmp");
	else if(f58==9) iShowBMP(560,145,"typednine.bmp");
	else iShowBMP(560,145,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==58) iShowBMP(610,193,"mark.bmp");
	
	if(f59==1) iShowBMP(560,80,"typedone.bmp");
	else if(f59==2) iShowBMP(560,80,"typedtwo.bmp");
	else if(f59==3) iShowBMP(560,80,"typedthree.bmp");
	else if(f59==4) iShowBMP(560,80,"typedfour.bmp");
	else if(f59==5) iShowBMP(560,80,"typedfive.bmp");
	else if(f59==6) iShowBMP(560,80,"typedsix.bmp");
	else if(f59==7) iShowBMP(560,80,"typedseven.bmp");
	else if(f59==8) iShowBMP(560,80,"typedeight.bmp");
	else if(f59==9) iShowBMP(560,80,"typednine.bmp");
	else iShowBMP(560,80,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==59) iShowBMP(610,128,"mark.bmp");


	// 6th column
	
	iShowBMP(625,600,"five.bmp");
	
	if(f62==1) iShowBMP(625,535,"typedone.bmp");
	else if(f62==2) iShowBMP(625,535,"typedtwo.bmp");
	else if(f62==3) iShowBMP(625,535,"typedthree.bmp");
	else if(f62==4) iShowBMP(625,535,"typedfour.bmp");
	else if(f62==5) iShowBMP(625,535,"typedfive.bmp");
	else if(f62==6) iShowBMP(625,535,"typedsix.bmp");
	else if(f62==7) iShowBMP(625,535,"typedseven.bmp");
	else if(f62==8) iShowBMP(625,535,"typedeight.bmp");
	else if(f62==9) iShowBMP(625,535,"typednine.bmp");
	else iShowBMP(625,535,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==62) iShowBMP(673,583,"mark.bmp");


	if(f63==1) iShowBMP(625,470,"typedone.bmp");
	else if(f63==2) iShowBMP(625,470,"typedtwo.bmp");
	else if(f63==3) iShowBMP(625,470,"typedthree.bmp");
	else if(f63==4) iShowBMP(625,470,"typedfour.bmp");
	else if(f63==5) iShowBMP(625,470,"typedfive.bmp");
	else if(f63==6) iShowBMP(625,470,"typedsix.bmp");
	else if(f63==7) iShowBMP(625,470,"typedseven.bmp");
	else if(f63==8) iShowBMP(625,470,"typedeight.bmp");
	else if(f63==9) iShowBMP(625,470,"typednine.bmp");
	else iShowBMP(625,470,"grid.bmp");
	if(flagmouse == 63) iShowBMP(673,518,"mark.bmp");

	iShowBMP(625,405,"six.bmp");
	
	if(f65==1) iShowBMP(625,340,"typedone.bmp");
	else if(f65==2) iShowBMP(625,340,"typedtwo.bmp");
	else if(f65==3) iShowBMP(625,340,"typedthree.bmp");
	else if(f65==4) iShowBMP(625,340,"typedfour.bmp");
	else if(f65==5) iShowBMP(625,340,"typedfive.bmp");
	else if(f65==6) iShowBMP(625,340,"typedsix.bmp");
	else if(f65==7) iShowBMP(625,340,"typedseven.bmp");
	else if(f65==8) iShowBMP(625,340,"typedeight.bmp");
	else if(f65==9) iShowBMP(625,340,"typednine.bmp");
	else iShowBMP(625,340,"grid.bmp");
	if(flagmouse == 65) iShowBMP(673,388,"mark.bmp");
	

	if(f66==1) iShowBMP(625,275,"typedone.bmp");
	else if(f66==2) iShowBMP(625,275,"typedtwo.bmp");
	else if(f66==3) iShowBMP(625,275,"typedthree.bmp");
	else if(f66==4) iShowBMP(625,275,"typedfour.bmp");
	else if(f66==5) iShowBMP(625,275,"typedfive.bmp");
	else if(f66==6) iShowBMP(625,275,"typedsix.bmp");
	else if(f66==7) iShowBMP(625,275,"typedseven.bmp");
	else if(f66==8) iShowBMP(625,275,"typedeight.bmp");
	else if(f66==9) iShowBMP(625,275,"typednine.bmp");	
	else iShowBMP(625,275,"grid.bmp");
	if (flagmouse == 66) iShowBMP(673,323,"mark.bmp");
	
	if(f67==1) iShowBMP(625,210,"typedone.bmp");
	else if(f67==2) iShowBMP(625,210,"typedtwo.bmp");
	else if(f67==3) iShowBMP(625,210,"typedthree.bmp");
	else if(f67==4) iShowBMP(625,210,"typedfour.bmp");
	else if(f67==5) iShowBMP(625,210,"typedfive.bmp");
	else if(f67==6) iShowBMP(625,210,"typedsix.bmp");
	else if(f67==7) iShowBMP(625,210,"typedseven.bmp");
	else if(f67==8) iShowBMP(625,210,"typedeight.bmp");
	else if(f67==9) iShowBMP(625,210,"typednine.bmp");
	else iShowBMP(625,210,"grid.bmp");
	if(flagmouse == 67) iShowBMP(673,256,"mark.bmp");


	if(f68==1) iShowBMP(625,145,"typedone.bmp");
	else if(f68==2) iShowBMP(625,145,"typedtwo.bmp");
	else if(f68==3) iShowBMP(625,145,"typedthree.bmp");
	else if(f68==4) iShowBMP(625,145,"typedfour.bmp");
	else if(f68==5) iShowBMP(625,145,"typedfive.bmp");
	else if(f68==6) iShowBMP(625,145,"typedsix.bmp");
	else if(f68==7) iShowBMP(625,145,"typedseven.bmp");
	else if(f68==8) iShowBMP(625,145,"typedeight.bmp");
	else if(f68==9) iShowBMP(625,145,"typednine.bmp");
	else iShowBMP(625,145,"grid.bmp");
	if (flagmouse == 68) iShowBMP(673,193,"mark.bmp");
	
	iShowBMP(625,80,"one.bmp");
	
	// 7th column

	if(f71==1) iShowBMP(690,600,"typedone.bmp");
	else if(f71==2) iShowBMP(690,600,"typedtwo.bmp");
	else if(f71==3) iShowBMP(690,600,"typedthree.bmp");
	else if(f71==4) iShowBMP(690,600,"typedfour.bmp");
	else if(f71==5) iShowBMP(690,600,"typedfive.bmp");
	else if(f71==6) iShowBMP(690,600,"typedsix.bmp");
	else if(f71==7) iShowBMP(690,600,"typedseven.bmp");
	else if(f71==8) iShowBMP(690,600,"typedeight.bmp");
	else if(f71==9) iShowBMP(690,600,"typednine.bmp");
	else iShowBMP(690,600,"grid.bmp");
	if (flagmouse == 71) iShowBMP(740,648,"mark.bmp");

	
	iShowBMP(690,535,"seven.bmp");

	if(f73==1) iShowBMP(690,470,"typedone.bmp");
	else if(f73==2) iShowBMP(690,470,"typedtwo.bmp");
	else if(f73==3) iShowBMP(690,470,"typedthree.bmp");
	else if(f73==4) iShowBMP(690,470,"typedfour.bmp");
	else if(f73==5) iShowBMP(690,470,"typedfive.bmp");
	else if(f73==6) iShowBMP(690,470,"typedsix.bmp");
	else if(f73==7) iShowBMP(690,470,"typedseven.bmp");
	else if(f73==8) iShowBMP(690,470,"typedeight.bmp");
	else if(f73==9) iShowBMP(690,470,"typednine.bmp");
	else iShowBMP(690,470,"grid.bmp");
	if(flagmouse == 73) iShowBMP(740,518,"mark.bmp");

	if(f74==1) iShowBMP(690,405,"typedone.bmp");
	else if(f74==2) iShowBMP(690,405,"typedtwo.bmp");
	else if(f74==3) iShowBMP(690,405,"typedthree.bmp");
	else if(f74==4) iShowBMP(690,405,"typedfour.bmp");
	else if(f74==5) iShowBMP(690,405,"typedfive.bmp");
	else if(f74==6) iShowBMP(690,405,"typedsix.bmp");
	else if(f74==7) iShowBMP(690,405,"typedseven.bmp");
	else if(f74==8) iShowBMP(690,405,"typedeight.bmp");
	else if(f74==9) iShowBMP(690,405,"typednine.bmp");
	else iShowBMP(690,405,"grid.bmp");
	if(flagmouse == 74) iShowBMP(740,451,"mark.bmp");
	
	if(f75==1) iShowBMP(690,340,"typedone.bmp");
	else if(f75==2) iShowBMP(690,340,"typedtwo.bmp");
	else if(f75==3) iShowBMP(690,340,"typedthree.bmp");
	else if(f75==4) iShowBMP(690,340,"typedfour.bmp");
	else if(f75==5) iShowBMP(690,340,"typedfive.bmp");
	else if(f75==6) iShowBMP(690,340,"typedsix.bmp");
	else if(f75==7) iShowBMP(690,340,"typedseven.bmp");
	else if(f75==8) iShowBMP(690,340,"typedeight.bmp");
	else if(f75==9) iShowBMP(690,340,"typednine.bmp");
	else iShowBMP(690,340,"grid.bmp");
	if(flagmouse == 75)iShowBMP(740,388,"mark.bmp");
	
	
	iShowBMP(690,275,"four.bmp");

	iShowBMP(690,210,"eight.bmp");

	if(f78==1) iShowBMP(690,145,"typedone.bmp");
	else if(f78==2) iShowBMP(690,145,"typedtwo.bmp");
	else if(f78==3) iShowBMP(690,145,"typedthree.bmp");
	else if(f78==4) iShowBMP(690,145,"typedfour.bmp");
	else if(f78==5) iShowBMP(690,145,"typedfive.bmp");
	else if(f78==6) iShowBMP(690,145,"typedsix.bmp");
	else if(f78==7) iShowBMP(690,145,"typedseven.bmp");
	else if(f78==8) iShowBMP(690,145,"typedeight.bmp");
	else if(f78==9) iShowBMP(690,145,"typednine.bmp");
	else iShowBMP(690,145,"grid.bmp");
	if(flagmouse == 78) iShowBMP(740,193,"mark.bmp");
	
	if(f79==1) iShowBMP(690,80,"typedone.bmp");
	else if(f79==2) iShowBMP(690,80,"typedtwo.bmp");
	else if(f79==3) iShowBMP(690,80,"typedthree.bmp");
	else if(f79==4) iShowBMP(690,80,"typedfour.bmp");
	else if(f79==5) iShowBMP(690,80,"typedfive.bmp");
	else if(f79==6) iShowBMP(690,80,"typedsix.bmp");
	else if(f79==7) iShowBMP(690,80,"typedseven.bmp");
	else if(f79==8) iShowBMP(690,80,"typedeight.bmp");
	else if(f79==9) iShowBMP(690,80,"typednine.bmp");
	else iShowBMP(690,80,"grid.bmp");
	if(flagmouse == 79) iShowBMP(740,128,"mark.bmp");
	
	// 8th column

	iShowBMP(755,600,"six.bmp");

	if(f82==1) iShowBMP(755,535,"typedone.bmp");
	else if(f82==2) iShowBMP(755,535,"typedtwo.bmp");
	else if(f82==3) iShowBMP(755,535,"typedthree.bmp");
	else if(f82==4) iShowBMP(755,535,"typedfour.bmp");
	else if(f82==5) iShowBMP(755,535,"typedfive.bmp");
	else if(f82==6) iShowBMP(755,535,"typedsix.bmp");
	else if(f82==7) iShowBMP(755,535,"typedseven.bmp");
	else if(f82==8) iShowBMP(755,535,"typedeight.bmp");
	else if(f82==9) iShowBMP(755,535,"typednine.bmp");
	else iShowBMP(755,535,"grid.bmp");
	if(flagmouse == 82) iShowBMP(805,583,"mark.bmp");

	iShowBMP(755,470,"three.bmp");

	if(f84==1) iShowBMP(755,405,"typedone.bmp");
	else if(f84==2) iShowBMP(755,405,"typedtwo.bmp");
	else if(f84==3) iShowBMP(755,405,"typedthree.bmp");
	else if(f84==4) iShowBMP(755,405,"typedfour.bmp");
	else if(f84==5) iShowBMP(755,405,"typedfive.bmp");
	else if(f84==6) iShowBMP(755,405,"typedsix.bmp");
	else if(f84==7) iShowBMP(755,405,"typedseven.bmp");
	else if(f84==8) iShowBMP(755,405,"typedeight.bmp");
	else if(f84==9) iShowBMP(755,405,"typednine.bmp");
	else iShowBMP(755,405,"grid.bmp");
	if(flagmouse == 84) iShowBMP(805,451,"mark.bmp");

	if(f85==1) iShowBMP(755,340,"typedone.bmp");
	else if(f85==2) iShowBMP(755,340,"typedtwo.bmp");
	else if(f85==3) iShowBMP(755,340,"typedthree.bmp");
	else if(f85==4) iShowBMP(755,340,"typedfour.bmp");
	else if(f85==5) iShowBMP(755,340,"typedfive.bmp");
	else if(f85==6) iShowBMP(755,340,"typedsix.bmp");
	else if(f85==7) iShowBMP(755,340,"typedseven.bmp");
	else if(f85==8) iShowBMP(755,340,"typedeight.bmp");
	else if(f85==9) iShowBMP(755,340,"typednine.bmp");
	else iShowBMP(755,340,"grid.bmp");
	if(flagmouse == 85) iShowBMP(805,388,"mark.bmp");

	if(f86==1) iShowBMP(755,275,"typedone.bmp");
	else if(f86==2) iShowBMP(755,275,"typedtwo.bmp");
	else if(f86==3) iShowBMP(755,275,"typedthree.bmp");
	else if(f86==4) iShowBMP(755,275,"typedfour.bmp");
	else if(f86==5) iShowBMP(755,275,"typedfive.bmp");
	else if(f86==6) iShowBMP(755,275,"typedsix.bmp");
	else if(f86==7) iShowBMP(755,275,"typedseven.bmp");
	else if(f86==8) iShowBMP(755,275,"typedeight.bmp");
	else if(f86==9) iShowBMP(755,275,"typednine.bmp");
	else iShowBMP(755,275,"grid.bmp");
	if(flagmouse == 86) iShowBMP(805,323,"mark.bmp");

	if(f87==1) iShowBMP(755,210,"typedone.bmp");
	else if(f87==2) iShowBMP(755,210,"typedtwo.bmp");
	else if(f87==3) iShowBMP(755,210,"typedthree.bmp");
	else if(f87==4) iShowBMP(755,210,"typedfour.bmp");
	else if(f87==5) iShowBMP(755,210,"typedfive.bmp");
	else if(f87==6) iShowBMP(755,210,"typedsix.bmp");
	else if(f87==7) iShowBMP(755,210,"typedseven.bmp");
	else if(f87==8) iShowBMP(755,210,"typedeight.bmp");
	else if(f87==9) iShowBMP(755,210,"typednine.bmp");
	else iShowBMP(755,210,"grid.bmp");
	if(flagmouse == 87) iShowBMP(805,256,"mark.bmp");

	if(f88==1) iShowBMP(755,145,"typedone.bmp");
	else if(f88==2) iShowBMP(755,145,"typedtwo.bmp");
	else if(f88==3) iShowBMP(755,145,"typedthree.bmp");
	else if(f88==4) iShowBMP(755,145,"typedfour.bmp");
	else if(f88==5) iShowBMP(755,145,"typedfive.bmp");
	else if(f88==6) iShowBMP(755,145,"typedsix.bmp");
	else if(f88==7) iShowBMP(755,145,"typedseven.bmp");
	else if(f88==8) iShowBMP(755,145,"typedeight.bmp");
	else if(f88==9) iShowBMP(755,145,"typednine.bmp");
	else iShowBMP(755,145,"grid.bmp");
	if(flagmouse == 88) iShowBMP(805,193,"mark.bmp");

	if(f89==1) iShowBMP(755,80,"typedone.bmp");
	else if(f89==2) iShowBMP(755,80,"typedtwo.bmp");
	else if(f89==3) iShowBMP(755,80,"typedthree.bmp");
	else if(f89==4) iShowBMP(755,80,"typedfour.bmp");
	else if(f89==5) iShowBMP(755,80,"typedfive.bmp");
	else if(f89==6) iShowBMP(755,80,"typedsix.bmp");
	else if(f89==7) iShowBMP(755,80,"typedseven.bmp");
	else if(f89==8) iShowBMP(755,80,"typedeight.bmp");
	else if(f89==9) iShowBMP(755,80,"typednine.bmp");
	else iShowBMP(755,80,"grid.bmp");
	if(flagmouse == 89) iShowBMP(805,128,"mark.bmp");

	// 9th column

	iShowBMP(820,600,"eight.bmp");

	iShowBMP(820,535,"one.bmp");

	
	if(f93==1) iShowBMP(820,470,"typedone.bmp");
	else if(f93==2) iShowBMP(820,470,"typedtwo.bmp");
	else if(f93==3) iShowBMP(820,470,"typedthree.bmp");
	else if(f93==4) iShowBMP(820,470,"typedfour.bmp");
	else if(f93==5) iShowBMP(820,470,"typedfive.bmp");
	else if(f93==6) iShowBMP(820,470,"typedsix.bmp");
	else if(f93==7) iShowBMP(820,470,"typedseven.bmp");
	else if(f93==8) iShowBMP(820,470,"typedeight.bmp");
	else if(f93==9) iShowBMP(820,470,"typednine.bmp");
	else iShowBMP(820,470,"grid.bmp");
	if(flagmouse == 93) iShowBMP(872,518,"mark.bmp");
	
	if(f94==1) iShowBMP(820,405,"typedone.bmp");
	else if(f94==2) iShowBMP(820,405,"typedtwo.bmp");
	else if(f94==3) iShowBMP(820,405,"typedthree.bmp");
	else if(f94==4) iShowBMP(820,405,"typedfour.bmp");
	else if(f94==5) iShowBMP(820,405,"typedfive.bmp");
	else if(f94==6) iShowBMP(820,405,"typedsix.bmp");
	else if(f94==7) iShowBMP(820,405,"typedseven.bmp");
	else if(f94==8) iShowBMP(820,405,"typedeight.bmp");
	else if(f94==9) iShowBMP(820,405,"typednine.bmp");
	else iShowBMP(820,405,"grid.bmp");
	if(flagmouse == 94) iShowBMP(872,450,"mark.bmp");
	
	iShowBMP(820,340,"three.bmp");
	
	if(f96==1) iShowBMP(820,275,"typedone.bmp");
	else if(f96==2) iShowBMP(820,275,"typedtwo.bmp");
	else if(f96==3) iShowBMP(820,275,"typedthree.bmp");
	else if(f96==4) iShowBMP(820,275,"typedfour.bmp");
	else if(f96==5) iShowBMP(820,275,"typedfive.bmp");
	else if(f96==6) iShowBMP(820,275,"typedsix.bmp");
	else if(f96==7) iShowBMP(820,275,"typedseven.bmp");
	else if(f96==8) iShowBMP(820,275,"typedeight.bmp");
	else if(f96==9) iShowBMP(820,275,"typednine.bmp");
	else iShowBMP(820,275,"grid.bmp");
	if(flagmouse == 96) iShowBMP(872,323,"mark.bmp");
	
	iShowBMP(820,210,"five.bmp");
	
	if(f98==1) iShowBMP(820,145,"typedone.bmp");
	else if(f98==2) iShowBMP(820,145,"typedtwo.bmp");
	else if(f98==3) iShowBMP(820,145,"typedthree.bmp");
	else if(f98==4) iShowBMP(820,145,"typedfour.bmp");
	else if(f98==5) iShowBMP(820,145,"typedfive.bmp");
	else if(f98==6) iShowBMP(820,145,"typedsix.bmp");
	else if(f98==7) iShowBMP(820,145,"typedseven.bmp");
	else if(f98==8) iShowBMP(820,145,"typedeight.bmp");
	else if(f98==9) iShowBMP(820,145,"typednine.bmp");
	else iShowBMP(820,145,"grid.bmp");
	if(flagmouse == 98) iShowBMP(872,193,"mark.bmp");
	
	if(f99==1) iShowBMP(820,80,"typedone.bmp");
	else if(f99==2) iShowBMP(820,80,"typedtwo.bmp");
	else if(f99==3) iShowBMP(820,80,"typedthree.bmp");
	else if(f99==4) iShowBMP(820,80,"typedfour.bmp");
	else if(f99==5) iShowBMP(820,80,"typedfive.bmp");
	else if(f99==6) iShowBMP(820,80,"typedsix.bmp");
	else if(f99==7) iShowBMP(820,80,"typedseven.bmp");
	else if(f99==8) iShowBMP(820,80,"typedeight.bmp");
	else if(f99==9) iShowBMP(820,80,"typednine.bmp");
	else iShowBMP(820,80,"grid.bmp");
	if(flagmouse == 99) iShowBMP(872,128,"mark.bmp");
	
}

void soln_stage2()
{
	int i,j;

	stage_sol_2[1][1] = 4;
	stage_sol_2[1][2] = 7;
	stage_sol_2[1][3] = 3;
	stage_sol_2[1][5] = 9;
	stage_sol_2[1][7] = 2;

	stage_sol_2[2][1] = 8;
	stage_sol_2[2][2] = 5;
	stage_sol_2[2][3] = 6;
	stage_sol_2[2][4] = 3;
	stage_sol_2[2][5] = 4;
	stage_sol_2[2][6] = 2;
	stage_sol_2[2][8] = 9;


	stage_sol_2[3][2] = 2;
	stage_sol_2[3][4] = 6;
	stage_sol_2[3][5] = 8;
	stage_sol_2[3][6] = 7;
	stage_sol_2[3][7] = 5;
	stage_sol_2[3][9] = 4;

	stage_sol_2[4][1] = 3;
	stage_sol_2[4][2] = 4;
	stage_sol_2[4][4] = 5;
	stage_sol_2[4][7] = 1;
	stage_sol_2[4][8] = 8;
	stage_sol_2[4][9] = 9;

	stage_sol_2[5][2] = 8;
	stage_sol_2[5][3] = 2;
	stage_sol_2[5][4] = 9;
	stage_sol_2[5][5] = 1;
	stage_sol_2[5][6] = 4;
	stage_sol_2[5][7] = 6;
	stage_sol_2[5][8] = 7;

	stage_sol_2[6][1] = 6;
	stage_sol_2[6][2] = 1;
	stage_sol_2[6][3] = 9;
	stage_sol_2[6][6] = 3;
	stage_sol_2[6][8] = 5;
	stage_sol_2[6][9] = 2;

	stage_sol_2[7][1] = 2;
	stage_sol_2[7][3] = 4;
	stage_sol_2[7][4] = 7;
	stage_sol_2[7][5] = 6;
	stage_sol_2[7][6] = 9;
	stage_sol_2[7][8] = 1;

	stage_sol_2[8][2] = 6;
	stage_sol_2[8][4] = 2;
	stage_sol_2[8][5] = 3;
	stage_sol_2[8][6] = 8;
	stage_sol_2[8][7] = 9;
	stage_sol_2[8][8] = 4;
	stage_sol_2[8][9] = 7;


	stage_sol_2[9][3] = 8;
	stage_sol_2[9][5] = 5;
	stage_sol_2[9][7] = 3;
	stage_sol_2[9][8] = 2;
	stage_sol_2[9][9] = 6;


if(checkflag==1)
{
		checkallryt=0;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(stage_sol_2[i][j]==stage2_values[i][j])
				{
					if(i==1 && j==1) iShowBMP(305,640,"green.bmp");
					if(i==2 && j==1) iShowBMP(305,575,"green.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"green.bmp");
					if(i==6 && j==1) iShowBMP(305,315,"green.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"green.bmp");

					if(i==1 && j==2) iShowBMP(370,640,"green.bmp");
					if(i==2 && j==2) iShowBMP(370,575,"green.bmp");
					if(i==3 && j==2) iShowBMP(370,510,"green.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"green.bmp");
					if(i==5 && j==2) iShowBMP(370,380,"green.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"green.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"green.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"green.bmp");
					if(i==2 && j==3) iShowBMP(435,575,"green.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"green.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"green.bmp");
					if(i==7 && j==3) iShowBMP(435,250,"green.bmp"); 
					if(i==9 && j==3) iShowBMP(435,120,"green.bmp");

					if(i==2 && j==4) iShowBMP(500,575,"green.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"green.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"green.bmp");
					if(i==5 && j==4) iShowBMP(500,380,"green.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"green.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"green.bmp");
					
					if(i==1 && j==5) iShowBMP(565,640,"green.bmp");
					if(i==2 && j==5) iShowBMP(565,575,"green.bmp");
					if(i==3 && j==5) iShowBMP(565,510,"green.bmp");
					if(i==5 && j==5) iShowBMP(565,380,"green.bmp");
					if(i==7 && j==5) iShowBMP(565,250,"green.bmp");
					if(i==8 && j==5) iShowBMP(565,185,"green.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"green.bmp");

					if(i==2 && j==6) iShowBMP(630,575,"green.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"green.bmp");
					if(i==5 && j==6) iShowBMP(630,380,"green.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"green.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"green.bmp");
					if(i==8 && j==6) iShowBMP(630,185,"green.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"green.bmp");
					if(i==3 && j==7) iShowBMP(695,510,"green.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"green.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"green.bmp");
					if(i==8 && j==7) iShowBMP(695,185,"green.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"green.bmp");

					if(i==2 && j==8) iShowBMP(760,575,"green.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"green.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"green.bmp");
					if(i==6 && j==8) iShowBMP(760,315,"green.bmp");
					if(i==7 && j==8) iShowBMP(760,250,"green.bmp");
					if(i==8 && j==8) iShowBMP(760,185,"green.bmp");
					if(i==9 && j==8) iShowBMP(760,120,"green.bmp");

					if(i==3 && j==9) iShowBMP(825,510,"green.bmp");
					if(i==4 && j==9) iShowBMP(825,445,"green.bmp");
					if(i==6 && j==9) iShowBMP(825,315,"green.bmp");
					if(i==8 && j==9) iShowBMP(825,185,"green.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"green.bmp");
				}

				else if(stage_sol_2[i][j]!=stage2_values[i][j])
				{
					checkallryt=1;
					if(i==1 && j==1) iShowBMP(305,640,"red.bmp");
					if(i==2 && j==1) iShowBMP(305,575,"red.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"red.bmp");
					if(i==6 && j==1) iShowBMP(305,315,"red.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"red.bmp");

					if(i==1 && j==2) iShowBMP(370,640,"red.bmp");
					if(i==2 && i==2) iShowBMP(370,575,"red.bmp");
					if(i==3 && j==2) iShowBMP(370,510,"red.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"red.bmp");
					if(i==5 && j==2) iShowBMP(370,380,"red.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"red.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"red.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"red.bmp");
					if(i==2 && j==3) iShowBMP(435,575,"red.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"red.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"red.bmp");
					if(i==7 && j==3) iShowBMP(435,250,"red.bmp"); 
					if(i==9 && j==3) iShowBMP(435,120,"red.bmp");

					if(i==2 && j==4) iShowBMP(500,575,"red.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"red.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"red.bmp");
					if(i==5 && j==4) iShowBMP(500,380,"red.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"red.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"red.bmp");
					
					if(i==1 && j==5) iShowBMP(565,640,"red.bmp");
					if(i==2 && j==5) iShowBMP(565,575,"red.bmp");
					if(i==3 && j==5) iShowBMP(565,510,"red.bmp");
					if(i==5 && j==5) iShowBMP(565,380,"red.bmp");
					if(i==7 && j==5) iShowBMP(565,250,"red.bmp");
					if(i==8 && j==5) iShowBMP(565,185,"red.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"red.bmp");

					if(i==2 && j==6) iShowBMP(630,575,"red.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"red.bmp");
					if(i==5 && j==6) iShowBMP(630,380,"red.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"red.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"red.bmp");
					if(i==8 && j==6) iShowBMP(630,185,"red.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"red.bmp");
					if(i==3 && j==7) iShowBMP(695,510,"red.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"red.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"red.bmp");
					if(i==8 && j==7) iShowBMP(695,185,"red.bmp");

					if(i==2 && j==8) iShowBMP(760,575,"red.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"red.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"red.bmp");
					if(i==6 && j==8) iShowBMP(760,315,"red.bmp");
					if(i==7 && j==8) iShowBMP(760,250,"red.bmp");
					if(i==8 && j==8) iShowBMP(760,185,"red.bmp");
					if(i==9 && j==8) iShowBMP(760,120,"red.bmp");

					if(i==3 && j==9) iShowBMP(825,510,"red.bmp");
					if(i==4 && j==9) iShowBMP(825,445,"red.bmp");
					if(i==6 && j==9) iShowBMP(825,315,"red.bmp");
					if(i==8 && j==9) iShowBMP(825,185,"red.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"red.bmp");
				}
			}
		}

	}

}


void stage_4()
{
	// 1st column

	if(f11==1) iShowBMP(300,600,"typedone.bmp");
	else if(f11==2) iShowBMP(300,600,"typedtwo.bmp");
	else if(f11==3) iShowBMP(300,600,"typedthree.bmp");
	else if(f11==4) iShowBMP(300,600,"typedfour.bmp");
	else if(f11==5) iShowBMP(300,600,"typedfive.bmp");
	else if(f11==6) iShowBMP(300,600,"typedsix.bmp");
	else if(f11==7) iShowBMP(300,600,"typedseven.bmp");
	else if(f11==8) iShowBMP(300,600,"typedeight.bmp");
	else if(f11==9) iShowBMP(300,600,"typednine.bmp");
	else iShowBMP(300,600,"grid.bmp");
    if(flagmouse==11) iShowBMP(350,648,"mark.bmp");
    
    if(f12==1) iShowBMP(300,535,"typedone.bmp");
	else if(f12==2) iShowBMP(300,535,"typedtwo.bmp");
	else if(f12==3) iShowBMP(300,535,"typedthree.bmp");
	else if(f12==4) iShowBMP(300,535,"typedfour.bmp");
	else if(f12==5) iShowBMP(300,535,"typedfive.bmp");
	else if(f12==6) iShowBMP(300,535,"typedsix.bmp");
	else if(f12==7) iShowBMP(300,535,"typedseven.bmp");
	else if(f12==8) iShowBMP(300,535,"typedeight.bmp");
	else if(f12==9) iShowBMP(300,535,"typednine.bmp");
	else iShowBMP(300,535,"grid.bmp");
    if(flagmouse==12) iShowBMP(350,583,"mark.bmp");
    
	if(f13==1) iShowBMP(300,470,"typedone.bmp");
	else if(f13==2) {iShowBMP(300,470,"typedtwo.bmp");}
	else if(f13==3) iShowBMP(300,470,"typedthree.bmp");
	else if(f13==4) iShowBMP(300,470,"typedfour.bmp");
	else if(f13==5) iShowBMP(300,470,"typedfive.bmp");
	else if(f13==6) iShowBMP(300,470,"typedsix.bmp");
	else if(f13==7) iShowBMP(300,470,"typedseven.bmp");
	else if(f13==8) iShowBMP(300,470,"typedeight.bmp");
	else if(f13==9) iShowBMP(300,470,"typednine.bmp");
	else iShowBMP(300,470,"grid.bmp");
    if(flagmouse==13) iShowBMP(350,518,"mark.bmp");
    
    if(f14==1) iShowBMP(300,470,"typedone.bmp");
	else if(f14==2) {iShowBMP(300,405,"typedtwo.bmp");}
	else if(f14==3) iShowBMP(300,405,"typedthree.bmp");
	else if(f14==4) iShowBMP(300,405,"typedfour.bmp");
	else if(f14==5) iShowBMP(300,405,"typedfive.bmp");
	else if(f14==6) iShowBMP(300,405,"typedsix.bmp");
	else if(f14==7) iShowBMP(300,405,"typedseven.bmp");
	else if(f14==8) iShowBMP(300,405,"typedeight.bmp");
	else if(f14==9) iShowBMP(300,405,"typednine.bmp");
	else iShowBMP(300,405,"grid.bmp");
    if(flagmouse==14) iShowBMP(350,451,"mark.bmp");
    
	if(f15==1) iShowBMP(300,340,"typedone.bmp");
	else if(f15==2) {iShowBMP(300,340,"typedtwo.bmp");}
	else if(f15==3) iShowBMP(300,340,"typedthree.bmp");
	else if(f15==4) iShowBMP(300,340,"typedfour.bmp");
	else if(f15==5) iShowBMP(300,340,"typedfive.bmp");
	else if(f15==6) iShowBMP(300,340,"typedsix.bmp");
	else if(f15==7) iShowBMP(300,340,"typedseven.bmp");
	else if(f15==8) iShowBMP(300,340,"typedeight.bmp");
	else if(f15==9) iShowBMP(300,340,"typednine.bmp");
	else iShowBMP(300,340,"grid.bmp");
    if(flagmouse==15) iShowBMP(350,388,"mark.bmp");
    
   
	iShowBMP(300,275,"two.bmp");
 
	if(f17==1) iShowBMP(300,210,"typedone.bmp");
	else if(f17==2) {iShowBMP(300,210,"typedtwo.bmp");}
	else if(f17==3) iShowBMP(300,210,"typedthree.bmp");
	else if(f17==4) iShowBMP(300,210,"typedfour.bmp");
	else if(f17==5) iShowBMP(300,210,"typedfive.bmp");
	else if(f17==6) iShowBMP(300,210,"typedsix.bmp");
	else if(f17==7) iShowBMP(300,210,"typedseven.bmp");
	else if(f17==8) iShowBMP(300,210,"typedeight.bmp");
	else if(f17==9) iShowBMP(300,210,"typednine.bmp");
	else iShowBMP(300,210,"grid.bmp");
	if(flagmouse==17) iShowBMP(350,256,"mark.bmp");
	

	iShowBMP(300,145,"eight.bmp");

	
	if(f19==1) iShowBMP(300,80,"typedone.bmp");
	else if(f19==2) {iShowBMP(300,80,"typedtwo.bmp");}
	else if(f19==3) iShowBMP(300,80,"typedthree.bmp");
	else if(f19==4) iShowBMP(300,80,"typedfour.bmp");
	else if(f19==5) iShowBMP(300,80,"typedfive.bmp");
	else if(f19==6) iShowBMP(300,80,"typedsix.bmp");
	else if(f19==7) iShowBMP(300,80,"typedseven.bmp");
	else if(f19==8) iShowBMP(300,80,"typedeight.bmp");
	else if(f19==9) iShowBMP(300,80,"typednine.bmp");
	else iShowBMP(300,80,"grid.bmp");
	if(flagmouse==19) iShowBMP(350,128,"mark.bmp");

	// second column

	iShowBMP(365,600,"nine.bmp");


	if(f22==1) iShowBMP(365,535,"typedone.bmp");
	else if(f22==2) iShowBMP(365,535,"typedtwo.bmp");
	else if(f22==3) iShowBMP(365,535,"typedthree.bmp");
	else if(f22==4) iShowBMP(365,535,"typedfour.bmp");
	else if(f22==5) iShowBMP(365,535,"typedfive.bmp");
	else if(f22==6) iShowBMP(365,535,"typedsix.bmp");
	else if(f22==7) iShowBMP(365,535,"typedseven.bmp");
	else if(f22==8) iShowBMP(365,535,"typedeight.bmp");
	else if(f22==9) iShowBMP(365,535,"typednine.bmp");
	else iShowBMP(365,535,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==22) iShowBMP(415,584,"mark.bmp");

	if(f23==1) iShowBMP(365,470,"typedone.bmp");
	else if(f23==2) iShowBMP(365,470,"typedtwo.bmp");
	else if(f23==3) iShowBMP(365,470,"typedthree.bmp");
	else if(f23==4) iShowBMP(365,470,"typedfour.bmp");
	else if(f23==5) iShowBMP(365,470,"typedfive.bmp");
	else if(f23==6) iShowBMP(365,470,"typedsix.bmp");
	else if(f23==7) iShowBMP(365,470,"typedseven.bmp");
	else if(f23==8) iShowBMP(365,470,"typedeight.bmp");
	else if(f23==9) iShowBMP(365,470,"typednine.bmp");
	else iShowBMP(365,470,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==23) iShowBMP(415,517,"mark.bmp");

	if(f24==1) iShowBMP(365,405,"typedone.bmp");
	else if(f24==2) iShowBMP(365,405,"typedtwo.bmp");
	else if(f24==3) iShowBMP(365,405,"typedthree.bmp");
	else if(f24==4) iShowBMP(365,405,"typedfour.bmp");
	else if(f24==5) iShowBMP(365,405,"typedfive.bmp");
	else if(f24==6) iShowBMP(365,405,"typedsix.bmp");
	else if(f24==7) iShowBMP(365,405,"typedseven.bmp");
	else if(f24==8) iShowBMP(365,405,"typedeight.bmp");
	else if(f24==9) iShowBMP(365,405,"typednine.bmp");
	else iShowBMP(365,405,"grid.bmp");//iShowBMP(365,405,"grid.bmp");
	if(flagmouse==24) iShowBMP(415,452,"mark.bmp");


	iShowBMP(365,340,"six.bmp");//iShowBMP(365,340,"grid.bmp");

	if(f26==1) iShowBMP(365,275,"typedone.bmp");
	else if(f26==2) iShowBMP(365,275,"typedtwo.bmp");
	else if(f26==3) iShowBMP(365,275,"typedthree.bmp");
	else if(f26==4) iShowBMP(365,275,"typedfour.bmp");
	else if(f26==5) iShowBMP(365,275,"typedfive.bmp");
	else if(f26==6) iShowBMP(365,275,"typedsix.bmp");
	else if(f26==7) iShowBMP(365,275,"typedseven.bmp");
	else if(f26==8) iShowBMP(365,275,"typedeight.bmp");
	else if(f26==9) iShowBMP(365,275,"typednine.bmp");
	else iShowBMP(365,275,"grid.bmp");//iShowBMP(365,275,"grid.bmp");
	if(flagmouse==26) iShowBMP(415,323,"mark.bmp");

	if(f27==1) iShowBMP(365,210,"typedone.bmp");
	else if(f27==2) iShowBMP(365,210,"typedtwo.bmp");
	else if(f27==3) iShowBMP(365,210,"typedthree.bmp");
	else if(f27==4) iShowBMP(365,210,"typedfour.bmp");
	else if(f27==5) iShowBMP(365,210,"typedfive.bmp");
	else if(f27==6) iShowBMP(365,210,"typedsix.bmp");
	else if(f27==7) iShowBMP(365,210,"typedseven.bmp");
	else if(f27==8) iShowBMP(365,210,"typedeight.bmp");
	else if(f27==9) iShowBMP(365,210,"typednine.bmp");
	else iShowBMP(365,210,"grid.bmp");//iShowBMP(365,275,"grid.bmp");
	if(flagmouse==27) iShowBMP(415,257,"mark.bmp");

	if(f28==1) iShowBMP(365,145,"typedone.bmp");
	else if(f28==2) iShowBMP(365,145,"typedtwo.bmp");
	else if(f28==3) iShowBMP(365,145,"typedthree.bmp");
	else if(f28==4) iShowBMP(365,145,"typedfour.bmp");
	else if(f28==5) iShowBMP(365,145,"typedfive.bmp");
	else if(f28==6) iShowBMP(365,145,"typedsix.bmp");
	else if(f28==7) iShowBMP(365,145,"typedseven.bmp");
	else if(f28==8) iShowBMP(365,145,"typedeight.bmp");
	else if(f28==9) iShowBMP(365,145,"typednine.bmp");
	else iShowBMP(365,145,"grid.bmp");//iShowBMP(365,145,"grid.bmp");
	if(flagmouse==28) iShowBMP(415,193,"mark.bmp");


	iShowBMP(365,80,"five.bmp");


	// 3rd column
	if(f31==1) iShowBMP(430,600,"typedone.bmp");
	else if(f31==2) iShowBMP(430,600,"typedtwo.bmp");
	else if(f31==3) iShowBMP(430,600,"typedthree.bmp");
	else if(f31==4) iShowBMP(430,600,"typedfour.bmp");
	else if(f31==5) iShowBMP(430,600,"typedfive.bmp");
	else if(f31==6) iShowBMP(430,600,"typedsix.bmp");
	else if(f31==7) iShowBMP(430,600,"typedseven.bmp");
	else if(f31==8) iShowBMP(430,600,"typedeight.bmp");
	else if(f31==9) iShowBMP(430,600,"typednine.bmp");
	else iShowBMP(430,600,"grid.bmp");//iShowBMP(430,600,"grid.bmp");
	if(flagmouse==31) iShowBMP(478,648,"mark.bmp");


	iShowBMP(430,535,"five.bmp");

	if(f33==1) iShowBMP(430,470,"typedone.bmp");
	else if(f33==2) iShowBMP(430,470,"typedtwo.bmp");
	else if(f33==3) iShowBMP(430,470,"typedthree.bmp");
	else if(f33==4) iShowBMP(430,470,"typedfour.bmp");
	else if(f33==5) iShowBMP(430,470,"typedfive.bmp");
	else if(f33==6) iShowBMP(430,470,"typedsix.bmp");
	else if(f33==7) iShowBMP(430,470,"typedseven.bmp");
	else if(f33==8) iShowBMP(430,470,"typedeight.bmp");
	else if(f33==9) iShowBMP(430,470,"typednine.bmp");
	else iShowBMP(430,470,"grid.bmp");//iShowBMP(430,535,"grid.bmp");
	if(flagmouse==33) iShowBMP(478,516,"mark.bmp");

	iShowBMP(430,405,"one.bmp");

	if(f35==1) iShowBMP(430,340,"typedone.bmp");
	else if(f35==2) iShowBMP(430,340,"typedtwo.bmp");
	else if(f35==3) iShowBMP(430,340,"typedthree.bmp");
	else if(f35==4) iShowBMP(430,340,"typedfour.bmp");
	else if(f35==5) iShowBMP(430,340,"typedfive.bmp");
	else if(f35==6) iShowBMP(430,340,"typedsix.bmp");
	else if(f35==7) iShowBMP(430,340,"typedseven.bmp");
	else if(f35==8) iShowBMP(430,340,"typedeight.bmp");
	else if(f35==9) iShowBMP(430,340,"typednine.bmp");
	else iShowBMP(430,340,"grid.bmp");//iShowBMP(430,340,"grid.bmp");
	if(flagmouse==35) iShowBMP(478,388,"mark.bmp");

	if(f36==1) iShowBMP(430,275,"typedone.bmp");
	else if(f36==2) iShowBMP(430,275,"typedtwo.bmp");
	else if(f36==3) iShowBMP(430,275,"typedthree.bmp");
	else if(f36==4) iShowBMP(430,275,"typedfour.bmp");
	else if(f36==5) iShowBMP(430,275,"typedfive.bmp");
	else if(f36==6) iShowBMP(430,275,"typedsix.bmp");
	else if(f36==7) iShowBMP(430,275,"typedseven.bmp");
	else if(f36==8) iShowBMP(430,275,"typedeight.bmp");
	else if(f36==9) iShowBMP(430,275,"typednine.bmp");
	else iShowBMP(430,275,"grid.bmp");//iShowBMP(430,275,"grid.bmp");
	if(flagmouse==36) iShowBMP(478,323,"mark.bmp");


	iShowBMP(430,210,"three.bmp");
	
	if(f38==1) iShowBMP(430,145,"typedone.bmp");
	else if(f38==2) iShowBMP(430,145,"typedtwo.bmp");
	else if(f38==3) iShowBMP(430,145,"typedthree.bmp");
	else if(f38==4) iShowBMP(430,145,"typedfour.bmp");
	else if(f38==5) iShowBMP(430,145,"typedfive.bmp");
	else if(f38==6) iShowBMP(430,145,"typedsix.bmp");
	else if(f38==7) iShowBMP(430,145,"typedseven.bmp");
	else if(f38==8) iShowBMP(430,145,"typedeight.bmp");
	else if(f38==9) iShowBMP(430,145,"typednine.bmp");
	else iShowBMP(430,145,"grid.bmp");
	if(flagmouse==38) iShowBMP(478,192,"mark.bmp");

	if(f39==1) iShowBMP(430,80,"typedone.bmp");
	else if(f39==2) iShowBMP(430,80,"typedtwo.bmp");
	else if(f39==3) iShowBMP(430,80,"typedthree.bmp");
	else if(f39==4) iShowBMP(430,80,"typedfour.bmp");
	else if(f39==5) iShowBMP(430,80,"typedfive.bmp");
	else if(f39==6) iShowBMP(430,80,"typedsix.bmp");
	else if(f39==7) iShowBMP(430,80,"typedseven.bmp");
	else if(f39==8) iShowBMP(430,80,"typedeight.bmp");
	else if(f39==9) iShowBMP(430,80,"typednine.bmp");
	else iShowBMP(430,80,"grid.bmp");
	if(flagmouse==39) iShowBMP(478,128,"mark.bmp");

	// 4th column
	
	if(f41==1) iShowBMP(495,600,"typedone.bmp");
	else if(f41==2) iShowBMP(495,600,"typedtwo.bmp");
	else if(f41==3) iShowBMP(495,600,"typedthree.bmp");
	else if(f41==4) iShowBMP(495,600,"typedfour.bmp");
	else if(f41==5) iShowBMP(495,600,"typedfive.bmp");
	else if(f41==6) iShowBMP(495,600,"typedsix.bmp");
	else if(f41==7) iShowBMP(495,600,"typedseven.bmp");
	else if(f41==8) iShowBMP(495,600,"typedeight.bmp");
	else if(f41==9) iShowBMP(495,600,"typednine.bmp");
	else iShowBMP(495,600,"grid.bmp");
	if(flagmouse==41) iShowBMP(545,648,"mark.bmp");


	iShowBMP(495,535,"three.bmp");
	
	if(f43==1) iShowBMP(495,470,"typedone.bmp");
	else if(f43==2) iShowBMP(495,470,"typedtwo.bmp");
	else if(f43==3) iShowBMP(495,470,"typedthree.bmp");
	else if(f43==4) iShowBMP(495,470,"typedfour.bmp");
	else if(f43==5) iShowBMP(495,470,"typedfive.bmp");
	else if(f43==6) iShowBMP(495,470,"typedsix.bmp");
	else if(f43==7) iShowBMP(495,470,"typedseven.bmp");
	else if(f43==8) iShowBMP(495,470,"typedeight.bmp");
	else if(f43==9) iShowBMP(495,470,"typednine.bmp");
	else iShowBMP(495,470,"grid.bmp");
	if(flagmouse==43) iShowBMP(545,518,"mark.bmp");

	if(f44==1) iShowBMP(495,405,"typedone.bmp");
	else if(f44==2) iShowBMP(495,405,"typedtwo.bmp");
	else if(f44==3) iShowBMP(495,405,"typedthree.bmp");
	else if(f44==4) iShowBMP(495,405,"typedfour.bmp");
	else if(f44==5) iShowBMP(495,405,"typedfive.bmp");
	else if(f44==6) iShowBMP(495,405,"typedsix.bmp");
	else if(f44==7) iShowBMP(495,405,"typedseven.bmp");
	else if(f44==8) iShowBMP(495,405,"typedeight.bmp");
	else if(f44==9) iShowBMP(495,405,"typednine.bmp");
	else iShowBMP(495,405,"grid.bmp");//iShowBMP(495,405,"grid.bmp");
	if(flagmouse==44) iShowBMP(545,451,"mark.bmp");

	if(f45==1) iShowBMP(495,340,"typedone.bmp");
	else if(f45==2) iShowBMP(495,340,"typedtwo.bmp");
	else if(f45==3) iShowBMP(495,340,"typedthree.bmp");
	else if(f45==4) iShowBMP(495,340,"typedfour.bmp");
	else if(f45==5) iShowBMP(495,340,"typedfive.bmp");
	else if(f45==6) iShowBMP(495,340,"typedsix.bmp");
	else if(f45==7) iShowBMP(495,340,"typedseven.bmp");
	else if(f45==8) iShowBMP(495,340,"typedeight.bmp");
	else if(f45==9) iShowBMP(495,340,"typednine.bmp");
	else iShowBMP(495,340,"grid.bmp");//iShowBMP(495,405,"grid.bmp");
	if(flagmouse==45) iShowBMP(545,388,"mark.bmp");

	if(f46==1) iShowBMP(495,275,"typedone.bmp");
	else if(f46==2) iShowBMP(495,275,"typedtwo.bmp");
	else if(f46==3) iShowBMP(495,275,"typedthree.bmp");
	else if(f46==4) iShowBMP(495,275,"typedfour.bmp");
	else if(f46==5) iShowBMP(495,275,"typedfive.bmp");
	else if(f46==6) iShowBMP(495,275,"typedsix.bmp");
	else if(f46==7) iShowBMP(495,275,"typedseven.bmp");
	else if(f46==8) iShowBMP(495,275,"typedeight.bmp");
	else if(f46==9) iShowBMP(495,275,"typednine.bmp");
	else iShowBMP(495,275,"grid.bmp");//iShowBMP(495,275,"grid.bmp");
	if(flagmouse==46) iShowBMP(545,323,"mark.bmp");

	if(f47==1) iShowBMP(495,210,"typedone.bmp");
	else if(f47==2) iShowBMP(495,210,"typedtwo.bmp");
	else if(f47==3) iShowBMP(495,210,"typedthree.bmp");
	else if(f47==4) iShowBMP(495,210,"typedfour.bmp");
	else if(f47==5) iShowBMP(495,210,"typedfive.bmp");
	else if(f47==6) iShowBMP(495,210,"typedsix.bmp");
	else if(f47==7) iShowBMP(495,210,"typedseven.bmp");
	else if(f47==8) iShowBMP(495,210,"typedeight.bmp");
	else if(f47==9) iShowBMP(495,210,"typednine.bmp");
	else iShowBMP(495,210,"grid.bmp");//iShowBMP(495,210,"grid.bmp");
	if(flagmouse==47) iShowBMP(545,256,"mark.bmp");

	if(f48==1) iShowBMP(495,145,"typedone.bmp");
	else if(f48==2) iShowBMP(495,145,"typedtwo.bmp");
	else if(f48==3) iShowBMP(495,145,"typedthree.bmp");
	else if(f48==4) iShowBMP(495,145,"typedfour.bmp");
	else if(f48==5) iShowBMP(495,145,"typedfive.bmp");
	else if(f48==6) iShowBMP(495,145,"typedsix.bmp");
	else if(f48==7) iShowBMP(495,145,"typedseven.bmp");
	else if(f48==8) iShowBMP(495,145,"typedeight.bmp");
	else if(f48==9) iShowBMP(495,145,"typednine.bmp");
	else iShowBMP(495,145,"grid.bmp");
	if(flagmouse==48) iShowBMP(545,191,"mark.bmp");

	iShowBMP(495,80,"four.bmp");

	// 5th column
	if(f51==1) iShowBMP(560,600,"typedone.bmp");
	else if(f51==2) iShowBMP(560,600,"typedtwo.bmp");
	else if(f51==3) iShowBMP(560,600,"typedthree.bmp");
	else if(f51==4) iShowBMP(560,600,"typedfour.bmp");
	else if(f51==5) iShowBMP(560,600,"typedfive.bmp");
	else if(f51==6) iShowBMP(560,600,"typedsix.bmp");
	else if(f51==7) iShowBMP(560,600,"typedseven.bmp");
	else if(f51==8) iShowBMP(560,600,"typedeight.bmp");
	else if(f51==9) iShowBMP(560,600,"typednine.bmp");
	else iShowBMP(560,600,"grid.bmp");
	if(flagmouse==51) iShowBMP(610,648,"mark.bmp");

	if(f52==1) iShowBMP(560,535,"typedone.bmp");
	else if(f52==2) iShowBMP(560,535,"typedtwo.bmp");
	else if(f52==3) iShowBMP(560,535,"typedthree.bmp");
	else if(f52==4) iShowBMP(560,535,"typedfour.bmp");
	else if(f52==5) iShowBMP(560,535,"typedfive.bmp");
	else if(f52==6) iShowBMP(560,535,"typedsix.bmp");
	else if(f52==7) iShowBMP(560,535,"typedseven.bmp");
	else if(f52==8) iShowBMP(560,535,"typedeight.bmp");
	else if(f52==9) iShowBMP(560,535,"typednine.bmp");
	else iShowBMP(560,535,"grid.bmp");
	if(flagmouse==52) iShowBMP(610,582,"mark.bmp");

	iShowBMP(560,470,"seven.bmp");
	

	iShowBMP(560,405,"five.bmp");

	
	if(f55==1) iShowBMP(560,340,"typedone.bmp");
	else if(f55==2) iShowBMP(560,340,"typedtwo.bmp");
	else if(f55==3) iShowBMP(560,340,"typedthree.bmp");
	else if(f55==4) iShowBMP(560,340,"typedfour.bmp");
	else if(f55==5) iShowBMP(560,340,"typedfive.bmp");
	else if(f55==6) iShowBMP(560,340,"typedsix.bmp");
	else if(f55==7) iShowBMP(560,340,"typedseven.bmp");
	else if(f55==8) iShowBMP(560,340,"typedeight.bmp");
	else if(f55==9) iShowBMP(560,340,"typednine.bmp");
	else iShowBMP(560,340,"grid.bmp");//iShowBMP(560,340,"grid.bmp");
	if(flagmouse==55) iShowBMP(610,388,"mark.bmp");

	iShowBMP(560,275,"eight.bmp");

	iShowBMP(560,210,"one.bmp");
	
	if(f58==1) iShowBMP(560,145,"typedone.bmp");
	else if(f58==2) iShowBMP(560,145,"typedtwo.bmp");
	else if(f58==3) iShowBMP(560,145,"typedthree.bmp");
	else if(f58==4) iShowBMP(560,145,"typedfour.bmp");
	else if(f58==5) iShowBMP(560,145,"typedfive.bmp");
	else if(f58==6) iShowBMP(560,145,"typedsix.bmp");
	else if(f58==7) iShowBMP(560,145,"typedseven.bmp");
	else if(f58==8) iShowBMP(560,145,"typedeight.bmp");
	else if(f58==9) iShowBMP(560,145,"typednine.bmp");
	else iShowBMP(560,145,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==58) iShowBMP(610,191,"mark.bmp");

	if(f59==1) iShowBMP(560,80,"typedone.bmp");
	else if(f59==2) iShowBMP(560,80,"typedtwo.bmp");
	else if(f59==3) iShowBMP(560,80,"typedthree.bmp");
	else if(f59==4) iShowBMP(560,80,"typedfour.bmp");
	else if(f59==5) iShowBMP(560,80,"typedfive.bmp");
	else if(f59==6) iShowBMP(560,80,"typedsix.bmp");
	else if(f59==7) iShowBMP(560,80,"typedseven.bmp");
	else if(f59==8) iShowBMP(560,80,"typedeight.bmp");
	else if(f59==9) iShowBMP(560,80,"typednine.bmp");
	else iShowBMP(560,80,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==59) iShowBMP(610,127,"mark.bmp");


	// 6th column

	iShowBMP(625,600,"six.bmp");

	if(f62==1) iShowBMP(625,535,"typedone.bmp");
	else if(f62==2) iShowBMP(625,535,"typedtwo.bmp");
	else if(f62==3) iShowBMP(625,535,"typedthree.bmp");
	else if(f62==4) iShowBMP(625,535,"typedfour.bmp");
	else if(f62==5) iShowBMP(625,535,"typedfive.bmp");
	else if(f62==6) iShowBMP(625,535,"typedsix.bmp");
	else if(f62==7) iShowBMP(625,535,"typedseven.bmp");
	else if(f62==8) iShowBMP(625,535,"typedeight.bmp");
	else if(f62==9) iShowBMP(625,535,"typednine.bmp");
	else iShowBMP(625,535,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==62) iShowBMP(673,582,"mark.bmp");

	if(f63==1) iShowBMP(625,470,"typedone.bmp");
	else if(f63==2) iShowBMP(625,470,"typedtwo.bmp");
	else if(f63==3) iShowBMP(625,470,"typedthree.bmp");
	else if(f63==4) iShowBMP(625,470,"typedfour.bmp");
	else if(f63==5) iShowBMP(625,470,"typedfive.bmp");
	else if(f63==6) iShowBMP(625,470,"typedsix.bmp");
	else if(f63==7) iShowBMP(625,470,"typedseven.bmp");
	else if(f63==8) iShowBMP(625,470,"typedeight.bmp");
	else if(f63==9) iShowBMP(625,470,"typednine.bmp");
	else iShowBMP(625,470,"grid.bmp");
	if(flagmouse == 63) iShowBMP(673,518,"mark.bmp");

	if(f64==1) iShowBMP(625,405,"typedone.bmp");
	else if(f64==2) iShowBMP(625,405,"typedtwo.bmp");
	else if(f64==3) iShowBMP(625,405,"typedthree.bmp");
	else if(f64==4) iShowBMP(625,405,"typedfour.bmp");
	else if(f64==5) iShowBMP(625,405,"typedfive.bmp");
	else if(f64==6) iShowBMP(625,405,"typedsix.bmp");
	else if(f64==7) iShowBMP(625,405,"typedseven.bmp");
	else if(f64==8) iShowBMP(625,405,"typedeight.bmp");
	else if(f64==9) iShowBMP(625,405,"typednine.bmp");
	else iShowBMP(625,405,"grid.bmp");
	if(flagmouse == 64) iShowBMP(673,451,"mark.bmp");
	
	
	iShowBMP(625,340,"nine.bmp");

	iShowBMP(625,275,"four.bmp");

	if(f67==1) iShowBMP(625,210,"typedone.bmp");
	else if(f67==2) iShowBMP(625,210,"typedtwo.bmp");
	else if(f67==3) iShowBMP(625,210,"typedthree.bmp");
	else if(f67==4) iShowBMP(625,210,"typedfour.bmp");
	else if(f67==5) iShowBMP(625,210,"typedfive.bmp");
	else if(f67==6) iShowBMP(625,210,"typedsix.bmp");
	else if(f67==7) iShowBMP(625,210,"typedseven.bmp");
	else if(f67==8) iShowBMP(625,210,"typedeight.bmp");
	else if(f67==9) iShowBMP(625,210,"typednine.bmp");
	else iShowBMP(625,210,"grid.bmp");
	if (flagmouse == 67) iShowBMP(673,256,"mark.bmp");
	
	iShowBMP(625,145,"two.bmp");

	if(f69==1) iShowBMP(625,80,"typedone.bmp");
	else if(f69==2) iShowBMP(625,80,"typedtwo.bmp");
	else if(f69==3) iShowBMP(625,80,"typedthree.bmp");
	else if(f69==4) iShowBMP(625,80,"typedfour.bmp");
	else if(f69==5) iShowBMP(625,80,"typedfive.bmp");
	else if(f69==6) iShowBMP(625,80,"typedsix.bmp");
	else if(f69==7) iShowBMP(625,80,"typedseven.bmp");
	else if(f69==8) iShowBMP(625,80,"typedeight.bmp");
	else if(f69==9) iShowBMP(625,80,"typednine.bmp");
	else iShowBMP(625,80,"grid.bmp");
	if (flagmouse == 69) iShowBMP(673,128,"mark.bmp");
	
	// 7th column

	if(f71==1) iShowBMP(690,600,"typedone.bmp");
	else if(f71==2) iShowBMP(690,600,"typedtwo.bmp");
	else if(f71==3) iShowBMP(690,600,"typedthree.bmp");
	else if(f71==4) iShowBMP(690,600,"typedfour.bmp");
	else if(f71==5) iShowBMP(690,600,"typedfive.bmp");
	else if(f71==6) iShowBMP(690,600,"typedsix.bmp");
	else if(f71==7) iShowBMP(690,600,"typedseven.bmp");
	else if(f71==8) iShowBMP(690,600,"typedeight.bmp");
	else if(f71==9) iShowBMP(690,600,"typednine.bmp");
	else iShowBMP(690,600,"grid.bmp");
	if (flagmouse == 71) iShowBMP(740,648,"mark.bmp");

	if(f72==1) iShowBMP(690,535,"typedone.bmp");
	else if(f72==2) iShowBMP(690,535,"typedtwo.bmp");
	else if(f72==3) iShowBMP(690,535,"typedthree.bmp");
	else if(f72==4) iShowBMP(690,535,"typedfour.bmp");
	else if(f72==5) iShowBMP(690,535,"typedfive.bmp");
	else if(f72==6) iShowBMP(690,535,"typedsix.bmp");
	else if(f72==7) iShowBMP(690,535,"typedseven.bmp");
	else if(f72==8) iShowBMP(690,535,"typedeight.bmp");
	else if(f72==9) iShowBMP(690,535,"typednine.bmp");
	else iShowBMP(690,535,"grid.bmp");
	if(flagmouse == 72) iShowBMP(740,583,"mark.bmp");


	iShowBMP(690,470,"two.bmp");


	if(f74==1) iShowBMP(690,405,"typedone.bmp");
	else if(f74==2) iShowBMP(690,405,"typedtwo.bmp");
	else if(f74==3) iShowBMP(690,405,"typedthree.bmp");
	else if(f74==4) iShowBMP(690,405,"typedfour.bmp");
	else if(f74==5) iShowBMP(690,405,"typedfive.bmp");
	else if(f74==6) iShowBMP(690,405,"typedsix.bmp");
	else if(f74==7) iShowBMP(690,405,"typedseven.bmp");
	else if(f74==8) iShowBMP(690,405,"typedeight.bmp");
	else if(f74==9) iShowBMP(690,405,"typednine.bmp");
	else iShowBMP(690,405,"grid.bmp");
	if(flagmouse == 74) iShowBMP(740,451,"mark.bmp");
	
	if(f75==1) iShowBMP(690,340,"typedone.bmp");
	else if(f75==2) iShowBMP(690,340,"typedtwo.bmp");
	else if(f75==3) iShowBMP(690,340,"typedthree.bmp");
	else if(f75==4) iShowBMP(690,340,"typedfour.bmp");
	else if(f75==5) iShowBMP(690,340,"typedfive.bmp");
	else if(f75==6) iShowBMP(690,340,"typedsix.bmp");
	else if(f75==7) iShowBMP(690,340,"typedseven.bmp");
	else if(f75==8) iShowBMP(690,340,"typedeight.bmp");
	else if(f75==9) iShowBMP(690,340,"typednine.bmp");
	else iShowBMP(690,340,"grid.bmp");
	if(flagmouse == 75)iShowBMP(740,388,"mark.bmp");
	

	iShowBMP(690,275,"one.bmp");

	if(f77==1) iShowBMP(690,210,"typedone.bmp");
	else if(f77==2) iShowBMP(690,210,"typedtwo.bmp");
	else if(f77==3) iShowBMP(690,210,"typedthree.bmp");
	else if(f77==4) iShowBMP(690,210,"typedfour.bmp");
	else if(f77==5) iShowBMP(690,210,"typedfive.bmp");
	else if(f77==6) iShowBMP(690,210,"typedsix.bmp");
	else if(f77==7) iShowBMP(690,210,"typedseven.bmp");
	else if(f77==8) iShowBMP(690,210,"typedeight.bmp");
	else if(f77==9) iShowBMP(690,210,"typednine.bmp");
	else iShowBMP(690,210,"grid.bmp");
	if(flagmouse == 77)iShowBMP(740,257,"mark.bmp");


	iShowBMP(690,145,"five.bmp");
	
	if(f79==1) iShowBMP(690,80,"typedone.bmp");
	else if(f79==2) iShowBMP(690,80,"typedtwo.bmp");
	else if(f79==3) iShowBMP(690,80,"typedthree.bmp");
	else if(f79==4) iShowBMP(690,80,"typedfour.bmp");
	else if(f79==5) iShowBMP(690,80,"typedfive.bmp");
	else if(f79==6) iShowBMP(690,80,"typedsix.bmp");
	else if(f79==7) iShowBMP(690,80,"typedseven.bmp");
	else if(f79==8) iShowBMP(690,80,"typedeight.bmp");
	else if(f79==9) iShowBMP(690,80,"typednine.bmp");
	else iShowBMP(690,80,"grid.bmp");
	if(flagmouse == 79)iShowBMP(740,128,"mark.bmp");
	
	
	// 8th column

	iShowBMP(755,600,"four.bmp");

	if(f82==1) iShowBMP(755,535,"typedone.bmp");
	else if(f82==2) iShowBMP(755,535,"typedtwo.bmp");
	else if(f82==3) iShowBMP(755,535,"typedthree.bmp");
	else if(f82==4) iShowBMP(755,535,"typedfour.bmp");
	else if(f82==5) iShowBMP(755,535,"typedfive.bmp");
	else if(f82==6) iShowBMP(755,535,"typedsix.bmp");
	else if(f82==7) iShowBMP(755,535,"typedseven.bmp");
	else if(f82==8) iShowBMP(755,535,"typedeight.bmp");
	else if(f82==9) iShowBMP(755,535,"typednine.bmp");
	else iShowBMP(755,535,"grid.bmp");
	if(flagmouse == 82) iShowBMP(805,583,"mark.bmp");

	if(f83==1) iShowBMP(755,470,"typedone.bmp");
	else if(f83==2) iShowBMP(755,470,"typedtwo.bmp");
	else if(f83==3) iShowBMP(755,470,"typedthree.bmp");
	else if(f83==4) iShowBMP(755,470,"typedfour.bmp");
	else if(f83==5) iShowBMP(755,470,"typedfive.bmp");
	else if(f83==6) iShowBMP(755,470,"typedsix.bmp");
	else if(f83==7) iShowBMP(755,470,"typedseven.bmp");
	else if(f83==8) iShowBMP(755,470,"typedeight.bmp");
	else if(f83==9) iShowBMP(755,470,"typednine.bmp");
	else iShowBMP(755,470,"grid.bmp");
	if(flagmouse == 83) iShowBMP(805,517,"mark.bmp");

	if(f84==1) iShowBMP(755,405,"typedone.bmp");
	else if(f84==2) iShowBMP(755,405,"typedtwo.bmp");
	else if(f84==3) iShowBMP(755,405,"typedthree.bmp");
	else if(f84==4) iShowBMP(755,405,"typedfour.bmp");
	else if(f84==5) iShowBMP(755,405,"typedfive.bmp");
	else if(f84==6) iShowBMP(755,405,"typedsix.bmp");
	else if(f84==7) iShowBMP(755,405,"typedseven.bmp");
	else if(f84==8) iShowBMP(755,405,"typedeight.bmp");
	else if(f84==9) iShowBMP(755,405,"typednine.bmp");
	else iShowBMP(755,405,"grid.bmp");
	if(flagmouse == 84) iShowBMP(805,451,"mark.bmp");

	iShowBMP(755,340,"seven.bmp");

	if(f86==1) iShowBMP(755,275,"typedone.bmp");
	else if(f86==2) iShowBMP(755,275,"typedtwo.bmp");
	else if(f86==3) iShowBMP(755,275,"typedthree.bmp");
	else if(f86==4) iShowBMP(755,275,"typedfour.bmp");
	else if(f86==5) iShowBMP(755,275,"typedfive.bmp");
	else if(f86==6) iShowBMP(755,275,"typedsix.bmp");
	else if(f86==7) iShowBMP(755,275,"typedseven.bmp");
	else if(f86==8) iShowBMP(755,275,"typedeight.bmp");
	else if(f86==9) iShowBMP(755,275,"typednine.bmp");
	else iShowBMP(755,275,"grid.bmp");
	if(flagmouse == 86) iShowBMP(805,323,"mark.bmp");	

	if(f87==1) iShowBMP(755,210,"typedone.bmp");
	else if(f87==2) iShowBMP(755,210,"typedtwo.bmp");
	else if(f87==3) iShowBMP(755,210,"typedthree.bmp");
	else if(f87==4) iShowBMP(755,210,"typedfour.bmp");
	else if(f87==5) iShowBMP(755,210,"typedfive.bmp");
	else if(f87==6) iShowBMP(755,210,"typedsix.bmp");
	else if(f87==7) iShowBMP(755,210,"typedseven.bmp");
	else if(f87==8) iShowBMP(755,210,"typedeight.bmp");
	else if(f87==9) iShowBMP(755,210,"typednine.bmp");
	else iShowBMP(755,210,"grid.bmp");
	if(flagmouse == 87) iShowBMP(805,256,"mark.bmp");


	if(f88==1) iShowBMP(755,145,"typedone.bmp");
	else if(f88==2) iShowBMP(755,145,"typedtwo.bmp");
	else if(f88==3) iShowBMP(755,145,"typedthree.bmp");
	else if(f88==4) iShowBMP(755,145,"typedfour.bmp");
	else if(f88==5) iShowBMP(755,145,"typedfive.bmp");
	else if(f88==6) iShowBMP(755,145,"typedsix.bmp");
	else if(f88==7) iShowBMP(755,145,"typedseven.bmp");
	else if(f88==8) iShowBMP(755,145,"typedeight.bmp");
	else if(f88==9) iShowBMP(755,145,"typednine.bmp");
	else iShowBMP(755,145,"grid.bmp");
	if(flagmouse == 88) iShowBMP(805,192,"mark.bmp");
	
	iShowBMP(755,80,"eight.bmp");

	// 9th column
	if(f91==1) iShowBMP(820,600,"typedone.bmp");
	else if(f91==2) iShowBMP(820,600,"typedtwo.bmp");
	else if(f91==3) iShowBMP(820,600,"typedthree.bmp");
	else if(f91==4) iShowBMP(820,600,"typedfour.bmp");
	else if(f91==5) iShowBMP(820,600,"typedfive.bmp");
	else if(f91==6) iShowBMP(820,600,"typedsix.bmp");
	else if(f91==7) iShowBMP(820,600,"typedseven.bmp");
	else if(f91==8) iShowBMP(820,600,"typedeight.bmp");
	else if(f91==9) iShowBMP(820,600,"typednine.bmp");
	else iShowBMP(820,600,"grid.bmp");
	if(flagmouse == 91) iShowBMP(872,648,"mark.bmp");

	iShowBMP(820,535,"eight.bmp");

	
	if(f93==1) iShowBMP(820,470,"typedone.bmp");
	else if(f93==2) iShowBMP(820,470,"typedtwo.bmp");
	else if(f93==3) iShowBMP(820,470,"typedthree.bmp");
	else if(f93==4) iShowBMP(820,470,"typedfour.bmp");
	else if(f93==5) iShowBMP(820,470,"typedfive.bmp");
	else if(f93==6) iShowBMP(820,470,"typedsix.bmp");
	else if(f93==7) iShowBMP(820,470,"typedseven.bmp");
	else if(f93==8) iShowBMP(820,470,"typedeight.bmp");
	else if(f93==9) iShowBMP(820,470,"typednine.bmp");
	else iShowBMP(820,470,"grid.bmp");
	if(flagmouse == 93) iShowBMP(872,518,"mark.bmp");
	

	iShowBMP(820,405,"three.bmp");
	
	if(f95==1) iShowBMP(820,340,"typedone.bmp");
	else if(f95==2) iShowBMP(820,340,"typedtwo.bmp");
	else if(f95==3) iShowBMP(820,340,"typedthree.bmp");
	else if(f95==4) iShowBMP(820,340,"typedfour.bmp");
	else if(f95==5) iShowBMP(820,340,"typedfive.bmp");
	else if(f95==6) iShowBMP(820,340,"typedsix.bmp");
	else if(f95==7) iShowBMP(820,340,"typedseven.bmp");
	else if(f95==8) iShowBMP(820,340,"typedeight.bmp");
	else if(f95==9) iShowBMP(820,340,"typednine.bmp");
	else iShowBMP(820,340,"grid.bmp");
	if(flagmouse == 95) iShowBMP(872,388,"mark.bmp");
	
	if(f96==1) iShowBMP(820,275,"typedone.bmp");
	else if(f96==2) iShowBMP(820,275,"typedtwo.bmp");
	else if(f96==3) iShowBMP(820,275,"typedthree.bmp");
	else if(f96==4) iShowBMP(820,275,"typedfour.bmp");
	else if(f96==5) iShowBMP(820,275,"typedfive.bmp");
	else if(f96==6) iShowBMP(820,275,"typedsix.bmp");
	else if(f96==7) iShowBMP(820,275,"typedseven.bmp");
	else if(f96==8) iShowBMP(820,275,"typedeight.bmp");
	else if(f96==9) iShowBMP(820,275,"typednine.bmp");
	else iShowBMP(820,275,"grid.bmp");
	if(flagmouse == 96) iShowBMP(872,323,"mark.bmp");
	

	if(f97==1) iShowBMP(820,210,"typedone.bmp");
	else if(f97==2) iShowBMP(820,210,"typedtwo.bmp");
	else if(f97==3) iShowBMP(820,210,"typedthree.bmp");
	else if(f97==4) iShowBMP(820,210,"typedfour.bmp");
	else if(f97==5) iShowBMP(820,210,"typedfive.bmp");
	else if(f97==6) iShowBMP(820,210,"typedsix.bmp");
	else if(f97==7) iShowBMP(820,210,"typedseven.bmp");
	else if(f97==8) iShowBMP(820,210,"typedeight.bmp");
	else if(f97==9) iShowBMP(820,210,"typednine.bmp");
	else iShowBMP(820,210,"grid.bmp");
	if(flagmouse == 97) iShowBMP(872,256,"mark.bmp");
	
	if(f98==1) iShowBMP(820,145,"typedone.bmp");
	else if(f98==2) iShowBMP(820,145,"typedtwo.bmp");
	else if(f98==3) iShowBMP(820,145,"typedthree.bmp");
	else if(f98==4) iShowBMP(820,145,"typedfour.bmp");
	else if(f98==5) iShowBMP(820,145,"typedfive.bmp");
	else if(f98==6) iShowBMP(820,145,"typedsix.bmp");
	else if(f98==7) iShowBMP(820,145,"typedseven.bmp");
	else if(f98==8) iShowBMP(820,145,"typedeight.bmp");
	else if(f98==9) iShowBMP(820,145,"typednine.bmp");
	else iShowBMP(820,145,"grid.bmp");
	if(flagmouse == 98) iShowBMP(872,191,"mark.bmp");
	
	if(f99==1) iShowBMP(820,80,"typedone.bmp");
	else if(f99==2) iShowBMP(820,80,"typedtwo.bmp");
	else if(f99==3) iShowBMP(820,80,"typedthree.bmp");
	else if(f99==4) iShowBMP(820,80,"typedfour.bmp");
	else if(f99==5) iShowBMP(820,80,"typedfive.bmp");
	else if(f99==6) iShowBMP(820,80,"typedsix.bmp");
	else if(f99==7) iShowBMP(820,80,"typedseven.bmp");
	else if(f99==8) iShowBMP(820,80,"typedeight.bmp");
	else if(f99==9) iShowBMP(820,80,"typednine.bmp");
	else iShowBMP(820,80,"grid.bmp");
	if(flagmouse == 99) iShowBMP(872,128,"mark.bmp");
	
}

void soln_stage4()
{
	int i,j;
	stage_sol_4[1][1] = 1;
	stage_sol_4[1][3] = 8;
	stage_sol_4[1][4] = 5;
	stage_sol_4[1][5] = 2;
	stage_sol_4[1][7] = 3;
	stage_sol_4[1][9] = 7;

	stage_sol_4[2][1] = 7;
	stage_sol_4[2][2] = 2;
	stage_sol_4[2][5] = 4;
	stage_sol_4[2][6] = 1;
	stage_sol_4[2][7] = 6;
	stage_sol_4[2][8] = 9;

	stage_sol_4[3][1] = 3;
	stage_sol_4[3][2] = 4;
	stage_sol_4[3][3] = 6;
	stage_sol_4[3][4] = 9;
	stage_sol_4[3][6] = 8;
	stage_sol_4[3][8] = 1;
	stage_sol_4[3][9] = 5;
	
	stage_sol_4[4][1] = 9;
	stage_sol_4[4][2] = 8;
	stage_sol_4[4][4] = 2;
	stage_sol_4[4][6] = 7;
	stage_sol_4[4][7] = 4;
	stage_sol_4[4][8] = 6;

	stage_sol_4[5][1] = 5;
	stage_sol_4[5][3] = 4;
	stage_sol_4[5][4] = 1;
	stage_sol_4[5][5] = 3;
	stage_sol_4[5][7] = 8;
	stage_sol_4[5][9] = 2;

	
	stage_sol_4[6][2] = 3;
	stage_sol_4[6][3] = 7;
	stage_sol_4[6][4] = 6;
	stage_sol_4[6][8] = 5;
	stage_sol_4[6][9] = 9;

	stage_sol_4[7][1] = 4;
	stage_sol_4[7][2] = 7;
	stage_sol_4[7][4] = 8;
	stage_sol_4[7][6] = 5;
	stage_sol_4[7][7] = 9;
	stage_sol_4[7][8] = 2;
	stage_sol_4[7][9] = 6;

	stage_sol_4[8][2] = 1;
	stage_sol_4[8][3] = 9;
	stage_sol_4[8][4] = 7;
	stage_sol_4[8][5] = 6;
	stage_sol_4[8][8] = 3;
	stage_sol_4[8][9] = 4;

	stage_sol_4[9][1] = 6;
	stage_sol_4[9][3] = 2;
	stage_sol_4[9][5] = 9;
	stage_sol_4[9][6] = 3;
	stage_sol_4[9][7] = 7;
	stage_sol_4[9][9] = 1;

	if(checkflag==1)
	{
		checkallryt=0;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(stage_sol_4[i][j]==stage4_values[i][j])
				{
					if(i==1 && j==1) iShowBMP(305,640,"green.bmp");
					if(i==2 && j==1) iShowBMP(305,575,"green.bmp");
					if(i==3 && j==1) iShowBMP(305,510,"green.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"green.bmp");
					if(i==5 && j==1) iShowBMP(305,380,"green.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"green.bmp");
					if(i==9 && j==1) iShowBMP(305,120,"green.bmp");

					if(i==2 && j==2) iShowBMP(370,575,"green.bmp");
					if(i==3 && j==2) iShowBMP(370,510,"green.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"green.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"green.bmp");
					if(i==7 && j==2) iShowBMP(370,250,"green.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"green.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"green.bmp");
					if(i==3 && j==3) iShowBMP(435,510,"green.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"green.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"green.bmp");
					if(i==8 && j==3) iShowBMP(435,186,"green.bmp");
					if(i==9 && j==3) iShowBMP(435,120,"green.bmp");

					if(i==1 && j==4) iShowBMP(500,640,"green.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"green.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"green.bmp");
					if(i==5 && j==4) iShowBMP(500,380,"green.bmp");
					if(i==6 && j==4) iShowBMP(500,315,"green.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"green.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"green.bmp");
	
					if(i==1 && j==5) iShowBMP(565,640,"green.bmp");
					if(i==2 && j==5) iShowBMP(565,575,"green.bmp"); 
					if(i==5 && j==5) iShowBMP(565,380,"green.bmp");
					if(i==8 && j==5) iShowBMP(565,185,"green.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"green.bmp");

					if(i==2 && j==6) iShowBMP(630,575,"green.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"green.bmp");
					if(i==4 && j==6) iShowBMP(630,445,"green.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"green.bmp");
					if(i==9 && j==6) iShowBMP(630,120,"green.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"green.bmp");
					if(i==2 && j==7) iShowBMP(695,575,"green.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"green.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"green.bmp");
					if(i==7 && j==7) iShowBMP(695,250,"green.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"green.bmp");
 
					if(i==2 && j==8) iShowBMP(760,575,"green.bmp");
					if(i==3 && j==8) iShowBMP(760,510,"green.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"green.bmp");
					if(i==6 && j==8) iShowBMP(760,315,"green.bmp");
					if(i==7 && j==8) iShowBMP(760,250,"green.bmp");
					if(i==8 && j==8) iShowBMP(760,185,"green.bmp");

					if(i==1 && j==9) iShowBMP(825,640,"green.bmp");
					if(i==3 && j==9) iShowBMP(825,510,"green.bmp");
					if(i==5 && j==9) iShowBMP(825,380,"green.bmp");
					if(i==6 && j==9) iShowBMP(825,315,"green.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"green.bmp");
					if(i==8 && j==9) iShowBMP(825,185,"green.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"green.bmp");

				}
				else if(stage_sol_4[i][j]!=stage4_values[i][j])
				{
					checkallryt=1;

					if(i==1 && j==1) iShowBMP(305,640,"red.bmp");
					if(i==2 && j==1) iShowBMP(305,575,"red.bmp");
					if(i==3 && j==1) iShowBMP(305,510,"red.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"red.bmp");
					if(i==5 && j==1) iShowBMP(305,380,"red.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"red.bmp");
					if(i==9 && j==1) iShowBMP(305,120,"red.bmp");

					if(i==2 && j==2) iShowBMP(370,575,"red.bmp");
					if(i==3 && j==2) iShowBMP(370,510,"red.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"red.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"red.bmp");
					if(i==7 && j==2) iShowBMP(370,250,"red.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"red.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"red.bmp");
					if(i==3 && j==3) iShowBMP(435,510,"red.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"red.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"red.bmp");
					if(i==8 && j==3) iShowBMP(435,186,"red.bmp");
					if(i==9 && j==3) iShowBMP(435,120,"red.bmp");

					if(i==1 && j==4) iShowBMP(500,640,"red.bmp");
					if(i==3 && j==4) iShowBMP(500,510,"red.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"red.bmp");
					if(i==5 && j==4) iShowBMP(500,380,"red.bmp");
					if(i==6 && j==4) iShowBMP(500,315,"red.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"red.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"red.bmp");
	
					if(i==1 && j==5) iShowBMP(565,640,"red.bmp");
					if(i==2 && j==5) iShowBMP(565,575,"red.bmp"); 
					if(i==5 && j==5) iShowBMP(565,380,"red.bmp");
					if(i==8 && j==5) iShowBMP(565,185,"red.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"red.bmp");

					if(i==2 && j==6) iShowBMP(630,575,"red.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"red.bmp");
					if(i==4 && j==6) iShowBMP(630,445,"red.bmp");
					if(i==7 && j==6) iShowBMP(630,250,"red.bmp");
					if(i==9 && j==6) iShowBMP(630,120,"red.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"red.bmp");
					if(i==2 && j==7) iShowBMP(695,575,"red.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"red.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"red.bmp");
					if(i==7 && j==7) iShowBMP(695,250,"red.bmp");
					if(i==9 && j==7) iShowBMP(695,120,"red.bmp");
 
					if(i==2 && j==8) iShowBMP(760,575,"red.bmp");
					if(i==3 && j==8) iShowBMP(760,510,"red.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"red.bmp");
					if(i==6 && j==8) iShowBMP(760,315,"red.bmp");
					if(i==7 && j==8) iShowBMP(760,250,"red.bmp");
					if(i==8 && j==8) iShowBMP(760,185,"red.bmp");

					if(i==1 && j==9) iShowBMP(825,640,"red.bmp");
					if(i==3 && j==9) iShowBMP(825,510,"red.bmp");
					if(i==5 && j==9) iShowBMP(825,380,"red.bmp");
					if(i==6 && j==9) iShowBMP(825,315,"red.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"red.bmp");
					if(i==8 && j==9) iShowBMP(825,185,"red.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"red.bmp");
				}
			}
		}
	}

}


void stage_3()
{
	// 1st column

	if(f11==1) iShowBMP(300,600,"typedone.bmp");
	else if(f11==2) iShowBMP(300,600,"typedtwo.bmp");
	else if(f11==3) iShowBMP(300,600,"typedthree.bmp");
	else if(f11==4) iShowBMP(300,600,"typedfour.bmp");
	else if(f11==5) iShowBMP(300,600,"typedfive.bmp");
	else if(f11==6) iShowBMP(300,600,"typedsix.bmp");
	else if(f11==7) iShowBMP(300,600,"typedseven.bmp");
	else if(f11==8) iShowBMP(300,600,"typedeight.bmp");
	else if(f11==9) iShowBMP(300,600,"typednine.bmp");
	else iShowBMP(300,600,"grid.bmp");
    if(flagmouse==11) iShowBMP(350,648,"mark.bmp");
    
    iShowBMP(300,535,"one.bmp");
    
	if(f13==1) iShowBMP(300,470,"typedone.bmp");
	else if(f13==2) {iShowBMP(300,470,"typedtwo.bmp");}
	else if(f13==3) iShowBMP(300,470,"typedthree.bmp");
	else if(f13==4) iShowBMP(300,470,"typedfour.bmp");
	else if(f13==5) iShowBMP(300,470,"typedfive.bmp");
	else if(f13==6) iShowBMP(300,470,"typedsix.bmp");
	else if(f13==7) iShowBMP(300,470,"typedseven.bmp");
	else if(f13==8) iShowBMP(300,470,"typedeight.bmp");
	else if(f13==9) iShowBMP(300,470,"typednine.bmp");
	else iShowBMP(300,470,"grid.bmp");
    if(flagmouse==13) iShowBMP(350,518,"mark.bmp");
    
    if(f14==1) iShowBMP(300,405,"typedone.bmp");
	else if(f14==2) {iShowBMP(300,405,"typedtwo.bmp");}
	else if(f14==3) iShowBMP(300,405,"typedthree.bmp");
	else if(f14==4) iShowBMP(300,405,"typedfour.bmp");
	else if(f14==5) iShowBMP(300,405,"typedfive.bmp");
	else if(f14==6) iShowBMP(300,405,"typedsix.bmp");
	else if(f14==7) iShowBMP(300,405,"typedseven.bmp");
	else if(f14==8) iShowBMP(300,405,"typedeight.bmp");
	else if(f14==9) iShowBMP(300,405,"typednine.bmp");
	else iShowBMP(300,405,"grid.bmp");
    if(flagmouse==14) iShowBMP(350,453,"mark.bmp");
    
	if(f15==1) iShowBMP(300,340,"typedone.bmp");
	else if(f15==2) {iShowBMP(300,340,"typedtwo.bmp");}
	else if(f15==3) iShowBMP(300,340,"typedthree.bmp");
	else if(f15==4) iShowBMP(300,340,"typedfour.bmp");
	else if(f15==5) iShowBMP(300,340,"typedfive.bmp");
	else if(f15==6) iShowBMP(300,340,"typedsix.bmp");
	else if(f15==7) iShowBMP(300,340,"typedseven.bmp");
	else if(f15==8) iShowBMP(300,340,"typedeight.bmp");
	else if(f15==9) iShowBMP(300,340,"typednine.bmp");
	else iShowBMP(300,340,"grid.bmp");
    if(flagmouse==15) iShowBMP(350,388,"mark.bmp");
    
    if(f16==1) iShowBMP(300,275,"typedone.bmp");
	else if(f16==2) {iShowBMP(300,275,"typedtwo.bmp");}
	else if(f16==3) iShowBMP(300,275,"typedthree.bmp");
	else if(f16==4) iShowBMP(300,275,"typedfour.bmp");
	else if(f16==5) iShowBMP(300,275,"typedfive.bmp");
	else if(f16==6) iShowBMP(300,275,"typedsix.bmp");
	else if(f16==7) iShowBMP(300,275,"typedseven.bmp");
	else if(f16==8) iShowBMP(300,275,"typedeight.bmp");
	else if(f16==9) iShowBMP(300,275,"typednine.bmp");
	else iShowBMP(300,275,"grid.bmp");
    if(flagmouse==16) iShowBMP(350,322,"mark.bmp");

	if(f17==1) iShowBMP(300,210,"typedone.bmp");
	else if(f17==2) {iShowBMP(300,210,"typedtwo.bmp");}
	else if(f17==3) iShowBMP(300,210,"typedthree.bmp");
	else if(f17==4) iShowBMP(300,210,"typedfour.bmp");
	else if(f17==5) iShowBMP(300,210,"typedfive.bmp");
	else if(f17==6) iShowBMP(300,210,"typedsix.bmp");
	else if(f17==7) iShowBMP(300,210,"typedseven.bmp");
	else if(f17==8) iShowBMP(300,210,"typedeight.bmp");
	else if(f17==9) iShowBMP(300,210,"typednine.bmp");
	else iShowBMP(300,210,"grid.bmp");
	if(flagmouse==17) iShowBMP(350,256,"mark.bmp");
	

	if(f18==1) iShowBMP(300,145,"typedone.bmp");
	else if(f18==2) {iShowBMP(300,145,"typedtwo.bmp");}
	else if(f18==3) iShowBMP(300,145,"typedthree.bmp");
	else if(f18==4) iShowBMP(300,145,"typedfour.bmp");
	else if(f18==5) iShowBMP(300,145,"typedfive.bmp");
	else if(f18==6) iShowBMP(300,145,"typedsix.bmp");
	else if(f18==7) iShowBMP(300,145,"typedseven.bmp");
	else if(f18==8) iShowBMP(300,145,"typedeight.bmp");
	else if(f18==9) iShowBMP(300,145,"typednine.bmp");
	else iShowBMP(300,145,"grid.bmp");
	if(flagmouse==18) iShowBMP(350,194,"mark.bmp");
	
	if(f19==1) iShowBMP(300,80,"typedone.bmp");
	else if(f19==2) {iShowBMP(300,80,"typedtwo.bmp");}
	else if(f19==3) iShowBMP(300,80,"typedthree.bmp");
	else if(f19==4) iShowBMP(300,80,"typedfour.bmp");
	else if(f19==5) iShowBMP(300,80,"typedfive.bmp");
	else if(f19==6) iShowBMP(300,80,"typedsix.bmp");
	else if(f19==7) iShowBMP(300,80,"typedseven.bmp");
	else if(f19==8) iShowBMP(300,80,"typedeight.bmp");
	else if(f19==9) iShowBMP(300,80,"typednine.bmp");
	else iShowBMP(300,80,"grid.bmp");
	if(flagmouse==19) iShowBMP(350,128,"mark.bmp");

	// second column

	if(f21==1) iShowBMP(365,600,"typedone.bmp");
	else if(f21==2) iShowBMP(365,600,"typedtwo.bmp");
	else if(f21==3) iShowBMP(365,600,"typedthree.bmp");
	else if(f21==4) iShowBMP(365,600,"typedfour.bmp");
	else if(f21==5) iShowBMP(365,600,"typedfive.bmp");
	else if(f21==6) iShowBMP(365,600,"typedsix.bmp");
	else if(f21==7) iShowBMP(365,600,"typedseven.bmp");
	else if(f21==8) iShowBMP(365,600,"typedeight.bmp");
	else if(f21==9) iShowBMP(365,600,"typednine.bmp");
	else iShowBMP(365,600,"grid.bmp");
	if(flagmouse==21) iShowBMP(415,645,"mark.bmp");

	if(f22==1) iShowBMP(365,535,"typedone.bmp");
	else if(f22==2) iShowBMP(365,535,"typedtwo.bmp");
	else if(f22==3) iShowBMP(365,535,"typedthree.bmp");
	else if(f22==4) iShowBMP(365,535,"typedfour.bmp");
	else if(f22==5) iShowBMP(365,535,"typedfive.bmp");
	else if(f22==6) iShowBMP(365,535,"typedsix.bmp");
	else if(f22==7) iShowBMP(365,535,"typedseven.bmp");
	else if(f22==8) iShowBMP(365,535,"typedeight.bmp");
	else if(f22==9) iShowBMP(365,535,"typednine.bmp");
	else iShowBMP(365,535,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==22) iShowBMP(415,584,"mark.bmp");

	if(f23==1) iShowBMP(365,470,"typedone.bmp");
	else if(f23==2) iShowBMP(365,470,"typedtwo.bmp");
	else if(f23==3) iShowBMP(365,470,"typedthree.bmp");
	else if(f23==4) iShowBMP(365,470,"typedfour.bmp");
	else if(f23==5) iShowBMP(365,470,"typedfive.bmp");
	else if(f23==6) iShowBMP(365,470,"typedsix.bmp");
	else if(f23==7) iShowBMP(365,470,"typedseven.bmp");
	else if(f23==8) iShowBMP(365,470,"typedeight.bmp");
	else if(f23==9) iShowBMP(365,470,"typednine.bmp");
	else iShowBMP(365,470,"grid.bmp");//iShowBMP(365,535,"grid.bmp");
	if(flagmouse==23) iShowBMP(415,517,"mark.bmp");

	if(f24==1) iShowBMP(365,405,"typedone.bmp");
	else if(f24==2) iShowBMP(365,405,"typedtwo.bmp");
	else if(f24==3) iShowBMP(365,405,"typedthree.bmp");
	else if(f24==4) iShowBMP(365,405,"typedfour.bmp");
	else if(f24==5) iShowBMP(365,405,"typedfive.bmp");
	else if(f24==6) iShowBMP(365,405,"typedsix.bmp");
	else if(f24==7) iShowBMP(365,405,"typedseven.bmp");
	else if(f24==8) iShowBMP(365,405,"typedeight.bmp");
	else if(f24==9) iShowBMP(365,405,"typednine.bmp");
	else iShowBMP(365,405,"grid.bmp");//iShowBMP(365,405,"grid.bmp");
	if(flagmouse==24) iShowBMP(415,452,"mark.bmp");


	if(f25==1) iShowBMP(365,340,"typedone.bmp");
	else if(f25==2) iShowBMP(365,340,"typedtwo.bmp");
	else if(f25==3) iShowBMP(365,340,"typedthree.bmp");
	else if(f25==4) iShowBMP(365,340,"typedfour.bmp");
	else if(f25==5) iShowBMP(365,340,"typedfive.bmp");
	else if(f25==6) iShowBMP(365,340,"typedsix.bmp");
	else if(f25==7) iShowBMP(365,340,"typedseven.bmp");
	else if(f25==8) iShowBMP(365,340,"typedeight.bmp");
	else if(f25==9) iShowBMP(365,340,"typednine.bmp");
	else iShowBMP(365,340,"grid.bmp");//iShowBMP(365,340,"grid.bmp");
	if(flagmouse==25) iShowBMP(415,388,"mark.bmp");

	if(f26==1) iShowBMP(365,275,"typedone.bmp");
	else if(f26==2) iShowBMP(365,275,"typedtwo.bmp");
	else if(f26==3) iShowBMP(365,275,"typedthree.bmp");
	else if(f26==4) iShowBMP(365,275,"typedfour.bmp");
	else if(f26==5) iShowBMP(365,275,"typedfive.bmp");
	else if(f26==6) iShowBMP(365,275,"typedsix.bmp");
	else if(f26==7) iShowBMP(365,275,"typedseven.bmp");
	else if(f26==8) iShowBMP(365,275,"typedeight.bmp");
	else if(f26==9) iShowBMP(365,275,"typednine.bmp");
	else iShowBMP(365,275,"grid.bmp");//iShowBMP(365,275,"grid.bmp");
	if(flagmouse==26) iShowBMP(415,323,"mark.bmp");

	if(f27==1) iShowBMP(365,210,"typedone.bmp");
	else if(f27==2) iShowBMP(365,210,"typedtwo.bmp");
	else if(f27==3) iShowBMP(365,210,"typedthree.bmp");
	else if(f27==4) iShowBMP(365,210,"typedfour.bmp");
	else if(f27==5) iShowBMP(365,210,"typedfive.bmp");
	else if(f27==6) iShowBMP(365,210,"typedsix.bmp");
	else if(f27==7) iShowBMP(365,210,"typedseven.bmp");
	else if(f27==8) iShowBMP(365,210,"typedeight.bmp");
	else if(f27==9) iShowBMP(365,210,"typednine.bmp");
	else iShowBMP(365,210,"grid.bmp");//iShowBMP(365,275,"grid.bmp");
	if(flagmouse==27) iShowBMP(415,257,"mark.bmp");

	if(f28==1) iShowBMP(365,145,"typedone.bmp");
	else if(f28==2) iShowBMP(365,145,"typedtwo.bmp");
	else if(f28==3) iShowBMP(365,145,"typedthree.bmp");
	else if(f28==4) iShowBMP(365,145,"typedfour.bmp");
	else if(f28==5) iShowBMP(365,145,"typedfive.bmp");
	else if(f28==6) iShowBMP(365,145,"typedsix.bmp");
	else if(f28==7) iShowBMP(365,145,"typedseven.bmp");
	else if(f28==8) iShowBMP(365,145,"typedeight.bmp");
	else if(f28==9) iShowBMP(365,145,"typednine.bmp");
	else iShowBMP(365,145,"grid.bmp");//iShowBMP(365,145,"grid.bmp");
	if(flagmouse==28) iShowBMP(415,193,"mark.bmp");


	iShowBMP(365,80,"four.bmp");


	// 3rd column
	if(f31==1) iShowBMP(430,600,"typedone.bmp");
	else if(f31==2) iShowBMP(430,600,"typedtwo.bmp");
	else if(f31==3) iShowBMP(430,600,"typedthree.bmp");
	else if(f31==4) iShowBMP(430,600,"typedfour.bmp");
	else if(f31==5) iShowBMP(430,600,"typedfive.bmp");
	else if(f31==6) iShowBMP(430,600,"typedsix.bmp");
	else if(f31==7) iShowBMP(430,600,"typedseven.bmp");
	else if(f31==8) iShowBMP(430,600,"typedeight.bmp");
	else if(f31==9) iShowBMP(430,600,"typednine.bmp");
	else iShowBMP(430,600,"grid.bmp");//iShowBMP(430,600,"grid.bmp");
	if(flagmouse==31) iShowBMP(478,648,"mark.bmp");

	if(f32==1) iShowBMP(430,535,"typedone.bmp");
	else if(f32==2) iShowBMP(430,535,"typedtwo.bmp");
	else if(f32==3) iShowBMP(430,535,"typedthree.bmp");
	else if(f32==4) iShowBMP(430,535,"typedfour.bmp");
	else if(f32==5) iShowBMP(430,535,"typedfive.bmp");
	else if(f32==6) iShowBMP(430,535,"typedsix.bmp");
	else if(f32==7) iShowBMP(430,535,"typedseven.bmp");
	else if(f32==8) iShowBMP(430,535,"typedeight.bmp");
	else if(f32==9) iShowBMP(430,535,"typednine.bmp");
	else iShowBMP(430,535,"grid.bmp");//iShowBMP(430,535,"grid.bmp");
	if(flagmouse==32) iShowBMP(478,583,"mark.bmp");

	if(f33==1) iShowBMP(430,470,"typedone.bmp");
	else if(f33==2) iShowBMP(430,470,"typedtwo.bmp");
	else if(f33==3) iShowBMP(430,470,"typedthree.bmp");
	else if(f33==4) iShowBMP(430,470,"typedfour.bmp");
	else if(f33==5) iShowBMP(430,470,"typedfive.bmp");
	else if(f33==6) iShowBMP(430,470,"typedsix.bmp");
	else if(f33==7) iShowBMP(430,470,"typedseven.bmp");
	else if(f33==8) iShowBMP(430,470,"typedeight.bmp");
	else if(f33==9) iShowBMP(430,470,"typednine.bmp");
	else iShowBMP(430,470,"grid.bmp");//iShowBMP(430,535,"grid.bmp");
	if(flagmouse==33) iShowBMP(478,516,"mark.bmp");

	if(f34==1) iShowBMP(430,405,"typedone.bmp");
	else if(f34==2) iShowBMP(430,405,"typedtwo.bmp");
	else if(f34==3) iShowBMP(430,405,"typedthree.bmp");
	else if(f34==4) iShowBMP(430,405,"typedfour.bmp");
	else if(f34==5) iShowBMP(430,405,"typedfive.bmp");
	else if(f34==6) iShowBMP(430,405,"typedsix.bmp");
	else if(f34==7) iShowBMP(430,405,"typedseven.bmp");
	else if(f34==8) iShowBMP(430,405,"typedeight.bmp");
	else if(f34==9) iShowBMP(430,405,"typednine.bmp");
	else iShowBMP(430,405,"grid.bmp");//iShowBMP(430,405,"grid.bmp");
	if(flagmouse==34) iShowBMP(478,451,"mark.bmp");

	if(f35==1) iShowBMP(430,340,"typedone.bmp");
	else if(f35==2) iShowBMP(430,340,"typedtwo.bmp");
	else if(f35==3) iShowBMP(430,340,"typedthree.bmp");
	else if(f35==4) iShowBMP(430,340,"typedfour.bmp");
	else if(f35==5) iShowBMP(430,340,"typedfive.bmp");
	else if(f35==6) iShowBMP(430,340,"typedsix.bmp");
	else if(f35==7) iShowBMP(430,340,"typedseven.bmp");
	else if(f35==8) iShowBMP(430,340,"typedeight.bmp");
	else if(f35==9) iShowBMP(430,340,"typednine.bmp");
	else iShowBMP(430,340,"grid.bmp");//iShowBMP(430,340,"grid.bmp");
	if(flagmouse==35) iShowBMP(478,388,"mark.bmp");

	if(f36==1) iShowBMP(430,275,"typedone.bmp");
	else if(f36==2) iShowBMP(430,275,"typedtwo.bmp");
	else if(f36==3) iShowBMP(430,275,"typedthree.bmp");
	else if(f36==4) iShowBMP(430,275,"typedfour.bmp");
	else if(f36==5) iShowBMP(430,275,"typedfive.bmp");
	else if(f36==6) iShowBMP(430,275,"typedsix.bmp");
	else if(f36==7) iShowBMP(430,275,"typedseven.bmp");
	else if(f36==8) iShowBMP(430,275,"typedeight.bmp");
	else if(f36==9) iShowBMP(430,275,"typednine.bmp");
	else iShowBMP(430,275,"grid.bmp");//iShowBMP(430,275,"grid.bmp");
	if(flagmouse==36) iShowBMP(478,323,"mark.bmp");

	if(f37==1) iShowBMP(430,210,"typedone.bmp");
	else if(f37==2) iShowBMP(430,210,"typedtwo.bmp");
	else if(f37==3) iShowBMP(430,210,"typedthree.bmp");
	else if(f37==4) iShowBMP(430,210,"typedfour.bmp");
	else if(f37==5) iShowBMP(430,210,"typedfive.bmp");
	else if(f37==6) iShowBMP(430,210,"typedsix.bmp");
	else if(f37==7) iShowBMP(430,210,"typedseven.bmp");
	else if(f37==8) iShowBMP(430,210,"typedeight.bmp");
	else if(f37==9) iShowBMP(430,210,"typednine.bmp");
	else iShowBMP(430,210,"grid.bmp");//iShowBMP(430,210,"grid.bmp");
	if(flagmouse==37) iShowBMP(478,256,"mark.bmp");

	iShowBMP(430,145,"two.bmp");

	if(f39==1) iShowBMP(430,80,"typedone.bmp");
	else if(f39==2) iShowBMP(430,80,"typedtwo.bmp");
	else if(f39==3) iShowBMP(430,80,"typedthree.bmp");
	else if(f39==4) iShowBMP(430,80,"typedfour.bmp");
	else if(f39==5) iShowBMP(430,80,"typedfive.bmp");
	else if(f39==6) iShowBMP(430,80,"typedsix.bmp");
	else if(f39==7) iShowBMP(430,80,"typedseven.bmp");
	else if(f39==8) iShowBMP(430,80,"typedeight.bmp");
	else if(f39==9) iShowBMP(430,80,"typednine.bmp");
	else iShowBMP(430,80,"grid.bmp");//iShowBMP(430,80,"grid.bmp");
	if(flagmouse==39) iShowBMP(478,128,"mark.bmp");

	// 4th column

	iShowBMP(495,600,"seven.bmp");
	
	if(f42==1) iShowBMP(495,535,"typedone.bmp");
	else if(f42==2) iShowBMP(495,535,"typedtwo.bmp");
	else if(f42==3) iShowBMP(495,535,"typedthree.bmp");
	else if(f42==4) iShowBMP(495,535,"typedfour.bmp");
	else if(f42==5) iShowBMP(495,535,"typedfive.bmp");
	else if(f42==6) iShowBMP(495,535,"typedsix.bmp");
	else if(f42==7) iShowBMP(495,535,"typedseven.bmp");
	else if(f42==8) iShowBMP(495,535,"typedeight.bmp");
	else if(f42==9) iShowBMP(495,535,"typednine.bmp");
	else iShowBMP(495,535,"grid.bmp");
	if(flagmouse==42) iShowBMP(545,582,"mark.bmp");


	iShowBMP(495,470,"four.bmp");

	if(f44==1) iShowBMP(495,405,"typedone.bmp");
	else if(f44==2) iShowBMP(495,405,"typedtwo.bmp");
	else if(f44==3) iShowBMP(495,405,"typedthree.bmp");
	else if(f44==4) iShowBMP(495,405,"typedfour.bmp");
	else if(f44==5) iShowBMP(495,405,"typedfive.bmp");
	else if(f44==6) iShowBMP(495,405,"typedsix.bmp");
	else if(f44==7) iShowBMP(495,405,"typedseven.bmp");
	else if(f44==8) iShowBMP(495,405,"typedeight.bmp");
	else if(f44==9) iShowBMP(495,405,"typednine.bmp");
	else iShowBMP(495,405,"grid.bmp");//iShowBMP(495,405,"grid.bmp");
	if(flagmouse==44) iShowBMP(545,451,"mark.bmp");

	iShowBMP(495,340,"five.bmp");

	if(f46==1) iShowBMP(495,275,"typedone.bmp");
	else if(f46==2) iShowBMP(495,275,"typedtwo.bmp");
	else if(f46==3) iShowBMP(495,275,"typedthree.bmp");
	else if(f46==4) iShowBMP(495,275,"typedfour.bmp");
	else if(f46==5) iShowBMP(495,275,"typedfive.bmp");
	else if(f46==6) iShowBMP(495,275,"typedsix.bmp");
	else if(f46==7) iShowBMP(495,275,"typedseven.bmp");
	else if(f46==8) iShowBMP(495,275,"typedeight.bmp");
	else if(f46==9) iShowBMP(495,275,"typednine.bmp");
	else iShowBMP(495,275,"grid.bmp");//iShowBMP(495,275,"grid.bmp");
	if(flagmouse==46) iShowBMP(545,323,"mark.bmp");

	if(f47==1) iShowBMP(495,210,"typedone.bmp");
	else if(f47==2) iShowBMP(495,210,"typedtwo.bmp");
	else if(f47==3) iShowBMP(495,210,"typedthree.bmp");
	else if(f47==4) iShowBMP(495,210,"typedfour.bmp");
	else if(f47==5) iShowBMP(495,210,"typedfive.bmp");
	else if(f47==6) iShowBMP(495,210,"typedsix.bmp");
	else if(f47==7) iShowBMP(495,210,"typedseven.bmp");
	else if(f47==8) iShowBMP(495,210,"typedeight.bmp");
	else if(f47==9) iShowBMP(495,210,"typednine.bmp");
	else iShowBMP(495,210,"grid.bmp");//iShowBMP(495,210,"grid.bmp");
	if(flagmouse==47) iShowBMP(545,256,"mark.bmp");

	if(f48==1) iShowBMP(495,145,"typedone.bmp");
	else if(f48==2) iShowBMP(495,145,"typedtwo.bmp");
	else if(f48==3) iShowBMP(495,145,"typedthree.bmp");
	else if(f48==4) iShowBMP(495,145,"typedfour.bmp");
	else if(f48==5) iShowBMP(495,145,"typedfive.bmp");
	else if(f48==6) iShowBMP(495,145,"typedsix.bmp");
	else if(f48==7) iShowBMP(495,145,"typedseven.bmp");
	else if(f48==8) iShowBMP(495,145,"typedeight.bmp");
	else if(f48==9) iShowBMP(495,145,"typednine.bmp");
	else iShowBMP(495,145,"grid.bmp");
	if(flagmouse==48) iShowBMP(545,193,"mark.bmp");

	if(f49==1) iShowBMP(495,80,"typedone.bmp");
	else if(f49==2) iShowBMP(495,80,"typedtwo.bmp");
	else if(f49==3) iShowBMP(495,80,"typedthree.bmp");
	else if(f49==4) iShowBMP(495,80,"typedfour.bmp");
	else if(f49==5) iShowBMP(495,80,"typedfive.bmp");
	else if(f49==6) iShowBMP(495,80,"typedsix.bmp");
	else if(f49==7) iShowBMP(495,80,"typedseven.bmp");
	else if(f49==8) iShowBMP(495,80,"typedeight.bmp");
	else if(f49==9) iShowBMP(495,80,"typednine.bmp");
	else iShowBMP(495,80,"grid.bmp");
	if(flagmouse==49) iShowBMP(545,128,"mark.bmp");

	// 5th column
	if(f51==1) iShowBMP(560,600,"typedone.bmp");
	else if(f51==2) iShowBMP(560,600,"typedtwo.bmp");
	else if(f51==3) iShowBMP(560,600,"typedthree.bmp");
	else if(f51==4) iShowBMP(560,600,"typedfour.bmp");
	else if(f51==5) iShowBMP(560,600,"typedfive.bmp");
	else if(f51==6) iShowBMP(560,600,"typedsix.bmp");
	else if(f51==7) iShowBMP(560,600,"typedseven.bmp");
	else if(f51==8) iShowBMP(560,600,"typedeight.bmp");
	else if(f51==9) iShowBMP(560,600,"typednine.bmp");
	else iShowBMP(560,600,"grid.bmp");
	if(flagmouse==51) iShowBMP(610,648,"mark.bmp");

	if(f52==1) iShowBMP(560,535,"typedone.bmp");
	else if(f52==2) iShowBMP(560,535,"typedtwo.bmp");
	else if(f52==3) iShowBMP(560,535,"typedthree.bmp");
	else if(f52==4) iShowBMP(560,535,"typedfour.bmp");
	else if(f52==5) iShowBMP(560,535,"typedfive.bmp");
	else if(f52==6) iShowBMP(560,535,"typedsix.bmp");
	else if(f52==7) iShowBMP(560,535,"typedseven.bmp");
	else if(f52==8) iShowBMP(560,535,"typedeight.bmp");
	else if(f52==9) iShowBMP(560,535,"typednine.bmp");
	else iShowBMP(560,535,"grid.bmp");
	if(flagmouse==52) iShowBMP(610,582,"mark.bmp");

	iShowBMP(560,470,"three.bmp");
	
	if(f54==1) iShowBMP(560,405,"typedone.bmp");
	else if(f54==2) iShowBMP(560,405,"typedtwo.bmp");
	else if(f54==3) iShowBMP(560,405,"typedthree.bmp");
	else if(f54==4) iShowBMP(560,405,"typedfour.bmp");
	else if(f54==5) iShowBMP(560,405,"typedfive.bmp");
	else if(f54==6) iShowBMP(560,405,"typedsix.bmp");
	else if(f54==7) iShowBMP(560,405,"typedseven.bmp");
	else if(f54==8) iShowBMP(560,405,"typedeight.bmp");
	else if(f54==9) iShowBMP(560,405,"typednine.bmp");
	else iShowBMP(560,405,"grid.bmp");
	if(flagmouse==54) iShowBMP(610,451,"mark.bmp");
	
	if(f55==1) iShowBMP(560,340,"typedone.bmp");
	else if(f55==2) iShowBMP(560,340,"typedtwo.bmp");
	else if(f55==3) iShowBMP(560,340,"typedthree.bmp");
	else if(f55==4) iShowBMP(560,340,"typedfour.bmp");
	else if(f55==5) iShowBMP(560,340,"typedfive.bmp");
	else if(f55==6) iShowBMP(560,340,"typedsix.bmp");
	else if(f55==7) iShowBMP(560,340,"typedseven.bmp");
	else if(f55==8) iShowBMP(560,340,"typedeight.bmp");
	else if(f55==9) iShowBMP(560,340,"typednine.bmp");
	else iShowBMP(560,340,"grid.bmp");//iShowBMP(560,340,"grid.bmp");
	if(flagmouse==55) iShowBMP(610,388,"mark.bmp");

	if(f56==1) iShowBMP(560,275,"typedone.bmp");
	else if(f56==2) iShowBMP(560,275,"typedtwo.bmp");
	else if(f56==3) iShowBMP(560,275,"typedthree.bmp");
	else if(f56==4) iShowBMP(560,275,"typedfour.bmp");
	else if(f56==5) iShowBMP(560,275,"typedfive.bmp");
	else if(f56==6) iShowBMP(560,275,"typedsix.bmp");
	else if(f56==7) iShowBMP(560,275,"typedseven.bmp");
	else if(f56==8) iShowBMP(560,275,"typedeight.bmp");
	else if(f56==9) iShowBMP(560,275,"typednine.bmp");
	else iShowBMP(560,275,"grid.bmp");
	if(flagmouse==56) iShowBMP(610,323,"mark.bmp");

	iShowBMP(560,210,"eight.bmp");
	
	if(f58==1) iShowBMP(560,145,"typedone.bmp");
	else if(f58==2) iShowBMP(560,145,"typedtwo.bmp");
	else if(f58==3) iShowBMP(560,145,"typedthree.bmp");
	else if(f58==4) iShowBMP(560,145,"typedfour.bmp");
	else if(f58==5) iShowBMP(560,145,"typedfive.bmp");
	else if(f58==6) iShowBMP(560,145,"typedsix.bmp");
	else if(f58==7) iShowBMP(560,145,"typedseven.bmp");
	else if(f58==8) iShowBMP(560,145,"typedeight.bmp");
	else if(f58==9) iShowBMP(560,145,"typednine.bmp");
	else iShowBMP(560,145,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==58) iShowBMP(610,191,"mark.bmp");

	if(f59==1) iShowBMP(560,80,"typedone.bmp");
	else if(f59==2) iShowBMP(560,80,"typedtwo.bmp");
	else if(f59==3) iShowBMP(560,80,"typedthree.bmp");
	else if(f59==4) iShowBMP(560,80,"typedfour.bmp");
	else if(f59==5) iShowBMP(560,80,"typedfive.bmp");
	else if(f59==6) iShowBMP(560,80,"typedsix.bmp");
	else if(f59==7) iShowBMP(560,80,"typedseven.bmp");
	else if(f59==8) iShowBMP(560,80,"typedeight.bmp");
	else if(f59==9) iShowBMP(560,80,"typednine.bmp");
	else iShowBMP(560,80,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==59) iShowBMP(610,127,"mark.bmp");


	// 6th column
	if(f61==1) iShowBMP(625,600,"typedone.bmp");
	else if(f61==2) iShowBMP(625,600,"typedtwo.bmp");
	else if(f61==3) iShowBMP(625,600,"typedthree.bmp");
	else if(f61==4) iShowBMP(625,600,"typedfour.bmp");
	else if(f61==5) iShowBMP(625,600,"typedfive.bmp");
	else if(f61==6) iShowBMP(625,600,"typedsix.bmp");
	else if(f61==7) iShowBMP(625,600,"typedseven.bmp");
	else if(f61==8) iShowBMP(625,600,"typedeight.bmp");
	else if(f61==9) iShowBMP(625,600,"typednine.bmp");
	else iShowBMP(625,600,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==61) iShowBMP(673,648,"mark.bmp");

	if(f62==1) iShowBMP(625,535,"typedone.bmp");
	else if(f62==2) iShowBMP(625,535,"typedtwo.bmp");
	else if(f62==3) iShowBMP(625,535,"typedthree.bmp");
	else if(f62==4) iShowBMP(625,535,"typedfour.bmp");
	else if(f62==5) iShowBMP(625,535,"typedfive.bmp");
	else if(f62==6) iShowBMP(625,535,"typedsix.bmp");
	else if(f62==7) iShowBMP(625,535,"typedseven.bmp");
	else if(f62==8) iShowBMP(625,535,"typedeight.bmp");
	else if(f62==9) iShowBMP(625,535,"typednine.bmp");
	else iShowBMP(625,535,"grid.bmp");//iShowBMP(560,210,"grid.bmp");
	if(flagmouse==62) iShowBMP(673,582,"mark.bmp");

	if(f63==1) iShowBMP(625,470,"typedone.bmp");
	else if(f63==2) iShowBMP(625,470,"typedtwo.bmp");
	else if(f63==3) iShowBMP(625,470,"typedthree.bmp");
	else if(f63==4) iShowBMP(625,470,"typedfour.bmp");
	else if(f63==5) iShowBMP(625,470,"typedfive.bmp");
	else if(f63==6) iShowBMP(625,470,"typedsix.bmp");
	else if(f63==7) iShowBMP(625,470,"typedseven.bmp");
	else if(f63==8) iShowBMP(625,470,"typedeight.bmp");
	else if(f63==9) iShowBMP(625,470,"typednine.bmp");
	else iShowBMP(625,470,"grid.bmp");
	if(flagmouse == 63) iShowBMP(673,518,"mark.bmp");

	if(f64==1) iShowBMP(625,405,"typedone.bmp");
	else if(f64==2) iShowBMP(625,405,"typedtwo.bmp");
	else if(f64==3) iShowBMP(625,405,"typedthree.bmp");
	else if(f64==4) iShowBMP(625,405,"typedfour.bmp");
	else if(f64==5) iShowBMP(625,405,"typedfive.bmp");
	else if(f64==6) iShowBMP(625,405,"typedsix.bmp");
	else if(f64==7) iShowBMP(625,405,"typedseven.bmp");
	else if(f64==8) iShowBMP(625,405,"typedeight.bmp");
	else if(f64==9) iShowBMP(625,405,"typednine.bmp");
	else iShowBMP(625,405,"grid.bmp");
	if(flagmouse == 64) iShowBMP(673,451,"mark.bmp");
	
	
	iShowBMP(625,340,"nine.bmp");

	if(f66==1) iShowBMP(625,275,"typedone.bmp");
	else if(f66==2) iShowBMP(625,275,"typedtwo.bmp");
	else if(f66==3) iShowBMP(625,275,"typedthree.bmp");
	else if(f66==4) iShowBMP(625,275,"typedfour.bmp");
	else if(f66==5) iShowBMP(625,275,"typedfive.bmp");
	else if(f66==6) iShowBMP(625,275,"typedsix.bmp");
	else if(f66==7) iShowBMP(625,275,"typedseven.bmp");
	else if(f66==8) iShowBMP(625,275,"typedeight.bmp");
	else if(f66==9) iShowBMP(625,275,"typednine.bmp");	
	else iShowBMP(625,275,"grid.bmp");
	if (flagmouse == 66) iShowBMP(673,323,"mark.bmp");
	
	iShowBMP(625,210,"one.bmp");

	if(f68==1) iShowBMP(625,145,"typedone.bmp");
	else if(f68==2) iShowBMP(625,145,"typedtwo.bmp");
	else if(f68==3) iShowBMP(625,145,"typedthree.bmp");
	else if(f68==4) iShowBMP(625,145,"typedfour.bmp");
	else if(f68==5) iShowBMP(625,145,"typedfive.bmp");
	else if(f68==6) iShowBMP(625,145,"typedsix.bmp");
	else if(f68==7) iShowBMP(625,145,"typedseven.bmp");
	else if(f68==8) iShowBMP(625,145,"typedeight.bmp");
	else if(f68==9) iShowBMP(625,145,"typednine.bmp");
	else iShowBMP(625,145,"grid.bmp");
	if (flagmouse == 68) iShowBMP(673,193,"mark.bmp");

	if(f69==1) iShowBMP(625,80,"typedone.bmp");
	else if(f69==2) iShowBMP(625,80,"typedtwo.bmp");
	else if(f69==3) iShowBMP(625,80,"typedthree.bmp");
	else if(f69==4) iShowBMP(625,80,"typedfour.bmp");
	else if(f69==5) iShowBMP(625,80,"typedfive.bmp");
	else if(f69==6) iShowBMP(625,80,"typedsix.bmp");
	else if(f69==7) iShowBMP(625,80,"typedseven.bmp");
	else if(f69==8) iShowBMP(625,80,"typedeight.bmp");
	else if(f69==9) iShowBMP(625,80,"typednine.bmp");
	else iShowBMP(625,80,"grid.bmp");
	if (flagmouse == 69) iShowBMP(673,128,"mark.bmp");
	
	// 7th column

	if(f71==1) iShowBMP(690,600,"typedone.bmp");
	else if(f71==2) iShowBMP(690,600,"typedtwo.bmp");
	else if(f71==3) iShowBMP(690,600,"typedthree.bmp");
	else if(f71==4) iShowBMP(690,600,"typedfour.bmp");
	else if(f71==5) iShowBMP(690,600,"typedfive.bmp");
	else if(f71==6) iShowBMP(690,600,"typedsix.bmp");
	else if(f71==7) iShowBMP(690,600,"typedseven.bmp");
	else if(f71==8) iShowBMP(690,600,"typedeight.bmp");
	else if(f71==9) iShowBMP(690,600,"typednine.bmp");
	else iShowBMP(690,600,"grid.bmp");
	if (flagmouse == 71) iShowBMP(740,648,"mark.bmp");

	if(f72==1) iShowBMP(690,535,"typedone.bmp");
	else if(f72==2) iShowBMP(690,535,"typedtwo.bmp");
	else if(f72==3) iShowBMP(690,535,"typedthree.bmp");
	else if(f72==4) iShowBMP(690,535,"typedfour.bmp");
	else if(f72==5) iShowBMP(690,535,"typedfive.bmp");
	else if(f72==6) iShowBMP(690,535,"typedsix.bmp");
	else if(f72==7) iShowBMP(690,535,"typedseven.bmp");
	else if(f72==8) iShowBMP(690,535,"typedeight.bmp");
	else if(f72==9) iShowBMP(690,535,"typednine.bmp");
	else iShowBMP(690,535,"grid.bmp");
	if(flagmouse == 72) iShowBMP(740,583,"mark.bmp");


	iShowBMP(690,470,"two.bmp");


	if(f74==1) iShowBMP(690,405,"typedone.bmp");
	else if(f74==2) iShowBMP(690,405,"typedtwo.bmp");
	else if(f74==3) iShowBMP(690,405,"typedthree.bmp");
	else if(f74==4) iShowBMP(690,405,"typedfour.bmp");
	else if(f74==5) iShowBMP(690,405,"typedfive.bmp");
	else if(f74==6) iShowBMP(690,405,"typedsix.bmp");
	else if(f74==7) iShowBMP(690,405,"typedseven.bmp");
	else if(f74==8) iShowBMP(690,405,"typedeight.bmp");
	else if(f74==9) iShowBMP(690,405,"typednine.bmp");
	else iShowBMP(690,405,"grid.bmp");
	if(flagmouse == 74) iShowBMP(740,451,"mark.bmp");
	
	if(f75==1) iShowBMP(690,340,"typedone.bmp");
	else if(f75==2) iShowBMP(690,340,"typedtwo.bmp");
	else if(f75==3) iShowBMP(690,340,"typedthree.bmp");
	else if(f75==4) iShowBMP(690,340,"typedfour.bmp");
	else if(f75==5) iShowBMP(690,340,"typedfive.bmp");
	else if(f75==6) iShowBMP(690,340,"typedsix.bmp");
	else if(f75==7) iShowBMP(690,340,"typedseven.bmp");
	else if(f75==8) iShowBMP(690,340,"typedeight.bmp");
	else if(f75==9) iShowBMP(690,340,"typednine.bmp");
	else iShowBMP(690,340,"grid.bmp");
	if(flagmouse == 75)iShowBMP(740,388,"mark.bmp");
	

	iShowBMP(690,275,"four.bmp");

	if(f77==1) iShowBMP(690,210,"typedone.bmp");
	else if(f77==2) iShowBMP(690,210,"typedtwo.bmp");
	else if(f77==3) iShowBMP(690,210,"typedthree.bmp");
	else if(f77==4) iShowBMP(690,210,"typedfour.bmp");
	else if(f77==5) iShowBMP(690,210,"typedfive.bmp");
	else if(f77==6) iShowBMP(690,210,"typedsix.bmp");
	else if(f77==7) iShowBMP(690,210,"typedseven.bmp");
	else if(f77==8) iShowBMP(690,210,"typedeight.bmp");
	else if(f77==9) iShowBMP(690,210,"typednine.bmp");
	else iShowBMP(690,210,"grid.bmp");
	if(flagmouse == 77)iShowBMP(740,257,"mark.bmp");

	if(f78==1) iShowBMP(690,145,"typedone.bmp");
	else if(f78==2) iShowBMP(690,145,"typedtwo.bmp");
	else if(f78==3) iShowBMP(690,145,"typedthree.bmp");
	else if(f78==4) iShowBMP(690,145,"typedfour.bmp");
	else if(f78==5) iShowBMP(690,145,"typedfive.bmp");
	else if(f78==6) iShowBMP(690,145,"typedsix.bmp");
	else if(f78==7) iShowBMP(690,145,"typedseven.bmp");
	else if(f78==8) iShowBMP(690,145,"typedeight.bmp");
	else if(f78==9) iShowBMP(690,145,"typednine.bmp");
	else iShowBMP(690,145,"grid.bmp");
	if(flagmouse == 78) iShowBMP(740,193,"mark.bmp");
	
	
	iShowBMP(690,80,"three.bmp");
	
	// 8th column

	if(f81==1) iShowBMP(755,600,"typedone.bmp");
	else if(f81==2) iShowBMP(755,600,"typedtwo.bmp");
	else if(f81==3) iShowBMP(755,600,"typedthree.bmp");
	else if(f81==4) iShowBMP(755,600,"typedfour.bmp");
	else if(f81==5) iShowBMP(755,600,"typedfive.bmp");
	else if(f81==6) iShowBMP(755,600,"typedsix.bmp");
	else if(f81==7) iShowBMP(755,600,"typedseven.bmp");
	else if(f81==8) iShowBMP(755,600,"typedeight.bmp");
	else if(f81==9) iShowBMP(755,600,"typednine.bmp");
	else iShowBMP(755,600,"grid.bmp");
	if (flagmouse == 81) iShowBMP(805,648,"mark.bmp");

	if(f82==1) iShowBMP(755,535,"typedone.bmp");
	else if(f82==2) iShowBMP(755,535,"typedtwo.bmp");
	else if(f82==3) iShowBMP(755,535,"typedthree.bmp");
	else if(f82==4) iShowBMP(755,535,"typedfour.bmp");
	else if(f82==5) iShowBMP(755,535,"typedfive.bmp");
	else if(f82==6) iShowBMP(755,535,"typedsix.bmp");
	else if(f82==7) iShowBMP(755,535,"typedseven.bmp");
	else if(f82==8) iShowBMP(755,535,"typedeight.bmp");
	else if(f82==9) iShowBMP(755,535,"typednine.bmp");
	else iShowBMP(755,535,"grid.bmp");
	if(flagmouse == 82) iShowBMP(805,583,"mark.bmp");

	if(f83==1) iShowBMP(755,470,"typedone.bmp");
	else if(f83==2) iShowBMP(755,470,"typedtwo.bmp");
	else if(f83==3) iShowBMP(755,470,"typedthree.bmp");
	else if(f83==4) iShowBMP(755,470,"typedfour.bmp");
	else if(f83==5) iShowBMP(755,470,"typedfive.bmp");
	else if(f83==6) iShowBMP(755,470,"typedsix.bmp");
	else if(f83==7) iShowBMP(755,470,"typedseven.bmp");
	else if(f83==8) iShowBMP(755,470,"typedeight.bmp");
	else if(f83==9) iShowBMP(755,470,"typednine.bmp");
	else iShowBMP(755,470,"grid.bmp");
	if(flagmouse == 83) iShowBMP(805,517,"mark.bmp");

	if(f84==1) iShowBMP(755,405,"typedone.bmp");
	else if(f84==2) iShowBMP(755,405,"typedtwo.bmp");
	else if(f84==3) iShowBMP(755,405,"typedthree.bmp");
	else if(f84==4) iShowBMP(755,405,"typedfour.bmp");
	else if(f84==5) iShowBMP(755,405,"typedfive.bmp");
	else if(f84==6) iShowBMP(755,405,"typedsix.bmp");
	else if(f84==7) iShowBMP(755,405,"typedseven.bmp");
	else if(f84==8) iShowBMP(755,405,"typedeight.bmp");
	else if(f84==9) iShowBMP(755,405,"typednine.bmp");
	else iShowBMP(755,405,"grid.bmp");
	if(flagmouse == 84) iShowBMP(805,451,"mark.bmp");

	if(f85==1) iShowBMP(755,340,"typedone.bmp");
	else if(f85==2) iShowBMP(755,340,"typedtwo.bmp");
	else if(f85==3) iShowBMP(755,340,"typedthree.bmp");
	else if(f85==4) iShowBMP(755,340,"typedfour.bmp");
	else if(f85==5) iShowBMP(755,340,"typedfive.bmp");
	else if(f85==6) iShowBMP(755,340,"typedsix.bmp");
	else if(f85==7) iShowBMP(755,340,"typedseven.bmp");
	else if(f85==8) iShowBMP(755,340,"typedeight.bmp");
	else if(f85==9) iShowBMP(755,340,"typednine.bmp");
	else iShowBMP(755,340,"grid.bmp");
	if(flagmouse == 85) iShowBMP(805,388,"mark.bmp");

	iShowBMP(755,275,"one.bmp");

	if(f87==1) iShowBMP(755,210,"typedone.bmp");
	else if(f87==2) iShowBMP(755,210,"typedtwo.bmp");
	else if(f87==3) iShowBMP(755,210,"typedthree.bmp");
	else if(f87==4) iShowBMP(755,210,"typedfour.bmp");
	else if(f87==5) iShowBMP(755,210,"typedfive.bmp");
	else if(f87==6) iShowBMP(755,210,"typedsix.bmp");
	else if(f87==7) iShowBMP(755,210,"typedseven.bmp");
	else if(f87==8) iShowBMP(755,210,"typedeight.bmp");
	else if(f87==9) iShowBMP(755,210,"typednine.bmp");
	else iShowBMP(755,210,"grid.bmp");
	if(flagmouse == 87) iShowBMP(805,256,"mark.bmp");


	iShowBMP(755,145,"five.bmp");

	if(f89==1) iShowBMP(755,80,"typedone.bmp");
	else if(f89==2) iShowBMP(755,80,"typedtwo.bmp");
	else if(f89==3) iShowBMP(755,80,"typedthree.bmp");
	else if(f89==4) iShowBMP(755,80,"typedfour.bmp");
	else if(f89==5) iShowBMP(755,80,"typedfive.bmp");
	else if(f89==6) iShowBMP(755,80,"typedsix.bmp");
	else if(f89==7) iShowBMP(755,80,"typedseven.bmp");
	else if(f89==8) iShowBMP(755,80,"typedeight.bmp");
	else if(f89==9) iShowBMP(755,80,"typednine.bmp");
	else iShowBMP(755,80,"grid.bmp");
	if(flagmouse == 89) iShowBMP(805,126,"mark.bmp");

	// 9th column
	if(f91==1) iShowBMP(820,600,"typedone.bmp");
	else if(f91==2) iShowBMP(820,600,"typedtwo.bmp");
	else if(f91==3) iShowBMP(820,600,"typedthree.bmp");
	else if(f91==4) iShowBMP(820,600,"typedfour.bmp");
	else if(f91==5) iShowBMP(820,600,"typedfive.bmp");
	else if(f91==6) iShowBMP(820,600,"typedsix.bmp");
	else if(f91==7) iShowBMP(820,600,"typedseven.bmp");
	else if(f91==8) iShowBMP(820,600,"typedeight.bmp");
	else if(f91==9) iShowBMP(820,600,"typednine.bmp");
	else iShowBMP(820,600,"grid.bmp");
	if(flagmouse == 91) iShowBMP(872,648,"mark.bmp");

	if(f92==1) iShowBMP(820,535,"typedone.bmp");
	else if(f92==2) iShowBMP(820,535,"typedtwo.bmp");
	else if(f92==3) iShowBMP(820,535,"typedthree.bmp");
	else if(f92==4) iShowBMP(820,535,"typedfour.bmp");
	else if(f92==5) iShowBMP(820,535,"typedfive.bmp");
	else if(f92==6) iShowBMP(820,535,"typedsix.bmp");
	else if(f92==7) iShowBMP(820,535,"typedseven.bmp");
	else if(f92==8) iShowBMP(820,535,"typedeight.bmp");
	else if(f92==9) iShowBMP(820,535,"typednine.bmp");
	else iShowBMP(820,535,"grid.bmp");
	if(flagmouse == 92) iShowBMP(872,583,"mark.bmp");
	
	if(f93==1) iShowBMP(820,470,"typedone.bmp");
	else if(f93==2) iShowBMP(820,470,"typedtwo.bmp");
	else if(f93==3) iShowBMP(820,470,"typedthree.bmp");
	else if(f93==4) iShowBMP(820,470,"typedfour.bmp");
	else if(f93==5) iShowBMP(820,470,"typedfive.bmp");
	else if(f93==6) iShowBMP(820,470,"typedsix.bmp");
	else if(f93==7) iShowBMP(820,470,"typedseven.bmp");
	else if(f93==8) iShowBMP(820,470,"typedeight.bmp");
	else if(f93==9) iShowBMP(820,470,"typednine.bmp");
	else iShowBMP(820,470,"grid.bmp");
	if(flagmouse == 93) iShowBMP(872,518,"mark.bmp");
	

	iShowBMP(820,405,"six.bmp");
	
	if(f95==1) iShowBMP(820,340,"typedone.bmp");
	else if(f95==2) iShowBMP(820,340,"typedtwo.bmp");
	else if(f95==3) iShowBMP(820,340,"typedthree.bmp");
	else if(f95==4) iShowBMP(820,340,"typedfour.bmp");
	else if(f95==5) iShowBMP(820,340,"typedfive.bmp");
	else if(f95==6) iShowBMP(820,340,"typedsix.bmp");
	else if(f95==7) iShowBMP(820,340,"typedseven.bmp");
	else if(f95==8) iShowBMP(820,340,"typedeight.bmp");
	else if(f95==9) iShowBMP(820,340,"typednine.bmp");
	else iShowBMP(820,340,"grid.bmp");
	if(flagmouse == 95) iShowBMP(872,388,"mark.bmp");
	
	iShowBMP(820,275,"eight.bmp");
	

	if(f97==1) iShowBMP(820,210,"typedone.bmp");
	else if(f97==2) iShowBMP(820,210,"typedtwo.bmp");
	else if(f97==3) iShowBMP(820,210,"typedthree.bmp");
	else if(f97==4) iShowBMP(820,210,"typedfour.bmp");
	else if(f97==5) iShowBMP(820,210,"typedfive.bmp");
	else if(f97==6) iShowBMP(820,210,"typedsix.bmp");
	else if(f97==7) iShowBMP(820,210,"typedseven.bmp");
	else if(f97==8) iShowBMP(820,210,"typedeight.bmp");
	else if(f97==9) iShowBMP(820,210,"typednine.bmp");
	else iShowBMP(820,210,"grid.bmp");
	if(flagmouse == 97) iShowBMP(872,256,"mark.bmp");
	
	if(f98==1) iShowBMP(820,145,"typedone.bmp");
	else if(f98==2) iShowBMP(820,145,"typedtwo.bmp");
	else if(f98==3) iShowBMP(820,145,"typedthree.bmp");
	else if(f98==4) iShowBMP(820,145,"typedfour.bmp");
	else if(f98==5) iShowBMP(820,145,"typedfive.bmp");
	else if(f98==6) iShowBMP(820,145,"typedsix.bmp");
	else if(f98==7) iShowBMP(820,145,"typedseven.bmp");
	else if(f98==8) iShowBMP(820,145,"typedeight.bmp");
	else if(f98==9) iShowBMP(820,145,"typednine.bmp");
	else iShowBMP(820,145,"grid.bmp");
	if(flagmouse == 98) iShowBMP(872,191,"mark.bmp");
	
	if(f99==1) iShowBMP(820,80,"typedone.bmp");
	else if(f99==2) iShowBMP(820,80,"typedtwo.bmp");
	else if(f99==3) iShowBMP(820,80,"typedthree.bmp");
	else if(f99==4) iShowBMP(820,80,"typedfour.bmp");
	else if(f99==5) iShowBMP(820,80,"typedfive.bmp");
	else if(f99==6) iShowBMP(820,80,"typedsix.bmp");
	else if(f99==7) iShowBMP(820,80,"typedseven.bmp");
	else if(f99==8) iShowBMP(820,80,"typedeight.bmp");
	else if(f99==9) iShowBMP(820,80,"typednine.bmp");
	else iShowBMP(820,80,"grid.bmp");
	if(flagmouse == 99) iShowBMP(872,128,"mark.bmp");
	
}

void soln_stage3()
{
	int i,j;
	stage_sol_3[1][1] = 2;
	stage_sol_3[1][2] = 6;
	stage_sol_3[1][3] = 4;
	stage_sol_3[1][5] = 1;
	stage_sol_3[1][6] = 5;
	stage_sol_3[1][7] = 8;
	stage_sol_3[1][8] = 3;
	stage_sol_3[1][9] = 9;

	stage_sol_3[2][2] = 3;
	stage_sol_3[2][3] = 7;
	stage_sol_3[2][4] = 8;
	stage_sol_3[2][5] = 9;
	stage_sol_3[2][6] = 2;
	stage_sol_3[2][7] = 6;
	stage_sol_3[2][8] = 4;
	stage_sol_3[2][9] = 5;

	stage_sol_3[3][1] = 5;
	stage_sol_3[3][2] = 9;
	stage_sol_3[3][3] = 8;
	stage_sol_3[3][6] = 6;
	stage_sol_3[3][8] = 7;
	stage_sol_3[3][9] = 1;
	
	stage_sol_3[4][1] = 4;
	stage_sol_3[4][2] = 2;
	stage_sol_3[4][3] = 3;
	stage_sol_3[4][4] = 1;
	stage_sol_3[4][5] = 7;
	stage_sol_3[4][6] = 8;
	stage_sol_3[4][7] = 5;
	stage_sol_3[4][8] = 9;

	stage_sol_3[5][1] = 8;
	stage_sol_3[5][2] = 1;
	stage_sol_3[5][3] = 6;
	stage_sol_3[5][5] = 4;
	stage_sol_3[5][7] = 7;
	stage_sol_3[5][8] = 2;
	stage_sol_3[5][9] = 3;

	stage_sol_3[6][1] = 7;
	stage_sol_3[6][2] = 5;
	stage_sol_3[6][3] = 9;
	stage_sol_3[6][4] = 6;
	stage_sol_3[6][5] = 2;
	stage_sol_3[6][6] = 3;

	stage_sol_3[7][1] = 3;
	stage_sol_3[7][2] = 7;
	stage_sol_3[7][3] = 5;
	stage_sol_3[7][4] = 2;
	stage_sol_3[7][7] = 9;
	stage_sol_3[7][8] = 6;
	stage_sol_3[7][9] = 4;

	stage_sol_3[8][1] = 9;
	stage_sol_3[8][2] = 8;
	stage_sol_3[8][4] = 3;
	stage_sol_3[8][5] = 6;
	stage_sol_3[8][6] = 4;
	stage_sol_3[8][7] = 1;
	stage_sol_3[8][9] = 7;

	stage_sol_3[9][1] = 6;
	stage_sol_3[9][3] = 1;
	stage_sol_3[9][4] = 9;
	stage_sol_3[9][5] = 5;
	stage_sol_3[9][6] = 7;
	stage_sol_3[9][8] = 8;
	stage_sol_3[9][9] = 2;

	if(checkflag==1)
	{
		checkallryt=0;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(stage_sol_3[i][j]==stage3_values[i][j])
				{
					if(i==1 && j==1) iShowBMP(305,640,"green.bmp");
					if(i==3 && j==1) iShowBMP(305,510,"green.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"green.bmp");
					if(i==5 && j==1) iShowBMP(305,380,"green.bmp");
					if(i==6 && j==1) iShowBMP(305,315,"green.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"green.bmp");
					if(i==8 && j==1) iShowBMP(305,185,"green.bmp");
					if(i==9 && j==1) iShowBMP(305,120,"green.bmp");


					if(i==1 && j==2) iShowBMP(370,640,"green.bmp");
					if(i==2 && j==2) iShowBMP(370,575,"green.bmp");
					if(i==3 && j==2) iShowBMP(370,510,"green.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"green.bmp");
					if(i==5 && j==2) iShowBMP(370,380,"green.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"green.bmp");
					if(i==7 && j==2) iShowBMP(370,250,"green.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"green.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"green.bmp");
					if(i==2 && j==3) iShowBMP(435,575,"green.bmp");
					if(i==3 && j==3) iShowBMP(435,510,"green.bmp");
					if(i==4 && j==3) iShowBMP(435,445,"green.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"green.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"green.bmp");
					if(i==7 && j==3) iShowBMP(435,250,"green.bmp");
					if(i==9 && j==3) iShowBMP(435,120,"green.bmp");

					if(i==2 && j==4) iShowBMP(500,575,"green.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"green.bmp");
					if(i==6 && j==4) iShowBMP(500,315,"green.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"green.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"green.bmp");
					if(i==9 && j==4) iShowBMP(500,120,"green.bmp");

					if(i==1 && j==5) iShowBMP(565,640,"green.bmp");
					if(i==2 && j==5) iShowBMP(565,575,"green.bmp"); 
					if(i==4 && j==5) iShowBMP(565,445,"green.bmp");
					if(i==5 && j==5) iShowBMP(565,380,"green.bmp");
					if(i==6 && j==5) iShowBMP(565,315,"green.bmp");
					if(i==8 && j==5) iShowBMP(565,185,"green.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"green.bmp");

					if(i==1 && j==6) iShowBMP(630,640,"green.bmp");
					if(i==2 && j==6) iShowBMP(630,575,"green.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"green.bmp");
					if(i==4 && j==6) iShowBMP(630,445,"green.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"green.bmp");
					if(i==8 && j==6) iShowBMP(630,185,"green.bmp");
					if(i==9 && j==6) iShowBMP(630,120,"green.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"green.bmp");
					if(i==2 && j==7) iShowBMP(695,575,"green.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"green.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"green.bmp");
					if(i==7 && j==7) iShowBMP(695,250,"green.bmp");
					if(i==8 && j==7) iShowBMP(695,185,"green.bmp");

					if(i==1 && j==8) iShowBMP(760,640,"green.bmp"); 
					if(i==2 && j==8) iShowBMP(760,575,"green.bmp");
					if(i==3 && j==8) iShowBMP(760,510,"green.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"green.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"green.bmp");
					if(i==7 && j==8) iShowBMP(760,250,"green.bmp");
					if(i==9 && j==8) iShowBMP(760,120,"green.bmp");

					if(i==1 && j==9) iShowBMP(825,640,"green.bmp");
					if(i==2 && j==9) iShowBMP(825,575,"green.bmp");
					if(i==3 && j==9) iShowBMP(825,510,"green.bmp");
					if(i==5 && j==9) iShowBMP(825,380,"green.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"green.bmp");
					if(i==8 && j==9) iShowBMP(825,185,"green.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"green.bmp");

				}
				else if(stage_sol_3[i][j]!=stage3_values[i][j])
				{
					checkallryt=1;

					if(i==1 && j==1) iShowBMP(305,640,"red.bmp");
					if(i==3 && j==1) iShowBMP(305,510,"red.bmp");
					if(i==4 && j==1) iShowBMP(305,445,"red.bmp");
					if(i==5 && j==1) iShowBMP(305,380,"red.bmp");
					if(i==6 && j==1) iShowBMP(305,315,"red.bmp");
					if(i==7 && j==1) iShowBMP(305,250,"red.bmp");
					if(i==8 && j==1) iShowBMP(305,185,"red.bmp");
					if(i==9 && j==1) iShowBMP(305,120,"red.bmp");


					if(i==1 && j==2) iShowBMP(370,640,"red.bmp");
					if(i==2 && j==2) iShowBMP(370,575,"red.bmp");
					if(i==3 && j==2) iShowBMP(370,510,"red.bmp");
					if(i==4 && j==2) iShowBMP(370,445,"red.bmp");
					if(i==5 && j==2) iShowBMP(370,380,"red.bmp");
					if(i==6 && j==2) iShowBMP(370,315,"red.bmp");
					if(i==7 && j==2) iShowBMP(370,250,"red.bmp");
					if(i==8 && j==2) iShowBMP(370,185,"red.bmp");

					if(i==1 && j==3) iShowBMP(435,640,"red.bmp");
					if(i==2 && j==3) iShowBMP(435,575,"red.bmp");
					if(i==3 && j==3) iShowBMP(435,510,"red.bmp");
					if(i==4 && j==3) iShowBMP(435,445,"red.bmp");
					if(i==5 && j==3) iShowBMP(435,380,"red.bmp");
					if(i==6 && j==3) iShowBMP(435,315,"red.bmp");
					if(i==7 && j==3) iShowBMP(435,250,"red.bmp");
					if(i==9 && j==3) iShowBMP(435,120,"red.bmp");

					if(i==2 && j==4) iShowBMP(500,575,"red.bmp");
					if(i==4 && j==4) iShowBMP(500,445,"red.bmp");
					if(i==6 && j==4) iShowBMP(500,315,"red.bmp");
					if(i==7 && j==4) iShowBMP(500,250,"red.bmp");
					if(i==8 && j==4) iShowBMP(500,185,"red.bmp");
					if(i==9 && j==4) iShowBMP(500,120,"red.bmp");

					if(i==1 && j==5) iShowBMP(565,640,"red.bmp");
					if(i==2 && j==5) iShowBMP(565,575,"red.bmp"); 
					if(i==4 && j==5) iShowBMP(565,445,"red.bmp");
					if(i==5 && j==5) iShowBMP(565,380,"red.bmp");
					if(i==6 && j==5) iShowBMP(565,315,"red.bmp");
					if(i==8 && j==5) iShowBMP(565,185,"red.bmp");
					if(i==9 && j==5) iShowBMP(565,120,"red.bmp");

					if(i==1 && j==6) iShowBMP(630,640,"red.bmp");
					if(i==2 && j==6) iShowBMP(630,575,"red.bmp");
					if(i==3 && j==6) iShowBMP(630,510,"red.bmp");
					if(i==4 && j==6) iShowBMP(630,445,"red.bmp");
					if(i==6 && j==6) iShowBMP(630,315,"red.bmp");
					if(i==8 && j==6) iShowBMP(630,185,"red.bmp");
					if(i==9 && j==6) iShowBMP(630,120,"red.bmp");

					if(i==1 && j==7) iShowBMP(695,640,"red.bmp");
					if(i==2 && j==7) iShowBMP(695,575,"red.bmp");
					if(i==4 && j==7) iShowBMP(695,445,"red.bmp");
					if(i==5 && j==7) iShowBMP(695,380,"red.bmp");
					if(i==7 && j==7) iShowBMP(695,250,"red.bmp");
					if(i==8 && j==7) iShowBMP(695,185,"red.bmp");

					if(i==1 && j==8) iShowBMP(760,640,"red.bmp"); 
					if(i==2 && j==8) iShowBMP(760,575,"red.bmp");
					if(i==3 && j==8) iShowBMP(760,510,"red.bmp");
					if(i==4 && j==8) iShowBMP(760,445,"red.bmp");
					if(i==5 && j==8) iShowBMP(760,380,"red.bmp");
					if(i==7 && j==8) iShowBMP(760,250,"red.bmp");
					if(i==9 && j==8) iShowBMP(760,120,"red.bmp");

					if(i==1 && j==9) iShowBMP(825,640,"red.bmp");
					if(i==2 && j==9) iShowBMP(825,575,"red.bmp");
					if(i==3 && j==9) iShowBMP(825,510,"red.bmp");
					if(i==5 && j==9) iShowBMP(825,380,"red.bmp");
					if(i==7 && j==9) iShowBMP(825,250,"red.bmp");
					if(i==8 && j==9) iShowBMP(825,185,"red.bmp");
					if(i==9 && j==9) iShowBMP(825,120,"red.bmp");
				}
			}
		}
	}

}

void drawTextBox()
{
	iSetColor(0, 250, 0);
	iRectangle(50, 100, 250, 30);
}

void leaderboard_update()
{
	iClear() ;

    FILE *fp = NULL ;

    fp = fopen( "leaderboard.txt" , "r") ;

    int i ;

   
	

    for( i = 0 ; i < 10 ; i++)
    {
        fscanf(fp , "%s %d", name[i] , &score[i]) ;
    }

    fclose( fp) ;

    for( i = 0 ; i < 10 ; i++)
    {
        printf("%s %d\n", name[i] , score[i]) ;
    }

    int congo = 0 ;

    for( i = 0 ; i < 10 ; i++)
    {
        if( score[i] < countscore )
        {
            congo = 1 ;
			bro_pos = i ;
            break ;
        }
    }
	for( i = 9 ; i > bro_pos ; i-- )
	{
		strcpy( name[i] , name[i-1] ) ;
		score[i] = score[i-1] ;
	}

	printf("congo %d \n" , congo ) ;

	if(!congo )
    {
        leaderboard_show() ;
    }
    if(congo )
    {
		update_update = 1 ;
		take_result = 1 ; 
		for( i = 9 ; i > bro_pos ; i-- )
    {
        strcpy( name[i] , name[i-1] ) ;
        score[i] = score[i-1] ;
    }
        //ekhne user tar nam dibe ebong oita save kore rakhbo :3
		//iSetColor( 0 , 0 , 255) ;
		//iShowBMP( 0 , 0 , "write_name.bmp") ;
       // take_name = 1 ;
		//printf("take_name %d \n" , take_name) ;
		//drawTextBox() ;
		//iSetColor( 0 , 255 , 0 ) ;
        //iText( 50 , 150 , "please enter your name : ") ;
	
		//iText(10, 10, "Click to activate the box, enter to finish.");
		//printf("str name:: %s\n", str) ;

    }


}

void leaderboard_update2()
{

	printf("str name:: %s\n", str2) ;
	strcpy(name[bro_pos] , str2) ;
	score[bro_pos] = countscore ;


	 FILE * fp = fopen( "leaderboard.txt" , "w") ;

    int i ;
   

    for( i = 0 ; i < 10 ; i++)
    {
        fprintf(fp , "%s %d", name[i] , score[i]) ;
    }

    fclose( fp) ;

	leaderboard_show() ;



}

void leaderboard_show()
{
    FILE *fp = NULL ;
	take_result = 0 ;
	show_result = 1 ;
	page8=1 ;
	page3 = 0 ;
page4 = 0 ;
page5 = 0 ;
page6 = 0 ;
	page7 = 0 ;
    fp = fopen( "leaderboard.txt" , "r") ;

    int i ;
    char name[10][100] ;
    int score[10] ;
    char my_name[100] ;

    for( i = 0 ; i < 10 ; i++)
    {
        fscanf(fp , "%s %d", name[i] , &score[i]) ;
    }

    fclose( fp) ;
    char score_score[10][100] ;

    for( i = 0 ; i < 10 ; i++)
    {
        sprintf (score_score[i] , "%s %d", name[i] , score[i] );
    }

    leader = 1 ;

    iSetColor( 0, 0, 0) ;

    for( i = 0 ; i < 10 ; i++)
    {
        iText(85, 458 - 32*i ,score_score[i] ,GLUT_BITMAP_TIMES_ROMAN_24 );
    }






}


void time(void)
{

	//sprintf(printscore, "%d", countscore);
	countscore-=5;
}
int main()
{
	countscore = 500 ;
	iSetTimer(30000,time);
	
	iInitialize(1350, 725, "sudoku");

	return 0;
}
