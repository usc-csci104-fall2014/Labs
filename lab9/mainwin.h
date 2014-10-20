#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>

class MainWin : ?? QWidget // you can also try QMainWindow
{
	Q_OBJECT

	public:
		MainWin(QWidget *parent = 0);
		~MainWin();

	protected:
		void closeEvent(QCloseEvent *event);

	private slots:
		void doCountWord();
		void showAbout();
		
	private:
		QPushButton * btnCount;
		QPushButton * btnAbout;
		QPlainTextEdit * txtWordInput;
};

#endif

