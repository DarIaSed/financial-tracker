#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

#include <QDialog>
#include <QLineEdit>

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);

private slots:
    void login();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
};

#endif // LOGINDIALOG_HPP
