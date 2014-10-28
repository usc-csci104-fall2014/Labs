#ifndef DefWin_H
#define DefWin_H

#include <QWidget>
#include <QMainWindow>
#include <QWebView>
#include <QString>
#include <string>

class DefWin : public QMainWindow
{
Q_OBJECT

public:
	DefWin(std::string word, QWidget *parent = 0);
	~DefWin();

private:
	QWebView * web;
};

#endif
