#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <iostream>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget *window = new QWidget;

  QPushButton *button1 = new QPushButton("One");
  QPushButton *button2 = new QPushButton("Two");
  QPushButton *button3 = new QPushButton("Three");

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(button1);
  layout->addWidget(button2);
  layout->addWidget(button3);

  window->setLayout(layout);
  window->show();
  int r = app.exec();
  delete button1;
  delete button2;
  delete button3;
  delete layout;
  delete window;
//  std::cout << "deleted" << std::endl;
//  std::cout << "app.exe" << std::endl;
  return r;
}
