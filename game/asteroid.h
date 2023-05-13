#ifndef ASTEROID_H_INCLUDED
#define ASTEROID_H_INCLUDED
#include <gl/glut.h>
#include <cmath>

#include "hexagon.h"

#define DEFAULT_MAXASTSPEED 1

#define ASTEROID_BIG 20
#define ASTEROID_MEDIUM 10
#define ASTEROID_SMALL 5

class Asteroid{

    private:
        Hexagon body = Hexagon();
        float velocity[2] = {0,0};
        float maxspeed = DEFAULT_MAXASTSPEED;
        float dirx, diry = 0;
        float angularspeed = 0;

    public:
        Asteroid() {
            body = Hexagon();
            velocity[0], velocity[1] = 0;
            maxspeed = DEFAULT_MAXASTSPEED;
            dirx = sin((body.getAngle() * M_PI) / 180);
            diry = cos((body.getAngle() * M_PI) / 180);
            angularspeed = 1 * ((rand() % 11) -5); // -5° to 5°
        }

        Asteroid(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y, float p5x, float p5y, float p6x, float p6y, float r, float g, float b, float px, float py, float scx, float scy, float ang, float ms) {
            body = Hexagon(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, p5x, p5y, p6x, p6y, r, g, b, px, py, scx, scy, ang);
            velocity[0], velocity[1] = 0;
            maxspeed = ms;
            dirx = sin((body.getAngle() * M_PI) / 180);
            diry = cos((body.getAngle() * M_PI) / 180);
            angularspeed = 1 * (rand() % 11) -5; // -5° to 5°
        }

        void draw() {
            body.draw();
        }

        void movement(int min_x, int max_x, int min_y, int max_y) {
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
            // Spin
            body.rotate(angularspeed);
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

        Hexagon getBody() {
            return body;
        }

        void setBody(Hexagon hex) {
            body = hex;
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

        float getAngularSpeed() {
            return angularspeed;
        }

        void setAngularSpeed(float angspd) {
            angularspeed = angspd;
        }

        void setup(float desired_posx, float desired_posy, float desired_scale) {
            body.setPosX(desired_posx);
            body.setPosY(desired_posy);
            body.setScale(desired_scale);
            body.randomizeShape();
            velocity[0] = 1 * ((rand() % 11) - 5);
            velocity[1] = 1 * ((rand() % 11) - 5);
            angularspeed = 1 * ((rand() % 11) -5); // -5° to 5°
        }
};


#endif // ASTEROID_H_INCLUDED
