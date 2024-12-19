#ifndef FINANCEMANAGER_HPP
#define FINANCEMANAGER_HPP

#include <QWidget>
#include <QTableView>

class FinanceManager : public QWidget {
    Q_OBJECT

public:
    FinanceManager(QWidget *parent = nullptr);

private slots:
    void addRecord();
    void viewReports();

private:
    QTableView *tableView;
};

#endif // FINANCEMANAGER_HPP
