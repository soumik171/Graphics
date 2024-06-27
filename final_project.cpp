#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include<cstring>
using namespace std;

float move_ship_container = 0.0f;
float move_airplane = 0.0f;
float move_left_car = 0.0f;
float move_left_truck = 0.0f;


float move_right_truck = 0.0f;
float move_right_car = 0.0f;
float move_cloud = 0.0f;
float move_sun = 0.0f;
float move_moon = 0.0f;

float move_wave = 0.0f;
float move_boat = 0.0f;
float move_boat_1 = 0.0f;
float move_boat_2 = 0.0f;
float move_speed_boat = 0.0f;
float angle_1 = 0.0f;
float angle_2 = 0.0f;
float right_angle_1 = 0.0f;
float right_angle_2 = 0.0f;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = 3.1416f * i / 180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


//DAY START

void water() //id1
{
    //water
    glColor3ub(120, 215, 255); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, -200.0f);
    glVertex2f(200.0f, -200.0f);
    glVertex2f(200.0f, -35.0f);
    glVertex2f(0.0f, -35.0f);
    glEnd();

    //beach
    glColor3ub(194, 178, 128); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, -35.0f);
    glVertex2f(200.0f, -35.0f);
    glVertex2f(200.0f, 25.0f);
    glVertex2f(0.0f, 25.0f);
    glEnd();

}




void LeftSide(float x, float y, float a, float b)
{
    glColor3ub(128.0f, 0.0f, 32.0f);
    glBegin(GL_QUADS);//base-rod
    glVertex2f(((-5.0 * x) + a), (b + (0.0 * y)));
    glVertex2f(((-4.3 * x) + a), (b + (0.0 * y)));
    glVertex2f(((-4.3 * x) + a), (b + (3.5 * y)));
    glVertex2f(((-5.0 * x) + a), (b + (3.5 * y)));
    glEnd();

    glBegin(GL_TRIANGLES);//base-angle
    glVertex2f(((-4.3 * x) + a), (b + (2.5 * y)));
    glVertex2f(((-6.0 * x) + a), (b + (4.0 * y)));
    glVertex2f(((-4.3 * x) + a), (b + (4.0 * y)));
    glEnd();

    glBegin(GL_QUADS);//upper-rod
    glVertex2f(((-5.0 * x) + a), (b + (3.0 * y)));
    glVertex2f(((-4.3 * x) + a), (b + (3.0 * y)));
    glVertex2f(((-4.3 * x) + a), (b + (10.0 * y)));
    glVertex2f(((-4.9 * x) + a), (b + (10.0f * y)));
    glEnd();

    glColor3ub(160, 79, 43);
    glBegin(GL_QUADS);//seat
    glVertex2f(((-6.8 * x) + a), (b + (4.0 * y)));
    glVertex2f(((-0.0 * x) + a), (b + (4.0 * y)));
    glVertex2f(((-0.0 * x) + a), (b + (4.5 * y)));
    glVertex2f(((-7.0 * x) + a), (b + (4.5 * y)));
    glEnd();

    glBegin(GL_QUADS);//base-rod-holder
    glColor3ub(0, 0, 0);
    glVertex2f(((-5.3 * x) + a), (b + (0.0 * y)));
    glVertex2f(((-4.0 * x) + a), (b + (0.0 * y)));
    glVertex2f(((-4.3 * x) + a), (b + (1.5 * y)));
    glVertex2f(((-5.0 * x) + a), (b + (1.5 * y)));
    glEnd();

    float  p = 0, q = 0;
    float x1 = 6.0, y1 = 5.0, x2 = 0.0, y2 = 5.5;
    for (int i = 0;i < 10;i++)
    {


        if (i % 2 == 0)
        {

            glBegin(GL_QUADS);
            glColor3ub(200, 90, 43);
            glVertex2f(((-(x1 + p) * x) + a), (b + ((y1 + q) * y)));
            glVertex2f(((-(x2 + p) * x) + a), (b + ((y1 + q) * y)));
            glVertex2f(((-(x2 + p) * x) + a), (b + ((y2 + q) * y)));
            glVertex2f(((-(x1 + p) * x) + a), (b + ((y2 + q) * y)));
            glEnd();
            ++q;
        }

    }


}
void RightSide(float x, float y, float a, float b)
{
    glColor3ub(128.0f, 0.0f, 32.0f);
    glBegin(GL_QUADS);//base-rod
    glVertex2f(((5.0 * x) + a), (b + (0.0 * y)));
    glVertex2f(((4.3 * x) + a), (b + (0.0 * y)));
    glVertex2f(((4.3 * x) + a), (b + (3.5 * y)));
    glVertex2f(((5.0 * x) + a), (b + (3.5 * y)));
    glEnd();

    glBegin(GL_TRIANGLES);//base-angle
    glVertex2f(((4.3 * x) + a), (b + (2.5 * y)));
    glVertex2f(((6.0 * x) + a), (b + (4.0 * y)));
    glVertex2f(((4.3 * x) + a), (b + (4.0 * y)));
    glEnd();

    glBegin(GL_QUADS);//upper-rod
    glVertex2f(((5.0 * x) + a), (b + (3.0 * y)));
    glVertex2f(((4.3 * x) + a), (b + (3.0 * y)));
    glVertex2f(((4.3 * x) + a), (b + (10.0 * y)));
    glVertex2f(((4.9 * x) + a), (b + (10.0 * y)));
    glEnd();

    glColor3ub(160, 79, 43);
    glBegin(GL_QUADS);//seat
    glVertex2f(((6.8 * x) + a), (b + (4.0 * y)));
    glVertex2f(((0.0 * x) + a), (b + (4.0 * y)));
    glVertex2f(((0.0 * x) + a), (b + (4.5 * y)));
    glVertex2f(((7.0 * x) + a), (b + (4.5 * y)));
    glEnd();

    glBegin(GL_QUADS);//base-rod-holder
    glColor3ub(0, 0, 0);

    glVertex2f(((5.3 * x) + a), (b + (0.0 * y)));
    glVertex2f(((4.0 * x) + a), (b + (0.0 * y)));
    glVertex2f(((4.3 * x) + a), (b + (1.5 * y)));
    glVertex2f(((5.0 * x) + a), (b + (1.5 * y)));
    glEnd();

    float x1 = 6.0, y1 = 5.0, x2 = 0.0, y2 = 5.5;
    float  p = 0, q = 0;

    for (int i = 0;i < 10;i++)
    {


        if (i % 2 == 0)
        {

            glBegin(GL_QUADS);
            glColor3ub(200, 90, 43);
            glVertex2f((((x1 + p) * x) + a), (b + ((y1 + q) * y)));
            glVertex2f((((x2 + p) * x) + a), (b + ((y1 + q) * y)));
            glVertex2f((((x2 + p) * x) + a), (b + ((y2 + q) * y)));
            glVertex2f((((x1 + p) * x) + a), (b + ((y2 + q) * y)));
            glEnd();
            ++q;
        }

    }


}
void Body(float x, float y, float a, float b)
{

    glColor3ub(210.0f, 105.0, 30.0);//RGB Chocholate
    LeftSide(x, y, a, b);
    RightSide(x, y, a, b);
    glFlush();  // Render now

}
//bench-1:

void beach_bench1() {
    float x = 1, y = 1;  //Scale or ratio of bench
    float a = -0, b = -0;//position


    glClearColor(0.6f, 0.4f, 1.0f, 1.0f); // Set background color to violate and opaque
    //  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
       //plot(x,y);

    Body(x, y, a, b);


    glFlush(); // Render now
}

void render_bench1() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(18.0f, -14.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(.5f, 3.5f, 0.0f); // Scale down to fit the new project's coordinate system
    beach_bench1();
    glPopMatrix();

    //glFlush();
}
//bench-2:

void beach_bench2() {
    float x = 1, y = 1;  //Scale or ratio of bench
    float a = -0, b = -0;//position


    glClearColor(0.6f, 0.4f, 1.0f, 1.0f); // Set background color to violate and opaque
    //  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
       //plot(x,y);

    Body(x, y, a, b);


    glFlush(); // Render now
}

void render_bench2() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(68.0f, -14.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(.5f, 3.5f, 0.0f); // Scale down to fit the new project's coordinate system
    beach_bench2();
    glPopMatrix();

    //glFlush();
}
//bench-1:

void beach_bench3() {
    float x = 1, y = 1;  //Scale or ratio of bench
    float a = -0, b = -0;//position


    glClearColor(0.6f, 0.4f, 1.0f, 1.0f); // Set background color to violate and opaque
    //  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
       //plot(x,y);

    Body(x, y, a, b);


    glFlush(); // Render now
}

void render_bench3() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(118.0f, -14.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(.5f, 3.5f, 0.0f); // Scale down to fit the new project's coordinate system
    beach_bench3();
    glPopMatrix();

    //glFlush();
}
//bench-4:

void beach_bench4() {
    float x = 1, y = 1;  //Scale or ratio of bench
    float a = -0, b = -0;//position


    glClearColor(0.6f, 0.4f, 1.0f, 1.0f); // Set background color to violate and opaque
    //  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
       //plot(x,y);

    Body(x, y, a, b);


    glFlush(); // Render now
}

void render_bench4() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(168.0f, -14.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(.5f, 3.5f, 0.0f); // Scale down to fit the new project's coordinate system
    beach_bench4();
    glPopMatrix();

    //glFlush();
}






void umbrella() //id3
{
    //from left first umbrella

    //stand
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(22.0f, -15.0f);
    glVertex2f(22.0f, 35.0f);
    glEnd();

    //left[1st part]
    glColor3ub(176, 32, 17); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(12.0f, 26.0f);
    glVertex2f(17.0f, 20.0f);
    glVertex2f(22.0f, 50.0f);

    glEnd();

    //2nd part

    glColor3ub(20, 158, 43); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(17.0f, 20.0f);
    glVertex2f(22.0f, 18.0f);
    glVertex2f(22.0f, 50.0f);
    glEnd();

    // 3rd part

    glColor3ub(17, 48, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(22.0f, 18.0f);
    glVertex2f(27.0f, 20.0f);
    glVertex2f(22.0f, 50.0f);
    glEnd();

    // 4th part
    glColor3ub(116, 17, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(27.0f, 20.0f);
    glVertex2f(32.0f, 26.0f);
    glVertex2f(22.0f, 50.0f);
    glEnd();




    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(72.0f, -15.0f);
    glVertex2f(72.0f, 35.0f);
    glEnd();

    //left from second [1st part]
    glColor3ub(176, 32, 17); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(62.0f, 26.0f);
    glVertex2f(67.0f, 20.0f);
    glVertex2f(72.0f, 50.0f);

    glEnd();

    //2nd part

    glColor3ub(20, 158, 43); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(67.0f, 20.0f);
    glVertex2f(72.0f, 18.0f);
    glVertex2f(72.0f, 50.0f);
    glEnd();

    // 3rd part

    glColor3ub(17, 48, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(72.0f, 18.0f);
    glVertex2f(77.0f, 20.0f);
    glVertex2f(72.0f, 50.0f);
    glEnd();

    // 4th part
    glColor3ub(116, 17, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(77.0f, 20.0f);
    glVertex2f(82.0f, 26.0f);
    glVertex2f(72.0f, 50.0f);
    glEnd();



    //left from third [1st part]
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(122.0f, -15.0f);
    glVertex2f(122.0f, 35.0f);
    glEnd();

    glColor3ub(176, 32, 17); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(112.0f, 26.0f);
    glVertex2f(117.0f, 20.0f);
    glVertex2f(122.0f, 50.0f);

    glEnd();

    //2nd part

    glColor3ub(20, 158, 43); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(117.0f, 20.0f);
    glVertex2f(122.0f, 18.0f);
    glVertex2f(122.0f, 50.0f);
    glEnd();

    // 3rd part

    glColor3ub(17, 48, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(122.0f, 18.0f);
    glVertex2f(127.0f, 20.0f);
    glVertex2f(122.0f, 50.0f);
    glEnd();

    // 4th part
    glColor3ub(116, 17, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(127.0f, 20.0f);
    glVertex2f(132.0f, 26.0f);
    glVertex2f(122.0f, 50.0f);
    glEnd();





    //left from fourth [1st part]
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(172.0f, -15.0f);
    glVertex2f(172.0f, 35.0f);
    glEnd();

    glColor3ub(176, 32, 17); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(162.0f, 26.0f);
    glVertex2f(167.0f, 20.0f);
    glVertex2f(172.0f, 50.0f);

    glEnd();

    //2nd part

    glColor3ub(20, 158, 43); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(167.0f, 20.0f);
    glVertex2f(172.0f, 18.0f);
    glVertex2f(172.0f, 50.0f);
    glEnd();

    // 3rd part

    glColor3ub(17, 48, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(172.0f, 18.0f);
    glVertex2f(177.0f, 20.0f);
    glVertex2f(172.0f, 50.0f);
    glEnd();

    // 4th part
    glColor3ub(116, 17, 176); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(177.0f, 20.0f);
    glVertex2f(182.0f, 26.0f);
    glVertex2f(172.0f, 50.0f);
    glEnd();


}


void wave()  //id4
{
    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f, move_wave, 0.0f);//for move
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-200.0f, -195.0f);
    glVertex2f(300.0f, -195.0f);
    glVertex2f(20.0f, -190.0f);
    glVertex2f(20.0f, -190.0f);
    glEnd();

    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-160.0f, -195.0f);
    glVertex2f(400.0f, -195.0f);
    glVertex2f(20.0f, -190.0f);
    glVertex2f(20.0f, -190.0f);
    glEnd();

    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-100.0f, -170.0f);
    glVertex2f(400.0f, -170.0f);
    glVertex2f(200.0f, -165.0f);
    glVertex2f(160.0f, -165.0f);
    glEnd();

    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-160.0f, -150.0f);
    glVertex2f(240.0f, -150.0f);
    glVertex2f(100.0f, -145.0f);
    glVertex2f(100.0f, -145.0f);
    glEnd();

    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-120.0f, -130.0f);
    glVertex2f(400.0f, -130.0f);
    glVertex2f(100.0f, -125.0f);
    glVertex2f(100.0f, -125.0f);
    glEnd();


    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-180.0f, -120.0f);
    glVertex2f(300.0f, -120.0f);
    glVertex2f(144.0f, -115.0f);
    glVertex2f(130.0f, -115.0f);
    glEnd();

    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-50.0f, -100.0f);
    glVertex2f(350.0f, -100.0f);
    glVertex2f(183.0f, -95.0f);
    glVertex2f(140.0f, -95.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-150.0f, -100.0f);
    glVertex2f(500.0f, -100.0f);
    glVertex2f(60.0f, -95.0f);
    glVertex2f(80.0f, -95.0f);
    glEnd();

    glColor3ub(166, 225, 249); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-166.0f, -80.0f);
    glVertex2f(360.0f, -80.0f);
    glVertex2f(50.0f, -75.0f);
    glVertex2f(40.0f, -75.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-178.0f, -60.0f);
    glVertex2f(380.0f, -60.0f);
    glVertex2f(50.0f, -55.0f);
    glVertex2f(40.0f, -55.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-190.0f, -50.0f);
    glVertex2f(350.0f, -50.0f);
    glVertex2f(48.0f, -45.0f);
    glVertex2f(67.0f, -45.0f);
    glEnd();
    glPopMatrix();
}

void update_wave(int value) //id40
{
    move_wave += 0.5; //assume as moving speed
    if (move_wave > 13) //water layer -35 |-45+13=-32
    {
        move_wave = -20;//-32+20=-52 then start form -52
    }
    glutPostRedisplay();
    glutTimerFunc(40, update_wave, 0);
}


void road()  //id5
{

    //main structure
    glColor3ub(128, 128, 128); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, 25.0f);
    glVertex2f(200.0f, 25.0f);
    glVertex2f(200.0f, 80.0f);
    glVertex2f(0.0f, 80.0f);
    glEnd();

    //road slide lines
    glLineWidth(3.0f);
    glColor3ub(255, 255, 255); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, 75.0f);
    glVertex2f(200.0f, 75.0f);
    glVertex2f(200.0f, 30.0f);
    glVertex2f(0.0f, 30.0f);
    glEnd();

    //middle dot lines
    glLineWidth(3.0f);
    glColor3ub(255, 255, 255); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(5.0f, 52.5f);
    glVertex2f(10.0f, 52.5f);
    glVertex2f(15.0f, 52.5f);
    glVertex2f(20.0f, 52.5f);
    glVertex2f(25.0f, 52.5f);
    glVertex2f(30.0f, 52.5f);
    glVertex2f(35.0f, 52.5f);
    glVertex2f(40.0f, 52.5f);
    glVertex2f(45.0f, 52.5f);
    glVertex2f(50.0f, 52.5f);
    glVertex2f(55.0f, 52.5f);
    glVertex2f(60.0f, 52.5f);
    glVertex2f(65.0f, 52.5f);
    glVertex2f(70.0f, 52.5f);
    glVertex2f(75.0f, 52.5f);
    glVertex2f(80.0f, 52.5f);
    glVertex2f(85.0f, 52.5f);
    glVertex2f(90.0f, 52.5f);
    glVertex2f(95.0f, 52.5f);
    glVertex2f(100.0f, 52.5f);

    glVertex2f(105.0f, 52.5f);
    glVertex2f(110.0f, 52.5f);
    glVertex2f(115.0f, 52.5f);
    glVertex2f(120.0f, 52.5f);
    glVertex2f(125.0f, 52.5f);
    glVertex2f(130.0f, 52.5f);
    glVertex2f(135.0f, 52.5f);
    glVertex2f(140.0f, 52.5f);
    glVertex2f(145.0f, 52.5f);
    glVertex2f(150.0f, 52.5f);
    glVertex2f(155.0f, 52.5f);
    glVertex2f(160.0f, 52.5f);
    glVertex2f(165.0f, 52.5f);
    glVertex2f(170.0f, 52.5f);
    glVertex2f(175.0f, 52.5f);
    glVertex2f(180.0f, 52.5f);
    glVertex2f(185.0f, 52.5f);
    glVertex2f(190.0f, 52.5f);
    glVertex2f(195.0f, 52.5f);
    glVertex2f(200.0f, 52.5f);
    glEnd();

}
void sky()  //id6
{
    //glColor3ub(34.0f,263.0f,223.0f); // Clear the color buffer (background)
    glColor3ub(135, 240, 250);
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, 80.0f);
    glVertex2f(200.0f, 80.0f);
    glVertex2f(200.0f, 400.0f);
    glVertex2f(0.0f, 400.0f);
    glEnd();

}

void bench()  //id7
{

    //left side 1st bench
    //upper part
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(40.0f, 92.0f);
    glVertex2f(48.0f, 92.0f);
    glEnd();

    //left leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(41.0f, 80.0f);
    glVertex2f(41.0f, 92.0f);
    glEnd();
    //right leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(47.0f, 80.0f);
    glVertex2f(47.0f, 92.0f);
    glEnd();


    //left side 2nd bench
    //upper part
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(50.0f, 92.0f);
    glVertex2f(58.0f, 92.0f);
    glEnd();

    //left leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(51.0f, 80.0f);
    glVertex2f(51.0f, 92.0f);
    glEnd();
    //right leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(57.0f, 80.0f);
    glVertex2f(57.0f, 92.0f);
    glEnd();

}
void lamppost()  //id8
{
    //left side lamppost
    //pillar
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(62.0f, 80.0f);
    glVertex2f(62.0f, 162.5f);
    glEnd();

    //light holder
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(62.0f, 160.0f);
    glVertex2f(54.0f, 160.0f);
    glEnd();

    //light
    glColor3ub(255, 255, 255); // Clear the color buffer (background)
    glLineWidth(7.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(54.0f, 158.0f);
    glVertex2f(57.0f, 158.0f);
    glEnd();
}
void left_car()  //id9
{

    //left first car
    //middle body
    glColor3ub(137, 1, 255); // Clear the color buffer (background)
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(move_left_car, 0.0f, 0.0f);//for move
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(5.0f, 62.0f);
    glVertex2f(23.0f, 62.0f);
    glVertex2f(23.0f, 79.0f);
    glVertex2f(5.0f, 79.0f);
    glEnd();

    //upper body
    glColor3ub(245, 245, 245); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(6.0f, 79.0f);
    glVertex2f(20.0f, 79.0f);
    glVertex2f(17.0f, 97.0f);
    glVertex2f(8.0f, 97.0f);
    glEnd();

    //RIGHT 2D view
    glColor3ub(138, 43, 226); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(20.0f, 79.0f);
    glVertex2f(23.0f, 79.0f);
    glVertex2f(19.0f, 84.0f);
    glEnd();

    //car glass left
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(7.0f, 79.0f);
    glVertex2f(12.5f, 79.0f);
    glVertex2f(12.5f, 93.5f);
    glVertex2f(8.5f, 93.5f);
    glEnd();

    //car glass Right

    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(13.0f, 79.0f);
    glVertex2f(19.0f, 79.0f);
    glVertex2f(17.0f, 93.5f);
    glVertex2f(13.0f, 93.5f);
    glEnd();

    //left back light
    glColor3ub(255, 0, 0); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(5.0f, 70.0f);
    glVertex2f(6.0f, 70.0f);
    glVertex2f(6.0f, 79.0f);
    glVertex2f(5.0f, 79.0f);
    glEnd();

    //rear wheel
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 2.7f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 9.3, y + 62);
    }

    glEnd();

    //front wheel
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 2.7f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 17, y + 62);
    }

    glEnd();
    glPopMatrix();

}

void right_car()  //id10
{

    //right first car
    //middle body
    glColor3ub(6, 47, 255); // Clear the color buffer (background)
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(move_right_car, 0.0f, 0.0f);//for move
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(176.5f, 39.0f);
    glVertex2f(195.0f, 39.0f);
    glVertex2f(195.0f, 58.0f);
    glVertex2f(176.5f, 58.0f);
    glEnd();


    //Left 2d View
    glColor3ub(6, 47, 255); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(176.5f, 58.0f);
    glVertex2f(180.0f, 58.0f);
    glVertex2f(183.0f, 62.5f);
    glEnd();

    //upper body
    glColor3ub(245, 245, 245); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(180.0f, 58.0f);
    glVertex2f(194.0f, 58.0f);
    glVertex2f(192.0f, 78.0f);
    glVertex2f(182.0f, 78.0f);
    glEnd();

    //car glass left
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(181.0f, 57.0f);
    glVertex2f(186.5f, 57.0f);
    glVertex2f(186.5f, 74.0f);
    glVertex2f(182.5f, 74.0f);
    glEnd();

    //car glass Right
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(187.0f, 57.0f);
    glVertex2f(193.0f, 57.0f);
    glVertex2f(191.5f, 74.0f);
    glVertex2f(187.0f, 74.0f);
    glEnd();

    //Right back light
    glColor3ub(255, 0, 0); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(194.0f, 48.0f);
    glVertex2f(195.0f, 48.0f);
    glVertex2f(195.0f, 57.0f);
    glVertex2f(194.0f, 57.0f);
    glEnd();

    //front wheel
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 2.7f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 182.5, y + 39);
    }

    glEnd();

    //rear wheel
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 2.6f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 190.5, y + 39);
    }

    glEnd();
    glPopMatrix();

}


void tree_old()  //id11
{
    //right side tree
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 160, y + 85);
    }

    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 13.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 182, y + 103.5);
    }

    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 170, y + 85);
    }

    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 12.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 195, y + 85);
    }
    glEnd();

    //left side tree
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 12.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 70, y + 85);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 60, y + 102);
    }
    glEnd();


    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 46, y + 122);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 40, y + 95);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 20.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 55, y + 85);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 45, y + 85);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 35, y + 85);
    }
    glEnd();


    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 25, y + 85);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 18.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 25, y + 100);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 15, y + 85);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(154, 205, 50);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 15.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 5, y + 85);
    }
    glEnd();


}

void tree()  //id11
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(15, 90);
    glVertex2f(22, 90);
    glVertex2f(21, 100);
    glVertex2f(20, 110);
    glVertex2f(18, 120);
    glVertex2f(16, 130);
    glVertex2f(17, 140);
    glVertex2f(18, 145);
    glVertex2f(20, 150);
    glVertex2f(22, 150);
    glVertex2f(21, 147);
    glVertex2f(20, 145);
    glVertex2f(18, 140);
    glVertex2f(16, 130);
    glVertex2f(13, 120);
    glVertex2f(16, 130);
    glVertex2f(18, 140);
    glVertex2f(20, 145);
    glVertex2f(22, 150);
    glVertex2f(22, 160);
    glVertex2f(18, 150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///........Tree........D-2.......///
    glColor3ub(75, 35, 5);
    glVertex2f(15, 125);
    glVertex2f(19, 130);
    glVertex2f(14, 140);
    glVertex2f(14, 150);
    glVertex2f(13, 160);
    glVertex2f(10, 170);
    glVertex2f(12, 170);
    glVertex2f(12, 160);
    glVertex2f(11, 150);
    glVertex2f(11, 140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);   ///tree...................D-3 p2  ///
    glColor3ub(75, 35, 5);
    glVertex2f(31, 140);
    glVertex2f(29, 140);
    glVertex2f(28, 120);
    glVertex2f(25, 120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///tree..................D-3 p1   ///
    glColor3ub(75, 35, 5);
    glVertex2f(16, 100);
    glVertex2f(21, 100);
    glVertex2f(24.5, 120);
    glVertex2f(28, 120);
    glEnd();

    ///
    glColor3ub(139, 146, 22);
    circle(8, 22, 0, 150);
    glColor3ub(139, 146, 22);
    circle(8, 22, 10, 170);
    glColor3ub(139, 146, 22);
    circle(8, 22, 13, 140);
    glColor3ub(139, 146, 22);
    circle(7, 25, 22, 150);
    glColor3ub(139, 146, 22);
    circle(8, 22, 30, 150);
    glColor3ub(139, 146, 22);
    circle(10, 40, 0, 250);

    glColor3ub(139, 146, 22);
    circle(9, 22, 30, 295);
    glColor3ub(139, 146, 22);
    circle(8, 15, 30, 293);

    glColor3ub(139, 146, 22);
    circle(9, 22, 45, 285);
    glColor3ub(139, 146, 22);
    circle(9, 22, 45, 280);
    glColor3ub(139, 146, 22);
    circle(8, 15, 45, 275);

    glColor3ub(139, 146, 22);
    circle(9, 22, 55, 235);
    glColor3ub(139, 146, 22);
    circle(9, 32, 50, 255);

    glColor3ub(139, 146, 22);
    circle(9, 22, 59, 225);
    glColor3ub(139, 146, 22);
    circle(9, 22, 56, 255);
    glColor3ub(139, 146, 22);
    circle(9, 22, 63, 195);
    glColor3ub(139, 146, 22);
    circle(9, 22, 50, 180);
    glColor3ub(139, 146, 22);
    circle(9, 22, 58, 165);
    glColor3ub(139, 146, 22);
    circle(9, 22, 49, 150);
    glColor3ub(139, 146, 22);
    circle(9, 22, 38, 140);


    glColor3ub(0, 77, 26);
    circle(10, 20, 55, 190);
    glColor3ub(139, 146, 22);
    circle(9.5, 19, 55, 190);


    glColor3ub(0, 77, 26);
    circle(10, 20, 55, 205);
    glColor3ub(139, 146, 22);
    circle(9.5, 20, 55, 205);


    glColor3ub(0, 77, 26);
    circle(10, 20, 50, 218);
    glColor3ub(139, 146, 22);
    circle(9.5, 20, 50, 218);


    glColor3ub(139, 146, 22);
    circle(10, 20, 27, 130);


    glColor3ub(139, 146, 22);
    circle(35, 70, 20, 200);
    glColor3ub(139, 146, 22);    ///
    circle(15, 30, 30, 255);


    glColor3ub(0, 77, 26);
    circle(10, 20, 42, 225);
    glColor3ub(139, 146, 22);
    circle(9.5, 20, 42, 224);


    glColor3ub(0, 77, 26);
    circle(10, 20, 30, 225);
    glColor3ub(139, 146, 22);
    circle(10, 20, 30, 224);


    glColor3ub(0, 77, 26);
    circle(10, 18, 42, 263);
    glColor3ub(139, 146, 22);
    circle(10, 18, 42, 262);


    glColor3ub(0, 77, 26);
    circle(10, 20, 30, 180);
    glColor3ub(139, 146, 22);
    circle(10, 20, 30, 179);

    glColor3ub(0, 77, 26);
    circle(10, 20, 20, 180);
    glColor3ub(139, 146, 22);
    circle(10, 20, 20, 179);

    glColor3ub(0, 77, 26);
    circle(10, 20, 40, 155);
    glColor3ub(139, 146, 22);
    circle(10, 20, 40, 156);


    glColor3ub(139, 146, 22);
    circle(9, 22, 20, 280);
    glColor3ub(0, 77, 26);
    circle(9, 21, 20, 270);
    glColor3ub(139, 146, 22);
    circle(9, 21, 20, 269);


    glColor3ub(139, 146, 22);
    circle(9, 22, 10, 255);
    glColor3ub(0, 77, 26);
    circle(9, 20, 10, 245);
    glColor3ub(139, 146, 22);
    circle(9, 20, 10.5, 244);

}

void render_tree() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(0.0f, 36.0f, 0.0f);
    glScalef(0.22f, 0.50f, 0.0f);
    glPopMatrix();

    //glFlush();
}
void tree2()  //id11
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(15, 90);
    glVertex2f(22, 90);
    glVertex2f(21, 100);
    glVertex2f(20, 110);
    glVertex2f(18, 120);
    glVertex2f(16, 130);
    glVertex2f(17, 140);
    glVertex2f(18, 145);
    glVertex2f(20, 150);
    glVertex2f(22, 150);
    glVertex2f(21, 147);
    glVertex2f(20, 145);
    glVertex2f(18, 140);
    glVertex2f(16, 130);
    glVertex2f(13, 120);
    glVertex2f(16, 130);
    glVertex2f(18, 140);
    glVertex2f(20, 145);
    glVertex2f(22, 150);
    glVertex2f(22, 160);
    glVertex2f(18, 150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///........Tree........D-2.......///
    glColor3ub(75, 35, 5);
    glVertex2f(15, 125);
    glVertex2f(19, 130);
    glVertex2f(14, 140);
    glVertex2f(14, 150);
    glVertex2f(13, 160);
    glVertex2f(10, 170);
    glVertex2f(12, 170);
    glVertex2f(12, 160);
    glVertex2f(11, 150);
    glVertex2f(11, 140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);   ///tree...................D-3 p2  ///
    glColor3ub(75, 35, 5);
    glVertex2f(31, 140);
    glVertex2f(29, 140);
    glVertex2f(28, 120);
    glVertex2f(25, 120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///tree..................D-3 p1   ///
    glColor3ub(75, 35, 5);
    glVertex2f(16, 100);
    glVertex2f(21, 100);
    glVertex2f(24.5, 120);
    glVertex2f(28, 120);
    glEnd();

    ///
    glColor3ub(139, 146, 22);
    circle(8, 22, 0, 150);
    glColor3ub(139, 146, 22);
    circle(8, 22, 10, 170);
    glColor3ub(139, 146, 22);
    circle(8, 22, 13, 140);
    glColor3ub(139, 146, 22);
    circle(7, 25, 22, 150);
    glColor3ub(139, 146, 22);
    circle(8, 22, 30, 150);
    glColor3ub(139, 146, 22);
    circle(10, 40, 0, 250);

    glColor3ub(139, 146, 22);
    circle(9, 22, 30, 295);
    glColor3ub(139, 146, 22);
    circle(8, 15, 30, 293);

    glColor3ub(139, 146, 22);
    circle(9, 22, 45, 285);
    glColor3ub(139, 146, 22);
    circle(9, 22, 45, 280);
    glColor3ub(139, 146, 22);
    circle(8, 15, 45, 275);

    glColor3ub(139, 146, 22);
    circle(9, 22, 55, 235);
    glColor3ub(139, 146, 22);
    circle(9, 32, 50, 255);

    glColor3ub(139, 146, 22);
    circle(9, 22, 59, 225);
    glColor3ub(139, 146, 22);
    circle(9, 22, 56, 255);
    glColor3ub(139, 146, 22);
    circle(9, 22, 63, 195);
    glColor3ub(139, 146, 22);
    circle(9, 22, 50, 180);
    glColor3ub(139, 146, 22);
    circle(9, 22, 58, 165);
    glColor3ub(139, 146, 22);
    circle(9, 22, 49, 150);
    glColor3ub(139, 146, 22);
    circle(9, 22, 38, 140);


    glColor3ub(0, 77, 26);
    circle(10, 20, 55, 190);
    glColor3ub(139, 146, 22);
    circle(9.5, 19, 55, 190);


    glColor3ub(0, 77, 26);
    circle(10, 20, 55, 205);
    glColor3ub(139, 146, 22);
    circle(9.5, 20, 55, 205);


    glColor3ub(0, 77, 26);
    circle(10, 20, 50, 218);
    glColor3ub(139, 146, 22);
    circle(9.5, 20, 50, 218);


    glColor3ub(139, 146, 22);
    circle(10, 20, 27, 130);


    glColor3ub(139, 146, 22);
    circle(35, 70, 20, 200);
    glColor3ub(139, 146, 22);    ///
    circle(15, 30, 30, 255);


    glColor3ub(0, 77, 26);
    circle(10, 20, 42, 225);
    glColor3ub(139, 146, 22);
    circle(9.5, 20, 42, 224);


    glColor3ub(0, 77, 26);
    circle(10, 20, 30, 225);
    glColor3ub(139, 146, 22);
    circle(10, 20, 30, 224);


    glColor3ub(0, 77, 26);
    circle(10, 18, 42, 263);
    glColor3ub(139, 146, 22);
    circle(10, 18, 42, 262);


    glColor3ub(0, 77, 26);
    circle(10, 20, 30, 180);
    glColor3ub(139, 146, 22);
    circle(10, 20, 30, 179);

    glColor3ub(0, 77, 26);
    circle(10, 20, 20, 180);
    glColor3ub(139, 146, 22);
    circle(10, 20, 20, 179);

    glColor3ub(0, 77, 26);
    circle(10, 20, 40, 155);
    glColor3ub(139, 146, 22);
    circle(10, 20, 40, 156);


    glColor3ub(139, 146, 22);
    circle(9, 22, 20, 280);
    glColor3ub(0, 77, 26);
    circle(9, 21, 20, 270);
    glColor3ub(139, 146, 22);
    circle(9, 21, 20, 269);


    glColor3ub(139, 146, 22);
    circle(9, 22, 10, 255);
    glColor3ub(0, 77, 26);
    circle(9, 20, 10, 245);
    glColor3ub(139, 146, 22);
    circle(9, 20, 10.5, 244);

}

void render_tree2() {
    //glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(145.0f, 34.0f, 0.0f);
    glScalef(0.22f, 0.50f, 0.0f);
    tree2();
    glPopMatrix();

    //glFlush();
}


void identity_axis() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset the projection matrix
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Reset the modelview matrix if necessary
}


void building1st()
{
    /////////

  //right door//
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(50, 90);
    glVertex2f(110, 90);
    glVertex2f(110, 475);
    glVertex2f(50, 475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(52.5, 90);        //1st Building main part 2
    glVertex2f(106, 90);
    glVertex2f(106, 460);
    glVertex2f(52.5, 460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(110, 90);         //1st Building 2nd part 2
    glVertex2f(140, 90);
    glVertex2f(140, 420);
    glVertex2f(110, 420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(110, 90);         //1st Building 2nd part 1
    glVertex2f(137.5, 90);
    glVertex2f(137.5, 410);
    glVertex2f(110, 410);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(113, 370);   //part 2 1st Building 6th floor2..........outlook
    glVertex2f(137.5, 370);
    glVertex2f(137.5, 400);
    glVertex2f(113, 400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(113, 365);   //part 2 1st Building 6th floor2..........outlook
    glVertex2f(123, 365);
    glVertex2f(123, 400);
    glVertex2f(113, 400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(118, 365);   //Door 1st Building 6th floor2..........outlook-1
    glVertex2f(119, 365);
    glVertex2f(119, 392);
    glVertex2f(118, 392);
    glEnd();

    /////////////****
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 90);  //1st Building 1st floor1
    glVertex2f(197, 90);
    glVertex2f(197, 145);
    glVertex2f(90, 145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 145);   //1st Building 2nd floor1
    glVertex2f(197, 145);
    glVertex2f(197, 200);
    glVertex2f(90, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 200);   //1st Building 3rd floor1
    glVertex2f(197, 200);
    glVertex2f(197, 255);
    glVertex2f(90, 255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 255);   //1st Building 4th floor1
    glVertex2f(197, 255);
    glVertex2f(197, 310);
    glVertex2f(90, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 310);   //1st Building 5th floor1
    glVertex2f(197, 310);
    glVertex2f(197, 365);
    glVertex2f(90, 365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 365);   //1st Building 6th floor1
    glVertex2f(197, 365);
    glVertex2f(197, 420);
    glVertex2f(90, 420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90, 420);   //1st Building 7th floor1
    glVertex2f(197, 420);
    glVertex2f(197, 475);
    glVertex2f(90, 475);
    glEnd();



    glColor3ub(0, 51, 204);
    glRasterPos2i(133, 465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'D');
    glColor3ub(115, 115, 115);
    glRasterPos2i(139, 465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'I');
    glColor3ub(0, 102, 34);
    glRasterPos2i(143, 465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'U');


    glBegin(GL_QUADS);              ///SIRI GHORE.//
    glColor3ub(204, 204, 204);
    glVertex2f(90, 475);
    glVertex2f(120, 475);
    glVertex2f(120, 515);
    glVertex2f(90, 515);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(92, 475);
    glVertex2f(118, 475);
    glVertex2f(118, 510);
    glVertex2f(92, 510);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(100, 475);
    glVertex2f(110, 475);
    glVertex2f(110, 505);
    glVertex2f(100, 505);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(105, 483);
    glVertex2f(106, 483);
    glVertex2f(106, 492);
    glVertex2f(105, 492);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(140, 140, 140);
    glVertex2f(65, 475);
    glVertex2f(66, 475);
    glVertex2f(66, 600);
    glVertex2f(65, 600);
    glEnd();

    glColor3ub(102, 102, 102);
    circle(3, 6, 64, 580);
    glColor3ub(217, 217, 217);
    circle(2.5, 5, 64, 580);
    glColor3ub(102, 102, 102);
    circle(2, 4, 67, 565);
    glColor3ub(217, 217, 217);
    circle(1.5, 3, 67, 565);

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(110, 420);   //part 2 1st Building 7th floor2 white
    glVertex2f(194, 420);
    glVertex2f(194, 460);
    glVertex2f(110, 460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140, 365);   //part 2 1st Building 6th floor2
    glVertex2f(194, 365);
    glVertex2f(194, 405);
    glVertex2f(140, 405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140, 310);   //part 2 1st Building 5th floor2
    glVertex2f(194, 310);
    glVertex2f(194, 350);
    glVertex2f(140, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140, 255);   //part 2 1st Building 4th floor2
    glVertex2f(194, 255);
    glVertex2f(194, 295);
    glVertex2f(140, 295);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140, 200);   //part 2 1st Building 3rd floor2
    glVertex2f(194, 200);
    glVertex2f(194, 240);
    glVertex2f(140, 240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140, 145);   //part 2 1st Building 2nd floor2
    glVertex2f(194, 145);
    glVertex2f(194, 185);
    glVertex2f(140, 185);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140, 90);  //part 2 1st Building 1st floor2
    glVertex2f(194, 90);
    glVertex2f(194, 130);
    glVertex2f(140, 130);
    glEnd();



    ///design of main building....red and glass..............

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 420);  //7 1st Building main part3
    glVertex2f(67, 420);
    glVertex2f(67, 460);
    glVertex2f(52.5, 460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 365);  //6 1st Building main part3
    glVertex2f(67, 365);
    glVertex2f(67, 405);
    glVertex2f(52.5, 405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 310);  //5 1st Building main part3
    glVertex2f(67, 310);
    glVertex2f(67, 350);
    glVertex2f(52.5, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 255);  //4 1st Building main part3
    glVertex2f(67, 255);
    glVertex2f(67, 295);
    glVertex2f(52.5, 295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 200);  //3 1st Building main part3
    glVertex2f(67, 200);
    glVertex2f(67, 240);
    glVertex2f(52.5, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 145);  //2 1st Building main part3
    glVertex2f(67, 145);
    glVertex2f(67, 185);
    glVertex2f(52.5, 185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(52.5, 90);  //1 1st Building main part3
    glVertex2f(67, 90);
    glVertex2f(67, 130);
    glVertex2f(52.5, 130);
    glEnd();
    /////////.....................
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(95, 420);  //7 1st Building main part3
    glVertex2f(106, 420);
    glVertex2f(106, 460);
    glVertex2f(95, 460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(95, 365);  //6 1st Building main part3
    glVertex2f(106, 365);
    glVertex2f(106, 405);
    glVertex2f(95, 405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(95, 310);  //5 1st Building main part3
    glVertex2f(106, 310);
    glVertex2f(106, 350);
    glVertex2f(95, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(95, 255);  //4 1st Building main part3
    glVertex2f(106, 255);
    glVertex2f(106, 295);
    glVertex2f(95, 295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(95, 200);  //3 1st Building main part3
    glVertex2f(106, 200);
    glVertex2f(106, 240);
    glVertex2f(95, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(95, 145);  //2 1st Building main part3
    glVertex2f(106, 145);
    glVertex2f(106, 185);
    glVertex2f(95, 185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(85, 90);  //door
    glVertex2f(106, 90);
    glVertex2f(106, 130);
    glVertex2f(85, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(95, 90);  //door 1 main
    glVertex2f(96, 90);
    glVertex2f(96, 130);
    glVertex2f(95, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(96, 100);  //door 1 main
    glVertex2f(97, 100);
    glVertex2f(97, 120);
    glVertex2f(96, 120);
    glEnd();

    //////////............................

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 420);  //7 1st Building main part3
    glVertex2f(110, 420);
    glVertex2f(110, 421);
    glVertex2f(50, 421);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 365);  //6 1st Building main part3
    glVertex2f(137.5, 365);
    glVertex2f(137.5, 366);
    glVertex2f(50, 366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 310);  //5 1st Building main part3
    glVertex2f(110, 310);
    glVertex2f(110, 311);
    glVertex2f(50, 311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 255);  //4 1st Building main part3
    glVertex2f(110, 255);
    glVertex2f(110, 256);
    glVertex2f(50, 256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 199);  //3 1st Building main part3
    glVertex2f(110, 199);
    glVertex2f(110, 200);
    glVertex2f(50, 200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 145);  //2 1st Building main part3
    glVertex2f(110, 145);
    glVertex2f(110, 146);
    glVertex2f(50, 146);
    glEnd();

    ///////...............................
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 405);  //7 1st Building main part3
    glVertex2f(110, 405);
    glVertex2f(110, 406);
    glVertex2f(50, 406);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 350);  //6 1st Building main part3
    glVertex2f(110, 350);
    glVertex2f(110, 351);
    glVertex2f(50, 351);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 295);  //5 1st Building main part3
    glVertex2f(110, 295);
    glVertex2f(110, 296);
    glVertex2f(50, 296);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 240);  //4  main part3
    glVertex2f(110, 240);
    glVertex2f(110, 241);
    glVertex2f(50, 241);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 185);  //3 1st Building main part3
    glVertex2f(110, 185);
    glVertex2f(110, 186);
    glVertex2f(50, 186);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50, 130);  //2 1st Building main part3
    glVertex2f(110, 130);
    glVertex2f(110, 131);
    glVertex2f(50, 131);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(140, 90);  // part2
    glVertex2f(141, 90);
    glVertex2f(141, 420);
    glVertex2f(140, 420);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(110, 365);  //6 1st Building main part3
    glVertex2f(120, 365);
    glVertex2f(120, 385);
    glVertex2f(110, 385);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(128, 365);  //6 1st Building main part3
    glVertex2f(137.5, 365);
    glVertex2f(137.5, 385);
    glVertex2f(128, 385);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(57, 80, 80);
    glVertex2f(120, 370);  //6 1st Building main part3
    glVertex2f(128, 370);
    glVertex2f(128.5, 372);
    glVertex2f(120, 372);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(57, 80, 80);
    glVertex2f(120, 379);  //6 1st Building main part3
    glVertex2f(128, 379);
    glVertex2f(128.5, 381);
    glVertex2f(120, 381);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(110, 310);  //5 2nd part2
    glVertex2f(137.5, 310);
    glVertex2f(137.5, 350);
    glVertex2f(110, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(110, 255);  //4 2nd part3
    glVertex2f(137.5, 255);
    glVertex2f(137.5, 295);
    glVertex2f(110, 295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(110, 200);  //3 2nd part3
    glVertex2f(137.5, 200);
    glVertex2f(137.5, 240);
    glVertex2f(110, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(110, 145);  //2 2nd part3
    glVertex2f(137.5, 145);
    glVertex2f(137.5, 185);
    glVertex2f(110, 185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(110, 90);  //1 1st Building main part3
    glVertex2f(137.5, 90);
    glVertex2f(137.5, 130);
    glVertex2f(110, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(117, 90);  //1 1st Building main part3
    glVertex2f(118, 90);
    glVertex2f(118, 130);
    glVertex2f(117, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(127, 90);  //1 1st Building main part3
    glVertex2f(128, 90);
    glVertex2f(128, 130);
    glVertex2f(127, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(118, 100);  //1 1st Building main part3
    glVertex2f(119, 100);
    glVertex2f(119, 120);
    glVertex2f(118, 120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(128, 100);  //1 1st Building main part3
    glVertex2f(129, 100);
    glVertex2f(129, 120);
    glVertex2f(128, 120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(110, 90);   //partation
    glVertex2f(111, 90);
    glVertex2f(111, 475);
    glVertex2f(110, 475);
    glEnd();

    //..7th Floor design...................

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(113, 425);   //part 2 1st Building 7th floor2
    glVertex2f(191, 425);
    glVertex2f(191, 455);
    glVertex2f(113, 455);
    glEnd();

    //....door.....window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(113, 420);   //d1 1st Building 7th floor2
    glVertex2f(123, 420);
    glVertex2f(123, 455);
    glVertex2f(113, 455);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(118, 430);   //d1 1st Building 7th floor2
    glVertex2f(119, 430);
    glVertex2f(119, 445);
    glVertex2f(118, 445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(133, 432);   //w1 1st Building 7th floor2
    glVertex2f(153, 432);
    glVertex2f(153, 448);
    glVertex2f(133, 448);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(133.5, 433);   //w1 1st Building 7th floor2
    glVertex2f(152.5, 433);
    glVertex2f(152.5, 447);
    glVertex2f(133.5, 447);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 432);   //w1 1st Building 7th floor2
    glVertex2f(144, 432);
    glVertex2f(144, 448);
    glVertex2f(143, 448);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 432);   //w2 1st Building 7th floor2
    glVertex2f(183, 432);
    glVertex2f(183, 448);
    glVertex2f(163, 448);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 433);   //w2 1st Building 7th floor2
    glVertex2f(182.5, 433);
    glVertex2f(182.5, 447);
    glVertex2f(163.5, 447);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 432);   //w2 1st Building 7th floor2
    glVertex2f(174, 432);
    glVertex2f(174, 448);
    glVertex2f(173, 448);
    glEnd();


    //....6th Floor Design..........Door window

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(141, 370);   //part 2 1st Building 6th floor2..........Inlook
    glVertex2f(191, 370);
    glVertex2f(191, 400);
    glVertex2f(141, 400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(141, 377);   //w1 1st Building 6th floor2
    glVertex2f(153, 377);
    glVertex2f(153, 393);
    glVertex2f(141, 393);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(141, 378);   //w1 1st Building 6th floor2
    glVertex2f(152.5, 378);
    glVertex2f(152.5, 392);
    glVertex2f(141, 392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 377);   //w1 1st Building 6th floor2
    glVertex2f(144, 377);
    glVertex2f(144, 393);
    glVertex2f(143, 393);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 377);   //w2 1st Building 6th floor2
    glVertex2f(183, 377);
    glVertex2f(183, 393);
    glVertex2f(163, 393);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 378);   //w2 1st Building 6th floor2
    glVertex2f(182.5, 378);
    glVertex2f(182.5, 392);
    glVertex2f(163.5, 392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 377);   //w2 1st Building 6th floor2
    glVertex2f(174, 377);
    glVertex2f(174, 393);
    glVertex2f(173, 393);
    glEnd();


    ///5th floor......design

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(141, 315);   //part 2 1st Building 5th floor2.........
    glVertex2f(191, 315);
    glVertex2f(191, 345);
    glVertex2f(141, 345);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(141, 322);   //w1 1st Building 5th floor2
    glVertex2f(153, 322);
    glVertex2f(153, 338);
    glVertex2f(141, 338);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(141, 323);   //w1 1st Building 5th floor2
    glVertex2f(152.5, 323);
    glVertex2f(152.5, 337);
    glVertex2f(141, 337);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 322);   //w1 1st Building 5th floor2
    glVertex2f(144, 322);
    glVertex2f(144, 338);
    glVertex2f(143, 338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 322);   //w2 1st Building 5th floor2
    glVertex2f(183, 322);
    glVertex2f(183, 338);
    glVertex2f(163, 338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 323);   //w2 1st Building 5th floor2
    glVertex2f(182.5, 323);
    glVertex2f(182.5, 337);
    glVertex2f(163.5, 337);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 322);   //w2 1st Building 5th floor2
    glVertex2f(174, 322);
    glVertex2f(174, 338);
    glVertex2f(173, 338);
    glEnd();


    ///....4TH floor design............

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(141, 260);   //part 2 1st Building 5th floor2.........
    glVertex2f(191, 260);
    glVertex2f(191, 290);
    glVertex2f(141, 290);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(141, 267);   //w1 1st Building 4th floor2
    glVertex2f(153, 267);
    glVertex2f(153, 283);
    glVertex2f(141, 283);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(141, 268);   //w1 1st Building 4th floor2
    glVertex2f(152.5, 268);
    glVertex2f(152.5, 282);
    glVertex2f(141, 282);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 267);   //w1 1st Building 4th floor2
    glVertex2f(144, 267);
    glVertex2f(144, 283);
    glVertex2f(143, 283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 267);   //w2 1st Building 4th floor2
    glVertex2f(183, 267);
    glVertex2f(183, 283);
    glVertex2f(163, 283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 268);   //w2 1st Building 4th floor2
    glVertex2f(182.5, 268);
    glVertex2f(182.5, 282);
    glVertex2f(163.5, 282);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 267);   //w2 1st Building 4th floor2
    glVertex2f(174, 267);
    glVertex2f(174, 283);
    glVertex2f(173, 283);
    glEnd();


    ///....3TH floor design............

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(141, 205);   //part 2 1st Building 3th floor2.........
    glVertex2f(191, 205);
    glVertex2f(191, 235);
    glVertex2f(141, 235);
    glEnd();

    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(141, 212);   //w1 1st Building 3rd floor2
    glVertex2f(153, 212);
    glVertex2f(153, 228);
    glVertex2f(141, 228);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(141, 213);   //w1 1st Building 3rd floor2
    glVertex2f(152.5, 213);
    glVertex2f(152.5, 227);
    glVertex2f(141, 227);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 212);   //w1 1st Building 3rd floor2
    glVertex2f(144, 212);
    glVertex2f(144, 228);
    glVertex2f(143, 228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 212);   //w2 1st Building 3rd floor2
    glVertex2f(183, 212);
    glVertex2f(183, 228);
    glVertex2f(163, 228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 213);   //w2 1st Building 3rd floor2
    glVertex2f(182.5, 213);
    glVertex2f(182.5, 227);
    glVertex2f(163.5, 227);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 212);   //w2 1st Building 3rd floor2
    glVertex2f(174, 212);
    glVertex2f(174, 228);
    glVertex2f(173, 228);
    glEnd();


    ///....2nd floor design............

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(141, 150);   //part 2 1st Building 2nd floor2.........
    glVertex2f(191, 150);
    glVertex2f(191, 180);
    glVertex2f(141, 180);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(141, 157);   //w1 1st Building 2nd floor2
    glVertex2f(153, 157);
    glVertex2f(153, 173);
    glVertex2f(141, 173);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(141, 158);   //w1 1st Building 2nd floor2
    glVertex2f(152.5, 158);
    glVertex2f(152.5, 172);
    glVertex2f(141, 172);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 157);   //w1 1st Building 2nd floor2
    glVertex2f(144, 157);
    glVertex2f(144, 173);
    glVertex2f(143, 173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 157);   //w2 1st Building 2nd floor2
    glVertex2f(183, 157);
    glVertex2f(183, 173);
    glVertex2f(163, 173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 158);   //w2 1st Building 2nd floor2
    glVertex2f(182.5, 158);
    glVertex2f(182.5, 172);
    glVertex2f(163.5, 172);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 157);   //w2 1st Building 2nd floor2
    glVertex2f(174, 157);
    glVertex2f(174, 173);
    glVertex2f(173, 173);
    glEnd();


    ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(141, 95);   //part 2 1st Building 1st floor red.........
    glVertex2f(191, 95);
    glVertex2f(191, 125);
    glVertex2f(141, 125);
    glEnd();


    ///....door.....window

    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(196, 90);   //d2 AB2 1st floor
    glVertex2f(206, 90);
    glVertex2f(206, 125);
    glVertex2f(196, 125);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(201, 100);   //d2 1st Building 1st floor
    glVertex2f(202, 100);
    glVertex2f(202, 115);
    glVertex2f(201, 115);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(141, 102);   //w1 1st Building 1st floor2
    glVertex2f(153, 102);
    glVertex2f(153, 118);
    glVertex2f(141, 118);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(141, 103);   //w1 1st Building 1st floor2
    glVertex2f(152.5, 103);
    glVertex2f(152.5, 117);
    glVertex2f(141, 117);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(143, 102);   //w1 1st Building 1st floor2
    glVertex2f(144, 102);
    glVertex2f(144, 118);
    glVertex2f(143, 118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(163, 102);   //w2 1st Building 1st floor2
    glVertex2f(183, 102);
    glVertex2f(183, 118);
    glVertex2f(163, 118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(163.5, 103);   //w2 1st Building 1st floor2
    glVertex2f(182.5, 103);
    glVertex2f(182.5, 117);
    glVertex2f(163.5, 117);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(173, 102);   //w2 1st Building 1st floor2
    glVertex2f(174, 102);
    glVertex2f(174, 118);
    glVertex2f(173, 118);
    glEnd();

}

void render_building1() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(0.0f, 36.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(0.22f, 0.50f, 0.0f); // Scale down to fit the new project's coordinate system
    building1st();
    glPopMatrix();

    //glFlush();
}

void building2_3()
{
    ///2nd building main part/////
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(200, 120);
    glVertex2f(287, 120);
    glVertex2f(287, 395);
    glVertex2f(200, 395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(202.5, 120);        //2nd building main part 2
    glVertex2f(284, 120);
    glVertex2f(284, 380);
    glVertex2f(202.5, 380);
    glEnd();

    ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(205, 125);   //part 2 2nd building 1st floor red.........
    glVertex2f(281, 125);
    glVertex2f(281, 155);
    glVertex2f(205, 155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(281, 125);   //part 2 2nd building 1st floor.......red
    glVertex2f(267, 125);
    glVertex2f(267, 155);
    glVertex2f(281, 155);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205, 120);   //d2 2nd building 1st floor
    glVertex2f(215, 120);
    glVertex2f(215, 155);
    glVertex2f(205, 155);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209, 132);   //d2 2nd building 1st floor
    glVertex2f(210, 132);
    glVertex2f(210, 147);
    glVertex2f(209, 147);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(223, 131);   //w1 2nd building 1st floor2
    glVertex2f(243, 131);
    glVertex2f(243, 147);
    glVertex2f(223, 147);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(223.5, 132);   //w1 2nd building 1st floor2
    glVertex2f(242.5, 132);
    glVertex2f(242.5, 146);
    glVertex2f(223.5, 146);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(233.1, 131);   //w1 2nd building 1st floor2
    glVertex2f(234, 131);
    glVertex2f(234, 147);
    glVertex2f(233.1, 147);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(253, 131);   //w2 2nd building 1st floor2
    glVertex2f(273, 131);
    glVertex2f(273, 147);
    glVertex2f(253, 147);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(253.5, 132);   //w2 2nd building 1st floor2
    glVertex2f(272.5, 132);
    glVertex2f(272.5, 146);
    glVertex2f(253.5, 146);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(263.1, 131);   //w2 2nd building 1st floor2
    glVertex2f(264, 131);
    glVertex2f(264, 147);
    glVertex2f(263.1, 147);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5, 160);  //2nd building 1st floor1
    glVertex2f(284, 160);
    glVertex2f(284, 175);
    glVertex2f(202.5, 175);
    glEnd();

    ///....2nd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(205, 180);   //part 2 2nd building 2nd floor red.........
    glVertex2f(281, 180);
    glVertex2f(281, 210);
    glVertex2f(205, 210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(281, 180);   //part 2 2nd building 2nd floor.......red
    glVertex2f(264, 180);
    glVertex2f(264, 210);
    glVertex2f(281, 210);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205, 175);   //d2 2nd building 2nd floor
    glVertex2f(215, 175);
    glVertex2f(215, 210);
    glVertex2f(205, 210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209, 187);   //d2 2nd building 2nd floor
    glVertex2f(210, 187);
    glVertex2f(210, 202);
    glVertex2f(209, 202);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(223, 186);   //w1 2nd building 2nd floor2
    glVertex2f(243, 186);
    glVertex2f(243, 202);
    glVertex2f(223, 202);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(223.5, 187);   //w1 2nd building 2nd floor2
    glVertex2f(242.5, 187);
    glVertex2f(242.5, 201);
    glVertex2f(223.5, 201);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(233.1, 186);   //w1 2nd building 2nd floor2
    glVertex2f(234, 186);
    glVertex2f(234, 202);
    glVertex2f(233.1, 202);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(253, 186);   //w2 2nd building 2nd floor2
    glVertex2f(273, 186);
    glVertex2f(273, 202);
    glVertex2f(253, 202);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(253.5, 187);   //w2 2nd building 2nd floor2
    glVertex2f(272.5, 187);
    glVertex2f(272.5, 201);
    glVertex2f(253.5, 201);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(263.1, 186);   //w2 2nd building 2nd floor2
    glVertex2f(264, 186);
    glVertex2f(264, 202);
    glVertex2f(263.1, 202);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5, 215);  //2nd building 2nd floor1
    glVertex2f(284, 215);
    glVertex2f(284, 230);
    glVertex2f(202.5, 230);
    glEnd();

    ///....3rd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(205, 235);   //part 2 2nd building 3rd floor red.........
    glVertex2f(281, 235);
    glVertex2f(281, 265);
    glVertex2f(205, 265);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(281, 235);   //part 2 2nd building 3rd floor.......red
    glVertex2f(264, 235);
    glVertex2f(264, 265);
    glVertex2f(281, 265);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205, 230);   //d2 2nd building 3rd floor
    glVertex2f(215, 230);
    glVertex2f(215, 265);
    glVertex2f(205, 265);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209, 242);   //d2 2nd building 2nd floor
    glVertex2f(210, 242);
    glVertex2f(210, 257);
    glVertex2f(209, 257);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(223, 241);   //w1 2nd building 3rd floor2
    glVertex2f(243, 241);
    glVertex2f(243, 257);
    glVertex2f(223, 257);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(223.5, 242);   //w1 2nd building 2nd floor2
    glVertex2f(242.5, 242);
    glVertex2f(242.5, 256);
    glVertex2f(223.5, 256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(233.1, 241);   //w1 2nd building 3rd floor2
    glVertex2f(234, 241);
    glVertex2f(234, 257);
    glVertex2f(233.1, 257);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(253, 241);   //w2 2nd building 3rd floor2
    glVertex2f(273, 241);
    glVertex2f(273, 257);
    glVertex2f(253, 257);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(253.5, 242);   //w2 2nd building 3rd floor2
    glVertex2f(272.5, 242);
    glVertex2f(272.5, 256);
    glVertex2f(253.5, 256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(263.1, 241);   //w2 2nd building 3rd floor2
    glVertex2f(264, 241);
    glVertex2f(264, 257);
    glVertex2f(263.1, 257);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5, 270);  //2nd building 3rd floor1
    glVertex2f(284, 270);
    glVertex2f(284, 285);
    glVertex2f(202.5, 285);
    glEnd();

    ///....4th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(205, 290);   //part 2 2nd building 4th floor red.........
    glVertex2f(281, 290);
    glVertex2f(281, 320);
    glVertex2f(205, 320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(281, 290);   //part 2 2nd building 4th floor.......red
    glVertex2f(264, 290);
    glVertex2f(264, 320);
    glVertex2f(281, 320);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205, 285);   //d2 2nd building 4th floor
    glVertex2f(215, 285);
    glVertex2f(215, 320);
    glVertex2f(205, 320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209, 297);   //d2 2nd building 5th floor
    glVertex2f(210, 297);
    glVertex2f(210, 312);
    glVertex2f(209, 312);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(223, 296);   //w1 2nd building 4th floor2
    glVertex2f(243, 296);
    glVertex2f(243, 312);
    glVertex2f(223, 312);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(223.5, 297);   //w1 2nd building 4th floor2
    glVertex2f(242.5, 297);
    glVertex2f(242.5, 311);
    glVertex2f(223.5, 311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(233.1, 296);   //w1 2nd building 4th floor2
    glVertex2f(234, 296);
    glVertex2f(234, 312);
    glVertex2f(233.1, 312);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(253, 297);   //w2 2nd building 4th floor2
    glVertex2f(273, 297);
    glVertex2f(273, 312);
    glVertex2f(253, 312);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(253.5, 297);   //w2 2nd building 4th floor2
    glVertex2f(272.5, 297);
    glVertex2f(272.5, 311);
    glVertex2f(253.5, 311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(263.1, 297);   //w2 2nd building 4th floor2
    glVertex2f(264, 297);
    glVertex2f(264, 312);
    glVertex2f(263.1, 312);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5, 325);  //2nd building 4th floor1
    glVertex2f(284, 325);
    glVertex2f(284, 340);
    glVertex2f(202.5, 340);
    glEnd();

    ///....5th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(205, 345);   //part 2 2nd building 5th floor red.........
    glVertex2f(281, 345);
    glVertex2f(281, 375);
    glVertex2f(205, 375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(281, 345);   //part 2 2nd building 5th floor.......red
    glVertex2f(264, 345);
    glVertex2f(264, 375);
    glVertex2f(281, 375);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205, 340);   //d2 2nd building 5th floor
    glVertex2f(215, 340);
    glVertex2f(215, 375);
    glVertex2f(205, 375);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209, 352);   //d2 2nd building 5th floor
    glVertex2f(210, 352);
    glVertex2f(210, 367);
    glVertex2f(209, 367);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(223, 351);   //w1 2nd building 5th floor2
    glVertex2f(243, 351);
    glVertex2f(243, 367);
    glVertex2f(223, 367);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(223.5, 352);   //w1 2nd building 5th floor2
    glVertex2f(242.5, 352);
    glVertex2f(242.5, 366);
    glVertex2f(223.5, 366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(233.1, 351);   //w1 2nd building 5th floor2
    glVertex2f(234, 351);
    glVertex2f(234, 367);
    glVertex2f(233.1, 367);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(253, 352);   //w2 2nd building 4th floor2
    glVertex2f(273, 352);
    glVertex2f(273, 367);
    glVertex2f(253, 367);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 197, 215);
    glVertex2f(253.5, 352);   //w2 2nd building 5th floor2
    glVertex2f(272.5, 352);
    glVertex2f(272.5, 366);
    glVertex2f(253.5, 366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(263.1, 352);   //w2 2nd building 5th floor2
    glVertex2f(264, 352);
    glVertex2f(264, 367);
    glVertex2f(263.1, 367);
    glEnd();
    ///End 2nd building//

    ///Tower 2nd Building//
    glBegin(GL_QUADS);
    glColor3ub(140, 140, 140);
    glVertex2f(273, 395);
    glVertex2f(274, 395);
    glVertex2f(274, 520);
    glVertex2f(273, 520);
    glEnd();

    glColor3ub(102, 102, 102);
    circle(3, 6, 273, 500);
    glColor3ub(217, 217, 217);
    circle(2.5, 5, 273, 500);
    glColor3ub(102, 102, 102);
    circle(2, 4, 276, 485);
    glColor3ub(217, 217, 217);
    circle(1.5, 3, 276, 485);
    //Tower End//

    glBegin(GL_TRIANGLE_FAN); ///triangle tree 2nd Building///
    glColor3ub(75, 35, 5);
    glVertex2f(290, 90);
    glVertex2f(295, 90);
    glVertex2f(295, 120);
    glVertex2f(290, 120);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(280, 120);
    glVertex2f(305, 120);
    glVertex2f(292.5, 180);
    glVertex2f(292.5, 180);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(281, 135);
    glVertex2f(304, 135);
    glVertex2f(292.5, 190);
    glVertex2f(292.5, 190);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(282, 150);
    glVertex2f(303, 150);
    glVertex2f(292.5, 180);
    glVertex2f(292.5, 180);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(283, 160);
    glVertex2f(302, 160);
    glVertex2f(292.5, 190);
    glVertex2f(292.5, 190);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(284, 170);
    glVertex2f(301, 170);
    glVertex2f(292.5, 200);
    glVertex2f(292.5, 200);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(285, 180);
    glVertex2f(300, 180);
    glVertex2f(292.5, 210);
    glVertex2f(292.5, 210);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(286, 190);
    glVertex2f(299, 190);
    glVertex2f(292.5, 260);
    glVertex2f(292.5, 260);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(286, 200);
    glVertex2f(299, 200);
    glVertex2f(292.5, 270);
    glVertex2f(292.5, 270);
    glEnd();


    ///3rd Building Foodcourt



      //glClear(GL_COLOR_BUFFER_BIT);

     ///5th Building Food Court///
    /// Food court big Right part///
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);///Food Court main part 2
    glVertex2f(373, 90);
    glVertex2f(466, 90);
    glVertex2f(466, 442);
    glVertex2f(373, 442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(91, 102, 108);
    glVertex2f(377.5, 90);        ///Food Court main part 2
    glVertex2f(461, 90);
    glVertex2f(461, 440);
    glVertex2f(377.5, 440);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(282.5, 270);  ///Middle divided left right
    glVertex2f(466, 270);
    glVertex2f(466, 281);
    glVertex2f(282.5, 281);
    glEnd();

    ///stairs//Top
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(371, 442);  ///3//
    glVertex2f(467.5, 442);
    glVertex2f(467.5, 451);
    glVertex2f(371, 451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(20, 25, 33);
    glVertex2f(371, 454);  ///2//
    glVertex2f(467.5, 454);
    glVertex2f(467.5, 451);
    glVertex2f(371, 451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(367, 454);  ///1//
    glVertex2f(471.5, 454);
    glVertex2f(471.5, 463);
    glVertex2f(367, 463);
    glEnd();

    ///stairs Top End//

    glBegin(GL_QUADS);
    glColor3ub(72, 85, 93);
    glVertex2f(377.5, 433);
    glVertex2f(461, 433);
    glVertex2f(461, 440);
    glVertex2f(377.5, 440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382, 290);        ///black Food Court Right part
    glVertex2f(457, 290);
    glVertex2f(457, 429);
    glVertex2f(382, 429);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(383.5, 293.6);        /// white color Food Court Right part
    glVertex2f(455.4, 293.6);
    glVertex2f(455.4, 425.4);
    glVertex2f(383.5, 425.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382, 314.2);  ///middle line 2
    glVertex2f(457, 314.2);
    glVertex2f(457, 310.2);
    glVertex2f(382, 310.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(368, 409.1);  ///middle line 1
    glVertex2f(457, 409.1);
    glVertex2f(457, 405.1);
    glVertex2f(368, 405.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(368, 429.1);  ///middle line for sign board
    glVertex2f(382, 429.1);
    glVertex2f(382, 426);
    glVertex2f(368, 426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(402, 290);   ///partation of Blue line
    glVertex2f(400.6, 290);
    glVertex2f(400.6, 426);
    glVertex2f(402, 426);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(420, 290);   ///partation of Blue line
    glVertex2f(418.6, 290);
    glVertex2f(418.6, 426);
    glVertex2f(420, 426);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(438, 290);   ///partation of Blue line
    glVertex2f(436.5, 290);
    glVertex2f(436.5, 426);
    glVertex2f(438, 426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(388.5, 255.6);        ///  Food Court board Black
    glVertex2f(450.2, 255.6);
    glVertex2f(450.2, 283.4);
    glVertex2f(388.5, 283.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(182, 138, 94);
    glVertex2f(386.5, 258.3);        /// Food Court board
    glVertex2f(448.3, 258.3);
    glVertex2f(448.3, 287);
    glVertex2f(386.5, 287);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5, 281.2);  ///middle line 1
    glVertex2f(448.3, 281.2);
    glVertex2f(448.3, 279);
    glVertex2f(386.5, 279);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5, 273.2);  ///middle line 1
    glVertex2f(448.3, 273.2);
    glVertex2f(448.3, 271);
    glVertex2f(386.5, 271);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5, 265.2);  ///middle line 1
    glVertex2f(448.3, 265.2);
    glVertex2f(448.3, 263);
    glVertex2f(386.5, 263);
    glEnd();

    glColor3ub(31, 46, 53);
    glRasterPos2i(400, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'H');
    glColor3ub(31, 46, 53);
    glRasterPos2i(404, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'O');
    glColor3ub(31, 46, 53);
    glRasterPos2i(408, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'T');
    glColor3ub(31, 46, 53);
    glRasterPos2i(412, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'E');
    glColor3ub(31, 46, 53);
    glRasterPos2i(416, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'L');
    glColor3ub(31, 46, 53);
    glRasterPos2i(420, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, ' ');
    glColor3ub(31, 46, 53);
    glRasterPos2i(424, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'R');
    glColor3ub(31, 46, 53);
    glRasterPos2i(428, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'E');
    glColor3ub(31, 46, 53);
    glRasterPos2i(432, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'L');
    glColor3ub(31, 46, 53);
    glRasterPos2i(436, 270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');

    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6, 241.4);  ///middle line
    glVertex2f(460.9, 241.4);
    glVertex2f(460.9, 239.2);
    glVertex2f(377.6, 239.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6, 230.4);  ///middle line
    glVertex2f(460.9, 230.4);
    glVertex2f(460.9, 228.2);
    glVertex2f(377.6, 228.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6, 220.4);  ///middle line
    glVertex2f(460.9, 220.4);
    glVertex2f(460.9, 218.2);
    glVertex2f(377.6, 218.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6, 210.5);  ///middle line
    glVertex2f(460.9, 210.5);
    glVertex2f(460.9, 208.4);
    glVertex2f(377.6, 208.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6, 200.5);  ///middle line
    glVertex2f(460.9, 200.5);
    glVertex2f(460.9, 198.4);
    glVertex2f(377.6, 198.4);
    glEnd();

    ///Door///
    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(397, 110);        ///black color Food court door
    glVertex2f(442, 110);
    glVertex2f(442, 230);
    glVertex2f(397, 230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(398.5, 110);        /// Food Court black color
    glVertex2f(440, 110);
    glVertex2f(440, 226.5);
    glVertex2f(398.5, 226.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 242, 205);
    glVertex2f(401.5, 110);        /// Food Court Right part
    glVertex2f(437, 110);
    glVertex2f(437, 220.5);
    glVertex2f(401.5, 220.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(399, 118.7);  ///
    glVertex2f(440, 118.7);
    glVertex2f(440, 124.6);
    glVertex2f(399, 124.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(420, 110);   ///partation of Blue line
    glVertex2f(416.6, 110);
    glVertex2f(416.6, 226);
    glVertex2f(420, 226);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(421, 110);   ///partation
    glVertex2f(419.6, 110);
    glVertex2f(419.6, 226);
    glVertex2f(421, 226);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(424, 110);   ///partation of Blue line
    glVertex2f(420.6, 110);
    glVertex2f(420.6, 226);
    glVertex2f(424, 226);
    glEnd();


    ///End Right part///

    ///Food Court left part
    glBegin(GL_QUADS);
    glColor3ub(91, 102, 108);///Food Court small left part
    glVertex2f(288, 110);
    glVertex2f(373, 110);
    glVertex2f(373, 270);
    glVertex2f(288, 270);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(293, 120);        ///black Food Court small left part
    glVertex2f(368, 120);
    glVertex2f(368, 259);
    glVertex2f(293, 259);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(295, 124);        /// white color Food Court small left part
    glVertex2f(366, 124);
    glVertex2f(366, 256);
    glVertex2f(295, 256);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(294.5, 190);  ///middle line
    glVertex2f(368, 190);
    glVertex2f(368, 187);
    glVertex2f(294.5, 187);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(350, 120);   ///partation of Blue line
    glVertex2f(348.6, 120);
    glVertex2f(348.6, 256);
    glVertex2f(350, 256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(332, 120);   ///partation of Blue line
    glVertex2f(330.6, 120);
    glVertex2f(330.6, 256);
    glVertex2f(332, 256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(314, 120);   ///partation of Blue line
    glVertex2f(312.6, 120);
    glVertex2f(312.6, 256);
    glVertex2f(314, 256);
    glEnd();

    ///top Boundary
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(284.3, 280);   ///partation of Blue line
    glVertex2f(282.5, 280);
    glVertex2f(282.5, 321);
    glVertex2f(284.3, 321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(302, 280);   ///partation of Blue line
    glVertex2f(300.2, 280);
    glVertex2f(300.2, 321);
    glVertex2f(302, 321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(320, 280);   ///partation of Blue line
    glVertex2f(318.2, 280);
    glVertex2f(318.2, 321);
    glVertex2f(320, 321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(338, 280);   ///partation of Blue line
    glVertex2f(336.1, 280);
    glVertex2f(336.1, 321);
    glVertex2f(338, 321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(356, 280);   ///partation of Blue line
    glVertex2f(354.2, 280);
    glVertex2f(354.2, 321);
    glVertex2f(356, 321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(373, 280);   ///partation of Blue line
    glVertex2f(371.2, 280);
    glVertex2f(371.2, 321);
    glVertex2f(373, 321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5, 314);  ///middle line
    glVertex2f(372, 314);
    glVertex2f(372, 309.6);
    glVertex2f(282.5, 309.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5, 304);  ///middle line
    glVertex2f(372, 304);
    glVertex2f(372, 300);
    glVertex2f(282.5, 300);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5, 294);  ///middle line
    glVertex2f(372, 294);
    glVertex2f(372, 290);
    glVertex2f(282.5, 290);
    glEnd();
    ///End top Boundary//
    ///End left part//



    ///stairs//
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(284, 90);  ///Bottom3
    glVertex2f(471.5, 90);
    glVertex2f(471.5, 99);
    glVertex2f(284, 99);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(20, 25, 33);
    glVertex2f(286, 102);  ///middle2
    glVertex2f(468, 102);
    glVertex2f(468, 99);
    glVertex2f(286, 99);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(286, 102);  ///Top1
    glVertex2f(468, 102);
    glVertex2f(468, 110);
    glVertex2f(286, 110);
    glEnd();

    ///stairs End//

}

void render_building2_3() {///both 2 and 3 building
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(0.0f, 35.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(0.22f, 0.50f, 0.0f); // Scale down to fit the new project's coordinate system
    building2_3();
    glPopMatrix();

    glFlush();
}

///4th building
void building4()
{


    ///4th Building Design///Top
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);///4th Building main part 2
    glVertex2f(483.5, 440);
    glVertex2f(555.2, 440);
    glVertex2f(555.2, 472);
    glVertex2f(483.5, 472);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(483.5, 440);        ///4th Building main part 2
    glVertex2f(555.2, 440);
    glVertex2f(555.2, 467);
    glVertex2f(483.5, 467);
    glEnd();
    ///white part///
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);///4th Building main part 2
    glVertex2f(475, 119);
    glVertex2f(563.5, 119);
    glVertex2f(563.5, 442);
    glVertex2f(475, 442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(477.5, 119);        ///4th Building main part 2
    glVertex2f(561, 119);
    glVertex2f(561, 434);
    glVertex2f(477.5, 434);
    glEnd();

    ///floor divided y+40//
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 150);  ///4th Building 1st floor1
    glVertex2f(563, 150);
    glVertex2f(563, 154);
    glVertex2f(475, 154);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 190);  ///4th Building 2nd floor1
    glVertex2f(563, 190);
    glVertex2f(563, 193);
    glVertex2f(475, 193);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 230);  ///4th Building 3rd floor1
    glVertex2f(563, 230);
    glVertex2f(563, 234);
    glVertex2f(475, 234);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 270);  ///4th Building 4th floor1
    glVertex2f(563, 270);
    glVertex2f(563, 273);
    glVertex2f(475, 273);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 310);  ///4th Building 5th floor1
    glVertex2f(563, 310);
    glVertex2f(563, 314);
    glVertex2f(475, 314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 310);  ///4th Building 6th floor1
    glVertex2f(563, 310);
    glVertex2f(563, 314);
    glVertex2f(475, 314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 350);  ///4th Building 7th floor1
    glVertex2f(563, 350);
    glVertex2f(563, 353);
    glVertex2f(475, 353);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475, 390);  ///4th Building 8th floor1
    glVertex2f(563, 390);
    glVertex2f(563, 394);
    glVertex2f(475, 394);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(491, 119);  /// 4th Building white line vertical
    glVertex2f(491.5, 119);
    glVertex2f(491.5, 440);
    glVertex2f(491, 440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(505, 119);  /// 4th Building white line vertical
    glVertex2f(505.5, 119);
    glVertex2f(505.5, 440);
    glVertex2f(505, 440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(519, 119);  /// 4th Building white line vertical
    glVertex2f(519.5, 119);
    glVertex2f(519.5, 440);
    glVertex2f(519, 440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(533, 119);  /// 4th Building white line vertical
    glVertex2f(533.5, 119);
    glVertex2f(533.5, 440);
    glVertex2f(533, 440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(547, 119);  /// 4th Building white line vertical
    glVertex2f(547.5, 119);
    glVertex2f(547.5, 440);
    glVertex2f(547, 440);
    glEnd();

    ///Door
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(505, 140);  ///4th Building 1st floor1
    glVertex2f(533, 140);
    glVertex2f(533, 144);
    glVertex2f(505, 144);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(532, 119);  /// 4th Building white line vertical
    glVertex2f(533.6, 119);
    glVertex2f(533.6, 140);
    glVertex2f(532, 140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(518, 119);  /// 4th Building white line vertical
    glVertex2f(519.6, 119);
    glVertex2f(519.6, 140);
    glVertex2f(518, 140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(505, 119);  ///4th Building white line vertical
    glVertex2f(506.6, 119);
    glVertex2f(506.6, 140);
    glVertex2f(505, 140);
    glEnd();
    ///End 4th Building///

    ///Hospital signboard

    glColor3ub(0, 51, 204);
    glRasterPos2i(504, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'H');
    glColor3ub(0, 51, 204);
    glRasterPos2i(509, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'O');
    glColor3ub(0, 51, 204);
    glRasterPos2i(513, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'T');
    glColor3ub(0, 51, 204);
    glRasterPos2i(517, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'E');
    glColor3ub(0, 51, 204);
    glRasterPos2i(521, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'L');
    glColor3ub(0, 51, 204);
    glRasterPos2i(525, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, ' ');
    glColor3ub(0, 51, 204);
    glRasterPos2i(529, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, '5');
    glColor3ub(0, 51, 204);
    glRasterPos2i(534, 455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, '*');
    ///End//


}
void render_building4() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(0.0f, 21.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(0.22f, 0.50f, 0.0f); // Scale down to fit the new project's coordinate system
    building4();
    glPopMatrix();

    glFlush();
}

///5th building

void building5()
{
    ///5th Building Design///
///white part///
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(575, 90);
    glVertex2f(635, 90);
    glVertex2f(635, 475);
    glVertex2f(575, 475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(577.5, 90);        //3rd Building main part 2
    glVertex2f(631, 90);
    glVertex2f(631, 460);
    glVertex2f(577.5, 460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(635, 90);         //3rd Building 2nd part 2
    glVertex2f(665, 90);
    glVertex2f(665, 420);
    glVertex2f(635, 420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(635, 90);         //3rd Building 2nd part 1
    glVertex2f(662.5, 90);
    glVertex2f(662.5, 410);
    glVertex2f(635, 410);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(637, 370);   //part 2 3rd Building 6th floor2..........outlook
    glVertex2f(662.5, 370);
    glVertex2f(662.5, 400);
    glVertex2f(637, 400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(638, 365);   //part 2 3rd Building 6th floor2..........outlook
    glVertex2f(648, 365);
    glVertex2f(648, 400);
    glVertex2f(638, 400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(643, 365);   //Door 3rd Building 6th floor2..........outlook-1
    glVertex2f(644, 365);
    glVertex2f(644, 392);
    glVertex2f(643, 392);
    glEnd();

    /////////////****
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 90); //3rd Building 3rd Building floor1
    glVertex2f(667, 90);
    glVertex2f(667, 145);
    glVertex2f(615, 145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 145);   //3rd Building 2nd floor1
    glVertex2f(667, 145);
    glVertex2f(667, 200);
    glVertex2f(615, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 200);   //3rd Building 3rd floor1
    glVertex2f(667, 200);
    glVertex2f(667, 255);
    glVertex2f(615, 255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 255);   //3rd Building 4th floor1
    glVertex2f(667, 255);
    glVertex2f(667, 310);
    glVertex2f(615, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 310);   //3rd Building 5th floor1
    glVertex2f(667, 310);
    glVertex2f(667, 365);
    glVertex2f(615, 365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 365);   //3rd Building 6th floor1
    glVertex2f(667, 365);
    glVertex2f(667, 420);
    glVertex2f(615, 420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615, 420);   //3rd Building 7th floor1
    glVertex2f(667, 420);
    glVertex2f(667, 475);
    glVertex2f(615, 475);
    glEnd();

    ///design of main building....red and glass....

    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 420);  //7 3rd Building main part3
    glVertex2f(592, 420);
    glVertex2f(592, 460);
    glVertex2f(577.5, 460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 365);  //6 3rd Building main part3
    glVertex2f(592, 365);
    glVertex2f(592, 405);
    glVertex2f(577.5, 405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 310);  //5 3rd Building main part3
    glVertex2f(592, 310);
    glVertex2f(592, 350);
    glVertex2f(577.5, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 255);  //4 3rd Building main part3
    glVertex2f(592, 255);
    glVertex2f(592, 295);
    glVertex2f(577.5, 295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 200);  //3 3rd Building main part3
    glVertex2f(592, 200);
    glVertex2f(592, 240);
    glVertex2f(577.5, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 145);  //2 3rd Building main part3
    glVertex2f(592, 145);
    glVertex2f(592, 185);
    glVertex2f(577.5, 185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 124, 119);
    glVertex2f(577.5, 90);  //1 3rd Building main part3
    glVertex2f(592, 90);
    glVertex2f(592, 130);
    glVertex2f(577.5, 130);
    glEnd();
    /////////.....................
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(620, 420);  //7 3rd Building main part3
    glVertex2f(631, 420);
    glVertex2f(631, 460);
    glVertex2f(620, 460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(620, 365);  //6 3rd Building main part3
    glVertex2f(631, 365);
    glVertex2f(631, 405);
    glVertex2f(620, 405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(620, 310);  //5 3rd Building main part3
    glVertex2f(631, 310);
    glVertex2f(631, 350);
    glVertex2f(620, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(620, 255);  //4 3rd Building main part3
    glVertex2f(631, 255);
    glVertex2f(631, 295);
    glVertex2f(620, 295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(620, 200);  //3 3rd Building main part3
    glVertex2f(631, 200);
    glVertex2f(631, 240);
    glVertex2f(620, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(620, 145);  //2 3rd Building main part3
    glVertex2f(631, 145);
    glVertex2f(631, 185);
    glVertex2f(620, 185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(610, 90);  //door
    glVertex2f(631, 90);
    glVertex2f(631, 130);
    glVertex2f(610, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(620, 90);  //door 1 main
    glVertex2f(621, 90);
    glVertex2f(621, 130);
    glVertex2f(620, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(621, 100);  //door 1 main
    glVertex2f(622, 100);
    glVertex2f(622, 120);
    glVertex2f(621, 120);
    glEnd();

    //////////............................

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 420);  //7 3rd Building main part3
    glVertex2f(635, 420);
    glVertex2f(635, 421);
    glVertex2f(575, 421);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 365);  //6 3rd Building main part3
    glVertex2f(662.5, 365);
    glVertex2f(662.5, 366);
    glVertex2f(575, 366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 310);  //5 3rd Building main part3
    glVertex2f(635, 310);
    glVertex2f(635, 311);
    glVertex2f(575, 311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 255);  //4 3rd Building main part3
    glVertex2f(635, 255);
    glVertex2f(635, 256);
    glVertex2f(575, 256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 199);  //3 3rd Building main part3
    glVertex2f(635, 199);
    glVertex2f(635, 200);
    glVertex2f(575, 200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 145);  //2 3rd Building main part3
    glVertex2f(635, 145);
    glVertex2f(635, 146);
    glVertex2f(575, 146);
    glEnd();

    ///////...............................
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 405);  //7 3rd Building main part3
    glVertex2f(635, 405);
    glVertex2f(635, 406);
    glVertex2f(575, 406);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 350);  //6 3rd Building main part3
    glVertex2f(635, 350);
    glVertex2f(635, 351);
    glVertex2f(575, 351);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 295);  //5 3rd Building main part3
    glVertex2f(635, 295);
    glVertex2f(635, 296);
    glVertex2f(575, 296);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 240);  //4 3rd Building main part3
    glVertex2f(635, 240);
    glVertex2f(635, 241);
    glVertex2f(575, 241);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 185);  //3 3rd Building main part3
    glVertex2f(635, 185);
    glVertex2f(635, 186);
    glVertex2f(575, 186);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575, 130);  //2 3rd Building main part3
    glVertex2f(635, 130);
    glVertex2f(635, 131);
    glVertex2f(575, 131);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(665, 90);  // part2 last black line
    glVertex2f(666, 90);
    glVertex2f(666, 460);
    glVertex2f(665, 460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(635, 420);  //7 2nd part3
    glVertex2f(662.5, 420);
    glVertex2f(662.5, 460);
    glVertex2f(635, 460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(635, 365);  //6 2nd part3
    glVertex2f(662.5, 365);
    glVertex2f(662.5, 405);
    glVertex2f(635, 405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(635, 310);  //5 part3
    glVertex2f(662.5, 310);
    glVertex2f(662.5, 350);
    glVertex2f(635, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(635, 255);  //4 2nd part3
    glVertex2f(662.5, 255);
    glVertex2f(662.5, 295);
    glVertex2f(635, 295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(635, 200);  //3 2nd part3
    glVertex2f(662.5, 200);
    glVertex2f(662.5, 240);
    glVertex2f(635, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85, 119, 119);
    glVertex2f(635, 145);  //2 2nd part3
    glVertex2f(662.5, 145);
    glVertex2f(662.5, 185);
    glVertex2f(635, 185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143, 175, 175);
    glVertex2f(635, 90);  //1 3rd Building main part3
    glVertex2f(662.5, 90);
    glVertex2f(662.5, 130);
    glVertex2f(635, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(642, 90);  //1 main part3
    glVertex2f(643, 90);
    glVertex2f(643, 130);
    glVertex2f(642, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(652, 90);  //1 main part3
    glVertex2f(653, 90);
    glVertex2f(653, 130);
    glVertex2f(652, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(643, 100);  //1 main part3
    glVertex2f(644, 100);
    glVertex2f(644, 120);
    glVertex2f(643, 120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(653, 100);  ///1 main part3
    glVertex2f(654, 100);
    glVertex2f(654, 120);
    glVertex2f(653, 120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(635, 90);   ///partation of Blue line
    glVertex2f(636, 90);
    glVertex2f(636, 460);
    glVertex2f(635, 460);
    glEnd();

    ///End 5 Building//


}

void render_building5() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(0.0f, 35.0f, 0.0f);
    glScalef(0.22f, 0.50f, 0.0f);
    building5();
    glPopMatrix();

    glFlush();
}


void sun() {

    glColor3ub(253, 183, 77);    ///.........S U N.....................///
    circle(18, 36, 400, 705);
    glColor3ub(253, 183, 77);
    circle(16.5, 33, 400, 705);
    glColor3ub(253, 183, 77);
    circle(14.5, 30, 400, 705);
    glColor3ub(253, 183, 77);
    circle(12.5, 27, 400, 705);

}
void update_sun_position(int value) {
    move_sun += 0.05f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_sun > 250.0f) { // Adjust this value as needed
        move_sun = -75.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_sun_position, 0);
}

void render_sun() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.0f, 10.0f + move_sun, 0.0f); // Translate to the building's original position in the old project
    glScalef(0.22f, 0.50f, 0.0f); // Scale down to fit the new project's coordinate system
    sun();
    glPopMatrix();

    //glFlush();
}

//-------------moon------------------
void moon() {

    glColor3f(1, 1, 1);    ///.........S U N.....................///
    circle(18, 36, 400, 705);
    glColor3f(1, 1, 1);
    circle(16.5, 33, 400, 705);
    glColor3f(1, 1, 1);
    circle(14.5, 30, 400, 705);
    glColor3f(1, 1, 1);
    circle(12.5, 27, 400, 705);

}
void update_moon_position(int value) {
    move_moon += 0.05f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_moon < 20.0f) { // Adjust this value as needed
        move_moon = 40.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_moon_position, 0);
}

void render_moon() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.0f, 10.0f, 0.0f);
    glScalef(0.22f, 0.50f, 0.0f);
    moon();
    glPopMatrix();

    //glFlush();
}



void cloud()  //id20
{



    glColor3ub(232, 241, 255);        ///....Megh.......1 covering sun....///
    circle(13, 20, 400, 665);
    glColor3ub(252, 254, 255);
    circle(11, 18, 400, 665);

    glColor3ub(232, 241, 255);
    circle(10, 20, 410, 675);
    glColor3ub(252, 254, 255);
    circle(10, 20, 412, 672);

    glColor3ub(232, 241, 255);
    circle(13, 20, 410, 655);

    glColor3ub(221, 229, 247);
    circle(9, 20, 420, 680);
    glColor3ub(252, 254, 255);
    circle(8, 18, 420, 679);

    glColor3ub(232, 241, 255);
    circle(9, 20, 420, 650);
    glColor3ub(252, 254, 255);
    circle(8, 18, 420, 652);

    glColor3ub(221, 229, 247);
    circle(9, 20, 430, 685);
    glColor3ub(252, 254, 255);
    circle(8, 18, 430, 683);

    glColor3ub(232, 241, 255);
    circle(9, 20, 425, 655);
    glColor3ub(252, 254, 255);
    circle(8, 18, 435, 657);

    glColor3ub(232, 241, 255);
    circle(9, 20, 440, 675);

    glColor3ub(221, 229, 247);
    circle(8, 18, 445, 665);
    glColor3ub(252, 254, 255);
    circle(8, 18, 443, 663);
    glColor3ub(252, 254, 255);
    circle(18, 18, 420, 664);
    glColor3ub(252, 254, 255);
    circle(18, 25, 417, 665);


    float p = -10;

    glColor3ub(232, 241, 255);        ///....Megh.......2.....///
    circle(13, 20, p + 200, 745);
    glColor3ub(252, 254, 255);
    circle(11, 18, p + 200, 745);

    glColor3ub(232, 241, 255);
    circle(10, 20, p + 210, 755);
    glColor3ub(252, 254, 255);
    circle(10, 20, p + 212, 762);

    glColor3ub(232, 241, 255);
    circle(13, 20, p + 210, 735);

    glColor3ub(221, 229, 247);
    circle(9, 20, p + 220, 750);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 220, 759);

    glColor3ub(232, 241, 255);
    circle(9, 20, p + 220, 756);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 220, 752);

    glColor3ub(232, 241, 255);
    circle(9, 20, p + 230, 765);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 230, 761);

    glColor3ub(232, 241, 255);
    circle(9, 20, p + 225, 745);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 235, 747);

    glColor3ub(232, 241, 255);
    circle(9, 20, p + 240, 755);

    glColor3ub(221, 229, 247);
    circle(8, 18, p + 243, 745);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 240, 743);
    glColor3ub(173, 197, 224);
    circle(8, 18, p + 230, 733);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 230, 738);
    glColor3ub(173, 197, 224);
    circle(8, 18, p + 220, 723);
    glColor3ub(252, 254, 255);
    circle(8, 18, p + 220, 728);



    glColor3ub(252, 254, 255);
    circle(23, 9, p + 245, 744);
    glColor3ub(173, 197, 224);
    circle(21, 10, p + 240, 720);
    glColor3ub(252, 254, 255);
    circle(21, 11, p + 238, 723);


    glColor3ub(252, 254, 255);
    circle(18, 18, p + 210, 744);
    glColor3ub(252, 254, 255);
    circle(18, 25, p + 220, 745);

    glColor3ub(173, 197, 224);
    circle(10, 20, p + 235, 715);
    glColor3ub(252, 254, 255);
    circle(10, 20, p + 235, 719);



    glColor3ub(173, 197, 224);        ///....Megh.......3.....///
    circle(9, 15, p + 20, 685);
    glColor3ub(252, 254, 255);
    circle(6, 14, p + 21, 685);

    glColor3ub(232, 241, 255);
    circle(7, 16, p + 30, 695);
    glColor3ub(252, 254, 255);
    circle(7, 14, p + 32, 692);

    glColor3ub(252, 254, 255);
    circle(12, 16, p + 28, 680);

    glColor3ub(221, 229, 247);
    circle(10, 15, p + 45, 690);
    glColor3ub(252, 254, 255);
    circle(9, 13, p + 43, 685);
    glColor3ub(252, 254, 255);
    circle(15, 18, p + 48, 670);

    glColor3ub(173, 197, 224);
    circle(6, 14, p + 30, 680);
    glColor3ub(252, 254, 255);
    circle(6, 13, p + 30, 677);

    glColor3ub(173, 197, 224);
    circle(6, 14, p + 38, 668);
    glColor3ub(252, 254, 255);
    circle(6, 13, p + 36, 667);


    glColor3ub(252, 254, 255);
    circle(11, 15, p + 29, 668);

    ///....Megh.......4.....///

    glColor3ub(173, 197, 224);
    circle(9, 15, 590, 695);
    glColor3ub(252, 254, 255);
    circle(6, 14, 591, 695);

    glColor3ub(232, 241, 255);
    circle(7, 16, 600, 705);
    glColor3ub(252, 254, 255);
    circle(7, 14, 602, 702);

    glColor3ub(252, 254, 255);
    circle(12, 16, 598, 690);

    glColor3ub(221, 229, 247);
    circle(10, 15, 615, 700);
    glColor3ub(252, 254, 255);
    circle(9, 13, 613, 695);
    glColor3ub(252, 254, 255);
    circle(15, 18, 618, 680);

    glColor3ub(173, 197, 224);
    circle(6, 14, 600, 690);
    glColor3ub(252, 254, 255);
    circle(6, 13, 600, 687);

    glColor3ub(173, 197, 224);
    circle(6, 14, 608, 678);
    glColor3ub(252, 254, 255);
    circle(6, 13, 606, 677);


    glColor3ub(252, 254, 255);
    circle(11, 15, 599, 678);



    if (p <= 800)
        p = p + 0.1;
    else
        p = -10;
}
void update_cloud_position(int value) {
    move_cloud += 0.10f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_cloud > 250.0f) { // Adjust this value as needed
        move_cloud = -75.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_cloud_position, 0);
}

void render_cloud() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.0f + move_cloud, 10.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(0.22f, 0.50f, 0.0f); // Scale down to fit the new project's coordinate system
    cloud();
    glPopMatrix();

    //glFlush();
}

void boat()  //id21
{

    //body
    glColor3ub(139, 69, 19); // Clear the color buffer (background)
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(move_boat, 0.0f, 0.0f);//for move
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(60.0f, -70.0f);
    glVertex2f(80.0f, -70.0f);
    glVertex2f(90.0f, -30.0f);
    glVertex2f(50.0f, -30.0f);
    glEnd();


    //boat pal holder
    glColor3ub(0, 0, 0);
    glLineWidth(7.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(60.0f, -30.0f);
    glVertex2f(60.0f, 50.0f);
    glEnd();

    //boat pal
    glColor3ub(138, 43, 226);
    glLineWidth(7.0f);
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(60.0f, -25.0f);
    glVertex2f(80.0f, -25.0f);
    glVertex2f(60.0f, 45.0f);
    glEnd();
    glPopMatrix();
}


// boat-1
void boat1()
{
    /**.......................................Boat 1 ..........................................**/

    glPushMatrix();
    //glTranslated(position_boat1x,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.463, 0.486, 0.502);
    glVertex2f(-0.38f, 0.76f);
    glVertex2f(-0.16f, 0.76f);
    glVertex2f(-0.19f, 0.747f);
    glVertex2f(-0.35f, 0.747f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.969, 0.49);
    glVertex2f(-0.26f, 0.83f);
    glVertex2f(-0.33f, 0.77f);
    glVertex2f(-0.26f, 0.77f);

    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3f(0.988f, 0.961f, 0.149f);
    glVertex2f(-0.26f, 0.86f);
    glVertex2f(-0.22f, 0.77f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.26f, 0.84f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();
    glPopMatrix();


}


void boat2()
{
    /**.......................................Boat 2 ..........................................**/

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.525, 0.286, 0.282);
    glVertex2f(0.6f, 0.71f);
    glVertex2f(0.36f, 0.71f);
    glVertex2f(0.39f, 0.69f);
    glVertex2f(0.57f, 0.69f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.58, 0.122);
    glVertex2f(0.48f, 0.78f);
    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.48f, 0.72f);

    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.58, 0.122);
    glVertex2f(0.48f, 0.82f);
    glVertex2f(0.44f, 0.72f);
    glVertex2f(0.48f, 0.71f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.48f, 0.79f);
    glVertex2f(0.48f, 0.71f);

    glEnd();
    glPopMatrix();
}



void update_boat1_position(int value) {
    move_boat_1 += 0.40f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_boat_1 > 150.0f) { // Adjust this value as needed
        move_boat_1 = -75.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_boat1_position, 0);
}

void render_boat1_new() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(70.0f + move_boat_1, -600.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(130.0f, 600.0f, 0.0f); // Scale down to fit the new project's coordinate system
    // display_boat();
    boat1();
    glPopMatrix();

}

void update_boat2_position(int value) {
    move_boat_2 += 0.40f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_boat_2 > 180.0f) { // Adjust this value as needed
        move_boat_2 = -60.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_boat2_position, 0);
}

void render_boat2_new() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(70.0f - move_boat_2, -600.0f, 0.0f); // Translate to the building's original position in the old project
    glScalef(130.0f, 600.0f, 0.0f); // Scale down to fit the new project's coordinate system
    // display_boat();
    boat2();
    glPopMatrix();

    //glFlush();
}



//Airplane

void Airplane() {

    glBegin(GL_QUADS);   // body
    glColor3ub(255, 255, 255);
    glVertex2f(.666f, -.435f);
    glVertex2f(.5f, -.262f);
    glVertex2f(-.6f, -.262f);
    glVertex2f(-.166f, -.435f);
    glEnd();

    glBegin(GL_QUADS); //cockpit
    glColor3ub(0, 0, 0);
    glVertex2f(.579f, -.353f);
    glVertex2f(.546f, -.318f);
    glVertex2f(.466f, -.318f);
    glVertex2f(.466f, -.353f);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.308f, -.353f);
    glVertex2f(.308f, -.318f);
    glVertex2f(.278f, -.318f);
    glVertex2f(.278f, -.353f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.258f, -.353f);
    glVertex2f(.258f, -.318f);
    glVertex2f(.218f, -.318f);
    glVertex2f(.218f, -.353f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.188f, -.353f);
    glVertex2f(.188f, -.318f);
    glVertex2f(.158f, -.318f);
    glVertex2f(.158f, -.353f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.128f, -.353f);
    glVertex2f(.128f, -.318f);
    glVertex2f(.098f, -.318f);
    glVertex2f(.098f, -.353f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.078f, -.353f);
    glVertex2f(.078f, -.318f);
    glVertex2f(.048f, -.318f);
    glVertex2f(.048f, -.353f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.018f, -.353f);
    glVertex2f(.018f, -.318f);
    glVertex2f(-.008f, -.318f);
    glVertex2f(-.008f, -.353f);
    glEnd();

    //wings last
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-.464f, -.1f);
    glVertex2f(-.464f, -.262f);
    glVertex2f(-.302f, -.262f);
    glVertex2f(-.398f, -.1f);
    glEnd();

    glBegin(GL_QUADS); //Cross line
    glColor3f(1, 0, 0);
    glVertex2f(-.384f, -.262f);
    glVertex2f(-.464f, -.262f);
    glVertex2f(-.02f, -.435f);
    glVertex2f(.06f, -.435f);
    glEnd();


    //Wings down
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(.308f, -.383f);
    glVertex2f(.108f, -.383f);
    glVertex2f(-.278f, -.628f);
    glVertex2f(-.274f, -.628f);
    glEnd();

    //Wings up
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(.148f, -.262f);
    glVertex2f(.305f, -.262f);
    glVertex2f(-.108f, -.015f);
    glVertex2f(-.107f, -.01f);
    glEnd();

    //glFlush();
}

void update_plane_position(int value) {
    move_airplane += 0.40f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_airplane > 150.0f) { // Adjust this value as needed
        move_airplane = -60.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_plane_position, 0);
}


void render_plane() {
    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(60.0 + move_airplane, 370.0f, 0.0f);
    glScalef(10.f, 60.f, 0.0f);
    Airplane();
    glPopMatrix();
}




/**................................Bus stand.................................**/

GLfloat i = 0.0f;

# define PI    3.14159265358979323846

void busStand()
{

    /**...............................Stand right.......................**/


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.341, 0.356, 0.375);
    glVertex2f(0.55f, 0.515f);
    glVertex2f(0.55f, 0.63f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.56f);
    glEnd();

    /**...............................Stand left.......................**/
    glPushMatrix();
    glTranslated(-0.2f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.341, 0.356, 0.375);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.63f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.56f);
    glEnd();
    glPopMatrix();

    /**...................................Shade..........................**/

    GLfloat x = 0.363f;GLfloat  y = 0.63f;GLfloat  radius = 0.041f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.600f, 0.616f, 0.651f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float i = 0; i <= triangleAmount;i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.443f;  y = 0.63f;  radius = 0.06f;
    twicePi = 1.0f * PI;
    glColor3f(0.600f, 0.616f, 0.651f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float i = 0; i <= triangleAmount;i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.523f;  y = 0.63f;  radius = 0.041f;
    twicePi = 1.0f * PI;
    glColor3f(0.600f, 0.616f, 0.651f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float i = 0; i <= triangleAmount;i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    // renderBitmapString(0.42f, 0.65f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, " Bus Stand ");


    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.32f, 0.63f);
    glVertex2f(0.58f, 0.63f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.35f, 0.59f);
    glVertex2f(0.55f, 0.59f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.35f, 0.575f);
    glVertex2f(0.55f, 0.575f);
    glEnd();

    /**.........................................Glass.................................................**/

    glBegin(GL_QUADS);
    glColor3f(0.784, 0.882, 0.961);
    glVertex2f(0.36f, 0.62f);
    glVertex2f(0.36f, 0.545f);
    glVertex2f(0.54f, 0.545f);
    glVertex2f(0.54f, 0.62f);
    glEnd();

    /**...................................................Glass Shade.............................................**/

    glBegin(GL_QUADS);
    glColor3f(0.749, 0.863, 0.969);
    glVertex2f(0.36f, 0.545f);
    glVertex2f(0.36f, 0.565f);
    glVertex2f(0.42f, 0.62f);
    glVertex2f(0.44f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.749, 0.863, 0.969);
    glVertex2f(0.4f, 0.545f);
    glVertex2f(0.42f, 0.545f);
    glVertex2f(0.5f, 0.62f);
    glVertex2f(0.48f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.749, 0.863, 0.969);
    glVertex2f(0.54f, 0.62f);
    glVertex2f(0.54f, 0.6f);
    glVertex2f(0.48f, 0.545f);
    glVertex2f(0.46f, 0.545f);
    glEnd();

    /**...........................................Bench...................................................**/

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.39f, 0.53f);
    glVertex2f(0.4f, 0.53f);
    glVertex2f(0.4f, 0.55f);
    glVertex2f(0.39f, 0.55f);
    glEnd();

    glPushMatrix();
    glTranslated(0.11f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.39f, 0.52f);
    glVertex2f(0.4f, 0.52f);
    glVertex2f(0.4f, 0.55f);
    glVertex2f(0.39f, 0.55f);
    glEnd();
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.39f, 0.55f);
    glVertex2f(0.39f, 0.59f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.43f, 0.55f);
    glVertex2f(0.43f, 0.59f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.47f, 0.55f);
    glVertex2f(0.47f, 0.59f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.51f, 0.55f);
    glVertex2f(0.51f, 0.59f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.375f, 0.55f);
    glVertex2f(0.525f, 0.55f);
    glVertex2f(0.525f, 0.555f);
    glVertex2f(0.375f, 0.555f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.38f, 0.558f);
    glVertex2f(0.52f, 0.558f);
    glVertex2f(0.52f, 0.568f);
    glVertex2f(0.38f, 0.568f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.38f, 0.571f);
    glVertex2f(0.52f, 0.571f);
    glVertex2f(0.52f, 0.581f);
    glVertex2f(0.38f, 0.581f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.38f, 0.584f);
    glVertex2f(0.52f, 0.584f);
    glVertex2f(0.52f, 0.594f);
    glVertex2f(0.38f, 0.594f);
    glEnd();
}

void human1()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.0f, 0.02f, 0.0f);
    glScalef(0.9f, 0.9f, 0.0f);
    GLfloat x = 0.3f; GLfloat y = 0.28f; GLfloat radius = 0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.3f; y = 0.28f; radius = 0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));

    }
    glEnd();

    /// Hair bun for the head
    x = 0.284f; y = 0.278f;radius = 0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}


void human2()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.02f, 0.02f, 0.0f);
    glScalef(0.9f, 0.9f, 0.0f);
    GLfloat x = 0.3f; GLfloat y = 0.28f; GLfloat radius = 0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.3f; y = 0.28f; radius = 0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor4f(0.6f, 0.4f, 1.0f, 1.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.6f, 0.4f, 1.0f, 1.0f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}


void human_busStop()
{
    // glClear(GL_COLOR_BUFFER_BIT);

    busStand();
    /// Human o the bus stop
    glPushMatrix();
    glTranslatef(0.2f, 0.3f, 0.0f);
    human1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f, 0.29f, 0.0f);
    human2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15f, 0.3f, 0.0f);
    human2();
    glPopMatrix();
    glFlush();
}
void render_Human_Busstand() {
    //glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(128.0f, -185.0f, 0.0f);
    glScalef(100.0f, 500.0f, 0.0f);
    human_busStop();
    glPopMatrix();

    //glFlush();
}

//DAY END





//NIGHT START

void water_night()
{
    //water
    glColor3ub(0, 150, 220); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, -200.0f);
    glVertex2f(200.0f, -200.0f);
    glVertex2f(200.0f, -35.0f);
    glVertex2f(0.0f, -35.0f);
    glEnd();

    //beach
    glColor3ub(230, 210, 160); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, -35.0f);
    glVertex2f(200.0f, -35.0f);
    glVertex2f(200.0f, 25.0f);
    glVertex2f(0.0f, 25.0f);
    glEnd();

}


void umbrella_night()
{
    //from left first umbrella
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(22.0f, -15.0f);
    glVertex2f(22.0f, 35.0f);
    glEnd();

    //left
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(12.0f, 26.0f);
    glVertex2f(22.0f, 35.0f);
    glVertex2f(22.0f, 50.0f);
    glEnd();

    //right
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(32.0f, 26.0f);
    glVertex2f(22.0f, 35.0f);
    glVertex2f(22.0f, 50.0f);
    glEnd();


    //from left second umbrella
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(72.0f, -15.0f);
    glVertex2f(72.0f, 35.0f);
    glEnd();

    //left
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(62.0f, 26.0f);
    glVertex2f(72.0f, 35.0f);
    glVertex2f(72.0f, 50.0f);
    glEnd();

    //right
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(82.0f, 26.0f);
    glVertex2f(72.0f, 35.0f);
    glVertex2f(72.0f, 50.0f);
    glEnd();

    //from left third umbrella
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(122.0f, -15.0f);
    glVertex2f(122.0f, 35.0f);
    glEnd();

    //left
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(112.0f, 26.0f);
    glVertex2f(122.0f, 35.0f);
    glVertex2f(122.0f, 50.0f);
    glEnd();

    //right
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(132.0f, 26.0f);
    glVertex2f(122.0f, 35.0f);
    glVertex2f(122.0f, 50.0f);
    glEnd();

    //from left fourth umbrella
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(172.0f, -15.0f);
    glVertex2f(172.0f, 35.0f);
    glEnd();

    //left
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(162.0f, 26.0f);
    glVertex2f(172.0f, 35.0f);
    glVertex2f(172.0f, 50.0f);
    glEnd();

    //right
    glColor3ub(124, 252, 0); // Clear the color buffer (background)
    glBegin(GL_TRIANGLES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(182.0f, 26.0f);
    glVertex2f(172.0f, 35.0f);
    glVertex2f(172.0f, 50.0f);
    glEnd();

}

void wave_night()
{
    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f, move_wave, 0.0f);//for move
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-200.0f, -195.0f);
    glVertex2f(300.0f, -195.0f);
    glVertex2f(20.0f, -190.0f);
    glVertex2f(20.0f, -190.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-160.0f, -195.0f);
    glVertex2f(400.0f, -195.0f);
    glVertex2f(20.0f, -190.0f);
    glVertex2f(20.0f, -190.0f);
    glEnd();


    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-100.0f, -170.0f);
    glVertex2f(400.0f, -170.0f);
    glVertex2f(200.0f, -165.0f);
    glVertex2f(160.0f, -165.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-160.0f, -150.0f);
    glVertex2f(240.0f, -150.0f);
    glVertex2f(100.0f, -145.0f);
    glVertex2f(100.0f, -145.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-120.0f, -130.0f);
    glVertex2f(400.0f, -130.0f);
    glVertex2f(100.0f, -125.0f);
    glVertex2f(100.0f, -125.0f);
    glEnd();


    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-180.0f, -120.0f);
    glVertex2f(300.0f, -120.0f);
    glVertex2f(144.0f, -115.0f);
    glVertex2f(130.0f, -115.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-50.0f, -100.0f);
    glVertex2f(350.0f, -100.0f);
    glVertex2f(183.0f, -95.0f);
    glVertex2f(140.0f, -95.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-150.0f, -100.0f);
    glVertex2f(500.0f, -100.0f);
    glVertex2f(60.0f, -95.0f);
    glVertex2f(80.0f, -95.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-166.0f, -80.0f);
    glVertex2f(360.0f, -80.0f);
    glVertex2f(50.0f, -75.0f);
    glVertex2f(40.0f, -75.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-178.0f, -60.0f);
    glVertex2f(380.0f, -60.0f);
    glVertex2f(50.0f, -55.0f);
    glVertex2f(40.0f, -55.0f);
    glEnd();

    glColor3ub(190, 230, 250); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(-190.0f, -50.0f);
    glVertex2f(350.0f, -50.0f);
    glVertex2f(48.0f, -45.0f);
    glVertex2f(67.0f, -45.0f);
    glEnd();
    glPopMatrix();
}
void road_night()
{

    //main structure
    glColor3ub(110, 110, 110); // Clear the color buffer (background)
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, 25.0f);
    glVertex2f(200.0f, 25.0f);
    glVertex2f(200.0f, 80.0f);
    glVertex2f(0.0f, 80.0f);
    glEnd();

    //road slide lines
    glLineWidth(3.0f);
    glColor3ub(255, 255, 255); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, 75.0f);
    glVertex2f(200.0f, 75.0f);
    glVertex2f(200.0f, 30.0f);
    glVertex2f(0.0f, 30.0f);
    glEnd();

    //middle dot lines
    glLineWidth(3.0f);
    glColor3ub(255, 255, 255); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(5.0f, 52.5f);
    glVertex2f(10.0f, 52.5f);
    glVertex2f(15.0f, 52.5f);
    glVertex2f(20.0f, 52.5f);
    glVertex2f(25.0f, 52.5f);
    glVertex2f(30.0f, 52.5f);
    glVertex2f(35.0f, 52.5f);
    glVertex2f(40.0f, 52.5f);
    glVertex2f(45.0f, 52.5f);
    glVertex2f(50.0f, 52.5f);
    glVertex2f(55.0f, 52.5f);
    glVertex2f(60.0f, 52.5f);
    glVertex2f(65.0f, 52.5f);
    glVertex2f(70.0f, 52.5f);
    glVertex2f(75.0f, 52.5f);
    glVertex2f(80.0f, 52.5f);
    glVertex2f(85.0f, 52.5f);
    glVertex2f(90.0f, 52.5f);
    glVertex2f(95.0f, 52.5f);
    glVertex2f(100.0f, 52.5f);

    glVertex2f(105.0f, 52.5f);
    glVertex2f(110.0f, 52.5f);
    glVertex2f(115.0f, 52.5f);
    glVertex2f(120.0f, 52.5f);
    glVertex2f(125.0f, 52.5f);
    glVertex2f(130.0f, 52.5f);
    glVertex2f(135.0f, 52.5f);
    glVertex2f(140.0f, 52.5f);
    glVertex2f(145.0f, 52.5f);
    glVertex2f(150.0f, 52.5f);
    glVertex2f(155.0f, 52.5f);
    glVertex2f(160.0f, 52.5f);
    glVertex2f(165.0f, 52.5f);
    glVertex2f(170.0f, 52.5f);
    glVertex2f(175.0f, 52.5f);
    glVertex2f(180.0f, 52.5f);
    glVertex2f(185.0f, 52.5f);
    glVertex2f(190.0f, 52.5f);
    glVertex2f(195.0f, 52.5f);
    glVertex2f(200.0f, 52.5f);
    glEnd();

}
void sky_night()
{
    //glColor3ub(34.0f,263.0f,223.0f); // Clear the color buffer (background)
    glColor3ub(36, 52, 71);
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(0.0f, 80.0f);
    glVertex2f(200.0f, 80.0f);
    glVertex2f(200.0f, 400.0f);
    glVertex2f(0.0f, 400.0f);
    glEnd();

    //star

    glColor3ub(255, 255, 255);
    glPointSize(4.0f);
    glBegin(GL_POINTS);// Draw a Red 1x1 Square centered at origin
    glVertex2f(5.0f, 350.0f);
    glVertex2f(15.0f, 335.0f);
    glVertex2f(25.0f, 370.0f);
    glVertex2f(35.0f, 330.0f);
    glVertex2f(45.0f, 365.0f);
    glVertex2f(55.0f, 370.0f);
    glVertex2f(65.0f, 365.0f);
    glVertex2f(75.0f, 385.0f);
    glVertex2f(85.0f, 380.0f);
    glVertex2f(95.0f, 385.0f);
    glVertex2f(105.0f, 380.0f);
    glVertex2f(115.0f, 385.0f);
    glVertex2f(125.0f, 350.0f);
    glVertex2f(135.0f, 365.0f);
    glVertex2f(145.0f, 395.0f);
    glVertex2f(155.0f, 380.0f);
    glVertex2f(165.0f, 345.0f);
    glVertex2f(175.0f, 375.0f);
    glVertex2f(185.0f, 370.0f);
    glVertex2f(195.0f, 365.0f);
    glVertex2f(10.0f, 320.0f);
    glVertex2f(20.0f, 300.0f);
    glVertex2f(30.0f, 340.0f);
    glVertex2f(40.0f, 320.0f);
    glVertex2f(50.0f, 280.0f);
    glVertex2f(60.0f, 360.0f);
    glVertex2f(70.0f, 340.0f);
    glVertex2f(140.0f, 300.0f);
    glVertex2f(150.0f, 280.0f);
    glVertex2f(160.0f, 265.0f);
    glVertex2f(180.0f, 270.0f);
    glVertex2f(170.0f, 300.0f);
    glVertex2f(130.0f, 390.0f);

    glVertex2f(190.0f, 320.0f);
    glEnd();

}



void bench_night()
{

    //left side 1st bench
    //upper part
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(40.0f, 92.0f);
    glVertex2f(48.0f, 92.0f);
    glEnd();

    //left leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(41.0f, 80.0f);
    glVertex2f(41.0f, 92.0f);
    glEnd();
    //right leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(47.0f, 80.0f);
    glVertex2f(47.0f, 92.0f);
    glEnd();


    //left side 2nd bench
    //upper part
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(50.0f, 92.0f);
    glVertex2f(58.0f, 92.0f);
    glEnd();

    //left leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(51.0f, 80.0f);
    glVertex2f(51.0f, 92.0f);
    glEnd();
    //right leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(57.0f, 80.0f);
    glVertex2f(57.0f, 92.0f);
    glEnd();


    //right side 1st bench
        //upper part
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(172.0f, 92.0f);
    glVertex2f(180.0f, 92.0f);
    glEnd();

    //left leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(173.0f, 80.0f);
    glVertex2f(173.0f, 92.0f);
    glEnd();
    //right leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(179.0f, 80.0f);
    glVertex2f(179.0f, 92.0f);
    glEnd();
    //right side 2nd bench
       //upper part
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(182.0f, 92.0f);
    glVertex2f(190.0f, 92.0f);
    glEnd();

    //left leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(183.0f, 80.0f);
    glVertex2f(183.0f, 92.0f);
    glEnd();
    //right leg
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(4.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin

    glVertex2f(189.0f, 80.0f);
    glVertex2f(189.0f, 92.0f);
    glEnd();
}
void lamppost_night()
{
    //left side lamppost
    //pillar
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(62.0f, 80.0f);
    glVertex2f(62.0f, 162.5f);
    glEnd();

    //light holder
    glColor3ub(0, 0, 0); // Clear the color buffer (background)
    glLineWidth(6.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(62.0f, 160.0f);
    glVertex2f(54.0f, 160.0f);
    glEnd();

    //light
    glColor3ub(255, 255, 0); // Clear the color buffer (background)
    glLineWidth(7.0f);
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glVertex2f(54.0f, 158.0f);
    glVertex2f(57.0f, 158.0f);
    glEnd();


}



//New portion finish 2 phase

void cloud_night()
{
    //cloud start
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(move_cloud, 0.0f, 0.0f);//for move
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(200, 200, 200);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 9.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 22, y + 302);
    }

    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(200, 200, 200);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 11.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 30, y + 290);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(200, 200, 200);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 9.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 40, y + 302);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(200, 200, 200);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 35, y + 312);
    }
    glEnd();
    glPopMatrix();
    //cloud end
}


//Airplane
void air_plane_night()
{
    //main body
    glColor3ub(60, 95, 215);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(move_airplane, 0.0f, 0.0f);//for move
    glBegin(GL_QUADS);
    glVertex2f(160.0f, 318.0f);
    glVertex2f(183.0f, 318.0f);
    glVertex2f(183.0f, 343.0f);
    glVertex2f(160.0f, 343.0f);
    glEnd();

    //body light

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(159.5f, 314.5f);
    glVertex2f(160.5f, 314.5f);
    glVertex2f(160.5f, 318.0f);
    glVertex2f(159.5f, 318.0f);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(178.0f, 314.5f);
    glVertex2f(179.0f, 314.5f);
    glVertex2f(179.0f, 318.0f);
    glVertex2f(178.0f, 318.0f);
    glEnd();


    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(180.0f, 314.5f);
    glVertex2f(181.0f, 314.5f);
    glVertex2f(181.0f, 318.0f);
    glVertex2f(180.0f, 318.0f);
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(183.0f, 358.5f);
    glVertex2f(184.0f, 358.5f);
    glVertex2f(184.0f, 364.0f);
    glVertex2f(183.0f, 364.0f);
    glEnd();

    //front part bottom
    glColor3ub(70, 0, 115);
    glBegin(GL_QUADS);
    glVertex2f(160.0f, 330.5f);
    glVertex2f(155.0f, 330.5f);
    glVertex2f(158.0f, 318.0f);
    glVertex2f(160.0f, 318.0f);
    glEnd();

    //front part upper
    glColor3ub(70, 0, 115);
    glBegin(GL_QUADS);
    glVertex2f(155.0f, 330.5f);
    glVertex2f(160.0f, 330.5f);
    glVertex2f(160.0f, 343.0f);
    glVertex2f(158.0f, 343.0f);
    glEnd();

    //left wings
    glColor3ub(245, 155, 0);
    glBegin(GL_QUADS);
    glVertex2f(163.0f, 330.5f);
    glVertex2f(168.0f, 298.0f);
    glVertex2f(173.0f, 295.0f);
    glVertex2f(168.0f, 330.5f);
    glEnd();


    //left wing light
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(169.0f, 300.0f);
    glVertex2f(167.5f, 300.0f);
    glVertex2f(167.5f, 295.0f);
    glVertex2f(169.0f, 295.0f);

    glEnd();

    //right wings
    glColor3ub(245, 155, 0);
    glBegin(GL_QUADS);
    glVertex2f(165.0f, 343.0f);
    glVertex2f(170.0f, 343.0f);
    glVertex2f(173.0f, 363.0f);
    glVertex2f(168.0f, 360.5f);
    glEnd();

    //right wing light
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(169.0f, 363.0f);
    glVertex2f(167.5f, 363.0f);
    glVertex2f(167.5f, 358.0f);
    glVertex2f(169.0f, 358.0f);

    glEnd();

    //tail
    glColor3ub(245, 155, 0);
    glBegin(GL_QUADS);
    glVertex2f(178.0f, 343.0f);
    glVertex2f(183.0f, 343.0f);
    glVertex2f(183.0f, 365.0f);
    glVertex2f(181.0f, 365.5f);
    glEnd();
    glPopMatrix();
}



//NIGHT END





void CarTire()
{
    //Tires

    glBegin(GL_POLYGON);//tire-1
    glLineWidth(7.5);
    for (int i = 0;i < 200;i++)
    {

        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 2.5;
        float x = (140 + (r * 5 * cos(A)));
        float y = (93 + (r * 10 * sin(A)));
        glVertex2f(x, y);

    }
    glEnd();
    // 140=140+200;

    glBegin(GL_POLYGON);
    glLineWidth(7.5);
    for (int i = 0;i < 200;i++)
    {

        glColor3ub(168, 169, 173);//steel-cover
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 1.5;
        float x = (140 + (r * 5 * cos(A)));
        float y = (93 + (r * 10 * sin(A)));
        glVertex2f(x, y);

    }
    glEnd();
    //140=140+200;

    glBegin(GL_POLYGON);//tire-2
    glLineWidth(7.5);
    for (int i = 0;i < 200;i++)
    {

        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 2.5;
        float x = (210 + (r * 5 * cos(A)));
        float y = (93 + (r * 10 * sin(A)));
        glVertex2f(x, y);

    }
    glEnd();
    // 210=210+200;

    glBegin(GL_POLYGON);
    glLineWidth(7.5);
    for (int i = 0;i < 200;i++)
    {

        glColor3ub(168, 169, 173);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 1.5;
        float x = (210 + (r * 5 * cos(A)));
        float y = (93 + (r * 10 * sin(A)));
        glVertex2f(x, y);

    }
    glEnd();
    // 210=210+200;
}
void CarBody()
{


    glColor3ub(199, 0, 57);//body
    glBegin(GL_POLYGON);
    glVertex2f(140, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(240, 127);
    glVertex2f(240, 92);
    glVertex2f(110, 92);
    glVertex2f(110, 127);
    glVertex2f(130, 127);
    glVertex2f(140, 152);
    glEnd();

    glBegin(GL_POLYGON);//back-light
    glColor3ub(255, 0, 0);
    glVertex2f(110, 92);
    glVertex2f(115, 92);
    glVertex2f(115, 117);
    glVertex2f(110, 117);
    glEnd();



    glBegin(GL_POLYGON);//window
    glColor3ub(255, 195, 0);
    glVertex2f(140, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(120, 127);
    glVertex2f(130, 127);
    glEnd();


    glBegin(GL_POLYGON);//window-Divider
    glColor3ub(67, 38, 11);
    glVertex2f(170, 152);
    glVertex2f(165, 152);
    glVertex2f(165, 127);
    glVertex2f(170, 127);
    glEnd();

    glBegin(GL_POLYGON);//roof-plate
    glColor3ub(67, 38, 11);

    glVertex2f(140, 152);
    glVertex2f(190, 152);
    glVertex2f(185, 157);
    glVertex2f(140, 157);
    glEnd();

    glBegin(GL_POLYGON);//window-holder-front
    glColor3ub(67, 38, 11);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(185, 152);
    glEnd();



    glBegin(GL_POLYGON);//window-holder-back
    glColor3ub(67, 38, 11);
    glVertex2f(140, 157);
    glVertex2f(115, 127);
    glVertex2f(125, 127);
    glVertex2f(140, 152);
    glEnd();

    glBegin(GL_POLYGON);//foot-holder
    glColor3ub(67, 38, 11);
    glVertex2f(215, 92);
    glVertex2f(110, 92);
    glVertex2f(110, 97);
    glVertex2f(215, 97);

    glEnd();

    glBegin(GL_POLYGON);//mirror
    glColor3ub(13, 182, 67);
    //glColor3ub(255,250,0);
    glVertex2f(211.5, 134.5);
    glVertex2f(204.5, 135.5);
    glVertex2f(203.5, 129);
    glVertex2f(210.5, 127);
    glEnd();



}
void CarForward()
{

    CarBody();


    CarTire();

}


void displayCar() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    //glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


    CarForward();
    glFlush();  // Render now
}

void update_left_car_position(int value) {
    move_left_car += 0.35f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_left_car > 200.0f) { // Adjust this value as needed
        move_left_car = -60.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_left_car_position, 0);
}


void render_car() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(10.0f + move_left_car, 28.0f, 0.0f);
    glScalef(0.12f, 0.40f, 0.0f);
    displayCar();
    glPopMatrix();

    //glFlush();
}


//Truck:
int _TruckMoveReverse = 0;

float TireRotateAngle = 0.0f;
void TruckTire(int xx, int yy, float r)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(TireRotateAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.0f, -0.0f, 0.0f);
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        // glColor3ub(255, 215, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        // float r = 4.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);//black-rim
    glVertex2f(-0.075, 0);
    glVertex2f(0.075, 0);

    glVertex2f(-0.05, -0.075);
    glVertex2f(0.05, 0.075);

    glVertex2f(0.05, -0.075);
    glVertex2f(-0.05, 0.075);

    glVertex2f(0, -0.1);
    glVertex2f(0, 0.1);

    glEnd();

    glPopMatrix();

}
void ScaledTire()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(140.1, 95, 0);
    glScalef(80, 80, 0);
    glColor3ub(0, 0, 0);//black-tire
    TruckTire(0, 0, 0.2);
    glColor3ub(192, 192, 192);//silver-tire-rim
    TruckTire(0, 0, 0.13);
    glColor3ub(211, 211, 255);//grey-tire-rim
    TruckTire(0, 0, 0.09);
    glPopMatrix();
}

void TruckBody()
{

    //glColor3f(0.1373, 0.5725, 0.5529); //body
    glColor3ub(23, 214, 231);
    glBegin(GL_POLYGON);
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(240, 127);
    glVertex2f(240, 92);
    glVertex2f(150, 92);
    glEnd();

    glBegin(GL_POLYGON);//trolly
    glVertex2f(150, 129);
    glVertex2f(60, 129);
    glVertex2f(60, 92);
    glVertex2f(150, 92);
    glEnd();

    glBegin(GL_POLYGON); //back-light
    glColor3ub(255, 0, 0);
    glVertex2f(110 - 50, 92);
    glVertex2f(115 - 50, 92);
    glVertex2f(115 - 50, 117);
    glVertex2f(110 - 50, 117);
    glEnd();

    glBegin(GL_POLYGON); //window
    glColor3ub(0, 0, 0);
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(150, 127);
    glVertex2f(130, 127);
    glEnd();

    glBegin(GL_POLYGON); //window-Divider
    glColor3ub(192, 192, 192);
    glVertex2f(170, 152);
    glVertex2f(165, 152);
    glVertex2f(165, 127);
    glVertex2f(170, 127);
    glEnd();

    glBegin(GL_POLYGON); //roof-plate
    glColor3ub(168, 169, 173);

    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(185, 157);
    glVertex2f(150, 157);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-front
    glColor3ub(168, 169, 173);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(185, 152);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-back
    glColor3ub(168, 169, 173);
    glVertex2f(140 + 20 - 10, 157);
    glVertex2f(115 + 20, 127);
    glVertex2f(125 + 20, 127);
    glVertex2f(140 + 20 - 10, 152);
    glEnd();

    glBegin(GL_POLYGON); //foot-holder
    glColor3ub(168, 169, 173);
    glVertex2f(242, 92);
    glVertex2f(60, 92);
    glVertex2f(60, 97);
    glVertex2f(242, 97);

    glEnd();

    glBegin(GL_POLYGON);      //mirror
    glColor3f(0.3, 0.9, 0.6); //body
    //glColor3ub(255,250,0);
    glVertex2f(211.5, 134.5);
    glVertex2f(204.5, 135.5);
    glVertex2f(203.5, 129);
    glVertex2f(210.5, 127);
    glEnd();

    glBegin(GL_POLYGON);      //Yellow-headlight
    glColor3f(1.0, 1.0, 0.0); //body
    //glColor3ub(255,250,0);
    glVertex2f(210.5 + 28, 134.5 - 10);
    glVertex2f(203.5 + 28, 135.5 - 10);
    glVertex2f(203.5 + 28, 129 - 10);
    glVertex2f(210.5 + 28, 127 - 10);
    glEnd();

    glBegin(GL_POLYGON); //window-opener-1
    glColor3ub(192, 192, 192);
    glVertex2f(150 - 15 - 5, 127 - 5 - 3);
    glVertex2f(155 - 5 - 5, 127 - 5 - 3);
    glVertex2f(155 - 5 - 5, 129 - 5);
    glVertex2f(150 - 15 - 5, 129 - 5);
    glEnd();
    glBegin(GL_POLYGON); //window-opener-2
    glColor3ub(192, 192, 192);
    glVertex2f(150 - 15 + 40, 127 - 5 - 3);
    glVertex2f(155 - 5 + 40, 127 - 5 - 3);
    glVertex2f(155 - 5 + 40, 129 - 5);
    glVertex2f(150 - 15 + 40, 129 - 5);
    glEnd();
}
void TruckThrust()
{
    glBegin(GL_POLYGON);
    glColor3ub(168, 169, 173);
    glVertex2f(110 - 50, 92);
    glColor3ub(255, 255, 255);
    glVertex2f(00 - 50, 80);
    glVertex2f(00 - 50, 110);
    glColor3ub(0, 0, 0);
    glVertex2f(110 - 50, 97);
    glEnd();

}
void fullTruck()
{
    //TruckThrust();
    TruckBody();
    //ScaledTire();
    glPushMatrix();
    glTranslatef(65, 0, 0);
    ScaledTire();
    glTranslatef(-85, 0, 0);
    ScaledTire();
    glPopMatrix();

}
void TruckReverse()
{
    glLineWidth(1);
    //glMatrixMode(GL_MODELVIEW);

     //init();
    //glPushMatrix();

    glTranslatef(-100.5, 0, 0);
    //glTranslatef(_TruckMoveReverse % 500, 0, 0);
    fullTruck();

    // glPopMatrix();

     //glutSwapBuffers();
}
void ScaledTruckReverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(300, 140, 0);
    glScalef(-0.5, 0.5, 0);
    TruckReverse();
    glPopMatrix();

}
void MovingScaledTruckReverse()
{
    glMatrixMode(GL_MODELVIEW);

    //init();
    glPushMatrix();
    //glTranslatef(-100.5, 0, 0);
    glTranslatef(_TruckMoveReverse % 550, 0, 0);

    ScaledTruckReverse();
    glPopMatrix();
    //glutSwapBuffers();
}
void TireRotate(int value)
{
    TireRotateAngle -= 5.0f;
    glutPostRedisplay(); //Notify GLUT that the display has changed

}
void MoveTruckReverse(int value) {



    _TruckMoveReverse -= 1;

    glutPostRedisplay();
    //glutTimerFunc(20, MoveTruckReverse, 0);
}

void display_Truck()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    //glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    MovingScaledTruckReverse();
    glFlush(); // Render now
}
void update_left_truck_position(int value) {
    move_right_car += 0.25f; // Adjust this value as needed

    // Reset the plane's position after it moves off screen
    if (move_right_car > 150.0f) { // Adjust this value as needed
        move_right_car = -100.0f; // Reset to initial value
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update_left_truck_position, 0);
}

void render_truck() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(36.0f - move_right_car, -135.0f, 0.0f); // 
    glScalef(0.23f, 0.95f, 0.0f);
    display_Truck();
    glPopMatrix();

    //glFlush();
}


int _angle1 = 0;

void init()
{
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void blades()
{
    glBegin(GL_POLYGON);          //blade
    glColor3ub(0, 0, 0);
    glVertex2f(257, 370);
    glVertex2f(267, 430);
    glVertex2f(284, 490);
    glVertex2f(280, 430);
    glVertex2f(261, 363);
    glEnd();

}
void windmill()
{
    glBegin(GL_QUADS);          //body
    glColor3ub(55, 25, 55);
    glVertex2f(250, 50);
    glVertex2f(260, 50);
    glVertex2f(257, 350);
    glVertex2f(253, 350);
    glEnd();


    glPushMatrix();

    glTranslatef(255, 360, 0);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
    glTranslatef(-255, -360, 0);


    blades();//1st
    glPushMatrix();
    glTranslatef(255, 360, 0);
    glRotatef(120, 0.0f, 0.0f, 1.0f);
    glTranslatef(-255, -360, 0);
    blades();//2nd
    glPopMatrix();


    glPushMatrix();
    glTranslatef(255, 360, 0);
    glRotatef(240, 0.0f, 0.0f, 1.0f);
    glTranslatef(-255, -360, 0);
    blades();   //3rd blade
    glPopMatrix();


    glPopMatrix();

}
void update_windmill(int value)
{

    // std::cout << "updated called";

    _angle1 -= 1.0f;
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(20, update_windmill, 0); //Notify GLUT to call update again in 25 milliseconds
}

void circle(int xx, int yy, float r)
{

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin

    for (int i = 0; i < 200; i++)
    {
        // glColor3ub(255, 215, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        // float r = 4.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
}

void display_windmill()
{
    glClearColor(0.2f, 0.4f, 0.93f, 1.0f); // Set background color to black and opaque

    windmill();
    //  CarForward();
    circle(255, 360, 10);

    glFlush(); // Render now

}

void render_windmill() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // Set up the projection matrix for the new project
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, -200, 400); // Set the new orthographic projection

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Render other objects of the new project here

    // Apply translation and scaling to the building object
    glPushMatrix();
    glTranslatef(125.0f, 48.0f, 0.0f);
    glScalef(0.12f, 0.60f, 0.0f);
    display_windmill();
    glPopMatrix();

    //glFlush();
}


//FOR DAY
void display() {
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    sky();

    tree_old();

    render_tree();
    render_Human_Busstand();
    road();

    water();

    wave();
    render_cloud();
    render_sun();


    render_building1();
    render_building2_3();
    render_building4();
    render_windmill();
    render_tree2();
    render_building5();


    bench();
    lamppost();

    render_car();  //
    render_truck();


    render_bench1();
    render_bench2();
    render_bench3();
    render_bench4();
    umbrella();

    render_plane(); //done

    render_boat1_new();
    render_boat2_new();






    glFlush(); // Render now
    glutSwapBuffers();
}


//FOR NIGHT

void display1() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor(0.0f,0.0f,0.0f,0.5f);
    sky_night();
    tree_old();
    //  render_tree();
    render_Human_Busstand();

    // tree_night();
    road_night();
    water_night();
    //beach_bench_night();
    wave_night();
    render_plane();

    render_building1();
    render_building2_3();
    render_building4();
    render_windmill();
    render_tree2();
    render_building5();

    render_boat1_new();
    render_boat2_new();

    // first_blade_night();
    // second_blade_night();
    // windmill_stand_night();

    // right_first_blade_night();
    // right_second_blade_night();
    // right_windmill_stand_night();
    //moon();
    // cloud_night();
    // air_plane_night();
    // building_1_night();
    // building_2_night();
    // building_3_night();
    // building_4_night();
    // building_5_night();
    // building_6_night();
    // building_7_night();

    render_car();
    render_truck();
    render_bench1();
    render_bench2();
    render_bench3();
    render_bench4();
    umbrella();

    bench_night();
    lamppost_night();
    render_moon();

    // boat_night();
    // boat_1_night();
    // speed_board_night();
    // ship_night();
    // containers_night();
    // upper_container_night_text(57.3, -75.0, text1);
    // left_container_night_text(49.0, -107.5, text2);
    // right_container_night_text(67.5, -107.5, text3);
    // ship_name_night_text(11.5, -137.0, text4);
    glFlush(); // Render now
    glutSwapBuffers();
}




void handleKeypress(unsigned char key, int x, int y)//id41
{

    switch (key) {

    case 'd':

        glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case 'n':
        glutDisplayFunc(display1);
        glutPostRedisplay();
        break;

    }
}



int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("An Interactive Costal scene");
    glutInitWindowSize(800, 400);// Set the window's initial width & height

    glutDisplayFunc(display);// Register display callback handler for window re-paint
    glutKeyboardFunc(handleKeypress);
    identity_axis();

    glutTimerFunc(0, update_plane_position, 0);
    glutTimerFunc(0, update_left_car_position, 0);
    glutTimerFunc(0, update_left_truck_position, 0);
    glutTimerFunc(0, update_left_truck_position, 0);
    glutTimerFunc(0, update_boat1_position, 0);
    glutTimerFunc(0, update_boat2_position, 0);
    glutTimerFunc(0, update_windmill, 0);
    glutTimerFunc(40, update_wave, 0);
    glutTimerFunc(0, update_cloud_position, 0);
    glutTimerFunc(0, update_sun_position, 0);
    //glutTimerFunc(0, update_moon_position, 0);


    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
