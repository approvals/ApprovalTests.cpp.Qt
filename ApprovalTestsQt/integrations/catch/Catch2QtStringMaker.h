#ifndef APPROVALTESTS_CPP_QT_CATCH2QTSTRINGMAKER_H
#define APPROVALTESTS_CPP_QT_CATCH2QTSTRINGMAKER_H

#ifdef CATCH_VERSION_MAJOR
#include <QColor>
#include <QTest>
#include <QStringBuilder>

namespace Catch
{
    template <> struct StringMaker<QColor>
    {
        static std::string convert(QColor const& color)
        {
            // clang-format off
            const QString result = "(" %
                                   QString::number(color.redF()) % ", " %
                                   QString::number(color.greenF()) % ", " %
                                   QString::number(color.blueF()) %
                                   "), alpha = " %
                                   QString::number(color.alphaF(), 'g', 20);
            // clang-format on
            return result.toStdString();
        }
    };

    // This adds support for all the types that can be stringified with Qt Test:
    // https://doc.qt.io/qt-5/qtest.html#toString
    template <class QtCoreType> struct StringMaker<QtCoreType>
    {
        static std::string convert(QtCoreType const& object)
        {
            return QTest::toString(object);
        }
    };

    template <> struct StringMaker<QString>
    {
        static std::string convert(QString const& string)
        {
            return string.toStdString();
        }
    };
} // namespace Catch
#endif // CATCH_VERSION_MAJOR

#endif //APPROVALTESTS_CPP_QT_CATCH2QTSTRINGMAKER_H
