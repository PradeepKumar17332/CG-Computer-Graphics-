#include<GL/glut.h>
#include<GL/gl.h>
#include<bits/stdc++.h>
using namespace std;

void putpixel(int x,int y)
{
	glBegin(GL_POINTS);
		glColor3f(1.0,0.0,0.0);//point display
		glVertex2i(x,y);
	glEnd();
	glFlush();
}
void drawLine(int x1, int y1, int x2, int y2)//DDA algorithm
{
//glClear(GL_COLOR_BUFFER_BIT);
/*glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2i(x1, y1);
glVertex2i(x2, y2);
*/

	int dx, dy, step, i;
	float incx, incy, x, y;

	dx = x2-x1;
	dy = y2-y1;

	if(dx>dy)
		step=dx;
	else
		step=dy;

	incx=(float)dx/step;
	incy=(float)dy/step;

	x=x1;
	y=y1;
	x=x+0.5;
	y=y+0.5;

	putpixel(x, y);
	//draw_pixel(x,y);

	for(i=1;i<step;i++)
	{
		x=x+incx;
		y=y+incy;


		glVertex2i(x, y);

	}


	glEnd();
	glFlush();
}
void draw_circle(int r,int h,int k)//Bresenham’s circle drawing algorithm
{

	glClear(GL_COLOR_BUFFER_BIT);
	int x1=0,y1=r;
	int d;
	d=3-2*r;
	while(x1<=y1)
	{
		putpixel(x1+h, y1+k);
		putpixel(-x1+h, y1+k);
		putpixel(x1+h, -y1+k);
		putpixel(-x1+h, -y1+k);
		putpixel(y1+h, x1+k);
		putpixel(y1+h, -x1+k);
		putpixel(-y1+h, x1+k);
		putpixel(-y1+h, -x1+k);
		if(d<0)
			d=d+4*x1+6;
		else
		{
			d=d+4*(x1-y1)+10;
			y1=y1-1;
		}
		x1=x1+1;
	}

}
void Displayme()
{
	int x1,y1,x2,y2,x3,y3;
	cout<<"Enter the x and y  first co-ordinate  of triangle\n";
	cin>>x1>>y1;
	cout<<"Enter the x and y  second co-ordinate  of triangle\n";
	cin>>x2>>y2;
	cout<<"Enter the x and y  third co-ordinate  of triangle\n";
	cin>>x3>>y3;
	drawLine(x1,y1,x2,y2);
	drawLine(x2,y2,x3,y3);
	drawLine(x1,y1,x3,y3);

	int h=(x1+x2+x3)/3;
	int k=(y1+y2+y3)/3;
	int ll=sqrt(pow(x2-x1,2)+pow((y2-y1),2));
	int hh=sqrt(3)*(ll);
	draw_circle(hh/3,h,k);
	draw_circle((2*hh)/3,h,k);

}
void Init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0);
	glMatrixMode(GL_PROJECTION);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);

}
int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);//size of window
	glutInitWindowPosition(100,100);
	glutCreateWindow("Hello world");//name of the window
	Init();
	glutDisplayFunc(Displayme);
	glutMainLoop();
	return 0;

}
