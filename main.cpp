#include<QApplication>
#include "QGame.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QGame game;
	game.init({ 480,852 }, "Plane-game");
	game.run();

	return a.exec();
}
