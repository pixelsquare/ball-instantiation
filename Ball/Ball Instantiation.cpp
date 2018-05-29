#include "glutSetup.h"
#include <iostream>
#include <vector>

using namespace std;

class Ball {																// Create a class "Implementation[class <any name> { }; ]"
public:																		// Specify its referencing make it public so it can be accessed outside the class							
	float posX, posY, posZ;
	vector<Ball> vectorBall;

	Ball() { posX = 0; posY = 0; posZ = 0; }

	Ball(float positionX, float positionY, float positionZ) {
		posX = positionX; posY = positionY; posZ = positionZ;	
	}

	// Class Function "Draw"
	// This will render the objectS
	void Draw() {
		for(int i = 0; i < vectorBall.size(); i++) {
			glPushMatrix();
				glTranslatef(vectorBall.at(i).posX, vectorBall.at(i).posY, vectorBall.at(i).posZ);
				glutSolidSphere(0.6f, 50, 50);
			glPopMatrix();
		}
	}

private:
protected:

};						// << ---- Don't forget this ";" in the class :)

// Object "Implementation[<Class Name> <Any Name>( <positionX>, <positionY>, <positionZ> ); ]"
// I used my Overloaded Constructor to set my object to x = -20, y = 0, z = 0
Ball ball(-20.0f, 0.0f, 0.0f);

// This variable will add 1 to the x position of the object
float increment = 0;

void GamePlay()
{
	// Used in drawing Objects on game screen
	ball.Draw();
}

void Scene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(LookX, LookY, LookZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glRotatef(AngleX, 1.0, 0.0, 0.0);
		glRotatef(AngleY, 0.0, 1.0, 0.0);
	/* Display Object on GLUT Window */
		glPushMatrix();

		GamePlay();

		glPopMatrix();

	glutSwapBuffers();
} 

void Keys(unsigned char key, int x, int y)
{
	KeyDown[key] = true;
  switch(key)
  {
  case ' ':																					// Space bar keypress
	  increment += 1.3f;																	// Add + 1.3f in my variable "increment"

	  // Store another ball to the vector
	  // Implementation [<CLASS VARIABLE name>.<VECTOR variable>.<push_back>( <CLASS NAME> ( <positionX>, <positionY>, <positionZ> ));
	  ball.vectorBall.push_back(Ball(ball.posX + increment, ball.posY, ball.posZ));
	  break;

  case 'e':
	  ball.vectorBall.erase(ball.vectorBall.begin());
	  break;
/* ZOOM FUNCTION */
	case 'z':
		LookZ += 1.0;
		break;

	case 'x':
		LookZ -= 1.0;
		break;

// Normal Camera origin
	case 'c':
		LookX = 0.0f;
		LookY = 0.0f;
		LookZ = 8.0f;
		break;

// Others
	case 27:
		exit(0);
  }
}

void main(int argc, char **argv)
{
	GLUTmain(argc, argv, "Ball Instantiation");
}	