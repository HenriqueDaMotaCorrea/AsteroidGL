// Aluno: Henrique da Mota Corrêa

#include <windows.h>
#include <stdlib.h>

#include <gl/gl.h>
#include <gl/glut.h>

#include "game.h"

Game game = Game();

void display() {
	// Limpa a janela com a cor especificada como cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0); // Origem no canto superior esquerdo
    
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

// Inicializa aspectos do rendering
void initialize() {
    glClearColor(game.bg.red, game.bg.green, game.bg.blue, game.bg.alpha);  // Cor de fundo da janela
    game.setup();
}

// Parte principal - ponto de início de execução
// Cria janela
// Inicializa aspectos relacionados a janela e a geração da imagem
// Especifica a função de callback de desenho
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

	// Indica que deve ser usado um único buffer para armazenamento da imagem e representação de cores RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Cria uma janela com o titulo especificado
    glutInitWindowSize(game.width, game.height);
	glutCreateWindow(game.title.c_str());

    glutTimerFunc(1000 / game.fps, update, 0);

    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);

    // Especifica para a OpenGL que função deve ser chamada para geração da imagem
	glutDisplayFunc(display);

    // Executa a inicialização de parâmetros de exibção
	initialize();

    // Dispara a "máquina de estados" de OpenGL
	glutMainLoop();
}

