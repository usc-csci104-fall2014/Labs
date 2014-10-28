#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <string>
#include <set>
#include <list>
#include "defwin.h"
#include "WordPushButton.h"

// helper function
void SplitString(const std::string &, std::set<std::string> &);

class MainWin : public QMainWindow
{
	Q_OBJECT

	public:
		MainWin(QWidget *parent = 0);
		~MainWin();

	private slots:
		void doGenerateDynamicButtons();
		void doLookupWord(std::string word);
		void showAbout();
		
	private:
		void cleanAllDynamicButtons(void);

		QPushButton    * btnGen;
		QPushButton    * btnAbout;
		QPlainTextEdit * txtWordsInput;
		QVBoxLayout    * winLayout;
		QHBoxLayout    * genLayout;
		QWidget        * centerWidget;

		std::set<WordPushButton *> setWordButtons; // set of all dynamic buttons
		std::list<DefWin *>        listDefWindows; // list of all dynamic definition windows
};

#endif
