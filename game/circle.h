#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include <gl/glut.h>
#include <cmath>

class Circle {

    private:
        float ox;
        float oy;
        float radius;
        float cr, cg, cb;
        float posx, posy;

    public:
        //Construtores
        Circle() {
            ox = 0;
            oy = 0;
            radius = 0.125;
            cr = 1.0;
            cg = 1.0;
            cb = 1.0;
            posx = posy = 0.0;
        }

        Circle(float pox, float poy, float prad, float r, float g, float b) {
            ox = poy;
            oy = poy;
            radius = prad;
            cr = r;
            cg = g;
            cb = b;
            posx = posy = 0.0;
        }

        //Metodo para desenhar
        //Fonte: https://gist.github.com/linusthe3rd/803118
        void draw() {
            int i;
            int triangleCount = 20;
            float twicePi = 2.0f * M_PI;
            glColor3f(cr, cg, cb);

            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(ox+posx, oy+posy);
                for (int i = 0; i <= triangleCount; i++){
                    glVertex2f(
                        ox + ((radius * cos(i * twicePi / triangleCount)) + posx),
                        oy + ((radius * sin(i * twicePi / triangleCount)) + posy)
                    );
                }
            glEnd();
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

        float getRadius() {
            return radius;
        }

        void setRadius(float r) {
            radius = r;
        }
};


#endif // CIRCLE_H_INCLUDED
