#include <windows.h>
#include <stdlib.h>

#include <gl/gl.h>
#include <gl/glut.h>

#include "game.h"

Game game = Game();

void display() {
	// Clears window and sets background color
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Origin (0,0) in upper left corner
    gluOrtho2D(0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0);
    
    game.drawObjects();
    glutSwapBuffers();
}

void special(int key, int dummy1, int dummy2) {
    game.shipControls(key);
}

void keyboard(unsigned char key, int dummy1, int dummy2) {
    game.keyboardKeys(key);
}

void update(int) {
    game.update();
    glutPostRedisplay();
    glutTimerFunc(1000 / game.fps, update, 0);
}

void initialize() {
    // Window background color
    glClearColor(game.bg.red, game.bg.green, game.bg.blue, game.bg.alpha);
    game.setup();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(game.width, game.height);
	glutCreateWindow(game.title.c_str());

    glutTimerFunc(1000 / game.fps, update, 0);

    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);

	glutDisplayFunc(display);
	initialize();
	glutMainLoop();
}

