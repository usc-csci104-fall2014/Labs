#include "mainwin.h"
#include <string>
#include <sstream>

using namespace std;

MainWin::MainWin(QWidget *parent) : QWidget(parent)
{
	// allocate memory for both buttons and textbox
	// lookup button and textbox documentation for constructor

	// place buttons and textbox in the window with move and setFixedSize functions
	// move: http://qt-project.org/doc/qt-4.8/qwidget.html#pos-prop
	// set size: http://qt-project.org/doc/qt-4.8/qwidget.html#setFixedSize
	// get height: http://qt-project.org/doc/qt-4.8/qwidget.html#height-prop
	// get width: http://qt-project.org/doc/qt-4.8/qwidget.html#width-prop
	// get x and y: http://qt-project.org/doc/qt-4.8/qwidget.html#x-prop

	// Alternatively, consider using a GridLayout.
	// That way, you do not have to worry about finding the pixel counts yourself.
	// Start by doing:
	// QGridLayout *layout = new QGridLayout;
  // setLayout(layout);
	
	// connect clicked signal of each button to the right slot
}

MainWin::~MainWin()
{
	delete ??;
}

void MainWin::closeEvent(QCloseEvent *event)
{
	if (true /* is it ok to close the window ? */)
	{
		// save data
		event->accept();
	}
	else // otherwise
	{
		event->ignore();
	}
}

void MainWin::doCountWord()
{
	// complete this function so that it counts the number of words in the textbox and show it as a message box
	// get text: http://qt-project.org/doc/qt-5/qplaintextedit.html#plainText-prop
	// message box: http://qt-project.org/doc/qt-5/qmessagebox.html#information
}

void MainWin::showAbout()
{
	// ref: http://qt-project.org/doc/qt-5/qmessagebox.html#information
	QMessageBox::information(this, tr("About"), tr("Sample Qt app for lab8"));
}

