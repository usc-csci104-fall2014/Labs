#include "defwin.h"

using namespace std;

DefWin::DefWin(string word, QWidget *parent) : QMainWindow(parent)
{
	setWindowTitle(QString::fromStdString("Define: " + word));     // set window title
	web = new QWebView(this);           // this object is a web browser embedded inside your window
	this->setCentralWidget(web);        // sets the web view object to fill the window

	// setup the web view and show it
	// what kind of function is 'QString::fromStdString'?
	web->load(QUrl(QString::fromStdString("http://www.merriam-webster.com/dictionary/" + word)));
	web->show();
}

DefWin::~DefWin()
{
	delete web;
}
