#ifndef EmojiRunnerCONFIG_H
#define EmojiRunnerCONFIG_H

#include "ui_emojirunner_config.h"
#include <KCModule>
#include <KConfigCore/KConfigGroup>
#include <EmojiCategory.h>

class EmojiRunnerConfigForm : public QWidget, public Ui::EmojiRunnerConfigUi {
Q_OBJECT

public:
    explicit EmojiRunnerConfigForm(QWidget *parent);
};

class EmojiRunnerConfig : public KCModule {
Q_OBJECT

public:
    explicit EmojiRunnerConfig(QWidget *parent = nullptr, const QVariantList &args = QVariantList());

    KConfigGroup config;

    QList<EmojiCategory> emojiCategories;

    QStringList disabledEmojis;

    QStringList unicodeVersions = {"3.0", "3.2", "4.0", "4.1", "5.1", "5.2", "6.0", "6.1", "7.0", "8.0", "9.0", "11.0", "12.0"};
    QStringList iosVersions = {"6.0", "8.3", "9.0", "9.1", "10.0", "10.2", "12.1", "13.0"};

public Q_SLOTS:

    void save() override;

    void load() override;

    void defaults() override;


private:
    EmojiRunnerConfigForm *m_ui;

};

#endif
