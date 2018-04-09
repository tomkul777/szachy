#include "logi.h"

Logi::Logi(QWidget *parent) : QTextBrowser(parent)
{
    this->setGeometry(670, 400, 200, 210);
    this->setText("");
}

Logi::Logi(const Logi &logi) : QTextBrowser()
{
    this->setText(logi.toPlainText());
}
