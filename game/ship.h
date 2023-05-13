#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED
#include <gl/glut.h>
#include <cmath>

#include "triangle.h"
#include "projectile.h"

#define DEFAULT_MAXSHIPSPEED 2
#define DEFAULT_SHIPTHRUST 0.2

class Ship{

    private:
        Triangle body = Triangle();
        float velocity[2] = {0,0};
        float thrust = DEFAULT_SHIPTHRUST;
        float maxspeed = DEFAULT_MAXSHIPSPEED;
        float dirx, diry = 0;

    public:
        //Construtores
        Ship() {
            body = Triangle();
            velocity[0], velocity[1] = 0;
            thrust = DEFAULT_SHIPTHRUST;
            maxspeed = DEFAULT_MAXSHIPSPEED;
            dirx = sin((body.getAngle() * M_PI) / 180);
            diry = cos((body.getAngle() * M_PI) / 180);
        }

        Ship(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float r, float g, float b, float px, float py, float scx, float scy, float ang, float thr, float ms) {
            body = Triangle(p1x, p1y, p2x, p2y, p3x, p3y, r, g, b, px, py, scx, scy, ang);
            velocity[0], velocity[1] = 0;
            thrust = thr;
            maxspeed = ms;
            dirx = sin((body.getAngle() * M_PI) / 180);
            diry = cos((body.getAngle() * M_PI) / 180);
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
            body.setPosX(body.getPosX() - velocity[0]);
            body.setPosY(body.getPosY() + velocity[1]);
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

        //Método para movimentação
        void movementKeys(int key) {
            dirx = sin(body.getAngle() * M_PI / 180);
            diry = cos(body.getAngle() * M_PI / 180);
            if (key == GLUT_KEY_UP) {
                velocity[0] += dirx * thrust;
                velocity[1] += diry * thrust;
            } else if (key == GLUT_KEY_DOWN) {
                velocity[0] -= dirx * thrust;
                velocity[1] -= diry * thrust;
            } else if (key == GLUT_KEY_RIGHT) {
                body.rotate(10.0);
            } else if (key == GLUT_KEY_LEFT) {
                body.rotate(-10.0);
            }
        }

        //Métodos Get e Set
        Triangle getBody() {
            return body;
        }

        void setBody(Triangle tri) {
            body = tri;
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
        void setup(float desired_posx, float desired_posy, float desired_scale) {
            body.setPosX(desired_posx);
            body.setPosY(desired_posy);
            body.setScale(desired_scale);
            velocity[0], velocity[1] = 0;
        }
};


#endif // SHIP_H_INCLUDED
