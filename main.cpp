#include <QApplication>
 
#include "simgui.h"
 
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	SimGui sim;
	sim.show();

	return app.exec();
}