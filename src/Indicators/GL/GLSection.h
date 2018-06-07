#ifndef GLSECTION_H
#define GLSECTION_H

// Qt
#include <QWidget>

// UI
namespace Ui
{
  class GLSection;
}

class GLSection : public QWidget
{
  Q_OBJECT

  public:
    explicit GLSection(QWidget *parent = nullptr);
    ~GLSection();

  private:
    Ui::GLSection *ui;
};

#endif // GLSECTION_H
