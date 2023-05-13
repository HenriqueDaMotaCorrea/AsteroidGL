#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <gl/glut.h>
#include <cmath>
#include <string>
#include <iostream>
#include <array>

#include "ship.h"
#include "asteroid.h"

// Resolução
#define RESOLUTION_HEIGHT 600
#define RESOLUTION_WIDTH 800

// Quadros por segundo
#define DESIRED_FPS 60

struct windowcolor {
            GLclampf red;
            GLclampf green;
            GLclampf blue;
            GLclampf alpha;
        };

class Game{

    public:
        // Window
        std::string title;
        int width;
        int height;
        windowcolor bg;
        int fps;
        // Actors
        Ship ship;
        Projectile proj;
        Asteroid ast;
        std::array<Asteroid, 3> astbuffer;

        Game() {
            title = "AsteroidGL";
            width = RESOLUTION_WIDTH;
            height = RESOLUTION_HEIGHT;
            bg.red = 0.0f;
            bg.green = 0.0f;
            bg.blue = 0.0f;
            bg.alpha = 0.0f;
            fps = DESIRED_FPS;
            ship = Ship();
            proj = Projectile();
            ast = Asteroid();
        }

        Game(std::string t, int h, int w, GLclampf r, GLclampf g, GLclampf b, GLclampf a, int f, Ship sh, Projectile pr, Asteroid as) {
            title = t;
            height = h;
            width = w;
            bg.red = r;
            bg.green = g;
            bg.blue = b;
            bg.alpha = a;
            fps = f;
            ship = sh;
            proj = pr;
            ast = as;
        }

        void drawObjects() {
            ship.draw();
            proj.draw();
            ast.draw();
            for (int i = 0; i < astbuffer.size(); i++) {
                astbuffer[i].draw();
            }
        }

        void spawnAsteroid() {
            // Dynamic array should have worked but caused the application to not run
            // I never figured out why
            // std::size_t newsize = astbuffer.size() + 1;
            // std::array<Asteroid, newsize> auxbuf;
            Asteroid newast = Asteroid();
            newast.setup((RESOLUTION_WIDTH / 2), (RESOLUTION_HEIGHT / 2), ASTEROID_MEDIUM);
            ast = newast;
        }

        void shipControls(int key) {
            ship.movementKeys(key);
        }

        void keyboardKeys(unsigned char key) {
            key = toupper(key);
            if (key == 27) { // Esc
                exit(0);
            } else if (key == 32) { // Spacebar
                Circle auxbody = proj.getBody();
                auxbody.setPosX(ship.getBody().getPosX());
                auxbody.setPosY(ship.getBody().getPosY());
                proj.setBody(auxbody);
                proj.setDirX(ship.getDirX());
                proj.setDirY(ship.getDirY());
            } else if (key == 'A') {
                ship.getBody().setScaleX(ship.getBody().getScaleX()+1);
                ship.getBody().setScaleY(ship.getBody().getScaleY()+1);
            } else if (key == 'D') {
                ship.getBody().setScaleX(ship.getBody().getScaleX()-1);
                ship.getBody().setScaleY(ship.getBody().getScaleY()-1);
            // Debug
            } else if (key = 'Z') {
                spawnAsteroid();
            }
        }

        void update() {
            ship.movement(0, RESOLUTION_WIDTH, 0, RESOLUTION_HEIGHT);
            proj.movement(0, RESOLUTION_WIDTH, 0, RESOLUTION_HEIGHT);
            ast.movement(0, RESOLUTION_WIDTH, 0, RESOLUTION_HEIGHT);
            for (int i = 0; i < astbuffer.size(); i++) {
                astbuffer[i].movement(0, RESOLUTION_WIDTH, 0, RESOLUTION_HEIGHT);
            }
        }

        void setup() {
            ship.setup(RESOLUTION_WIDTH / 2, RESOLUTION_HEIGHT / 2, 20);
            proj.setup(RESOLUTION_WIDTH / 2, RESOLUTION_HEIGHT / 2, 2);

            // Selects random positions for asteroid spawning, adjusted
            // to account for a safezone at the center
            float safezone_left = (RESOLUTION_WIDTH / 4);
            float safezone_right = (RESOLUTION_WIDTH / 4);
            float safezone_top = (RESOLUTION_HEIGHT / 4);
            float safezone_bottom = (RESOLUTION_HEIGHT / 4);
            float init_posx = 0;
            float init_posy = 0;
            
            for (int i = 0; i < astbuffer.size(); i++) {
                init_posx = rand() % RESOLUTION_WIDTH;
                init_posy = rand() % RESOLUTION_HEIGHT;
                if (safezone_left < init_posx < safezone_right) {
                    init_posx -= RESOLUTION_WIDTH / 4;
                }
                if (safezone_top < init_posy < safezone_bottom) {
                    init_posy -= RESOLUTION_HEIGHT / 4;
                }
                astbuffer[i].setup(init_posx, init_posy, ASTEROID_BIG);
            }
        }
};


#endif // GAME_H_INCLUDED
