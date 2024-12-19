#ifndef EXPENSESWINDOW_H
#define EXPENSESWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class MainAppWindow; // Предварительное объявление класса MainAppWindow

class ExpensesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExpensesWindow(MainAppWindow *mainAppWindow, QWidget *parent = nullptr);

private slots:
    void onSaveButtonClicked();

private:
    void setupUI();

    QLineEdit *amountEdit;
    QLabel *categoryLabel;
    QRadioButton *productsRadio;
    QRadioButton *educationRadio;
    QRadioButton *leisureRadio;
    QRadioButton *cafeRadio;
    QLabel *dateLabel;
    QLineEdit *dayEdit;
    QLineEdit *monthEdit;
    QPushButton *saveButton;

    MainAppWindow *mainAppWindow; // Указатель на основное окно приложения
};

#endif // EXPENSESWINDOW_H
