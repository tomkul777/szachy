#ifndef LOGI_H
#define LOGI_H

#include <QTextBrowser>

class Logi : public QTextBrowser
{
public:
    Logi(QWidget *parent);
    Logi(const Logi &logi);
};

#endif // LOGI_H
