#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <gl/glut.h>
#include <cmath>

class Triangle {

    private:
        float v1x, v1y, v2x, v2y, v3x, v3y;
        float cr, cg, cb;
        float posx, posy;
        float scalex, scaley;
        float angleTotal;

    public:
        //Construtores
        Triangle() {
            v1x = -0.5;
            v1y = -0.5;
            v2x = 0.5;
            v2y = -0.5;
            v3x = 0.0;
            v3y = 0.75;
            cr = 1.0;
            cg = 1.0;
            cb = 1.0;
            posx = posy = 0.0;
            scalex = scaley = 1.0;
            angleTotal = 0.0;
        }

        Triangle(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float r, float g, float b, float px, float py, float scx, float scy, float ang) {
            v1x = p1x;
            v1y = p1y;
            v2x = p2x;
            v2y = p2y;
            v3x = p3x;
            v3y = p3y;
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
            glBegin(GL_TRIANGLES);
                glVertex2f(v1x*scalex+posx, v1y*scaley+posy);
                glVertex2f(v2x*scalex+posx, v2y*scaley+posy);
                glVertex2f(v3x*scalex+posx, v3y*scaley+posy);
            glEnd();
        }

        //Método para a transformação geométrica de rotação
        void rotate(float angle) {
            angleTotal += angle;
            if (angleTotal == 360) {
                angleTotal = 0;
            } else if (angleTotal > 360) {
                angleTotal -= 360;
            }

            angle = (angle * M_PI)/180.0;

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
        }

        //Métodos Get e Set para variáveis de transformações geométricas
        float getPosX(){
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


#endif // TRIANGLE_H_INCLUDED
