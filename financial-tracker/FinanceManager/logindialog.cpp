#include "LoginDialog.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Вход в систему");

    QLabel *userLabel = new QLabel("Имя пользователя:", this);
    QLabel *passLabel = new QLabel("Пароль:", this);

    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *loginButton = new QPushButton("Войти", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(userLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::login);
}

void LoginDialog::login() {
    //TODO надо поменять на валидацию из бд
    if (usernameEdit->text() == "login" && passwordEdit->text() == "password") {
        accept();
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверные имя пользователя или пароль!");
    }
}

//TODO добавить регистрацию
