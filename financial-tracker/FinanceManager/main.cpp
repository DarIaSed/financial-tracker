#include <QApplication>
#include "LoginDialog.hpp"
#include "FinanceManager.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Окно для входа
    LoginDialog login;
    if (login.exec() != QDialog::Accepted) {
        return 0;  // Если вход не успешен, завершаем приложение
    }

    // Основное окно после успешного входа
    FinanceManager manager;
    manager.setWindowTitle("Personal Finance Manager");
    manager.resize(400, 300);
    manager.show();

    return app.exec();
}
