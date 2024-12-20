#include "StyledButtonFactory.h"

QPushButton* StyledButtonFactory::createStyledButton(const QString& text, QWidget* parent) {
    QPushButton* button = new QPushButton(text, parent);
    button->setFixedSize(130, 30); // Устанавливаем фиксированный размер
    button->setStyleSheet(
        "QPushButton {"
        "background-color: #6E8387;" // Основной цвет
        "color: white;"
        "font-size: 15px;"
        "border-radius: 15px;"
        "border: 2px solid #5A6E72;"
        "}"
        "QPushButton:hover {"
        "background-color: #5A6E72;" // Цвет при наведении
        "}"
    );
    return button;
}