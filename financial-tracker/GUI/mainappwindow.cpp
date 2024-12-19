#include "mainappwindow.h"
#include "expenseswindow.h" // Добавляем заголовок для ExpensesWindow
#include "incomewindow.h" // Добавляем заголовок для IncomeWindow
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QInputDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QMenu>
#include "mainwindow.h" // Включаем заголовок с функцией createStyledButton

MainAppWindow::MainAppWindow(QWidget *parent)
    : QWidget(parent), balance(0.0)
{
    setupUI();
}

void MainAppWindow::setupUI()
{
    // Устанавливаем фиксированный размер окна
    setFixedSize(600, 700); // Увеличиваем высоту окна

    // Устанавливаем заголовок окна
    setWindowTitle("Основное окно приложения");

    // Устанавливаем фон основного окна
    setStyleSheet("background-color: #FCFAFA;");

    // Создаем главный вертикальный layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Добавляем прямоугольный слот с закругленными краями
    QFrame *roundedSlot = new QFrame(this);
    roundedSlot->setFixedSize(300, 200); // Устанавливаем размер слота
    roundedSlot->setStyleSheet("QFrame {"
                               "background-color: #A4B8C4;"
                               "border-radius: 20px;"
                               "}");

    // Добавляем круглое кольцо поверх слота
    QFrame *ringFrame = new QFrame(roundedSlot);
    ringFrame->setGeometry(25, 25, 250, 250); // Устанавливаем размер и позицию кольца
    ringFrame->setStyleSheet("QFrame {"
                             "background-color: transparent;" // Прозрачный фон
                             "border: 20px solid #6E8387;" // Темно-серый цвет и увеличенная толщина границы
                             "border-radius: 125px;" // Круглая форма
                             "}");

    // Создаем QLabel для отображения баланса внутри круга
    balanceLabel = new QLabel("Баланс: 0", ringFrame);
    balanceLabel->setAlignment(Qt::AlignCenter);
    QFont balanceFont("Calibri Light", 15, QFont::Bold); // Шрифт для надписи "Баланс"
    balanceLabel->setFont(balanceFont);
    balanceLabel->setStyleSheet("background-color: transparent; border: none;"); // Убираем рамку и фон
    balanceLabel->setGeometry(25, 50, 200, 50); // Устанавливаем позицию и размер метки

    // Создаем кнопку для изменения баланса с помощью функции createStyledButton
    changeBalanceButton = MainWindow::createStyledButton("Изменить", ringFrame);
    changeBalanceButton->setGeometry(50, 120, 150, 30); // Устанавливаем позицию и размер кнопки
    connect(changeBalanceButton, &QPushButton::clicked, this, &MainAppWindow::onChangeBalanceButtonClicked);

    mainLayout->addWidget(roundedSlot, 0, Qt::AlignCenter);

    // Создаем список для отображения транзакций
    transactionsList = new QListWidget(this);
    transactionsList->setFixedSize(350, 370); // Устанавливаем ширину списка транзакций
    mainLayout->addWidget(transactionsList, 0, Qt::AlignCenter); // Располагаем список по центру

    // Создаем горизонтальный layout для кнопок "Расходы" и "Доходы"
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(20);

    // Создаем кнопку "Расходы"
    expensesButton = new QPushButton("Расходы", this);
    expensesButton->setFixedSize(150, 40);
    expensesButton->setStyleSheet("QPushButton {"
                                  "background-color: #A4B8C4;"
                                  "color: white;"
                                  "font-size: 16px;"
                                  "border-radius: 20px;"
                                  "border: 2px solid #8E9EAB;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #8E9EAB;"
                                  "}");
    connect(expensesButton, &QPushButton::clicked, this, &MainAppWindow::onExpensesButtonClicked);

    // Создаем кнопку "Доходы"
    incomeButton = new QPushButton("Доходы", this);
    incomeButton->setFixedSize(150, 40);
    incomeButton->setStyleSheet("QPushButton {"
                                "background-color: #A4B8C4;"
                                "color: white;"
                                "font-size: 16px;"
                                "border-radius: 20px;"
                                "border: 2px solid #8E9EAB;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: #8E9EAB;"
                                "}");
    connect(incomeButton, &QPushButton::clicked, this, &MainAppWindow::onIncomeButtonClicked);

    buttonLayout->addWidget(expensesButton);
    buttonLayout->addWidget(incomeButton);
    mainLayout->addLayout(buttonLayout);

    // Устанавливаем отступы и интервалы
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(20);

    // Устанавливаем центральный виджет и layout
    setLayout(mainLayout);
}

void MainAppWindow::onExpensesButtonClicked() {
    // Логика для обработки нажатия кнопки "Расходы"
    ExpensesWindow *expensesWindow = new ExpensesWindow(this);
    expensesWindow->show();
}

void MainAppWindow::onIncomeButtonClicked() {
    // Логика для обработки нажатия кнопки "Доходы"
    IncomeWindow *incomeWindow = new IncomeWindow(this);
    incomeWindow->show();
}

void MainAppWindow::onChangeBalanceButtonClicked() {
    // Логика для изменения баланса
    bool ok;
    double newBalance = QInputDialog::getDouble(this, "Изменить баланс", "Введите новый баланс:", balance, -1000000, 1000000, 2, &ok);
    if (ok) {
        balance = newBalance;
        balanceLabel->setText(QString("Баланс: %1").arg(balance));
    }
}

void MainAppWindow::addExpense(const QString &category, double amount, const QString &date) {
    QString transaction = QString("%1 -%2   Дата: %3").arg(category).arg(amount).arg(date);
    transactionsList->addItem(transaction);
    balance -= amount;
    balanceLabel->setText(QString("Баланс: %1").arg(balance));
}

void MainAppWindow::addIncome(const QString &category, double amount, const QString &date) {
    QString transaction = QString("%1 +%2   Дата: %3").arg(category).arg(amount).arg(date);
    transactionsList->addItem(transaction);
    balance += amount;
    balanceLabel->setText(QString("Баланс: %1").arg(balance));
}
