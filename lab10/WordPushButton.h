#ifndef WORDPUSHBUTTON_H_
#define WORDPUSHBUTTON_H_

#include <QPushButton>
#include <string>

// quick customization of push button
class WordPushButton : public QPushButton
{
	Q_OBJECT

public:
	WordPushButton(std::string & word, QWidget* parent = 0);
	virtual ~WordPushButton();

protected:
	std::string _word;

public slots:
	void triggerPush();

signals:
	void ClickedWithArgument( std::string );
};

#endif
