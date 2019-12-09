#ifndef EMOJIRUNNER_UTILITIES_H
#define EMOJIRUNNER_UTILITIES_H

#include <QtWidgets/QListWidgetItem>
#include <core/Emoji.h>
#include <core/Config.h>

namespace Utilities {

/**
 * Returns a QListWidgetItem with the data of the emoji
 * @return QListWidgetItem
 */
    QListWidgetItem *toListWidgetItem(const Emoji &emoji) {
        auto *item = new QListWidgetItem(emoji.emoji + " " + emoji.name);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(emoji.favourite != 0 ? Qt::Checked : Qt::Unchecked);
        item->setData(Qt::UserRole, emoji.name);
        return item;
    }
}

/**
 * Create the config file and parent folder if they do not exist already
 */
void createConfigFile() {
    const QString configFolder = QDir::homePath() + "/.config/krunnerplugins/";
    const QDir configDir(configFolder);
    if (!configDir.exists()) configDir.mkpath(configFolder);
    // Create file
    QFile configFile(configFolder + Config::ConfigFileName);
    if (!configFile.exists()) {
        configFile.open(QIODevice::WriteOnly);
        configFile.close();
    }
}

#endif //EMOJIRUNNER_UTILITIES_H
