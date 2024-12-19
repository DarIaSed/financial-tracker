#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginButtonClicked();
    void onShowPasswordButtonClicked();

private:
    QLabel *loginLabel;
    QLineEdit *loginEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *showPasswordButton;
    QLabel *successLabel;
};

#endif // LOGINWINDOW_H
