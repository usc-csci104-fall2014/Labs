#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget *window = new QWidget;

  QPushButton *button1 = new QPushButton("One");
  QPushButton *button2 = new QPushButton("Two");
  QPushButton *button3 = new QPushButton("Three");

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(button1, 1, 1);
  layout->addWidget(button2, 1, 2);
  layout->addWidget(button3, 2, 1, 1, 2);

  window->setLayout(layout);
  window->show();
  return app.exec();
}
