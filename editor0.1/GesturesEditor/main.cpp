#include <QtGui/QApplication>
#include "gestEditor.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GestEditor w;
	w.show();
	
	return a.exec();
}
