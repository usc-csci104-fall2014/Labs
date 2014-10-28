#include "mainwin.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

MainWin::MainWin(QWidget *parent) : QMainWindow(parent)
{
	// allocate memory for all widgets
	winLayout     = new QVBoxLayout;
	genLayout     = new QHBoxLayout;
	txtWordsInput = new QPlainTextEdit;
	btnGen        = new QPushButton("&Generate Buttons");
	btnAbout      = new QPushButton("&About");
	
	// setup the grid layout and make it fill the window
	centerWidget  = new QWidget(this);
	centerWidget->setLayout(winLayout);
	this->setCentralWidget(centerWidget);

	// add all widgets to the layout
	// redo the following 4 lines to customize the layout
	winLayout->addWidget(txtWordsInput, 0);
	winLayout->addLayout(genLayout,     1);
	winLayout->addWidget(btnAbout,      2);
	// winLayout->addWidget(btnGen,        3);
	
	// connect clicked signal of each button to the right slot
	connect(btnAbout,      SIGNAL(clicked()),     this, SLOT(showAbout()));
	connect(txtWordsInput, SIGNAL(textChanged()), this, SLOT(doGenerateDynamicButtons()));
}

MainWin::~MainWin()
{
	cleanAllDynamicButtons(); // cleans the dynamic buttons	
	for (auto w : listDefWindows) delete w;	
	
	delete genLayout;
	delete txtWordsInput;
	delete btnAbout;
	delete btnGen;
	delete winLayout;
}

void MainWin::cleanAllDynamicButtons(void)
{
	// this is c++11 syntax to loop over an STL container
	// re-write this for-loop using set iterator
	for (auto b : setWordButtons)
	{
		// remove the widget 'b' from genLayout
		genLayout->removeWidget(b);
		delete b; // this would also disconnect the signal-slot connection
	}

	// Cleaning the set. We deallocated the button pointers but the set is still not empty. Why?
	setWordButtons.clear();
}

void MainWin::doGenerateDynamicButtons()
{
	cleanAllDynamicButtons();  // clean previous buttons

	set<string> words;
	int pos = 0;
	SplitString(txtWordsInput->toPlainText().toStdString(), words);

	for(auto word : words) // this is the c++11 syntax to iterate over sets and lists
	{
		// for every word create a new button
		// we are only new-ing a button here. Where is the delete!?
		WordPushButton * btnWord = new WordPushButton(word);

		// insert the new button into the set and genLayout
		// we add it to the set so that later we can find it and delete it
		setWordButtons.insert(btnWord);
		genLayout->addWidget(btnWord, 0);

		// this is a signal-slot connection with argument.
		// we are connecting all the dynamic buttons into a single slot.
		// the slot function can tell which buttons is pushed based on the passed string argument.
		// Why are we using pushed signal instead of clicked signal?
		connect(btnWord, SIGNAL(ClickedWithArgument(std::string)), this, SLOT(doLookupWord(std::string)));
	}
}

void MainWin::doLookupWord(std::string word)
{
	// create a new DefWin window and pass the string as argument.
	// look at the DefWin header. It does not have a default ctor! Why?

	// this function is leaking memory because we do not delete the dynamically created DefWin later.
	// fix this issue by storing the pointer in a list and delete them all during destruction.

	auto w = new DefWin(word, this);
	listDefWindows.insert(listDefWindows.end(), w);
	w->show();
}

void MainWin::showAbout()
{
	/// http://qt-project.org/doc/qt-5/qmessagebox.html#information
	QMessageBox::information(this, tr("About"), tr("Sample Qt app for lab9"));
}

// helper function to split string into a unique set of words
void SplitString(const string & s, set<string> & words)
{
	string temp;
	for( stringstream ss(s); ss >> temp; )
	{
		try { words.insert(temp); }
		catch (exception &) { }
	}
}
