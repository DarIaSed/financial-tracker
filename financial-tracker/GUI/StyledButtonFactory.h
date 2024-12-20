#ifndef STYLED_BUTTON_FACTORY_H
#define STYLED_BUTTON_FACTORY_H

#include <QPushButton>
#include <QString>

class StyledButtonFactory {
public:

    static QPushButton* createStyledButton(const QString& text, QWidget* parent = nullptr);
};

#endif // STYLED_BUTTON_FACTORY_H