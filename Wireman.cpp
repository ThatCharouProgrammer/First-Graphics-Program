// Include the necessary libraries
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>

// current wireman position (initialised in main)
double x, y, z, angle;

void init() {

	// Set background colour
	glClearColor(9.0, 9.0, 9.0, 0.0);

	// Set foreground colour
	glColor3f(0, 0.0, 1.0);

	// Define projection transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1, 1);

	// Define viewing transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Initialise wireman variables
	x = y = z = angle = 0;
}

void render() {

	// Clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Future matrix manipulations should affect the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	/* Code to create the wire man */

	// body
	//glPushMatrix();
	glutWireCube(0.5);
	//glPopMatrix();

	// neck
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0);
	glTranslatef(0.0, 0.0, -0.35);
	glutWireCylinder(0.05, 0.1, 20, 20);
	glPopMatrix();

	// head
	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(0.52, 0.0, 0.0);
	glutWireSphere(0.18, 30, 30);
	glPopMatrix();

	// left leg
	glPushMatrix();
	glTranslatef(0.15, -0.475, 0.0);
	glScalef(0.4, 4.5, 0.4);
	glutWireCube(0.1);
	glPopMatrix();

	// right leg
	glPushMatrix();
	glTranslatef(-0.15, -0.475, 0.0);
	glScalef(0.4, 4.5, 0.4);
	glutWireCube(0.1);
	glPopMatrix();

	// left arm
	glPushMatrix();
	glRotatef(45, 0.0, 0.0, 1.0);
	glScalef(0.4, 4.4, 0.4);
	glTranslatef(0.7, -0.058, 0.0);
	glutWireCube(0.1);
	glPopMatrix();

	// right arm
	glPushMatrix();
	glRotatef(-45, 0.0, 0.0, 1.0);
	glScalef(0.4, 4.4, 0.4);
	glTranslatef(-0.7, -0.058, 0.0);
	glutWireCube(0.1);
	glPopMatrix();

	glFlush();
}

void animate(int) {
	angle = 0.45;
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, animate, 0);
}

int main(int argc, char* argv[]) {

	/* initialize GLUT, using any commandline parameters passed to the program */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

	/* setup the size, position for new windows */
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	/* create and set up a window */
	glutCreateWindow("Wireman");

	/* display wireman and execute animation */
	glutDisplayFunc(render);
	glutTimerFunc(0, animate, 0);

	/* initialisation of global constants and run all drawing instructions in the display function */
	init();

	glutMainLoop();
	return 0;
}