#ifndef INCOMEWINDOW_H
#define INCOMEWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class MainAppWindow; // Предварительное объявление класса MainAppWindow

class IncomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit IncomeWindow(MainAppWindow *mainAppWindow, QWidget *parent = nullptr);

private slots:
    void onSaveButtonClicked();

private:
    void setupUI();

    QLineEdit *amountEdit;
    QLabel *categoryLabel;
    QRadioButton *salaryRadio;
    QRadioButton *giftRadio;
    QLabel *dateLabel;
    QLineEdit *dayEdit;
    QLineEdit *monthEdit;
    QPushButton *saveButton;

    MainAppWindow *mainAppWindow; // Указатель на основное окно приложения
};

#endif // INCOMEWINDOW_H
