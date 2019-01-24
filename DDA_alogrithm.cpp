#include <GL/glut.h>
int ww = 600, wh = 400;
int first = 0;
int xi, yi, xf, yf, xt, yt;
const int ESCKEY = 27;
void drawLine(int x1, int y1, int x2, int y2)//DDA alogrithm
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
	glBegin(GL_POINTS);
	glVertex2i(x, y);
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
void display()
{
	glClearColor(1.0, 1.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		switch(first)
		{
		case 0:
				xi = x;
				yi = (wh-y);
				first = 1;
				break;
		case 1:
				xf = x;
				yf = (wh-y);
				drawLine(xi,yi,xf,yf);
				first = 2;
				break;
		case 2:
				xt = x;
				yt = (wh-y);
				drawLine(xf,yf,xt,yt);
				drawLine(xi,yi,xt,yt);
				first = 0;
				break;
		}
	}
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case ESCKEY:  // ESC: Quit
      exit(0);
      break;
   }
}


void myinit()
{
	glViewport(0,0,ww,wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww,wh);
	glutCreateWindow("demo");
	glutDisplayFunc(display);
	myinit();
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
