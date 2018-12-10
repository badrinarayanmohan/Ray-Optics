#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>
#include<dos.h>
#include<process.h>
void concm()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	int i;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
	}
	float h,u,t,a,b,c,d;
	cout<<"NOTE: Focal length= 1cm"<<endl<<endl;;
	cout<<"Enter the object distance(in cm) : ";
	cin>>u;
   cout<<endl<<"Enter the object height(in cm)(0<h<1.5) : ";
   cin>>h;
   while(h>1.5)
   {
	cout<<"Invalid Choice, 0<h<1.5";
	cout<<"\n Enter Again :";
	cin>>h;
   }
   clearviewport();
   setcolor(5);
   setbkcolor(7);
   outtextxy(250,10,"RAY DIAGRAM");
   setcolor(5);
a=h*50;
b=u*50;

setcolor(1);
//Mirror lines
i=278;
int j=80;
while(j<=220)
{
	line(82,150,i,j);
	j+=10;
	i+=2;
	if(j>150)
		i-=4;
}

setcolor(0);
i=265;
j=80;
while(j<=220)
{
	line(82,150,i,j);
	j++;
}
for(i=78;i>=0;i--)
arc(i,150,340,20,200);
//end of mirror lines

//Principal Axis
setcolor(4);
line(30,150,580,150);
i=30;
while(i<=580)
{
 line(i,146,i,154);
 i+=50;
}

outtextxy(228,156,"F");
outtextxy(178,156,"C");
outtextxy(290,156,"P");
outtextxy(328,156,"F");
outtextxy(378,156,"C");
//mirror creation
setcolor(10);
arc(80,150,340,20,200);
arc(81,150,340,20,200);
arc(82,150,340,20,200);

//Object Creation
setcolor(6);
line(280-b,150-a,280-b,150);
line(279-b,150-a,279-b,150);
line(280-b,150-a,285-b,155-a);
line(280-b,150-a,275-b,155-a);
getch();
if(u>1&&u<5)
{
setcolor(4);
//Parallel Line to P
i=280-b;
while(i<=278)
{
line(i,150-a,i,150-a);
i++;
delay(6);
}

//Reflected pass F
i=280;
while(i>=(280-b-100))
{
	t=((a)*(230-i)/50)+150;
	line(i,t,i,t);
	i--;
	delay(6);
}

//pass F
i=280-b;
while(i<=278)
{
	t=150-a+((a*i)-(280*a)+(a*b))/(b-50);
	line(i,t,i,t);
	i++;
	delay(6);
}
//parallel after reflection
i=278;
while(i>=280-b-100)
{
	t=150-a+(a*b)/(b-50);
	line(i,t,i,t);
	delay(6);
	i--;
}
//image formation
setcolor(15);
i=150;
c=280-((50*b)/(b-50));
while(i<=t)
{
	line(c,i,c,i);
	i++;
	delay(6);
}
line(c,t,c+3,t-3);
line(c,t,c-3,t-3);
}


else if(u<1)
{
setcolor(4);
//Parallel Line to P
i=280-b;
while(i<=278)
{
line(i,150-a,i,150-a);
i++;
delay(6);
}
//Reflected pass F
i=280;
while(i>=(280-b-100))
{
	t=150-a+((a*(280-i))/50);
	line(i,t,i,t);
	i--;
	delay(6);
}

//Reflected pass F dotted
i=285;
while(i<=400)
{
	t=150-a+((a*(280-i))/50);
	line(i,t,i,t);
	i+=2;
	delay(6);
}
//through C
i=280-b;
while(i<=278)
{
	t=150-a+((a*i)-(280*a)+(a*b))/(b-100);
	line(i,t,i,t);
	i++;
	delay(6);
}

i=280-b;
while(i>=280-b-100)
{
	t=150-a+((a*i)-(280*a)+(a*b))/(b-100);
	line(i,t,i,t);
	i--;
	delay(6);
}
//through c dotted
i=285;
while(i<=400)
{
	t=150-a+((a*i)-(280*a)+(a*b))/(b-100);
	line(i,t,i,t);
	i+=2;
	delay(6);
}
//image formation
setcolor(1);
t=(14000-(230*b))/(50-b);
c=(150-a+(a*(280-t))/50);
i=150;
while(i>=c)
{
	line(t,i,t,i);
	i-=2;
	delay(6);
}
line(t,c,t+4,c+4);
line(t,c,t-4,c+4);
}
else
{
	setcolor(4);
	i=0;
	while(i<=272)
	{
		line(i,100,i,100);
		i++;
		delay(6);
	}
	i=0;
	while(i<=276)
	{
		line(i,125,i,125);
		i++;
		delay(6);
	}
	i=0;
	while(i<=276)
	{
		line(i,175,i,175);
		i++;
		delay(6);
	}
	i=0;
	while(i<=272)
	{
		line(i,200,i,200);
		i++;
		delay(6);
	}

	i=280;
	while(i>=230)
	{
		t=100+(280-i);
		line(i,t,i,t);
		i--;
		delay(6);
	}
	i=280;
	while(i>=230)
	{
		t=125+(280-i)/2;
		line(i,t,i,t);
		i--;
		delay(6);
	}
	i=280;
	while(i>=230)
	{
		t=175+(i-280)/2;
		line(i,t,i,t);
		i--;
		delay(6);
	}
	i=280;
	while(i>=230)
	{
		t=200+(i-280);
		line(i,t,i,t);
		i--;
		delay(6);
	}
	setcolor(15);
	line(230,150,230,150);
	line(231,150,231,150);
	line(229,150,229,150);
}
}

void convm()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	int i;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
	}
   float h,u,t,a,b,c;
   cout<<"NOTE: Focal length= 2cm"<<endl<<endl;
   cout<<"Enter the object distance(in cm) : ";
   cin>>u;
   cout<<endl<<"Enter the object height(in cm)(0<h<1.5) : ";
   cin>>h;
   while(h>1.5)
   {
	cout<<"Invalid Choice, 0<h<1.5";
	cout<<"\n Enter Again :";
	cin>>h;
   }
   clearviewport();
   setcolor(5);
   setbkcolor(7);
   outtextxy(250,10,"RAY DIAGRAM");
   getch();

a=h*50;
b=u*50;

//Mirror Lines
i=270;
int j=78;
while(j<=230)
{
	line(480,150,i,j);
	j+=10;
	i+=2;
	if(j>150)
		i-=4;
}

setcolor(0);
i=300;
j=80;

while(j<=230)
{
	line(480,150,i,j);
	j++;
}

for(i=479;i>=0;i--)
arc(i,150,150,210,200);

for(i=490;i<=getmaxx();i++)
arc(i,150,150,210,200);
//Mirror lines end

setcolor(1);
//Principal Axis
line(30,150,580,150);
i=30;
while(i<=580)
{
 line(i,146,i,154);
 i+=50;
}
outtextxy(378,156,"F");
outtextxy(478,156,"C");
outtextxy(270,156,"P");
outtextxy(178,156,"F");
outtextxy(78,156,"C");
//mirror arc
setcolor(10);
arc(480,150,160,200,200);
arc(481,150,160,200,200);
arc(482,150,160,200,200);


//Object Creation
setcolor(6);
line(280-b,150-a,280-b,150);
line(279-b,150-a,279-b,150);
line(280-b,150-a,285-b,155-a);
line(280-b,150-a,275-b,155-a);

setcolor(4);
if(u<5)
{
//Parallel Line to P
i=280-b;
while(i<=285)
{
line(i,150-a,i,150-a);
i++;
delay(6);
}

//divergent
i=285;
while(i>=(150-a))
{
	t=150-a+((a*i)-(285*a))/100;
	line(i,t,i,t);
	i--;
	delay(6);
}

//dotted divergent
i=288;
while(i<=380)
{
	t=150-a+((a*i)-(285*a))/100;
	line(i,t,i,t);
	i+=2;
	delay(6);
}

//hitting pole
i=280-b;
while(i<=278)
{
	t=150-a+((a*i)-(280*a)+(a*b))/b;
	line(i,t,i,t);
	i++;
	delay(6);
}

//pole reflect
i=278;
while(i>=(280-b))
{
	t=150+a+((a*280)-(i*a)-(a*b))/b;
	line(i,t,i,t);
	i--;
	delay(6);
}

//pole reflect dotted
i=281;
while(i<=380)
{
	t=150+a+((a*280)-(i*a)-(a*b))/b;
	line(i,t,i,t);
	i+=2;
	delay(6);
}


//image formation
setcolor(1);
t=((380*a*b)+(28500*a))/((a*b)+(100*a));
c=150-a+((100*a*a*b)/(100*((a*b)+(100*a))));
i=150;
while(i>=c)
{
	line(t,i,t,i);
	i-=2;
	delay(6);
}
line(t,c,t-3,c+3);
line(t,c,t+3,c+3);
}
else
{
	setcolor(4);
	i=0;
	while(i<=285)
	{
		line(i,100,i,100);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,125,i,125);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,175,i,175);
		i++;
		delay(6);
	}
	i=0;
	while(i<=285)
	{
		line(i,200,i,200);
		i++;
		delay(6);
	}
	i=285;
	while(i>=150)
	{
		t=145+(i-380)/2;
		line(i,t,i,t);
		i--;
		delay(6);
	}
	i=280;
	while(i>=150)
	{
		t=148+(i-380)/4;
		line(i,t,i,t);
		i--;
		delay(6);
	}
	i=280;
	while(i>=150)
	{
		t=150+(380-i)/4;
		line(i,t,i,t);
		i--;
		delay(6);
	}
	i=285;
	while(i>=150)
	{
		t=153+(380-i)/2;
		line(i,t,i,t);
		i--;
		delay(6);
	}


	//dotted
	i=290;
	while(i<=380)
	{
		t=148+(i-380)/2;
		line(i,t,i,t);
		i+=2;
		delay(6);
	}
	i=285;
	while(i<=380)
	{
		t=149+(i-380)/4;
		line(i,t,i,t);
		i+=2;
		delay(6);
	}
	i=285;
	while(i<=380)
	{
		t=150+(380-i)/4;
		line(i,t,i,t);
		i+=2;
		delay(6);
	}
	i=290;
	while(i<=380)
	{
		t=150+(380-i)/2;
		line(i,t,i,t);
		i+=2;
		delay(6);
	}
	//image point
	setcolor(4);
	line(380,150,380,150);
	line(381,150,381,150);
	line(379,150,379,150);

}
}

void convl()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	int i;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
	}
	float h,u,t,a,b,c,d;
	cout<<"NOTE: Focal length= 2cm"<<endl<<endl;
	cout<<"Enter the object distance(in cm) : ";
	cin>>u;
	cout<<endl<<"Enter the object height(in cm)(0<h<1.5) : ";
	cin>>h;
	while(h>1.5)
	{
	cout<<"Invalid Choice, 0<h<1.5";
	cout<<"\n Enter Again :";
	cin>>h;
	}
	clearviewport();
	setcolor(5);
	setbkcolor(7);
	outtextxy(250,0,"RAY DIAGRAM");
	getch();

a=h*40;
b=u*40;

//lens creation;
setcolor(15);
arc(515,150,160,200,250);
arc(45,150,340,20,250);
setfillstyle(8,1);
floodfill(280,150,15);
line(280,150-100*sin(3.14/3),280,150+100*sin(3.14/3));

//Principal Axis
setcolor(1);
line(0,150,640,150);
i=0;
while(i<=240)
{
 line(i,146,i,154);
 i+=40;
}
i=320;
while(i<=640)
{
 line(i,146,i,154);
 i+=40;
}
setcolor(4);
outtextxy(198,156,"F");
outtextxy(358,156,"F");
outtextxy(115,156,"2F");
outtextxy(435,156,"2F");
outtextxy(280,152,"O");
getch();

if(u<7&&u>2)
{
//object creation
setcolor(6);
line(280-b,150-a,280-b,150);
line(279-b,150-a,279-b,150);
line(280-b,150-a,285-b,155-a);
line(280-b,150-a,275-b,155-a);


setcolor(4);
//parallel ray
i=280-b;
while(i<=280)
{
	t=150-a;
	line(i,t,i,t);
	i++;
	delay(6);
}
//after refraction
i=280;
while(i<=630)
{
	t=150-a+((a*i)-(280*a))/80;
	line(i,t,i,t);
	i++;
	delay(6);
}

//through O
i=280-b;
while(i<=600)
{
	t=150-a+((a*i)-(280*a)+(a*b))/b;
	line(i,t,i,t);
	i++;
	delay(6);
}
//image creation
setcolor(1);
i=150;
t=(22400-(360*b))/(80-b);
c=150-a+((a*t)-(280*a)+(a*b))/b;
while(i<=c)
{
	line(t,i,t,i);
	i++;
	delay(6);
}
line(t,c,t-4,c-2);
line(t,c,t+4,c-2);
}

else if(u<2)
{
//object creation
setcolor(6);
line(280-b,150-a,280-b,150);
line(279-b,150-a,279-b,150);
line(280-b,150-a,285-b,155-a);
line(280-b,150-a,275-b,155-a);


setcolor(4);
//parallel ray
i=280-b;
while(i<=280)
{
	t=150-a;
	line(i,t,i,t);
	i++;
	delay(6);
}

//after refraction
i=280;
while(i<=630)
{
	t=150-a+((a*i)-(280*a))/80;
	line(i,t,i,t);
	i++;
	delay(6);
}

//through O
i=280-b;
while(i<=600)
{
	t=150-a+((a*i)-(280*a)+(a*b))/b;
	line(i,t,i,t);
	i++;
	delay(6);
}
t=(22400-(360*b))/(80-b);
c=150-a+((a*t)-(280*a)+(a*b))/b;

//after refraction
i=280;
while(i>=t)
{
	d=150-a+((a*i)-(280*a))/80;
	line(i,d,i,d);
	i-=2;
	delay(6);
}

//through O
i=280-b;
while(i>=t)
{
	d=150-a+((a*i)-(280*a)+(a*b))/b;
	line(i,d,i,d);
	i-=2;
	delay(6);
}


//image creation
setcolor(15);
i=150;
while(i>=c)
{
	line(t,i,t,i);
	i-=2;
	delay(6);
}
line(t,c,t-4,c+2);
line(t,c,t+4,c+2);
}

else
{
	setcolor(4);
	i=0;
	while(i<=280)
	{
		line(i,100,i,100);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,125,i,125);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,175,i,175);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,200,i,200);
		i++;
		delay(6);
	}

	i=280;
	while(i<=360)
	{
		t=100+(5*(i-280))/8;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	i=280;
	while(i<=360)
	{
		t=125+(25*(i-280))/80;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	i=280;
	while(i<=360)
	{
		t=175+(25*(280-i))/80;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	i=280;
	while(i<=360)
	{
		t=200+(5*(280-i))/8;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	setcolor(15);
	line(360,150,360,150);
	line(361,150,361,150);
	line(359,150,359,150);
}
}

void concl()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	int i;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
	}
	float h,u,t,a,b,c,d;
	cout<<"NOTE: Focal length= 2cm"<<endl<<endl;
	cout<<"Enter the object distance(in cm) : ";
	cin>>u;
	cout<<endl<<"Enter the object height(in cm)(0<h<2) : ";
	cin>>h;
	while(h>1.5)
	{
	cout<<"Invalid Choice, 0<h<1.5";
	cout<<"\n Enter Again :";
	cin>>h;
	}
   clearviewport();
   setcolor(5);
   setbkcolor(7);
   outtextxy(250,0,"RAY DIAGRAM");
   getch();

a=h*40;
b=u*40;

//lens creation;
setcolor(15);
arc(545,150,160,200,250);
arc(15,150,340,20,250);
line(280,151-100*sin(3.14/3),280,150+100*sin(3.14/3));
line(250,151-100*sin(3.14/3),310,151-100*sin(3.14/3));
line(250,150+100*sin(3.14/3),310,150+100*sin(3.14/3));
setfillstyle(8,1);
floodfill(280,150,15);


//Principal Axis
setcolor(1);
line(0,150,640,150);
i=0;
while(i<=240)
{
 line(i,146,i,154);
 i+=40;
}
i=320;
while(i<=640)
{
 line(i,146,i,154);
 i+=40;
}
setcolor(4);
outtextxy(198,156,"F");
outtextxy(358,156,"F");
outtextxy(115,156,"2F");
outtextxy(435,156,"2F");
outtextxy(280,152,"O");
getch();

if(u>7)
{
	setcolor(4);
	i=0;
	while(i<=280)
	{
		line(i,100,i,100);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,125,i,125);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,175,i,175);
		i++;
		delay(6);
	}
	i=0;
	while(i<=280)
	{
		line(i,200,i,200);
		i++;
		delay(6);
	}

	i=280;
	while(i<=360)
	{
		t=100+(5*(280-i))/8;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	i=280;
	while(i<=360)
	{
		t=125+(25*(280-i))/80;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	i=280;
	while(i<=360)
	{
		t=175+(25*(i-280))/80;
		line(i,t,i,t);
		i++;
		delay(6);
	}
	i=280;
	while(i<=360)
	{
		t=200+(5*(i-280))/8;
		line(i,t,i,t);
		i++;
		delay(6);
	}

	i=280;
	while(i>=200)
	{
		t=100+(5*(280-i))/8;
		line(i,t,i,t);
		i-=2;
		delay(6);
	}
	i=280;
	while(i>=200)
	{
		t=125+(25*(280-i))/80;
		line(i,t,i,t);
		i-=2;
		delay(6);
	}
	i=280;
	while(i>=200)
	{
		t=175+(25*(i-280))/80;
		line(i,t,i,t);
		i-=2;
		delay(6);
	}
	i=280;
	while(i>=200)
	{
		t=200+(5*(i-280))/8;
		line(i,t,i,t);
		i-=2;
		delay(6);
	}
	setcolor(15);
	line(200,150,200,150);
	line(201,150,201,150);
	line(199,150,199,150);
}


else
{
//object creation
setcolor(6);
line(280-b,150-a,280-b,150);
line(279-b,150-a,279-b,150);
line(280-b,150-a,285-b,155-a);
line(280-b,150-a,275-b,155-a);


setcolor(4);
//parallel ray
i=280-b;
while(i<=280)
{
	t=150-a;
	line(i,t,i,t);
	i++;
	delay(6);
}
//after refraction
i=280;
while(i<=400)
{
	t=150-a+((280*a)-(a*i))/80;
	line(i,t,i,t);
	i++;
	delay(6);
}

//after refraction
i=280;
while(i>=200)
{
	t=150-a+((280*a)-(a*i))/80;
	line(i,t,i,t);
	i-=2;
	delay(6);
}

//through O
i=280-b;
while(i<=600)
{
	t=150-a+((a*i)-(280*a)+(a*b))/b;
	line(i,t,i,t);
	i++;
	delay(6);
}
//image creation
setcolor(15);
i=150;
t=(22400+(200*b))/(80+b);
c=150-a+((a*t)-(280*a)+(a*b))/b;
while(i>=c)
{
	line(t,i,t,i);
	i-=2;
	delay(6);
}
line(t,c,t-4,c+2);
line(t,c,t+4,c+2);
}

}



int main()
{
	clrscr();
	int op1;
	char ch,ch1,op;
	char ops[1];
	int i,j;
	char menu[][30]={"1.Learn about mirrors",
			 "2.Learn about lenses",
			 "3.Draw Ray Diagrams",
			 "4.Credits",
			 "5.Quit the program"};
	char smenu[][30]={"1.Concave Mirror",
			 "2.Convex Mirror",
			 "3.Convex Lens",
			 "4.Concave Lens",
			 "5.Exit this sub menu"};
	 char miro[][30]={"1. At Infinity",
			 "2. At Focus",
			 "3. Beyond C",
			 "4. Between F & C",
			 "5. At C",
			 "6. Between F & P"};
	char leno[][30]={ "1. At Infinity",
			 "2. At Focus",
			 "3. Beyond 2F",
			 "4. Between F & 2F",
			 "5. At 2F",
			 "6. Between F & O"};
	char miri[][30]={"At Focus",
			 "At Infinity",
			 "Between F & C",
			 "Beyond C",
			 "At C",
			 "Behind the mirror"};
	char leni[][30]={"At Focus",
			 "At Infinity",
			 "Between F & 2F",
			 "Beyond 2F",
			 "At 2F"};


	do
	{
		j=60;
		clrscr();
		closegraph();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");
		settextstyle(0,0,3);
		setbkcolor(4);
		outtextxy(50,10,"R a y       p t i c s");
		settextstyle(1,0,2);
	//main-menu
	for(i=0;i<5;i++)
	{
		outtextxy(220,j,menu[i]);
		j=j+20;
	}
	outtextxy(220,200,"Enter your choice : ");
	op=getche();
	ops[0]=op;
	ops[1]=NULL;
	outtextxy(370,200,ops);
	op=ops[0];
	getch();
	//options

		if(op=='1')
		{
		clearviewport();
		settextstyle(0,0,2);
		setbkcolor(15);
		setcolor(1);
		outtextxy(70,10,"Image Formation In Mirrors");
		line(70,28,480,28);
		settextstyle(1,0,2);
		setcolor(6);
		outtextxy(20,70,"Concave Mirror:");
		//tabular column
		line(20,80,130,80);
		line(0,100,640,100);
		line(0,102,640,102);
		line(0,115,640,115);
		line(0,117,640,117);
		outtextxy(20,105,"OBJECT POSITION");
		outtextxy(215,105,"IMAGE POSITION");
		outtextxy(400,105,"NATURE");
		outtextxy(550,105,"SIZE");
		line(180,102,180,300);
		line(350,102,350,300);
		line(490,102,490,300);
		line(0,300,640,300);
		j=142.5;
		for(i=0;i<5;i++)
		{
		line(0,j,640,j);
		j=j+30;
		}
		j=125;
		for(i=0;i<6;i++)
		{
		outtextxy(10,j,miro[i]);
		j=j+30;
		}
		j=125;
		for(i=0;i<6;i++)
		{
		outtextxy(185,j,miri[i]);
		j=j+30;
		}
		j=125;
		for(i=0;i<5;i++)
		{
		outtextxy(355,j,"Real & Inverted");
		j=j+30;
		}
		outtextxy(355,j,"Virtual & Erect");
		outtextxy(500,125,"Highly Diminished");
		outtextxy(500,155,"Highly Enlarged");
		outtextxy(500,185,"Diminished");
		outtextxy(500,215,"Enlarged");
		outtextxy(500,245,"Same Size");
		outtextxy(500,275,"Enlarged");

		//next table
		outtextxy(20,315,"Convex Mirror:");
		line(20,325,125,325);
		//tabular column
		line(0,340,640,340);
		line(0,342,640,342);
		line(0,355,640,355);
		line(0,357,640,357);
		outtextxy(20,345,"OBJECT POSITION");
		outtextxy(215,345,"IMAGE POSITION");
		outtextxy(400,345,"NATURE");
		outtextxy(550,345,"SIZE");
		line(180,342,180,420);
		line(350,342,350,420);
		line(490,342,490,420);
		line(0,420,640,420);
		line(0,385,640,385);
		outtextxy(10,363,"1.At Focus");
		outtextxy(10,393,"2.Between Infinity");
		outtextxy(10,406,"  & P");
		outtextxy(185,363,"Behind Mirror At F");
		outtextxy(185,393,"Behind Mirror");
		outtextxy(355,363,"Virtual & Erect");
		outtextxy(355,393,"Virtual & Erect");
		outtextxy(495,363,"Highly Diminished");
		outtextxy(495,393,"Diminished");
		outtextxy(400,460,"[Press any key to continue]");
		getch();

		}


		if(op=='2')
		{
		clearviewport();
		settextstyle(0,0,2);
		setbkcolor(15);
		setcolor(1);
		outtextxy(70,10,"Image Formation In Lenses");
		line(70,28,470,28);
		settextstyle(1,0,2);
		setcolor(6);
		outtextxy(20,70,"Convex Lens:");
		//tabular column
		line(20,80,110,80);
		line(0,100,640,100);
		line(0,102,640,102);
		line(0,115,640,115);
		line(0,117,640,117);
		outtextxy(20,105,"OBJECT POSITION");
		outtextxy(215,105,"IMAGE POSITION");
		outtextxy(400,105,"NATURE");
		outtextxy(550,105,"SIZE");
		line(180,102,180,300);
		line(350,102,350,300);
		line(490,102,490,300);
		line(0,300,640,300);
		j=142.5;
		for(i=0;i<5;i++)
		{
		line(0,j,640,j);
		j=j+30;
		}
		j=125;
		for(i=0;i<6;i++)
		{
		outtextxy(10,j,leno[i]);
		j=j+30;
		}
		j=125;
		for(i=0;i<5;i++)
		{
		outtextxy(185,j,leni[i]);
		j=j+30;
		}
		outtextxy(185,j,"Same Side As Object");
		j=125;
		for(i=0;i<5;i++)
		{
		outtextxy(355,j,"Real & Inverted");
		j=j+30;
		}
		outtextxy(355,j,"Virtual & Erect");
		outtextxy(500,125,"Highly Diminished");
		outtextxy(500,155,"Highly Enlarged");
		outtextxy(500,185,"Diminished");
		outtextxy(500,215,"Enlarged");
		outtextxy(500,245,"Same Size");
		outtextxy(500,275,"Enlarged");

		//next table
		outtextxy(20,315,"Concave Lens:");
		line(20,325,125,325);
		//tabular column
		line(0,340,640,340);
		line(0,342,640,342);
		line(0,355,640,355);
		line(0,357,640,357);
		outtextxy(20,345,"OBJECT POSITION");
		outtextxy(215,345,"IMAGE POSITION");
		outtextxy(400,345,"NATURE");
		outtextxy(550,345,"SIZE");
		line(180,342,180,380);
		line(350,342,350,380);
		line(490,342,490,380);
		line(0,380,640,380);
		outtextxy(10,363,"Any Position");
		outtextxy(185,363,"Same Side As Object");
		outtextxy(355,363,"Virtual & Erect");
		outtextxy(495,363,"Diminished");
		outtextxy(400,460,"[Press any key to continue]");
		getch();

		}


		if(op=='3')
		{
		do
		{
		clearviewport();
		//sub-menu
		j=60;
		settextstyle(0,0,2);
		setbkcolor(14);
		setcolor(4);
		outtextxy(70,10,"R a y      D ! a g r a m s");
		settextstyle(1,0,2);
		setcolor(6);
		for(i=0;i<5;i++)
		{
			outtextxy(220,j,smenu[i]);
			j=j+20;
		}
		outtextxy(220,200,"Enter your choice : ");
		op1=getche();
		ops[0]=op1;
		ops[1]=NULL;
		outtextxy(370,200,ops);
		op1=ops[0];
		getch();
		if(op1=='1')
			concm();
		else if(op1=='2')
			convm();
		else if(op1=='3')
			convl();
		else if(op1=='4')
			concl();
		else if(op1=='5')
			break;
		else
			outtextxy(230,230,"INVALID CHOICE");
		setcolor(15);
		outtextxy(20,370,"Do you want to continue drawing ray diagrams(y/n) ? :");
		ch=getche();
		ops[0]=ch;
		ops[1]=NULL;
		outtextxy(450,370,ops);
		ch=ops[0];
		getch();
	}while(ch=='y'||ch=='Y');
	}


	else if(op=='4')
	{
		clrscr();
		closegraph();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "");
		setcolor(1);
		settextstyle(0,0,2);
		setbkcolor(14);
		outtextxy(20,100,"Ray  Optics  and Optical Instruments");
		setcolor(12);
		settextstyle(0,0,2);
		outtextxy(80,230," Reflexion $tudios,Inc. ");
		settextstyle(0,0,1);
		setcolor(4);
		outtextxy(100,270,"YQ-a3, Zirconium Valley");
		outtextxy(100,290,"Tokyo, Japan");
		setcolor(2);
		outtextxy(100,310,"Programmed by:");
		outtextxy(160,330,"Rajesh Mohan");
		outtextxy(160,350,"Paramasivan.E.M");
		setcolor(4);
		outtextxy(100,370,"Contact : ");
		outtextxy(130,390,"Office : 9600097000");
		outtextxy(130,410,"Fax    :+35-9755597000");
		outtextxy(130,430,"E-m@il : queries@reflioninc.com");
		outtextxy(130,450,"Website: www.reflexioninc.co.ja");
		outtextxy(400,460,"[Press any key to continue]");
		getch();
	}


	else if(op=='5')
	{
		exit(0);
	}

	else if(op!='1'&&op!='2'&&op!='3'&&op!='4'&&op!='5')
	{
		outtextxy(230,230,"INVALID CHOICE");
		getch();
	}
	clearviewport();
	outtextxy(20,200,"Do you want to continue with the program ?(y/n) :");
	ch1=getche();
	ops[0]=ch1;
	ops[1]=NULL;
	outtextxy(470,200,ops);
	ch1=ops[0];
	getch();
	}while(ch1=='y'||ch1=='Y');
	return(0);
}