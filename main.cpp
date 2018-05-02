#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/GL.H>

float XCam = -20.0, YCam = 20.0, ZCam = -30.0;
float Angle = 0.0;


void KeyFunc(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT: XCam += 0.5f; break;
	case GLUT_KEY_RIGHT: XCam += -0.5f; break;
	case GLUT_KEY_UP: YCam += 0.5f; break;
	case GLUT_KEY_DOWN: YCam += -0.5f; break;
	case GLUT_KEY_PAGE_UP: ZCam += 0.5f; break;
	case GLUT_KEY_PAGE_DOWN:  ZCam += -0.5f; break;

	}
}

void ShapeShift(int w, int h) {

	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}



void DrawCannon(void) {
	
	//JoinParts
	glPushMatrix();
	glColor3f(0.90, 0.91, 0.98);
	glTranslatef(4.0, +3.0, -3.25);
	glRotatef(180, 0.0, 0.0, 0.0);
	GLUquadricObj *Join = gluNewQuadric();
	gluCylinder(Join, 1.0, 1.0, 0.5, 5, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.560784, 0.560784, 0.737255);
	glTranslatef(4.0, +3.0, -3.25);
	glRotatef(180, 0.0, 0.0, 0.0);
	GLUquadricObj *Join1 = gluNewQuadric();
	gluCylinder(Join1, 1.0, 1.0, 0.5, 8, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.90, 0.91, 0.98);
	glTranslatef(4.0, +3.0, 0.0);
	glRotatef(180, 0.0, 0.0, 0.0);
	GLUquadricObj *Tampion = gluNewQuadric();
	gluCylinder(Tampion, 1.0, 1.0, 0.5, 5, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.560784, 0.560784, 0.737255);
	glTranslatef(4.0, +3.0, 0.0);
	glRotatef(180, 0.0, 0.0, 0.0);
	GLUquadricObj *Tampion1 = gluNewQuadric();
	gluCylinder(Tampion1, 1.0, 1.0, 0.5, 8, 20);
	glPopMatrix();


	//Body
	glPushMatrix();
	glColor3f(0.137255, 0.419608, 0.556863);
	glTranslatef(4.0, +3.0, -3.25);
	glRotatef(180, 0.0, 0.0, 0.0);
	GLUquadricObj *BodyBack = gluNewQuadric();
	gluCylinder(BodyBack, 0.92, 0.92, 2.75, 50, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.137255, 0.419608, 0.556863);
	glTranslatef(4.0, +3.0, 0.0);
	glRotatef(180, 0.0, 0.0, 0.0);
	GLUquadricObj *BodyFront = gluNewQuadric();
	gluCylinder(BodyFront, 0.92, 0.92, 3.25, 50, 20);
	glPopMatrix();


	//Support	
	glPushMatrix();
	glColor3f(0.35, 0.16, 0.14);
	glTranslatef(4.0, 2.5, -3.5);
	glRotatef(180, 0.0, 0.0, 0.0);
	glutSolidCube(2);
	glPopMatrix();

	//BackPart
	glPushMatrix();
	glColor3f(0.137255, 0.419608, 0.556863);
	glTranslatef(4.0, +3.0, -6.25);
	GLUquadricObj *BackPart = gluNewQuadric();
	gluSphere(BackPart, 0.92, 50, 8);
	glPopMatrix();

	//Ammo
	glPushMatrix();
	glColor3f(0.137255, 0.419608, 0.556863);
	glTranslatef(3.0, +1.0, 3.5);
	GLUquadricObj *Ammo = gluNewQuadric();
	gluSphere(Ammo, 0.92, 50, 8);
	glPopMatrix();

	//Color table//
	//#declare LightSteelBlue = color red 0.560784 green 0.560784 blue 0.737255
	//#declare Silver = color red 0.90 green 0.91 blue 0.98
	//#declare SteelBlue = color red 0.137255 green 0.419608 blue 0.556863
	//#declare Thistle = color red 0.847059 green 0.74902 blue 0.847059
	//#declare Turquoise = color red 0.678431 green 0.917647 blue 0.917647
	//#declare VeryDarkBrown = color red 0.35 green 0.16 blue 0.14
	//#declare Firebrick = color red 0.556863 green 0.137255 blue 0.137255
}


void DrawWalls() {
	glPushMatrix();
	glColor3f(0.556863, 0.137255, 0.137255);

	glTranslatef(0.0f, 0.0f, 50.0f);
	glBegin(GL_QUADS);
	glVertex3f(-30.0f, -30.0f, 0.0f);
	glVertex3f(-30.0f, 30.0f, 0.0f);
	glVertex3f(30.0f, -30.0f, 0.0f);
	glVertex3f(30.0f, 30.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void Battlefield(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(XCam, YCam, ZCam, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

		// Making the Battlefield

	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	
	DrawWalls();

		// Strengthening 

	for (int i = 0; i < 6; i++){
			glPushMatrix();
			glTranslatef(i*5.0f, 0.0f, 0.0f);
			DrawCannon();
			glPopMatrix();
		}

	
	glutSwapBuffers();

}

int main(int argc, char **argv) {

	//Windows form
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(150, 150);
	glutInitWindowSize(600, 600);
	glutCreateWindow("The Great Cannon");
	
	//Display functions
	
	
	//glutDisplayFunc(Battlefield);
	glutReshapeFunc(ShapeShift);
	glutIdleFunc(Battlefield);
	glutSpecialFunc(KeyFunc);
	

	glEnable(GL_DEPTH_TEST);
		
	glutMainLoop();
	
	return 0;
}