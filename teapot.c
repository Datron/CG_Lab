#include<stdio.h>
#include<GL/glut.h>

GLfloat mat_ambient[] = {0.7,0.7,0.7,1.0};
GLfloat mat_diffuse[] = {0.5,0.5,0.5,1.0};
GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
GLfloat mat_shininess[] = {50.0};
GLfloat light_intensity[] = {0.7,0.7,0.7,1.0};
GLfloat light_position[] = {2.0,6.0,3.0,0.0};
void draw_text(float x,float y,float z,char *s){
    int i;
    glRasterPos3f(x,y,z);
    for(i=0;s[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
    }   
}
void init(){
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_intensity);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0,1.0,2.0,0.0,0.2,0.2,0.0,1.0,0.0);
}
void teapot(){
	glPushMatrix();
	glTranslated(0.4,0.0,0.4);
	glRotated(30,0,1,0);
	glutSolidTeapot(0.2);
	glPopMatrix();
}
void tabletop(){
	glPushMatrix();
	//glColor3f(1.0,0.0,0.0);
	glTranslated(0.0,-0.3,0.0);
	glScaled(7.0,0.5,7.0);
	glutSolidCube(0.2);
	glPopMatrix();
}
void bottomfloor(){
	glPushMatrix();
	glTranslated(0.0,-1.0,0.0);
	glScaled(10.1,0.1,10.0);
	glutSolidCube(0.2);
	glPopMatrix();
}
void rightwall(){
	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslated(0.0,0.0,-1.0);
	glScaled(10.0,10.0,0.1);
	glutSolidCube(0.2);
	glPopMatrix();
}
void leftwall(){
	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslated(-1.0,0.0,0.0);
	glScaled(0.1,10.0,10.0);
	glutSolidCube(0.2);
	glPopMatrix();
}
void backleg(){
	glPushMatrix();
	glTranslated(-0.5,-0.7,-0.5);
	glScaled(0.5,7.0,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}
void frontleg(){
	glPushMatrix();
	glTranslated(0.5,-0.7,0.5);
	glScaled(0.5,7.0,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}
void leftleg(){
	glPushMatrix();
	glTranslated(-0.5,-0.7,0.5);
	glScaled(0.5,7.0,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}
void rightleg(){
	glPushMatrix();
	glTranslated(0.5,-0.7,-0.5);
	glScaled(0.5,7.0,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(1.0,1.0,1.0,1.0);
	draw_text(-0.2,1.55,-0.5,"Shaded Scene");
    	draw_text(-0.2,1.65,-0.5," USN:1BI15CS068 , NAME:KARTIK G");
	teapot();
	tabletop();
	frontleg();
	leftleg();
	rightleg();
	backleg();
	bottomfloor();
	rightwall();
	leftwall();
	glFlush();
}
void main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(800,500);
	glutCreateWindow("Teapot");
	init();
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(1.0,1.0,1.0,0.0);
	glViewport(0,0,640,480);
	glEnable(GL_COLOR_MATERIAL);
	glutMainLoop();
}
