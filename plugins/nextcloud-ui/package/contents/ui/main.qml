/*
 *   Copyright 2019 (C) Rituka Patwal <ritukapatwal21@gmail.com>
 *   Copyright 2015 (C) Martin Klapetek <mklapetek@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

import QtQuick 2.2
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

import org.kde.kirigami 2.5 as Kirigami
import org.kde.kaccounts.nextcloud 1.0

Kirigami.ApplicationWindow {
    id: ncAccountRoot

    width: Kirigami.Units.gridUnit * 25
    height: Kirigami.Units.gridUnit * 15

    pageStack.initialPage: Qt.resolvedUrl("Server.qml");

    Connections {
        target: helper

        function onStateChanged() {
            if (helper.state === NextcloudController.WebLogin) {
                ncAccountRoot.pageStack.replace(Qt.resolvedUrl("WebLogin.qml"))
            } else if (helper.state === NextcloudController.Services) {
                ncAccountRoot.pageStack.replace(Qt.resolvedUrl("Services.qml"))
            }
        }
    }
}
