#ifndef MAINAPPWINDOW_H
#define MAINAPPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QListWidget>
#include <QInputDialog>
#include <QMessageBox>
#include <QMenu>

class MainAppWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainAppWindow(QWidget *parent = nullptr);

    void addExpense(const QString &category, double amount, const QString &date); // Метод для добавления расхода
    void addIncome(const QString &category, double amount, const QString &date); // Метод для добавления дохода

private slots:
    void onExpensesButtonClicked();
    void onIncomeButtonClicked();
    void onChangeBalanceButtonClicked();

private:
    void setupUI();

    QLabel *balanceLabel; // Добавляем метку для баланса
    QPushButton *changeBalanceButton; // Добавляем кнопку для изменения баланса
    QPushButton *expensesButton; // Добавляем кнопку для расходов
    QPushButton *incomeButton; // Добавляем кнопку для доходов
    double balance; // Переменная для хранения баланса
    QListWidget *transactionsList; // Добавляем список для отображения транзакций
};

#endif // MAINAPPWINDOW_H
