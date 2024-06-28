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

#include <QGuiApplication>
#include <QLibraryInfo>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QStandardPaths>
#include <QTranslator>

#include "runner.h"

using namespace Qt::StringLiterals;

int main(int argc, char *argv[])
{
    // Setup application
    QGuiApplication app(argc, argv);
    app.setApplicationName(QStringLiteral("Live Welcome"));
    app.setApplicationVersion(QStringLiteral(VERSION));
    app.setOrganizationDomain(QStringLiteral("liri.io"));
    app.setOrganizationName(QStringLiteral("Liri"));
    app.setDesktopFileName(QStringLiteral("io.liri.LiveWelcome.desktop"));

    QQuickStyle::setStyle(QStringLiteral("Material"));

#ifndef QT_NO_TRANSLATION
    // Load Qt translations
    QTranslator qtTranslator;
    if (qtTranslator.load(QLocale(), "qt"_L1, "_"_L1,
                          QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
        app.installTranslator(&qtTranslator);

    // Load translations from resources
    QTranslator translator;
    if (translator.load(QLocale(), "liri-live-welcome"_L1, "_"_L1, ":/qt/qml/io/liri/LiveWelcome/i18n"_L1))
        QCoreApplication::installTranslator(&translator);
#endif

    // Load UI
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("Runner"), new Runner(&engine));
    engine.loadFromModule("io.liri.LiveWelcome", "Main");

    return app.exec();
}
