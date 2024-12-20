#include <iostream>

#include "loginwindow.h"
#include "mainappwindow.h" // Добавляем заголовок для MainAppWindow
#include "data_base.h"
#include <QMessageBox>
#include "StyledButtonFactory.h" // Добавляем заголовок для StyledButtonFactory

LoginWindow::LoginWindow(QWidget* parent) : QWidget(parent)
{
    // Устанавливаем фиксированный размер окна
    setFixedSize(450, 600);

    // Устанавливаем заголовок окна
    setWindowTitle("Авторизация");

    // Устанавливаем градиентный фон окна
    setStyleSheet("background: #FCFAFA;");

    // Создаем главный вертикальный layout
    QVBoxLayout* loginMainLayout = new QVBoxLayout(this);

    // Создаем QLabel для надписи "Логин"
    loginLabel = new QLabel("Логин", this);
    QFont loginFont("Calibri Light", 11); // Изменяем шрифт
    loginLabel->setFont(loginFont);
    loginLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    loginMainLayout->addWidget(loginLabel);

    // Создаем QLineEdit для ввода логина
    loginEdit = new QLineEdit(this);
    loginEdit->setStyleSheet("QLineEdit { border: 2px solid #C8D3D5; border-radius: 20px; padding: 8px; background-color: white; selection-background-color: darkgray; min-width: 150px; min-height: 35px; font-size: 16px; }");
    loginMainLayout->addWidget(loginEdit);

    // Создаем QLabel для надписи "Пароль"
    passwordLabel = new QLabel("Пароль", this);
    QFont passwordFont("Calibri Light", 11); // Изменяем шрифт
    passwordLabel->setFont(passwordFont);
    passwordLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    loginMainLayout->addWidget(passwordLabel);

    // Создаем QLineEdit для ввода пароля
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password); // Скрываем вводимый пароль
    passwordEdit->setStyleSheet("QLineEdit { border: 2px solid #C8D3D5; border-radius: 20px; padding: 8px; background-color: white; selection-background-color: darkgray; min-width: 150px; min-height: 35px; font-size: 16px; }");
    loginMainLayout->addWidget(passwordEdit);

    // Создаем кнопку "Показать пароль" с использованием StyledButtonFactory
    showPasswordButton = StyledButtonFactory::createStyledButton("Показать пароль", this);
    showPasswordButton->setFixedSize(130, 30);
    connect(showPasswordButton, &QPushButton::clicked, this, &LoginWindow::onShowPasswordButtonClicked);
    loginMainLayout->addWidget(showPasswordButton);

    // Создаем кнопку "Войти" с использованием StyledButtonFactory
    loginButton = StyledButtonFactory::createStyledButton("Войти", this);
    loginButton->setFixedSize(150, 40);

    // Добавляем тень к кнопке
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(0, 0, 0, 80));
    shadowEffect->setOffset(0, 4);
    loginButton->setGraphicsEffect(shadowEffect);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    loginMainLayout->addWidget(showPasswordButton, 0, Qt::AlignCenter);
    loginMainLayout->addWidget(loginButton, 0, Qt::AlignCenter);

    // Создаем QLabel для сообщения об успешной авторизации
    successLabel = new QLabel("", this);
    successLabel->setStyleSheet("color: green; background-color: #FCFAFA;");
    successLabel->hide(); // Скрываем метку до нажатия кнопки "Войти"
    loginMainLayout->addWidget(successLabel);

    // Устанавливаем отступы и интервалы
    loginMainLayout->setContentsMargins(50, 50, 50, 50);
    loginMainLayout->setSpacing(20);

    // Устанавливаем центральный виджет и layout
    setLayout(loginMainLayout);
}

void LoginWindow::onLoginButtonClicked() {
    QString login = loginEdit->text();
    QString password = passwordEdit->text();

    DBManager dbManager("172.27.8.206", "financal_tracker", "project_user", "123");
    dbManager.connect();

    QString query = QString(
        "SELECT COUNT(*) AS count "
        "FROM users "
        "WHERE login = '%1' AND password = '%2';"
    ).arg(login, password);

    QSqlQuery result = dbManager.fetchQuery(query);
    if (result.isActive() && result.next()) {
        int count = result.value("count").toInt(); // Получаем значение из колонки "count"
        if (count > 0) {
            // Пользователь найден
            std::cout << "Пользователь авторизован.\n";

            QMessageBox::information(this, "Информация", "Вы успешно авторизовались!");
            successLabel->setText("Вы успешно авторизовались!");
            successLabel->show();

            // Открываем основное окно приложения
            MainAppWindow* mainAppWindow = new MainAppWindow();
            mainAppWindow->show();
            this->close(); // Закрываем окно авторизации
        }
        else {
            // Пользователь не найден
            QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль!");
        }
    }
    else {
        // Ошибка при выполнении запроса
        QMessageBox::warning(this, "Ошибка", "Произошла ошибка при выполнении запроса!");
        std::cerr << "Ошибка при выполнении запроса: " << dbManager.getLastError().toStdString() << "\n";
    }
}

void LoginWindow::onShowPasswordButtonClicked() {
    // Обработка нажатия кнопки "Показать пароль"
    if (passwordEdit->echoMode() == QLineEdit::Password) {
        passwordEdit->setEchoMode(QLineEdit::Normal);
        showPasswordButton->setText("Скрыть пароль");
    }
    else {
        passwordEdit->setEchoMode(QLineEdit::Password);
        showPasswordButton->setText("Показать пароль");
    }
}
