/****************************************************************************
 * This file is part of Liri.
 *
 * Copyright (C) 2019 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:GPL3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Fluid as Fluid

Fluid.ApplicationWindow {
    title: qsTr("Welcome to Liri OS")
    width: 600
    height: 400
    minimumWidth: 600
    minimumHeight: 400
    visible: true

    Material.accent: Material.Blue
    Material.primary: Material.BlueGrey

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Fluid.Placeholder {
            icon.source: Fluid.Utils.iconUrl("hardware/computer")
            text: qsTr("Welcome to Liri OS")
            subText: qsTr("You are currently running Liri OS from live media.\nYou can install Liri OS now, or launch \"Install to Hard Drive\" later.")

            Layout.fillWidth: true
            Layout.preferredHeight: 300
            Layout.alignment: Qt.AlignCenter
        }

        Item {
            Layout.fillHeight: true
        }

        Fluid.ListItem {
            icon.source: Fluid.Utils.iconUrl("action/exit_to_app")
            text: qsTr("Try Liri OS")
            onClicked: Qt.quit()
        }

        Fluid.ListItem {
            icon.source: Fluid.Utils.iconUrl("file/file_download")
            text: qsTr("Install to Hard Drive")
            onClicked: {
                Runner.run();
                Qt.quit();
            }
        }
    }
}
