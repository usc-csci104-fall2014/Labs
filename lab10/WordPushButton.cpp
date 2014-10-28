#include "WordPushButton.h"

WordPushButton::WordPushButton(std::string & word, QWidget* parent)
: QPushButton(QString::fromStdString(word), parent), _word(word)
{
	// capture the clicked() signal internally and then emit another one
	connect(this, SIGNAL(clicked()), this, SLOT(triggerPush()));
}

void WordPushButton::triggerPush()
{
	// emit a new signal and pass the word as string argument
	emit ClickedWithArgument(_word);
}

WordPushButton::~WordPushButton()
{
	// disconnect the signal upon destruction
	disconnect(this, SIGNAL(clicked()), this, SLOT(triggerPush()));
}
