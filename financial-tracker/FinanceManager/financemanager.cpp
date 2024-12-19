#include "FinanceManager.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QMessageBox>

FinanceManager::FinanceManager(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    //TODO Поля для ввода данных
    QLabel *incomeLabel = new QLabel("Доход:", this);
    QLabel *expenseLabel = new QLabel("Расход:", this);
    QLabel *dateLabel = new QLabel("Дата:", this);

    QLineEdit *incomeEdit = new QLineEdit(this);
    QLineEdit *expenseEdit = new QLineEdit(this);
    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(), this);

    layout->addWidget(incomeLabel);
    layout->addWidget(incomeEdit);
    layout->addWidget(expenseLabel);
    layout->addWidget(expenseEdit);
    layout->addWidget(dateLabel);
    layout->addWidget(dateEdit);

    //TODO Кнопки для добавления и отображения записей
    QPushButton *addButton = new QPushButton("Добавить запись", this);
    QPushButton *viewButton = new QPushButton("Показать отчеты", this);

    layout->addWidget(addButton);
    layout->addWidget(viewButton);

    //TODO Таблица для отображения отчетов (пока что без данных)
    tableView = new QTableView(this);
    layout->addWidget(tableView);

    connect(addButton, &QPushButton::clicked, this, &FinanceManager::addRecord);
    connect(viewButton, &QPushButton::clicked, this, &FinanceManager::viewReports);
}

void FinanceManager::addRecord() {
    //TODO Логика для добавления записи о доходе или расходе
    QMessageBox::information(this, "Добавление записи", "Запись добавлена (заглушка)!");
}

void FinanceManager::viewReports() {
    //TODO Логика для отображения отчетов
    QMessageBox::information(this, "Отчеты", "Показ отчетов (заглушка)!");
}
