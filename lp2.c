#include<stdio.h>
#include<GL/glut.h>
int x1,y1,x2,y2;
char x[10];

void convertToString(int x1,int y1){
	char x2[10],y[10],result;
	sprintf(x2,"(%d,",x1);
	sprintf(y,"%d)",y1);
	strcpy(x,x2);
	strcat(x,y);
	printf("%s",x);
}
void drawText(float x,float y,float z, char* s){
	int i;
	glRasterPos3f(x,y,z);
	for(i=0;s[i] != '\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}
void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500,500,-500,500);
}
void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void draw_line(int x1,int x2,int y1,int y2) {
	int dx,dy,i,e;
	int incx,incy,inc1,inc2;
	int x,y;
	dx= x2 - x1;
	dy= y2 - y1;
	if(dx < 0)
		dx = -dx;
	if(dy < 0)
		dy = -dy;
	incx=1;
	if(x2 < x1)
		incx = -1;
	incy = 1;
	if(y2 < y1)
		incy = -1;
	x = x1;
	y = y1;
	if(dx > dy){
		draw_pixel(x,y);
		e = 2*dy - dx;
		inc1 = 2*(dy-dx);
		inc2 = 2 * dy;
		for(i=0;i<dx;i++){
			if(e >= 0) {
				y+=incy;
				e+inc1;
			}
			else
				e+=inc2;
			x+=incx;
			draw_pixel(x,y);
		}
	}
	else {
		draw_pixel(x,y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for(i=0;i<dy;i++){
			if(e >= 0) {
				x+=incx;
				e+=inc1;
			}
			else
				e+=inc2;
			y+=incy;
			draw_pixel(x,y);
		}
	}
}
void myDisplay(){
	//glColor3f(1.0,1.0,0.0);
	draw_line(x1,x2,y1,y2);
	glColor3f(1.0,1.0,1.0);
	drawText(10,450,0,"Breshenham's Line Drawing Algorithm");
	drawText(10,400,0,"Kartik G 1BI15CS068");
	convertToString(x1,y1);
	drawText(x1,y1,0,x);
	convertToString(x2,y2);
	drawText(x2,y2,0,x);
	glFlush();
}

void myReshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	myInit();
	glutPostRedisplay();
}
int main(int argc,char** argv){
	printf("Enter the points of line(x1,y1,x2,y2)\n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1368,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham's line drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);	
	glutMainLoop();
	return 0;
}
