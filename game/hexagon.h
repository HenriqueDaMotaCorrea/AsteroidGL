#ifndef HEXAGON_H_INCLUDED
#define HEXAGON_H_INCLUDED
#include <gl/glut.h>
#include <cmath>

class Hexagon {

    private:
        float v1x, v1y, v2x, v2y, v3x, v3y, v4x, v4y, v5x, v5y, v6x, v6y;
        float cr, cg, cb;
        float posx, posy;
        float scalex, scaley;
        float angleTotal;

    public:
        //Construtores
        Hexagon() {
            v1x = 1;
            v1y = 1.5;
            v2x = -1;
            v2y = 1.5;
            v3x = -1.5;
            v3y = 0;
            v4x = -1;
            v4y = -1.5;
            v5x = 1;
            v5y = -1.5;
            v6x = 1.5;
            v6y = 0;
            cr = 1.0;
            cg = 1.0;
            cb = 1.0;
            posx = posy = 0.0;
            scalex = scaley = 1.0;
            angleTotal = 0.0;
        }

        Hexagon(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y, float p5x, float p5y, float p6x, float p6y, float r, float g, float b, float px, float py, float scx, float scy, float ang) {
            v1x = p1x;
            v1y = p1y;
            v2x = p2x;
            v2y = p2y;
            v3x = p3x;
            v3y = p3y;
            v4x = p4x;
            v4y = p4y;
            v5x = p5x;
            v5y = p5y;
            v6x = p6x;
            v6y = p6y;
            cr = r;
            cg = g;
            cb = b;
            posx = px;
            posy = py;
            scalex = scx;
            scaley = scy;
            angleTotal = ang;
        }

        //Metodo para desenhar
        void draw() {
            glColor3f(cr, cg, cb);
            glBegin(GL_LINE_LOOP);
                glVertex2f(v1x*scalex+posx, v1y*scaley+posy);
                glVertex2f(v2x*scalex+posx, v2y*scaley+posy);
                glVertex2f(v3x*scalex+posx, v3y*scaley+posy);
                glVertex2f(v4x*scalex+posx, v4y*scaley+posy);
                glVertex2f(v5x*scalex+posx, v5y*scaley+posy);
                glVertex2f(v6x*scalex+posx, v6y*scaley+posy);
            glEnd();
        }

        //Método para a posformação geométrica de rotação
        void rotate(float angle) {
            angleTotal += angle;
            if (angleTotal == 360) {
                angleTotal = 0;
            } else if (angleTotal > 360) {
                angleTotal -= 360;
            }

            angle = (angle * M_PI) / 180.0;

            float auxX = 0.0;
            float auxY = 0.0;

            auxX = v1x * cos(angle) - v1y * sin(angle);
            auxY = v1x * sin(angle) + v1y * cos(angle);
            v1x = auxX;
            v1y = auxY;

            auxX = v2x * cos(angle) - v2y * sin(angle);
            auxY = v2x * sin(angle) + v2y * cos(angle);
            v2x = auxX;
            v2y = auxY;

            auxX = v3x * cos(angle) - v3y * sin(angle);
            auxY = v3x * sin(angle) + v3y * cos(angle);
            v3x = auxX;
            v3y = auxY;

            auxX = v4x * cos(angle) - v4y * sin(angle);
            auxY = v4x * sin(angle) + v4y * cos(angle);
            v4x = auxX;
            v4y = auxY;

            auxX = v5x * cos(angle) - v5y * sin(angle);
            auxY = v5x * sin(angle) + v5y * cos(angle);
            v5x = auxX;
            v5y = auxY;

            auxX = v6x * cos(angle) - v6y * sin(angle);
            auxY = v6x * sin(angle) + v6y * cos(angle);
            v6x = auxX;
            v6y = auxY;
        }

        // Forma aleatória para geração de asteroides
        void randomizeShape() {
            v1x = 1 * (1 + (rand() % 11) / 5);
            v1y = 1.5 * (1 + (rand() % 11) / 5);
            v2x = -1 * (1 + (rand() % 11) / 5);
            v2y = 1.5 * (1 + (rand() % 11) / 5);
            v3x = -1.5 * (1 + (rand() % 11) / 5);
            v3y = 0 * (1 + (rand() % 11) / 5);
            v4x = -1 * (1 + (rand() % 11) / 5);
            v4y = -1.5 * (1 + (rand() % 11) / 5);
            v5x = 1 * (1 + (rand() % 11) / 5);
            v5y = -1.5 * (1 + (rand() % 11) / 5);
            v6x = 1.5 * (1 + (rand() % 11) / 5);
            v6y = 0 * (1 + (rand() % 11) / 5);
        }

        //Métodos Get e Set para variáveis de posformações geométricas
        float getPosX() {
            return posx;
        }

        float getPosY() {
            return posy;
        }
        
        void setPosX(float tx) {
            posx = tx;
        }

        void setPosY(float ty) {
            posy = ty;
        }

        float getScaleX() {
            return scalex;
        }

        float getScaleY() {
            return scaley;
        }

        void setScaleX(float scx) {
            scalex = scx;
        }

        void setScaleY(float scy) {
            scaley = scy;
        }

        void setScale(float sc) {
            scalex = sc;
            scaley = sc;
        }

        float getAngle() {
            return angleTotal;
        }

        void setAngle(float ang) {
            angleTotal = ang;
        }
};

#endif // HEXAGON_H_INCLUDED
