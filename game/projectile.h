#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include <gl/glut.h>
#include <cmath>

#include "circle.h"

#define DEFAULT_MAXPROJSPEED 4

class Projectile{

    private:
        Circle body = Circle();
        float velocity[2] = {0,0};
        float maxspeed = DEFAULT_MAXPROJSPEED;
        float dirx, diry = 0;

    public:
        //Construtores
        Projectile() {
            body = Circle();
            velocity[0], velocity[1] = 0;
            maxspeed = DEFAULT_MAXPROJSPEED;
            dirx, diry = 0;
        }

        Projectile(float pox, float poy, float prad, float r, float g, float b, float velx, float vely, float ms, float dx, float dy) {
            body = Circle(pox, poy, prad, r, g, b);
            velocity[0] = velx;
            velocity[1] = vely;
            maxspeed = ms;
            dirx = dx;
            diry = dy;
        }

        //Metodo para desenhar
        void draw() {
            body.draw();
        }

        void movement(int min_x, int max_x, int min_y, int max_y) {
            // Velocidade máxima
            if (velocity[0] > maxspeed) {
                velocity[0] = maxspeed;
            }
            if (velocity[1] > maxspeed) {
                velocity[1] = maxspeed;
            }
            if (velocity[0] < -maxspeed) {
                velocity[0] = -maxspeed;
            }
            if (velocity[1] < -maxspeed) {
                velocity[1] = -maxspeed;
            }
            // Drift            
            velocity[0] = dirx * DEFAULT_MAXPROJSPEED;
            velocity[1] = diry * DEFAULT_MAXPROJSPEED;
            body.setPosX(body.getPosX() - velocity[0] * 2);
            body.setPosY(body.getPosY() + velocity[1] * 2);
            // Wrap around
            float currentposx = body.getPosX();
            float currentposy = body.getPosY();
            if (currentposx < min_x) {
                body.setPosX(max_x);
            } else if (currentposx > max_x) {
                body.setPosX(min_x);
            }
            if (currentposy < min_y) {
                body.setPosY(max_y);
            } else if (currentposy > max_y) {
                body.setPosY(min_y);
            }
        }

        //Métodos Get e Set
        Circle getBody() {
            return body;
        }

        void setBody(Circle c) {
            body = c;
        }

        float getVelocityX() {
            return velocity[0];
        }

        float getVelocityY() {
            return velocity[1];
        }

        void setVelocityX(float velx) {
            velocity[0] = velx;
        }

        void setVelocityY(float vely) {
            velocity[1] = vely;
        }

        float getDirX() {
            return dirx;
        }

        float getDirY() {
            return diry;
        }

        void setDirX(float dx) {
            dirx = dx;
        }

        void setDirY(float dy) {
            diry = dy;
        }

        //Método que inicializa o objeto nas condições desejadas
        void setup(float desired_posx, float desired_posy, float desired_radius) {
            body.setPosX(desired_posx);
            body.setPosY(desired_posy);
            body.setRadius(desired_radius);
        }
};


#endif // PROJECTILE_H_INCLUDED
