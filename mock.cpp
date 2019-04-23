#include <GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
struct point
{
	GLint x;
	GLint y;
};

struct Color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

Color getpixelcolor(GLint x,GLint y)
{
	Color color;
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&color);
	return color;
}
void setpixelcolor(GLint x,GLint y,Color color)
{

	glColor3f(color.r,color.g,color.b);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}
void drawpixel(int x,int y)
{
	//glPointSize(2);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}
void bre(int x1,int y1,int x2,int y2)
{
	int dx,dy,d,incx=1,incy=1,x,y,i=0;
	dx=x2-x1;
	dy=y2-y1;
	x=x1;y=y1;
	if(dx<0)dx=-dx;
	if(dy<0)dy=-dy;
	if(x2<x1)incx=-1;
	if(y2<y1)incy=-1;
	drawpixel(x,y);
	if(dx>dy)
	{

		d=2*dy-dx;
		while(i<=dx)
		{if(d<0)d=d+2*dy;
		else{d=d+2*(dy-dx);y=y+incy;}
		x=x+incx;
		drawpixel(x,y);i++;}
	}
	else
	{
		d=2*dx-dy;
		while(i<=dy){
		if(d<0)d=d+2*dx;
		else{d=d+2*(dx-dy);x=x+incx;}
		y=y+incy;
		drawpixel(x,y);i++;}
	}
}
void floodfill(GLint x,GLint y,Color old1,Color new1)
{
	Color color;
	color=getpixelcolor(x,y);
	
	if(color.r==old1.r && color.g==old1.g && color.b==old1.b )
	{
	//cout<<color.r<<' '<<color.g<<' '<<color.b<<endl;
	//cout<<'a'<<endl;
		setpixelcolor(x,y,new1);
		floodfill(x+1,y,old1,new1);
		floodfill(x-1,y,old1,new1);
		floodfill(x,y-1,old1,new1);
		floodfill(x,y+1,old1,new1);
	}
}
void mouse(int btn ,int state,GLint x,GLint y)
{
	float ang=(float)(45*3.142)/180.0;
	Color old1={0.0,0.0,0.0};
	Color new1={1.0,1.0,1.0};
	int x1,y1;
	x1=200+(200-125)*cos(ang)-(200-275)*sin(ang);
	y1=200+(200-125)*sin(ang)+(200-275)*cos(ang);
	floodfill(x1,y1,old1,new1);
	
	x1=200+(200-125)*cos(ang)-(200-175)*sin(ang);
	y1=200+(200-125)*sin(ang)+(200-175)*cos(ang);
	floodfill(x1,y1,old1,new1);
	
	x1=200+(200-275)*cos(ang)-(200-225)*sin(ang);
	y1=200+(200-275)*sin(ang)+(200-225)*cos(ang);
	floodfill(x1,y1,old1,new1);
	
	x1=200+(200-225)*cos(ang)-(200-275)*sin(ang);
	y1=200+(200-225)*sin(ang)+(200-275)*cos(ang);
	floodfill(x1,y1,old1,new1);
	
	x1=200+(200-225)*cos(ang)-(200-175)*sin(ang);
	y1=200+(200-225)*sin(ang)+(200-175)*cos(ang);
	floodfill(x1,y1,old1,new1);

	x1=200+(200-175)*cos(ang)-(200-225)*sin(ang);
	y1=200+(200-175)*sin(ang)+(200-225)*cos(ang);
	floodfill(x1,y1,old1,new1);

	x1=200+(200-175)*cos(ang)-(200-125)*sin(ang);
	y1=200+(200-175)*sin(ang)+(200-125)*cos(ang);
	floodfill(x1,y1,old1,new1);	

 	x1=200+(200-275)*cos(ang)-(200-125)*sin(ang);
	y1=200+(200-275)*sin(ang)+(200-125)*cos(ang);
	floodfill(x1,y1,old1,new1);

}
void display()
{
	float ang=(float)(45*3.142)/180.0;
	int x1,y1,x2,y2;
	x1=200+(200-100)*cos(ang)-(200-100)*sin(ang);
	y1=200+(200-100)*sin(ang)+(200-100)*cos(ang);
	
	x2=200+(200-300)*cos(ang)-(200-100)*sin(ang);
	y2=200+(200-300)*sin(ang)+(200-100)*cos(ang);
	bre(x1,y1,x2,y2);
	
//
	x1=200+(200-300)*cos(ang)-(200-100)*sin(ang);
	y1=200+(200-300)*sin(ang)+(200-100)*cos(ang);

	x2=200+(200-300)*cos(ang)-(200-300)*sin(ang);
	y2=200+(200-300)*sin(ang)+(200-300)*cos(ang);
	bre(x1,y1,x2,y2);
	
//
	x1=200+(200-300)*cos(ang)-(200-300)*sin(ang);
	y1=200+(200-300)*sin(ang)+(200-300)*cos(ang);

	x2=200+(200-100)*cos(ang)-(200-300)*sin(ang);
	y2=200+(200-100)*sin(ang)+(200-300)*cos(ang);
	bre(x1,y1,x2,y2);
	
//
	x1=200+(200-100)*cos(ang)-(200-300)*sin(ang);
	y1=200+(200-100)*sin(ang)+(200-300)*cos(ang);

	x2=200+(200-100)*cos(ang)-(200-100)*sin(ang);
	y2=200+(200-100)*sin(ang)+(200-100)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-100)*cos(ang)-(200-150)*sin(ang);
	y1=200+(200-100)*sin(ang)+(200-150)*cos(ang);

	x2=200+(200-300)*cos(ang)-(200-150)*sin(ang);
	y2=200+(200-300)*sin(ang)+(200-150)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-100)*cos(ang)-(200-200)*sin(ang);
	y1=200+(200-100)*sin(ang)+(200-200)*cos(ang);

	x2=200+(200-300)*cos(ang)-(200-200)*sin(ang);
	y2=200+(200-300)*sin(ang)+(200-200)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-100)*cos(ang)-(200-250)*sin(ang);
	y1=200+(200-100)*sin(ang)+(200-250)*cos(ang);

	x2=200+(200-300)*cos(ang)-(200-250)*sin(ang);
	y2=200+(200-300)*sin(ang)+(200-250)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-150)*cos(ang)-(200-100)*sin(ang);
	y1=200+(200-150)*sin(ang)+(200-100)*cos(ang);

	x2=200+(200-150)*cos(ang)-(200-300)*sin(ang);
	y2=200+(200-150)*sin(ang)+(200-300)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-150)*cos(ang)-(200-100)*sin(ang);
	y1=200+(200-150)*sin(ang)+(200-100)*cos(ang);

	x2=200+(200-150)*cos(ang)-(200-300)*sin(ang);
	y2=200+(200-150)*sin(ang)+(200-300)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-200)*cos(ang)-(200-100)*sin(ang);
	y1=200+(200-200)*sin(ang)+(200-100)*cos(ang);

	x2=200+(200-200)*cos(ang)-(200-300)*sin(ang);
	y2=200+(200-200)*sin(ang)+(200-300)*cos(ang);
	bre(x1,y1,x2,y2);
	
	x1=200+(200-250)*cos(ang)-(200-100)*sin(ang);
	y1=200+(200-250)*sin(ang)+(200-100)*cos(ang);

	x2=200+(200-250)*cos(ang)-(200-300)*sin(ang);
	y2=200+(200-250)*sin(ang)+(200-300)*cos(ang);
	bre(x1,y1,x2,y2);
	
	glFlush();
}

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,700,0,700);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("Chess board");
	glutDisplayFunc(display);
	init();
	//glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;

}

